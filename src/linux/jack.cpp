/******************************************************************************\
 * British Broadcasting Corporation
 * Copyright (c) 2007
 *
 * Author(s):
 *	Julian Cable
 *
 * Description:
 *	Jack sound classes
 *
 ******************************************************************************
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include <ctime>
#include "jack.h"
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <map>
#include <utility>

using namespace std;

instance_data_t::instance_data_t()
    : num_channels(2), left(NULL), right(NULL), buff(NULL), underruns(0),
      overruns(0), peer_left(), peer_right() {
  buff = jack_ringbuffer_create(8 * sizeof(short) * 48 * 400 * num_channels);
}

instance_data_t::~instance_data_t() { jack_ringbuffer_free(buff); }

struct CJackCommon {
  CJackCommon()
      : client(NULL), is_active(false), capture_data(NULL), play_data(NULL) {}
  jack_client_t *client;
  volatile bool is_active;
  instance_data_t *capture_data;
  instance_data_t *play_data;
  void initialise();
  void terminate();
};

static CJackCommon common_data;

static int capture_stereo(jack_nframes_t nframes, void *arg) {
  instance_data_t &data = *(instance_data_t *)arg;
  if (arg == NULL) {
    return 0;
  }
  if (data.left == NULL || data.right == NULL) {
    return 0;
  }
  jack_default_audio_sample_t *in[2];
  in[0] =
      (jack_default_audio_sample_t *)jack_port_get_buffer(data.left, nframes);
  in[1] =
      (jack_default_audio_sample_t *)jack_port_get_buffer(data.right, nframes);
  if (in[0] == NULL || in[1] == NULL) {
    return 0;
  }
  if (data.buff == NULL) {
    return 0;
  }
  for (jack_nframes_t i = 0; i < nframes; i++) {
    short sample[2];
    size_t bytes = sizeof(short) * 2;
    /* interleave samples for encoder */
    for (int chn = 0; chn < 2; chn++)
      sample[chn] = short(32768.0 * in[chn][i]);
    if (jack_ringbuffer_write(data.buff, (char *)sample, bytes) < bytes)
      data.overruns++;
  }
  return 0;
}

static int play_stereo(jack_nframes_t nframes, void *arg) {
  if (arg == NULL) {
    return 0;
  }
  instance_data_t &data = *(instance_data_t *)arg;
  if (data.left == NULL || data.right == NULL) {
    return 0;
  }
  jack_default_audio_sample_t *out[2];
  out[0] =
      (jack_default_audio_sample_t *)jack_port_get_buffer(data.left, nframes);
  out[1] =
      (jack_default_audio_sample_t *)jack_port_get_buffer(data.right, nframes);
  if (out[0] == NULL || out[1] == NULL) {
    return 0;
  }
  if (data.buff == NULL) {
    return 0;
  }
  for (jack_nframes_t i = 0; i < nframes; i++) {
    short buffer[2];
    size_t bytes = sizeof(short) * 2;
    size_t n = jack_ringbuffer_read(data.buff, (char *)buffer, bytes);
    if (n < bytes)
      data.underruns++;
    /* de-interleave samples from decoder */
    for (int chn = 0; chn < 2; chn++)
      out[chn][i] = jack_default_audio_sample_t(double(buffer[chn]) / 32768.0);
  }
  return 0;
}

static int process_callback(jack_nframes_t nframes, void *arg) {
  CJackCommon *This = (CJackCommon *)arg;
  if (This->capture_data)
    capture_stereo(nframes, This->capture_data);
  if (This->play_data)
    play_stereo(nframes, This->play_data);
  return 0;
}

static void jack_shutdown(void *arg) { cout << "jack shut down" << endl; }

void CJackCommon::initialise() {
  jack_options_t options = jack_options_t(JackNullOption | JackServerName);
  jack_status_t status;
  string server = "default";

  /* open a client connection to the Jack server */

  client = jack_client_open("dream", options, &status, server.c_str());
  if (client == NULL) {
    cerr << "jack_client_open() failed, status = " << ((long unsigned)status)
         << endl;
    if (status & JackServerFailed) {
      throw "Unable to connect to Jack server";
    }
  }
  if (status & JackServerStarted) {
    cout << "Jack server started" << endl;
  }
  if (status & JackNameNotUnique) {
    char *client_name = jack_get_client_name(client);
    cout << "Jack unique name `" << client_name << "' assigned" << endl;
  }

  /* tell the CSoundInJack server to call `process()' whenever
     there is work to be done.
   */

  jack_set_process_callback(client, process_callback, &common_data);

  /* tell the Jack server to call `jack_shutdown()' if
     it ever shuts down, either entirely, or if it
     just decides to stop calling us.
   */

  jack_on_shutdown(client, jack_shutdown, 0);

  // if (jack_get_sample_rate(client) != Parameters.GetSampleRate())
  //{
  // throw "Jack: jack is running with the wrong sample rate";
  //}
}

void CJackCommon::terminate() {
  jack_client_close(client);
  client = NULL;
}

CSoundInJack::CSoundInJack()
    : iBufferSize(0), bBlocking(true), capture_data(), dev("") {
  if (common_data.client == NULL)
    common_data.initialise();

  if (common_data.is_active && jack_deactivate(common_data.client)) {
    throw "Jack: cannot deactivate client";
  }
  common_data.is_active = false;

  capture_data.left =
      jack_port_register(common_data.client, "input_0", JACK_DEFAULT_AUDIO_TYPE,
                         JackPortIsInput, 0);
  capture_data.right =
      jack_port_register(common_data.client, "input_1", JACK_DEFAULT_AUDIO_TYPE,
                         JackPortIsInput, 0);

  if ((capture_data.left == NULL) || (capture_data.right == NULL)) {
    throw "Jack: no more ports available";
  }

  jack_ringbuffer_reset(capture_data.buff);

  common_data.capture_data = &capture_data;

  if (jack_activate(common_data.client)) {
    throw "Jack: cannot activate client";
  }
  common_data.is_active = true;
}

CSoundInJack::CSoundInJack(const CSoundInJack &e)
    : iBufferSize(e.iBufferSize), bBlocking(e.bBlocking), device_changed(true),
      capture_data(e.capture_data), dev(e.dev) {}

CSoundInJack &CSoundInJack::operator=(const CSoundInJack &e) {
  iBufferSize = e.iBufferSize;
  bBlocking = e.bBlocking;
  capture_data = e.capture_data;
  dev = e.dev;
  return *this;
}

CSoundInJack::~CSoundInJack() {
  Close();
  if (common_data.client == NULL)
    return;

  if (common_data.is_active && jack_deactivate(common_data.client)) {
    throw "Jack: cannot deactivate client";
  }
  common_data.is_active = false;
  common_data.capture_data = NULL;
  if (jack_activate(common_data.client)) {
    throw "Jack: cannot activate client";
  }
  common_data.is_active = true;
}

void CSoundInJack::Enumerate(std::vector<std::string> &names,
                             std::vector<std::string> &descriptions,
                             std::string &defaultDevice) {
  names.clear();
  descriptions.clear();

  // Get all capture ports (physical outputs that we can capture from)
  const char **ports = jack_get_ports(
      common_data.client, nullptr, JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput);

  if (ports) {
    for (int i = 0; ports[i] != nullptr; i++) {
      names.push_back(ports[i]);

      // Try to get port alias as friendly name
      jack_port_t *port = jack_port_by_name(common_data.client, ports[i]);
      if (port) {
        char *aliases[2];
        aliases[0] = new char[jack_port_name_size()];
        aliases[1] = new char[jack_port_name_size()];
        int num_aliases = jack_port_get_aliases(port, aliases);
        if (num_aliases > 0) {
          descriptions.push_back(aliases[0]);
        } else {
          descriptions.push_back(ports[i]);
        }
      } else {
        descriptions.push_back(ports[i]);
      }
    }
    jack_free(ports);
  }

  // Set default to first physical capture port if available
  const char **physical_ports =
      jack_get_ports(common_data.client, nullptr, JACK_DEFAULT_AUDIO_TYPE,
                     JackPortIsPhysical | JackPortIsOutput);
  if (physical_ports && physical_ports[0]) {
    defaultDevice = physical_ports[0];
    jack_free(physical_ports);
  } else if (!names.empty()) {
    defaultDevice = names[0];
  } else {
    defaultDevice = "";
  }
}

string CSoundInJack::GetItemName() { return dev; }

void CSoundInJack::SetItem(string sNewDevice) {
  if (dev != sNewDevice) {
    dev = sNewDevice;
    device_changed = true;
  }
}

std::string CSoundInJack::GetVersion() {
  return std::string(jack_get_version_string());
}

void CSoundInJack::Init(int iNewBufferSize, bool bNewBlocking) {
  if (device_changed == false)
    return;

  iBufferSize = iNewBufferSize;
  bBlocking = bNewBlocking;

  const char **l = jack_port_get_connections(capture_data.left);
  const char **r = jack_port_get_connections(capture_data.right);
  if (l || r)
    Close();

  if (l)
    free(l);
  if (r)
    free(r);

  int err = jack_connect(data.client, source.first.c_str(),
                         jack_port_name(capture_data.left));
  if (err) {
    cout << "err " << err << " can't connect " << source.first << " to "
         << jack_port_name(capture_data.left) << endl;
  }

  err = jack_connect(common_data.client, source.second.c_str(),
                     jack_port_name(capture_data.right));
  if (err) {
    cout << "err " << err << " can't connect " << source.second << " to "
         << jack_port_name(capture_data.right) << endl;
  }
  device_changed = false;
}

bool CSoundInJack::Read(CVector<short> &psData) {
  if (device_changed)
    Init(iBufferSize, bBlocking);

  size_t bytes = iBufferSize * sizeof(short);
  const int delay_ms = 100;
#ifdef _WIN32
  while (jack_ringbuffer_read_space(capture_data.buff) < bytes) {
    Sleep(delay_ms);
  }
#else
  timespec delay;
  delay.tv_sec = 0;
  const long one_ms = 1000000L; // nanoseconds
  delay.tv_nsec = delay_ms * one_ms;
  while (jack_ringbuffer_read_space(capture_data.buff) < bytes) {
    nanosleep(&delay, NULL);
  }
#endif
  char *buffer = (char *)&psData[0];
  // short buffer[16384];
  size_t n = jack_ringbuffer_read(capture_data.buff, (char *)&buffer[0], bytes);
  /*
  short smax=-32767, smin=32767;
  for(int i=0; i<iBufferSize; i++)
  {
      if(smax<buffer[i]) smax = buffer[i];
      if(smin>buffer[i]) smin = buffer[i];
  }
  cout << iBufferSize << " " << setw(8) << smin << " " << setw(8) << smax <<
  endl;
  */
  if (n != bytes) {
    capture_data.underruns++;
    cerr << "jack read " << n << " wanted " << bytes << endl;
    return true;
  }
  return false;
}

void CSoundInJack::Close() {
  jack_port_disconnect(common_data.client, capture_data.left);
  jack_port_disconnect(common_data.client, capture_data.right);
  device_changed = true;
}

CSoundOutJack::CSoundOutJack()
    : iBufferSize(0), bBlocking(true), device_changed(true), play_data(),
      dev("") {
  if (common_data.client == NULL)
    common_data.initialise();

  if (common_data.is_active && jack_deactivate(common_data.client)) {
    throw "Jack: cannot deactivate client";
  }
  common_data.is_active = false;

  play_data.left =
      jack_port_register(common_data.client, "output_0",
                         JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0);
  play_data.right =
      jack_port_register(common_data.client, "output_1",
                         JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0);

  if ((play_data.left == NULL) || (play_data.right == NULL)) {
    throw "Jack: no more ports available";
  }

  common_data.play_data = &play_data;
  ports.load(common_data.client, JackPortIsInput);

  if (jack_activate(common_data.client)) {
    throw "Jack: cannot activate client";
  }
  common_data.is_active = true;
}

CSoundOutJack::~CSoundOutJack() {
  Close();
  if (common_data.is_active && jack_deactivate(common_data.client)) {
    throw "Jack: cannot deactivate client";
  }
  common_data.is_active = false;
  common_data.capture_data = NULL;
  if (jack_activate(common_data.client)) {
    throw "Jack: cannot activate client";
  }
  common_data.is_active = true;
}

CSoundOutJack::CSoundOutJack(const CSoundOutJack &e)
    : iBufferSize(e.iBufferSize), bBlocking(e.bBlocking), dev(e.dev) {}

CSoundOutJack &CSoundOutJack::operator=(const CSoundOutJack &e) {
  iBufferSize = e.iBufferSize;
  bBlocking = e.bBlocking;
  play_data = e.play_data;
  dev = e.dev;
  return *this;
}

void CSoundOutJack::Enumerate(std::vector<std::string> &names,
                              std::vector<std::string> &descriptions,
                              std::string &defaultDevice) {
  names.clear();
  descriptions.clear();

  // Get all playback ports (physical inputs that we can send to)
  const char **ports = jack_get_ports(common_data.client, nullptr,
                                      JACK_DEFAULT_AUDIO_TYPE, JackPortIsInput);

  if (ports) {
    for (int i = 0; ports[i] != nullptr; i++) {
      names.push_back(ports[i]);

      // Try to get port alias as friendly name
      jack_port_t *port = jack_port_by_name(common_data.client, ports[i]);
      if (port) {
        char *aliases[2];
        aliases[0] = new char[jack_port_name_size()];
        aliases[1] = new char[jack_port_name_size()];
        int num_aliases = jack_port_get_aliases(port, aliases);
        if (num_aliases > 0) {
          descriptions.push_back(std::string(aliases[0]));
        } else {
          descriptions.push_back(std::string(ports[i]));
        }
      } else {
        descriptions.push_back(std::string(ports[i]));
      }
    }
    jack_free(ports);
  }

  // Set default to first physical playback port if available
  const char **physical_ports =
      jack_get_ports(common_data.client, nullptr, JACK_DEFAULT_AUDIO_TYPE,
                     JackPortIsPhysical | JackPortIsInput);
  if (physical_ports && physical_ports[0]) {
    defaultDevice = physical_ports[0];
    jack_free(physical_ports);
  } else if (!names.empty()) {
    defaultDevice = names[0];
  } else {
    defaultDevice = "";
  }
}

string CSoundOutJack::GetItemName() { return dev; }

void CSoundOutJack::SetItem(string sNewDevice) {
  if (dev != sNewDevice) {
    dev = sNewDevice;
    device_changed = true;
  }
}

std::string CSoundOutJack::GetVersion() {
  return std::string(jack_get_version_string());
}

void CSoundOutJack::Init(int iNewBufferSize, bool bNewBlocking) {
  if (device_changed == false)
    return;

  iBufferSize = iNewBufferSize;
  bBlocking = bNewBlocking;

  const char **l = jack_port_get_connections(play_data.left);
  const char **r = jack_port_get_connections(play_data.right);
  if (l || r)
    Close();

  if (l)
    free(l);

  pair<string, string> sink = ports.get_ports(dev);

  int err = jack_connect(data.client, jack_port_name(play_data.left),
                         sink.first.c_str());
  if (err) {
    cout << "err " << err << " can't connect " << jack_port_name(play_data.left)
         << " to " << sink.first << endl;
  }
  err = jack_connect(data.client, jack_port_name(play_data.right),
                     sink.second.c_str());
  if (err) {
    cout << "err " << err << " can't connect "
         << jack_port_name(play_data.right) << " to " << sink.second << endl;
  }
  device_changed = false;
}

bool CSoundOutJack::Write(CVector<short> &psData) {
  if (device_changed)
    Init(iBufferSize, bBlocking);

  size_t bytes = psData.Size() * sizeof(short);
  if (jack_ringbuffer_write(play_data.buff, (char *)&psData[0], bytes) <
      bytes) {
    play_data.overruns++;
    return true;
  }
  return false;
}

void CSoundOutJack::Close() {
  jack_port_disconnect(common_data.client, play_data.left);
  jack_port_disconnect(common_data.client, play_data.right);
  device_changed = true;
}

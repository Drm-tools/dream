/******************************************************************************\
* Technische Universitaet Darmstadt, Institut fuer Nachrichtentechnik
* Copyright (c) 2001
*
* Author(s):
*	Alexander Kurpiers, Volker Fischer
*
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
*
\******************************************************************************/

#include "sound.h"


#ifdef WITH_SOUND
/******************************************************************************/
/******************************************************************************/
/************************** OSS Sound interface *******************************/
/******************************************************************************/
/******************************************************************************/
#ifdef USE_DEVDSP

#include <linux/soundcard.h>
#include <errno.h>

static int fdSound = 0;


void CSound::InitIF(int & fdSound)
{
	int arg;      /* argument for ioctl calls */
	int status;   /* return status of system calls */
	
	printf("fdsound: %d\n", fdSound);
	if (fdSound >0) 
	{
		printf("already open\n");
		return;	// already open
	}

	/* Open sound device (Use O_RDWR only when writing a program which is
	   going to both record and play back digital audio) */
	fdSound = open("/dev/dsp", O_RDWR | O_NONBLOCK);
	if (fdSound < 0) 
    {   
		perror("open of /dev/dsp failed");
		exit(1);
    }
	

#if 0    
	/* Number of buffers and buffer size 
	   (If you need to set this parameter, you must set it directly after
	   opening the device. Executing another operation on the opened device can
	   cause the device driver to choose the settings itself after which it will
	   not allow you to change them) */
//	arg = (64<<16) | 13;	// 64 buffers of 8k each
	arg = (8<<16) | 16;	// 8 buffers of 64k each
	// hmm, the total size is 64k :-(
#endif		
	status = ioctl(fdSound, SNDCTL_DSP_SETFRAGMENT, &arg);
	if (status == -1)
		perror("SNDCTL_DSP_SETFRAGMENT ioctl failed");
printf("fragment %x\n", arg);

	/* Get ready for us.
	   ioctl(audio_fd, SNDCTL_DSP_SYNC, 0) can be used when application wants 
	   to wait until last byte written to the device has been played (it doesn't
	   wait in recording mode). After that the call resets (stops) the device
	   and returns back to the calling program. Note that this call may take
	   several seconds to execute depending on the amount of data in the 
	   buffers. close() calls SNDCTL_DSP_SYNC automaticly */
	ioctl(fdSound, SNDCTL_DSP_SYNC, 0);

	/* Set sampling parameters always so that number of channels (mono/stereo) 
	   is set before selecting sampling rate! */
	/* Set number of channels (0=mono, 1=stereo) */
	arg = NO_IN_OUT_CHANNELS - 1;
	status = ioctl(fdSound, SNDCTL_DSP_STEREO, &arg);
	if (status == -1)
		perror("SNDCTL_DSP_CHANNELS ioctl failed");
	if (arg != (NO_IN_OUT_CHANNELS - 1))
		perror("unable to set number of channels");
	

	/* Sampling rate */
	arg = SOUNDCRD_SAMPLE_RATE;
	status = ioctl(fdSound, SNDCTL_DSP_SPEED, &arg);
	if (status == -1)
		perror("SNDCTL_DSP_SPEED ioctl failed");
	if (arg != SOUNDCRD_SAMPLE_RATE)
		perror("unable to set sample rate");
	

	/* Sample size */
	arg = (BITS_PER_SAMPLE == 16) ? AFMT_S16_LE : AFMT_U8;      
	status = ioctl(fdSound, SNDCTL_DSP_SAMPLESIZE, &arg);
	if (status == -1)
		perror("SNDCTL_DSP_SAMPLESIZE ioctl failed");
	if (arg != ((BITS_PER_SAMPLE == 16) ? AFMT_S16_LE : AFMT_U8))
		perror("unable to set sample size");


	/* Print out capabilities of the sound card */
	printf("\nCapabilities:\n");
	status = ioctl(fdSound, SNDCTL_DSP_GETCAPS, &arg);
	if (status ==  -1)
		perror("SNDCTL_DSP_GETCAPS ioctl failed");
	printf(
		"  revision: %d\n"
		"  full duplex: %s\n"
		"  real-time: %s\n"
		"  batch: %s\n"
		"  coprocessor: %s\n" 
		"  trigger: %s\n"
		"  mmap: %s\n",
		arg & DSP_CAP_REVISION,
		(arg & DSP_CAP_DUPLEX) ? "yes" : "no",
		(arg & DSP_CAP_REALTIME) ? "yes" : "no",
		(arg & DSP_CAP_BATCH) ? "yes" : "no",
		(arg & DSP_CAP_COPROC) ? "yes" : "no",
		(arg & DSP_CAP_TRIGGER) ? "yes" : "no",
		(arg & DSP_CAP_MMAP) ? "yes" : "no");
	if (ioctl(fdSound, SNDCTL_DSP_GETBLKSIZE, &arg) == -1)
		 perror("SNDCTL_DSP_GETBLKSIZE");
printf("fragsize %d\n", arg);
}


/* Wave in ********************************************************************/
void CSound::InitRecording(int iNewBufferSize)
{
	printf("initrec %d\n", iNewBufferSize);

	/* Save buffer size */
	iInBufferSize = iNewBufferSize;

	/* Allocate memory for temporary record buffer */
	if (tmprecbuf != NULL)
		delete[] tmprecbuf;
	tmprecbuf = new short int[iNewBufferSize * NO_IN_OUT_CHANNELS];
	
	InitIF(fdSound);
}

void CSound::StopRecording()
{
	printf("stoprec\n");

	if (fdSound >0)
		close(fdSound);

	fdSound = 0;
}
void CSound::Read(CVector<short>& psData)
{
	int size;
	int start;
	int ret;
	
	/* Reset start position of reading and set read block size */
	start = 0;
	size = iInBufferSize * NO_IN_OUT_CHANNELS * BYTES_PER_SAMPLE;

	while (size) 
	{
		ret = read(fdSound, &tmprecbuf[ start ], 
			(size > SSIZE_MAX) ? SSIZE_MAX : size);
		
		if (ret < 0) 
		{
			if (errno == EINTR || errno == EAGAIN) 
			{
//printf(".");
				continue;
			}
			perror("CSound:Read");
			exit(1);
		}
		size -= ret;
		start += ret / BYTES_PER_SAMPLE;
	}
	
	/* Copy data from temporary buffer in output buffer */
	for (int i = 0; i < iInBufferSize; i++)
		psData[i] = tmprecbuf[NO_IN_OUT_CHANNELS * i + RECORDING_CHANNEL];


// TEST
#if 0
static FILE* pFile = fopen("test/recsamples.dat", "w");
for (int i = 0; i < iInBufferSize; i++)
	fprintf(pFile, "%d ", psData[i]);		
fflush(pFile);
#endif
}


/* Wave out *******************************************************************/
void CSound::InitPlayback(int iNewBufferSize)
{
	printf("initplay %d\n", iNewBufferSize);
	
	/* Save buffer size */
	iBufferSize = iNewBufferSize;
	
	InitIF( fdSound );
}

void CSound::Write(CVector<short>& psData)
{
	int size = iBufferSize * BYTES_PER_SAMPLE;
	int start = 0;
	int ret;
	
	/* FIXME in the moment this is implemented with blocking write
	   this is not good! But the sound interface only accepts 64 kB.
	   Solution is to use an intermediate buffer and select() or something */
	   
//	audio_buf_info info;
//ioctl(fdSound, SNDCTL_DSP_GETOSPACE, &info);
//printf("fr %d frt %d frs %d by %d\n", info.fragments, info.fragstotal, 
//	info.fragsize, info.bytes);


	while (size) {

		ret = write(fdSound, &psData[start],(size > SSIZE_MAX) ? SSIZE_MAX : size);
		if (ret < 0) {
			if (errno == EINTR || errno == EAGAIN) 
			{
				continue;
			}
			perror("CSound:Write");
			exit(1);
		}
		size -= ret;
		start += ret / BYTES_PER_SAMPLE;
	}
}
#endif







/******************************************************************************/
/******************************************************************************/
/************************** ALSA Sound interface ******************************/
/******************************************************************************/
/******************************************************************************/
#ifdef USE_ALSA

#define ALSA_PCM_NEW_HW_PARAMS_API
#define ALSA_PCM_NEW_SW_PARAMS_API

#include <sys/asoundlib.h>

static snd_pcm_t *rhandle = NULL;
static snd_pcm_t *phandle = NULL;

/* playback/record device directly to the kernel without sample rate conversion 
   - we do it on our own	*/
static const char *device = "hw:0,0";	


/* Wave in ********************************************************************/
void CSound::InitRecording(int iNewBufferSize){
 	
	int err, dir;
        snd_pcm_hw_params_t *hwparams;
        snd_pcm_sw_params_t *swparams;
	unsigned int rrate;
	unsigned int buffer_time = 4*5000;	// 4*500ms
	unsigned int period_time =   5000;	// 500ms
	snd_pcm_uframes_t buffer_size;
	snd_pcm_uframes_t period_size;

	printf("initrec %d\n", iNewBufferSize);

	/* Save buffer size */
	iInBufferSize = iNewBufferSize;

	/* Allocate memory for temporary record buffer */
	if (tmprecbuf != NULL)
		delete[] tmprecbuf;
	tmprecbuf = new short int[iNewBufferSize * NO_IN_OUT_CHANNELS];
	

	if (rhandle != NULL) {
		snd_pcm_close( rhandle );
	}
	
	if ( err = snd_pcm_open( &rhandle, device, SND_PCM_STREAM_CAPTURE, 0 )) {
                printf("Playback open error: %s\n", snd_strerror(err));
                return;	
	}

        snd_pcm_hw_params_alloca(&hwparams);
        snd_pcm_sw_params_alloca(&swparams);

	
		/* choose all parameters */
        err = snd_pcm_hw_params_any(rhandle, hwparams);
        if (err < 0) {
                printf("Broken configuration for record: no configurations available: %s\n", snd_strerror(err));
                return;
        }
        /* set the interleaved read/write format */
        err = snd_pcm_hw_params_set_access(rhandle, hwparams, SND_PCM_ACCESS_MMAP_INTERLEAVED);
        if (err < 0) {
                printf("Access type not available for record: %s\n", snd_strerror(err));
                return;

        }
        /* set the sample format */
        err = snd_pcm_hw_params_set_format(rhandle, hwparams, SND_PCM_FORMAT_S16);
        if (err < 0) {
                printf("Sample format not available for record: %s\n", snd_strerror(err));
                return;
        }
        /* set the count of channels */
        err = snd_pcm_hw_params_set_channels(rhandle, hwparams, NO_IN_OUT_CHANNELS);
        if (err < 0) {
                printf("Channels count (%i) not available for records: %s\n", NO_IN_OUT_CHANNELS, snd_strerror(err));
                return;
        }
        /* set the stream rate */
        rrate = SOUNDCRD_SAMPLE_RATE;
        err = snd_pcm_hw_params_set_rate_near(rhandle, hwparams, &rrate, 0);
        if (err < 0) {
                printf("Rate %iHz not available for record: %s\n", rrate, snd_strerror(err));
                return;        err = snd_pcm_hw_params_get_buffer_size(hwparams, &buffer_size);

        }
        if (rrate != SOUNDCRD_SAMPLE_RATE) {
                printf("Rate doesn't match (requested %iHz, get %iHz)\n", rrate, err);
                return;
        }        err = snd_pcm_hw_params_get_buffer_size(hwparams, &buffer_size);

        /* set the buffer time */
        err = snd_pcm_hw_params_set_buffer_time_near(rhandle, hwparams, &buffer_time, &dir);
        if (err < 0) {
                printf("Unable to set buffer time %i for record: %s\n", buffer_time, snd_strerror(err));
                return;
        }
        err = snd_pcm_hw_params_get_buffer_size(hwparams, &buffer_size);
        if (err < 0) {
                printf("Unable to get buffer size for record: %s\n", snd_strerror(err));
                return;
        }
        /* set the period time */
        err = snd_pcm_hw_params_set_period_time_near(rhandle, hwparams, &period_time, &dir);
        if (err < 0) {
                printf("Unable to set period time %i for record: %s\n", period_time, snd_strerror(err));
                return;
        }
        err = snd_pcm_hw_params_get_period_size(hwparams, &period_size, &dir);
        if (err > 0) {
                printf("Unable to get period size for record: %s\n", snd_strerror(err));
                return;
        }
        /* write the parameters to device */
        err = snd_pcm_hw_params(rhandle, hwparams);
        if (err < 0) {
                printf("Unable to set hw params for record: %s\n", snd_strerror(err));
                return;
        }
	        /* get the current swparams */
        err = snd_pcm_sw_params_current(rhandle, swparams);
        if (err < 0) {
                printf("Unable to determine current swparams for record: %s\n", snd_strerror(err));
                return;
        }
        /* start the transfer when the buffer is full */
        err = snd_pcm_sw_params_set_start_threshold(rhandle, swparams, buffer_size);
        if (err < 0) {
                printf("Unable to set start threshold mode for record: %s\n", snd_strerror(err));
                return;
        }
        /* allow the transfer when at least period_size samples can be processed */
        err = snd_pcm_sw_params_set_avail_min(rhandle, swparams, period_size);
        if (err < 0) {
                printf("Unable to set avail min for record: %s\n", snd_strerror(err));
                return;
        }
        /* align all transfers to 1 sample */
        err = snd_pcm_sw_params_set_xfer_align(rhandle, swparams, 1);
        if (err < 0) {
                printf("Unable to set transfer align for record: %s\n", snd_strerror(err));
                return;
        }
        /* write the parameters to the record device */
        err = snd_pcm_sw_params(rhandle, swparams);
        if (err < 0) {
                printf("Unable to set sw params for record: %s\n", snd_strerror(err));
                return;
        }
printf("record init done\n");

}

void CSound::StopRecording()
{
	printf("stoprec\n");

	if (rhandle != NULL)
		snd_pcm_close( rhandle );

	rhandle = NULL;
}

void CSound::Read(CVector<short>& psData)
{
	int size;
	int start;
	int ret;
	
	/* Reset start position of reading and set read block size */
	start = 0;
	size = iInBufferSize;

	while (size) 
	{
		ret = snd_pcm_avail_update(rhandle);
printf("r %d %d available %d state %d\n", size, start, ret, snd_pcm_state(rhandle));
		ret = snd_pcm_mmap_readi(rhandle, &tmprecbuf[start], size);
printf("ret: %d\n", ret);
		if (ret < 0) 
		{
			if (ret == -EAGAIN) 
			{
//printf(".");
				continue;
			} else if (ret == -EPIPE) {    /* under-run */
			printf("prepare\n");
        			ret = snd_pcm_prepare(rhandle);
        			if (ret < 0)
                			printf("Can't recover from undretun, prepare failed: %s\n", snd_strerror(ret));
        			continue;
			} else if (ret == -ESTRPIPE) {
			printf("strpipe\n");
        			while ((ret = snd_pcm_resume(rhandle)) == -EAGAIN)
                			sleep(1);       /* wait until the suspend flag is released */
        			if (ret < 0) {
                			ret = snd_pcm_prepare(rhandle);
                			if (ret < 0)
                        			printf("Can't recover from suspend, prepare failed: %s\n", snd_strerror(ret));
        			}
        			continue;
			} else {
                                printf("CSound::Read: %s\n", snd_strerror(ret));
                                exit(1);
                        }
		}
		size -= ret;
		start += ret;
	}
	
	/* Copy data from temporary buffer in output buffer */
	for (int i = 0; i < iInBufferSize; i++)
		psData[i] = tmprecbuf[NO_IN_OUT_CHANNELS * i + RECORDING_CHANNEL];

}


/* Wave out *******************************************************************/
void CSound::InitPlayback(int iNewBufferSize)
{
	int err, dir;
        snd_pcm_hw_params_t *hwparams;
        snd_pcm_sw_params_t *swparams;
	unsigned int rrate;
	unsigned int buffer_time = 4*500000;	// 4*500ms
	unsigned int period_time =   500000;	// 500ms
	snd_pcm_uframes_t buffer_size;
	snd_pcm_uframes_t period_size;

	printf("initplay %d\n", iNewBufferSize);
	
	if (phandle != NULL) {
printf("already open!\n");
		snd_pcm_close( phandle );
	}
	
	/* Save buffer size */
	iBufferSize = iNewBufferSize;

	if ( err = snd_pcm_open( &phandle, device, SND_PCM_STREAM_PLAYBACK, 0 )) {
                printf("Playback open error: %s\n", snd_strerror(err));
                return;	
	}

        snd_pcm_hw_params_alloca(&hwparams);
        snd_pcm_sw_params_alloca(&swparams);

	
	/* choose all parameters */
        err = snd_pcm_hw_params_any(phandle, hwparams);
        if (err < 0) {
                printf("Broken configuration for playback: no configurations available: %s\n", snd_strerror(err));
                return;
        }
        /* set the interleaved read/write format */
        err = snd_pcm_hw_params_set_access(phandle, hwparams, SND_PCM_ACCESS_MMAP_INTERLEAVED);
        if (err < 0) {
                printf("Access type not available for playback: %s\n", snd_strerror(err));
                return;

        }
        /* set the sample format */
        err = snd_pcm_hw_params_set_format(phandle, hwparams, SND_PCM_FORMAT_S16);
        if (err < 0) {
                printf("Sample format not available for playback: %s\n", snd_strerror(err));
                return;
        }
        /* set the count of channels */
        err = snd_pcm_hw_params_set_channels(phandle, hwparams, NO_IN_OUT_CHANNELS);
        if (err < 0) {
                printf("Channels count (%i) not available for playbacks: %s\n", NO_IN_OUT_CHANNELS, snd_strerror(err));
                return;
        }
        /* set the stream rate */
        rrate = SOUNDCRD_SAMPLE_RATE;
        err = snd_pcm_hw_params_set_rate_near(phandle, hwparams, &rrate, 0);
        if (err < 0) {
                printf("Rate %iHz not available for playback: %s\n", rrate, snd_strerror(err));
                return;        err = snd_pcm_hw_params_get_buffer_size(hwparams, &buffer_size);

        }
        if (rrate != SOUNDCRD_SAMPLE_RATE) {
                printf("Rate doesn't match (requested %iHz, get %iHz)\n", rrate, err);
                return;
        }        err = snd_pcm_hw_params_get_buffer_size(hwparams, &buffer_size);

        /* set the buffer time */
        err = snd_pcm_hw_params_set_buffer_time_near(phandle, hwparams, &buffer_time, &dir);
        if (err < 0) {
                printf("Unable to set buffer time %i for playback: %s\n", buffer_time, snd_strerror(err));
                return;
        }
        err = snd_pcm_hw_params_get_buffer_size(hwparams, &buffer_size);
        if (err < 0) {
                printf("Unable to get buffer size for playback: %s\n", snd_strerror(err));
                return;
        }
        /* set the period time */
        err = snd_pcm_hw_params_set_period_time_near(phandle, hwparams, &period_time, &dir);
        if (err < 0) {
                printf("Unable to set period time %i for playback: %s\n", period_time, snd_strerror(err));
                return;
        }
        err = snd_pcm_hw_params_get_period_size(hwparams, &period_size, &dir);
        if (err > 0) {
                printf("Unable to get period size for playback: %s\n", snd_strerror(err));
                return;
        }
        /* write the parameters to device */
        err = snd_pcm_hw_params(phandle, hwparams);
        if (err < 0) {
                printf("Unable to set hw params for playback: %s\n", snd_strerror(err));
                return;
        }
	        /* get the current swparams */
        err = snd_pcm_sw_params_current(phandle, swparams);
        if (err < 0) {
                printf("Unable to determine current swparams for playback: %s\n", snd_strerror(err));
                return;
        }
        /* start the transfer when the buffer is full */
        err = snd_pcm_sw_params_set_start_threshold(phandle, swparams, buffer_size);
        if (err < 0) {
                printf("Unable to set start threshold mode for playback: %s\n", snd_strerror(err));
                return;
        }
        /* allow the transfer when at least period_size samples can be processed */
        err = snd_pcm_sw_params_set_avail_min(phandle, swparams, period_size);
        if (err < 0) {
                printf("Unable to set avail min for playback: %s\n", snd_strerror(err));
                return;
        }
        /* align all transfers to 1 sample */
        err = snd_pcm_sw_params_set_xfer_align(phandle, swparams, 1);
        if (err < 0) {
                printf("Unable to set transfer align for playback: %s\n", snd_strerror(err));
                return;
        }
        /* write the parameters to the playback device */
        err = snd_pcm_sw_params(phandle, swparams);
        if (err < 0) {
                printf("Unable to set sw params for playback: %s\n", snd_strerror(err));
                return;
        }
printf("init done\n");
}

/*
 *   Underrun and suspend recovery
 */
 
void CSound::Write(CVector<short>& psData)
{
	int size = iBufferSize;
	int start = 0;
	int ret;
	while (size) {
printf("w %d %d available %d\n", size, start, snd_pcm_avail_update(phandle));	

		ret = snd_pcm_mmap_writei(phandle, &psData[start], size);
		if (ret < 0) {
printf("ret: %d\n", ret);
			if (ret ==  -EAGAIN) {
				continue;
			} else if (ret == -EPIPE) {    /* under-run */
			printf("prepare\n");
        			ret = snd_pcm_prepare(phandle);
        			if (ret < 0)
                			printf("Can't recover from undretun, prepare failed: %s\n", snd_strerror(ret));
        			continue;
			} else if (ret == -ESTRPIPE) {
			printf("strpipe\n");
        			while ((ret = snd_pcm_resume(phandle)) == -EAGAIN)
                			sleep(1);       /* wait until the suspend flag is released */
        			if (ret < 0) {
                			ret = snd_pcm_prepare(phandle);
                			if (ret < 0)
                        			printf("Can't recover from suspend, prepare failed: %s\n", snd_strerror(ret));
        			}
        			continue;
			} else {
                                printf("Write error: %s\n", snd_strerror(ret));
                                exit(1);
                        }
                        break;  /* skip one period */
		}
printf("size %d ret %d\n", size, ret);	
		size -= ret;
		start += ret * NO_IN_OUT_CHANNELS;
	}
}
#endif






/******************************************************************************/
/******************************************************************************/
/************************** ARTS Sound interface ******************************/
/******************************************************************************/
/******************************************************************************/
/* this code seems to work, unfortunatly arts recording is broken :-( A sine 
   wave gets completely distorted */
#ifdef HAVE_ARTS

#include <artsc.h>

static arts_stream_t pstream = NULL;
static arts_stream_t rstream = NULL;


/* Wave in ********************************************************************/
void CSound::InitRecording(int iNewBufferSize)
{
	int arg;      /* argument for ioctl calls */
	int status;   /* return status of system calls */
	
	printf("\ninitrec %d\n",iNewBufferSize);
	
	/* Save buffer size */
	iInBufferSize = iNewBufferSize ;
	/* allocate memory for temporary record buffer */
	if ( tmprecbuf != NULL)
		delete[] tmprecbuf;
	tmprecbuf = new short int[ iNewBufferSize * NO_IN_OUT_CHANNELS ];
	
	if (rstream != NULL)
		arts_close_stream( rstream );

	
	/* Init arts */
	status = arts_init();
	
	if (status < 0) 
	{   
		fprintf(stderr, "arts_init error: %s\n", arts_error_text(status));
		return;
	}
	
	/* Set sampling parameters */
	rstream = arts_record_stream(SOUNDCRD_SAMPLE_RATE, BITS_PER_SAMPLE, 
		NO_IN_OUT_CHANNELS, "DRM");
	
	/* Set to blocking */
	status = arts_stream_set( rstream, ARTS_P_BLOCKING, 1);
	if (status != 1)
		fprintf(stderr, "arts_stream_set (InitRecording): ARTS_P_BLOCKING error %s\n", 
		arts_error_text(status));
		
	/* Set to buffer size */
	status = arts_stream_set( rstream, ARTS_P_BUFFER_TIME, 400); // 400ms buffer
	if (status != 1)
		fprintf(stderr, "arts_stream_set (InitRecording): ARTS_P_BUFFER_TIME error %s\n", 
		arts_error_text(status));
	
}

void CSound::StopRecording()
{
	printf("stoprec\n");
	if (rstream != NULL)
		arts_close_stream( rstream );
}


void CSound::Read(CVector<short>& psData)
{
	int size = iInBufferSize * NO_IN_OUT_CHANNELS * BYTES_PER_SAMPLE;
	int start = 0;
	int ret;
	
	while (size) {
		ret = arts_read(rstream, &tmprecbuf[start], (size>32768) ? 32768 : size);
		if (ret < 0) {
			fprintf(stderr, "CSound:Read error %s\n", arts_error_text(ret));
			exit(1);
		}
if (size != ret) printf("ret: %d\n", ret);
		size -= ret;
		start += ret / BYTES_PER_SAMPLE;
	}

	/* We read stereo samples, but actually we want only one channel */
	for (int i = 0; i < iInBufferSize; i++)
		psData[i] = tmprecbuf[NO_IN_OUT_CHANNELS * i + RECORDING_CHANNEL];
	


#ifdef _DEBUG_
// TEST
static FILE* pFile = fopen("test/recsamples.dat", "w");
for (int i = 0; i < iInBufferSize; i++)
	fprintf(pFile, "%d ", psData[i]);		
fflush(pFile);
#endif
}


/* Wave out *******************************************************************/
void CSound::InitPlayback(int iNewBufferSize)
{
	int arg;      /* argument for ioctl calls */
	int status;   /* return status of system calls */
	
	printf("\ninitplay %d\n", iNewBufferSize);
	
	/* Save buffer size */
	iBufferSize = iNewBufferSize;
	
	if (pstream != NULL)
		arts_close_stream( pstream );
	
	/* Init arts */
	status = arts_init();
	
	if (status < 0) 
    {   
		fprintf(stderr, "arts_init error: %s\n", arts_error_text(status));
        return;
    }
    
	/* Set sampling parameters */
	pstream = arts_play_stream( SOUNDCRD_SAMPLE_RATE, BITS_PER_SAMPLE, 
		NO_IN_OUT_CHANNELS, "DRM");
	
	/* Set to non-blocking */
//	status = arts_stream_set( pstream, ARTS_P_BLOCKING, 0);
	status = arts_stream_set( pstream, ARTS_P_BLOCKING, 1);
	if (status != 0)
		fprintf(stderr, "arts_stream_set: ARTS_P_BLOCKING error %s\n", arts_error_text(status));

	/* set buffer size */
	status = arts_stream_set( pstream, ARTS_P_BUFFER_SIZE, 
		4*iBufferSize * NO_IN_OUT_CHANNELS * BYTES_PER_SAMPLE);
	if (status != 0)
		fprintf(stderr, "arts_stream_set: ARTS_BUFFER_SIZE error %s\n", arts_error_text(status));
	
}

void CSound::Write(CVector<short>& psData)
{
	int size = iBufferSize * BYTES_PER_SAMPLE;
	int start = 0;
	int ret;
	
	while (size) 
	{
		ret = arts_write(pstream, &psData[start], size);
		if (ret < 0) 
		{
			fprintf(stderr, "CSound:Write error %s\n", arts_error_text(ret));
			exit(1);
		}
printf("w%d\n", ret);
		size -= ret;
		start += ret / BYTES_PER_SAMPLE;
	}
}
#endif
#endif

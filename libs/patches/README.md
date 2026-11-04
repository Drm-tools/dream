fdk-xhe-aac-low-bitrate.patch lowers the minimum xHE-AAC bit rates (mono 6 kbit/s, stereo
12 kbit/s) of a stock fdk-aac 3.0.0. It is only needed with a system fdk-aac: the vendored
copy in `../fdk-aac` (rafael2k's fork, branch `upstream/xhe-low-bitrate` merged into master)
already contains it, and the DRM HE-AAC encoder as well.

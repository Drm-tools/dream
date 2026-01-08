Building on windows.

1. There is a GitHub Action which successfully build for windows.
    a. It uses vcpkg in classic mode to install all the dependencies except:
      * qt
      * qwt
      * hamlib
    b. the vcpkg install command is:

        vcpkg --triplet x64-windows install \
            fftw3 zlib dlfcn-win32 winpcap pthreads libsndfile\
            fdk-aac[he-aac] opus speexdsp soapysdr
    c. Hamlib is installed from the binary 4.6.5 windows build in GitHub Hamlib/Hamlib
    d. Qt is installed from a GitHub action
    e. Qwt is installed from GitHub buaabyl/qwt_windows binaries. The header files are downloaded as the source tarball and extracted to the local include folder.      
    f. It uses qmake to make the Makefile and MSVC to complile and link

2. To get a development environment for windows
    a. Either QtCreator or Visual Studio is recommended. I haven't got VSCode to work.
    b. Make sure you have and are using the Native 64 bit Microsoft toolchain. I had x86 by  mistake!
    c. Install Qt using the official offline installer and choose the 'Archive' and install a 64 bit 5.12 version. Later versions might not work well with the Qwt binary or the source code or the platform.
    d. Make sure vcpkg is integrated. I put a vcpkg clone parallel to the dream clone.
    e. add a VCPKG_ROOT environment variable. Dream.pro wants this to include the installed folder in its include and lib paths.
    f. I couldn't get winpcap to install using vcpkg so I left it out.

Building inside the dev environment should enable debugging. I haven't managed this in VSCode but it works well for me with QtCreator in Linux with gcc/clang
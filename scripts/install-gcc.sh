#!/bin/bash

# Exit if fail
set -e

# Repository for gcc
sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test

# Update packages
sudo apt-get update -qq

# Install gcc
sudo apt-get -qq --allow-unauthenticated install gcc-${LIBSTDC_VERSION} g++-${LIBSTDC_VERSION}

# Update alternatives for gcc
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-${LIBSTDC_VERSION} 50
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-${LIBSTDC_VERSION} 50

# Export gcc
export CXX="g++-${LIBSTDC_VERSION}"
export CC="gcc-${LIBSTDC_VERSION}"

# Debug information
gcc --version
g++ --version


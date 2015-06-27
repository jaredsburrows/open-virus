#!/bin/bash

# Exit if fail
set -e

# Repository for clang
sudo add-apt-repository -y ppa:h-rayflood/llvm
sudo add-apt-repository -y ppa:h-rayflood/llvm-upper
sudo add-apt-repository -y ppa:h-rayflood/gcc-upper

# Update packages
sudo apt-get update -qq

# Install clang
sudo apt-get -qq --allow-unauthenticated install clang-${CLANG_VERSION} clang++-${CLANG_VERSION}

# Install libc++ for clang
CWD=$(pwd)
export CXXFLAGS="-std=c++0x -stdlib=libc++"
svn co --quiet http://llvm.org/svn/llvm-project/libcxx/trunk libcxx
cd libcxx/lib && bash buildit
sudo cp ./libc++.so.1.0 /usr/lib/
sudo mkdir /usr/include/c++/v1
cd .. && sudo cp -r include/* /usr/include/c++/v1/
cd /usr/lib && sudo ln -sf libc++.so.1.0 libc++.so
sudo ln -sf libc++.so.1.0 libc++.so.1 && cd $CWD

# Update alternatives for clang
sudo update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-${CLANG_VERSION} 50
sudo update-alternatives --install /usr/bin/clang clang /usr/bin/clang-${CLANG_VERSION} 50

# Export clang
export CXX="clang++-${CLANG_VERSION}"
export CC="clang-${CLANG_VERSION}"

# Debug information
clang --version
clang++ --version

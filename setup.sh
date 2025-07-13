#!/bin/bash

# Install dependencies
sudo apt-get update && \
sudo apt-get install -y \
    cmake \
    g++ \
    git \
    libflac-dev \
    libfreetype-dev \
    libgl1-mesa-dev \
    libglu1-mesa-dev \
    libogg-dev \
    libopenal-dev \
    libudev-dev \
    libvorbis-dev \
    libx11-dev \
    libxcursor-dev \
    libxi-dev \
    libxinerama-dev \
    libxrandr-dev \
    mesa-common-dev

# Build instructions
git reset --hard && \
git submodule foreach --recursive git clean -xfd && \
cmake -DCMAKE_INSTALL_PREFIX=SFML/install -B SFML/build SFML && \
cmake --build SFML/build --target install && \
rm -rf build && \
mkdir -p build && \
cd build && \
cmake .. && \
cmake --build .

# Run tests
ctest --output-on-failure
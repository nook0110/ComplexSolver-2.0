# Use official Ubuntu image
FROM gcc:15.1.0

# Install all required dependencies
RUN apt-get update && \
    apt-get install -y \
    cmake \
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
    mesa-common-dev \
    && rm -rf /var/lib/apt/lists/*

# Copy the project files
COPY . /ComplexSolver

WORKDIR /ComplexSolver

# Build instructions
RUN git reset --hard && \
    git submodule foreach --recursive git clean -xfd && \
    cmake -DCMAKE_INSTALL_PREFIX=SFML/install -B SFML/build SFML && \
    cmake --build SFML/build --target install && \
    rm -rf build && \
    mkdir -p build && \
    cd build && \
    cmake .. && \
    cmake --build .

# Default command to run tests
CMD ["ctest", "--output-on-failure"]
# Dockerfile for setting up a development environment for 3DS homebrew

FROM ubuntu:20.04

# Set environment variables
ENV DEBIAN_FRONTEND=noninteractive
ENV DEVKITPRO=/opt/devkitpro
ENV DEVKITARM=${DEVKITPRO}/devkitARM
ENV PATH=${PATH}:${DEVKITARM}/bin

# Install dependencies
RUN apt-get update && apt-get install -y --no-install-recommends \
    wget \
    unzip \
    build-essential \
    cmake \
    pkg-config \
    libssl-dev \
    libpng-dev \
    libjpeg-dev \
    zlib1g-dev \
    libglfw3-dev \
    libglm-dev \
    libogg-dev \
    libvorbis-dev \
    libtheora-dev \
    libopenal-dev \
    libudev-dev \
    libfreetype6-dev \
    libharfbuzz-dev \
    libtinyxml-dev \
    libzip-dev \
    ffmpeg \
    devkitpro-devkitarm \
    devkitpro-tools \
    libctru \
    citro3d \
    libsf2d

# Set working directory
WORKDIR /workspaces/DENTAKU

# Example: Download and install any additional dependencies if needed
# RUN wget -O some-library.zip http://example.com/some-library.zip && unzip some-library.zip && cd some-library && make && make install

# Example: Copy your project files into the container
# COPY . .

# Example: Build your project
# RUN make

# Example: Start your application
# CMD ["./your_executable"]

# Dockerfile for setting up a development environment for 3DS homebrew

FROM ubuntu:20.04

# Install dependencies
RUN apt-get update && apt-get install -y \
  devkitpro-devkitarm \
  devkitpro-tools \
  libctru \
  citro3d \
  libsf2d \
  ffmpeg

# Set environment variables
ENV DEVKITPRO=/opt/devkitpro
ENV DEVKITARM=${DEVKITPRO}/devkitARM
ENV PATH=${PATH}:${DEVKITARM}/bin

# Set working directory
WORKDIR /workspaces/DENTAKU/

# Example: Copy your project files into the container
# COPY . /workspaces/DENTAKU/

# Example: Build your project
# RUN make

# Example: Start your application
# CMD ["./your_executable"]

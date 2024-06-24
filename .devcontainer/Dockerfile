FROM ubuntu:20.04

# Install dependencies
RUN apt-get update && apt-get install -y \
  devkitpro-devkitarm \
  devkitpro-tools \
  libctru \
  citro3d \
  sf2dlib \
  ffmpeg

# Set environment variables
ENV DEVKITPRO=/opt/devkitpro
ENV DEVKITARM=${DEVKITPRO}/devkitARM
ENV PATH=${PATH}:${DEVKITARM}/bin

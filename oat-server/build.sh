#!/bin/bash

# Build and make project 
mkdir -p build && cd build
cmake ..
make

# Launch server
./disco-ps-core
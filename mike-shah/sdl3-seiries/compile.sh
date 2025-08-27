#!/usr/bin/bash

set -xe

g++ src/main.cpp -o out/hello_app -I./SDL/include/SDL3 -L./SDL/build/ -lSDL3

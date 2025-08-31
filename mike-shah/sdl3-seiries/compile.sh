#!/usr/bin/bash

set -xe

# mkdir -p ./out
# rm out/*

g++ src/main.cpp -o out/app -I./SDL/include/SDL3 -L./SDL/build/ -lSDL3

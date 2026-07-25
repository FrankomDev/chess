#!/usr/bin/env bash

mkdir build
cd build

g++ ../src/*.cpp -lraylib -o chess -Wall -Wextra
./chess

cd ..

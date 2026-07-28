#!/usr/bin/env bash

mkdir build
cd build

if [[ -z $(ldconfig -p | grep raylib) ]]
then
    echo "Install Raylib!!!!"
else
    g++ ../src/*.cpp -lraylib -o chess -Wall -Wextra -g
    ./chess
fi

cd ..

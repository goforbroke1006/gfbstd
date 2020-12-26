#!/bin/bash

set -e

mkdir -p ./build/
cd ./build/
rm -rf ./*
cmake ..
make
sudo make install
cd -

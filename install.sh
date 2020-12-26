#!/bin/bash

set -e

mkdir -p ./build/
cd ./build/
rm -rf ./*
cmake ..
make
make test
sudo make install
cd -

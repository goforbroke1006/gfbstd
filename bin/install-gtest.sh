#!/bin/bash

set -e

sudo apt-get install -y libgtest-dev
sudo apt-get install -y cmake

cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
sudo cp *.a /usr/lib
sudo cp ./lib/*.a /usr/lib

sudo mkdir -p /usr/local/lib/gtest/
sudo ln -s /usr/lib/libgtest.a /usr/local/lib/gtest/libgtest.a
sudo ln -s /usr/lib/libgtest_main.a /usr/local/lib/gtest/libgtest_main.a

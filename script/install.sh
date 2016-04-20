#!/bin/bash

SOURCE=${1}

mkdir $SOURCE"/build"
cd $SOURCE"/build"
cmake -G "Unix Makefiles" -D CMAKE_INSTALL_PREFIX=../ -D CMAKE_BUILD_TYPE=Debug ../
make install




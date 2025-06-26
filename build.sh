#!/bin/bash

set -e

if [ $# -gt 0 ] && [ $1 = "-r" ]; then
    echo "[WARN] All previous built files will be removed!"
    rm -rf build
fi

root_path=$(dirname $(readlink -f $0))
include_path="${root_path}/include"
src_path="${root_path}/src"

protoc ${root_path}/proto/*.proto --proto_path=${root_path}/proto --cpp_out=${root_path}/gen

cmake -S . -B build \
    -DCMAKE_BUILD_TYPE="Debug" \
    -DCMAKE_CXX_COMPILER="clang++" \
    -DCMAKE_TOOLCHAIN_FILE="${VCPKG_HOME}/scripts/buildsystems/vcpkg.cmake"

cmake --build build --parallel 1

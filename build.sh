#!/bin/bash

mkdir -p build
pushd build
cmake .. -DCMAKE_BUILD_TYPE=MinSizeRel
make -j$(nproc)
sudo make install
popd

pushd examples
gen_rfl
mkdir -p build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)
popd
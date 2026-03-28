#!/bin/bash

# 检查是否有 noroot 选项
noroot=true
for arg in "$@"
do
    if [ "$arg" == "noroot" ]; then
        noroot=true
    fi
done

mkdir -p build
pushd build
cmake .. -DCMAKE_BUILD_TYPE=MinSizeRel
if [ $? -ne 0 ]; then
    echo "CMake failed"
    exit 1
fi

make -j$(nproc)
if [ $? -ne 0 ]; then
    echo "Build failed"
    exit 1
fi
echo "Build completed."
echo "Running install..."
# 如果没有指定 noroot 选项，则执行 sudo make install
if [ "$noroot" == "false" ]; then
    sudo make install
    if [ $? -ne 0 ]; then
        echo "Install failed"
        exit 1
    fi
fi

echo "Running gen_rfl..."
cd ../examples
../bin/gen_rfl
if [ $? -ne 0 ]; then
    echo "gen_rfl failed"
    exit 1
fi

echo "Running build..."
cd build
cmake ..
make -j$(nproc)
popd
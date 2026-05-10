#!/bin/bash

# 检查是否有 notroot 选项
notroot=true
for arg in "$@"
do
    if [ "$arg" == "notroot" ]; then
        notroot=true
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
# 如果没有指定 notroot 选项，则执行 sudo make install
if [ "$notroot" == "false" ]; then
    sudo make install
    if [ $? -ne 0 ]; then
        echo "Install failed"
        exit 1
    fi
fi

echo "Running gen_rfl..."
function gen {
    FILE=$1
    ../bin/gen_rfl --file $FILE
    if [ $? -ne 0 ]; then
        echo "gen_rfl $FILE failed"
        exit 1
    fi
}
popd
pushd examples

# 执行前清除缓存头文件
echo "Clearing cache header files before execution..."
rm -f gen_rfl/referenced_headers.txt

gen node.h
gen node.cpp
gen base/common.h

# 执行后清除缓存头文件
echo "Clearing cache header files after execution..."
rm -f gen_rfl/referenced_headers.txt

echo "Running build..."
mkdir -p build
cd build && cmake .. -DCMAKE_BUILD_TYPE=MinSizeRel && make -j$(nproc)
popd

pushd performance
rm -f gen_rfl/referenced_headers.txt
gen node.h
gen node.cpp
rm -f gen_rfl/referenced_headers.txt

mkdir -p build
cd build && cmake .. -DCMAKE_BUILD_TYPE=MinSizeRel && make -j$(nproc)
popd


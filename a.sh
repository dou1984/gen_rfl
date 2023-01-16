#!/bin/bash

#source /opt/rh/devtoolset-10/enable 
g++ main.cpp -O2 -std=c++17 -o ./bin/genreflect -lgflags 2> ./build/compile.1.log

./bin/genreflect -header node.h -class base -member a,b,c,d,e,f,g,h,i,j,k,l,m,n,o -out ./example
./bin/genreflect -header node.h -class node -member h,x,y,z -out ./example

cd example
g++ -ggdb -O2 -std=c++17 -I.. -I. -o ../bin/main base.reflect.cpp node.reflect.cpp main.cpp 2> ../build/compile.2.log
cd ..
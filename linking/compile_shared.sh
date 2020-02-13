#!/usr/bin/bash
rm main
#rm *.a
rm *.o
rm *.so

g++ -c -fPIC main.cpp
g++ -c -fPIC calc.cpp
g++ -shared -fPIC -o libcalc.so calc.o main.o

g++ -o main libcalc.so



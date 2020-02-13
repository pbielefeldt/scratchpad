#!/usr/bin/bash
rm main
rm *.a
rm *.o

g++ -c main.cpp
g++ -c calc.cpp

ar crv libcalc.a calc.o
g++ -o main main.o -L. -lcalc -lm

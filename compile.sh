#!/bin/sh

rm -f src/*.gch
rm -f src/*/*.gch
rm -f src/*.o
rm -f src/*/*.o
g++ -g -std=c++0x -pthread src/main.cpp src/OscTransmitter* src/abstracts/* src/models/* src/constraints/* config/* src/osc/* src/ip/*
rm -f src/*.gch
rm -f src/*/*.gch
rm -f src/*.o
rm -f src/*/*.o

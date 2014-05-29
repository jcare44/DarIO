#!/bin/sh

rm -Rf src/*/*.gch
rm -Rf src/*/*.o
g++ -std=c++0x src/main.cpp src/abstracts/* src/models/* src/constraints/* config/* src/osc/* src/ip/*
rm -Rf src/*/*.gch
rm -Rf src/*/*.o

#!/bin/sh

rm -Rf src/*/*.gch
rm -Rf src/*/*.o
g++ -std=c++0x src/main.cpp src/abstracts/* src/models/* src/constraints/* config/*
rm -Rf src/*/*.gch
rm -Rf src/*/*.o

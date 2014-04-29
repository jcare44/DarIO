#!/bin/sh

rm -Rf src/*/*.gch
rm -Rf src/*/*.o
g++ src/main.cpp src/models/*
rm -Rf src/*/*.gch
rm -Rf src/*/*.o

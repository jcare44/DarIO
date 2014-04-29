#!/bin/sh

rm -Rf src/*/*.gch
rm -Rf src/*/*.o
g++ src/main.cpp src/models/* src/constraints/*
rm -Rf src/*/*.gch
rm -Rf src/*/*.o

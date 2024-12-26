#!/bin/bash

g++ -o binary_search main.cpp
./binary_search < .in > actual.out

if diff -q actual.out .out > /dev/null; then
    echo "Test passed."
else
    echo "Test failed."
    diff actual.out .out
fi

rm actual.out
rm binary_search
#!/bin/bash

g++ -o interpolation_search main.cpp
./interpolation_search < .in > actual.out

if diff -q actual.out .out > /dev/null; then
    echo "Test passed."
else
    echo "Test failed."
    diff actual.out .out
fi

rm actual.out
rm interpolation_search
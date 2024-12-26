#!/bin/bash

g++ -o merge_sort main.cpp
./merge_sort < .in > actual.out

if diff -q actual.out .out > /dev/null; then
    echo "Test passed."
else
    echo "Test failed."
    diff actual.out .out
fi

rm actual.out
rm merge_sort


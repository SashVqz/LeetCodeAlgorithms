#!/bin/bash

g++ -o red_black_tree main.cpp
./red_black_tree < .in > actual.out

if diff -q actual.out .out > /dev/null; then
    echo "Test passed."
else
    echo "Test failed."
    diff actual.out .out
fi

rm actual.out
rm red_black_tree
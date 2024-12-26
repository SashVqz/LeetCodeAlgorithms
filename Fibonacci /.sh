#!/bin/bash

g++ -o fibonacci main.cpp
./fibonacci < .in > actual.out

if diff -q actual.out .out > /dev/null; then
    echo "Test passed."
else
    echo "Test failed."
    diff actual.out .out
fi

rm actual.out
rm fibonacci
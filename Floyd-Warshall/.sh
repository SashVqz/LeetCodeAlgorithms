#!/bin/bash

g++ -o floyd_warshall main.cpp
./floyd_warshall < .in > actual.out

if diff -q actual.out .out > /dev/null; then
    echo "Test passed."
else
    echo "Test failed."
    diff actual.out .out
fi

rm actual.out
rm floyd_warshall
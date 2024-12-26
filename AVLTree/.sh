#!/bin/bash

g++ -o avl_tree main.cpp
./avl_tree < .in > actual.out

if diff -q actual.out .out > /dev/null; then
    echo "Test passed."
else
    echo "Test failed."
    diff actual.out .out
fi

rm actual.out
rm avl_tree
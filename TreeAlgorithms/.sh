#!/bin/bash

g++ -o tree_traversal main.cpp
./tree_traversal < .in > actual.out

if diff -q actual.out .out > /dev/null; then
    echo "Test passed."
else
    echo "Test failed."
    diff actual.out .out
fi

rm actual.out
rm tree_traversal
#!/bin/bash

g++ -o sudoku_solver main.cpp
./sudoku_solver < .in > actual.out

if diff -q actual.out .out > /dev/null; then
    echo "Test passed."
else
    echo "Test failed."
    diff actual.out .out
fi

rm actual.out
rm sudoku_solver
#!/usr/bin/bash

g++ -std=c++17 roman_num.cpp -o to_roman

assert() {
    output=$(./to_roman "$1")
    if [ "$output" != "$2" ]; then
        echo "$1: $2 expected, but got $output"
        exit 1
    fi
    echo "$1 => $output"
}

assert 1 I
assert 3 III
assert 9 IX
assert 49 XLIX
assert 53 LIII
assert 160 CLX
assert 238 CCXXXVIII
assert 466 CDLXVI
assert 1523 MDXXIII
assert 1670 MDCLXX
echo "OK!"

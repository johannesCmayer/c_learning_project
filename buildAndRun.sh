#!/bin/bash

# Build as C with gcc and run

gcc -ggdb -x c -o $1.out $1 -lm && ./$1.out

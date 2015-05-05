#!/bin/bash

NAME=reverse_add

/usr/bin/gcc -DEVAL -static -O2 -std=c11 -o $NAME grader.c $NAME.c -lm

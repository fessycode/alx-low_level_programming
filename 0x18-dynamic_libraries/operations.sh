#!/bin/bash

gcc -Wall -Wextra -Werror -pedantic -c -fPIC operations.c
gcc -shared -o 100-operations.so operations.o

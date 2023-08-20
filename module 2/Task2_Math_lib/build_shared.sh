#!/bin/bash

# Step 1: Build the Shared Library
gcc -c -Wall -Werror -fpic math_functions.c
gcc -shared -o libmath.so math_functions.o

# Step 2: Compile the Test Application
gcc -L./ -Wall -o test main.c -lmath -lm

# Step 3: Set the Library Path
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/nahass/Desktop/Math_lib

# Step 4: Run the Test Application
./test

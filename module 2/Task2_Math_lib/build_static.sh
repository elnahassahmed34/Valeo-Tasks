#!/bin/bash

# Compile math_functions.c to an object file
gcc -c math_functions.c -o class.o

# Create a static library and add object files to it
ar rcs libclass.a class.o

# Link the library to your application
gcc main.c -L. -lclass -lm -o myapp

#run app
./myapp

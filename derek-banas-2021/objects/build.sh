#! /usr/bin/env bash

# -c Compile and assemble but dont link
# -I the header files directory for includes
# -o for creating output files

mkdir ./bin

g++ -c ./src/Shape.cpp -I include/ -o ./bin/Shape.o
g++ -c ./src/Circle.cpp -I include/ -o ./bin/Circle.o
g++ -c ./src/main.cpp -I include/ -o ./bin/main.o

# link all in a single executable called main
g++ ./bin/Shape.o ./bin/Circle.o ./bin/main.o -o main.out

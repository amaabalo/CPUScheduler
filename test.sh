#!/bin/bash

make

##Run all the originals

./scheduler input/input1
./scheduler input/input2
./scheduler input/input3
./scheduler input/input4
./scheduler input/input5
./scheduler input/input6
./scheduler input/input7
./scheduler input/input8
./scheduler input/input9
./scheduler input/input10

mkdir -p correct
mv input*_* correct

./my_scheduler input/input1
./my_scheduler input/input2
./my_scheduler input/input3
./my_scheduler input/input4
./my_scheduler input/input5
./my_scheduler input/input6
./my_scheduler input/input7
./my_scheduler input/input8
./my_scheduler input/input9
./my_scheduler input/input10

mkdir -p my_correct
mv input*_* my_correct

diff -rqb correct my_correct

#!/bin/bash

make

mkdir -p my_input
cd my_input
#Create all the tests
../test_gen 5 5 input1
../test_gen 10 5 input2
../test_gen 50 5 input3
../test_gen 200 10 input4
../test_gen 10000 10000 input5
cd -

##Run all the originals

./scheduler my_input/input1
./scheduler my_input/input2
./scheduler my_input/input3
./scheduler my_input/input4
./scheduler my_input/input5
: '
./scheduler my_input/input6
./scheduler my_input/input7
./scheduler my_input/input8
./scheduler my_input/input9
./scheduler my_input/input10
'

mkdir -p correct
mv input*_* correct

./my_scheduler my_input/input1
./my_scheduler my_input/input2
./my_scheduler my_input/input3
./my_scheduler my_input/input4
./my_scheduler my_input/input5
: '
./my_scheduler my_input/input6
./my_scheduler my_input/input7
./my_scheduler my_input/input8
./my_scheduler my_input/input9
./my_scheduler my_input/input10
'

mkdir -p my_correct
mv input*_* my_correct

diff -rqb correct my_correct

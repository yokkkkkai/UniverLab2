#!/bin/bash

g++ *.cpp -o sorts
rm -rf output
echo "Delete output dir"
mkdir output 
echo "Make output dir"
./sorts 
echo "Finish"

#!/bin/bash
# MCS172   - Lab 07
# Filename   : q1
# Author     : Balakrishnan Lakshmi, Rajkumar
# Student ID : 2047120

echo "Enter a word:"
read word
wordlen=${#word}
for((i=1; i <= wordlen; i++))
do 
   substring="$(echo $word | cut -c$1-$i)"
   echo "$substring*"
done
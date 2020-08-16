#!/bin/bash
# MCS172   - Lab 02
# Filename   : fnumbers
# Author     : Balakrishnan Lakshmi, Rajkumar
# Student ID : 2047120

echo -n "Enter three numbers to find the biggest among them:"
echo -en "\n In the format Num1 Num2 Num3: "
read -a num

if [ ${#num[@]} -ne 3 ]
then
    echo -en "\nError! Invalid Argument"
fi
if [ ${#num[@]} -eq 3 ]
then
     if [[ (${num[0]} -gt ${num[1]}) && (${num[0]} -gt ${num[2]}) ]]
   then
       echo "Num1 ${num[0]} is the biggest number."
   elif [[ (${num[1]} -gt ${num[0]}) && (${num[1]} -gt ${num[2]}) ]]
   then
       echo "Num2 ${num[1]} is the biggest number."
   else
       echo "Num3 ${num[2]} is the biggest number."
   fi
fi
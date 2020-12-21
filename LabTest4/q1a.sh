#!/bin/bash
# Name       : RAJKUMAR B L
# Student ID : 2047120
# Email      : rajkumar.bl@cs.christuniversity.in
# MCS172     : LabTest4_Q1A


echo -n "Enter the first four digit number: "
read num1

sumnum1=0
while [ $num1 -gt 0 ]
do
    mod=$((num1 % 10))    
    sumnum1=$((sumnum1 + mod))   
    num1=$((num1 / 10))  
done

echo -n "Enter the first four digit number: "
read num2

prodnum2=1
while [ $num2 -gt 0 ]
do
    mod=$((num2 % 10))    
    prodnum2=$((prodnum2 * mod))   
    num2=$((num2 / 10))  
done

finalout=$((sumnum1+prodnum2))
echo  ""
echo  "The sum of first number is : $sumnum1"
echo  "The prod of second number is :$prodnum2"
echo  "The final output is $sumnum1 + $prodnum2 = $finalout"
echo  ""
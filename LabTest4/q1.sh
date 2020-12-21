#!/bin/bash
# Name       : RAJKUMAR B L
# Student ID : 2047120
# Email      : rajkumar.bl@cs.christuniversity.in
# MCS172     : LabTest4_Q1B

te_a()
{
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
}

menu="
========= Menu ==================
1: Sum two 4 digit no's
2: Set
3: Which ls
4: top
5: vmstat
6: Clear
7: Exit
================================="

echo "$menu"
echo -n "Enter the command: "
read choice

while test $choice != 8
do
case $choice in 
      1) te_a ;;
      2) set ;;
      3) which ls;;
      4) top ;;
      5) vmstat;;
      6) clear ;;
      7) exit 1 ;;
      *) echo "Invalid command" ;;
esac
echo -e "\n$menu"
echo -n "Enter the command: " 
read choice
done 

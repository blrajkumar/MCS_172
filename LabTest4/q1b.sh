#!/bin/bash
# Name       : RAJKUMAR B L
# Student ID : 2047120
# Email      : rajkumar.bl@cs.christuniversity.in
# MCS172     : LabTest4_Q1B
menu="
========= Menu ==================
1: Set
2: Which ls
3: top
4: vmstat
5: Clear
6: Exit
================================="

echo "$menu"
echo -n "Enter the command: "
read choice

while test $choice != 8
do
case $choice in 
      1) set ;;
      2) which ls;;
      3) top ;;
      4) vmstat;;
      5) clear ;;
      6) exit 1 ;;
      *) echo "Invalid command" ;;
esac
echo -e "\n$menu"
echo -n "Enter the command: " 
read choice
done 

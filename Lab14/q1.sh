#!/bin/bash
# Name       : RAJKUMAR B L
# Student ID : 2047120
# Email      : rajkumar.bl@cs.christuniversity.in
# MCS172     : Lab14

menu="
========= Menu ==================
1: Free
2: Vmstat
3: top
4: htop
5: which ls
6: Clear
7: Exit
================================="

echo "$menu"
echo -n "Enter the command: "
read choice

while test $choice != 8
do
case $choice in 
      1) free ;;
      2) vmstat ;;
      3) top ;;
      4) htop ;;
      5) which ls ;;
      6) clear ;;
      7) exit 1 ;;
      *) echo "Invalid command" ;;
esac
echo -e "\n$menu"
echo -n "Enter the command: " 
read choice
done 

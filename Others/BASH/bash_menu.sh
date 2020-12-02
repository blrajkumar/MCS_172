#!/bin/sh
# MCS172     : 
# Filename   : 
# Name       : RAJKUMAR B L
# Student ID : 2047120

choice01()
{
  echo -e "\nDisplaying all current dir files:"
  ls
}

menu="
========= Menu ===========
1: Print ls
2: Echo hello
3: Echo RAJ
4: Clear
5: clear
6: Exit
=========================="

echo "$menu"
echo -n "Enter the command: "
read choice

while test $choice != 6
do
case $choice in 
      1) choice01 ;;
      2) echo "hello" ;;
      3) echo "RAJ" ;;
      4) clear ;;
      5) clear ;;
      6) exit 1 ;; 
        *) echo "Invalid command" ;;
esac
echo -e "\n$menu"
echo -n "Enter the command: " 
read choice
done 

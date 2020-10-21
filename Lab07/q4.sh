#!/bin/sh
# MCS172     : Lab 07
# Filename   : MENU
# Author     : Balakrishnan Lakshmi, Rajkumar
# Student ID : 2047120


mv_file()
{
  echo "Enter  a file name to be moved: "
  read file
  echo "Enter new file_name for the move"
  read name
  mv $file $name
}

link_file()
{
  echo "Enter  a file name to be linked: "
  read file
  echo "Enter new file_name to link $file: "
  read name
  ln $file $name
}

mymenu="================ MENU ================
1: Viewing long list of processes
2: Print the current user
3: Print i-node for current directory files
4: Link a file
5: Move a file
6: Print current directory files alone
7: Clear the screen
8: Quit the program
======================================
"
for i in *
do
  chmod 700 $i
done

echo -e "\n"
echo    "$mymenu"
echo -n "Enter command: "
read mychoice

while test $mychoice != 8
do
case $mychoice in
     1) ps -el ;;
     2) whoami ;;
     3) ls -i ;;
     4) link_file ;;
     5) mv_file ;;
     6) ls ;;
     7) clear ;;
     8) exit 1 ;;
     *) echo "Invalid command" ;;
esac
echo -e "\n$mymenu"
echo -n "Enter command: "
read mychoice
done

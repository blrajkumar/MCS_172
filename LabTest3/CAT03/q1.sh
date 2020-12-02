#!/bin/bash
# Name       : RAJKUMAR B L
# Student ID : 2047120
# Email      : rajkumar.bl@cs.christuniversity.in
# MCS172     : LabTest3

echo -n "Enter the name of dir to create:" 
read choice
mkdir $choice
for file in *;
do
  if test -f $file
  then
     cp $file $choice
  fi
done

echo -n "Listing all current open files:" 
lsof +D .


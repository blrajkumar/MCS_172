#!/bin/bash
# MCS172   - Lab 02
# Filename   : ffile
# Author     : Balakrishnan Lakshmi, Rajkumar
# Student ID : 2047120




echo -n "Enter a file/directory name: "
read myfile

if test -f $myfile
then 
   echo "'$myfile' exists and it is a regular file."
   ls -i $myfile
elif test -d $myfile
then 
   echo "'$myfile' exists and it is a directory."
   ls -i $myfile
elif test -e $myfile
then 
   echo "File '$myfile' exists."
   ls -i $myfile
else
   echo "File '$myfile' does'nt exist."

fi
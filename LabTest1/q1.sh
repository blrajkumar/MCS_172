#!/bin/bash
# Name       : RAJKUMAR B L
# Student ID : 2047120
# Email      : rajkumar.bl@cs.christuniversity.in
# MCS172     : Labtest 01

palindrome()
{
echo "Enter a string to check palindrome:"
read str
echo
len=`echo $str | wc -c`
len=`expr $len - 1`
i=1
j=`expr $len / 2`
while test $i -le $j
do
k=`echo $str | cut -c $i`
l=`echo $str | cut -c $len`
if test $k != $l
then
echo "String is not palindrome"
exit
fi
i=`expr $i + 1`
len=`expr $len - 1`
done
echo "String is palindrome"
}

splchar()
{
   chmod 700 *
   echo "Enter a file to extract characters and numbers:"
   read file
   echo $(grep -Eo '[A-Za-z0-9\.]+' $file) >myoutput.txt
   echo "Displaying the extracted content:"
   chmod 700 *
   cat myoutput.txt
}

menu="
========= Menu ==================
1: Palindrome
2: Extract Special Char
3: Clear
4: Exit
================================="

echo "$menu"
echo -n "Enter the command: "
read choice

while test $choice != 4
do
case $choice in 
      1) palindrome ;;
      2) splchar ;;
      3) clear ;;
      4) exit 1 ;; 
        *) echo "Invalid command" ;;
esac
echo -e "\n$menu"
echo -n "Enter the command: " 
read choice
done 

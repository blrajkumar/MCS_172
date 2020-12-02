#!/bin/bash
# Name       : RAJKUMAR B L
# Student ID : 2047120
# Email      : rajkumar.bl@cs.christuniversity.in
# MCS172     : Lab12

test_func()
{
  echo -e "\nTest command is used to check file types and compare values."
  echo -e "It is primarly used for:\n *File attribute comparissions\n *Perform string comparissions\n *Basic arithmetic comparissions"
  echo -e "\nSyntax: test condition"
  echo -e "\nExample: test 5 -eq 5 && echo Yes || echo No"
  test 5 -eq 5 && echo "Result --> Yes" || echo "Result --> No"
}

stat_func()
{
  echo -e "\nStat cmd is command-line utility that displays,\ndetailed information about given files or file systems"
  echo -e "\nSyntax: stat [OPTION]... FILE..."
  echo -e "\nExample: stat q1.sh\nThe output is:"
  stat q1.sh
}

df_func()
{
  echo -e "\ndf(Disk Free) cmd is used to display,\nthe disk usage of the file system"
  echo -e "\nSyntax: df {OPTION}{mount_point_of_filesystem}"
  echo -e "\nExample: df -h (Human readable version of df)\nThe output is:"
  df -h
}

lsof_func()
{
  echo -e "\nlsof is a cmd-line utility for all Unix,\nand Linux like OS to check List of open files"
  echo -e "\nSyntax: lsof"
  echo -e "\nExample: lsof -u root (Prints the lsof for particular user)\nThe output is:"
  lsof -u root
}

zip_func()
{
  echo -e "\nZip is a compression and file packaging utility"
  echo -e "\nSyntax: zip [OPTION] zipfile files_list"
  echo -e "\nExample: zip lab12.zip *  (Zip all files in CD as lab12.zip)\nThe output is:"
  zip lab12.zip *
  ls
}

unzip_func()
{
  echo -e "\nUnzip is a utility that unzips the zipped file package"
  echo -e "\nSyntax: unzip zipfile"
  echo -e "\nExample: unzip lab12.zip (Unzip all files in lab12.zip)\nThe output is:"
  unzip lab12.zip 
  ls
}

menu="
========= Menu ==================
1: Test
2: Stat
3: df
4: Lsof
5: Zip
6: Unzip
7: Clear
8: Exit
================================="

echo "$menu"
echo -n "Enter the command: "
read choice

while test $choice != 8
do
case $choice in 
      1) test_func ;;
      2) stat_func ;;
      3) df_func ;;
      4) lsof_func ;;
      5) zip_func ;;
      6) unzip_func ;;
      7) clear ;;
      8) exit 1 ;;
      *) echo "Invalid command" ;;
esac
echo -e "\n$menu"
echo -n "Enter the command: " 
read choice
done 

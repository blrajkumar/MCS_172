#!/bin/bash
# Name       : RAJKUMAR B L
# Student ID : 2047120
# Email      : rajkumar.bl@cs.christuniversity.in
# MCS172     : Labtest 02

priori()
{
  echo -e "\nEnter the command to set priority: "
  read prcmnd
  echo -e "Enter priority value (Most -20 to least 19): "
  read prval
  nice -$prval $prcmnd
}

chpriori()
{
  echo -e "\n--------- Diplaying Processes --------- "
  ps -e
  echo -e "-----------------------------------------\n "
  echo -e "Enter the process id to change priority: "
  read prsid1
  echo -e "Enter priority value (Most -20 to least 19): "
  read prval2
  renice -n $prval2 -p $prsid1
}

stpprcs()
{
  echo -e "\n--------- Diplaying Processes --------- "
  ps -e
  echo -e "-----------------------------------------\n "
  echo -e "Enter the process id to stop: "
  read prsid2
  kill -9 $prsid2
}

dispallps()
{
  echo -e "\n--------- Diplaying All Processes --------- "
  ps -el
  echo -e "---------------------------------------------\n "
}

disppshier()
{
  echo -e "\n--------- Diplaying Processes Hier --------- "
  pstree
  echo -e "---------------------------------------------\n "
}

menu="
========= Menu ==================
1: Set Prority
2: Change Priority
3: Stop process
4: Display Process Info
5: Display Process Hierarchy
6: Clear
7: Exit
================================="

echo "$menu"
echo -n "Enter the command: "
read choice

while test $choice != 7
do
case $choice in 
      1) priori ;;
      2) chpriori ;;
      3) stpprcs ;;
      4) dispallps ;;
      5) disppshier ;;
      6) clear ;;
      7) exit 1 ;; 
        *) echo "Invalid command" ;;
esac
echo -e "\n$menu"
echo -n "Enter the command: " 
read choice
done 

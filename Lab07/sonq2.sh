#!/bin/bash
# MCS172   - Lab 07
# Filename   : q2
# Author     : Balakrishnan Lakshmi, Rajkumar
# Student ID : 2047120

for(( i=7;i>=-1;i-- ))
do 
    for(( j=i;j>0;j-- ))
    do
        if (( $i == 7 || $i == 5 ))
        then
            echo -ne $i
        elif (( $i == 4 ))
        then
            temp=$(($i-1))
            echo -ne $temp
        elif (( $i == 3 || $i == 2 || $i == 1))
        then
            temp=$(($i-2))
            echo -ne $temp
        fi
    done
    if (( $i==7 || $i==5 || $i==4 || $i==3 || $i==2 || $i==1))
    then
        echo
    fi
done

for(( i=0;i<=7;i++ ))
do 
    for(( j=0;j<i;j++ ))
    do
        if (( $i == 7 || $i == 5 ))
        then
            echo -ne $i
        elif (( $i == 4 ))
        then
            temp=$(($i-1))
            echo -ne $temp
        elif (( $i == 3 || $i == 2 ))
        then
            temp=$(($i-2))
            echo -ne $temp
        fi
    done
    if (( $i==7 || $i==5 || $i==4 || $i==3 || $i==2 ))
    then
        echo " "
    fi
done
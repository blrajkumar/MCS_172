#!/bin/bash
# MCS172   - Lab 02
# Filename   : Question1
# Author     : Balakrishnan Lakshmi, Rajkumar
# Student ID : 2047120

echo -en "\n===============================\n"
ps
echo -en "\n===============================\n"
echo "
Alabama
Alaska
Arizona
Arkansas
California
Colorado
Connecticut
Delaware
Florida
Georgia
Hawaii
Idaho
Illinois
Indiana
Iowa
Kansas
Kentucky
Louisiana
Maine
Maryland
Massachusetts
Michigan
Nevada
New Hampshire
New Jersey
New Mexico
New York
North Carolina
North Dakota
Ohio
Oklahoma
Oregon
Pennsylvania
Rhode Island
South Carolina
South Dakota">state.txt

cut -b 1,4,5 state.txt
echo -en "\n===============================\n"
cut -c 1-5 state.txt
echo -en "\n===============================\n"
cut -d " " -f 5 state.txt
echo -en "\n===============================\n"
at now + 2 minutes < myutil



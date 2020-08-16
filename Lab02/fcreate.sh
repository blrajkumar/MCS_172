#!/bin/bash
# MCS172   - Lab 02
# Filename   : fcreate
# Author     : Balakrishnan Lakshmi, Rajkumar
# Student ID : 2047120


touch file1.txt file2.txt file3.txt
chmod 700 *

echo "This is a sample list of professors 
where the names of some professors are missing.
Chandra
Prabhu
Sivakumar
Nismon
Tulasi
Manjunath
Deepa
Saleema
Sandeep
JP
">file1.txt

echo "This is a sample list of professors and students
where the names of some professors and students are missing.
Chandra
Rahul
Ravi
Sivakumar
Deepak
Hareesma
Manjunath
Hema
Saleema
Krishna
Aakaash
">file2.txt

grep -o -E '\w+' file1.txt | sort -u -f > temp1.txt
grep -o -E '\w+' file2.txt | sort -u -f > temp2.txt
# -E '\w+' searches for words
# -o only prints the portion of the line that matches
# -u only prints each word once
# -f tells sort to ignore case when comparing words


echo -n "
 --------------------------------------
| Displaying the conent of file 3.txt |
 --------------------------------------
">file3.txt
echo -ne "The common words in File1.txt and File2.txt are: \n">>file3.txt


grep -Fxf temp1.txt temp2.txt>> file3.txt
#The command uses grep with -x, which forces matches across full lines only (no substring matches).
#-F which changes grep to do string comparisons rather than regular expression matches.
#The -f file1 instructs grep to read the patterns (the strings to match with) from file1.

rm temp1.txt
rm temp2.txt

cat file3.txt
echo " "

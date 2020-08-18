#!/usr/bin/env bash
# Filename   : Guessinggame
# Author     : Balakrishnan Lakshmi, Rajkumar


function file_guess()
{
  no_files=$(ls -l |grep "^-"|wc -l)
  while(true)
  do
    echo -e "Guess the number of files in current directory: "
        read  file_count
        if [ $file_count -gt $no_files ]
        then
            echo "Great try! But the guess is greater than actual number of files"
        elif [ $file_count -lt $no_files ]
        then
            echo "Great try! But the guess is less than actual number of files"
        else
            echo "YAAY! Congratualtions. You guessed it right"
            break;
        fi
   done
}
file_guess
#!/bin/bash
# MCS172   - Lab 07
# Filename   : q2
# Author     : Balakrishnan Lakshmi, Rajkumar
# Student ID : 2047120

echo "Enter an odd number to print the pattern: "
read oddnum
hed="=======================
  Printing the pattern
======================="
echo "$hed"

for(( x=$oddnum;x>=-1; ))
do 
   for(( y=$x;y>=-1;y-- ))
   do
      if(( $x > 3  && $x == $y ))
      then 
          :
      elif(( $x >= 3  && $x-1 == $y ))
      then 
          :
      else
          echo -ne "$x"
      fi
   done
   if(( $x >= 3 ))
   then
       let "x-=2"
   elif(( $x <= 1 ))
   then
       let "x-=1"
   fi
   echo ""
done

for(( x=0;x<=$oddnum; ))
do 
   for(( y=0;y<=$x;y++ ))
   do
      if(( $x < 3  && $x == $y ))
      then 
          echo -ne "$x$x"
      elif(( $x > 3  && $x == $y ))
      then 
          :
      else
           echo -ne "$x"
      fi     
   done

   if(( $x >= 1 ))
   then
       let "x+=2"
   elif(( $x < 1 ))
   then
       let "x+=1"
   fi
   echo ""
done
echo ""
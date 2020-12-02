#!/bin/sh

wordlen=${#word}
for((i=1; i <= wordlen; i++))
do 
   substring="$(echo $word | cut -c$1-$i)"
   echo "$substring*"
done



// If- else======================================================
status=1
if [ "$status" = "1" ]
    then
        echo -e "Smart quotes are enabled."
    elif [ "$status" = "0" ]
    then
        : // This is used to pass this condition

    else
        echo -e "Sorry, an error occured. You have to run this on OS X""
fi
//End If- else======================================================


//aRRAY=====================================================================

$ string='This is a hello world string'
$ array=( $string  )
$ echo ${array[*]}
This is a hello world string
$ echo ${array[4]}
world
//eND - aRRAY=====================================================================



//File Directory================================================================
echo -n "Enter the first directory name: "
read mydir1
if test ! -d $mydir1
then 
  echo "Directory '$mydir1' does not exist."
  exit 0

else
    echo -n "Enter the second directory name: "
    read mydir2
    if test ! -d $mydir2
    then 
      echo "Directory '$mydir2' does not exist."
      exit 0
     else
	for d1f in ./$mydir1/*
	do
 	  if test -f $d1f
  	  then 
             file1=$(basename "$d1f")
    	     for d2f in ./$mydir2/*
	     do
             if test -f $d2f
  	     then
               file2=$(basename "$d2f")
               if [ "$file1" == "$file2" ]
               then
		 echo "Name: $file2,  Root --->$d2f ">>duplicate.txt
                 rm $d2f
               fi
             fi
             done
          fi
        done
      fi
   fi
//END - FILE DIRECTORY============================================================




//Pattern Matching ==============================================================
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
//=====================================================================================




//Biggest number - multiple args=====================================================================================
echo -n "Enter three numbers to find the biggest among them:"
echo -en "\n In the format Num1 Num2 Num3: "
read -a num

if [ ${#num[@]} -ne 3 ]
then
    echo -en "\nError! Invalid Argument"
fi
if [ ${#num[@]} -eq 3 ]
then
     if [[ (${num[0]} -gt ${num[1]}) && (${num[0]} -gt ${num[2]}) ]]
   then
       echo "Num1 ${num[0]} is the biggest number."
   elif [[ (${num[1]} -gt ${num[0]}) && (${num[1]} -gt ${num[2]}) ]]
   then
       echo "Num2 ${num[1]} is the biggest number."
   else
       echo "Num3 ${num[2]} is the biggest number."
   fi
fi

Parameteerrs ===========>  $! $2 $3 $4 ....$*(all parameters)
No of arguments ========>  $#


//Biggest number - multiple args=====================================================================================




======================================================================================================================

# function to return whether prime or not
check_prime() {
    current_number=$1
    flag=0
    i=2

    while test $i -le `expr $current_number / 2`
    do
        if test `expr $current_number % $i` -eq 0
        then
            flag=1
        fi
        i=`expr $i + 1`
    done

    if test $flag -eq 0
        then echo $current_number
    fi
}

# Assign From and to number
from_number=$1
to_number=$2

for (( number=$from_number; number<=$to_number; number++ ))
do
    check_prime $number
done

======================================================================================================================

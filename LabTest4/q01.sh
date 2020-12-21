Num=123 
g=$Num 
  
# store the sum of  
# digits 
s=0 
  
# use while loop to 
# caclulate the sum 
# of all digits 
while [ $Num -gt 0 ] 
do
    # get Remainder 
    k=$(( $Num % 10 ))  
  
    # get next digit 
    Num=$(( $Num / 10 )) 
  
    # calculate sum of 
    # digit   
    s=$(( $s + $k ))  
done
echo  "sum of digits of $g is : $s"




while [ $n -gt 0 ]
do
    sd=$(( $n % 10 )) # get Remainder 
    n=$(( $n / 10 ))  # get next digit
    sum=$(( $sum + $sd )) # calculate sum of digit
done
echo  "Sum of all digit  is $sum"
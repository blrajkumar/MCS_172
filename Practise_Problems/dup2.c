#include<stdlib.h> 
#include<unistd.h> 
#include<stdio.h> 
#include<fcntl.h> 
  
int main() 
{ 
    int file_desc = open("dup2data",O_WRONLY | O_APPEND); 
      
    // here the newfd is the file descriptor of stdout (1) 
    dup2(file_desc, 1) ;  
          
    // All the printf statements will be written in the file 
    // " you need to create the file manually or using creat dup2.txt" 
    printf("This text  will be printed in the file dup2data.txt\n"); 
      
return 0; 
} 

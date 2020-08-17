/*
 * Student Name : Rajkumar B L
 * Student id   : 2047120
 * Email        : rajkumar.bl@cs.christuniversity.in
 * MCS 172      : Lab04 - C Program to implement UNIX I/O System Calls - open(), read(),write(),lseek and Close()
 */

#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{ 
  int ch,fd,fd1;
  char txt[60];
  char fd_txt[60] = "I AM UNIX OS";
  char fd1_name[60];

  printf("Lab04- Demonstartion of system calls:");
  fd=open("file2.txt",O_WRONLY | O_RDONLY | O_CREAT | O_TRUNC, 0777); 
  write(fd,fd_txt,strlen(fd_txt));
  printf("\nfile2.txt created successfully and information has been written.\n");
  
  do
  {
    printf("\n\tFILE MENU OPERATION\n");
    printf("\t===================\n");
    printf("\t1.File creation\n");
    printf("\t2.File Reading\n");
    printf("\t3.File Appending\n");
    printf("\t4.Move File Pointer\n");
    printf("\t0.Exit\n");
    printf("Enter your choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1:
       printf("Enter the File name to be created:\n");
       scanf("%s",fd1_name);
       fd1=open(fd1_name,O_CREAT|O_WRONLY|O_TRUNC, 0777);
       printf("File created successfully\n");
       printf("Enter the information to write in the file\n");
       scanf("%s",txt);
       write(fd1,txt,strlen(txt));
       printf("\nInformation Written Successfully\n");
       close(fd1);
       printf("File Closed\n");
       break;
       
       case 2:
       printf("Enter the File name to open\n");
       scanf("%s",txt);
       fd1=open(txt,O_RDONLY, 0777);
       printf("Information about the file\n");
       while(read(fd1,txt,sizeof txt)>0)
            write(STDOUT_FILENO,txt,strlen(txt)+1);
       close(fd1);
       break;

       case 3:
       printf("Enter the File name to open\n");
       scanf("%s",txt);
       fd1=open(txt,O_WRONLY| O_APPEND, 0777);
       printf("Enter the information to append to the file\n");
       scanf("%s",txt);
       write(fd1,txt,strlen(txt));
       printf("\nInformation appended Successfully\n");
       close(fd1);
       printf("\nFile Closed\n");
       break;

       case 4:
       printf("Enter the File name to open\n");
       scanf("%s",txt);
       fd1=open(txt,O_RDONLY);
       lseek(fd1,5,SEEK_SET);
       printf("Information about the File\n");
       while(read(fd1,txt,50)>0)
            write(STDOUT_FILENO,txt,5);
       close(fd1);
       break;
       
       case 0:
       exit(0);
       default:
       printf("Invalid Choice\n");
       break;
    }
  }while(ch!=0);
}
#include <stdio.h>
#include <stdlib.h>
  
int main()
{
   char ug[200];
   char fname[20]="my_data.txt";
   FILE *fptr;
   int i,num_lines;
   char rd;

   fptr=fopen(fname,"w");	
   if(fptr==NULL)
   {
      printf("File cannaot be opened");
      exit(1);
   }
   printf("Input the number of lines to be written : ");
   scanf("%d", &num_lines);
   for(i = 0; i < num_lines+1;i++)
    {
	fgets(ug, sizeof ug, stdin);
	fputs(ug, fptr);
     }
   fclose(fptr);
   printf("\nThe file %s is created and data has been entered\n",fname);

   /*-------------- Question 01 - Part A -------------------------------------*/
   fptr = fopen (fname, "r");  
   printf("Displaying the content of %s:\n",fname);
   rd = fgetc(fptr);
   while (rd != EOF)
   {
      printf ("%c", rd);
      rd = fgetc(fptr);
   }
    fclose (fptr);
    return 0;
}
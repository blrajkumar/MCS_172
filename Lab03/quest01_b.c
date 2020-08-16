#include <stdio.h>
#include <stdlib.h>
  
int main()
{
   char pg[200];
   char fname[20]="my_data.txt";
   FILE *fptr;
   int i,num_lines;
   char rd;

   fptr=fopen(fname,"a");	
   if(fptr==NULL)
   {
      printf("File cannaot be opened");
      exit(1);
   }
   printf("To update the file %s with pg deatails.",fname);
   printf("\nInput the number of lines to be appended : ");
   scanf("%d", &num_lines);
   for(i = 0; i <=num_lines;i++)
    {
	fgets(pg, sizeof pg, stdin);
	fputs(pg, fptr);
     }
   fclose(fptr);
   printf("\nThe file %s is updated and pg data has been appended\n",fname);

   
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
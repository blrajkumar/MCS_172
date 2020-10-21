#include<stdio.h>
main()
{
  int child1,child2;
  int ch1_grandchild1, ch2_grandchild1, ch2_grandchild2;
  int i;
  child1 = fork();
  if(child1==0)
  {
    ch1_grandchild1 = fork();
    if(ch1_grandchild1==0)
    {
      printf("This is a Child1 - Granchild01 process and pid is %d\n", getpid());
    }
    printf("This is a Child1 process and pid is %d\n", getpid());
    
  }
  else
  {
    child2=fork();     
    if(child2==0)
    {   
       ch2_grandchild1 = fork();
       if(ch2_grandchild1==0)
       {
         printf("This is a Child2 - Granchild01 process and pid is %d\n", getpid());
       }
      
       else
       {
          ch2_grandchild2 = fork();
    	  if(ch2_grandchild2==0)
          {
            printf("This is a Child1 - Granchild01 process and pid is %d\n", getpid());
          }
       }
       printf("This is Child2  process and pid is %d\n",getpid());
    }
   }
   printf("The Parent process has pid %d\n",getppid());

          
}
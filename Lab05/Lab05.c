#include <stdio.h>
#include <unistd.h>
int main()
{
    int id = fork();
    if (id != 0)
    {
        int id2 = fork(), i;
        if (id2 == 0)
        {
            printf("I am Child  Two --> 2 Printing ");
            printf("Odd Numbers:  ");
            for (int i = 0; i < 20; i++)
            {
                if (!(i % 2 == 0))
                {
                    printf("%d ", i);
                }
            }
            printf("\n");
        }
        else
        {
            printf("I am Parent --->  Printing ");
            printf("Fibonacci series: ");
            int n = 10, n1 = 0, n2 = 1, z, i;
            for (i = 1; i <= n; i++)
            {
                z = n1 + n2;
                printf("%d ", z);
                n1 = n2;
                n2 = z;
            }
            printf("\n");
        }
    }
    else
    {
        printf("I am Child One-- > 1  Printing ");
        printf("Even Numbers: ");
        for (int i = 0; i < 20; i++)
        {
            if (i % 2 == 0)
            {
                printf("%d ", i);
            }
        }
        printf("\n");
    }
    return 0;
}

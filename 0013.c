#include <stdio.h>

int main()
{
    int prime, i, j;
    for (i = 2; i < 1000; i++)
    {
        prime = 1;
        for (j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                prime = 0;
                break;
            }
        }

        if (prime)
        {
            printf("%d\t", i);
        }
    }

    return 0;
}

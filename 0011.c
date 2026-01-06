#include <stdio.h>

int main()
{

    int i, prime, n;

    printf("ente the numer:");
    scanf("%d", &n);

    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            prime = 0;
            break;
        }
    }
    if (prime)
        printf("prime");
    else
        printf("not prime");

    return 0;
}

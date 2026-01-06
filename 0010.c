#include <stdio.h>

int main()
{
    int n, i = 2, prime = 1;
    while (i <= sqrt(n))
    {
        if (n % i == 0)
        {
            prime = 0;
            i = n;
        }
        i++
    }
    if (prime)
    {
        printf("%d is prime", n);
    }
    else
        printf("%d is not prime")

            return 0;
}
#include <stdio.h>

int main()
{
    int coun = 0, sum = 0, x;

    printf("enter the number0: ");
    scanf("%d", &x);
    while (x > 0)
    {
        printf("enter the number%d: \n", coun + 1);
        sum += x;
        coun++;
        scanf("%d", &x);
    }
    if (coun == 0)
    {
        printf("no avg");
    }
    else
    {

        printf("avg=%.2f", (float)sum / coun);
    }

    return 0;
}
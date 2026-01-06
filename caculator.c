#include <stdio.h>
#include <math.h>
int main()
{
float num1, num2, result;
    char operator;
    
    while(1) {
        printf(">> ");
        
        scanf("%f%c%f", &num1, &operator, &num2);
        
        while(getchar() != '\n');
        
        if(num1 == 0 && num2 == 0 && operator == '+') {
            break;
        }
        
        switch(operator) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if(num2 != 0) {
                    result = num1 / num2;
                } else {
                    printf("khata!");
                    continue;
                }
                break;
            default:
                printf("amalgar na motabar");  
                continue;
        }
        
        printf("= %.2f\n", result);
    }
    return 0;
}


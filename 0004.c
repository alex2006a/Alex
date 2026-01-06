//برنامه ای بنویسید یک رشته از وروذی بخواند و معکوس آن را در خروجی چاپ کند

#include<stdio.h>

int main(){
    int i ,j;
char s[50];
printf("string:");
scanf("%s",s);

for(i=0;s[i]!='\0';i++);

for (j=i-1 ; j>=0 ;j--)
{
    printf("%c",s[j]);
}


    return 0;
}
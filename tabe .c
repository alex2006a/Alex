#include <stdio.h>
int max(int x,int y){

    int z;
    if(x>y){
    z=x;}
    else{
    z=y;}
    return z;}
    int main(){

     int a ,b;
        printf("a=");
         scanf("%d",&a);

        printf("b=");
         scanf("%d",&b);
        printf("max is %d" ,max(a,b));

    return 0;

}
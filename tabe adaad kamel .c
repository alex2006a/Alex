#include<stdio.h>

int kam(int x){
    int maqh=0;

    for (int i = 0; i <=x; i++)
    {
        if(x%i==0){
            maqh+=i;
        }
    }
        if(maqh==(2*x)){
            printf("kamel");
        }else
            printf("no kamel");
    }
    int main(){
        int a;
        printf("a=");
        scanf("%d",&a);
        kamel(a);
        return 0;
    }
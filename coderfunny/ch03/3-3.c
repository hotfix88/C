#include <stdio.h>
int fact(int n)
{
    if(n==0)
    {
        return 1;
    }else{
        return n*fact(n-1);
    }
}

int main()
{
    int n;
    printf("������Ҫ����׳˵�������");
    scanf("%d",&n);
    
    printf("%d!=%d\n",n,fact(n));
    getch();
    return 0;
} 

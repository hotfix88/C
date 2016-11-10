#include <stdio.h>
int fibo(int n)
{
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else
        return fibo(n-1)+fibo(n-2);
}

int main()
{
    int f,i;
    printf("请输入斐波那契数列的数量：");
    scanf("%d",&f);

    printf("斐波那契数列：\n"); 
    printf("F(0)=0\n");
    printf("F(1)=1\n");
    for(i=2;i<=f;i++)
    {
        printf("F(%d)=F(%d)+F(%d)=%d+%d=%d\n",
          i,i-1,i-2,fibo(i-1),fibo(i-2),fibo(i));
    }
       
    getch();
    return 0;
}

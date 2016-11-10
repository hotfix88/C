#include <stdio.h>
int is_prime(int n)
{
    int i;
 
    if(n <= 1)//1不是素數,参数n<=1時返回0
    {
        return 0;
    }
 
    for(i = 2; i * i <= n; i++)
    {
        if(n % i == 0)//判断是否能被i整除
        {
            return 0;
        }
    }
 
    return 1;
}

int main()
{
    int i,n=0,t=1;
    
    printf("1000以内的素数排列：\n");
    
    for(i=2;i<1000;i++)
    {
        if(is_prime(i))
        {
            n++;
            t++;
            printf("%4d",i);
            if(t>10)  //每输出10个素数就换行 
            {
                printf("\n");
                t=1;
            }
        }
    }
    printf("\n1000以内的素数共有%d个\n",n);
    
    getch();
    return 0;
}

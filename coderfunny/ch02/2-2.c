#include <stdio.h>
int is_prime(int n)
{
    int i;
 
    if(n <= 1)//1不是素數,参数n<=1時返回0
    {
        return 0;
    }
 
    for(i = 2; i*i <= n; i++)
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
    int n;
    
    printf("请输入需要验证的数：");
    scanf("%d",&n);
    
    if(is_prime(n))
    {
        printf("%d是素数！\n",n);
    }else{
        printf("%d不是素数！\n",n);
    } 
    
    getch();
    return 0;
}

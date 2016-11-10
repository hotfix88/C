#include <stdio.h>
int gcd(int m,int n)
{
    int r;
    r=m%n;
    if(r==0)
    {
        return n;
    }else{
        return gcd(n,r);
    }
}

int main()
{
    int m,n;
    printf("请输入2个整数：");
    scanf("%d,%d",&m,&n);
    printf("%d,%d的最大公约数为：%d\n",m,n,gcd(m,n));
    getch();
    return 0;
} 

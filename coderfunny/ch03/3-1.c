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
    printf("������2��������");
    scanf("%d,%d",&m,&n);
    printf("%d,%d�����Լ��Ϊ��%d\n",m,n,gcd(m,n));
    getch();
    return 0;
} 

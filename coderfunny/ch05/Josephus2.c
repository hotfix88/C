#include <stdio.h>
int main(void)
{
    int n,m,i,s=0;
    printf ("�����������N�ͳ���λ��M��ֵ = ");
    scanf("%d%d",&n,&m);
    
    printf ("�����е������λ���� %d\n",josephus(n,m));
    getch();
    return 0 ;
}

int josephus(int n,int m)
{
    if(n==1)
        return 0;
    else
        return (josephus(n-1,m)+m)%n;
}

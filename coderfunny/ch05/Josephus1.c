#include <stdio.h>
int main(void)
{
    int n,m,i,s=0;
    printf ("�����������N�ͳ���λ��M��ֵ = ");
    scanf("%d%d",&n,&m);
    for (i=2; i<=n; i++)
        s=(s+m)%i;
    printf ("�����е������λ���� %d\n",s);
    getch();
    return 0 ;
}

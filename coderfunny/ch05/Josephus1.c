#include <stdio.h>
int main(void)
{
    int n,m,i,s=0;
    printf ("输入参与人数N和出列位置M的值 = ");
    scanf("%d%d",&n,&m);
    for (i=2; i<=n; i++)
        s=(s+m)%i;
    printf ("最后出列的人最初位置是 %d\n",s);
    getch();
    return 0 ;
}

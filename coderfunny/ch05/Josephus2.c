#include <stdio.h>
int main(void)
{
    int n,m,i,s=0;
    printf ("输入参与人数N和出列位置M的值 = ");
    scanf("%d%d",&n,&m);
    
    printf ("最后出列的人最初位置是 %d\n",josephus(n,m));
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

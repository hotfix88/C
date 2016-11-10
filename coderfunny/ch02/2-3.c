#include <stdio.h>
int is_prime(int n)
{
    int i;
 
    if(n <= 1)//1�����ؔ�,����n<=1�r����0
    {
        return 0;
    }
 
    for(i = 2; i * i <= n; i++)
    {
        if(n % i == 0)//�ж��Ƿ��ܱ�i����
        {
            return 0;
        }
    }
 
    return 1;
}

int main()
{
    int i,n=0,t=1;
    
    printf("1000���ڵ��������У�\n");
    
    for(i=2;i<1000;i++)
    {
        if(is_prime(i))
        {
            n++;
            t++;
            printf("%4d",i);
            if(t>10)  //ÿ���10�������ͻ��� 
            {
                printf("\n");
                t=1;
            }
        }
    }
    printf("\n1000���ڵ���������%d��\n",n);
    
    getch();
    return 0;
}

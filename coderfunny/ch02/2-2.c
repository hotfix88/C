#include <stdio.h>
int is_prime(int n)
{
    int i;
 
    if(n <= 1)//1�����ؔ�,����n<=1�r����0
    {
        return 0;
    }
 
    for(i = 2; i*i <= n; i++)
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
    int n;
    
    printf("��������Ҫ��֤������");
    scanf("%d",&n);
    
    if(is_prime(n))
    {
        printf("%d��������\n",n);
    }else{
        printf("%d����������\n",n);
    } 
    
    getch();
    return 0;
}

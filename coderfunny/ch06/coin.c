#include <stdio.h>

int main()
{
    int i,m=0,n=0;  //m�������ϵĴ���,n�ܴ��� 
    
    srand((int)time(0));  //������������� 
    printf("������Ӳ�ҵĴ�����");
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        if(rand()%2==1)  //�������� 
            m++;
    }
    
    printf("\n���� %d ��Ӳ�ҵ�ͳ�����ݣ�\n",n);
    printf("Ӳ���������ϵĴ���:%d,Ƶ��:%.2f\n",m,(float)m/n);
     
    getch();
    return 0;
}

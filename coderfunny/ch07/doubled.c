#include <stdio.h>

int main()
{
    float thickness;  //����ֽ�ĺ��
    float total;      //�ܵĺ��
    float side[2];     //ֽ�ĳ��ȺͿ�� 
    int count;        //���۴��� 
    
    int i;
    float s;       //���۱߳��� 
    
    
    printf("ֽ�ŵĳ��ȣ�");
    scanf("%f",&side[0]);
    printf("ֽ�ŵĿ�ȣ�");
    scanf("%f",&side[1]);
    printf("ֽ�ŵĺ��:");
    scanf("%f",&thickness);
    
    total=thickness;
    count=0;
    printf("\n����\t���۱߳�\t\t���\n") ;
    for(i=0;i<2;i++)
    {
        s=side[i];  //ȡ�ñ߳� 
        if(i==0)
            printf("�ӳ��ȷ������\n");
        else
            printf("�ӿ�ȷ������\n");
        while(s>total)
        {
            count++;
            s/=2;   //���۱߳����� 
            total*=2;      //��ȼӱ� 
            printf("%2d\t%10.2f\t\t%10.2f\n",count,s,total);
        }
        
    } 
     
    getch();
    return 0;
}

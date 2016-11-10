#include <stdio.h>
#include <stdlib.h>


#define NUMBER 100

int main()
{
    int coin[NUMBER];   //����Ӳ������ 
    int i,j,s;
    int low,high,mid,total1,total2;   //����ÿ�γ��غ�������±���� ������ 
    int count=0;                          //���� 
    int fake=-1;                          //��Ӳ�ҵ��±� 
    
    srand((int)time(NULL));               //������������� 
    
    for(i=0;i<NUMBER;i++)                 //��Ӳ��ȫ������Ϊ��ͬ���� 
    {
        coin[i]=6;
    }
        
    s=rand()%NUMBER;                      //����һ���������ʾ��Ӳ�ҵ��±�                         
    coin[s]=5;                            //��Ӧλ��Ϊ��Ӳ��������С����Ӳ������) 
    printf("��Ӳ�ҵ��±�:%d\n",s);        //�����Ӳ���±� 
     
    low=0;                                //��Ӳ�ҷ�Χ���� 
    high=NUMBER;                          //��Ӳ�ҷ�Χ���� 
    mid=(high-low)/2+low;                 //�۰�λ�� 
    
    while(low<=mid-1)
    {        
        count++;     //���ش��� 
        if((high-low)%2==1)     //�۰��Ϊ���� 
        {
           fake=--high;         //�����һöӲ��Ϊ�ٱ� 
        }
        
        total1=total2=0;        //������ʼ�� 
        for(j=low;j<mid;j++)    //�ۼ������Ӳ������ 
        {
            total1+=coin[j];
        }
        for(j=mid;j<high;j++)   //�ۼ��ҳ���Ӳ������ 
        {
            total2+=coin[j];
        }
        
        if(total1<total2)   //�����Ӳ�������� 
        {
            high=mid;       //��С�۰뷶Χ 
            fake=high-1;    //������ܵļ�Ӳ���±� 
        }else if(total1>total2)           //�ұ߳���Ӳ�������� 
        {
            fake=low=mid;                 //��С�۰뷶Χ ,������ܵļ�Ӳ���±� 
        }else                             //���߳���������� 
        {
            break;                        //�˳�ѭ������ɳ��� 
        }
        
        printf("�� %d �γ��غ󣬼ٱ�λ�� %d ~ %d֮��\n",count,low,high); 
        mid=(high-low)/2+low;           //�����۰�����       
    }
    
    printf("�������� %d �γ��أ��� %d öӲ���Ǽٵģ�\n",count,fake+1); 
     
    getch();
    return 0;
}

#include <stdio.h> 
#define MAXNUM 10000 //��10000���ڵ��������� 
int main()
{
    long i,j,c=0,twin=2,t=0;
    char prime[MAXNUM+1]; //���屣������������ 
    prime[0]=0;
    prime[1]=0;
    for(i=2;i<=MAXNUM;i++) //��ʼ������ 
        prime[i]=1; //��־Ϊ1��ʾ��Ӧ���������� 
        
    for(i=2;i*i<=MAXNUM;i++) //ɸѡ���� 
    {
        if(prime[i]==1) //��Ϊ����
        {
            for(j=2*i;j<=MAXNUM;j++) //ɸȥ���� 
            {
                if(!prime[j]) continue;
                if(j%i==0) //��j�ܱ�������˵���������� 
                    prime[j]=0; //�����־ 
            }
        }
    }
    
    //ͳ���������� 
    for(i=2;i<MAXNUM;i++)
    {
        if(prime[i]==1)
        {
            c++;
            if(i-2==twin)       //���������� 
            {
                printf("(%d,%d) ",twin,i);
                t++;
                if(t%5==0)  printf("\n");
            }
            twin=i;
        }
    }   
    
    printf("\n����%d��������%d������������",c,t);
    getch();
    return 0; 
}

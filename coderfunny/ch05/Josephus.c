#include <stdio.h> 
#include <stdlib.h> 
#define N 41 	//������
#define M 3 	//����3����
int main()
{
    int man[N]={0}; //������е���ţ�Ϊ0��ʾδ���� 
    int count=1;  //���м����� 
    int i=0;   //���������� 
    int pos=-1;  //λ�ü����� 
    int alive=0;
    while(count<=N) //��N������ģ��ѭ������
    {
        do{
            pos=(pos+1) % N;	//���࣬���л�״����������������� Nֵ���ִ�1��ʼ 
            if(man[pos]==0)	//�����pos��δ����
                i++;        //���� 
            if(i==M)	//����M���� 
            {
                i=0;    //��ʼ�����������ִ�1��ʼ���� 
                break;
            }
        }while(1);
        man[pos]=count;  //���������� 
        count++;
    }    
    printf("\nԼɪ������(���λ��-Լɪ��λ��):\n"); 	//�������λ��
    for(i=0;i<N;i++)
    {
        printf("%d-%d  ",i+1,man[i]);
        if(i!=0 && i%10==0) 	//ÿ���10������ 
            printf("\n");
    }

    for(i=0;i<N;i++)	//���ҵ��豣���ı��
        if(man[i]>N-1)
            printf("\n��ʼ���:%d,Լɪ�����:%d\n",i+1,man[i]);
    printf("\n");
    getch();
    return 0;
}

#include <stdio.h>
float fact(float f,int n);  //����׳� 
float ROI(float a,float r,int p);     //����ر� 

int main()      //������ 
{
    float rate,amount,pay,t1;
    int period,i;
    
    printf("Ͷ�ʻر��������\n\n");
    printf("Ͷ�ʽ�");
    scanf("%f",&amount);
    
    printf("�ر��ʣ�");
    scanf("%f",&rate);
    
    printf("Ͷ��������");
    scanf("%d",&period);    
  
    printf("\n\n����\t����\t�����ϼ�\n");
    for(i=1;i<=period;i++)               //���ÿһ�ڵ����󼰱����ϼ� 
    {
        t1=ROI(amount,rate,i);
        printf("%d\t%.0f\t%.0f\n",i, t1-amount,t1);
    }
    
    getch();
    return 0;
}     

float ROI(float a,float r,int p)     //����Ͷ�ʻر� 
{
    return a*fact(1+r,p);
}

float fact(float f,int n)     //����׳� 
{
    float temp=1;
    int i;
    for(i=0;i<n;i++)
    {
        temp*=f;
    }
    return temp;
}

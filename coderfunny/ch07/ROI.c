#include <stdio.h>
float fact(float f,int n);  //计算阶乘 
float ROI(float a,float r,int p);     //计算回报 

int main()      //主函数 
{
    float rate,amount,pay,t1;
    int period,i;
    
    printf("投资回报计算程序\n\n");
    printf("投资金额：");
    scanf("%f",&amount);
    
    printf("回报率：");
    scanf("%f",&rate);
    
    printf("投资期数：");
    scanf("%d",&period);    
  
    printf("\n\n期数\t利润\t本利合计\n");
    for(i=1;i<=period;i++)               //输出每一期的利润及本利合计 
    {
        t1=ROI(amount,rate,i);
        printf("%d\t%.0f\t%.0f\n",i, t1-amount,t1);
    }
    
    getch();
    return 0;
}     

float ROI(float a,float r,int p)     //计算投资回报 
{
    return a*fact(1+r,p);
}

float fact(float f,int n)     //计算阶乘 
{
    float temp=1;
    int i;
    for(i=0;i<n;i++)
    {
        temp*=f;
    }
    return temp;
}

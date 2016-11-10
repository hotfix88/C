#include <stdio.h>

int main()
{
    int i,m=0,n=0;  //m正面向上的次数,n总次数 
    
    srand((int)time(0));  //设置随机数种子 
    printf("输入抛硬币的次数：");
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        if(rand()%2==1)  //正面向上 
            m++;
    }
    
    printf("\n抛掷 %d 次硬币的统计数据：\n",n);
    printf("硬币正面向上的次数:%d,频率:%.2f\n",m,(float)m/n);
     
    getch();
    return 0;
}

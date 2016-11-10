#include <stdio.h>
#include <stdlib.h>


#define NUMBER 100

int main()
{
    int coin[NUMBER];   //保存硬币重量 
    int i,j,s;
    int low,high,mid,total1,total2;   //保存每次称重后的数组下标序号 ，重量 
    int count=0;                          //计数 
    int fake=-1;                          //假硬币的下标 
    
    srand((int)time(NULL));               //生成随机数种子 
    
    for(i=0;i<NUMBER;i++)                 //将硬币全部设置为相同重量 
    {
        coin[i]=6;
    }
        
    s=rand()%NUMBER;                      //生成一个随机数表示假硬币的下标                         
    coin[s]=5;                            //对应位置为假硬币重量（小于真硬币重量) 
    printf("假硬币的下标:%d\n",s);        //输出假硬币下标 
     
    low=0;                                //假硬币范围下限 
    high=NUMBER;                          //假硬币范围上限 
    mid=(high-low)/2+low;                 //折半位置 
    
    while(low<=mid-1)
    {        
        count++;     //称重次数 
        if((high-low)%2==1)     //折半后不为整数 
        {
           fake=--high;         //设最后一枚硬币为假币 
        }
        
        total1=total2=0;        //重量初始化 
        for(j=low;j<mid;j++)    //累加左称盘硬币重量 
        {
            total1+=coin[j];
        }
        for(j=mid;j<high;j++)   //累加右称盘硬币重量 
        {
            total2+=coin[j];
        }
        
        if(total1<total2)   //左称盘硬币重量轻 
        {
            high=mid;       //缩小折半范围 
            fake=high-1;    //保存可能的假硬币下标 
        }else if(total1>total2)           //右边称盘硬币重量轻 
        {
            fake=low=mid;                 //缩小折半范围 ,保存可能的假硬币下标 
        }else                             //两边称盘重量相等 
        {
            break;                        //退出循环，完成称重 
        }
        
        printf("第 %d 次称重后，假币位于 %d ~ %d之间\n",count,low,high); 
        mid=(high-low)/2+low;           //进行折半运算       
    }
    
    printf("共进行了 %d 次称重，第 %d 枚硬币是假的！\n",count,fake+1); 
     
    getch();
    return 0;
}

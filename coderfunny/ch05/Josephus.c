#include <stdio.h> 
#include <stdlib.h> 
#define N 41 	//总人数
#define M 3 	//数到3出列
int main()
{
    int man[N]={0}; //保存出列的序号，为0表示未出列 
    int count=1;  //出列记数器 
    int i=0;   //报数记数器 
    int pos=-1;  //位置记数器 
    int alive=0;
    while(count<=N) //在N个人中模拟循环报数
    {
        do{
            pos=(pos+1) % N;	//求余，进行环状处理，如果记数器超过 N值，又从1开始 
            if(man[pos]==0)	//若编号pos还未出列
                i++;        //报数 
            if(i==M)	//报数M的人 
            {
                i=0;    //初始化记数器，又从1开始报数 
                break;
            }
        }while(1);
        man[pos]=count;  //保存出列序号 
        count++;
    }    
    printf("\n约瑟夫排列(最初位置-约瑟夫环位置):\n"); 	//输出排列位置
    for(i=0;i<N;i++)
    {
        printf("%d-%d  ",i+1,man[i]);
        if(i!=0 && i%10==0) 	//每输出10个则换行 
            printf("\n");
    }

    for(i=0;i<N;i++)	//查找到需保留的编号
        if(man[i]>N-1)
            printf("\n初始序号:%d,约瑟夫环序号:%d\n",i+1,man[i]);
    printf("\n");
    getch();
    return 0;
}

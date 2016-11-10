#include <stdio.h> 
#define MAXNUM 10000 //求10000以内的所有素数 
int main()
{
    long i,j,c=0,twin=2,t=0;
    char prime[MAXNUM+1]; //定义保存素数的数组 
    prime[0]=0;
    prime[1]=0;
    for(i=2;i<=MAXNUM;i++) //初始化数组 
        prime[i]=1; //标志为1表示对应的数是素数 
        
    for(i=2;i*i<=MAXNUM;i++) //筛选合数 
    {
        if(prime[i]==1) //若为素数
        {
            for(j=2*i;j<=MAXNUM;j++) //筛去合数 
            {
                if(!prime[j]) continue;
                if(j%i==0) //数j能被整除，说明不是素数 
                    prime[j]=0; //清除标志 
            }
        }
    }
    
    //统计素数数量 
    for(i=2;i<MAXNUM;i++)
    {
        if(prime[i]==1)
        {
            c++;
            if(i-2==twin)       //是孪生素数 
            {
                printf("(%d,%d) ",twin,i);
                t++;
                if(t%5==0)  printf("\n");
            }
            twin=i;
        }
    }   
    
    printf("\n共有%d个素数，%d对孪生素数！",c,t);
    getch();
    return 0; 
}

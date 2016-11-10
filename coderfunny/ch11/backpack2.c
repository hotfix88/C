#include <stdio.h>

typedef struct goods
{
    double *value; //各物品的价值（数组） 
    double *weight; //各物品的重量（数组） 
    int num;//物品数量 
    int limitw; //前包限制重量
}GOODS;

void backpack(GOODS *g,char select[])
//参数说明：
//g指向保存物品信息的结构
//select用来返回物品的装入状态
{
   int i,flag;
   char *select1; //0未装入背包，1装入前包 
   double maxvalue = 0; 
   double tw; //装入背包物品总重量 
   double tv;//装入背包物品总价值
   if(!(select1 = (char *)malloc(sizeof(char) * g->num)))
   {
       printf("内存分配失败\n");
       exit(0);   
   }
   
   for (i = 0; i < g->num; i++)//将数组清空，表示全部未装入背包 
       select1[i] = 0;    
       
   while(binadd(select1, g->num) == 0) //进行一次二进制加法运算 
   {
       tw = 0;         
       tv = 0;           
       flag = 1;
       //printf("\n");
       for (i = 0; i < g->num; i++) //根据物品装入背包的状态进行试算 
       {
           if (select1[i] == 1) //若将该物品装入背包 
           {
               tw += g->weight[i]; //累加装入物品的重量 
               tv += g->value[i];//累加装入物品的价值 
               if (tw > g->limitw) //若重量超过限制 
               {
                   flag = 0;
                   break; //退出本次试装入 
               }
           } 
       }
       
       if(flag && maxvalue < tv) //若前包中物品重量未超过限制,并且本次累加价值大于已有最大值
       {
           maxvalue = tv;  //保存最大值 
           for(i = 0; i < g->num; i++) //保存物品状态 
               select[i] = select1[i];
       } 
   }   
}

int binadd(char select1[],int n) //二进制运算 
{
    int i,carry=0;
    select1[0] += 1;  //低位加1 
    for (i = 0; i < n; i++)
    {
        select1[i] += carry; //加上进位 
        carry = select1[i] /2;//计算进位         
        select1[i] %= 2; //保留0或1; 
        if (carry==0)
            return 0;
    }
    return carry;
}

int main()
{
   double sumweight,maxvalue; //用来保存阶段最优价值 
   char *select;  //保存最大价值时各物品的装入状态 
   GOODS g;
   int i; 
   
   printf("背包最大重量:");
   scanf("%d",&g.limitw);
   printf("可选物品数量:"); 
   scanf("%d",&g.num);
   
   if(!(g.value = (double *)malloc(sizeof(double)*g.num)))//分配内存保存物品价值 
   {
       printf("内存分配失败\n");
       exit(0); 
   }
   
   if(!(g.weight = (double *)malloc(sizeof(double)*g.num)))//分配内存保存物品的重量 
   {
       printf("内存分配失败\n");
       exit(0);   
   }
   
   if(!(select = (char *)malloc(sizeof(char)*g.num))) //分配内存保存物品状态 
   {
       printf("内存分配失败\n");
       exit(0);   
   }
   
   for(i=0;i<g.num;i++)
   {
	  printf("输入第%d号物品的重量和价值:",i + 1);
	  scanf("%lf%lf",&g.weight[i],&g.value[i]);
   }
   
   printf("\n背包最大能装的重量为:%.2f\n\n",g.limitw);
   for (i = 0; i < g.num; i++)
	  printf("第%d号物品重:%.2f,价值:%.2f\n", i + 1, g.weight[i], g.value[i]);
   
   backpack(&g,select);
   
   sumweight=0;
   maxvalue=0;   
   printf("\n可将以下物品装入背包,使背包装的物品价值最大:\n");
   for (i = 0; i < g.num; ++i)
	  if (select[i])      //装入背包 
	  {
		 printf("第%d号物品,重量:%.2f,价值:%.2f\n", i + 1, g.weight[i], g.value[i]);
		 sumweight+=g.weight[i];
		 maxvalue+=g.value[i];
      }	 
   printf("\n总重量为: %.2f,总价值为:%.2f\n", sumweight, maxvalue );
   
   getch();
   return 0;
}

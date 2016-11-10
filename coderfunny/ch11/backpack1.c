#include <stdio.h>

typedef struct goods	//定义结构
{
    double *value; 	//保存各物品价值（数组）
    double *weight; 	//保存各物品重量（数组）
    char *select; 	//保存各物品是否装入背包（数组）
    int num;	//可装入背包的物品数量 
    double limitw; 	//背包最大重量
}GOODS;

double maxvalue;	//装入背包物品的最大值
double totalvalue;	//所有物品的总价值
char *select1; 	//临时数组 

void backpack(GOODS *g, int i, double tw, double tv)
//参数说明
//g传入要处理物品结构指针，
//i需要试装入物品的序号
//tw当前背包已经达到的总重量
//tv所有未装入背包的物品的总价值
{
   int k;
   if (tw + g->weight[i] <= g->limitw)	//试装入物品i，未超重
   {
     select1[i] = 1; 	//选中第i个物品装入背包 
     if (i < g->num - 1) 	//若物品i不是最后一个物品 
       backpack(g, i + 1, tw + g->weight[i], tv); 	//递归调用,继续试装入下一物品 
     else 	//若已到最后一个物品 
     {
       for (k = 0; k < g->num; ++k) 	//将状态标志复制到select数组中 
         g->select[k] = select1[k];
       maxvalue = tv; 	//保存当前背包中的最大价值 
     }
   }
   select1[i] = 0; 	//从背包中取出物品i
   if (tv - g->value[i] > maxvalue)
   //若未装入背包的物品总价值减去物品i的价值还大于maxvalue,
   //说明还可以继续向背包中添加物品 
   {
     if (i < g->num - 1) 	//若物品i不是最后一个物品 
       backpack(g, i + 1, tw, tv - g->value[i]); 	//递归调用,继续装入下一物品 
     else 	//若已到最后一个物品 
     {
       for (k = 0; k < g->num; ++k) 	//将状态标志复制到select数组中 
         g->select[k] = select1[k];
       maxvalue = tv - g->value[i]; 	//保存当前背包中的最大价值
     }
   }
}

int main()
{
   double sumweight;	//保存装入背包物品总价值
   GOODS g;
   int i;
    
   printf("背包最大重量:");
   scanf("%lf",&g.limitw);	//输入背包最大重量
   printf("可选物品数量:"); 
   scanf("%d",&g.num);	//输入物品数量
   if(!(g.value = (double *)malloc(sizeof(double)*g.num)))	//分配内存保存物品价值 
   {
       printf("内存分配失败\n");
       exit(0); 
   }
   if(!(g.weight = (double *)malloc(sizeof(double)*g.num)))	//分配内存保存物品的重量 
   {
       printf("内存分配失败\n");
       exit(0);   
   }
   if(!(g.select = (char *)malloc(sizeof(char)*g.num)))	//分配内存保存物品的重量 
   {
       printf("内存分配失败\n");
       exit(0);   
   }
   if(!(select1 = (char *)malloc(sizeof(char)*g.num)))	//分配内存保存物品的重量 
   {
       printf("内存分配失败\n");
       exit(0);   
   }

   totalvalue=0;   
   for (i = 0; i < g.num; i++)	//输入各物品的重量和价值
   {
     printf("输入第%d号物品的重量和价值:",i + 1);
     scanf("%lf%lf",&g.weight[i],&g.value[i]);
     totalvalue+=g.value[i];	//统计所有物品的价值总和 
   }

   printf("\n背包最大能装的重量为:%.2f\n\n",g.limitw);
   for (i = 0; i < g.num; i++)
     printf("第%d号物品重:%.2f,价值:%.2f\n", i + 1, g.weight[i], g.value[i]);

   for (i = 0; i < g.num; i++)	//初始设各物品都没装入背包 
       select1[i]=0;

   maxvalue=0;	//装入背包物品的总价值 
   backpack(&g,0,0.0,totalvalue); 	//调用函数将第1个物品装入背包

   sumweight=0; 
   printf("\n可将以下物品装入背包,使背包装的物品价值最大:\n");
   for (i = 0; i < g.num; ++i)
     if (g.select[i])	//若装入背包
     {
       printf("第%d号物品,重量:%.2f,价值:%.2f\n", i + 1, g.weight[i], g.value[i]);
       sumweight+=g.weight[i];
      } 
   printf("\n总重量为: %.2f,总价值为:%.2f\n", sumweight, maxvalue );

   getch();
   return 0;
}

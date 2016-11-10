#include <stdio.h>

typedef struct goods	//����ṹ
{
    double *value; 	//�������Ʒ��ֵ�����飩
    double *weight; 	//�������Ʒ���������飩
    char *select; 	//�������Ʒ�Ƿ�װ�뱳�������飩
    int num;	//��װ�뱳������Ʒ���� 
    double limitw; 	//�����������
}GOODS;

double maxvalue;	//װ�뱳����Ʒ�����ֵ
double totalvalue;	//������Ʒ���ܼ�ֵ
char *select1; 	//��ʱ���� 

void backpack(GOODS *g, int i, double tw, double tv)
//����˵��
//g����Ҫ������Ʒ�ṹָ�룬
//i��Ҫ��װ����Ʒ�����
//tw��ǰ�����Ѿ��ﵽ��������
//tv����δװ�뱳������Ʒ���ܼ�ֵ
{
   int k;
   if (tw + g->weight[i] <= g->limitw)	//��װ����Ʒi��δ����
   {
     select1[i] = 1; 	//ѡ�е�i����Ʒװ�뱳�� 
     if (i < g->num - 1) 	//����Ʒi�������һ����Ʒ 
       backpack(g, i + 1, tw + g->weight[i], tv); 	//�ݹ����,������װ����һ��Ʒ 
     else 	//���ѵ����һ����Ʒ 
     {
       for (k = 0; k < g->num; ++k) 	//��״̬��־���Ƶ�select������ 
         g->select[k] = select1[k];
       maxvalue = tv; 	//���浱ǰ�����е�����ֵ 
     }
   }
   select1[i] = 0; 	//�ӱ�����ȡ����Ʒi
   if (tv - g->value[i] > maxvalue)
   //��δװ�뱳������Ʒ�ܼ�ֵ��ȥ��Ʒi�ļ�ֵ������maxvalue,
   //˵�������Լ����򱳰��������Ʒ 
   {
     if (i < g->num - 1) 	//����Ʒi�������һ����Ʒ 
       backpack(g, i + 1, tw, tv - g->value[i]); 	//�ݹ����,����װ����һ��Ʒ 
     else 	//���ѵ����һ����Ʒ 
     {
       for (k = 0; k < g->num; ++k) 	//��״̬��־���Ƶ�select������ 
         g->select[k] = select1[k];
       maxvalue = tv - g->value[i]; 	//���浱ǰ�����е�����ֵ
     }
   }
}

int main()
{
   double sumweight;	//����װ�뱳����Ʒ�ܼ�ֵ
   GOODS g;
   int i;
    
   printf("�����������:");
   scanf("%lf",&g.limitw);	//���뱳���������
   printf("��ѡ��Ʒ����:"); 
   scanf("%d",&g.num);	//������Ʒ����
   if(!(g.value = (double *)malloc(sizeof(double)*g.num)))	//�����ڴ汣����Ʒ��ֵ 
   {
       printf("�ڴ����ʧ��\n");
       exit(0); 
   }
   if(!(g.weight = (double *)malloc(sizeof(double)*g.num)))	//�����ڴ汣����Ʒ������ 
   {
       printf("�ڴ����ʧ��\n");
       exit(0);   
   }
   if(!(g.select = (char *)malloc(sizeof(char)*g.num)))	//�����ڴ汣����Ʒ������ 
   {
       printf("�ڴ����ʧ��\n");
       exit(0);   
   }
   if(!(select1 = (char *)malloc(sizeof(char)*g.num)))	//�����ڴ汣����Ʒ������ 
   {
       printf("�ڴ����ʧ��\n");
       exit(0);   
   }

   totalvalue=0;   
   for (i = 0; i < g.num; i++)	//�������Ʒ�������ͼ�ֵ
   {
     printf("�����%d����Ʒ�������ͼ�ֵ:",i + 1);
     scanf("%lf%lf",&g.weight[i],&g.value[i]);
     totalvalue+=g.value[i];	//ͳ��������Ʒ�ļ�ֵ�ܺ� 
   }

   printf("\n���������װ������Ϊ:%.2f\n\n",g.limitw);
   for (i = 0; i < g.num; i++)
     printf("��%d����Ʒ��:%.2f,��ֵ:%.2f\n", i + 1, g.weight[i], g.value[i]);

   for (i = 0; i < g.num; i++)	//��ʼ�����Ʒ��ûװ�뱳�� 
       select1[i]=0;

   maxvalue=0;	//װ�뱳����Ʒ���ܼ�ֵ 
   backpack(&g,0,0.0,totalvalue); 	//���ú�������1����Ʒװ�뱳��

   sumweight=0; 
   printf("\n�ɽ�������Ʒװ�뱳��,ʹ����װ����Ʒ��ֵ���:\n");
   for (i = 0; i < g.num; ++i)
     if (g.select[i])	//��װ�뱳��
     {
       printf("��%d����Ʒ,����:%.2f,��ֵ:%.2f\n", i + 1, g.weight[i], g.value[i]);
       sumweight+=g.weight[i];
      } 
   printf("\n������Ϊ: %.2f,�ܼ�ֵΪ:%.2f\n", sumweight, maxvalue );

   getch();
   return 0;
}

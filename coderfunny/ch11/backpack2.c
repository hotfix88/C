#include <stdio.h>

typedef struct goods
{
    double *value; //����Ʒ�ļ�ֵ�����飩 
    double *weight; //����Ʒ�����������飩 
    int num;//��Ʒ���� 
    int limitw; //ǰ����������
}GOODS;

void backpack(GOODS *g,char select[])
//����˵����
//gָ�򱣴���Ʒ��Ϣ�Ľṹ
//select����������Ʒ��װ��״̬
{
   int i,flag;
   char *select1; //0δװ�뱳����1װ��ǰ�� 
   double maxvalue = 0; 
   double tw; //װ�뱳����Ʒ������ 
   double tv;//װ�뱳����Ʒ�ܼ�ֵ
   if(!(select1 = (char *)malloc(sizeof(char) * g->num)))
   {
       printf("�ڴ����ʧ��\n");
       exit(0);   
   }
   
   for (i = 0; i < g->num; i++)//��������գ���ʾȫ��δװ�뱳�� 
       select1[i] = 0;    
       
   while(binadd(select1, g->num) == 0) //����һ�ζ����Ƽӷ����� 
   {
       tw = 0;         
       tv = 0;           
       flag = 1;
       //printf("\n");
       for (i = 0; i < g->num; i++) //������Ʒװ�뱳����״̬�������� 
       {
           if (select1[i] == 1) //��������Ʒװ�뱳�� 
           {
               tw += g->weight[i]; //�ۼ�װ����Ʒ������ 
               tv += g->value[i];//�ۼ�װ����Ʒ�ļ�ֵ 
               if (tw > g->limitw) //�������������� 
               {
                   flag = 0;
                   break; //�˳�������װ�� 
               }
           } 
       }
       
       if(flag && maxvalue < tv) //��ǰ������Ʒ����δ��������,���ұ����ۼӼ�ֵ�����������ֵ
       {
           maxvalue = tv;  //�������ֵ 
           for(i = 0; i < g->num; i++) //������Ʒ״̬ 
               select[i] = select1[i];
       } 
   }   
}

int binadd(char select1[],int n) //���������� 
{
    int i,carry=0;
    select1[0] += 1;  //��λ��1 
    for (i = 0; i < n; i++)
    {
        select1[i] += carry; //���Ͻ�λ 
        carry = select1[i] /2;//�����λ         
        select1[i] %= 2; //����0��1; 
        if (carry==0)
            return 0;
    }
    return carry;
}

int main()
{
   double sumweight,maxvalue; //��������׶����ż�ֵ 
   char *select;  //��������ֵʱ����Ʒ��װ��״̬ 
   GOODS g;
   int i; 
   
   printf("�����������:");
   scanf("%d",&g.limitw);
   printf("��ѡ��Ʒ����:"); 
   scanf("%d",&g.num);
   
   if(!(g.value = (double *)malloc(sizeof(double)*g.num)))//�����ڴ汣����Ʒ��ֵ 
   {
       printf("�ڴ����ʧ��\n");
       exit(0); 
   }
   
   if(!(g.weight = (double *)malloc(sizeof(double)*g.num)))//�����ڴ汣����Ʒ������ 
   {
       printf("�ڴ����ʧ��\n");
       exit(0);   
   }
   
   if(!(select = (char *)malloc(sizeof(char)*g.num))) //�����ڴ汣����Ʒ״̬ 
   {
       printf("�ڴ����ʧ��\n");
       exit(0);   
   }
   
   for(i=0;i<g.num;i++)
   {
	  printf("�����%d����Ʒ�������ͼ�ֵ:",i + 1);
	  scanf("%lf%lf",&g.weight[i],&g.value[i]);
   }
   
   printf("\n���������װ������Ϊ:%.2f\n\n",g.limitw);
   for (i = 0; i < g.num; i++)
	  printf("��%d����Ʒ��:%.2f,��ֵ:%.2f\n", i + 1, g.weight[i], g.value[i]);
   
   backpack(&g,select);
   
   sumweight=0;
   maxvalue=0;   
   printf("\n�ɽ�������Ʒװ�뱳��,ʹ����װ����Ʒ��ֵ���:\n");
   for (i = 0; i < g.num; ++i)
	  if (select[i])      //װ�뱳�� 
	  {
		 printf("��%d����Ʒ,����:%.2f,��ֵ:%.2f\n", i + 1, g.weight[i], g.value[i]);
		 sumweight+=g.weight[i];
		 maxvalue+=g.value[i];
      }	 
   printf("\n������Ϊ: %.2f,�ܼ�ֵΪ:%.2f\n", sumweight, maxvalue );
   
   getch();
   return 0;
}

#include<stdio.h> 
#include<string.h> 
//���������㺯�� 
int int_pow(int x,int y)
{
    int i,result=1;
    for(i=1;i<=y;i++)
    {
        result*=x;
    }
    return result;
}

//��10������ת��Ϊ������ƣ�����numΪ10������������jzΪĿ����� 
void dtox(int dnum,int jz) 
{  
     char xnum[100];         //����Ŀ����Ƶĸ�λ�� 
     int i=0,j=0;  
     while(dnum>=jz)         //�ó�ģȡ�෨�����Ӧ���Ƶĸ�λ 
     {   
         if(dnum%jz<=9)
             xnum[j++]=dnum%jz+48;  //0~9֮����� 
         else
             xnum[j++]=dnum%jz-10+'A';  //����9��������ĸ��ʾ 
         dnum=dnum/jz;  
     }
     if(dnum<=9)
         xnum[j]=dnum+'0';  //0~9֮����� 
     else
         xnum[j]=dnum-10+'A';  //����9�����ô�д��ĸ��ʾ  
     for(i = j;i>=0;i--)
     {   
         printf("%c",xnum[i]);  
     }  
 } 
/*���������ת��Ϊ10����
����num��һ�����飬����������ַ���������jzΪԴ���ݵĽ��� */
int xtod(char num[],int jz) 
{  
       int dnum = 0,i,n=0,b;  
       for(i=0;;i++)  
       {   
           if(num[i]=='\0')break;   
           else n++;   
       } 
       for(i=n-1;i>=0;i--)          //��Ȩչ����ת��Ϊ10���� 
       {       
           if(num[n-i-1]>='a')
               b=num[n-i-1]-'a'+10;
           else if(num[n-i-1]>='A')
               b=num[n-i-1]-'A'+10;
           else
               b=num[n-i-1]-'0';
           dnum =dnum + b*int_pow(jz,i);
       }
       return dnum;   
}
//������ 
int main() 
{  
     char num[100];   //����Ҫת������  
     int jz1,jz2;  //�������ֽ��� 
     printf("����Ҫת��������");  
     scanf("%s",num);     
     printf("�������Ľ��ƣ�");  
     scanf("%d",&jz1);  
     printf("Ҫת���Ľ��ƣ�");  
     scanf("%d",&jz2);  
     dtox(xtod(num,jz1),jz2);
     getch();
     return 0;
}

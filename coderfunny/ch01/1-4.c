#include<stdio.h> 
#include<string.h> 
//整数幂运算函数 
int int_pow(int x,int y)
{
    int i,result=1;
    for(i=1;i<=y;i++)
    {
        result*=x;
    }
    return result;
}

//将10进制数转换为任意进制，参数num为10进制数，参数jz为目标进制 
void dtox(int dnum,int jz) 
{  
     char xnum[100];         //保存目标进制的各位数 
     int i=0,j=0;  
     while(dnum>=jz)         //用除模取余法计算对应进制的各位 
     {   
         if(dnum%jz<=9)
             xnum[j++]=dnum%jz+48;  //0~9之间的数 
         else
             xnum[j++]=dnum%jz-10+'A';  //超过9的数用字母表示 
         dnum=dnum/jz;  
     }
     if(dnum<=9)
         xnum[j]=dnum+'0';  //0~9之间的数 
     else
         xnum[j]=dnum-10+'A';  //超过9的数用大写字母表示  
     for(i = j;i>=0;i--)
     {   
         printf("%c",xnum[i]);  
     }  
 } 
/*将输入的数转换为10进制
参数num是一个数组，保存输入的字符串，参数jz为源数据的进制 */
int xtod(char num[],int jz) 
{  
       int dnum = 0,i,n=0,b;  
       for(i=0;;i++)  
       {   
           if(num[i]=='\0')break;   
           else n++;   
       } 
       for(i=n-1;i>=0;i--)          //按权展开，转换为10进制 
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
//主函数 
int main() 
{  
     char num[100];   //保存要转换的数  
     int jz1,jz2;  //保存两种进制 
     printf("输入要转换的数：");  
     scanf("%s",num);     
     printf("输入数的进制：");  
     scanf("%d",&jz1);  
     printf("要转换的进制：");  
     scanf("%d",&jz2);  
     dtox(xtod(num,jz1),jz2);
     getch();
     return 0;
}

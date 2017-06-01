#include <stdio.h>
#include <string.h>
//fengyang test 
//作为python教程的c语言比对复习使用 
int main()
{
    int a,b;
    
    char c,t;
    char s[]="中文";
    printf("hello world!\n");
    
    //值传递 
    a = 100;
    b = a;
    a = 200;
    printf("%d,%d\n",a,b);
    
    //字符
    c = 'z';
    printf("%d,%c\n",c,c);
    
    //支持后续定义 
    int i,j;
    //打印各种ASCII字符 
    for (i = 1;i<128;i++)
        printf("%c ",i);
        
   
    printf("\n%s\n",s);   
    printf("%d\n",sizeof(s)); 
   
    
    getchar();
    return 1;
}
    

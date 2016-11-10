#include <stdio.h>

int main()
{
    int age;
    
    printf("请输入年龄:");
    scanf("%d",&age); 
    
    if(age<18)
    {
        printf("对不起，你不能单独进入网吧！\n");
    }else{
        printf("欢迎光临！\n");
    }
             
    getch();
    return 0;        
}

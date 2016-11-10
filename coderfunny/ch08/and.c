#include <stdio.h>

int main()
{
    int x;
    
    printf("请输入一个整数:");
    scanf("%d",&x);
    
    if(x>=0 && x<=10)
    {
         printf("输入的数在0~10之间。\n"); 
      }else{
         printf("输入的数不在0~10之间。\n");
    }
    
    getch();
    return 0;
}

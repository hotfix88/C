#include <stdio.h>

int main()
{
    int x;
    
    printf("������һ������:");
    scanf("%d",&x);
    
    if(x>=0 && x<=10)
    {
         printf("���������0~10֮�䡣\n"); 
      }else{
         printf("�����������0~10֮�䡣\n");
    }
    
    getch();
    return 0;
}

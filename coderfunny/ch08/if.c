#include <stdio.h>

int main()
{
    int age;
    
    printf("����������:");
    scanf("%d",&age); 
    
    if(age<18)
    {
        printf("�Բ����㲻�ܵ����������ɣ�\n");
    }else{
        printf("��ӭ���٣�\n");
    }
             
    getch();
    return 0;        
}

#include <stdio.h>
#include <string.h>
//fengyang test 
//��Ϊpython�̵̳�c���ԱȶԸ�ϰʹ�� 
int main()
{
    int a,b;
    
    char c,t;
    char s[]="����";
    printf("hello world!\n");
    
    //ֵ���� 
    a = 100;
    b = a;
    a = 200;
    printf("%d,%d\n",a,b);
    
    //�ַ�
    c = 'z';
    printf("%d,%c\n",c,c);
    
    //֧�ֺ������� 
    int i,j;
    //��ӡ����ASCII�ַ� 
    for (i = 1;i<128;i++)
        printf("%c ",i);
        
   
    printf("\n%s\n",s);   
    printf("%d\n",sizeof(s)); 
   
    
    getchar();
    return 1;
}
    

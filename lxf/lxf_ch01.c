#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//fengyang test 
//��Ϊpython�̵̳�c���ԱȶԸ�ϰʹ�� 
int main()
{
    int a,b;
    
    char c,t;
    char s[]="����";
    char s1[10];
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
    for (i = 0;i<sizeof(s);i++)
        printf("%2X ",s[i]);
    printf("\n");
    
    memcpy(s1,s,sizeof(s));
    for (i = 0;i<sizeof(s1);i++)
        printf("%2X ",s1[i]);
    printf("\n");
    
    printf("%2X ",s[0]);
    printf("%2X\n",12);
    printf("%02X\n",12);
    
    
    getchar();
    return 1;
}
    

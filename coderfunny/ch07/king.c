#include <stdio.h>

int main()
{
    double chessboard,sum;
    int i;
    
    chessboard=1;
    sum=1;
    for(i=2;i<=64;i++)
    {
        chessboard*=2;
        sum+=chessboard;
        printf("��%d��������%10.0lf\n",i,chessboard);
    }
    printf("\n����������%10.0lf,Լ�ϣ�%10.2lf��\n",sum,sum/28000/1000); 
    
    getch();
    return 0;
}

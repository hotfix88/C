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
        printf("第%d格，麦粒：%10.0lf\n",i,chessboard);
    }
    printf("\n总麦粒数：%10.0lf,约合：%10.2lf吨\n",sum,sum/28000/1000); 
    
    getch();
    return 0;
}

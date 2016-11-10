#include <stdio.h>

int main()
{
    float thickness;  //单张纸的厚度
    float total;      //总的厚度
    float side[2];     //纸的长度和宽度 
    int count;        //对折次数 
    
    int i;
    float s;       //对折边长度 
    
    
    printf("纸张的长度：");
    scanf("%f",&side[0]);
    printf("纸张的宽度：");
    scanf("%f",&side[1]);
    printf("纸张的厚度:");
    scanf("%f",&thickness);
    
    total=thickness;
    count=0;
    printf("\n次数\t对折边长\t\t厚度\n") ;
    for(i=0;i<2;i++)
    {
        s=side[i];  //取得边长 
        if(i==0)
            printf("从长度方向对折\n");
        else
            printf("从宽度方向对折\n");
        while(s>total)
        {
            count++;
            s/=2;   //对折边长减半 
            total*=2;      //厚度加倍 
            printf("%2d\t%10.2f\t\t%10.2f\n",count,s,total);
        }
        
    } 
     
    getch();
    return 0;
}

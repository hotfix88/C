int main()
{
    int Dividend, Divisor,Result;
    Dividend = 8;
    Divisor = 0;
    if(Divisor==0){
        printf("��������Ϊ0��");
	}else{
        Result = Dividend / Divisor;
	    printf("%d/%d=%d",Dividend,Divisor,Result );
    }
    getch();
    return 0;
}

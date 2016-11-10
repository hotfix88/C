long fact(int f)
{
     long result=1;
     int i;
     for(i=2;i<=f;i++)
     {
        result*=i;
     }
     return result;
}
		
int main()
{
     int f;
     long r;
 	 for (f=1;f<=20;f++)
 	 {
	 	r=fact(f);
	 	printf("%d!=%d\n",f,r);
     }
     getch();
     return 0;
}

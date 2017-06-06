/*#include<stdio.h>
int main()
{
	int n,x,i,t,y;
	for(n=6;n>=6&&n<=20;n=n+2)
	{
		for(x=2;x<=n/2;x++)
		{
			for(i=2;i<x;i++)
			if(x%i==0) break;
			if(i>=x)
				y=n-x;
			for(t=2;t<y;t++)
			if(y%t==0) break;
			if(t>=y)
			{	
				printf("%d=%d+%d\n",n,x,y);
				break;
			}
		}
	}
	return 0;
}
*/


#include<stdio.h>
int main()
{
	int n,x,i,t,y;
	for(n=6;n>=6;n=n+2)
	{
		for(x=2;x<=n/2;x++)
		{
			for(i=2;i<x;i++)
			if(x%i==0) break;
			if(i>=x)
				y=n-x;
			for(t=2;t<y;t++)
			if(y%t==0) break;
			if(t>=y)
			{	
				printf("%d=%d+%d\n",n,x,y);
				break;
			}
		}
	}
	return 0;
}

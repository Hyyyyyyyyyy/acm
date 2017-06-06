#include<stdio.h>
#include<string.h>
int main()
{
	char a[10006]={0};
	int L1;
	int i;
	while(scanf("%s",a)==1)
	{
		L1=strlen(a);
		for(i=0;i<L1;i++)
		{
			a[i]-=48;
			printf("%d",a[i]);
		}
		memset(a,0,sizeof a);
	}
	return 0;
}

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int Mainl, Assl;
char ar[100010];
int Next[100010];
void Cal_Next();
int main()
{
	int i, j, k, n, m, re, t;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%s", ar);
			Mainl = strlen(ar);
			Cal_Next();
			re = Mainl - Next[Mainl];
			if (re != Mainl && Mainl % re == 0)
			{
				printf("0\n");
			}
			else
			{
				t = re - Mainl % re;
				printf("%d\n", t);
			}
		}
	}
	return 0;
}
void Cal_Next()
{
	int i = 0, j = -1;
	Next[0] = -1;
	while (i < Mainl)
	{
		if (j == -1 || ar[i] == ar[j])
		{
			Next[++i] = ++j;
		}
		else
			j = Next[j];
	}
}
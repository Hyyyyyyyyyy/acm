#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int Mainl, Assl;
char ar[1000010];
int Next[1000010];
void Cal_Next();
int main()
{
	int n, m, i, j, doudou = 0, cas = 1;
	while (scanf("%d", &n) != EOF && n)
	{
		scanf("%s", ar + 1);
		Assl = n;
		Cal_Next();
		//for (i = 1; i <= n; i++)
		//	printf("%d ", Next[i]);
		//putchar('\n');
		printf("Test case #%d\n", cas++);
		for (i = 2; i <= n; i++)
		{
			if (i % (i - Next[i]) == 0 && Next[i] != 0)
				printf("%d %d\n", i, i / (i - Next[i]));
		}
		putchar('\n');
	}
	return 0;
}
void Cal_Next()
{
	int i, j, L = 1;
	Next[1] = 0;
	for (i = 2; i <= Assl; i++)
	{
		j = Next[i - 1];
		while (ar[j + 1] != ar[i] && j >= 1)
		{
			j = Next[j];
		}
		if (ar[j + 1] == ar[i])
		{
			Next[i] = j + 1;
		}
		else
			Next[i] = 0;
	}
}
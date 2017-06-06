#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int Mainl, Assl;
int sa[10010], ar[1000010];
int Next[10010];
void Cal_Next();
int KMP();
int main()
{
	int i, j, k, n, m;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &Mainl, &Assl);
			for (i = 1; i <= Mainl; i++)
				scanf("%d", &ar[i]);
			for (i = 1; i <= Assl; i++)
				scanf("%d", &sa[i]);
			Cal_Next();
			printf("%d\n", KMP());
		}
	}
	return 0;
}
int KMP()
{
	int i, j, L1, L2, doudou = 0;
	i = 1;
	j = 1;
	while (i <= Mainl && j <= Assl)
	{
		if (ar[i] == sa[j])
		{
			if (j == Assl)
			{
				doudou = 1;
				break;
			}
			else;
			i++;
			j++;
		}
		else
		{
			if (j == 1)
			{
				i++;
			}
			else
			{
				j = Next[j - 1] + 1;
			}
		}
	}
	if (doudou)
		return i - Assl + 1;
	return -1;
}
void Cal_Next()
{
	int i, j, k, L1, L2;
	Next[1] = 0;
	for (i = 2; i <= Assl; i++)
	{
		j = Next[i - 1];
		while (sa[i] != sa[j + 1] && j > 0)
		{
			j = Next[j];
		}
		if (sa[i] == sa[j + 1])
			Next[i] = j + 1;
		else
			Next[i] = 0;
	}
}

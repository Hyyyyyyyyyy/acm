#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 200;
int ar[maxn], sa[maxn], sf[maxn];
int main()
{
	int i, j, k, u, n, m, doudou1, doudou2, doudou3;
	while (scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", &ar[1], &ar[2], &ar[3], &ar[4], &ar[5], &ar[6], &ar[7], &ar[8], &sa[1], &sa[2], &sa[3], &sa[4], &sa[5], &sa[6], &sa[7], &sa[8], &sf[1], &sf[2], &sf[3], &sf[4], &sf[5], &sf[6], &sf[7], &sf[8]) != EOF)
	{
		doudou1 = doudou2 = doudou3 = 0;
		for (i = 1; i <= 8; i++)
		{
			if (ar[i] < sa[i] && doudou2 == 0)
				break;
			if (ar[i] > sa[i])
			{
				doudou2 = 1;
			}
			if (ar[i] < sf[i] && doudou3 == 0)
				break;
			if (ar[i] > sf[i])
			{
				doudou3 = 1;
			}
		}
		if (doudou2 && doudou3)
		{
			printf("1\n");
			continue;
		}
		for (i = 1; i <= 8; i++)
		{
			if (sa[i] < ar[i] && doudou1 == 0)
				break;
			if (sa[i] > ar[i])
			{
				doudou1 = 1;
			}
			if (sa[i] < sf[i] && doudou3 == 0)
				break;
			if (sa[i] > sf[i])
			{
				doudou3 = 1;
			}
		}
		if (doudou1 && doudou3)
		{
			printf("2\n");
			continue;
		}
		for (i = 1; i <= 8; i++)
		{
			if (sf[i] < ar[i] && doudou1 == 0)
				break;
			if (sf[i] > ar[i])
			{
				doudou1 = 1;
			}
			if (sf[i] < sa[i] && doudou2 == 0)
				break;
			if (sf[i] > sa[i])
			{
				doudou2 = 1;
			}
		}
		if (doudou1 && doudou2)
		{
			printf("3\n");
			continue;
		}
		printf("1\n");
	}
	return 0;
}
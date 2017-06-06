#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int ar[30], cur[300], pre[300];
int main()
{
	int i, j, k, u, n, m;
	for (i = 0; i <= 18; i++)
	{
		ar[i] = i*i;
	}
	while (scanf("%d", &n) != EOF && n)
	{
		memset(pre, 0, sizeof(pre));
		memset(cur, 0, sizeof(cur));
		for (i = 0; i <= n; i++)
		{
			pre[i] = 1;
		}
		for (i = 2; i <= 17; i++)
		{
			for (j = 0; j <= n; j++)
			{
				for (k = 0; k + j <= n; k += ar[i])
				{
					cur[k + j] += pre[j];
				}
			}
			for (j = 0; j <= n; j++)
			{
				pre[j] = cur[j];
				cur[j] = 0;
			}
		}
		printf("%d\n", pre[n]);
	}
	return 0;
}

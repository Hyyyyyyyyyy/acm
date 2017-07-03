#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1200;
int ar[maxn], set[maxn];
int main()
{
	int i, j, k, n, m, a, b;
	memset(set, 0, sizeof(set));
	for (i = 2; i <= maxn; i++)
	{
		if (set[i])
			continue;
		for (j = i*i; j <= maxn; j += i)
		{
			set[j] = 1;
		}
	}
	//for (i = 1; i <= 1000; i++)
	//	printf("%d ", set[i]);
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &a);
			int res = 0;
			for (i = 2; i <= a / 2; i++)
			{
				if (set[i] && !set[a - i])
				{
					res++;
				}
				if (!set[i] && set[a - i])
				{
					res++;
				}
			}
			printf("%d\n", res);
		}
	}
	return 0;
}
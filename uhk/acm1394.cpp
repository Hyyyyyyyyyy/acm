#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 5000 + 10;
int ar[maxn], sa[maxn];
int main()
{
	int i, j, k, u, n, m, res, cnt, MAX;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &ar[i]);
		}
		cnt = 0;
		for (i = 1; i <= n; i++)
		{
			for (j = i + 1; j <= n; j++)
			{
				if (ar[i] > ar[j])
					cnt++;
			}
		}
		res = cnt;
		for (i = 1; i < n; i++)
		{
			cnt = cnt - ar[i] + (n- 1 - ar[i]);
			if (res > cnt)
				res = cnt;
		}
		printf("%d\n", res);
	}
	return 0;
}

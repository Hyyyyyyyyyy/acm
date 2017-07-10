#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 50000 + 100;
int ar[maxn], block_id[maxn], block_res[maxn];
int block_len;
int N, M;
void init(int n)
{
	int i, j, k;
	block_len = (int)sqrt(n);
	memset(block_res, 0, sizeof(block_res));
	for (i = 1; i <= n; i++)
	{
		int u = i / block_len;
		block_id[i] = u;
		block_res[u] += ar[i];
	}
}
int query(int begin, int end)
{
	int i, j;
	int res = 0;
	for (i = begin; i <= end;)
	{
		if (i % block_len == 0 && i + block_len - 1 <= end)
		{
			res += block_res[block_id[i]];
			i += block_len;
		}
		else
		{
			res += ar[i];
			i++;
		}
	}
	return res;
}
int main()
{
	int i, j, k, u, n, m, a, b;
	char s[20];
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &N);
			for (i = 1; i <= N; i++)
				scanf("%d", &ar[i]);
			init(N);
			int doudou = 0;
			while (1)
			{
				scanf("%s", s);
				if (strcmp(s, "End") == 0)
					break;
				scanf("%d %d", &a, &b);
				if (strcmp(s, "Query") == 0)
				{
					if (!doudou)
						printf("Case %d:\n", m);
					doudou = 1;
					printf("%d\n", query(a, b));
				}
				else if (strcmp(s, "Add") == 0)
				{
					block_res[block_id[a]] += b;
					ar[a] += b;
				}
				else
				{
					block_res[block_id[a]] -= b;
					ar[a] -= b;
				}
			}
		}
	}
	return 0;
}
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int MAX = 100000000;
const int MIN = -100000000;

unsigned long long now[1000000], pre[1000000];
unsigned long long ar[30][30];
unsigned long long temp[1000000], dp[1000000], ans[1000000];
unsigned long long now_size, pre_size, n;
void dfs(unsigned long long x, unsigned long long y, unsigned long long sta, unsigned long long sum);
void DP();
int main()
{
	unsigned long long i, j, k, u, a, b, c, res;
	while (scanf("%llu", &n) != EOF)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				scanf("%llu", &ar[i][j]);
			}
		}
		pre_size = 2;
		temp[1] = pre[1] = 0;
		DP();
		res = 0;
		for (i = 1; i < pre_size; i++)
		{
			if (res < temp[i])
				res = temp[i];
		}
		printf("%llu\n", res);
	}
	return 0;
}
void DP()
{
	unsigned long long i, j, k;
	for (k = 1; k <= n; k++)
	{
		now_size = 1;
		dfs(k, 1, 0, 0);
		memset(dp, 0, sizeof(dp));
		for (i = 1; i < now_size; i++)
		{
			for (j = 1; j < pre_size; j++)
			{
				if (!(now[i] & pre[j]))
					dp[i] = (dp[i] > temp[j] + ans[i]) ? dp[i] : (temp[j] + ans[i]);
			}
		}
		for (i = 1; i < now_size; i++)
		{
			pre[i] = now[i];
			temp[i] = dp[i];
		}
		pre_size = now_size;
	}
}

void dfs(unsigned long long x, unsigned long long y, unsigned long long sta, unsigned long long sum)
{
	while (y > n)
	{
		now[now_size] = sta;
		ans[now_size++] = sum;
		return;
	}
	dfs(x, y + 1, sta, sum);
	dfs(x, y + 2, (sta | 1 << y), sum + ar[x][y]);
}

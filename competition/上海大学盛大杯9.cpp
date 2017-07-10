#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <cctype>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 500 + 30;
typedef long long ll;
int ar[maxn][maxn], visit[maxn][maxn], set[maxn];
int N, M;
int prime[maxn + 1];
void getprime()
{
	int i, j;
	memset(prime, 0, sizeof(prime));
	for (i = 2; i <= maxn; i++)
	{
		if (!prime[i])
			prime[++prime[0]] = i;
		for (j = 1; j <= prime[0] && i*prime[j] <= maxn; j++)
		{
			prime[prime[j] * i] = 1;
			if (i % prime[j] == 0)
				break;
		}
	}
}
int dfs(int x, int y)
{
	int i, j;
	if (visit[x][y])
		return ar[x][y];
	visit[x][y] = 1;
	for (i = 1; i <= prime[0]; i++)
	{
		if (x - prime[i] > 0)
			ar[x][y] |= !dfs(x - prime[i], y);
		if (y - prime[i] > 0)
			ar[x][y] |= !dfs(x, y - prime[i]);
		if (x - prime[i] > 0 && y - prime[i] > 0)
			ar[x][y] |= !dfs(x - prime[i], y - prime[i]);
	}
	return ar[x][y];
}
int main()
{
	int i, j, k, u, n, m, a, b;
	getprime();
	memset(ar, 0, sizeof(ar));
	memset(visit, 0, sizeof(visit));
	for (i = 1; i <= 500; i++)
	{
		for (j = 1; j <= 500; j++)
		{
			dfs(i, j);
		}
	}
	//for (i = 1; i <= 500; i++)
	//{
	//	for (j = 1; j <= 500; j++)
	//	{
	//		printf("%d ", ar[i][j]);
	//	}
	//	putchar('\n');
	//}
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &a, &b);
			if (ar[a][b])
				printf("Sora\n");
			else
				printf("Shiro\n");
		}
	}
	return 0;
}
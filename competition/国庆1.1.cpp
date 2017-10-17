#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const int INF = 100000000;
const int MOD = 1e9 + 7;
const int maxn = 100;
int N, M, K;
int C[maxn];
struct Node
{
	int x;
	int y;
};
Node node[maxn];
int ar[10][10];
int doudou, cnt;
bool check(int n, int c)
{
	if (ar[node[n].x - 1][node[n].y] == c || ar[node[n].x + 1][node[n].y] == c || ar[node[n].x][node[n].y - 1] == c || ar[node[n].x][node[n].y + 1] == c)
		return false;
	return true;
}
void dfs(int n)
{
	if (doudou)
		return;
	int i, j;
	if (n == cnt + 1)
	{
		printf("YES\n");
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= M; j++)
			{
				if (j == 1)
					printf("%d", ar[i][j]);
				else
					printf(" %d", ar[i][j]);
			}
			putchar('\n');
		}
		doudou = 1;
		return;
	}
	for (i = 1; i <= K; i++)
	{
		if (C[i] > (cnt - n + 2) / 2)
			return;
	}
	for (i = 1; i <= K; i++)
	{
		if (C[i] > 0 && check(n, i))
		{
			C[i]--;
			ar[node[n].x][node[n].y] = i;
			dfs(n + 1);
			if (doudou)
				return;
			C[i]++;
			ar[node[n].x][node[n].y] = 0;
		}
	}
}
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d %d", &N, &M, &K);
			for (i = 1; i <= K; i++)
			{
				scanf("%d", &C[i]);
			}
			cnt = 0;
			for (i = 1; i <= N; i++)
			{
				for (j = 1; j <= M; j++)
				{
					node[++cnt].x = i;
					node[cnt].y = j;
				}
			}
			memset(ar, 0, sizeof(ar));
			doudou = 0;
			printf("Case #%d:\n", m);
			dfs(1);
			if (!doudou)
			{
				printf("NO\n");
			}
		}
	}
	return 0;
}
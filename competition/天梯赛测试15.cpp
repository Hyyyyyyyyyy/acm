#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cctype>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define foR for
#define for9 for
#define retunr return
#define reutrn return
#define reutnr return
const int inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1000000007ll;
const int maxn = 100 + 100;
const int maxm = 1000000 + 100;
int N;
int ar[maxn][maxn];
char s[maxn];
int vis[maxn];
int pre[maxn];
bool dfs(int u, int dep)
{
	int i, j;
	if (dep == N && ar[u][1] == 1)
		return true;
	//加上这个错了，别乱剪枝
	// if (dep == N+1 && ar[u][1] != 1)
	// 	return false;
	if (dep > N+1)
		return false;
	for(i = 1; i <= N; i++)
		if(!vis[i] && ar[i][1] == 1)
			break;
	if(i > N)
		return false;
	for (i = 1; i <= N; i++)
	{
		if (!vis[i] && ar[u][i] == 1)
		{
			vis[i] = 1;
			if (dfs(i, dep + 1))
			{
				pre[u] = i;
				return true;
			}
			vis[i] = 0;
		}
	}
	return false;
}

int main()
{
	int i, j, k, n;
	while (scanf("%d", &N) != EOF)
	{
		memset(ar, -1, sizeof(ar));
		memset(pre, -1, sizeof(pre));
		for (i = 1; i <= N; i++)
		{
			scanf("%s", s);
			for (j = 0; j < N; j++)
			{
				if (s[j] == 'W')
					ar[i][j + 1] = 1;
				if (s[j] == 'L')
					ar[j + 1][i] = 1;
			}
		}
		memset(vis, 0, sizeof(vis));
		vis[1] = 1;
		if (!dfs(1, 1))
		{
			printf("No Solution\n");
			continue;
		}
		int doudou = 0;
		i = 1;
		while (i != -1)
		{
			if (doudou)
				printf(" ");
			doudou = 1;
			printf("%d", i);
			i = pre[i];
		}
		printf("\n");
	}
	return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <cctype>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 20000 + 100;
typedef long long ll;
struct Node
{
	int xue;
	int gong;
};
Node ar[15], sa[15], t[15];
int visit[15];
int N, M;
bool dfs(int num, int blood, int id, int xue, int gong)
{
	int i, j, k;
	if (id > N && blood > 0)
		return true;
	if (sa[num].gong >= xue && gong >= blood)
	{
		for (i = 1; i <= N; i++)
		{
			if (visit[i])
				continue;
			visit[i] = 1;
			if (dfs(i, sa[i].xue, id + 1, ar[id + 1].xue, ar[id + 1].gong))
				return true;
			visit[i] = 0;
		}
	}
	else if (xue <= sa[num].gong && blood > gong)
	{
		if (dfs(num, blood - gong, id + 1, ar[id + 1].xue, ar[id + 1].gong))
			return true;
	}
	else if (xue > sa[num].gong && blood <= gong)
	{
		for (i = 1; i <= N; i++)
		{
			if (visit[i])
				continue;
			visit[i] = 1;
			if (dfs(i, sa[i].xue, id, xue - sa[num].gong, gong))
				return true;
			visit[i] = 0;
		}
	}
	else
	{
		if (dfs(num, blood - gong, id, xue - sa[num].gong, gong))
			return true;
	}
	return false;
}
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &N);
			for (i = 1; i <= N; i++)
			{
				scanf("%d %d", &ar[i].xue, &ar[i].gong);
			}
			for (i = 1; i <= N; i++)
			{
				scanf("%d %d", &sa[i].xue, &sa[i].gong);
				t[i] = sa[i];
			}
			memset(visit, 0, sizeof(visit));
			int doudou = 0;
			for (i = 1; i <= N; i++)
			{
				visit[i] = 1;
				if (dfs(i, sa[i].xue, 1, ar[1].xue, ar[1].gong))
				{
					doudou = 1;
					break;
				}
				visit[i] = 0;
			}
			if (doudou)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
	}
	return 0;
}
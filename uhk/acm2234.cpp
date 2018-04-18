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
#define retrun return
const int inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1000000007ll;
const int maxn = 10;
const int maxm = 1000000 + 100;
int ar[maxn][maxn];
int vis[maxn];
int res;
bool check()
{
	int i, j, k;
	for (i = 1; i <= 4; i++)
	{
		for (j = 1; j <= 4; j++)
		{
			if (ar[i][i] != ar[i][j])
				return false;
		}
	}
	for (i = 1; i <= 4; i++)
	{
		for (j = 1; j <= 4; j++)
		{
			if (ar[i][i] != ar[j][i])
				return false;
		}
	}
	return true;
}
int getH()
{
	int i, j, k;
	int num_vis[5];
	memset(num_vis, 0, sizeof(num_vis));
	int cnt = inf;
	int temp = 0;
	int ans = 0;
	for (i = 1; i <= 4; i++)
	{
		temp = 0;
		memset(num_vis, 0, sizeof(num_vis));
		for (j = 1; j <= 4; j++)
		{
			num_vis[ar[i][j]] = 1;
		}
		for (j = 1; j <= 4; j++)
			if (num_vis[j])
				temp++;
		ans = max(ans, temp);
	}
	cnt = min(cnt, ans);
	ans = 0;
	for (j = 1; j <= 4; j++)
	{
		temp = 0;
		memset(num_vis, 0, sizeof(num_vis));
		for (i = 1; i <= 4; i++)
		{
			num_vis[ar[i][j]] = 1;
		}
		for (i = 1; i <= 4; i++)
			if (num_vis[i])
				temp++;
		ans = max(ans, temp);
	}
	cnt = min(cnt, ans);
	return cnt-1;
}
void move_up(int x)
{
	int i, j;
	int temp = ar[1][x];
	for (i = 2; i <= 4; i++)
		ar[i - 1][x] = ar[i][x];
	ar[4][x] = temp;
}
void move_down(int x)
{
	int i, j;
	int temp = ar[4][x];
	for (i = 3; i >= 1; i--)
		ar[i + 1][x] = ar[i][x];
	ar[1][x] = temp;
}
void move_left(int x)
{
	int i, j;
	int temp = ar[x][1];
	for (i = 2; i <= 4; i++)
		ar[x][i - 1] = ar[x][i];
	ar[x][4] = temp;
}
void move_right(int x)
{
	int i, j;
	int temp = ar[x][4];
	for (i = 3; i >= 1; i--)
		ar[x][i + 1] = ar[x][i];
	ar[x][1] = temp;
}
bool IDA_dfs(int dep)
{
	if (dep + getH() > res)
		return false;
	if (dep == res)
	{
		if (getH() == 0)
			return true;
		return false;
	}
	int i, j;
	for (i = 1; i <= 4; i++)
	{
		move_left(i);
		if (IDA_dfs(dep + 1))
			return true;
		move_right(i);
		move_right(i);
		if (IDA_dfs(dep + 1))
			return true;
		move_left(i);
	}
	for (j = 1; j <= 4; j++)
	{
		move_up(j);
		if (IDA_dfs(dep + 1))
			return true;
		move_down(j);
		move_down(j);
		if (IDA_dfs(dep + 1))
			return true;
		move_up(j);
	}
	return false;
}
int main()
{
	int i, j, k, cas, CAS;
	while (scanf("%d", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			for (i = 1; i <= 4; i++)
			{
				for (j = 1; j <= 4; j++)
				{
					scanf("%d", &ar[i][j]);
				}
			}
			if (check())
			{
				printf("0\n");
				continue;
			}

			for (res = getH(); res <= 5; res++)
			{
				if (IDA_dfs(0))
					break;
			}
			if (res <= 5)
				printf("%d\n", res);
			else
				printf("-1\n");
		}
	}
	return 0;
}
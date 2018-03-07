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
const ll MOD = 100000007ll;
const int maxn = 100000 + 100;
const int maxm = 1000000 + 100;
int N;
int vis[20][20];
bool check(int x, int y)
{
	if (x - 1 >= 1 && y + 2 <= 9 && vis[x - 1][y + 2] == 4 && !vis[x - 1][y + 1])
		return true;
	if (x - 2 >= 1 && y + 1 <= 9 && vis[x - 2][y + 1] == 4 && !vis[x - 1][y + 1])
		return true;
	if (x - 2 >= 1 && y - 1 >= 1 && vis[x - 2][y - 1] == 4 && !vis[x - 1][y - 1])
		return true;
	if (x - 1 >= 1 && y - 2 >= 1 && vis[x - 1][y - 2] == 4 && !vis[x - 1][y - 1])
		return true;
	if (x + 1 <= 10 && y - 2 >= 1 && vis[x + 1][y - 2] == 4 && !vis[x + 1][y - 1])
		return true;
	if (x + 2 <= 10 && y - 1 >= 1 && vis[x + 2][y - 1] == 4 && !vis[x + 1][y - 1])
		return true;
	if (x + 2 <= 10 && y + 1 <= 9 && vis[x + 2][y + 1] == 4 && !vis[x + 1][y + 1])
		return true;
	if (x + 1 <= 10 && y + 2 <= 9 && vis[x + 1][y + 2] == 4 && !vis[x + 1][y + 1])
		return true;

	int num;
	num = 0;
	for (int i = x + 1; i <= 10; i++)
	{
		if (num == 0 && (vis[i][y] == 1 || vis[i][y] == 2))
			return true;
		else if (num == 1 && vis[i][y] == 3)
			return true;
		else if (vis[i][y])
			num++;
	}

	num = 0;
	for (int i = x - 1; i >= 1; i--)
	{
		if (num == 0 && (vis[i][y] == 1 || vis[i][y] == 2))
			return true;
		else if (num == 1 && vis[i][y] == 3)
			return true;
		else if (vis[i][y])
			num++;
	}

	num = 0;
	for (int i = y + 1; i <= 9; i++)
	{
		if (num == 0 && (vis[x][i] == 1 || vis[x][i] == 2))
			return true;
		else if (num == 1 && vis[x][i] == 3)
			return true;
		else if (vis[x][i])
			num++;
	}

	num = 0;
	for (int i = y - 1; i >= 1; i--)
	{
		if (num == 0 && (vis[x][i] == 1 || vis[x][i] == 2))
			return true;
		else if (num == 1 && vis[x][i] == 3)
			return true;
		else if (vis[x][i])
			num++;
	}
	return false;
}
int main()
{
	int i, j, k, n, m, x, y, X, Y;
	char s[3];
	while (scanf("%d %d %d", &N, &X, &Y) != EOF && N + X + Y)
	{
		memset(vis, 0, sizeof(vis));
		for (i = 1; i <= N; i++)
		{
			scanf("%s %d %d", s, &x, &y);
			if (s[0] == 'G')
				vis[x][y] = 1;
			else if (s[0] == 'R')
				vis[x][y] = 2;
			else if (s[0] == 'C')
				vis[x][y] = 3;
			else
				vis[x][y] = 4;
		}
		bool flag = true;
		if (X + 1 <= 3 && X + 1 >= 1)
		{
			if (!check(X + 1, Y))
			{
				flag = false;
			}
		}
		if (X - 1 >= 1 && X - 1 <= 3)
		{
			if (!check(X - 1, Y))
			{
				flag = false;
			}
		}
		if (Y + 1 <= 6 && Y + 1 >= 4)
		{
			if (!check(X, Y + 1))
			{
				flag = false;
			}
		}
		if (Y - 1 >= 4 && Y - 1 <= 6)
		{
			if (!check(X, Y - 1))
			{
				flag = false;
			}
		}
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
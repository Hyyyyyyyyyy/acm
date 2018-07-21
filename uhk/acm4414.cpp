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
const int maxn = 50 + 100;
const int maxm = 1000000 + 100;
char ar[maxn][maxn];
int N;
bool check(int r, int c, int cnt)
{
	if (r + cnt > N || c + cnt > N || r - cnt < 1 || c - cnt < 1)
		return false;
	if (ar[r + cnt][c] == '#' && ar[r - cnt][c] == '#' && ar[r][c + cnt] == '#' && ar[r][c - cnt] == '#')
		return true;
	return false;
}
bool solve(int r, int c)
{
	int i, j, k;
	int cnt = 1;
	while (check(r, c, cnt))
	{
		cnt++;
	}
	if (cnt <= 1)
		return false;
	if (r + cnt <= N)
	{
		if (ar[r + cnt][c] == '#')
			return false;
	}
	if (r - cnt >= 1)
	{
		if (ar[r - cnt][c] == '#')
			return false;
	}
	if (c + cnt <= N)
	{
		if (ar[r][c + cnt] == '#')
			return false;
	}
	if (c - cnt >= 1)
	{
		if (ar[r][c - cnt] == '#')
			return false;
	}
	cnt--;
	for (i = 1; i <= cnt; i++)
	{
		if (ar[r - 1][c - i] == '#' || ar[r - 1][c + i] == '#')
			return false;
		if (ar[r + 1][c - i] == '#' || ar[r + 1][c + i] == '#')
			return false;
		if (ar[r - i][c - 1] == '#' || ar[r+i][c-1] == '#')
			return false;
		if (ar[r-i][c+1] == '#' || ar[r+i][c+1] == '#')
			return false;
	}
	return true;
}
int main()
{
	int i, j, k;
	while (scanf("%d", &N) != EOF && N)
	{
		for (i = 1; i <= N; i++)
		{
			scanf("%s", ar[i] + 1);
		}
		int res = 0;
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{
				if (ar[i][j] == 'o')
					continue;
				if (solve(i, j))
					res++;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
//4414            找十字架，模拟
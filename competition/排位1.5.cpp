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
const int maxn = 200 + 100;
const int maxm = 1000000 + 100;
char ar[maxn][maxn];
int N, M, X, Y;
int vis[maxn][maxn];
int dir[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
struct Node
{
	int x;
	int y;
	int step;
};
Node oo[40000];
void dfs(int x, int y)
{
		int i, j;
		for (i = x + 1; i <= N; i++)
		{
			if (ar[i][y] == '.' || ar[i][y] == '@')
				ar[i][y] = 'o';
			if (ar[i][y] == 'x')
				break;
		}
		for (i = x - 1; i >= 1; i--)
		{
			if (ar[i][y] == '.' || ar[i][y] == '@')
				ar[i][y] = 'o';
			if (ar[i][y] == 'x')
				break;
		}
		for (j = y + 1; j <= M; j++)
		{
			if (ar[x][j] == '.' || ar[x][j] == '@')
				ar[x][j] = 'o';
			if (ar[x][j] == 'x')
				break;
		}
		for (j = y - 1; j >= 1; j--)
		{
			if (ar[x][j] == '.' || ar[x][j] == '@')
				ar[x][j] = 'o';
			if (ar[x][j] == 'x')
				break;
		}
}
int bfs()
{
	int i, j, k;
	if (ar[X][Y] == 'o')
		return -1;
	queue<Node>Q;
	memset(vis, 0, sizeof(vis));
	Node now, after;
	now.x = X;
	now.y = Y;
	now.step = 0;
	vis[X][Y] = 1;
	Q.push(now);
	while (!Q.empty())
	{
		now = Q.front();
		Q.pop();
		if (now.x == 1 || now.y == 1 || now.x == N || now.y == M)
			return now.step;
		for (i = 0; i < 4; i++)
		{
			after.x = now.x + dir[i][0];
			after.y = now.y + dir[i][1];
			after.step = now.step + 1;
			if (after.x < 1 || after.x > N || after.y < 1 || after.y > M)
				continue;
			if (vis[after.x][after.y])
				continue;
			if (ar[after.x][after.y] == 'o' || ar[after.x][after.y] == 'x')
				continue;
			Q.push(after);
			vis[after.x][after.y] = 1;
		}
	}
	return -1;
}
int main()
{
	int i, j, k, cas, CAS;

	while (scanf("%d", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%d %d", &N, &M);
			int cnt = 0;
			for (i = 1; i <= N; i++)
			{
				scanf("%s", ar[i] + 1);
				for (j = 1; j <= M; j++)
				{
					if (ar[i][j] == '@')
					{
						X = i;
						Y = j;
					}
					if (ar[i][j] == 'o')
					{
						oo[cnt].x = i;
						oo[cnt++].y = j;
					}
				}
			}
			for (i = 0; i < cnt; i++)
			{
				dfs(oo[i].x, oo[i].y);
			}
			//for (i = 1; i <= N; i++)
			//{
			//	if (ar[i][1] == '.' || ar[i][1] == '@')
			//		ar[i][1] = '!';
			//	if (ar[i][M] == '.' || ar[i][M] == '@')
			//		ar[i][M] = '!';
			//}
			//for (j = 1; j <= M; j++)
			//{
			//	if (ar[1][j] == '.' || ar[1][j] == '@')
			//		ar[1][j] = '!';
			//	if (ar[N][j] == '.' || ar[N][j] == '@')
			//		ar[N][j] = '!';
			//}
			int res = bfs();
			if (res == -1)
				printf("no zuo no die!\n");
			else
				printf("%d\n", res + 1);
		}
	}
	return 0;
}

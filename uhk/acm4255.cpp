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
const int maxn = 40000 + 100;
const int maxm = 1000000 + 100;
int dir[4][2] = { -1, 0, 0 , -1, 1, 0, 0, 1 };
int N, M;
struct Node
{
	int x;
	int y;
	int dist;
	//bool operator < (const Node& a) const
	//{
	//	return dist > a.dist;
	//}
};
queue<Node>Q;
int vis[210][210];
bool check[maxn];       //true表示不是素数 false是素数
int prime[maxn];        //前tot-1个素数是什么
int tot;                //素数个数是tot-1
void prime_table(int N)
{
	memset(check, false, sizeof(check));
	check[1] = true;
	tot = 0;
	for (int i = 2; i <= N; i++)
	{
		if (!check[i])
		{
			prime[tot++] = i;
		}
		for (int j = 0; j < tot; j++)
		{
			if (i * prime[j] > N)
				break;
			check[i * prime[j]] = true;
		}
	}
}
//质数个数 < tot
int hui[210][210];
void huihuan(int N)
{
	int n = N;
	int sq = (int)sqrt((double)N);
	for (int i = sq; i >= 2; i -= 2)
	{
		int up = (sq - i) / 2 + i;
		int down = (sq - i) / 2 + 1;
		for (int y = down; y <= up; y++)
		{
			hui[down][y] = n--;
		}
		for (int x = down + 1; x <= up; x++)
		{
			hui[x][up] = n--;
		}
		for (int y = up - 1; y >= down; y--)
		{
			hui[up][y] = n--;
		}
		for (int x = up - 1; x > down; x--)
		{
			hui[x][down] = n--;
		}
	}
}
//N是一个平方数 且是整个宫格中最大数
int bfs(int X, int Y)
{
	int i, j, k;
	while (!Q.empty())
		Q.pop();
	memset(vis, 0, sizeof(vis));
	vis[X][Y] = 1;
	Node now;
	now.x = X;
	now.y = Y;
	now.dist = 0;
	Q.push(now);
	while (!Q.empty())
	{
		now = Q.front();
		Q.pop();
		if (hui[now.x][now.y] == M)
			return now.dist;
		for (i = 0; i < 4; i++)
		{
			Node temp;
			temp.x = now.x + dir[i][0];
			temp.y = now.y + dir[i][1];
			temp.dist = now.dist + 1;
			if (temp.x < 1 || temp.y < 1 || temp.x > 200 || temp.y > 200)
				continue;
			if (check[hui[temp.x][temp.y]] && !vis[temp.x][temp.y])
			{
				Q.push(temp);
				vis[temp.x][temp.y] = 1;
			}
		}
	}
	return -1;
}
int main()
{
	int i, j, k, cas = 1, x, y;
	prime_table(maxn);
	huihuan(40000);
	while (scanf("%d %d", &N, &M) != EOF)
	{
		//for (i = 2; i <= 100; i++)
		//	printf("%d ", check[i]);
		//putchar('\n');
		//for (i = 46; i <= 55; i++)
		//{
		//	for (j = 46; j <= 55; j++)
		//	{
		//		printf("%d ", hui[i][j]);
		//		if (hui[i][j] == N)
		//		{
		//			x = i;
		//			y = j;
		//		}
		//	}
		//	putchar('\n');
		//}
		for (i = 1; i <= 200; i++)
		{
			for (j = 1; j <= 200; j++)
			{
				if (hui[i][j] == N)
				{
					x = i;
					y = j;
				}
			}
		}
		int res = bfs(x, y);
		if (res != -1)
		{
			printf("Case %d: %d\n", cas++, res);
		}
		else
		{
			printf("Case %d: impossible\n", cas++);
		}
	}
	return 0;
}

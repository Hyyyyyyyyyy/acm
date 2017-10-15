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
const ll MOD = 1e9 + 7;
const int maxn = 10 + 100;
bool visit[maxn][maxn][1 << 5];
int N, M, bx, by, K;
int dir[4][2] = { -1, 0, 0, -1, 1, 0, 0 , 1 };
struct Node
{
	int x;
	int y;
	int step;
	int key;
	bool operator < (const Node& p) const
	{
		return step > p.step;
	}
};
Node now, after;
char ar[maxn][maxn];
int Pow[6];
int bfs()
{
	int i, j;
	priority_queue<Node>Q;
	memset(visit, false, sizeof(visit));
	now.x = bx;
	now.y = by;
	now.step = 0;
	now.key = 0;
	visit[bx][by][0] = true;
	Q.push(now);
	while (!Q.empty())
	{
		now = Q.top();
		Q.pop();
		if (now.key == Pow[K])
		{
			return now.step;
		}
		for (i = 0; i < 4; i++)
		{
			after.x = now.x + dir[i][0];
			after.y = now.y + dir[i][1];
			after.step = now.step + 1;
			after.key = now.key;
			if (after.x > N || after.x < 1 || after.y > M || after.y < 1 || ar[after.x][after.y] == '#')
				continue;
			if (ar[after.x][after.y] >= 'a' && ar[after.x][after.y] <= 'z')
			{
				if (visit[after.x][after.y][after.key | (1 << (ar[after.x][after.y] - 'a'))])
					continue;
				after.key |= (1 << (ar[after.x][after.y] - 'a'));
				Q.push(after);
				visit[after.x][after.y][after.key] = true;
			}
			else
			{
				if (visit[after.x][after.y][after.key])
					continue;
				Q.push(after);
				visit[after.x][after.y][after.key] = true;
			}
		}
	}
	return -1;
}
int main()
{
	int i, j, n, m, a, b;
	Pow[0] = 0;
	for (i = 1; i <= 5; i++)
	{
		Pow[i] = Pow[i - 1] | (1 << (i - 1));
	}
	while (scanf("%d %d", &N, &M) != EOF && N + M)
	{
		for (i = 1; i <= N; i++)
		{
			scanf("%s", ar[i] + 1);
			for (j = 1; j <= M; j++)
			{
				if (ar[i][j] == '@')
				{
					bx = i;
					by = j;
				}
			}
		}
		scanf("%d", &K);
		for (i = 0; i < K; i++)
		{
			scanf("%d %d", &a, &b);
			ar[a][b] = 'a' + i;
		}
		printf("%d\n", bfs());
	}
	return 0;
}
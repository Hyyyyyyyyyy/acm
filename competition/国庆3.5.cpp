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
typedef unsigned long long ull;
const double eps = 1e-8;
const int inf = 1e9;
const int INF = 2147483647;
const ll MOD = 1e9 + 7;
const int maxn = 405;
int dir[4][2] = { 0,1, 1, 0, 0, -1, -1, 0 }; //上下左右
int visit[maxn][maxn][4];
int px[maxn], py[maxn];
struct Node
{
	int x;
	int y;
	int turn;
	int sta;
	bool operator < (const Node& p) const
	{
		return turn > p.turn;
	}
};
Node now, after, ar[maxn];
int bx, by, ex, ey, N, M;
char s[maxn][maxn];
bool check(int x, int y, int d, int pd)
{
	if (d == 0)
	{
		if(s[x][y] == '#' && s[x-1][y] == '#')
			return false;
		if((pd == 0 || pd == 3) && s[x][y] == '#' && s[x-1][y-1] == '#')
			return false;
		if((pd == 0 || pd == 1) && s[x-1][y] == '#' && s[x][y-1] == '#')
			return false;
		return true;
	}
	if(d == 1)
	{
		if(s[x][y] == '#' && s[x][y-1] == '#')
			return false;
		if((pd == 1 || pd == 2) && s[x][y] == '#' && s[x-1][y-1] == '#')
			return false;
		if((pd == 1 || pd == 0) && s[x-1][y] == '#' && s[x][y-1] == '#')
			return false;
		return true;
	}
	if(d == 2)
	{
		if(s[x-1][y-1] == '#' && s[x][y-1] == '#')
			return false;
		if((pd == 2 || pd == 3) && s[x-1][y] == '#' && s[x][y-1] == '#')
			return false;
		if((pd == 2 || pd == 1) && s[x][y] == '#' && s[x-1][y-1] == '#')
			return false;
		return true;
	}
	if(d == 3)
	{
		if(s[x-1][y] == '#' && s[x-1][y-1] == '#')
			return false;
		if((pd == 3 || pd == 2) && s[x-1][y] == '#' && s[x][y-1] == '#')
			return false;
		if((pd == 3 || pd == 0) && s[x-1][y-1] == '#' && s[x][y] == '#')
			return false;
		return true;
	}
}
int bfs()
{
	int i, j, k;
	priority_queue<Node>Q;
	memset(visit, -1, sizeof(visit));
	now.x = bx;
	now.y = by;
	now.turn = 0;
	for (i = 0; i < 4; i++)
	{
		now.sta = i;
		Q.push(now);
	}
	while (!Q.empty())
	{
		now = Q.top();
		Q.pop();
		//if (now.x == ex && now.y == ey)
		//	return now.turn;
		if(visit[now.x][now.y][now.sta] != -1)
			continue;
		visit[now.x][now.y][now.sta] = now.turn;
		for (i = 0; i < 4; i++)
		{
			after.x = now.x + dir[i][0];
			after.y = now.y + dir[i][1];
			after.turn = now.turn;
			after.sta = i;
			if(i != now.sta)
				after.turn++;
			if (after.x < 1 || after.x > N || after.y < 1 || after.y > M)
                continue;
            if(check(now.x, now.y, i, now.sta))
            {
                if (visit[after.x][after.y][after.sta] == -1)
                {
                    Q.push(after);
                    
                }
            }
		}
	}
	int res = -1;
	for (i = 0; i < 4; i++)
		if(visit[ex][ey][i] != -1)
		{
			if(res == -1 || res > visit[ex][ey][i])
				res = visit[ex][ey][i];
		}
	return res;
}
int main()
{
	int i, j, k, n, m, a, b, c, d, cnt, cntx, cnty;
	while (scanf("%d %d %d %d", &bx, &by, &ex, &ey) != EOF && (bx + by + ex + ey))
	{
		scanf("%d", &n);
		cnt = cntx = cnty = 0;
		for (i = 1; i <= n; i++)
		{
			scanf("%d %d %d %d", &a, &b, &c, &d);
			if (a > c)
				swap(a, c);
			if (b > d)
				swap(b, d);
			px[++cntx] = a;
			py[++cnty] = b;
			ar[++cnt].x = a;
			ar[cnt].y = b;
			px[++cntx] = c;
			py[++cnty] = d;
			ar[++cnt].x = c;
			ar[cnt].y = d;
		}
		px[++cntx] = bx;
		py[++cnty] = by;
		px[++cntx] = ex;
		py[++cnty] = ey;
		sort(px + 1, px + 1 + cntx);
		sort(py + 1, py + 1 + cnty);
		for (i = 1; i <= cnt; i++)
		{
			ar[i].x = lower_bound(px + 1, px + 1 + cnt, ar[i].x) - px;
			ar[i].y = lower_bound(py + 1, py + 1 + cnt, ar[i].y) - py;
		}
		bx = lower_bound(px + 1, px + 1 + cnt, bx) - px;
		by = lower_bound(py + 1, py + 1 + cnt, by) - py;
		ex = lower_bound(px + 1, px + 1 + cnt, ex) - px;
		ey = lower_bound(py + 1, py + 1 + cnt, ey) - py;
		memset(s, '.', sizeof(s));
		for (i = 1; i <= cnt; i += 2)
		{
			for (j = ar[i].x; j < ar[i + 1].x; j++)
			{
				for (k = ar[i].y; k < ar[i + 1].y; k++)
				{
                    s[j][k] = '#';
				}
			}
		}
		N = cntx;
		M = cnty;
		printf("%d\n", bfs());
	}
	return 0;
}
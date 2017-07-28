#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;
const int INF = 2147483640;
const double eps = 1e-7;
typedef long long ll;
const int maxn = 3000 + 10;
struct HC
{
	vector<int>G[maxn];
	int uN;
	int Mx[maxn], My[maxn];
	int dx[maxn], dy[maxn];
	int dist;
	bool visit[maxn];
	void init()
	{
		for (int i = 0; i <= uN; i++)
			G[i].clear();
	}
	void addedge(int u, int v)
	{
		G[u].push_back(v);
	}
	bool SearchP()
	{
		queue<int>Q;
		dist = INF;
		memset(dx, -1, sizeof(dx));
		memset(dy, -1, sizeof(dy));
		for (int i = 1; i <= uN; i++)
		{
			if (Mx[i] == -1)
			{
				Q.push(i);
				dx[i] = 0;
			}
		}
		while (!Q.empty())
		{
			int u = Q.front();
			Q.pop();
			if (dx[u] > dist)
				break;
			int sz = G[u].size();
			for (int i = 0; i < sz; i++)
			{
				int v = G[u][i];
				if (dy[v] == -1)
				{
					dy[v] = dx[u] + 1;
					if (My[v] == -1)
						dist = dy[v];
					else
					{
						dx[My[v]] = dy[v] + 1;
						Q.push(My[v]);
					}
				}
			}
		}
		return dist != INF;
	}
	bool dfs(int u)
	{
		int sz = G[u].size();
		for (int i = 0; i < sz; i++)
		{
			int v = G[u][i];
			if (!visit[v] && dy[v] == dx[u] + 1)
			{
				visit[v] = true;
				if (My[v] != -1 && dy[v] == dist)
					continue;
				if (My[v] == -1 || dfs(My[v]))
				{
					My[v] = u;
					Mx[u] = v;
					return true;
				}
			}
		}
		return false;
	}
	int MaxMatch()
	{
		int res = 0;
		memset(Mx, -1, sizeof(Mx));
		memset(My, -1, sizeof(My));
		while (SearchP())
		{
			memset(visit, false, sizeof(visit));
			for (int i = 1; i <= uN; i++)
			{
				if (Mx[i] == -1 && dfs(i))
					res++;
			}
		}
		return res;
	}
};
HC hop;
//要先给uN赋值
//初始化hop.init()
struct Node
{
	int x;
	int y;
	int speed;
};
Node P[maxn], U[maxn];
int T, N, M;
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			hop.init();
			scanf("%d %d", &T, &N);
			hop.uN = N;
			for (i = 1; i <= N; i++)
			{
				scanf("%d %d %d", &P[i].x, &P[i].y, &P[i].speed);
			}
			scanf("%d", &M);
			for (i = 1; i <= M; i++)
			{
				scanf("%d %d", &U[i].x, &U[i].y);
				for (j = 1; j <= N; j++)
				{
					int t = (P[j].x - U[i].x) * (P[j].x - U[i].x) + (P[j].y - U[i].y) * (P[j].y - U[i].y);
					if (T*P[j].speed*T*P[j].speed >= t)
					{
						hop.addedge(j, i);
					}
				}
			}
			printf("Scenario #%d:\n%d\n\n", m, hop.MaxMatch());
		}
	}
	return 0;
}
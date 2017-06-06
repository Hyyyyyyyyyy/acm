#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 60000 + 100;
struct Node
{
	int u;
	int v;
	int c;
	Node() {}
	Node(int a, int b, int d) : u(a), v(b), c(d) {}
	Node(const Node& p)
	{
		u = p.u;
		v = p.v;
		c = p.c;
	}
};
Node now;
queue<Node>q;
vector<Node>G_to[450], from_G[450];
int N, M, K;
int ar[450][450][30], S[110];
int dist[450][450], dist_temp[450][450][30];
int main()
{
	int i, j, k, u, n, m, a, b;
	char s[5];
	while (scanf("%d %d", &N, &M) != EOF)
	{
		memset(ar, 0, sizeof(ar));
		memset(dist, -1, sizeof(dist));
		memset(dist_temp, -1, sizeof(dist_temp));
		while (!q.empty())
			q.pop();
		for (i = 0; i <= 401; i++)
		{
			G_to[i].clear();
			from_G[i].clear();
		}
		for (i = 1; i <= N; i++)
		{
			dist[i][i] = 0;
			q.push(Node(i, i, 27));
		}
		for (i = 1; i <= M; i++)
		{
			scanf("%d %d %s", &a, &b, s);
			G_to[a].push_back(Node(a, b, s[0] - 'a'));
			from_G[b].push_back(Node(a, b, s[0] - 'a'));
			dist[a][b] = 1;
			q.push(Node(a, b, 27));
		}
		while (!q.empty())
		{
			int t;
			now = q.front();
			q.pop();
			if (now.c == 27)
			{
				t = dist[now.u][now.v];
			}
			else
			{
				t = dist_temp[now.u][now.v][now.c];
			}
			if (now.c  == 27)
			{
				for (i = 0; i < G_to[now.v].size(); i++)
				{
					int v = G_to[now.v][i].v;
					int c = G_to[now.v][i].c;
					if (dist_temp[now.u][v][c] == -1)
					{
						dist_temp[now.u][v][c] = t + 1;
						q.push(Node(now.u, v, c));
					}
				}
			}
			else
			{
				for (i = 0; i < from_G[now.u].size(); i++)
				{
					int u = from_G[now.u][i].u;
					int c = from_G[now.u][i].c;
					if (c == now.c)
					{
						if (dist[u][now.v] == -1)
						{
							dist[u][now.v] = t + 1;
							q.push(Node(u, now.v, 27));
						}
					}
				}
			}
		}
		scanf("%d", &K);
		scanf("%d", &S[1]);
		for (i = 2; i <= K; i++)
		{
			scanf("%d", &S[i]);
			printf("%d\n", dist[S[i - 1]][S[i]]);
		}
	}
	return 0;
}

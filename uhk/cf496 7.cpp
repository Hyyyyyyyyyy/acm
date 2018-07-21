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
const int inf = 1e8;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1000000007ll;
const int maxn = 300000 + 100;
const int maxm = 1000000 + 100;
struct Edge
{
	int v;
	int id;
	Edge() {}
	Edge(int a, int b) : v(a), id(b) {}
};
int d[maxn];
vector<Edge> G[maxn];
vector<int> red[maxn];
int N, M, K;
void bfs()
{
	int i, j;
	for (i = 1; i <= N; i++)
		d[i] = inf;
	d[1] = 0;
	queue<int>Q;
	int now, after;
	now = 1;
	Q.push(now);
	while (!Q.empty())
	{
		now = Q.front();
		Q.pop();
		for (i = 0; i < G[now].size(); i++)
		{
			if (d[G[now][i].v] > d[now] + 1)
			{
				d[G[now][i].v] = d[now] + 1;
				Q.push(G[now][i].v);
			}
		}
	}
}
char s[maxn];
vector<string> S;
void dfs(int u)
{
	if (S.size() >= K)
		return;
	if (u > N)
	{
		s[M] = 0;
		S.push_back(s);
		return;
	}
	int i, j;
	for (i = 0; i < red[u].size(); i++)
	{
		s[red[u][i]-1] = '1';
		dfs(u + 1);
		s[red[u][i]-1] = '0';
	}
}
int main()
{
	int i, j, k, a, b;
	while (scanf("%d %d %d", &N, &M, &K) != EOF)
	{
		S.clear();
		for (i = 0; i <= N; i++)
		{
			G[i].clear();
			red[i].clear();
		}
		for (i = 1; i <= M; i++)
		{
			scanf("%d %d", &a, &b);
			G[a].push_back(Edge(b, i));
			G[b].push_back(Edge(a, i));
		}
		bfs();
		for (i = 1; i <= N; i++)
		{
			for (j = 0; j < G[i].size(); j++)
			{
				if (d[i] == d[G[i][j].v] + 1)
				{
					red[i].push_back(G[i][j].id);
				}
			}
		}
		for (i = 0; i < M; i++)
			s[i] = '0';
		dfs(2);
		printf("%d\n", S.size());
		for (i = 0; i < S.size(); i++)
			cout << S[i] << endl;
	}
	return 0;
}

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll maxn1 = 10000;
const ll maxn2 = 10000;
vector<int>G[maxn1];
ll uN;
ll Mx[maxn1], My[maxn2];
ll dx[maxn1], dy[maxn2];
ll dist;
bool visit[maxn2];
void init()
{
	for (ll i = 0; i <= uN; i++)
		G[i].clear();
}
void addedge(ll u, ll v)
{
	G[u].push_back(v);
}
bool SearchP()
{
	queue<int>Q;
	dist = INF;
	memset(dx, -1, sizeof(dx));
	memset(dy, -1, sizeof(dy));
	for (ll i = 1; i <= uN; i++)
	{
		if (Mx[i] == -1)
		{
			Q.push(i);
			dx[i] = 0;
		}
	}
	while (!Q.empty())
	{
		ll u = Q.front();
		Q.pop();
		if (dx[u] > dist)
			break;
		ll sz = G[u].size();
		for (ll i = 0; i < sz; i++)
		{
			ll v = G[u][i];
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
bool dfs(ll u)
{
	ll sz = G[u].size();
	for (ll i = 0; i < sz; i++)
	{
		ll v = G[u][i];
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
ll MaxMatch()
{
	ll res = 0;
	memset(Mx, -1, sizeof(Mx));
	memset(My, -1, sizeof(My));
	while (SearchP())
	{
		memset(visit, false, sizeof(visit));
		for (ll i = 1; i <= uN; i++)
		{
			if (Mx[i] == -1 && dfs(i))
				res++;
		}
	}
	return res;
}

//要先给uN赋值
//初始化hop.init()
map<ll, ll>mp;
ll ar[maxn1];
int main()
{
	ll i, j, k, u, n, m, cnt, a[3000], b[3000], N;
	while (scanf("%lld", &N) != EOF)
	{
		uN = N;
		init();
		mp.clear();
		cnt = 0;
		for (i = 1; i <= N; i++)
		{
			scanf("%lld %lld", &a[i], &b[i]);
			if (mp.find(a[i] + b[i]) == mp.end())
			{
				mp[a[i] + b[i]] = ++cnt;
				ar[cnt] = a[i] + b[i];
			}
			addedge(i, mp[a[i] + b[i]]);
			if (mp.find(a[i] - b[i]) == mp.end())
			{
				mp[a[i] - b[i]] = ++cnt;
				ar[cnt] = a[i] - b[i];
			}
			addedge(i, mp[a[i] - b[i]]);
			if (mp.find(a[i] * b[i]) == mp.end())
			{
				mp[a[i] * b[i]] = ++cnt;
				ar[cnt] = a[i] * b[i];
			}
			addedge(i, mp[a[i] * b[i]]);
		}
		if (MaxMatch() == N)
		{
			for (i = 1; i <= N; i++)
			{
				ll t = ar[Mx[i]];
				if (a[i] + b[i] == t)
				{
					printf("%lld + %lld = %lld\n", a[i], b[i], t);
				}
				else if (a[i] - b[i] == t)
				{
					printf("%lld - %lld = %lld\n", a[i], b[i], t);
				}
				else
				{
					printf("%lld * %lld = %lld\n", a[i], b[i], t);
				}
			}
		}
		else
		{
			printf("impossible\n");
		}
	}
	return 0;
}
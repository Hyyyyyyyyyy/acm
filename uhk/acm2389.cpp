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

struct Point
{
    int x,y,s;
    void input1()
    {
        scanf("%d%d%d",&x,&y,&s);
    }
    void input2()
    {
        scanf("%d%d",&x,&y);
    }
};
int dis2(Point a,Point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
Point p1[maxn],p2[maxn];

int main()
{
    int T;
    int t;
    int iCase = 0;
    int n,m;
    scanf("%d",&T);
    while(T--)
    {
        iCase++;
        scanf("%d",&t);
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
            p1[i].input1();
        scanf("%d",&m);
        for(int i = 1;i <= m;i++)
            p2[i].input2();
        hop.init();
        hop.uN = n;
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= m;j++)
                if(dis2(p1[i],p2[j]) <= p1[i].s*p1[i].s*t*t)
                    hop.addedge(i, j);
        printf("Scenario #%d:\n",iCase);
        printf("%d\n\n",hop.MaxMatch());
    }
    return 0;
}
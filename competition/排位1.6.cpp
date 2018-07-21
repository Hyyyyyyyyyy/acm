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
const int maxn = 10000 + 100;
const int maxm = 1000000 + 100;
int N, M;
struct Node
{
	int x;
	bool operator < (const Node& p) const
	{
		return x > p.x;
	}
};
Node ar[maxn];
priority_queue<Node>Q;
bool comp(Node a,  Node b)
{
	return a.x > b.x;
}
int main()
{
	int i, j, k, cas, CAS, a;
	while (scanf("%d", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%d %d", &N, &M);
			while (!Q.empty())
				Q.pop();
			for (i = 1; i <= M; i++)
			{
				scanf("%d", &ar[i].x);
			}
			//sort(ar+1, ar+1+N, comp);
			for (i = 1; i <= N; i++)
			{
				ar[i].x += 45;
				Q.push(ar[i]);
			}
			for (i = N + 1; i <= M; i++)
			{
				Node now = Q.top();
				Q.pop();
				if (now.x > ar[i].x)
				{
					now.x += 45;
					Q.push(now);
				}
				else
				{
					ar[i].x += 45;
					Q.push(ar[i]);
				}
			}
			Node res;
			while (!Q.empty())
			{
				res = Q.top();
				Q.pop();
			}
			printf("%d\n", res.x);
		}
	}
	return 0;
}

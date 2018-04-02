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
const int maxn = 100000 + 100;
const int maxm = 1000000 + 100;
int N, M, cnt;
int res[maxn];
struct Node
{
	int l;
	int r;
	int x;
	int id;
};
Node ar[maxn];
Node ask[maxn];
bool comp(const Node& a, const Node& b)
{
	return a.x < b.x;
}
int Bit[maxn];
void Add(int x, int val)
{
	for (int i = x; i <= N; i += (i & -i))
		Bit[i] += val;
}
int Sum(int x)
{
	int res = 0;
	for (int i = x; i > 0; i -= (i & -i))
		res += Bit[i];
	return res;
}
int main()
{
	int i, j, k, n, m, a, b, c, CAS, cas;
	while (scanf("%d", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%d %d", &N, &M);
			for (n = 1; n <= N; n++)
			{
				scanf("%d", &ar[n].x);
				ar[n].id = n;
			}
			for (m = 1; m <= M; m++)
			{
				scanf("%d %d %d", &ask[m].l, &ask[m].r, &ask[m].x);
				ask[m].l++;
				ask[m].r++;
				ask[m].id = m;
			}
			sort(ar + 1, ar + 1 + N, comp);
			sort(ask + 1, ask + 1 + M, comp);
			memset(Bit, 0, sizeof(Bit));
			for (i = 1, j = 1; i <= M; i++)
			{
				while (j <= N && ask[i].x >= ar[j].x)
				{
					Add(ar[j].id, 1);
					j++;
				}
				res[ask[i].id] = Sum(ask[i].r) - Sum(ask[i].l - 1);
			}
			printf("Case %d:\n", cas);
			for (i = 1; i <= M; i++)
			{
				printf("%d\n", res[i]);
			}
		}
	}
	return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const int INF = 2147483640;
const int maxn = 100000 + 100;
struct Node
{
	int xue;
	int val;
	int x;
};
Node sa[maxn];
int ar[maxn];
bool comp(const Node& a, const Node& b)
{
	return a.x > b.x;
}
bool comp2(const int& a, const int& b)
{
	return a > b;
}
int N, M;
multiset<int>S;
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &N, &M);
			S.clear();
			for (i = 1; i <= N; i++)
			{
				scanf("%d", &ar[i]);
				S.insert(ar[i]);
			}
			sort(ar + 1, ar + 1 + N, comp2);
			for (i = 1; i <= M; i++)
			{
				scanf("%d %d", &sa[i].xue, &sa[i].val);
				sa[i].x = sa[i].val - sa[i].xue;
			}
			sort(sa + 1, sa + 1 + M, comp);
			int cnt = 1;
			ll res = 0;
			for(i = 1; i <= M; i++)
			{
				multiset<int>::iterator it;
				it = S.upper_bound(sa[i].xue);
				if (it == S.end())
				{
					continue;
				}
				res += ar[cnt++] + sa[i].val - sa[i].xue;
				S.erase(it);
			}
			printf("%lld\n", res);
		}
	}
	return 0;
}
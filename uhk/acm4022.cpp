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
const int inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 100000007ll;
const int maxn = 100000 + 100;
const int maxm = 1000000 + 100;
map<int, int>MPX, MPY;
multiset<int>SX[maxn], SY[maxn];
multiset<int>::iterator it;
int main()
{
	int i, j, n, m, a, N, M;
	int x, y;
	while (scanf("%d %d", &N, &M) != EOF && N + M)
	{
		MPX.clear();
		MPY.clear();
		for (i = 0; i <= N; i++)
			SX[i].clear(), SY[i].clear();
		int cntx = 1;
		int cnty = 1;
		int doudoux = 0;
		int doudouy = 0;
		for (i = 1; i <= N; i++)
		{
			scanf("%d %d", &x, &y);
			if (MPX.find(x) == MPX.end())
				MPX[x] = cntx++;
			if (MPY.find(y) == MPY.end())
				MPY[y] = cnty++;
			SX[MPX[x]].insert(MPY[y]);
			SY[MPY[y]].insert(MPX[x]);
		}
		for (i = 1; i <= M; i++)
		{
			scanf("%d %d", &a, &x);
			if (a == 0)
			{
				if (MPX.find(x) == MPX.end())
					printf("0\n");
				else
					printf("%d\n", SX[MPX[x]].size());
				for (it = SX[MPX[x]].begin(); it != SX[MPX[x]].end(); it++)
				{
					SY[*it].erase(MPX[x]);
				}
				SX[MPX[x]].clear();
			}
			else
			{
				if (MPY.find(x) == MPY.end())
					printf("0\n");
				else
					printf("%d\n", SY[MPY[x]].size());
				for (it = SY[MPY[x]].begin(); it != SY[MPY[x]].end(); it++)
				{
					SX[*it].erase(MPY[x]);
				}
				SY[MPY[x]].clear();
			}
		}
		printf("\n");
	}
	return 0;
}
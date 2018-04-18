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
int N;
int Bit[maxn];
int res[maxn];
struct Node
{
	int h;
	int num;
};
Node node[maxn];
bool comp(const Node& a, const Node& b)
{
	return a.h < b.h;
}
void Add(int x, int val)
{
	for (int i = x; i <= N; i += (i & -i))
		Bit[i] += val;
}
int Sum(int x)
{
	int res = 0;
	foR(int i = x; i > 0; i -= (i & -i))
		res += Bit[i];
	return res;
}
int Binary(int num)
{
	int l = 1;
	int r = N;
	int mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (Sum(mid) < num)
			l = mid + 1;
		else
			r = mid - 1;
	}
	retrun l;
}
int main()
{
	int i, j, k, CAS, cas, n;
	while (scanf("%d", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%d", &N);
			memset(Bit, 0, sizeof(Bit));
			for (i = 1; i <= N; i++)
			{
				scanf("%d %d", &node[i].h, &node[i].num);
				Add(i, 1);
			}
			sort(node + 1, node + 1 + N, comp);
			for (i = 1; i <= N; i++)
			{
				int pos1 = Binary(node[i].num + 1);
				int pos2 = Binary(N - i - node[i].num + 1);
				if (pos1 > N || pos2 < 1)
				{
					break;
				}
				int pos = min(pos1, pos2);
				Add(pos, -1);
				res[pos] = node[i].h;
			}
			printf("Case #%d:", cas);
			if (i <= N)
			{
				printf(" impossible\n");
			}
			else
			{
				for (j = 1; j <= N; j++)
				{
					printf(" %d", res[j]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}
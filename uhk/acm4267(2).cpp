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
const int maxn = 50000 + 100;
const int maxm = 1000000 + 100;
int ar[maxn];
int Bit[11][11][maxn];
int N;
void Add(int x, int k, int mod, int val)
{
	int i;
	for (i = x; i <= N; i += (i & -i))
	{
		Bit[k][mod][i] += val;
	}
}
int Sum(int x, int k, int mod)
{
	int i;
	int res = 0;
	for (i = x; i > 0; i -= (i & -i))
	{
		res += Bit[k][mod][i];
	}
	return res;
}
int main()
{
	int i, j, k, n, Q, q, a, b, c, op;
	while (scanf("%d", &N) != EOF)
	{
		memset(Bit, 0, sizeof(Bit));
		for (n = 1; n <= N; n++)
		{
			scanf("%d", &ar[n]);
		}
		scanf("%d", &Q);
		for (q = 1; q <= Q; q++)
		{
			scanf("%d", &op);
			if (op == 2)
			{
				scanf("%d", &a);
				int res = ar[a];
				for (i = 1; i <= 10; i++)
				{
					res += Sum(a, i, a%i);
				}
				printf("%d\n", res);
			}
			else
			{
				scanf("%d %d %d %d", &a, &b, &k, &c);
				Add(a, k, a%k, c);
				Add(b + 1, k, a%k, -c);
			}
		}
	}
	return 0;
}
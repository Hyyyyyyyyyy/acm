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
const int maxn = 100 + 100;
const int maxm = 1000000 + 100;
int Bit[maxn][maxn][maxn];
int N, M;
void Add(int x, int y, int z, int val)
{
	for (int i = x; i <= N; i += (i & -i))
	{
		for (int j = y; j <= N; j += (j & -j))
		{
			for (int k = z; k <= N; k += (k & -k))
			{
				Bit[i][j][k] += val;
			}
		}
	}
}
int Sum(int x, int y, int z)
{
    int res = 0;
    for (int i = x; i > 0; i -= (i & -i))
	{
		for (int j = y; j > 0; j -= (j & -j))
		{
			for (int k = z; k > 0; k -= (k & -k))
			{
				res += Bit[i][j][k];
			}
		}
	}
    return res % 2;
}
int main()
{
	int i, j, k, n, m, a, b, c, op, aa, bb, cc;
	while (scanf("%d %d", &N, &M) != EOF)
	{
		memset(Bit, 0, sizeof(Bit));
		for (m = 1; m <= M; m++)
		{
			scanf("%d", &op);
			if (op == 1)
			{
				scanf("%d %d %d", &a, &b, &c);
				Add(a, b, c, 1);
				scanf("%d %d %d", &aa, &bb, &cc);
				Add(aa+1, b, c, 1);
				Add(a, bb+1, c, 1);
				Add(a, b, cc+1, 1);
				Add(aa+1, bb+1, c, 1);
                Add(aa+1, b, cc+1, 1);
                Add(a, bb+1, cc+1, 1);
                Add(aa+1, bb+1, cc+1, 1);
			}
			else
			{
				scanf("%d %d %d", &a, &b, &c);
				printf("%d\n", Sum(a, b, c));
			}
		}
	}
	return 0;
}
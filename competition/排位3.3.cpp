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
const int maxn = 1000000 + 100;
const int maxm = 1000000 + 100;
int N;
int ar[maxn];
stack<int>S;
int gong[maxn];
int ying[maxn];
int sum[maxn];
void Add(int x, int val)
{
	int i;
	for (i = x; i <= N; i += (i & -i))
	{
		sum[i] += val;
	}
}
int Sum(int x)
{
	int i;
	int res = 0;
	for (i = x; i > 0; i -= (i & -i))
	{
		res += sum[i];
	}
	return res;
}

int main()
{
	int i, j, k, cas, CAS;
	while (scanf("%d", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%d", &N);
			while (!S.empty())
				S.pop();
			memset(gong, 0, sizeof(gong));
			memset(ying, 0, sizeof(ying));
			memset(sum, 0, sizeof(sum));
			for (i = 1; i <= N; i++)
			{
				scanf("%d", &ar[i]);
			}
			for (i = 1; i <= N; i++)
			{
				int x = Sum(ar[i]);
				if (x > 1)
				{
					gong[ar[i]] = 1;
					while (!S.empty() && ar[i] <= S.top())
						S.pop();
					S.push(ar[i]);
				}
				else if (x == 1)
				{
					gong[ar[i]] = 1;
					while (!S.empty() && ar[i] <= S.top())
						S.pop();
					if (!S.empty())
						ying[S.top()]++;
					S.push(ar[i]);
				}
				else
				{
					while (!S.empty() && ar[i] <= S.top())
						S.pop();
					S.push(ar[i]);
					gong[ar[i]] = 0;
				}
				Add(ar[i], 1);
			}
			int res = 0;
			int resi;
			for (i = 1; i <= N; i++)
			{
				int t = N - gong[ar[i]] - ying[ar[i]];
				if (res < t)
				{
					res = t;
					resi = ar[i];
				}
				else if (res == t && resi > ar[i])
				{
					resi = ar[i];
				}
			}
			printf("%d\n", resi);
		}
	}
	return 0;
}
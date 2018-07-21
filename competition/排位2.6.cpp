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
const int inf = 1e8;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1000000007ll;
const int maxn = 100 + 100;
const int maxm = 1000000 + 100;
int ar[maxn];
bool comp(int a, int b)
{
	return a > b;
}
int erfen(int L, int R, int val)
{
	int mid;
	while (L <= R)
	{
		mid = (L + R) / 2;
		if (ar[mid] >= val)
			L = mid + 1;
		else
			R = mid - 1;
	}
	return R;
}
int main()
{
	int i, j, k, cas, CAS, t, N, M;
	while (scanf("%d", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%d %d", &N, &M);
			int T = N / 3;
			for (i = 1; i <= N; i++)
			{
				scanf("%d", &ar[i]);
			}
			sort(ar + 1, ar + 1 + N, comp);
			int res = 0;
			for (t = 1; t <= T; t++)
			{
				if (ar[t] == -inf)
					continue;
				int Min = t;
				int pos;
				for (i = N - 1; i > t; i--)
				{
					if (ar[i] == -inf)
						continue;
					pos = erfen(i + 1, N, M - 3 * ar[t] - 2 * ar[i]);
					if (pos > N || pos <= i)
						continue;
					else
					{
						ar[t] = ar[i] = ar[pos] = -inf;
						break;
					}
				}
				if (i > t)
					res++;
			}
			printf("%d\n", res);
		}
	}
	return 0;
}
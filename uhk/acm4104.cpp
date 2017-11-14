#include <cstdio>
#include <cstring>
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
#define foR for
#define for9 for
typedef long long ll;
typedef unsigned long long ull;
const int inf = (1ll << 31) - 1;
const ll INF = (1ull << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1e9;
const int maxn = 10000 + 100;
const int maxm = 1000000 + 100;
int ar[maxn];
int main()
{
	int i, j, k, n, m;
	while (scanf("%d", &n) != EOF)
	{
		int res = 0;
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &ar[m]);
			res += ar[m];
		}
		
		printf("%d\n", res+1);
	}
	return 0;
}
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
const int maxn = 1000 + 100;
const int maxm = 1000000 + 100;
int N;
int ar[maxn];
int main()
{
	int i, j, k, a, b, res;
	while (scanf("%d", &N) != EOF)
	{
		res = 0;
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &ar[i]);
			if (ar[i] == 1)
				res++;
		}
		printf("%d\n", res);
		for (i = 1; i <= N; i++)
		{
			if (i != 1 && ar[i] == 1)
				printf("%d ", ar[i - 1]);
		}
		printf("%d", ar[N]);
		printf("\n");
	}
	return 0;
}
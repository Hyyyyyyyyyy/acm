#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cctype>
#include <set>
using namespace std;
const int INF = 1e10;
const double eps = 1e-8;
typedef long long ll;
const int maxn = 10010;
int ar[maxn * 2];
int N;
int main()
{
	int i, j, k, n, m;
	scanf("%d", &n);
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &N);
			for (i = 1; i <= 2*N; i++)
			{
				scanf("%d", &ar[i]);
			}
			printf("Case %d: %.2f\n", m, 1.0*N / 2.0);
		}
	}
	return 0;
}
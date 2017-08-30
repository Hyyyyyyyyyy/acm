#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <vector>
#include <cctype>
#include <set>
using namespace std;
const int INF = 2147483640;
const double eps = 1e-7;
typedef long long ll;
const int maxn = 100000 + 10;
struct Node
{
	ll x;
	int id;
} ar[maxn];
bool comp(Node& a, Node& b)
{
	return a.x > b.x;
}
ll B[maxn];
int main()
{
	int i, j, k, u, n, m, N;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &N);
			for (i = 1; i <= N; i++)
			{
				scanf("%lld", &ar[i].x);
				ar[i].id = i;
			}
			sort(ar + 1, ar + 1 + N, comp);
			for (i = 2; i <= N; i++)
			{
				for (j = 1; j <= N; j++)
				{
					if (ar[j].id % i != 0)
					{
						if (i != 2)
							putchar(' ');
						printf("%lld", ar[j].x);
						break;
					}
				}
			}
			putchar('\n');
		}
	}
	return 0;
}
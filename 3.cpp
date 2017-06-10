#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
using namespace std;
const int maxn = 110;
typedef long long ll;
int ar[maxn];
int sa[maxn];
int C[maxn];
int main()
{
	int i, j, k, u, n, m, a, b;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &k);
			for (i = 1; i <= k; i++)
			{
				scanf("%d", &ar[i]);
			}
			for (i = 1; i <= k; i++)
			{
				scanf("%d", &sa[i]);
			}
			sort(ar + 1, ar + 1 + k);
			sort(sa + 1, sa + 1 + k);
			int cnt = 1;
			for (i = 1; i <= k; i++)
			{
				C[cnt++] = ar[i] + sa[k - i + 1];
			}
			sort(C + 1, C + cnt);
			printf("%d\n", C[cnt - 1]);
		}
	}
	return 0;
}
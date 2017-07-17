#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const int INF = 2147483640;
const int maxn = 500;
char s[maxn], ss[maxn];
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%d", &n) != EOF)
	{
		scanf("%s", s + 1);
		int L = strlen(s + 1);
		strcpy(ss + 1, s + n + 1);
		sort(s + 1, s + 1 + n);
		sort(ss + 1, ss + 1 + n);
		int doudou = 1;
		for (i = 1; i <= n; i++)
		{
				if (s[i] >= ss[i])
				{
					doudou = 0;
					break;
				}
		}
		doudou = 1;
		for (i = 1; i <= n; i++)
		{
				if (s[i] <= ss[i])
				{
					doudou = 0;
					break;
				}
		}
		if (doudou)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
const int maxn = 10000 + 10;
int ar[maxn], sa[maxn];
int main()
{
	int i, j, k, u, n, m, a, b, c;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &ar[i]);
			sa[i] = ar[i];
		}
		for (i = 1; i <= m; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			sort(ar + a, ar + b + 1);
			if (ar[c] == sa[c])
				printf("Yes\n");
			else
				printf("No\n");
			for (j = a; j <= b; j++)
				ar[j] = sa[j];
		}
	}
	return 0;
}
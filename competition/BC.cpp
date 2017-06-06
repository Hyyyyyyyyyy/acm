#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std;
typedef __int64 ll;
ll ar[100010];
map<ll, ll>q;
int main()
{
	int i, j, k, u, n, m, flag, a, b;
	ll f;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &a);
			flag = 1;
			q.clear();
			for (b = 1; b <= a; b++)
			{
				scanf("%I64d", &ar[b]);
				if (q[ar[b]])
				{
					flag++;
					q.clear();
				}
				q[ar[b]] = 1;
			}
			printf("%d\n", flag);
		}
	}
	return 0;
}

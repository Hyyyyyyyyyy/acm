#include <cstdio>
#include <cstring>
#include <map>
#include <string>
using namespace std;
map<string, int>q;
int main()
{
	int i, j, k, u, n, m, a, ar[10010];
	char s[40];
	while (scanf("%d", &n) != EOF)
	{
		q.clear();
		memset(ar, 0, sizeof(ar));
		for (i = 1; i <= n; i++)
		{
			scanf("%s", s);
			if (strcmp(s, "memory") == 0)
				q[s] = 0;
			else
				q[s] = i;
		}
		scanf("%d", &k);
		for (u = 1; u <= k; u++)
		{
			for (i = 1; i <= n; i++)
			{
				scanf("%d%s", &a, s);
				ar[q[s]] += a;
			}
			int num = 0;
			for (j = 0; j <= n; j++)
				if (ar[j] > ar[0])
					num++;
			printf("%d\n", num+1);
		}
	}
	return 0;
}
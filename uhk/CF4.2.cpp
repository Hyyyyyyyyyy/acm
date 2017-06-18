#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 200000 + 100;
const int INF = 1000000000;
int ar[maxn], s[maxn];
int main()
{
	int i, j, k, u, n, m, a, b, q, max, min, cnt;
	while (scanf("%d %d %d", &n, &k, &q) != EOF)
	{
		memset(ar, 0, sizeof(ar));
		memset(s, 0, sizeof(s));
		max = -INF;
		min = INF;
		for (i = 1; i <= n; i++)
		{
			scanf("%d %d", &a, &b);
			ar[a]++;
			ar[b + 1]--;
			if (max < b)
				max = b;
			if (min > a)
				min = a;
		}
		//printf("%d ", ar[min]);
		s[1] = (ar[1] >= k) ? 1:0;
		for (i = 1; i <= maxn; i++)
		{
			ar[i] += ar[i - 1];
			if (ar[i] >= k)
				s[i] = s[i - 1] + 1;
			else
				s[i] = s[i - 1];
			//printf("%d ", ar[i]);
		}
		cnt = 0;
		for (i = 1; i <= q; i++)
		{
			scanf("%d %d", &a, &b);
			printf("%d\n", s[b] - s[a-1]);
		}
	}
	return 0;
}
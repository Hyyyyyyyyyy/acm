#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf = 2147483647;
const ll INF = 9223372036854775807;
const double eps = 1e-8;
const int maxn = 100000 + 100;
int ar[maxn];
int main()
{
	int i, j, k, n, m, N, K;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &N, &K);
			int sum = 0;
			memset(ar, 0, sizeof(ar));
			for (i = 1; i <= N; i++)
			{
				scanf("%d", &ar[i]);
				sum += ar[i];
			}
			printf("Case #%d: ", m);
			if (sum % K)
			{
				printf("-1\n");
				continue;
			}
			else
			{
				int T = sum / K;
				int op = 0;
				for (i = 1; i <= N; i++)
				{
					if (ar[i] < T)
					{
						ar[i + 1] += ar[i];
						op++;
					}
					else if (ar[i] > T)
					{
						if (ar[i] - T < T)
						{
							op += 2;
							ar[i + 1] += ar[i] - T;
						}
						else
						{
							ar[i] = ar[i] - T;
							op++;
							i--;
						}
					}
                }
                if(ar[N+1] > 0)
                    op += ar[N+1] / T - 1;
				printf("%d\n", op);
			}
		}
	}
	return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 1000000 + 10;
typedef long long ll;
int N;
int main()
{
	int i, j, k, u, n, m;
	ll a;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &N);
			ll res = 0;
			for (i = 1; i <= N; i++)
			{
				scanf("%lld", &a);
				if (a % 8 == 0)
				{
					res ^= (a - 1);
					continue;
				}
				if ((a + 1) % 8 == 0)
				{
					res ^= (a + 1);
					continue;
				}
				res ^= a;
			}
			if (res == 0)
			{
				printf("Second player wins.\n");
			}
			else
			{
				printf("First player wins.\n");
			}
		}
	}
	return 0;
}


//先打sg表找到规律   除了8的倍数和8的倍数-1的sg值是互换的，其他sg值均等于自身；
// #include <cstdio>
// #include <cstring>
// #include <algorithm>
// #include <cmath>
// using namespace std;
// const int maxn = 1000000 + 10;
// int sa[maxn], grundy[maxn];
// void getgrundy()
// {
// 	int i, j, k;
// 	int visit[maxn];
// 	grundy[0] = 0;
// 	for (i = 1; i <= 1000; i++)
// 	{
// 		memset(visit, 0, sizeof(visit));
// 		for (j = 1; j <= i; j++)
// 		{
// 			visit[grundy[i - j]] = 1;
// 		}
// 		for (j = 1; j <= i - 2; j++)
// 		{
// 			for (k = 1; k <= i - j - 1; k++)
// 			{
// 				visit[grundy[j] ^ grundy[k] ^ grundy[i - j - k]] = 1;
// 			}
// 		}
// 		int res = 0;
// 		while (visit[res])
// 			res++;
// 		grundy[i] = res;
// 	}
// }
// int main()
// {
// 	int i, j, k, u, n, m;
// 	freopen("OUT.txt", "w", stdout);
// 	getgrundy();
// 	for (i = 0; i <= 1000; i++)
// 		printf("grundy[%d] = %d\n", i, grundy[i]);
// 	return 0;
// }
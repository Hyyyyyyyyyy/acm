#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
int N;
typedef long long ll;
set<ll>S;
int main()
{
	ll i, j, k, a;
	while (scanf("%d", &N) != EOF)
	{
		if (N == 0)
		{
			printf("Yes\n");
		}
		else
		{
			ll res = 0;
			S.clear();
			for (i = 1; i <= N; i++)
			{
				scanf("%lld", &a);
				if (S.count(a))
					continue;
				S.insert(a);
				ll cnt = 0;
				ll t = a;
				while (a)
				{
					if (a & 1)
						cnt++;
					a >>= 1;
				}
				if (cnt % 2 == 1)
				{
					res ^= 2 * t;
				}
				else
					res ^= 2 * t + 1;
			}
			if (res == 0)
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}

//打表   i表示第i个位置是正面朝上，  设ar[i]表示第i个位置正面朝上，则该游戏可以分为sg[ar[1]]^sg[ar[2]]^sg[ar[3]]....
// #include <cstdio>
// #include <algorithm>
// #include <cstring>
// using namespace std;
// const int maxn = 1000 + 10;
// int grundy[maxn];
// int main()
// {
// 	int i, j, k, u, n, m;
// 	int visit[maxn];
// 	grundy[0] = 1;
// 	for (i = 1; i <= 100; i++)
// 	{
// 		memset(visit, 0, sizeof(visit));
// 		visit[0] = 1;
// 		for (j = 0; j < i; j++)
// 			visit[grundy[j]] = 1;
// 		for (j = 0; j < i; j++)
// 		{
// 			for (k = 0; k < i; k++)
// 			{
// 				if (k == j)
// 					continue;
// 				visit[grundy[j] ^ grundy[k]] = 1;
// 			}
// 		}
// 		int res = 0;
// 		while (visit[res])
// 			res++;
// 		grundy[i] = res;
// 	}
// 	for (i = 0; i <= 100; i++)
// 		printf("grundy[%d] = %d\n", i, grundy[i]);
// 	return 0;
// }
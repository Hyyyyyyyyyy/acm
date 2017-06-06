#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
ll Floor[2002000], num[2002000];
int main()
{
	int i, j, k, u, n, m, a, b, c;
	ll N;
	Floor[0] = num[0] = 0;
	for (i = 1; i < 2002000; i++)
	{
		num[i] = num[i - 1] + i;
		Floor[i] = Floor[i - 1] + num[i];
	}
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%lld", &N);
			ll l = 1;
			ll r = 2002000;
			ll mid = (l + r) / 2;
			while (r > l)
			{
				if (Floor[mid] < N)
					l = mid + 1;
				else if (Floor[mid] > N)
					r = mid - 1;
				else
					break;
				mid = (l + r) / 2;
			}
			if (Floor[mid] < N)
				mid++;
			ll F = mid;
			l = 1;
			r = F;
			mid = (l + r) / 2;
			while (r > l)
			{
				if (num[mid] < N - Floor[F - 1])
					l = mid + 1;
				else if (num[mid] > N - Floor[F - 1])
					r = mid - 1;
				else
					break;
				mid = (l + r) / 2;
			}
			ll row = mid;
			if (num[row] == N - Floor[F - 1])
				printf("%lld %lld %lld\n", F, row, row);
			else
			{
				if (num[row] < N - Floor[F - 1])
					row++;
				printf("%lld %lld %lld\n", F, row, N - Floor[F - 1] - num[row - 1]);
			}
		}
	}
	return 0;
}

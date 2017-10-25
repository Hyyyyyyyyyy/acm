//数组依次找
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
const int INF = 1e9 + 1;
const int maxn = 500000 + 100;
int A[maxn], R[maxn], L[maxn];
int N, K, lcnt, rcnt;
int main()
{
	int i, j, k, u, n, m;
	scanf("%d", &n);
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &N, &K);
			for (i = 0; i < N; i++)
			{
				scanf("%d", &A[i]);
			}
			ll res = 0;
			for (i = 0; i < N; i++)
			{
				int lcnt = 1;
				int rcnt = 1;
				for (j = i + 1; j < N && rcnt <= K; j++)
				{
					if (A[j] > A[i])
						R[rcnt++] = j - i;
				}
				if (j >= N)
					R[rcnt] = N - i;
				for (j = i - 1; j >= 0 && lcnt <= K; j--)
				{
					if (A[j] > A[i])
						L[lcnt++] = i - j;
				}
				if (j <= 0)
					L[lcnt] = i + 1;
				for (j = 0; j < lcnt; j++)
				{
					if (K - j - 1 >= rcnt)
						continue;
					int lnum = L[j + 1] - L[j];
					int rnum = R[K - j] - R[K - j - 1];
					res += (ll)A[i] * (lnum) * rnum;
				}
			}
			printf("%lld\n", res);
		}
	}
	return 0;
}





//链表法，必须是1~n每个出现一次
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
const int INF = 1e9 + 1;
const int maxn = 500000 + 100;
int A[maxn], R[maxn], L[maxn], pos[maxn], pre[maxn], aft[maxn];
int N, K, lcnt, rcnt;
void del(int n)
{
	if (n == 1)
	{
		pre[aft[n]] = pre[n];
	}
	else if (n == N)
	{
		aft[pre[n]] = aft[n];
	}
	else
	{
		pre[aft[n]] = pre[n];
		aft[pre[n]] = aft[n];
	}
	pre[n] = aft[n] = 0;
}
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &N, &K);
			for (i = 1; i <= N; i++)
			{
				scanf("%d", &A[i]);
				pos[A[i]] = i;
				pre[i] = i - 1;
				aft[i] = i + 1;
			}
			ll res = 0;
			for (i = 1; i <= N; i++)
			{
				int p = pos[i];
				int lcnt = 0;
				int rcnt = 0;
				for (j = p; j > 0 && lcnt <= K; j = pre[j])
					L[lcnt++] = j;
				for (j = p; j <= N && rcnt <= K; j = aft[j])
					R[rcnt++] = j;
				L[lcnt] = 0;
				R[rcnt] = N + 1;
				for (j = 0; j < lcnt && j < K; j++)
				{
					if (K - j - 1 >= rcnt)
						continue;
					int lnum = L[j + 1] - L[j];
					int rnum = R[K - j] - R[K - j - 1];
					res += (ll)i * (-lnum) * rnum;
				}
				del(p);
			}
			printf("%lld\n", res);
		}
	}
	return 0;
}
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
const int maxn = 100000 + 100;
const int maxm = 100000 + 100;
const ll MOD = 1e9 + 7;
vector<int>GA, GB;
int A[maxn], B[maxn];
bool visit[maxn];
void solve(int *ar, int n, vector<int>&G)
{
	int i, j, k, u;
	memset(visit, false, sizeof(visit));
	for (i = 0; i < n; i++)
	{
		if (!visit[i])
		{
			int now = ar[i];
			int len = 0;
			while (!visit[now])
			{
				++len;
				visit[now] = true;
				now = ar[now];
			}
			G.push_back(len);
		}
	}
}
int main()
{
	int i, j, k, u, n, m, cas = 1, N, M;
	while (scanf("%d %d", &N, &M) != EOF)
	{
		GA.clear();
		GB.clear();
		for (i = 0; i < N; i++)
		{
			scanf("%d", &A[i]);
		}
		for (i = 0; i < M; i++)
		{
			scanf("%d", &B[i]);
		}
		solve(A, N, GA);
		solve(B, M, GB);
		int LA = GA.size();
		int LB = GB.size();
		ll res = 1;
		for (i = 0; i < LA; i++)
		{
			ll t = 0;
			for (j = 0; j < LB; j++)
			{
				if (GA[i] % GB[j] == 0)
				{
					t = (t + (ll)GB[j]) % MOD;
				}
			}
			res = (res * t) % MOD;
		}
		printf("Case #%d: %lld\n", cas++, res);
	}
	return 0;
}
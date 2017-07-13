//记忆化搜索求grundy值
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <cctype>
#include <set>
using namespace std;
const int maxn = 1e3 + 10;
const int INF = 1e9;
typedef long long ll;
char ar[maxn];
int sa[maxn];
int grundy[maxn], visit[maxn];
int N, cnt;
int getgrundy(int x)
{
	if (visit[x])
		return grundy[x];
	visit[x] = 1;
	int i, j;
	set<int>S;
	for (i = 1; i <= x-1; i++)
	{
		S.insert(getgrundy(i - 1) ^ getgrundy(x - i - 1));
	}
	int res = 0;
	while (S.count(res))
		res++;
	grundy[x] = res;
	return res;
}
int main()
{
	int i, j, k, u, n, m;
	memset(visit, 0, sizeof(visit));
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &N);
			int flag = 0;
			cnt = 0;
			scanf("%s", ar);
			for (i = 0; i < N; i++)
			{
				if (ar[i] == '1')
				{
					flag++;
				}
				else
				{
					if (flag)
					{
						sa[++cnt] = flag;
					}
					flag = 0;
				}
			}
			if (flag)
				sa[++cnt] = flag;
			if (N <= 1)
				printf("Bob\n");
			else
			{
				int res = 0;
				for (i = 1; i <= cnt; i++)
				{
					res ^= getgrundy(sa[i]);
				}
				if (res == 0)
					printf("Bob\n");
				else
					printf("Alice\n");
			}
		}
	}
	return 0;
}




//dp求grundy表
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <cctype>
#include <set>
using namespace std;
const int maxn = 1e3 + 10;
const int INF = 1e9;
typedef long long ll;
char ar[maxn];
int sa[maxn];
int grundy[maxn];
int N, cnt;
void getgrundy()
{
	int i, j;
	grundy[0] = 0;
	int maxr = 15;
	for (i = 2; i <= maxr; i++)
	{
		set<int>S;
		for (j = 1; j <= i - 1; j++)
		{
			S.insert(grundy[j - 1] ^ grundy[i - j - 1]);
		}
		int res = 0;
		while (S.count(res))
			res++;
		grundy[i] = res;
	}
}
int main()
{
	int i, j, k, u, n, m;
	getgrundy();
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &N);
			int flag = 0;
			cnt = 0;
			scanf("%s", ar);
			for (i = 0; i < N; i++)
			{
				if (ar[i] == '1')
				{
					flag++;
				}
				else
				{
					if (flag)
					{
						sa[++cnt] = flag;
					}
					flag = 0;
				}
			}
			if(flag)
				sa[++cnt] = flag;
			if (N <= 1)
				printf("Bob\n");
			else
			{
				int res = 0;
				for (i = 1; i <= cnt; i++)
				{
					res ^= grundy[sa[i]];
				}
				if (res == 0)
					printf("Bob\n");
				else
					printf("Alice\n");
			}
		}
	}
	return 0;
}
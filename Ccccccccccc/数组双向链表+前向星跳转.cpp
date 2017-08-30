#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const int INF = 100000000;
const ll MOD = 1e18;
const int maxn = 2000000 + 100;
int ar[maxn];
int l[maxn], r[maxn], val[maxn], Next[maxn], head[maxn];
int cnt;
int main()
{
	int i, j, k, u, n, m, N, L, R, a, b;
	while (scanf("%d %d %d", &N, &L, &R) != EOF)
	{
		memset(head, -1, sizeof(head));
		cnt = 1;
		l[1] = 0;
		r[1] = 0;
		val[1] = 0;
		head[0] = 1;
		Next[0] = -1;
		for (i = 1; i <= N; i++)
		{
			scanf("%d %d", &a, &b);
			for (j = head[a]; j != -1; j = Next[j])
			{
				l[++cnt] = j;
				r[cnt] = r[j];
				l[r[j]] = cnt;
				r[j] = cnt;
				val[cnt] = b;
				if (head[b] == -1)
				{
					Next[cnt] = -1;
					head[b] = cnt;
				}
				else
				{
					Next[cnt] = head[b];
					head[b] = cnt;
				}
			}
		}
		int tot = -1;
		for (i = 1; r[i] != 0; i = r[i])
		{
			ar[++tot] = val[i];
			//printf("%d ", val[i]);
		}
		ar[++tot] = val[i];
		int l = L;
		l %= (tot+1);
		int count;
		for (i = l, count = 1; count <= R - L; count++)
		{
			if (i == tot + 1)
			{
				i = 0;
			}
			if (count == 1)
				printf("%d", ar[i]);
			else
				printf(" %d", ar[i]);
			i++;
		}
		putchar('\n');
	}
	return 0;
}

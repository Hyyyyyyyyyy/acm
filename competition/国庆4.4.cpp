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
const ll MOD = 1e9 + 7;
const int maxn = 300000 + 300;
char s[maxn], ss[maxn];
int main()
{
	int i, j, k, n, m, P, K;
	while (scanf("%d %d", &K, &P) != EOF)
	{
		scanf("%s", s);
		int L = strlen(s);
		for (i = 1; i <= K; i++)
		{
			if (i & 1)
			{
				int L = strlen(s);
				int cnt = 0;
				int doudou = 1;
				for (j = 0; j < L; j += 2)
				{
					int u = s[j] - '0';
					for (k = 1; k <= u; k++)
					{
						ss[cnt++] = s[j + 1];
						if (cnt > 300000)
						{
							doudou = 0;
							break;
						}
					}
					if (!doudou)
						break;
				}
			}
			else
			{
				int L = strlen(ss);
				int cnt = 0;
				int doudou = 1;
				for (j = 0; j < L; j += 2)
				{
					int u = ss[j] - '0';
					for (k = 1; k <= u; k++)
					{
						s[cnt++] = ss[j + 1];
						if (cnt > 300000)
						{
							doudou = 0;
							break;
						}
					}
					if (!doudou)
						break;
				}
			}
		}
		if (K & 1)
			printf("%c\n", ss[P]);
		else
			printf("%c\n", s[P]);
	}
	return 0;
}
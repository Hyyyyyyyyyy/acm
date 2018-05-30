#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cctype>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define foR for
#define for9 for
#define retunr return
#define reutrn return
#define reutnr return
const ll inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1e7 + 7;
const ll maxn = 100000 + 100;
const ll maxm = 1000000 + 100;
char S[maxn];
int N;
int F(int n, int f)
{
	if (f == 0 && S[n] == '0')
		return 1;
	if (f == 1 && S[n] == '0')
		return 2;
	if (f == 0 && S[n] == '1')
		return 3;
	if (f == 1 && S[n] == '1')
		return 4;
}
int main()
{
	int i, j, k, CAS, cas;
	while (scanf("%d", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%d", &N);
			scanf("%s", S);
			if (N % 4 == 1 || N <= 2 || N % 4 == 2)
				printf("-1\n");
			else
			{
				if (N % 2 == 1)
				{
					int L = strlen(S);
					for (i = 0; i < L; i++)
					{
						if (i < 3)
						{
							if (i % 3 == 0 || i % 3 == 1)
								printf("%d", F(i, 0));
							else
								printf("%d", F(i, 1));
						}
						else
						{
							if ((i - 3) % 4 == 0 || (i - 3) % 4 == 3)
							{
								printf("%d", F(i, 0));
							}
							else
								printf("%d", F(i, 1));
						}
					}
				}
				else
				{
					int L = strlen(S);
					for (i = 0; i < L; i++)
					{
						if (i < N / 2 && i % 2 == 0)
							printf("%d", F(i, 0));
						if (i < N / 2 && i % 2 == 1)
							printf("%d", F(i, 1));
						if (i >= N / 2 && i % 2 == 0)
							printf("%d", F(i, 1));
						if(i >= N / 2 && i % 2 == 1)
							printf("%d", F(i, 0));
					}
				}
				putchar('\n');
			}
		}
	}
	return 0;
}
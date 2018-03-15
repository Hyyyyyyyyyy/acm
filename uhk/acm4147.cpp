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
const int inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 100000007ll;
const int maxn = 50000 + 100;
const int maxm = 100000 + 100;
char S[maxn];
int main()
{
	int i, j, N, b, D, F, f, A, B, C;
	while (scanf("%d %d %d %d %d", &N, &b, &D, &f, &F) != EOF)
	{
		A = b + D + f;
		B = 2 * b + 2 * D + F;
		C = 3 * b + 3 * D + 2 * F;
		int res = inf;
		int t;
		for (i = 1; i <= N; i++)
		{
			scanf("%s", &S);
			t = 0;
			for (j = 0; S[j] != '\0'; j++)
			{
				if (S[j] == 'A')
				{
					t += A;
				}
				else if (S[j] == 'B')
				{
					t += B;
				}
				else
				{
					t += C;
				}
			}
			if (res > t)
				res = t;
		}
		printf("%d\n", res);
	}
	return 0;
}
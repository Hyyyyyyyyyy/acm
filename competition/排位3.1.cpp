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
#define retrun return
const int inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1000000007ll;
const int maxn = 10000 + 100;
const int maxm = 1000000 + 100;
char A[maxn];
char B[maxn];
int vis1[30];
int vis2[30];
int main()
{
	int i, j, k, cas, CAS;
	while (scanf("%s %s", A, B) != EOF)
	{
		int L1 = strlen(A);
		int L2 = strlen(B);
		memset(vis1, 0, sizeof(vis1));
		memset(vis2, 0, sizeof(vis2));
		for (i = 0; i < L2; i++)
		{
			vis2[B[i] - 'A']++;
		}
		for (i = 0; i < L1; i++)
		{
			vis1[A[i] - 'A']++;
		}
		for (i = 0; i < 26; i++)
		{
			if (vis1[i] >= vis2[i])
			{
				vis1[i] -= vis2[i];
				vis2[i] = 0;
			}
			else
			{
				vis2[i] -= vis1[i];
				vis1[i] = 0;
			}
		}
		int res = 0;
		for (i = 0; i < 26; i++)
		{
			while (vis2[i] > 0)
			{
				for (j = i - 1; j >= 0; j--)
				{
					if (vis1[j])
					{
						if (vis1[j] >= vis2[i])
						{
							res += vis2[i] * (i - j);
							vis1[j] -= vis2[i];
							vis2[i] = 0;
							break;
						}
						else
						{
							res += vis1[j] * (i - j);
							vis2[i] -= vis1[j];
							vis1[j] = 0;
						}
					}
				}
				if (vis2[i] > 0)
				{
					for (j = 25; j > i; j--)
					{
						if (vis1[j])
						{
							if (vis1[j] >= vis2[i])
							{
								res += vis2[i] * (26 - j + i);
								vis1[j] -= vis2[i];
								vis2[i] = 0;
								break;
							}
							else
							{
								res += vis1[j] * (26 - j + i);
								vis2[i] -= vis1[j];
								vis1[j] = 0;
							}
						}
					}
				}
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
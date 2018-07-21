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
const int maxn = 300000 + 100;
const int maxm = 1000000 + 100;
char s[maxn];
char t[maxn];
int main()
{
	int i, j, k;
	while (scanf("%s %s", s, t) != EOF)
	{
		int Ls = strlen(s);
		int Lt = strlen(t);
		reverse(s, s + Ls);
		reverse(t, t + Lt);
		for (i = 0; i < min(Ls, Lt); i++)
		{
			if (s[i] != t[i])
				break;
		}
		printf("%d\n", Lt + Ls - 2 * i);
	}
	return 0;
}
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
const int maxn = 100 + 100;
const int maxm = 1000000 + 100;
char s1[maxn];
char s2[maxn];
char s[maxn];
int main()
{
	int i, j, N, n;
	while(scanf("%d", &N) != EOF)
	{
		for(n = 1; n <= N; n++)
		{
			scanf("%s %s", s1, s2);
			strcat(s2, s1);
			int L = strlen(s2);
			L += strlen(s1);
			toupper(s2[0]);
			s2[L] = 0;
			puts(s2);
		}
	}
	return 0;
}
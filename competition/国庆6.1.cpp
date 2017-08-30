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
typedef unsigned long long ll;
const double eps = 1e-8;
const int INF = 100000000;
const ll MOD = 1e18;
const int maxn = 1000 + 100;
int ar[maxn];
int sa[maxn];
char s[maxn];
int main()
{
	int i, j, k, u, n, m;
	memset(ar, 0, sizeof(ar));
	memset(sa, 0, sizeof(sa));
	ar['a' - 'a'] = 2;
	ar['k' - 'a'] = 1;
	ar['n' - 'a'] = 1;
	ar['g' - 'a'] = 1;
	ar['r' - 'a'] = 1;
	ar['o' - 'a'] = 2;
	sa['k' - 'a'] = 1;
	sa['i' - 'a'] = 3;
	sa['w' - 'a'] = 1;
	sa['b' - 'a'] = 1;
	sa['r' - 'a'] = 1;
	sa['d' - 'a'] = 1;
	while (scanf("%s", &s) != EOF)
	{
		int L = strlen(s);
		int res1 = 0;
		int res2 = 0;
		for (i = 0; i < L; i++)
		{
			if (isupper(s[i]))
				s[i] += 32;
			res1 += ar[s[i] - 'a'];
			res2 += sa[s[i] - 'a'];
		}
		if (res1 > res2)
			printf("Kangaroos\n");
		else if (res1 < res2)
			printf("Kiwis\n");
		else
			printf("Feud continues\n");
	}
	return 0;
}
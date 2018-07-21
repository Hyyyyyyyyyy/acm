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
bool check(int i)
{

	if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
		return true;
	return false;
}
int main()
{
	int i, j, k;
	while (scanf("%s", s) != EOF)
	{
		int L = strlen(s);
		int doudou = 1;
		for (i = 0; i < L; i++)
		{
			if (!check(i) && s[i] != 'n')
			{
				if (i + 1 >= L || !check(i+1))
				{
					doudou = 0;
					break;
				}
			}

		}
		if (doudou)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
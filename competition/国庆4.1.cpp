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
const int maxn = 1100 + 100;
ll Pow[11];
char s[11];
int main()
{
	ll i, j, k, u, n, m, N;
	Pow[0] = 0;
	Pow[1] = 26;
	for (i = 2; i <= 9; i++)
	{
		Pow[i] = Pow[i - 1] * 26;
	}
	while(scanf("%lld", &N) != EOF)
	{
		N++;
		if (N == 1)
		{
			printf("A\n");
		}
		else
		{
			ll t = N;
			i = 0;
			while (t > 0)
			{
				++i;
				t -= Pow[i] * i;
			}
			t += Pow[i] * i;
			ll tt = t / i - 1;
			ll ty = t % i;
			memset(s, 'A', sizeof(s));
			for (j = 1; j <= i && tt; j++)
			{
				s[j] += tt % 26;
				tt /= 26;
			}
			//for (j = 1; j < tt; j++)
			//{
			//	s[1]++;
			//	k = 1;
			//	while (s[k] > 'Z')
			//	{
			//		s[k] = 'A';
			//		k++;
			//		s[k]++;
			//	}
			//}
			if (ty == 0)
			{
				printf("%c\n", s[1]);
			}
			else
			{
				s[1]++;
				k = 1;
				while (s[k] > 'Z')
				{
					s[k] = 'A';
					k++;
					s[k]++;
				}
				printf("%c\n", s[i-ty+1]);
			}
		}
	}
	return 0;
}
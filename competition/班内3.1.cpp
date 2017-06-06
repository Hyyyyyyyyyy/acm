#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;
typedef unsigned long long ll;
char ss[51];
char *sss;
int N;
void er(ll n)
{
	int cnt = 1;
	while (n)
	{
		if (n % 2)
		{
			ss[cnt++] = '1';
		}
		else
		{
			ss[cnt++] = '0';
		}
		n /= 2;
	}
	N = cnt-1;
}
ll E()
{
	int i;
	ll res = 0, a = 1;
	for (i = 1; i <= 32; i++)
	{
		if (ss[i] == '1')
		{
			res += a;
		}
		a *= 2;
	}
	return res;
}
int main()
{
	int i, j, k, u, n, m, len;
	ll a;
	while (scanf("%lld", &a) != EOF)
	{
		memset(ss, '0', sizeof(ss));
		er(a);
			for (i = 1; i <= 16; i++)
			{
				char t = ss[i];
				//ss[i] = ss[N - 16 + i];
				//ss[N - 16 + i] = t;
				ss[i] = ss[16 + i];
				ss[16 + i] = t;
			}
		printf("%lld\n", E());

	}
	return 0;
}

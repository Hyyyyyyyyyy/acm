#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 10000;
int prime[maxn + 1];
void getprime()
{
	int i, j;
	memset(prime, 0, sizeof(prime));
	for (i = 2; i <= maxn; i++)
	{
		if (!prime[i])
			prime[++prime[0]] = i;
		for (j = 1; j <= prime[0] && i*prime[j] <= maxn; j++)
		{
			prime[prime[j] * i] = 1;
			if (i % prime[j] == 0)
				break;
		}
	}
}

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef unsigned long long ll;
const double eps = 1e-8;
const int INF = 1e9+1;
const int maxn = 100000 + 100;
const double MOD = 998244353.0;
double MUL(double a, long long b)
{
	double res = 1.0;
	while (b)
	{
		if (b & 1)
		{
			res = (res * a) % MOD;
		}
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}
int N, M;
int ar[maxn];
int main()
{
    int i, j, k, u, n, m;
    while(scanf("%lld", &N) != EOF)
    {
        printf("%.0f\n", 1.0 / sqrt(5.0) * (MUL((1.0+sqrt(5.0)) / 2.0, N) - MUL((1.0-sqrt(5.0)) / 2.0, N)))
    }
    return 0;
}
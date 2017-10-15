#include<iostream>  
#include<sstream>  
#include<fstream>  
#include<vector>  
#include<list>  
#include<deque>  
#include<queue>  
#include<stack>  
#include<map>  
#include<set>  
#include<bitset>  
#include<algorithm>  
#include<cstdio>  
#include<cstdlib>  
#include<cstring>  
#include<cctype>  
#include<cmath>  
#include<ctime>  
#include<iomanip>  
using namespace std;
const double eps = 1e-8;
typedef unsigned long long ull;
typedef long long ll;
const int maxn = 1100 + 100;
long long MUL(long long a, long long b, long long MOD)
{
	long long res = 1;
	while (b)
	{
		if (b & 1)
		{
			res = (res * a);
		}
		a = (a * a);
		b >>= 1;
	}
	return res;
}
int main()
{
    ll i, j, k, n, m, N;
    while(scanf("%lld", &N) != EOF && N)
    {
        ll res = 0;
        for(i = 1; i <= N; i++)
        {
            scanf("%lld", &k);
            res += k*k;
        }
        printf("%lld\n", res);
    }
    return 0;
}
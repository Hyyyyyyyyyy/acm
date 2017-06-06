// 同源数； 如果x和y的质因子集合完全相同，那么我们就说他们是同源的；
// 				令 d=gcd(x,y)，将x和y不断与d进行约分。  
// 				若此时x=y=1，那么说明其质因子集合相同。 
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
using namespace std;
typedef long long ll;
const int MAX = 100000000;
const int MIN = -100000000;
ll gcd(ll a, ll b);
int main()
{
	ll i, j, k, u, n, m, p, q, a, b, temp, doudou;
	while (scanf("%lld %lld", &n, &m) != EOF)
	{
		doudou = 0;
		q = gcd(n, m);
		temp = q;
		while (temp != 1)
		{
			temp = gcd(n, temp);
			n /= temp;
			if (n == 1)
			{
				doudou = 1;
				break;
			}
		}
		if (!doudou)
		{
			printf("No\n");
			continue;
		}
		temp = q;
		while (temp != 1)
		{
			temp = gcd(m, temp);
			m /= temp;
			if (temp == 1)
			{
				if (m != 1)
					doudou = 0;
				break;
			}
		}
		if (doudou)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
ll gcd(ll a, ll b)
{
	ll temp;
	while (b)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

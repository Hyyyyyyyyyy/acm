#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
const int maxn = 110;
ll A[10], M[10];
ll key[maxn], ar[60];
char s[10];
ll S;
map<int, char>q;
ll gcd(ll x, ll y)
{
	ll t;
	while (y)
	{
		t = x%y;
		x = y;
		y = t;
	}
	return  x;
}

ll Extend_Euclid(ll a, ll b, ll&x, ll& y)
{
	if (b == 0)
	{
		x = 1, y = 0;
		return a;
	}
	ll d = Extend_Euclid(b, a%b, x, y);
	ll t = x;
	x = y;
	y = t - a / b*y;
	return d;
}

//a在模n乘法下的逆元，没有则返回-1
ll inv(ll a, ll n)
{
	ll x, y;
	ll t = Extend_Euclid(a, n, x, y);
	if (t != 1)
		return -1;
	return (x%n + n) % n;
}

//将两个方程合并为一个
bool merge(ll a1, ll m1, ll a2, ll m2, ll& a3, ll& m3)
{
	ll d = gcd(m1, m2);
	ll c = a2 - a1;
	if (c%d)
		return false;
	c = (c%m2 + m2) % m2;
	c /= d;
	m1 /= d;
	m2 /= d;
	c *= inv(m1, m2);
	c %= m2;
	c *= m1*d;
	c += a1;
	m3 = m1*m2*d;
	a3 = (c%m3 + m3) % m3;
	return true;
}

//求模线性方程组x=ai(mod ni),ni可以不互质
//最小结果（特解）是(a1%n1 + n1) % n1，通解是(a1%n1 + n1) % n1 + K*S，K是倍数
ll China_Reminder2(int len)
{
	ll a1 = A[1], m1 = M[1];
	ll a2, m2;
	for (int i = 2; i <= len; i++)
	{
		ll aa, mm;
		a2 = A[i], m2 = M[i];
		if (!merge(a1, m1, a2, m2, aa, mm))
			return -1;
		a1 = aa;
		m1 = mm;
	}
	S = m1;            //S 或者 n1 就是 通解的差
	return (a1 % m1 + m1) % m1;
}
int main()
{
	int i, j, k, u, n, m;
	q[1] = 'A';
	q[2] = 'B';
	q[3] = 'C';
	q[4] = 'D';
	q[5] = 'E';
	q[6] = 'F';
	q[7] = 'G';
	q[8] = 'H';
	q[9] = 'I';
	q[10] = 'J';
	q[11] = 'K';
	q[12] = 'L';
	q[13] = 'M';
	q[14] = 'N';
	q[15] = 'O';
	q[16] = 'P';
	q[17] = 'Q';
	q[18] = 'R';
	q[19] = 'S';
	q[20] = 'T';
	q[21] = 'U';
	q[22] = 'V';
	q[23] = 'W';
	q[24] = 'X';
	q[25] = 'Y';
	q[26] = 'Z';
	q[27] = ' ';
	scanf("%d", &n);
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &k);
			for (i = 1; i <= 4; i++)
			{
				scanf("%lld", &M[i]);
			}
			for (u = 1; u <= k; u++)
			{
				scanf("%lld", &ar[u]);
			}
			for (i = 1; i <= k; i++)
			{
				for (j = 4; j >= 1; j--)
				{
					A[j] = (ar[i] % 100);
					ar[i] /= 100;
				}
				ll res = China_Reminder2(4);
				s[4] = '\0';
				for (j = 3; j >= 1; j--)
				{
					s[j] = q[res % 100];
					res /= 100;
				}
				if (i == k)
				{
					int v = 3;
					while (s[v] == ' ')
						s[v--] = '\0';
				}
				printf("%s", s + 1);
			}
			putchar('\n');
		}
	}
	return 0;
}
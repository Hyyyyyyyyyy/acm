#include<cstdio>
const int N = 1000010, P = 1000000007;
int i, fac[N], inv[N], Case, n, m, x, y, z, ans, p[N];
inline int C(int n, int m) 
{ 
	return n<m ? 0 : 1LL * fac[n] * inv[m] % P*inv[n - m] % P; 
}
int main()
{
	for (fac[0] = fac[1] = 1, i = 2; i<N; i++)
		fac[i] = 1LL * fac[i - 1] * i%P;
	for (inv[0] = inv[1] = 1, i = 2; i<N; i++)
		inv[i] = 1LL * (P - inv[P%i])*(P / i) % P;
	for (i = 2; i<N; i++)
		inv[i] = 1LL * inv[i - 1] * inv[i] % P;
	for (p[0] = 1, p[1] = inv[2], i = 2; i<N; i++)
		p[i] = 1LL * p[i - 1] * p[1] % P;
	scanf("%d", &Case);
	while (Case--)
	{
		scanf("%d%d", &n, &m);
		ans = 0;
		for (i = 0; i <= n; i++) 
		{
			x = i;//1
			y = i - m;//-1
			z = n - x - y;//0
			if (y<0 || y>n || z<0 || z>n)
				continue;
			ans = (1LL * C(n, x)*C(n - x, y) % P*p[(x + y) * 2 + z] + ans) % P;
		}
		printf("%d\n", ans);
	}
}
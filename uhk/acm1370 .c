#include <cstdio>
#include <iostream>
using namespace std;
long long int CAL(long long m[], long long int a[]);
void exOJLD(long long int a, long long int b, long long int & x, long long int & y);

int main()
{
	long long int i, j, k, m[5], a[5], n, d, res, cas, L, J;
	m[1] = 23;
	m[2] = 28;
	m[3] = 33;
	cin >> n;
		cin.get();
	cas = 1;
	while (cin >> a[1] >> a[2] >> a[3] >> d)
	{
		if (a[1] ==-1 && a[2] == -1 && a[3] == -1 && d == -1)
			break;
		res = CAL(m, a);
		if (res > d)
			cout << "Case " << cas++ << ": the next triple peak occurs in " << res - d << " days." << endl;
		else
			cout << "Case " << cas++ << ": the next triple peak occurs in " << res + 21252 - d << " days." << endl;
	}
	return 0;
}
long long int CAL(long long m[], long long int a[])
{
	long long int res = 0, M = 1, N[5], Mi, i, L, J;
	for (i = 1; i <= 3; i++)
		M *= m[i];
	for (i = 1; i <= 3; i++)
	{
		Mi = M / m[i];
		exOJLD(Mi, m[i], L, J);
		N[i] = Mi * L % 21252;
		res += N[i] * a[i];
		res = res % 21252;
	}
	if (res < 0)
		res += M;
	return res;
}
void exOJLD(long long int a, long long int b, long long int & x, long long int & y)
{
	int temp;
	if (b == 0)
	{
		x = 1;
		y = 0;
		return;
	}
	exOJLD(b, a%b, x, y);
	temp = x;
	x = y;
	y = temp - (a / b) * y;
}

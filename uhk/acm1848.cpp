#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 1000 + 100;
int Fibo[maxn];
int E[maxn];
int temp[maxn];
int main()
{
	int i, j, k, u, n, m, a, b, c;
	Fibo[1] = 1;
	Fibo[2] = 2;
	for (i = 3; i <= 16; i++)
	{
		Fibo[i] = Fibo[i - 1] + Fibo[i - 2];
	}
	E[0] = 0;
	E[1] = 1;
	E[2] = 2;
	E[3] = 3;
	for (i = 4; i <= 1000; i++)
	{
		memset(temp, 0, sizeof(temp));
		for (j = 1; Fibo[j] <= i; j++)
		{
			temp[E[i - Fibo[j]]] = 1;
		}
		for (j = 0; j <= i; j++)
		{
			if (!temp[j])
			{
				E[i] = j;
				break;
			}
		}
	}
	while (scanf("%d %d %d", &a, &b, &c) != EOF && a + b + c)
	{
		if ((E[a] ^ E[b] ^ E[c]) == 0)
			printf("Nacci\n");
		else
			printf("Fibo\n");
	}
	return 0;
}
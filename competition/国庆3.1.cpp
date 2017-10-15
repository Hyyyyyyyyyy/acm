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
typedef long long ll;
const int maxn = 1100 + 100;
vector<int>v[maxn];
struct polynomial
{
	int coe[maxn];
	int len;
	polynomial()
	{
		memset(coe, 0, sizeof(coe));
		len = 1;
	}
	void output()
	{
		printf("(");
		for (int i = len - 1; i >= 0; i--)
		{
			if (coe[i] == 0) continue;
			if (i == 0)
			{
				if (coe[i] > 0) printf("+");
				printf("%d", coe[i]);
				continue;
			}
			if (coe[i] > 0 && i != len - 1) printf("+");
			if (coe[i] == -1) printf("-");
			if (abs(coe[i]) != 1) printf("%d", coe[i]);
			if (i > 1)
				printf("x^%d", i);
			else printf("x");
		}
		printf(")");
		return;
	}
	polynomial operator / (const polynomial pol);
};

polynomial polynomial :: operator / (const polynomial pol)
{
	polynomial ret;
	ret.len = len - pol.len + 1;
	for (int i = len - 1; i >= pol.len - 1; i--)
	{
		int tim = coe[i] / pol.coe[pol.len - 1];
		if (tim != 0)
		{
			for (int j = 0; j < pol.len; j++)
				coe[i - j] -= tim*pol.coe[pol.len - 1 - j];
			ret.coe[i - pol.len + 1] = tim;
		}
	}
	return ret;
}

polynomial p[maxn];

bool cmp(int i, int j)//return p[i] < p[j]  
{
	if (p[i].len != p[j].len) return p[i].len < p[j].len;
	for (int k = p[i].len - 1; k >= 0; k--)
		if (p[i].coe[k] != p[j].coe[k])
		{
			if (abs(p[i].coe[k]) == abs(p[j].coe[k]))
				return p[i].coe[k] < 0;
			else return abs(p[i].coe[k]) < abs(p[j].coe[k]);
		}
	return false;
}

int main()
{
	int i, j, k, n, m, N, M;
	v[1].clear();
	p[1].coe[0] = -1;
	p[1].coe[1] = 1;
	p[1].len = 2;
	v[1].push_back(1);
	for (i = 2; i <= 1100; i++)
	{
		v[i].clear();
		p[i].coe[0] = -1;
		p[i].coe[i] = 1;
		p[i].len = i + 1;
		p[i] = p[i] / p[1];
		v[i].push_back(1);
		for (j = 2; j * j <= i; j++)
		{
			if (i % j == 0)
			{
				p[i] = p[i] / p[j];
				v[i].push_back(j);
				if (j*j != i)
				{
					p[i] = p[i] / p[i / j];
					v[i].push_back(i / j);
				}
			}
		}
		v[i].push_back(i);
	}
	while (scanf("%d", &N) != EOF && N)
	{
		if (N == 1)
		{
			printf("x-1\n");
			continue;
		}
		sort(v[N].begin(), v[N].end(), cmp);
		for (i = 0; i < v[N].size(); i++)
		{
			p[v[N][i]].output();
		}
		putchar('\n');
	}
	return 0;
}
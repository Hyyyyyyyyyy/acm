#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cctype>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define foR for
#define for9 for
#define retunr return
#define reutrn return
#define reutnr return
#define retrun return
const int inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1000000007ll;
const int maxn = 1000000 + 100;
const int maxm = 1000000 + 100;
list<pair<int, int> > lis;
list<pair<int, int> >::iterator it1, it2;
int N, num;
void bishi(int a, int b)
{

	if (a < b)
	{
		(it1->first)--;
		(it2->first)++;
		it1++;
		it1++;
	}
	else if (a > b)
	{
		(it1->first)++;
		(it2->first)--;
		it1++;
		it1++;
	}
	else
	{
		it2 = lis.erase(it2);
		it1 = lis.erase(it1);
//		it1 = lis.erase(it1);
	}
}
int main()
{
	int i, j, k, CAS, cas, a;
	while (scanf("%d", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%d", &N);
			lis.clear();
			for (i = 1; i <= N; i++)
			{
				scanf("%d", &a);
				lis.push_back(make_pair(a, i));
			}
			num = N;
			while (num)
			{
				it1 = lis.begin();
				while (it1 != lis.end())
				{
					it2 = it1;
					it2++;
					if (it2 == lis.end())
						break;
					bishi(it1->first, it2->first);
					if (lis.size() <= 2)
						break;
				}
				if (lis.size() <= 2)
					break;
				it1 = lis.begin();
				it1++;
				while (it1 != lis.end())
				{
					it2 = it1;
					it2++;
					if (it2 == lis.end())
						break;
					bishi(it1->first, it2->first);
					if (lis.size() <= 2)
						break;
				}
				if (lis.size() <= 2)
					break;
				int Min = inf;
				it1 = lis.begin();
				while (it1 != lis.end())
				{
					if (Min > it1->first)
					{
						Min = it1->first;
						it2 = it1;
					}
					it1++;
				}
				lis.erase(it2);
				if (lis.size() <= 2)
					break;
				num--;
			}
			if (lis.size() == 2)
			{
				for (it1 = lis.begin(); it1 != lis.end(); it1++)
					printf("%d ", it1->second);
				printf("\n");
			}
			else
			{
				printf("impossible\n");
			}
		}
	}
	return 0;
}
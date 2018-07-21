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
const int maxn = 100000 + 100;
const int maxm = 1000000 + 100;
ll N;
ll ar[maxn];
// ll vis[maxn];
// priority_queue<ll>Q;
bool comp(ll &a, ll &b)
{
    return a > b;
}
int main()
{
	ll i, j, k, cas, CAS;
	while (scanf("%lld", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%lld", &N);
			ll sum = 0;
			for (i = 1; i <= N; i++)
			{
				scanf("%lld", &ar[i]);
				sum += ar[i];
			}
			if (sum % 2 == 1)
			{
				printf("N\n");
				continue;
			}
			ll doudou = 1;
            sort(ar+1, ar+1+N, comp);
            for(i = 1, j = N; i < j; i++)
            {
                if(ar[i] == 0)
                    break;
                while(ar[i] && j > i)
                {
                    if(ar[j])
                    {
                        if(ar[j] <= ar[i])
                        {
                            ar[i] -= ar[j];
                            ar[j] = 0;
                            j--;
                        }
                        else
                        {
                            ar[j] -= ar[i];
                            ar[i] = 0;
                        }
                    }
                }
                if(ar[i])
                {
                    doudou = 0;
                    break;
                }
            }
			if (sum == 0)
				printf("Y\n");
			else
				printf("N\n");
		}
	}
	return 0;
}
int cmp(const void *a, const void *b)

{

     return(*(int *)b-*(int *)a);

}

 

bool havel(int p[],int len)

{

	qsort(p,len,sizeof(p[0]),cmp);

	if(p[0]==0)

		return true;

	for (int i=1;i<=p[0];i++)

	{

		p[i]-=1;

		if(p[i]<0)

			return false;

	}

	p[0]=0;

	if(!havel(p,len))

		return false;

	return true;

}
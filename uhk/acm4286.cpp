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
const int inf = 1000000000;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1000000007ll;
const int maxn = 500000 + 100;
const int maxm = 5000 + 100;
int N, M;
int ar[maxn];
char s[20];
deque<int> Q;
stack<int> L;
stack<int> R;
int main()
{
	int i, j, k, CAS, cas, a, begin, end;
	while (scanf("%d", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			while (!Q.empty())
				Q.pop_front();
			while (!L.empty())
				L.pop();
			while (!R.empty())
				R.pop();
			scanf("%d", &N);
			for (i = 1; i <= N; i++)
			{
				scanf("%d", &ar[i]);
			}
			scanf("%d %d", &begin, &end);
			for (i = 1; i < begin; i++)
				L.push(ar[i]);
			for (i = begin; i <= end; i++)
				Q.push_back(ar[i]);
			for (i = N; i >= end + 1; i--)
				R.push(ar[i]);
			scanf("%d", &M);
			int doudou = 0;
			for (i = 1; i <= M; i++)
			{
				scanf("%s", s);
				if (strcmp(s, "Reverse") == 0)
				{
					doudou ^= 1;
				}
				else if (strcmp(s, "MoveLeft") == 0)
				{
					scanf("%s", s);
					if (s[0] == 'L')
					{
						if (!doudou)
						{
							Q.push_front(L.top());
							L.pop();
						}
						else
						{
							Q.push_back(L.top());
							L.pop();
						}
					}
					else
					{
						if (!doudou)
						{
							R.push(Q.back());
							Q.pop_back();
						}
						else
						{
							R.push(Q.front());
							Q.pop_front();
						}
					}
				}
				else if (strcmp(s, "MoveRight") == 0)
				{
					scanf("%s", s);
					if (s[0] == 'L')
					{
						if (!doudou)
						{
							L.push(Q.front());
							Q.pop_front();
						}
						else
						{
							L.push(Q.back());
							Q.pop_back();
						}
					}
					else
					{
						if (!doudou)
						{
							Q.push_back(R.top());
							R.pop();
						}
						else
						{
							Q.push_front(R.top());
							R.pop();
						}
					}
				}
				else if (strcmp(s, "Insert") == 0)
				{
					scanf("%s", s);
					scanf("%d", &a);
					if (s[0] == 'L')
					{
						if (!doudou)
						{
							Q.push_front(a);
						}
						else
						{
							Q.push_back(a);
						}
					}
					else
					{
						if (!doudou)
						{
							Q.push_back(a);
						}
						else
						{
							Q.push_front(a);
						}
					}
				}
				else if (strcmp(s, "Delete") == 0)
				{
					scanf("%s", s);
					if (s[0] == 'L')
					{
						if (!doudou)
						{
							Q.pop_front();
						}
						else
						{
							Q.pop_back();
						}
					}
					else
					{
						if (!doudou)
						{
							Q.pop_back();
						}
						else
						{
							Q.pop_front();
						}
					}
				}
			}
			int l = L.size();
			for (i = L.size(); i >= 1; i--)
			{
				ar[i] = L.top();
				L.pop();
			}
			int flag = 0;
			for (i = 1; i <= l; i++)
			{
				if (flag)
					printf(" ");
				flag = 1;
				printf("%d", ar[i]);
			}
			while (!Q.empty())
			{
				if (flag)
					printf(" ");
				flag = 1;
				if (!doudou)
				{
					printf("%d", Q.front());
					Q.pop_front();
				}
				else
				{
					printf("%d", Q.back());
					Q.pop_back();
				}
			}
			while (!R.empty())
			{
				if (flag)
					printf(" ");
				flag = 1;
				printf("%d", R.top());
				R.pop();
			}
			printf("\n");
		}
	}
	return 0;
}
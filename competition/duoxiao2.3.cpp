#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <queue>  
#include <cmath>  
#include <algorithm>  
#include <deque>  
using namespace std;
typedef long long ll;
const int INF = 2147483640;
const int maxn = 100000+100;
const ll MOD = 1e9+7;
struct Node
{
    int l;
	int r;
	int mid;
	int max;
    int visit;
};
Node sa[250000*4];
void build(int root, int begin, int end);
void update(int root, int index, int val);
void pushup(int root);
void pushdown(int root);
int query(int root, int b, int e);
int main()
{
    ll i, j, k, u, n, m, N;
    while(scanf("%lld", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%lld", &A[m]);
            A[m] -= m;
        }
        for(i = 1; i <= n; i++)
        {
            scanf("%lld", &B[i]);
        }
        N = n*2;
        build(1, 1, N);
        sort(B+1, B+1+n);
        int pos;
        for(i = 1; i <= n; i++)
        {
            pos = = query(1, B[i], n+i-1);
            A[n+i] = A[pos] - (n+i);
            update(1, n+i, A[n+i]);
        }
        ll res = 0;
        for(i = n+1; i <= N; i++)
        {
            res = (res + A[i]+i) % MOD;
        }
        printf("%lld\n", res);
    }
    return 0;
}
void build(int root, int begin, int end)
{
    sa[root].l = begin;
	sa[root].r = end;
	sa[root].mid = (begin + end) / 2;
	sa[root].visit = -1;
	if (begin == end)
	{
        if(begin <= n)
		    sa[root].max = A[begin];
        else
            sa[root].max = -INF;
	}
	else
	{
		build(root * 2, sa[root].l, sa[root].mid);
		build(root * 2 + 1, sa[root].mid + 1, sa[root].r);
		pushup(root);
	}
}
void pushup(int root)
{
	sa[root].max = max(sa[root*2].max, sa[root*2+1].max);
}
void update(int root, int index, int val)
{
	if (sa[root].l > e || sa[root].r < b)
		return;
	if (sa[root].l == sa[root].r && sa[root].l == index)
	{
		A[index] = val;
        pushup(root);
		return;
	}
	update(root * 2, index, val);
	update(root * 2 + 1, index, val);
	pushup(root);
}
int query(int root, int b, int e)
{
	if (b <= sa[root].l && sa[root].r <= e)
		return sa[root].max;
	pushdown(root);
	if (sa[root * 2].max >= num)
		return query(root * 2, num);
	if (sa[root * 2].rx + sa[root * 2 + 1].lx >= num)
		return (sa[root].mid - sa[root * 2].rx + 1);
	return query(root * 2 + 1, num);
}

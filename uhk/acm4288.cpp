// #include <cstdio>
// #include <cstring>
// #include <cstdlib>
// #include <algorithm>
// #include <cmath>
// #include <set>
// #include <map>
// #include <cctype>
// #include <vector>
// #include <queue>
// #include <stack>
// #include <deque>
// #include <string>
// #include <iostream>
// using namespace std;
// typedef long long ll;
// typedef unsigned long long ull;
// #define foR for
// #define for9 for
// #define retunr return
// #define reutrn return
// #define reutnr return
// #define retrun return
// const int inf = 1000000000;
// const ll INF = (1ll << 63) - 1;
// const double PI = acos(-1.0);
// const double eps = 1e-7;
// const ll MOD = 1000000007ll;
// const int maxn = 100000 + 100;
// const int maxm = 5000 + 100;
// ll ar[maxn];
// ll N;
// char s[10];
// int main()
// {
// 	ll i, j, k, a;
// 	while (scanf("%lld", &N) != EOF)
// 	{
// 		ll top = 1;
// 		ar[0] = -1;
// 		for (i = 1; i <= N; i++)
// 		{
// 			scanf("%s", s);
// 			if (s[0] == 'a')
// 			{
// 				scanf("%lld", &a);
// 				for (j = top; j >= 1; j--)
// 				{
// 					if (a < ar[j - 1])
// 						ar[j] = ar[j - 1];
// 					else
// 						break;
// 				}
// 				ar[j] = a;
// 				top++;
// 			}
// 			else if (s[0] == 'd')
// 			{
// 				scanf("%lld", &a);
// 				ll pos = lower_bound(ar + 1, ar + top, a) - ar;
// 				for (j = pos; j < top - 1; j++)
// 					ar[j] = ar[j + 1];
// 				top--;
// 			}
// 			else
// 			{
// 				ll sum = 0;
// 				for (j = 3; j < top; j += 5)
// 					sum += ar[j];
// 				printf("%lld\n", sum);
// 			}
// 		}
// 	}
// 	return 0;
// }
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define maxn 100010
#define lson rt<<1
#define rson rt<<1|1
#define ll long long int
using namespace std;
struct node{
    int left, right, cnt;
    ll sum[5];
}tree[maxn<<2];
int a[maxn], b[maxn];
char q[maxn], c[5];
void pushUp(int rt){
    tree[rt].cnt = tree[lson].cnt + tree[rson].cnt;
    for(int i = 0;i < 5;i++)
        tree[rt].sum[i] = tree[lson].sum[i] + tree[rson].sum[((i-tree[lson].cnt)%5+5)%5];
}
void bulid(int rt, int l, int r){
    tree[rt].left = l;
    tree[rt].right = r;
    tree[rt].cnt = 0;
    memset(tree[rt].sum, 0, sizeof tree[rt].sum);
    if(l==r) return;
    int mid = (l+r)>>1;
    bulid(lson, l, mid);
    bulid(rson, mid+1, r);
}
void update(int rt, int pos, int add){
    if(tree[rt].left==tree[rt].right){
        tree[rt].sum[1] += add*b[pos];
        tree[rt].cnt += add;
        return;
    }
    int mid = (tree[rt].left+tree[rt].right)>>1;
    if(pos<=mid) update(lson, pos, add);
    else update(rson, pos, add);
    pushUp(rt);
}
int main()
{
    int N, i, j, k;
    while(~scanf("%d", &N)){
        k = 1;
        for(i = 1;i <= N;i++){
            scanf("%s", c);
            q[i] = c[0];
            if(q[i] != 's')
                scanf("%d", &a[k++]);
        }
        memcpy(b+1, a+1, sizeof(int)*(k-1));
        sort(b+1, b+k);
        int n = unique(b+1, b+k)-b-1;

        bulid(1, 1, n);

        for(i = j = 1;i<= N;i++){
            if(q[i] == 's'){
                printf("%I64d\n", tree[1].sum[3]);
                continue;
            }
            int ps = lower_bound(b+1, b+n, a[j++]) - b;

            if(q[i] == 'a') update(1, ps, 1);
            else  update(1, ps, -1);
        }
    }
    return 0;
}

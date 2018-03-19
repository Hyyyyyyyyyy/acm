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
const int inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1000000007ll;
const int maxn = 100000 + 100;
const int maxm = 1000000 + 100;
int tree[20][maxn];     //tree[i][j] 表示第i层第j个数   tree[0][j]表示原始数组
int toleft[20][maxn];   //toleft[i][j] 表示第i层1~j个数中有多少个进入了下一层的左子树
int ar[maxn];           //原始数组排序后的数组
void build(int L, int R, int dep)
{
	if (L == R)
	{
		return;
	}
	int i, j, k;
	int mid = (L + R) / 2;
	int same = mid - L + 1;
	for (i = L; i <= R; i++)
	{
		if (tree[dep][i] < ar[mid])
			same--;
	}
	int lpos = L;
	int rpos = mid + 1;
	for (i = L; i <= R; i++)
	{
		if (tree[dep][i] < ar[mid])
		{
			tree[dep + 1][lpos++] = tree[dep][i];
		}
		else if (tree[dep][i] == ar[mid] && same > 0)
		{
			tree[dep + 1][lpos++] = tree[dep][i];
			same--;
		}
		else
		{
			tree[dep + 1][rpos++] = tree[dep][i];
		}
		toleft[dep][i] = toleft[dep][L - 1] + lpos - L;
	}
	build(L, mid, dep + 1);
	build(mid + 1, R, dep + 1);
}
int query(int L, int R, int dep, int B, int E, int K)
{
	if (B == E)
	{
		return tree[dep][B];
	}
	int i, j, k;
	int mid = (L + R) / 2;
	int cnt = toleft[dep][E] - toleft[dep][B - 1];
	if (cnt >= K)
	{
		int newl = L + toleft[dep][B - 1] - toleft[dep][L - 1];
		int newr = newl + cnt - 1;
		return query(L, mid, dep + 1, newl, newr, K);
	}
	else
	{
		int newr = E + toleft[dep][R] - toleft[dep][E];
		int newl = newr - (E - B - cnt);
		return query(mid + 1, R, dep + 1, newl, newr, K-cnt);
	}
}
//memset(tree, 0, sizeof(tree))
//memset(toleft, 0, sizeof(toleft));
//sort(ar + 1, ar + 1 + N);
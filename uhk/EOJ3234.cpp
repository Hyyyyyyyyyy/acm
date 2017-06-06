#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e5+100;
typedef long long ll;
ll ar[maxn], temp[maxn];
void Merge(int l, int mid, int r)
{
    int i, j, k;
    for(i = l, j = mid+1; i <= mid && j <= r;)
    {
        if(i > mid)
        {
            temp[]
        }
    }
}
void mergesort(int l, int r)
{
    if(r <= l)
        return;
    int mid = (l + r) / 2;
    mergesort(l, mid);
    mergesort(mid+1, r);
    Merge(l, mid, r);
}

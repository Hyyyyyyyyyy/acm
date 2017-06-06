#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll res;
int ar[1000010], temp[1000010];
void merge(int left, int mid, int right);
void merge_sort(int left, int right);
int main()
{
    int i, j, k, u, n, m, b;
    while (scanf("%d", &n) != EOF)
    {
        for (m = 1; m <= n; m++)
        {
            scanf("%d", &ar[m]);
        }
        res = 0;
        merge_sort(1, n);
        //for (i = 1; i <= n; i++)
        //    printf("%d\n", ar[i]);
        printf("%lld\n", res);
    }
    return 0;
}
void merge_sort( int left, int right)
{
    if (left >= right)
        return;
    int mid;
    mid = (left + right) / 2;
    merge_sort(left, mid);
    merge_sort(mid + 1, right);
    merge(left, mid, right);
}
void merge(int left, int mid, int right)
{
    int i, j, k;
    i = left;
    j = mid + 1;
    for (k = left  ;k <= right; k++)
    {
        temp[k] = ar[k];
    }
    for (k = left; k <= right; k++)
    {
        if (i > mid)
            ar[k] = temp[j++];
        else if (j > right)
            ar[k] = temp[i++];
        else if (temp[i] <= temp[j])
            ar[k] = temp[i++];
        else
        {
            ar[k] = temp[j++];
            res += mid - i + 1;
        }
    }
}

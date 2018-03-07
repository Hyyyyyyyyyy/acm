#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 3000 + 100;
int ar[maxn];   //原始数据
int dp[maxn][20];   //dp[i][j]表示以i开始连续j个元素的最值
//转移：dp[i][j] = max(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);     相当于把区间[i,2^j-1]分成[i,2^(j-1)-1]和[i+2^(j-1), 2^j-1];
int Log2[maxn];
void initRMQ(int n)
{
    Log2[0] = -1;
    for(int i = 1; i <= n; i++)
    {
        Log2[i] = ((i & (i-1)) == 0) ? (Log2[i-1] + 1) : Log2[i-1];
        dp[i][0] = ar[i];
    }
    for(int j = 1; j <= Log2[n]; j++)
    {
        for(int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            dp[i][j] = max(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
        }
    }
}
int queryRMQ(int b, int e)
{
    int k = Log2[e - b + 1];
    return max(dp[b][k], dp[e - (1 << k) + 1][k]);
}

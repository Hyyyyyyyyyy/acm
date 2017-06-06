 #include <iostream>
 #include <algorithm>
 #include <cstring>

 using namespace std;

 int t, n, m, dp[33333], v[30], p[30];

 int main()
 {
     while (cin >> n >> m)
     {
         for (int i = 0; i<m; i++)
             cin >> v[i] >> p[i];
         memset(dp, 0, sizeof(dp));
         for (int i = 0; i<m; i++)
             for (int j = n; j >= v[i]; j--)
                     dp[j] = max(dp[j], dp[j - v[i]] + v[i] * p[i]);
         cout << dp[n] << endl;
     }
     return 0;
}

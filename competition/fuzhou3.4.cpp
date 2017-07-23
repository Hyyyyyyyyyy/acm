#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
#include <cctype>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const int maxn = 3000 + 100;
int N;
double dp[maxn];
ll w;
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &N);
			if (N <= 1)
			{
				printf("1.0\n");
				continue;
			}
			dp[N] = 0.0;
			//printf("%f\n", w);
			w = 1;
			double res = 0.0;
			for (i = 1; i <= N; i++)
			{
				w *= i;
				res += 1.0 / (1.0*i);
			}
			printf("%.1f\n", res * (1.0*w));
		}
	}
	return 0;
}
大数浮点数用java
import java.util.Scanner;
import java.math.*;

public class Main{
	
	public static void main(String [] arguments){
		BigDecimal[] dp=new BigDecimal[8100];
		Scanner cin = new Scanner(System.in);
		dp[0]=dp[1]=BigDecimal.ONE;
		BigDecimal w=BigDecimal.ONE;
		for(int i=2;i<=3000;i++){
			dp[i]=dp[i-1].multiply(BigDecimal.valueOf(i)).add(w);
			w=w.multiply(BigDecimal.valueOf(i));
		}
		int T=cin.nextInt();
		for(int t=1;t<=T;t++){
			int n=cin.nextInt();
			BigDecimal setScale1 = dp[n].setScale(1,BigDecimal.ROUND_HALF_UP);
			System.out.println(setScale1.toString());
		}
	}
}

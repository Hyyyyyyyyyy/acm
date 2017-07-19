#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cctype>
#include <set>
using namespace std;
const int INF = 1e10;
const double eps = 1e-8;
typedef long long ll;
const int maxn = 100000 + 100;
char ar[maxn], sa[maxn];
char res[maxn * 3];
char s[maxn];
int N, M;
int main()
{
	int i, j, k, u, n, m, a;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &N, &M);
			for (i = 0; i < N; i++)
			{
				scanf("%s", s);
                ar[i] = s[0];
			}
            ar[i] = 0;
			for (i = 0; i < M; i++)
			{
				scanf("%s", s);
                sa[i] = s[0];
			}
            sa[i] = 0;
			i = 0;
			j = 0;
			int cnt = 0;
			while (i < N && j < M)
			{
				if (ar[i] > sa[j])
				{
					res[cnt++] = ar[i];
					i++;
				}
				else if (ar[i] < sa[j])
				{
					res[cnt++] = sa[j];
					j++;
				}
				else
				{
					if(strcmp(ar+i, sa+j) > 0)
                    {
                        res[cnt++] = ar[i];
                        int k = 1;
                        while(ar[i+k] == sa[j+k] && ar[i+k] >= ar[i+k-1] && i+k<N && j+k < M)
                        {
                            res[cnt++] = ar[i+k];
                            k++;
                        }
                        i = i + k;
                    }
                    else
                    {
                        res[cnt++] = sa[j];
                        int k = 1;
                        while(ar[i+k] == sa[j+k] && sa[j+k] >= sa[j+k-1] && i+k<N && j+k < M)
                        {
                            res[cnt++] = sa[j+k];
                            k++;
                        }
                        j = j + k;
                    }
				}
			}
            res[cnt] = 0;
			if (i >= N && j < M)
			{
				strcat(res, sa+j);
			}
			else if (i < N && j >= M)
			{
				strcat(res, ar+i);
			}
			printf("Case %d: ", m);
			puts(res);
		}
	}
	return 0;
}
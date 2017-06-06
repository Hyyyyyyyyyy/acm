#include<cstdio>
#include <cstring>
#include <algorithm>
using  namespace std;
const int maxn = 10000;
int NUM[maxn], output[maxn];
int n, M, cnt;
void dfs(int num, int pos);
int main() {
	int flag = 0;
	while (scanf("%d %d", &n, &M) != EOF && n && M)
	{
		if (flag)
			printf("\n");
		flag = 1;
		memset(output, -1, sizeof(output));
		for (int i = 1; i <= n; i++)
			scanf("%d", &NUM[i]);
		cnt = 0;
		dfs(1, 1);
	}
	return 0;
}
void dfs(int num, int pos) {
	if (num == M + 1)
	{
		for (int i = 1; i <= M; i++)
		{
			if (i == M)
				printf("%d\n", output[i]);
			else
				printf("%d ", output[i]);
		}
		return;
	}
	if (pos > n)
	{
		return;
	}
	if (NUM[pos] > output[cnt])
	{
		output[++cnt] = NUM[pos];
		dfs(num + 1, pos + 1);
		cnt--;
		dfs(num, pos + 1);
	}
	else
		dfs(num, pos + 1);
}

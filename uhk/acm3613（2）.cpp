#include<iostream>  
#include<cstdio>  
#include<cstdlib>  
#include<cstring>  
#include<string>  
#include<queue>  
#include<algorithm>  
#include<map>  
#include<iomanip>  
#define INF 99999999  
using namespace std;

const int MAX = 500000 + 10;
char s1[MAX], s2[MAX];
int Next[MAX], extend1[MAX], extend2[MAX];
int sum[MAX], val[27];

void get_Next(char *a, int len) {
	int k = 0, i = 1, j;
	Next[0] = len;
	while (k + 1<len && a[k] == a[k + 1])++k;
	Next[1] = k;
	k = 1;
	for (i = 2; i < len; i++)
	{
		if (Next[i - k] + i < Next[k] + k)
			Next[i] = Next[i - k];
		else
		{
			j = Next[k] + k - i;
			if (j < 0)
				j = 0;
			while (a[i + j] == a[j] && i + j < len)
				j++;
			Next[i] = j;
			k = i;
		}
	}
}

void EKMP(char *a, char *b, int *extend, int len) {
	get_Next(a, len);
	int k = 0, i = 0, j;
	while (k < len && a[k] == b[k])++k;
	extend[0] = k;
	k = 0;
	for (i = 1; i < len; i++)
	{
		if (Next[i - k] + i < extend[k] + k)
			extend[i] = Next[i - k];
		else
		{
			j = extend[k] + k - i;
			if (j < 0)
				j = 0;
			while (b[i + j] == a[j] && i + j < len)
				j++;
			extend[i] = j;
			k = i;
		}
	}
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		for (int i = 0; i<26; ++i)cin >> val[i];
		scanf("%s", s1);
		int len = strlen(s1);
		for (int i = 1; i <= len; ++i) {
			sum[i] = sum[i - 1] + val[s1[i - 1] - 'a'];
			s2[i - 1] = s1[len - i];
		}
		EKMP(s1, s2, extend1, len);
		EKMP(s2, s1, extend2, len);
		int ans = 0, temp = 0;
		for (int i = 1; i<len; ++i) {
			if (extend1[len - i] == i)temp += sum[i];//???i???????  
			if (extend2[i] == len - i)temp += sum[len] - sum[i];//???len-i???????  
			if (temp>ans)ans = temp;
			temp = 0;
		}
		cout << ans << endl;
	}
	return 0;
}
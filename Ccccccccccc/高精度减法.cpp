#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
using namespace std;
const int LEN = 10010;
char p[LEN], q[LEN], c[LEN + 10];
char ta[LEN], tb[LEN];
char t[LEN + 10];
char * G_minus(char *a, char *b);
char * G_plus(char *a, char *b);
void Print_G_minus(char *a, char *b);
int main()
{
	int i, j, k, n, m;
	printf("请输入测试组数：\n");
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			printf("请输入两个数做减法：（例如 a b）\n");
			scanf("%s %s", p, q);
			Print_G_minus(p, q);
		}
	}
	return 0;
}
void Print_G_minus(char *a, char *b)
{
	bool flag1 = false, flag2 = false;
	if (a[0] == '-')
		flag1 = true;
	if (b[0] == '-')
		flag2 = true;
	if (!flag1 && !flag2)
	{
		printf("%s - %s = %s\n", a, b, G_minus(a, b));
	}
	else if (flag1 && !flag2)
	{
		printf("%s - %s = -%s\n", a, b, G_plus(a + 1, b));
	}
	else if (!flag1 && flag2)
	{
		printf("%s - %s = %s\n", a, b, G_plus(a, b + 1));
	}
	else
	{
		printf("%s - %s = %s\n", a, b, G_minus(b + 1, a + 1));
	}
}

char * G_minus(char *a, char *b)
{
	int L1, L2, L3, i, j, k, u;
	bool flag = false;
	memset(c, 48, sizeof(c));
	memset(t, 48, sizeof(t));
	L1 = strlen(a);
	L2 = strlen(b);
	if (L1 < L2 || (L1 == L2 && strcmp(a, b) < 0))
	{
		strcpy(ta, b);
		strcpy(tb, a);
		flag = true;
	}
	else
	{
		strcpy(ta, a);
		strcpy(tb, b);
	}
	L1 = strlen(ta);
	L2 = strlen(tb);
	for (i = L1 - 1, j = L2 - 1, k = 0; i >= 0 || j >= 0; i--, j--, k++)
	{
		if (j < 0)
		{
			u = c[k] + ta[i] - '0' - '0';
			if (u < 0)
			{
				c[k + 1] -= 1;
				c[k] = u + 10 + '0';
			}
			else
				c[k] = u + '0';
		}
		if (i < 0)
		{
			u = c[k] + tb[j] - '0' - '0';
			if (u < 0)
			{
				c[k + 1] -= 1;
				c[k] = u + 10 + '0';
			}
			else
				c[k] = u + '0';
		}
		if (i >= 0 && j >= 0)
		{
			u = c[k] + ta[i] - tb[j] + '0' - '0' - '0';
			//printf("%d\n", u);
			if (u < 0)
			{
				c[k + 1] -= 1;
				c[k] = u + 10 + '0';
			}
			else
			{
				c[k] = u + '0';
			}
		}
	}
	c[k + 1] = '\0';
	i = strlen(c) - 1;
	while (c[i] == '0')
		i--;
	if (i == -1)
		return "0";
	if (flag)
	{
		t[0] = '-';
		for (j = 1; i >= 0; i--, j++)
			t[j] = c[i];
		t[j] = '\0';
		return t;
	}
	else
	{
		for (j = 0; i >= 0; i--, j++)
			t[j] = c[i];
		t[j] = '\0';
		return t;
	}
}
char * G_plus(char *a, char *b)
{
	int L1, L2, L3, i, j, k, u;
	char temp[LEN + 10], c[LEN + 10];
	memset(c, 48, sizeof(c));
	memset(t, 48, sizeof(t));
	//puts(a);
	//puts(b);
	L1 = strlen(a);
	L2 = strlen(b);
	//不管谁长谁短一起搞，一个没了只加入另一个就行了，两个都没了结束；
	for (i = L1 - 1, j = L2 - 1, k = 0; i >= 0 || j >= 0; i--, j--, k++)
	{
		if (j < 0)
		{
			u = c[k] + a[i] - '0' - '0';
			if (u >= 10)
			{
				c[k + 1] += 1;
				c[k] = u % 10 + '0';
			}
			else
				c[k] = u + '0';
		}
		if (i < 0)
		{
			u = c[k] + b[j] - '0' - '0';
			if (u >= 10)
			{
				c[k + 1] += 1;
				c[k] = u % 10 + '0';
			}
			else
				c[k] = u + '0';
		}
		if (i >= 0 && j >= 0)
		{
			u = c[k] + a[i] + b[j] - '0' - '0' - '0';
			//printf("%d\n", u);
			if (u >= 10)
			{
				c[k + 1] += 1;
				c[k] = u % 10 + '0';
			}
			else
			{
				c[k] = u + '0';
			}
		}
	}
	c[k + 1] = '\0';
	i = strlen(c) - 1;
	//去掉前导0；
	while (c[i] == '0')
		i--;
	//如果结果是0，输出“0”
	if (i == -1)
		return "0";
	//把反向改为正向输出
	for (j = 0; i >= 0; i--, j++)
		t[j] = c[i];
	t[j] = '\0';
	return t;
}

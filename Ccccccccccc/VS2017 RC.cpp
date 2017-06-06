///*2082第一道生成函数题；
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	int n, m, i, j, k, pre[60], cur[60], num[30];
//	long long int S;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			for (i = 1; i <= 26; i++)
//				scanf("%d", &num[i]);
//			memset(pre, 0, sizeof(int) * 60);
//			memset(cur, 0, sizeof(int) * 60);
//			for (i = 0; i <= num[1]; i++)
//				pre[i] = 1;
//
//			for (i = 2; i <= 26; i++)
//			{
//				if (num[i] == 0)
//					continue;
//				for (j = 0; j <= 50; j++)
//				{
//					for (k = 0; k <= num[i] * i && k + j <= 50; k = k + i)
//					{
//						cur[k + j] += pre[j];
//
//					}
//				}
//
//				for (j = 0; j <= 50; j++)
//				{
//					pre[j] = cur[j];
//					cur[j] = 0;
//				}
//			}
//
//			S = 0;
//			for (i = 1; i <= 50; i++)
//				S += pre[i];
//
//			printf("%lld\n", S);
//			
//		}
//	}
//	return 0;
//}
//*/


//1085 很水，但是注意 取值范围；
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	int i, j, k, pre[20000], cur[20000], num[4];
//	while (scanf("%d %d %d", &num[1], &num[2], &num[3]) != EOF && (num[1] != 0 || num[2] != 0 || num[3] != 0))
//	{
//		memset(pre, 0, sizeof(int) * 20000);
//		memset(cur, 0, sizeof(int) * 20000);
//
//		for (i = 0; i <= num[1]; i++)
//			pre[i] = 1;
//
//		for (i = 0; i <= num[1]; i++)
//		{
//			for (j = 0; j <= num[2] * 2; j += 2)
//			{
//				cur[j + i] += pre[i];
//			}
//		}
//		for (i = 0; i <= num[2] * 2 + num[1]; i++)
//		{
//			pre[i] = cur[i];
//			cur[i] = 0;
//		}
//		for (i = 0; i <= num[2] * 2 + num[1]; i++)
//		{
//			for (j = 0; j <= num[3] * 5; j += 5)
//			{
//				cur[j + i] += pre[i];
//			}
//		}
//		for (i = 1; i <= num[1] + num[2] * 2 + num[3] * 5 + 1; i++)
//			if (cur[i] == 0)
//				break;
//		if (cur[i] == 0)
//			printf("%d\n", i);
//	}
//	return 0;
//}



//2079仍然生成函数
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	int n, m, a, b, u, i, j, k, pre[50], cur[50], num[50];
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d", &a, &b);
//			for (u = 1; u <= b; u++)
//			{
//				scanf("%d %d", &u, &num[u]);
//			}
//			memset(pre, 0, sizeof(int) * 50);
//			memset(cur, 0, sizeof(int) * 50);
//			for (i = 0; i <= num[1]; i++)
//				pre[i] = 1;
//			for (i = 2; i <= b; i++)
//			{
//				for (j = 0; j <= a; j++)
//				{
//					for (k = 0; k <= num[i] * i && k + j <= a; k += i)
//					{
//						cur[k + j] += pre[j];
//					}
//				}
//				for (j = 0; j <= a; j++)
//				{
//					pre[j] = cur[j];
//					cur[j] = 0;
//				}
//			}
//
//			printf("%d\n", pre[a]);
//		}
//	}
//	return 0;
//}


//2110 带求余的生成函数；
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	int n, m, i, j, k, sum, value[100], num[100], pre[10010], cur[10010];
//	while (scanf("%d", &n) && n != 0)
//	{
//		sum = 0;
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d", &value[m], &num[m]);
//			sum += value[m] * num[m];
//		}
//		if (sum % 3 != 0)
//		{
//			printf("sorry\n");
//			continue;
//		}
//		sum /= 3;
//		memset(pre, 0, sizeof(int) * 10010);
//		memset(cur, 0, sizeof(int) * 10010);
//		for (i = 0; i <= num[1] * value[1]; i += value[1])
//			pre[i] = 1;
//
//		for (i = 2; i <= n; i++)
//		{
//			for (j = 0; j <= (sum + 10); j++)
//			{
//				for (k = 0; k <= num[i] * value[i] && k + j <= (sum + 10); k += value[i])
//					cur[k + j] += pre[j] % 10000;
//			}
//
//			for (j = 0; j <= (sum + 10); j++)
//			{
//				pre[j] = cur[j] % 10000;
//				cur[j] = 0;
//			}
//		}
//		if (pre[sum] != 0)
//			printf("%d\n", pre[sum]);
//		else
//			printf("sorry\n");
//	}
//	return 0;
//}


/*1171  还是生成函数 有 sum 0 这种情况。。。醉了；
#include <stdio.h>
#include <string.h>
int main()
{
int n, m;
long long sum, halfsum, i, j, k, num[1005], value[55], pre[260000], cur[260000];
while (scanf("%d", &n) != EOF && n > 0)
{
sum = 0;
for (m = 1; m <= n; m++)
{
scanf("%lld %lld", &value[m], &num[m]);
sum += num[m] * value[m];
}
halfsum = sum / 2;
memset(pre, 0, sizeof(long long) * 260000);
memset(cur, 0, sizeof(long long) * 260000);
for (i = 0; i <= num[1] * value[1]; i += value[1])
pre[i] = 1;
for (i = 2; i <= n; i++)
{
for (j = 0; j <= halfsum; j++)
{

for (k = 0; k <= num[i] * value[i] && k + j <= halfsum; k += value[i])
cur[k + j] += pre[j];
}

for (j = 0; j <= halfsum; j++)
{
pre[j] = cur[j];
cur[j] = 0;
}
}

for (i = halfsum; i >= 0; i--)
{
if (pre[i])
{
if (i <= sum - i)
printf("%lld %lld\n", sum - i, i);
else
printf("%lld %lld\n", i, sum - i);
break;
}
}

}
return 0;
}
*/

/*2844  生成函数已经无能为力了，背包吧；
#include <stdio.h>
#include <string.h>
int main()
{
int x, y, n, m, i, j, k, pre[110000], cur[110000], num[105], value[105], count;
while (scanf("%d %d", &x, &y) != EOF && (x != 0 || y != 0))
{
for (n = 1; n <= x; n++)
scanf("%d", &value[n]);
for (n = 1; n <= x; n++)
scanf("%d", &num[n]);
for (i = 0; i < 110000; i++)
{
pre[i] = 0;
cur[i] = 0;
}
for (i = 0; i <= num[1] * value[1]; i += value[1])
pre[i] = 1;
for (i = 2; i <= x; i++)
{
for (j = 0; j <= y; j++)
{
if (pre[j] == 0)
continue;
for (k = 0; k <= num[i] * value[i] && k + j <= y; k += value[i])
cur[k + j] += pre[j];
}
for (j = 0; j <= y; j++)
{
pre[j] = cur[j];
cur[j] = 0;
}
}
count = 0;
for (i = 1; i <= y; i++)
if (pre[i] != 0)
count++;

printf("%d\n", count);
}
return 0;
}
*/

//2546 第一个背包；
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	int n, m, i, j, bag[1005], value[1005], money, max, temp, sum;
//	while (scanf("%d", &n) != EOF && n != 0)
//	{
//
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &value[m]);
//		}
//
//		scanf("%d", &money);
//		if (money < 5)
//		{
//			printf("%d\n", money);
//			continue;
//		}
//
//		for (i = 1; i <= n; i++)
//		{
//			if (value[n] < value[i])
//			{
//				temp = value[n];
//				value[n] = value[i];
//				value[i] = temp;
//			}
//		}
//
//		memset(bag, 0, sizeof(int) * 1005);
//		sum = 0;
//
//		for (i = 1; i < n; i++)
//		{
//			for (j = money - 5; j >= value[i]; j--)
//			{
//				temp = bag[j - value[i]] + value[i];
//				bag[j] = (bag[j] > temp) ? bag[j] : temp;
//			}
//
//		}
//		printf("%d\n", money - bag[money - 5] - value[n]);
//	}
//	return 0;
//}



//2546  2维版
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	int n, m, i, j, k, bag[1005][1005], value[1005], money, temp, max;
//	while (scanf("%d", &n) != EOF && n!=0)
//	{
//
//		for (m = 1; m <= n; m++)
//			scanf("%d", &value[m]);
//
//		scanf("%d", &money);
//		if (money < 5)
//		{
//			printf("%d\n", money);
//			continue;
//		}
//
//		for (i = 1; i <= n; i++)
//		{
//			if (value[n] < value[i])
//			{
//				temp = value[n];
//				value[n] = value[i];
//				value[i] = temp;
//			}
//		}
//
//		for (i = 0; i <= n; i++)
//			for (j = 0; j <= money; j++)
//				bag[i][j] = 0;
//		
//		for (i = 1; i < n; i++)
//		{
//			for (j = money-5; j >= value[i]; j--)
//			{
//				bag[i][j] = (bag[i - 1][j] > bag[i - 1][j - value[i]] + value[i]) ? bag[i - 1][j] : (bag[i - 1][j - value[i]] + value[i]);
//			}
//		}
//		max = 0;
//		for (i = 1; i < n; i++)
//			max += bag[i][money - 5];
//		printf("%d\n", money - max - value[n]);
//	}
//	return 0;
//}






//#include <stdio.h>
//#include <string.h>
//struct bone
//{
//	long long int volume, value;
//};
//int main()
//{
//	long long int n, m, i, j, k, bag[1010][1010], c, v;
//	struct bone Teddy[1010];
//
//	while (scanf("%lld", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%lld %lld", &c, &v);
//
//			for (i = 1; i <= c; i++)
//				scanf("%lld", &Teddy[i].value);
//			for (i = 1; i <= c; i++)
//				scanf("%lld", &Teddy[i].volume);
//
//			for (i = 0; i <= c; i++)
//				for (j = 0; j <= v; j++)
//					bag[i][j] = 0;
//			for (i = 1; i <= c; i++)
//			{
//				for (j = v; j >= Teddy[i].volume; j--)
//				{
//					bag[i][j] = (bag[i - 1][j] >= bag[i - 1][j - Teddy[i].volume] + Teddy[i].value) ? bag[i - 1][j] : bag[i - 1][j - Teddy[i].volume] + Teddy[i].value;
//				}
//			}
//			printf("%lld\n", bag[c][v]);
//		}
//	}
//	return 0;
//}



//曾庚的骨头；
//#include<stdio.h>
//
//int c[1001][1001] = { 0 };
//void knap(int n, int v)
//{
//	int i, j;
//	int val[1010] = { 0 }, w[1010] = { 0 };
//	for (i = 1; i <= n; i++)
//		scanf("%d", &val[i]);
//	for (i = 1; i <= n; i++)
//		scanf("%d", &w[i]);
//	for (i = 1; i <= n; i++)//先物品
//	{
//		for (j = 0; j <= v; j++)//后容量
//		{
//			if (j < val[i])//装不下，背包容量小于物品对应的体积
//			{
//				c[i][j] = c[i - 1][j];
//			}
//			else if (c[i - 1][j - val[i]] + w[i] > c[i - 1][j])
//			{
//				c[i][j] = c[i - 1][j - val[i]] + w[i];
//			}
//			else
//				c[i][j] = c[i - 1][j];
//		}
//	}
//}
//int main()
//{
//	int n, v;
//	int i, j;
//	int t;
//	while (scanf("%d", &t) == 1)
//	{
//		while (t--)
//		{
//			scanf("%d%d", &n, &v);
//			knap(n, v);
//			printf("%d\n", c[n][v]);
//		}
//	}
//	return 0;
//}







//2191 多重背包，一维背包；
//#include <stdio.h>
//#include <string.h>
//
//struct wen
//{
//	int value, weight, num;
//};
//
//int main()
//{
//	int n, m, sum, money, c, i, j, k, u, bag[40010];
//	struct wen di[105];
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d", &money, &c);
//			for (u = 1; u <= c; u++)
//			{
//				scanf("%d %d %d", &di[u].value, &di[u].weight, &di[u].num);
//			}
//			memset(bag, 0, sizeof(int) * 40010);
//			sum = 0;
//			for (i = 1; i <= c; i++)
//			{
//				for (k = 1; k <= di[i].num; k++)
//				{
//					for (j = money; j >= di[i].value; j--)
//					{
//						if (bag[j] < bag[j - di[i].value] + di[i].weight)
//						{
//							bag[j] = bag[j - di[i].value] + di[i].weight;
//						}
//					}
//				}
//			}
//			printf("%d\n", bag[money]);
//		}
//	}
//	return 0;
//}



//1203 一维背包, 不用恰好把背包装满。概率题，一定用乘法；
//#include <stdio.h>
//struct offer
//{
//	int expense;
//	double percent;
//};
//int main()
//{
//	int n, m, i, j, k, c;
//	double bag[41000];
//	struct offer sk[10010];
//	while (scanf("%d %d", &n, &m) != EOF && (n != 0 || m != 0))
//	{
//		for (c = 1; c <= m; c++)
//		{
//			scanf("%d %lf", &sk[c].expense, &sk[c].percent);
//		}
//		for (i = 0; i < 41000; i++)
//			bag[i] = 1;
//
//		for (i = 1; i <= m; i++)
//		{
//			for (j = n; j >= sk[i].expense; j--)
//			{
//				bag[j] = (bag[j] <= bag[j - sk[i].expense] * (1.0 - sk[i].percent)) ? bag[j] : (bag[j - sk[i].expense] * (1.0 - sk[i].percent));
//			}
//		}
//		printf("%.1f%%\n", (1.0 - bag[n])*100.0);
//	}
//	return 0;
//}



//2159  完全背包 + 二维背包，二维数组加顺序 即可；
//#include <stdio.h>
//#include <string.h>
//struct game
//{
//	int experience, patience;
//};
//
//int main()
//{
//	int n, m, i, j, k, bag[200][200], mexperience, mpatience, mkind, mkill, min, doudou, c;
//	struct game xhd[200];
//	while (scanf("%d %d %d %d", &mexperience, &mpatience, &mkind, &mkill) != EOF)
//	{
//		for (n = 1; n <= mkind; n++)
//		{
//			scanf("%d %d", &xhd[n].experience, &xhd[n].patience);
//		}
//
//		memset(bag, 0, sizeof(int) * 200 * 200);
//
//		for (i = 1; i <= mkind; i++)
//		{
//			for (j = 1; j <= mkill; j++)
//			{
//				for (k = xhd[i].patience; k <= mpatience; k++)
//				{
//					bag[j][k] = (bag[j][k] >= bag[j - 1][k - xhd[i].patience] + xhd[i].experience) ? bag[j][k] : (bag[j - 1][k - xhd[i].patience] + xhd[i].experience);
//				}
//			}
//		}
//
//		doudou = 0;
//		c = 9999999;
//		for (i = 0; i <= mpatience; i++)
//		{
//			for (j = 1; j <= mkill; j++)
//			{
//				if (bag[j][i] >= mexperience)
//				{
//					doudou = 1;
//					c = i;
//					break;
//				}
//			}
//			if (doudou)
//				break;
//		}
//		if (c != 9999999)
//			printf("%d\n", mpatience - c);
//		else
//			printf("-1\n");
//	}
//	return 0;
//}




//2955 带概率的基本都是用乘法，这个题为什么不用Roy[i].c直接乘，
//因为这样算出来的是既第一次被抓又第二次被抓概率，还要加上第一次被抓第二次不被抓和第一次不被抓第二次被抓。
//这样很麻烦，所以直接算1-Roy[i]相成，就是不会被抓的概率，最后算1-  就行了；
//初始化也很重要，这个是要恰好，因为我们要算出每一个准确金额的概率，必须装满；
//#include <stdio.h>
//#include <string.h>
//struct bank
//{
//	int money;
//	double c;
//};
//int main()
//{
//	int n, m, i, j, k, num, sum, u;
//	double bag[11000], mcatch;
//	struct bank Roy[110];
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			sum = 0;
//			scanf("%lf %d", &mcatch, &num);
//
//				for (u = 1; u <= num; u++)
//				{
//					scanf("%d %lf", &Roy[u].money, &Roy[u].c);
//						sum += Roy[u].money;
//
//				}
//				bag[0] = 1;
//				for (i = 0; i < 11000; i++)
//					bag[i] = 0;
//			for (i = 1; i <= num; i++)
//			{
//				for (j = sum; j >= Roy[i].money; j--)
//				{
//					bag[j] = (bag[j] > bag[j - Roy[i].money] * (1.0-Roy[i].c)) ? bag[j] : (bag[j - Roy[i].money] * (1.0-Roy[i].c));
//				}
//			}
//			for (j = sum; j >= 0; j--)
//			{
//				if (bag[j] > (1.0-mcatch))
//					break;
//			}
//			printf("%d\n", j);
//		}
//	}
//	return 0;
//}



//1114 完全背包，必须装满，顺序，bag【0】单列，少了一个句点。。。
//#include <stdio.h>
//#include <string.h>
//struct expense
//{
//	int wei, value;
//};
//int main()
//{
//	int n, m, i, j, k, u, bag[1000005], mwei, pigwei, c;
//	struct expense pig[550];
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d", &pigwei, &mwei);
//
//			mwei -= pigwei;
//
//			scanf("%d", &c);
//			for (u = 1; u <= c; u++)
//			{
//				scanf("%d %d", &pig[u].value, &pig[u].wei);
//			}
//			for (i = 1; i <= mwei; i++)
//				bag[i] = 10000000;
//			bag[0] = 0;
//			for (i = 1; i <= c; i++)
//			{
//				for (j = pig[i].wei; j <= mwei; j++)
//				{
//					bag[j] = (bag[j] < bag[j - pig[i].wei] + pig[i].value) ? bag[j] : (bag[j - pig[i].wei] + pig[i].value);
//				}
//			}
//			if (bag[mwei] == 10000000)
//				printf("This is impossible.\n");
//			else
//				printf("The minimum amount of money in the piggy-bank is %d.\n", bag[mwei]);
//		}
//	}
//	return 0;
//}







//2844 超时了，需要二进制优化
//#include <stdio.h>
//struct coin
//{
//	int value;
//	int num;
//};
//int main()
//{
//	int n, m, i, j, k, bag[100001], mvalue, c, count;
//	struct coin Hibix[105];
//	while (scanf("%d %d", &c, &mvalue) != EOF && (c != 0 || mvalue != 0))
//	{
//		for (m = 1; m <= c; m++)
//			scanf("%d", &Hibix[m].value);
//		for (m = 1; m <= c; m++)
//			scanf("%d", &Hibix[m].num);
//		for (i = 1; i <= mvalue; i++)
//			bag[i] = -100005;
//		bag[0] = 0;
//		for (i = 1; i <= c; i++)
//		{
//			for (k = 1; k <= Hibix[i].num; k++)
//			{
//				for (j = mvalue; j >= Hibix[i].value; j--)
//					bag[j] = (bag[j] > bag[j - Hibix[i].value] + Hibix[i].value) ? bag[j] : (bag[j - Hibix[i].value] + Hibix[i].value);
//			}
//		}
//		count = 0;
//		for (j = 1; j <= mvalue; j++)
//		{
//			if (bag[j] > 0)
//				count++;
//		}
//		printf("%d\n", count);
//	}
//	return 0;
//}






//进队赛，第一题选手机
//#include <stdio.h>
//int main()
//{
//	int i, j;
//	double n, m, p, k;
//	while (scanf("%d", &i) != EOF)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			scanf("%lf %lf %lf %lf", &n, &m, &p, &k);
//			if (n / m >= p / k)
//				printf("iphone 5S\n");
//			else
//				printf("iphone 5C\n");
//		}
//	}
//	return 0;
//}




//进队赛，旋转矩阵；
//#include <stdio.h>
//int main()
//{
//	int n, m, i, j, k, u, ar[105][105], c, d, doudou;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d", &c, &d);
//
//			for (i = 1; i <= c; i++)
//			{
//				for (j = 1; j <= c; j++)
//				{
//					scanf("%d", &ar[i][j]);
//
//				}
//			}
//			doudou = 0;
//			if ((d / 90) % 4 == 0)
//			{
//
//				for (i = 1; i <= c; i++)
//				{
//					doudou = 0;
//					for (j = 1; j <= c; j++)
//					{
//						if (doudou)
//							putchar(' ');
//						doudou = 1;
//						printf("%d", ar[i][j]);
//
//						if (j == c)
//							putchar('\n');
//					}
//				}
//			}
//			else if ((d / 90) % 4 == 1)
//			{
//
//				for (i = 1; i <= c; i++)
//				{
//					doudou = 0;
//					for (j = 1; j <= c; j++)
//					{
//						if (doudou)
//							putchar(' ');
//						doudou = 1;
//						printf("%d", ar[c+1-j][i]);
//						if (j == c)
//							putchar('\n');
//					}
//				}
//
//			}
//			else if ((d / 90) % 4 == 2)
//			{
//				for (i = 1; i <= c; i++)
//				{
//					doudou = 0;
//					for (j = 1; j <= c; j++)
//					{
//						if (doudou)
//							putchar(' ');
//						doudou = 1;
//						printf("%d", ar[c + 1 - i][c + 1 - j]);
//
//						if (j == c)
//							putchar('\n');
//					}
//				}
//			}
//			else if ((d / 90) % 4 == 3)
//			{
//				for (i = 1; i <= c; i++)
//				{
//					doudou = 0;
//					for (j = 1; j <= c; j++)
//					{
//						if (doudou)
//							putchar(' ');
//						doudou = 1;
//						printf("%d", ar[j][c+1-i]);
//
//						if (j == c)
//							putchar('\n');
//					}
//				}
//			}
//			putchar('\n');
//		}
//	}
//	return 0;
//}
//



//进队赛，矩阵
//#include <stdio.h>
//#include <stdlib.h>
//int comp(const void * p1, const void * p2);
//int main()
//{
//	int n, m, i, j, k, u, ar[999], row, line, doudou;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d", &row, &line);
//			k = 0;
//			for (i = 1; i <= row; i++)
//			{
//				for (j = 1; j <= line; j++)
//				{
//					scanf("%d", &ar[k]);
//					k++;
//				}
//			}
//			qsort(ar, row*line, sizeof(int), comp);
//			k = 0;
//			for (i = 1; i <= row; i++)
//			{
//				doudou = 0;
//				for (j = 1; j <= line; j++)
//				{
//					if (doudou)
//						putchar(' ');
//					doudou = 1;
//					printf("%d", ar[k]);
//					k++;
//					if (j == line)
//						putchar('\n');
//				}
//			}
//		}
//	}
//	return 0;
//}
//
//int comp(const void * p1, const void * p2)
//{
//	const int * a1 = (const int *)p1;
//	const int * a2 = (const int *)p2;
//
//	if (*a1 < *a2)
//		return -1;
//	else if (*a1 == *a2)
//		return 0;
//	else
//		return 1;
//}




//进队赛，算期望
//#include <stdio.h>
//int main()
//{
//	double a, b, c;
//	int n, m;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%lf %lf %lf", &a, &b, &c);
//			printf("%.6lf\n", 0.25*a + 0.25*b - 0.5*c);
//		}
//	}
//	return 0;
//}




//进队赛，找对称数；
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	int n, m, i, j, *p, *q, ar[100010], set[100010], sa[100010], doudou;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &i);
//			memset(set, 0, sizeof(int) * 100010);
//			memset(sa, 0, sizeof(int) * 100010);
//			for (j = 1; j <= i; j++)
//			{
//				scanf("%d", &ar[j]);
//				if (ar[j] >= 0)
//					set[ar[j]]++;
//				else
//					sa[(-1)*ar[j]]++;
//			}
//			doudou = 0;
//			for (i = 0; i < 100010; i++)
//			{
//				if (set[i] % 2 != 0 && doudou == 1)
//				{
//					printf("No\n");
//					doudou = 2;
//					break;
//				}
//				else if (set[i] % 2 != 0 && doudou == 0)
//				{
//					doudou = 1;
//				}
//			}
//			if (doudou == 2)
//				continue;
//			for (i = 0; i < 100010; i++)
//			{
//				if (sa[i] % 2 != 0 && doudou == 1)
//				{
//					printf("No\n");
//					doudou = 2;
//					break;
//				}
//				else if (sa[i] % 2 != 0 && doudou == 0)
//				{
//					doudou = 1;
//				}
//			}
//			if (doudou != 2)
//				printf("Yes\n");
//		}
//	}
//	return 0;
//}





//进队赛 7，约瑟夫圈
//#include <stdio.h>
//int main()
//{
//	int m, n, i, u, c, doudou, a, b;
//	int ar[110], sa[110];
//	while (scanf("%d", &a) != EOF)
//	{
//		for (b = 1; b <= a; b++)
//		{
//
//			scanf("%d", &m);
//
//
//			scanf("%d", &n);
//			{
//				doudou = 0;
//				for (i = 0; i < m; i++)
//					ar[i] = i + 1;
//				c = 0;
//				u = 0;
//				for (i = 0;; i++)
//				{
//					if (i == m)
//						i = 0;
//					if (ar[i] == 0)
//						continue;
//					c++;
//					if (c % n == 0)
//					{
//						sa[u] = ar[i];
//						u++;
//						ar[i] = 0;
//					}
//					if (u == m)
//						break;
//				}
//				for (i = 0; i < m; i++)
//				{
//					if (doudou)
//						printf(" ");
//					printf("%d", sa[i] - 1);
//					doudou = 1;
//				}
//			}
//			putchar('\n');
//		}
//	}
//	return 0;
//}











//2141  Ai+Bj+Ck==S  二分查找；
//#include <stdio.h>
//#include <stdlib.h>
//int comp(const void * p1, const void * p2)
//{
//	const int * a1 = (const int *)p1;
//	const int * a2 = (const int *)p2;
//
//	if (*a1 < *a2)
//		return -1;
//	else if (*a1 == *a2)
//		return 0;
//	else
//		return 1;
//}
//
//
//int main()
//{
//	int a[510], b[510], c[510], s, d = 1, temp, i, j, n, m, k, x, y, u, A, B, C, S, D, doudou, set[250010];
//	while (scanf("%d %d %d", &A, &B, &C) != EOF)
//	{
//		for (i = 1; i <= A; i++)
//			scanf("%d", &a[i]);
//		for (i = 1; i <= B; i++)
//			scanf("%d", &b[i]);
//		for (i = 1; i <= C; i++)
//			scanf("%d", &c[i]);
//		u = 0;
//		for (i = 1; i <= C; i++)
//		{
//			for (j = 1; j <= A; j++)
//			{
//				set[u++] = a[j] + c[i];
//			}
//		}
//		qsort(set, A*C, sizeof(int), comp);
//		scanf("%d", &S);
//		printf("Case %d:\n", d);
//		d++;
//		for (n = 1; n <= S; n++)
//		{
//			scanf("%d", &s);
//			doudou = 0;
//			for (i = 1; i <= B; i++)
//			{
//				x = 0;
//				y = A*C-1;
//				while (y >= x)
//				{
//					if (s - b[i] < set[(x + y) / 2])
//						y = (x + y) / 2 - 1;
//					else if (s - b[i] > set[(x + y) / 2])
//						x = (x + y) / 2 + 1;
//					else
//					{
//						doudou = 1;
//						break;
//					}
//				}
//				if (doudou)
//					break;
//			}
//			if (doudou)
//				printf("YES\n");
//			else
//				printf("NO\n");
//		}
//	}
//	return 0;
//}








//2143 没理解题意，10/3==3，但是这个不行，实际10/3==3.333333333，不等于3；
//#include <stdio.h>
//int main()
//{
//	long long int a, b, c;
//	while (scanf("%lld %lld %lld", &a, &b, &c) != EOF)
//	{
//
//		if (a + b == c || a + c == b || b + c == a || a*b == c || a*c == b || b*c == a || (a != 0 && (b%a==c || c%a==b)) || (b != 0 && (c%b==a || a%b==c)) || (c != 0 && (a%c==b || b%c==a)))
//			printf("oh,lucky!\n");
//		else
//			printf("what a pity!\n");
//
//	}
//	return 0;
//}



//1008 电梯（1）；
//#include <stdio.h>
//int main()
//{
//	int n, m, ar[9999], sum;
//	while (scanf("%d", &n) != EOF && n != 0)
//	{
//		ar[0] = 0;
//		sum = 0;
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &ar[m]);
//			if (ar[m] >= ar[m - 1])
//			{
//				sum += 6 * (ar[m] - ar[m - 1]) + 5;
//			}
//			else
//				sum += 4 * (ar[m - 1] - ar[m]) + 5;
//		}
//		printf("%d\n", sum);
//	}
//	return 0;
//}



//1248   纯完全背包；
//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	int n, m, i, j, k, u, bag[10010], ar[4], money;
//	while (scanf("%d", &n) != EOF)
//	{
//		ar[1] = 150;
//		ar[2] = 200;
//		ar[3] = 350;
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &money);
//			memset(bag, 0, sizeof(int) * 10010);
//			for (i = 1; i <= 3; i++)
//			{
//				for (j = ar[i]; j <= money; j++)
//				{
//					bag[j] = (bag[j] > bag[j - ar[i]] + ar[i]) ? bag[j] : bag[j - ar[i]] + ar[i];
//				}
//			}
//			printf("%d\n", money - bag[money]);
//		}
//
//	}
//	return 0;
//}




//4508   又是完全背包  根本没有看题。。。白白丢了ac率。。。
//#include <stdio.h>
//#include <string.h>
//struct lose_weight
//{
//	int happy;
//	int ka;
//};
//int main()
//{
//	int n, m, i, j, k, u, bag[100010], mka;
//	struct lose_weight qq[110];
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d", &qq[m].happy, &qq[m].ka);
//		}
//		scanf("%d", &mka);
//		memset(bag, 0, sizeof(int) * 100010);
//		for (i = 1; i <= n; i++)
//		{
//			for (j = qq[i].ka; j <= mka; j++)
//			{
//				bag[j] = (bag[j] > bag[j - qq[i].ka] + qq[i].happy) ? bag[j] : (bag[j - qq[i].ka] + qq[i].happy);
//			}
//		}
//		printf("%d\n", bag[mka]);
//	}
//	return 0;
//}




//4509  时间覆盖，用set【】记录，覆盖部分用1，其余部分用0；
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	int n, m, set[2000], b, e, i, j, k, u, count;
//	char begin[5], end[5];
//	while (scanf("%d", &n) != EOF)
//	{
//		getchar();
//		memset(set, 0, sizeof(int) * 2000);
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%c%c:%c%c %c%c:%c%c", &begin[1], &begin[2], &begin[3], &begin[4], &end[1], &end[2], &end[3], &end[4]);
//			getchar();
//			b = ((begin[1]-48) * 10 + (begin[2]-48)) * 60 + (begin[3]-48) * 10 + begin[4] - 48;
//			e = ((end[1]-48) * 10 + (end[2]-48)) * 60 + (end[3]-48) * 10 + (end[4]-48);
//			for (i = b; i <= e; i++)
//				set[i] = 1;
//		}
//		count = 0;
//		for (i = 1; i <= 1440; i++)
//		{
//			if (set[i] == 0)
//				count++;
//			else if (set[i - 1] == 0)
//				count++;
//		}
//		printf("%d\n", count);
//	}
//	return 0;
//}
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	int n, m, set[2000], b, e, i, j, k, u, count;
//	int begin[5], end[5];
//	while (scanf("%d", &n) != EOF)
//	{
//
//		memset(set, 0, sizeof(int) * 2000);
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d:%d %d:%d", &begin[1], &begin[2], &end[1], &end[2]);
//
//			b = (begin[1]) * 60 + begin[2];
//			e = (end[1]) * 60 + end[2];
//			for (i = b; i <= e; i++)
//				set[i] = 1;
//		}
//		count = 0;
//		for (i = 1; i <= 1440; i++)
//		{
//			if (set[i] == 0)
//				count++;
//			else if (set[i - 1] == 0)
//				count++;
//		}
//		printf("%d\n", count);
//	}
//	return 0;
//}







//2844   多重背包   终于过啦。。哈哈哈  人生得到了满足！！
//#include <stdio.h>
//struct coin
//{
//	int value;
//	int num;
//};
//int main()
//{
//	int n, m, i, j, k, bag[1000010], mvalue, c, count;
//	struct coin Hibix[2000];
//	while (scanf("%d %d", &c, &mvalue) != EOF && (c != 0 || mvalue != 0))
//	{
//		for (m = 1; m <= c; m++)
//			scanf("%d", &Hibix[m].value);
//		for (m = 1; m <= c; m++)
//			scanf("%d", &Hibix[m].num);
//		for (i = 1; i <= mvalue; i++)
//			bag[i] = -10000000;
//		bag[0] = 0;
//		for (i = 1; i <= c; i++)
//		{
//			if (Hibix[i].value * Hibix[i].num >= mvalue)
//			{
//				for (j = Hibix[i].value; j <= mvalue; j++)
//					bag[j] = (bag[j] > bag[j - Hibix[i].value] + Hibix[i].value) ? bag[j] : (bag[j - Hibix[i].value] + Hibix[i].value);
//			}
//			else
//			{
//				k = 1;
//				while (k <= Hibix[i].num)
//				{
//					for (j = mvalue; j >= k*Hibix[i].value; j--)
//						bag[j] = (bag[j] > bag[j - k*Hibix[i].value] + k*Hibix[i].value) ? bag[j] : (bag[j - k*Hibix[i].value] + k*Hibix[i].value);
//					Hibix[i].num -= k;
//					k *= 2;
//				}
//				if(Hibix[i].num)
//					for (j = mvalue; j >= Hibix[i].num*Hibix[i].value; j--)
//						bag[j] = (bag[j] > bag[j - Hibix[i].num*Hibix[i].value] + Hibix[i].num*Hibix[i].value) ? bag[j] : (bag[j - Hibix[i].num*Hibix[i].value] + Hibix[i].num*Hibix[i].value);
//			}
//		}
//		count = 0;
//		for (j = 1; j <= mvalue; j++)
//		{
//			if (bag[j] > 0)
//				count++;
//		}
//		printf("%d\n", count);
//	}
//	return 0;
//}









//2159  二维背包，耐性背包恰好装满，不能一个怪都不杀；
//#include <stdio.h>
//#include <string.h>
//struct monster
//{
//	int exp;
//	int pati;
//};
//int main()
//{
//	int n, m, i, j, k, u, bag[105][105], mexp, mpati, mkind, mkill, doudou;
//	struct monster xhd[105];
//	while (scanf("%d %d %d %d", &mexp, &mpati, &mkind, &mkill) != EOF)
//	{
//		for (m = 1; m <= mkind; m++)
//		{
//			scanf("%d %d", &xhd[m].exp, &xhd[m].pati);
//		}
//		for (i = 0; i < 105; i++)
//		{
//			for (j = 0; j < 105; j++)
//				bag[i][j] = -1000000;
//		}
//		bag[0][0] = 0;
//		for (i = 1; i <= mkind; i++)
//		{
//			for (j = xhd[i].pati; j <= mpati; j++)
//			{
//				for (k = 1; k <= mkill; k++)
//				{
//					bag[j][k] = (bag[j][k] > bag[j - xhd[i].pati][k - 1] + xhd[i].exp) ? bag[j][k] : (bag[j - xhd[i].pati][k - 1] + xhd[i].exp);
//				}
//			}
//		}
//		doudou = 0;
//		for (j = 0; j <= mpati; j++)
//		{
//			for (k = 0; k <= mkill; k++)
//			{
//				if (bag[j][k] >= mexp)
//				{
//					printf("%d\n", mpati - j);
//					doudou = 1;
//					break;
//				}
//			}
//			if (doudou)
//				break;
//		}
//		if (doudou == 0)
//		{
//			printf("-1\n");
//		}
//	}
//	return 0;
//}





//3496     二维背包， 初始化一维都要初始化，因为只要买的数量是0，不管time给多少都是0，因为需要的time有负数，所以初始化time时要赋为负无穷,
//数组要开大一点；
//#include <stdio.h>
//#include <string.h>
//struct moive
//{
//	int time;
//	int value;
//};
//int main()
//{
//	int n, m, i, j, k, u, bag[120][1200], mtime, mnum, c;
//	struct moive duoduo[120];
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d %d", &c, &mnum, &mtime);
//			for (u = 1; u <= c; u++)
//			{
//				scanf("%d %d", &duoduo[u].time, &duoduo[u].value);
//			}
//			for (i = 0; i < 120; i++)
//			{
//				for (j = 0; j < 1200; j++)
//					bag[i][j] = -10000000;
//			}
//			for (j = 0; j < 1200; j++)
//				bag[0][j] = 0;
//			for (i = 1; i <= c; i++)
//			{
//				for (j = mnum; j >= 1; j--)
//				{
//					for (k = mtime; k >= duoduo[i].time && k >= 0; k--)
//						bag[j][k] = (bag[j][k] > bag[j - 1][k - duoduo[i].time] + duoduo[i].value) ? bag[j][k] : (bag[j - 1][k - duoduo[i].time] + duoduo[i].value);
//				}
//			}
//			if (bag[mnum][mtime] < 0)
//				bag[mnum][mtime] = 0;
//			printf("%d\n", bag[mnum][mtime]);
//		}
//	}
//	return 0;
//}





//1059 多重背包，装一半能否恰好装满；
//#include <stdio.h>
//int main()
//{
//	int n, m, i, j, k, sum, bag[120010], ar[7], cas = 1;
//	while (scanf("%d %d %d %d %d %d", &ar[1], &ar[2], &ar[3], &ar[4], &ar[5], &ar[6]) != EOF && (ar[1] || ar[2] || ar[3] || ar[4] || ar[5] || ar[6]))
//	{
//		printf("Collection #%d:\n", cas++);
//		sum = ar[1] * 1 + ar[2] * 2 + ar[3] * 3 + ar[4] * 4 + ar[5] * 5 + ar[6] * 6;
//		if (sum % 2 != 0)
//		{
//			printf("Can't be divided.\n");
//			putchar('\n');
//			continue;
//		}
//		sum /= 2;
//		for (i = 1; i <= sum; i++)
//			bag[i] = -100000000;
//		bag[0] = 0;
//		for (i = 1; i <= 6; i++)
//		{
//			if (ar[i] == 0)
//				continue;
//			if (ar[i] * i >= sum)
//			{
//				for (j = i; j <= 120000; j++)
//					bag[j] = (bag[j] > bag[j - i] + i) ? bag[j] : (bag[j - i] + i);
//			}
//			else
//			{
//				k = 1;
//				while (k <= ar[i])
//				{
//					for (j = sum; j >= k*i; j--)
//						bag[j] = (bag[j] > bag[j - k*i] + k*i) ? bag[j] : (bag[j - k*i] + k*i);
//					ar[i] -= k;
//					k *= 2;
//				}
//				if (ar[i])
//					for (j = sum; j >= ar[i] * i; j--)
//						bag[j] = (bag[j] > bag[j - ar[i] * i] + ar[i] * i) ? bag[j] : (bag[j - ar[i] * i] + ar[i] * i);
//			}
//		}
//		if (bag[sum] > 0)
//			printf("Can be divided.\n");
//		else
//			printf("Can't be divided.\n");
//		
//		putchar('\n');
//	}
//
//	return 0;
//}



//3127 未过；
//#include <stdio.h>
//#include <string.h>
//struct cloth
//{
//	int x;
//	int y;
//	int s;
//	int value;
//};
//int main()
//{
//	int n, m, c, i, j, k, u, mx, my, bag[10100000], ms;
//	struct cloth girl[20];
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d %d", &c, &mx, &my);
//			ms = mx * my;
//			for (u = 1; u <= c; u++)
//			{
//				scanf("%d %d %d", &girl[u].x, &girl[u].y, &girl[u].value);
//				girl[u].s = girl[u].x * girl[u].y;
//			}
//			memset(bag, 0, sizeof(int) * 10100000);
//			for (i = 1; i <= c; i++)
//			{
//				for (j = ms; j >= girl[i].s; j--)
//				{
//					
//						bag[j] = (bag[j] > bag[j - girl[i].s] + girl[i].value) ? bag[j] : (bag[j - girl[i].x] + girl[i].value);
//					
//				}
//			}
//			printf("%d\n", bag[ms]);
//		}
//	}
//	return 0;
//}




//3535 未过; 
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//int comp(const void *a, const void *b);
//struct busy
//{
//	int time;
//	int happ;
//	double rate;
//};
//struct areyoubusy
//{
//	double mrate;
//	int mtimetem;
//	int mhapptem;
//	int n;
//	int judge;
//	struct busy B[110];
//};
//int main()
//{
//	int n, m, i, j, k, u, bag[99999], mtime, c;
//	struct areyoubusy A[110];
//	while (scanf("%d %d", &c, &mtime) != EOF)
//	{
//		for (n = 1; n <= c; n++)
//		{
//			scanf("%d %d", &A[n].n, &A[n].judge);
//			A[n].mrate = 0.0;
//			for (m = 1; m <= A[n].n; m++)
//			{
//				scanf("%d %d", &A[n].B[m].time, &A[n].B[m].happ);
//				/*if (A[n].judge == 0)
//				{
//					A[n].B[m].rate = (1.0*A[n].B[m].happ) / (1.0*A[n].B[m].time);
//					if (A[n].mrate < A[n].B[m].rate)
//					{
//						A[n].mrate = A[n].B[m].rate;
//						A[n].mtimetem = A[n].B[m].time;
//						A[n].mhapptem = A[n].B[m].happ;
//					}
//				}*/
//			}
//			if (A[n].judge == 0)
//			{
//				qsort(A, A[n].n, sizeof(struct busy), comp);
//			}
//		}
//		memset(bag, 0, sizeof(int) * 99999);
//		for (i = 1; i <= c; i++)
//		{
//			if (A[i].judge == 0)
//			{
//				for (k = mtime; k >= A[i].mtimetem; k--)
//					bag[k] = bag[k - A[i].mtimetem] + A[i].mhapptem;
//				for (j = 1; j <= A[i].n; j++)
//				{
//					if (A[i].B[j].time == A[i].mtimetem)
//						continue;
//					for (k = mtime; k >= A[i].B[j].time; k--)
//					{
//						bag[k] = (bag[k] > bag[k - A[i].B[j].time] + A[i].B[j].happ) ? bag[k] : (bag[k - A[i].B[j].time] + A[i].B[j].happ);
//					}
//				}
//			}
//			if (A[i].judge == 1)
//			{
//				for (k = mtime; k >= 0; k--)
//				{
//					for (j = 1; j <= A[i].n && k - A[i].B[j].time >= 0; j++)
//					{
//						bag[k] = (bag[k] > bag[k - A[i].B[j].time] + A[i].B[j].happ) ? bag[k] : (bag[k - A[i].B[j].time] + A[i].B[j].happ);
//					}
//				}
//			}
//			if (A[i].judge == 2)
//			{
//				for (j = 1; j <= A[i].n; j++)
//				{
//					for (k = mtime; k >= A[i].B[j].time; k--)
//					{
//						bag[k] = (bag[k] > bag[k - A[i].B[j].time] + A[i].B[j].happ) ? bag[k] : (bag[k - A[i].B[j].time] + A[i].B[j].happ);
//					}
//				}
//			}
//		}
//		if (bag[mtime] == 0)
//			printf("-1\n");
//		else
//			printf("%d\n", bag[mtime]);
//	}
//	return 0;
//}
//int comp(const void *a, const void *b)
//{
//	int i;
//	const struct areyoubusy *p1 = (const struct areyoubusy *)a;
//	const struct areyoubusy *p2 = (const struct areyoubusy *)b;
//	for (i = 1; i <= A[n].n; i++)
//	{
//
//	}
//}








//1003       if 要放到后面一起判断！！！；
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	int n, m, i, j, k, u, c, temp, ar[100010], r[100010], cas, maxi, maxj, b, e;
//	long long int max;
//	while (scanf("%d", &n) != EOF)
//	{
//		cas = 0;
//		for (m = 1; m <= n; m++)
//		{
//			cas++;
//			scanf("%d", &c);
//			for (i = 1; i <= c; i++)
//			{
//				scanf("%d", &ar[i]);
//			}
//			
//			max = -1000000;
//			r[0] = 0;
//			b = 1;
//			for (i = 1; i <= c; i++)
//			{
//				if (ar[i] > r[i - 1] + ar[i])
//				{
//					r[i] = ar[i];
//					e = i;
//					b = i;
//				}
//				else
//				{
//					r[i] = r[i - 1] + ar[i];
//					e = i;
//				}
//				if (max < r[i])
//				{
//					max = r[i];
//					maxi = e;
//					maxj = b;
//				}
//			}
//			printf("Case %d:\n", cas);
//			printf("%lld %d %d\n", max, maxj, maxi);
//			if(m != n)
//				putchar('\n');
//		}
//	}
//	return 0;
//}









//1160 mouse's speed   special judge  终于过了；   qsort模板；
//第一个for遍历每一个老鼠i作为开头， 第二个for是每一个作为开头的老鼠i的下一个是j，那么num【i】= num【j】+1；
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//int comp(const void * p1, const void * p2);
//struct mice
//{
//	int speed;
//	int wei;
//	int index;
//	int doudou;
//};
//
//int main()
//{
//	int n, m, i, j, k, u, sum, max, num[1010], maxi, b[1010], e;
//	struct mice mouse[1010];
//
//	n = 1;
//	while (scanf("%d %d", &mouse[n].wei, &mouse[n].speed) != EOF)
//	{
//		mouse[n].index = n;
//		mouse[n].doudou = 0;
//		n++;
//	}
//	qsort(&mouse[1], (n - 1), sizeof(struct mice), comp);
//	for (i = 0; i < 1010; i++)
//	{
//		b[i] = i;
//		num[i] = 1;
//	}
//	max = 0;
//	for (i = n-1; i >= 1; i--)
//	{
//		for (j = n-1; j > i; j--)
//		{
//			if (mouse[i].wei < mouse[j].wei && mouse[i].speed > mouse[j].speed && num[i] < num[j] + 1)
//			{
//				num[i] = num[j] + 1;
//				b[i] = j;
//			}
//		}
//		if (max < num[i])
//		{
//			max = num[i];
//			maxi = i;
//		}
//	}
//	printf("%d\n", max);
//	for (i = maxi; b[i] != i; i=b[i])
//	{
//		printf("%d\n", mouse[i].index);
//	}
//	printf("%d\n", mouse[i].index);
//	return 0;
//}
//
//int comp(const void * p1, const void * p2)
//{
//	const struct mice * a1 = (const struct mice *)p1;
//	const struct mice * a2 = (const struct mice *)p2;
//
//	if (a1->wei != a2->wei)
//		return a1->wei - a2->wei;
//	else
//		return a2->speed - a1->speed;
//}






//1087  现在看来就是水题一道，hhh；
//遍历每一个作为开头，遍历每一个开头的下一个， 找出最大和；
//#include <stdio.h>
//int main()
//{
//	int n, m, i, j, k, ar[1010];
//	long long sum[1010], max;
//	while (scanf("%d", &n) != EOF && n != 0)
//	{
//		for (i = 1; i <= n; i++)
//			scanf("%d", &ar[i]);
//		for (i = 1; i < 1010; i++)
//			sum[i] = ar[i];
//		max = 0;
//
//		for (i = n; i >= 1; i--)
//		{
//			for (j = n; j > i; j--)
//			{
//				if (ar[i] < ar[j] && sum[i] < ar[i] + sum[j])
//					sum[i] = ar[i] + sum[j];
//			}
//			if (max < sum[i])
//				max = sum[i];
//		}
//		printf("%lld\n", max);
//	}
//	return 0;
//}







//1176   注意数组的左右，上下边界啊；
//#include <stdio.h>
//#include <string.h>
//int max(int a, int b, int c)
//{
//	if (a > b)
//	{
//		if (a > c)
//			return a;
//		else
//			return c;
//	}
//	else
//	{
//		if (b > c)
//			return b;
//		else
//			return c;
//	}
//}
//int main()
//{
//	int n, m, i, j, x, t, mtime, msum, k, u, ar[13][100010], s[13][100010];
//	while (scanf("%d", &n) != EOF && n != 0)
//	{
//		memset(ar, 0, sizeof(int) * 13 * 100010);
//		mtime = 0;
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d", &x, &t);
//			mtime = (mtime > t) ? mtime : t;
//			ar[x][t]++;
//		}
//		for (x = 0; x <= 11; x++)
//			s[x][mtime+1] = 0;
//
//		for (t = mtime; t > 0; t--)
//		{
//			for (x = 0; x <= 10; x++)
//			{
//				if (x == 0)
//				{
//					s[x][t] = ((s[x][t + 1] + ar[x][t]) > (s[x + 1][t + 1] + ar[x + 1][t])) ? (s[x][t + 1] + ar[x][t]) : (s[x + 1][t + 1] + ar[x + 1][t]);
//					continue;
//				}
//				s[x][t] = max((ar[x - 1][t] + s[x - 1][t +1]), (ar[x][t] + s[x][t + 1]), (ar[x + 1][t] + s[x + 1][t + 1]));
//			}
//		}
//
//		printf("%d\n", s[5][1]);
//	}
//	return 0;
//}




//1257  
//#include <stdio.h>
//int main()
//{
//	int n, m, i, j, count, ar[30001], num[30001];
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &ar[m]);
//			num[m] = 1;
//		}
//		for (i = n; i >= 1; i--)
//		{
//			for (j = n; j > i; j--)
//			{
//				if (ar[i] < ar[j] && num[i] < num[j] + 1)
//				{
//					num[i] = num[j] + 1;
//				}
//			}
//			
//		}
//		count = 0;
//		for (i = 1; i <= n; i++)
//			if (count < num[i])
//				count = num[i];
//		printf("%d\n", count);
//	}
//	return 0;
//}





//#include <stdio.h>
//#include <stdlib.h>
//int comp(const void * p1, const void * p2);
//int main()
//{
//	int n, m, i, j, k, u, x, y, bag[2005][1005], ar[2005];
//	while (scanf("%d %d", &n, &m) != EOF)
//	{
//		for (x = 1; x <= n; x++)
//		{
//			scanf("%d", &ar[x]);
//		}
//		ar[0] = 0;
//		qsort(&ar[1], n, sizeof(int), comp);
//		for (i = 0; i <= n; i++)
//			for (j = 1; j <= m; j++)
//				bag[i][j] = 2147483640;
//
//		bag[0][0] = 0;
//		 
//		for (i = 2; i <= n; i++)
//		{
//			for (j = 1; j * 2 <= i; j++)
//			{
//				bag[i][j] = (bag[i - 1][j] < (bag[i - 2][j - 1] + (ar[i] - ar[i - 1])*(ar[i] - ar[i - 1]))) ? bag[i - 1][j] : (bag[i - 2][j - 1] + (ar[i] - ar[i - 1])*(ar[i] - ar[i - 1]));
//			}
//		}
//		printf("%d\n", bag[n][m]);
//	}
//	return 0;
//}
//int comp(const void * p1, const void * p2)
//{
//	return *(int *)p1 - *(int *)p2;
//}
//
//


//未过； 
//#include <stdio.h>  
//#include <stdlib.h>  
//#define size 2005  
//#define INIT 2147483646  
//
//int cmp(const void *a, const void *b)
//{
//	return *(int *)a - *(int *)b;
//}
//
//int Min(int a, int b)
//{
//	return a<b ? a : b;
//}
//
//int dp[size][1005];
//
//int main()
//{
//	int n, k, i, j;
//	int val[size] = { 0 };
//	dp[0][0] = 0;
//	while (scanf("%d%d", &n, &k) != EOF)
//	{
//		val[0] = 0;
//		for (i = 1; i <= n; i++)
//			scanf("%d", &val[i]);
//		qsort(val + 1, n, sizeof(val[0]), cmp);
//		for (i = 0; i <= n; i++)
//		{
//			for (j = 1; j <= k; j++)
//				dp[i][j] = INIT;
//		}
//		for (i = 2; i <= n; i++)
//		{
//			for (j = 1; j * 2 <= i; j++)
//				dp[i][j] = Min(dp[i - 2][j - 1] + (val[i] - val[i - 1])*(val[i] - val[i - 1]), dp[i - 1][j]);
//		}
//		printf("%d\n", dp[n][k]);
//	}
//	return 0;
//}





//1305  字典树第一题， 只创建树就行了，不用查找；
//#include <stdio.h>
//#include <stdlib.h>
//struct binary
//{
//	int sta;
//	struct binary* next[2];
//};
//int insert(struct binary *root, char *ar);
//
//int main()
//{
//	int i, doudou = 0, cas = 0;
//	char ar[50];
//	struct binary *root = (struct binary *)malloc(sizeof(struct binary));
//	for (i = 0; i < 2; i++)
//	{
//		root->next[i] = NULL;
//	}
//	root -> sta = 0;
//	while (scanf("%s", ar) != EOF)
//	{
//		if (ar[0] == '9')
//		{
//			cas++;
//			if (doudou == 0)
//				printf("Set %d is immediately decodable\n", cas);
//			else
//				printf("Set %d is not immediately decodable\n", cas);
//			continue;
//		}
//		getchar();
//
//		if (insert(root, ar))
//			doudou = 1;
//		else
//			doudou = 0;
//	}
//
//
//	return 0;
//}
//
//int insert(struct binary *root, char *ar)
//{
//	int i, doudou = 0;
//	struct binary *p, *temp;
//	p = root;
//
//	while (*ar != '\0')
//	{
//		if (p->next[*ar - '0'] == NULL)
//		{
//			if (p->sta == 1)
//				doudou = 1;
//			temp = (struct binary *)malloc(sizeof(struct binary));
//			for (i = 0; i < 2; i++)
//				temp->next[i] = NULL;
//			temp->sta = 0;
//			p->next[*ar - '0'] = temp;
//		}
//		else
//		{
//			if (*(ar + 1) == '\0')
//				doudou = 1;
//		}
//		p = p->next[*ar - '0'];
//		ar++;
//	}
//	p->sta = 1;
//	return doudou;
//}





//1251   字典树第二题，不能在结构体内初始化变量；
//#include <stdio.h>
//#include <stdlib.h>
//struct pre
//{
//	int count;
//	struct pre *next[26];
//};
//void insert(struct pre *root, char *ar);
//int search(struct pre *root, char *ar);
//void del(struct pre *root);
//int main()
//{
//	int i, j, n, m;
//	char ar[11];
//	struct pre * root;
//	root = (struct pre *)malloc(sizeof(struct pre));
//	for (i = 0; i < 26; i++)
//	{
//		root->next[i] = NULL;
//	}
//	root->count = 0;
//	while (gets(ar) != NULL && ar[0] != '\0')
//	{
//		insert(root, ar);
//	}
//	while (gets(ar) != NULL && ar[0] != '\0')
//	{
//		printf("%d\n", search(root, ar));
//	}
//	del(root);
//	return 0;
//}
//
//void insert(struct pre *root, char *ar)
//{
//	int i, c;
//	struct pre *p = root, *temp;
//	while (*ar != '\0')
//	{
//		if (p->next[*ar - 'a'] == NULL)
//		{
//			temp = (struct pre *)malloc(sizeof(struct pre));
//			for (i = 0; i < 26; i++)
//			{
//				temp->next[i] = NULL;
//			}
//			temp->count = 0;
//			p->next[*ar - 'a'] = temp;
//		}
//		p = p->next[*ar - 'a'];
//		p->count++;
//		ar++;
//	}
//}
//
//int search(struct pre *root, char *ar)
//{
//	int i;
//	struct pre *p = root;
//	while (*ar != '\0' && p != NULL)
//	{
//		p = p->next[*ar - 'a'];
//		if (*(ar + 1) == '\0' && p != NULL)
//			return p->count;
//		ar++;
//	}
//	if (p == NULL)
//		return 0;
//}
//
//void del(struct pre *root)
//{
//	int i;
//	for (i = 0; i < 26; i++)
//	{
//		if (root->next[i] != NULL)
//			del(root->next[i]);
//	}
//	free(root);
//}



//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	int i, j, k, u, n, m, count, L;
//	char ar[1100];
//	while (gets(ar) != NULL && ar[0] != '#')
//	{
//		count = 0;
//		L = strlen(ar);
//		for (i = 0; i < L - 1; i++)
//			if (ar[i] == '1')
//				count++;
//		if (count % 2 == 0 && ar[L - 1] == 'f')
//		{
//			ar[L - 1] = '0';
//			puts(ar);
//		}
//		else if (count % 2 == 0 && ar[L - 1] == 'u')
//		{
//			ar[L - 1] = '1';
//			puts(ar);
//		}
//		else if (count % 2 != 0 && ar[L - 1] == 'f')
//		{
//			ar[L - 1] = '1';
//			puts(ar);
//		}
//		else
//		{
//			ar[L - 1] = '0';
//			puts(ar);
//		}
//	}
//	return 0;
//}



//#include <stdio.h>
//int main()
//{
//	unsigned long long sum, k, n, m, i;
//	while (scanf("%llu", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			sum = 0;
//			scanf("%llu", &k);
//			sum = (k / 10) * 45;
//			for (i = 1; i <= (k % 10); i++)
//			{
//				sum += (i *i) % 10;
//			}
//			printf("%llu\n", sum);
//		}
//	}
//	return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//int comp(const void * p1, const void * p2);
//int main()
//{
//	int n, m, i, k, j, u;
//	long long ar[1000005];
//	while (scanf("%d %d %d", &n, &m, &k) != EOF)
//	{
//		for (i = 1; i <= n; i++)
//			scanf("%lld", &ar[i]);
//		qsort(&ar[1], n, sizeof(int), comp);
//		if ((k*(k - 1) / 2) + m > ar[1])
//			printf("Yes\n");
//		else
//			printf("Impossible\n");
//	}
//	return 0;
//}
//
//int comp(const void * p1, const void * p2)
//{
//	return *(int *)p2 - *(int *)p1;
//}


//#include <stdio.h>
//#include <math.h>
//int main()
//{
//	int n, m, u, ip, ic, j, k, xp, yp, x1, y1, x2, y2, cas;
//	double S;
//	while (scanf("%d", &n) != EOF)
//	{
//		cas = 0;
//		for (m = 1; m <= n; m++)
//		{
//			cas++;
//			scanf("%d", &k);
//			xp = 0;
//			yp = 0;
//			S = 0.0;
//			for (u = 1; u <= k; u++)
//			{
//
//				scanf("%d", &ic);
//				if (ic == 1)
//				{
//					scanf("%d %d", &x1, &y1);
//					S += pow((x1 - xp)*(x1 - xp) + (y1 - yp)*(y1 - yp), 0.5);
//					xp = x1;
//					yp = y1;
//					ip = ic;
//				}
//				else if (ic == 2)
//				{
//					scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
//					S += pow((x1 - xp)*(x1 - xp) + (y1 - yp)*(y1 - yp), 0.5);
//					S += pow((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2), 0.5);
//					xp = x2;
//					yp = y2;
//					ip = ic;
//				}
//				else
//				{
//					scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
//					S += pow((x1 - xp)*(x1 - xp) + (y1 - yp)*(y1 - yp), 0.5);
//					S += pow((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2), 0.5);
//					S += pow((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2), 0.5);
//					xp = x1;
//					yp = y1;
//					ip = ic;
//				}
//			}
//			printf("Case %d: %.6lf\n", cas, S);
//		}
//	}
//	return 0;
//}






//1671   字典树第三题，和第一题类似
//#include <stdio.h>
//#include <stdlib.h>
//
//struct phone
//{
//	int sta;
//	struct phone *next[10];
//};
//int insert(struct phone *root, char *s);
//void del(struct phone *root);
//int main()
//{
//	int i, j, k, m, n, u, doudou;
//	char ar[10005];
//	struct phone *root;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &k);
//			root = (struct phone *)malloc(sizeof(struct phone));
//			for (i = 0; i < 10; i++)
//				root->next[i] = NULL;
//			root->sta = 0;
//			doudou = 1;
//			for (u = 1; u <= k; u++)
//			{
//				scanf("%s", ar);
//				if (doudou == 1 && insert(root, ar))
//					doudou = 1;
//				else
//					doudou = 0;
//			}
//			if (doudou)
//				printf("YES\n");
//			else
//				printf("NO\n");
//			del(root);
//		}
//
//	}
//	return 0;
//}
//
//int insert(struct phone *root, char *s)
//{
//	struct phone *p = root, *temp;
//	int i, doudou = 1;
//	while (*s != '\0')
//	{
//		if (p->next[*s - '0'] == NULL)
//		{
//			if (p->sta == 1)
//				doudou = 0;
//			temp = (struct phone *)malloc(sizeof(struct phone));
//			for (i = 0; i < 10; i++)
//				temp->next[i] = NULL;
//			temp->sta = 0;
//			p->next[*s - '0'] = temp;
//
//		}
//		else
//		{
//			if (*(s + 1) == '\0')
//				doudou = 0;
//		}
//		p = p->next[*s - '0'];
//		s++;
//	}
//	p->sta = 1;
//	return doudou;
//}
//
//void del(struct phone *root)
//{
//	int i;
//	for (i = 0; i< 10; i++)
//	{
//		if (root->next[i] != NULL)
//			del(root->next[i]);
//	}
//	free(root);
//}







//
//#include <stdio.h>
//int main()
//{
//	int i, j, k, n, m, u, ar[100000];
//	long long S;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &k);
//			S = 0;
//			for (u = 1; u <= k; u++)
//			{
//				scanf("%d", &ar[u]);
//				if (ar[u] % 2 == 0)
//					S += ar[u];
//				else
//					S -= ar[u];
//			}
//			printf("%lld\n", S);
//		}
//	}
//	return 0;
//}




//#include <stdio.h>
//#include <stdlib.h>
//int comp(const void * p1, const void * p2);
//int main()
//{
//	int i, j, k, u, n, m;
//	long long ar[1005], count;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &k);
//			for (u = 1; u <= k; u++)
//			{
//				scanf("%lld", &ar[u]);
//
//			}
//			qsort(&ar[1], k, sizeof(long long int), comp);
//			count = 0;
//			for (i = 1; i < k; i++)
//				if (ar[i] != ar[i + 1])
//					count++;
//			printf("%lld\n", count+1);
//		}
//	}
//}
//
//int comp(const void * p1, const void * p2)
//{
//	return *(long long *)p1 - *(long long *)p2;
//}
//





//#include <stdio.h>
//int main()
//{
//	int i, j, k, u, n, m;
//	unsigned long long a, b, c, S, t;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%llu %llu %llu", &a, &b, &c);
//			if (a < b)
//			{
//				t = a;
//				a = b;
//				b = t;
//			}
//			S = 0;
//			a = a%c;
//			b = b %c;
//			while (a > 0)
//			{
//				if (a % 2 != 0)
//				{
//					S += b%c;
//				}
//				a /= 2;
//				b *= 2;
//				b %= c;
//			}
//			printf("%llu\n", S%c);
//		}
//	}
//	return 0;
//}
//





//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int main()
//{
//	char ar[40005], sa[40005], ar0[40005], sa0[40005], temp[40005];
//	int i, j, k, n, m, u, L1, L2;
//
//
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%s", ar);
//			scanf("%s", sa);
//			L1 = strlen(ar);
//			L2 = strlen(sa);
//			strcpy(ar0, ar);
//			strcpy(sa0, sa);
//
//			for (i = 1; i <= L1; i++)
//			{
//				temp[0] = ar[L1 - 1];
//				strcat(temp, ar);
//				temp[L1 - 1] = '\0';
//				strcpy(ar, temp);
//				if (strcmp(ar0, ar) < 0)
//					strcpy(ar0, ar);
//			}
//			for (i = 1; i <= L2; i++)
//			{
//				temp[0] = sa[L2 - 1];
//				strcat(temp, sa);
//				temp[L2 - 1] = '\0';
//				strcpy(sa, temp);
//				if (strcmp(sa0, sa) < 0)
//					strcpy(sa0, sa);
//			}
//			if (strcmp(ar0, sa0) < 0)
//				printf("dd\n");
//			else if (strcmp(ar0, sa0) == 0)
//				printf("ddbb\n");
//			else
//				printf("bb\n");
//		}
//	}
//	return 0;
//}



//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//struct aa
//{
//	char a[40005];
//};
//int main()
//{
//	char temp;
//	struct aa ar, sa, ar0, sa0;
//	int i, j, k, n, m, u, L1, L2;
//
//
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%s", ar.a);
//			scanf("%s", sa.a);
//			L1 = strlen(ar.a);
//			L2 = strlen(sa.a);
//			ar0 = ar;
//			sa0 = sa;
//
//			for (i = 1; i <= L1; i++)
//			{
//				for (j = 0; j <= L1 / 2; j++)
//				{
//					temp = ar.a[j];
//					ar.a[j] = ar.a[L1 - j - 1];
//					ar.a[L1 - 1 - j] = temp;
//				}
//				if (strcmp(ar0.a, ar.a) < 0)
//					ar0 = ar;
//			}
//			for (i = 1; i <= L2; i++)
//			{
//				for (j = 0; j <= L2 / 2; j++)
//				{
//					temp = sa.a[j];
//					sa.a[j] = sa.a[L2 - j - 1];
//					sa.a[L2 - 1 - j] = temp;
//				}
//				if (strcmp(sa0.a, sa.a) < 0)
//					sa0 = sa;
//			}
//			if (strcmp(ar0.a, sa0.a) < 0)
//				printf("dd\n");
//			else if (strcmp(ar0.a, sa0.a) == 0)
//				printf("ddbb\n");
//			else
//				printf("bb\n");
//		}
//	}
//	return 0;
//}






//1075  字典树第四题 用strcmp比较结束标志，指针只是门牌号的纸，不往上写号码怎么行？
//#include <stdio.h>
//#include <ctype.h>
//#include <string.h>
//#include <stdlib.h>
//struct dict
//{
//	int sta;
//	struct dict *next[26];
//	char sg[15];
//};
//void insert(struct dict *root, char *s, char *f);
//void search(struct dict *root, char *s);
//void del(struct dict *root);
//
//int main()
//{
//	int i, j, k, u, n, m, L;
//	struct dict *root;
//	char ar[10000000], *p;
//	char sa[15], sd[15], sf[15];
//	root = (struct dict *)malloc(sizeof(struct dict));
//	for (i = 0; i < 26; i++)
//		root->next[i] = NULL;
//	root->sta = 0;
//
//	scanf("%s", sd);
//	while (scanf("%s", sa) != EOF && strcmp(sa, "END") != 0)
//	{
//		scanf("%s", sd);
//		insert(root, sd, sa);
//	}
//	scanf("%s", sd);
//	getchar();
//	while(fgets(ar,10000000, stdin) != NULL && strcmp(ar, "END\n") != 0)
//	{
//		j = 0;
//		L = strlen(ar);
//		for (i = 0; i < L; i++)
//		{
//			if (isalpha(ar[i]))
//			{
//				sf[j] = ar[i];
//				j++;
//			}
//			else
//			{
//				sf[j] = '\0';
//				search(root, sf);
//				putchar(ar[i]);
//				j = 0;
//			}
//		 }
//	}
//	del(root);
//	return 0;
//}
//void del(struct dict *root)
//{
//	int i;
//	for (i = 0; i < 26; i++)
//	{
//		if (root->next[i] != NULL)
//			del(root->next[i]);
//	}
//	free(root);
//}
//void insert(struct dict *root, char *s, char *f)
//{
//	int i, j;
//	struct dict *temp, *p = root;
//	char *q = f;
//	while (*s != '\0')
//	{
//		if (p->next[*s - 'a'] == NULL)
//		{
//			temp = (struct dict *)malloc(sizeof(struct dict));
//			for (i = 0; i < 26; i++)
//				temp->next[i] = NULL;
//			temp->sta = 0;
//
//			p->next[*s - 'a'] = temp;
//		}
//		p = p->next[*s - 'a'];
//		s++;
//	}
//	p->sta = 1;
//	strcpy(p->sg, q);
//}
//void search(struct dict *root, char *s)
//{
//	int i;
//	struct dict *p = root;
//	char *q = s;
//	while (*q != '\0' && p != NULL)
//	{
//		p = p->next[*q - 'a'];
//		q++;
//	}
//	if (p != NULL && p->sta == 1)
//		printf("%s", p->sg);
//	else if(*s != '\0')
//		printf("%s", s);
//}






//3460 字典树第5题，他输完一个名字必须删了才能输下一个，只是有的不用删完；公式：创建次数*2 - 最长字符串长度 + 字符串数； 
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//struct print
//{
//
//	struct print * next[26];
//};
//void insert(struct print * root, char *s, long long int *S);
//void del(struct print *root);
//int main()
//{
//	int i, j, n, m, L, maxl;
//	char ar[55];
//	long long sum, *S;
//	struct print *root;
//	while (scanf("%d", &n) != EOF)
//	{
//		sum = 0;
//		maxl = 0;
//		S = &sum;
//		root = (struct print *)malloc(sizeof(struct print));
//		for (i = 0; i < 26; i++)
//			root->next[i] = NULL;
//
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%s", ar);
//			if (maxl < (L = strlen(ar)))
//				maxl = L;
//			insert(root, ar, S);
//		}
//		printf("%lld\n", sum - maxl + n);
//		del(root);
//	}
//
//	return 0;
//}
//void del(struct print *root)
//{
//	int i;
//	for (i = 0; i < 26; i++)
//		if (root->next[i] != NULL)
//			del(root->next[i]);
//	free(root);
//}
//void insert(struct print * root, char *s, long long  int *S)
//{
//	int i;
//	struct print *temp, *p = root;
//	while (*s != '\0')
//	{
//		if (p->next[*s - 'a'] == NULL)
//		{
//			temp = (struct print *)malloc(sizeof(struct print));
//			for (i = 0; i < 26; i++)
//				temp->next[i] = NULL;
//			*S += 2;
//			p->next[*s - 'a'] = temp;
//		}
//		p = p->next[*s - 'a'];
//		s++;
//	}
//}




//2072      字典树第六题   坑啊， # 后面还有一大堆东西也要结束，不能用strcmp（这题没有出现，一大堆东西之后不换行再输一个#， 要先处理再结束）
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <ctype.h>
//struct lily
//{
//	int sta;
//	struct lily *next[26];
//
//};
//int insert(struct lily * root, char *s);
//void del(struct lily *root);
//int main()
//{
//	int i, j;
//	int L, count;
//	char ar[10000000], sf[10000];
//	struct lily *root;
//	while (fgets(ar, 10000000, stdin) != NULL && ar[0] != '#')
//	{
//		root = (struct lily *)malloc(sizeof(struct lily));
//		root->sta = 1;
//		for (i = 0; i < 26; i++)
//			root->next[i] = NULL;
//		L = strlen(ar);
//		j = 0;
//		count = 0;
//		for (i = 0 ;ar[i] != '\0'; i++)
//		{
//			if (isalpha(ar[i]))
//			{
//				sf[j] = ar[i];
//				j++;
//			}
//			else
//			{
//				sf[j] = '\0';
//				if (insert(root, sf) == 1)
//					count++;
//				j = 0;
//			}
//		}
//		printf("%d\n", count);
//		del(root);
//	}
//	return 0;
//}
//
//int insert(struct lily * root, char *s)
//{
//	int i;
//	struct lily *p = root, *temp;
//	while (*s != '\0')
//	{
//		if (p->next[*s - 'a'] == NULL)
//		{
//			temp = (struct lily *)malloc(sizeof(struct lily));
//			temp->sta = 0;
//			for (i = 0; i < 26; i++)
//				temp->next[i] = NULL;
//			p->next[*s - 'a'] = temp;
//
//		}
//		p = p->next[*s - 'a'];
//		s++;
//	}
//	if (p->sta == 1)
//		return 0;
//	else
//	{
//		p->sta = 1;
//		return 1;
//	}
//}
//
//void del(struct lily *root)
//{
//	int i;
//	for (i = 0; i < 26; i++)
//	{
//		if (root->next[i] != NULL)
//			del(root->next[i]);
//	}
//	free(root);
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <ctype.h>
//struct lily
//{
//	int sta;
//	struct lily *next[26];
//
//};
//int insert(struct lily * root, char *s);
//void del(struct lily *root);
//int main()
//{
//	int i, j, L, count;
//	char ar[100000], sf[100];
//	struct lily *root;
//	while (fgets(ar, 100000, stdin) != NULL && ar[0] != '#')
//	{
//		root = (struct lily *)malloc(sizeof(struct lily));
//		root->sta = 0;
//		for (i = 0; i < 26; i++)
//			root->next[i] = NULL;
//		L = strlen(ar);
//		j = 0;
//		count = 0;
//		for (i = 0; i < L; i++)
//		{
//			if (isalpha(ar[i]))
//			{
//				sf[j] = ar[i];
//				j++;
//			}
//			else
//			{
//				sf[j] = '\0';
//				if (insert(root, sf) == 1)
//					count++;
//				j = 0;
//			}
//		}
//		printf("%d\n", count);
//		del(root);
//	}
//	
//	return 0;
//}
//void del(struct lily *root)
//{
//	int i;
//	for (i = 0; i < 26; i++)
//	{
//		if (root -> next[i] != NULL)
//			del(root->next[i]);
//	}
//	free(root);
//}
//
//int insert(struct lily * root, char *s)
//{
//	int i;
//	struct lily *p = root, *temp;
//	while (*s != '\0')
//	{
//		if (p->next[*s - 'a'] == NULL)
//		{
//			temp = (struct lily *)malloc(sizeof(struct lily));
//			temp->sta = 0;
//			for (i = 0; i < 26; i++)
//				temp->next[i] = NULL;
//			p->next[*s - 'a'] = temp;
//
//		}
//		p = p->next[*s - 'a'];
//		s++;
//
//	}
//	if (p->sta == 1 || p == root)
//		return 0;
//	else
//	{
//		p->sta = 1;
//		return 1;
//	}
//}






//1247   字典树第七题，注意 不要使用 空指针和'\0'，会runtime error；
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <ctype.h>
//struct hat
//{
//	int sta;
//	struct hat *next[26];
//};
//void insert(struct hat * root, char *s);
//int search(struct hat * root, char *s);
//int search1(struct hat * root, char *s);
//void del(struct hat *root);
//
//int main()
//{
//	int i, n = 0;
//	struct hat *root;
//	char ar[50005][100];
//
//	root = (struct hat *)malloc(sizeof(struct hat));
//	root->sta = 0;
//	for (i = 0; i < 26; i++)
//		root->next[i] = NULL;
//	while (scanf("%s", ar[n]) != EOF)
//	{
//		insert(root, ar[n]);
//		n++;
//	}
//	for (i = 0; i < n; i++)
//	{
//		if (search(root, ar[i]) == 1)
//		{
//			printf("%s", ar[i]);
//			putchar('\n');
//		}
//	}
//	del(root);
//	return 0;
//}
//void del(struct hat *root)
//{
//	int i;
//	for (i = 0; i < 26; i++)
//		if (root->next[i] != NULL)
//			del(root->next[i]);
//	free(root);
//}
//
//void insert(struct hat *root, char *s)
//{
//	int i;
//	struct hat *p = root, *temp;
//	while (*s != '\0')
//	{
//		if (p->next[*s - 'a'] == NULL)
//		{
//			temp = (struct hat *)malloc(sizeof(struct hat));
//			temp->sta = 0;
//			for (i = 0; i < 26; i++)
//				temp->next[i] = NULL;
//			p->next[*s - 'a'] = temp;
//		}
//		p = p->next[*s - 'a'];
//		s++;
//	}
//	p->sta = 1;
//}
//
//int search(struct hat *root, char *s)
//{
//	int i;
//	struct hat *p = root;
//	char * q = s;
//	while (*(q + 1) != '\0' && p->next[*q - 'a'] != NULL)
//	{
//		p = p->next[*q - 'a'];
//		q++;
//		if (p->sta == 1 && search1(root, q) == 1)
//			return 1;
//		
//	}
//	return 0;
//}
//
//int search1(struct hat *root, char *s)
//{
//	int i;
//	struct hat *p = root;
//	char * q = s;
//	while (*q != '\0' && p != NULL)
//	{
//		p = p->next[*q - 'a'];
//		q++;
//	}
//	if (p != NULL && p->sta == 1)
//		return 1;
//	return 0;
//}







//2846 字典树第八题， 用c++提交能过；
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//struct goods
//{
//	int sta;
//	int num;
//	int id;
//	struct goods *next[26];
//
//};
//void insert(struct goods *root, char *s, int n);
//int search(struct goods *root, char *s);
//void del(struct goods *root);
//int main()
//{
//	int i, j, n, m, k, u, L, count;
//	char ar[30], sa[30];
//	struct goods *root;
//	root = (struct goods *)malloc(sizeof(struct goods));
//	root->sta = 0;
//	root->num = 0;
//	root->id = -1;
//	for (i = 0; i<26; i++)
//		root->next[i] = NULL;
//	scanf("%d", &n);
//	for (m = 0; m < n; m++)
//	{
//		scanf("%s", ar);
//		L = strlen(ar);
//		for(i = 0; i < L; i++)
//			insert(root, &ar[i], m);
//	}
//	scanf("%d", &k);
//	for (u = 0; u < k; u++)
//	{		
//		scanf("%s", sa);	
//		printf("%d\n", search(root, sa));
//	}
//	del(root);
//	return 0;
//}
//
//void del(struct goods *root)
//{
//	int i;
//	for (i = 0; i < 26; i++)
//		if (root->next[i] != NULL)
//			del(root->next[i]);
//	free(root);
//}
//
//void insert(struct goods *root, char *s, int n)
//{
//	int i;
//	struct goods *p = root, *temp;
//	while (*s != '\0')
//	{
//		if (p->next[*s - 'a'] == NULL)
//		{
//			temp = (struct goods *)malloc(sizeof(struct goods));
//			temp->sta = 0;
//			temp->num = 1;
//			temp->id = n;
//			for (i = 0; i < 26; i++)
//				temp->next[i] = NULL;
//			p->next[*s - 'a'] = temp;
//		}
//		p = p->next[*s - 'a'];
//		if (p->id != n)
//		{
//			p->num++;
//			p->id = n;
//		}
//		s++;
//	}
//	p->sta = 1;
//}
//
//int search(struct goods *root, char *s)
//{
//	int i, count = 0;
//	struct goods *p = root;
//	while (*s != '\0' && p != NULL)
//	{
//		p = p->next[*s - 'a'];
//		s++;
//	}
//	if (p != NULL)
//		return p->num;
//	return 0;
//}











//#include <stdio.h>
//int main()
//{
//	int i, j, n, m;
//	char ar[1005];
//	while (fgets(ar, 1005, stdin) != NULL)
//	{
//		n = 0;
//		for (i = 0; ar[i] != '\0'; i++)
//		{
//			if (ar[i] == 'a')
//			{
//				n++;
//			}
//		}
//		if (n % 3 == 0)
//			printf("yes\n");
//		else
//			printf("no\n");
//	}
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//int main()
//{
//	int i, j, k, u, n, m, L, p, q;
//	char ar[27], x, y;
//	while (scanf("%d", &n) != EOF)
//	{
//		getchar();
//		scanf("%s", ar);
//		getchar();
//		scanf("%d", &k);
//		getchar();
//		for (u = 1; u <= k; u++)
//		{
//			scanf("%c", &x);
//			getchar();
//			scanf("%c", &y);
//			getchar();
//			for (i = 0; i < n; i++)
//			{
//				if (ar[i] == x)
//					p = i;
//				if (ar[i] == y)
//					q = i;
//			}
//			if (p > q)
//				printf("After\n");
//			else
//				printf("Before\n");
//		}
//		
//	}
//	return 0;
//}




//#include <stdio.h>
//int main()
//{
//	int i, j, k, n, m, x, y, doudou;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d", &x, &y);
//			for (i = 0; i <= 100; i++)
//			{
//				if (x * (100 - y) + i * y >= 6000)
//				{
//					break;
//				}
//			
//			}
//			if (i <= 100)
//				printf("%d\n", i);
//			else
//				printf("poor guy\n");
//		}
//	}
//	return 0;
//}




//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <math.h>
//
//int main()
//{
//	int i, j, k, u, n, m, a, b;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d %d", &a, &b, &k);
//			printf("%.3lf\n", 1.0 * b / (1.0 * (a+b)));
//		}
//	}
//	return 0;
//}






//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//#include <math.h>
//
//int main()
//{
//	int i, j, k, u, n, m, x, y, q, doudou = 0, dodo = 0;
//	double ar[1000010];
//	long long num;
//	double ave, max, min;
//	char sa[10];
//	while (scanf("%d", &n) != EOF)
//	{
//		doudou = 0;
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%lf", &ar[m]);
//		}
//		num = n;
//		scanf("%d", &q);
//		
//		for (u = 1; u <= q; u++)
//		{
//			scanf("%s", sa);
//			if (strcmp(sa, "Query") == 0)
//			{
//				ave = 0.0;
//				max = 0.0;
//				min = 10000000.0;
//				for (i = 1; i <= num; i++)
//				{
//					ave += ar[i];
//					max = (max < ar[i]) ? ar[i] : max;
//					min = (min > ar[i]) ? ar[i] : min;
//				}
//				if (doudou == 0 && dodo == 1)
//				{
//					putchar('\n');
//
//					doudou = 1;
//				}
//
//				printf("%.2lf\n", (ave-max-min)/(num-2));
//			}
//			else
//			{
//				scanf("%d", &k);
//				for (j = 1; j <= k; j++)
//				{
//					scanf("%lf", &ar[num + j]);
//				}
//				num += k;
//			}
//		}
//		dodo = 1;
//	}
//	return 0;
//}




//#include <stdio.h>
//
//int main()
//{
//	unsigned long long i, j, k, u, m, n;
//	while (scanf("%llu", &n) != EOF)
//	{
//
//			printf("%llu\n", n * 2 / 3 + 1);
//
//	}
//	return 0;
//}



//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//int main()
//{
//	char ar[50], sa[50], ag[50], sg[50], sf[100], st[100], temp;
//	char t[10][10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
//	int i, j, k, u, n, m, L, L1, L2;
//	long long a, b, c, count, d;
//	while (scanf("%s", ar) != EOF && scanf("%s", sa) != EOF)
//	{
//		L1 = strlen(ar);
//		L2 = strlen(sa);
//		a = 0;
//		b = 0;
//		count = 1;
//		for (i = L1 - 1; i >= 0; i--)
//		{
//			strcpy(ag, &ar[i]);
//			for (j = 0; j <= 9; j++)
//			{
//				if (strcmp(ag, t[j]) == 0)
//				{
//					a = a + j * count;
//					ar[i] = '\0';
//					count *= 10;
//				}
//			}
//		}
//		count = 1;
//		for (i = L2 - 1; i >= 0; i--)
//		{
//			strcpy(sg, &sa[i]);
//			for (j = 0; j <= 9; j++)
//			{
//				if (strcmp(sg, t[j]) == 0)
//				{
//					b = b + j * count;
//					sa[i] = '\0';
//					count *= 10;
//				}
//			}
//		}
//		c = 0;
//		d = a + b;
//		itoa(d, st, 10);
//		L = strlen(st);
//		for (i = 0; i <= (L - 1) / 2; i++)
//		{
//			temp = st[i];
//			st[i] = st[L - 1 - i];
//			st[L - 1 - i] = temp;
//		}
//		j = L - 1;
//		sf[0] = '\0';
//		while (j >= 0)
//		{
//			strcat(sf, t[st[j] - '0']);
//			j--;
//		}
//		L = strlen(sf);
//		puts(sf);
//
//	}
//	return 0;
//}


//
//#include <stdio.h>
//long long int C(long long int a, long long int b);
//long long int A(long long int a, long long int b);
//long long int F(long long int a);
//int main()
//{
//	long long int n, m, i, j, k, u, temp;
//	long long S;
//	while (scanf("%lld %lld %lld", &n, &m, &k) != EOF && (n != 0 || m != 0 || k != 0))
//	{
//
//		S = 1;
//		if (n - m*k < 0)
//		{
//			printf("0\n");
//			continue;
//		}
//
//			for (i = 0; i < m; i++)
//			{
//				S *= C(n - i*k, k);
//			}
//			for (i = 1; i <= n - m*k; i++)
//				S *= m;
//		
//			printf("%lld\n", S);
//	}
//	return 0;
//}
//long long int C(long long int a, long long int b)
//{
//	if (b == 0)
//		return 1;
//	return F(a) / (F(b) * F(a - b));
//}
//
//long long int F(long long int a)
//{
//	if (a == 0 || a == 1)
//		return 1;
//	long long int i;
//	long long int S = 1;
//	for (i = 1; i <= a; i++)
//		S *= i;
//	return S;
//}







//#include <stdio.h>
//
//int main()
//{
//	int i, j, k, u, n, m, x, y, set[100];
//	long long num[100], max;
//	while (scanf("%d %d", &n, &m) != EOF && (n != 0 || m != 0))
//	{
//		for (i = 1; i <= n; i++)
//		{
//			num[i] = 0;
//		}
//		max = 0;
//		for (u = 1; u <= m; u++)
//		{
//			scanf("%d %d", &x, &y);
//			num[x]++;
//			if (max < num[x])
//				max = num[x];
//			num[y]++;
//			if (max < num[y])
//				max = num[y];
//			
//		}
//		printf("%lld\n", max);
//	}
//	return 0;
//}









//#include <stdio.h>
//int main()
//{
//	int x, y, temp;
//	while (scanf("%d %d", &x, &y) != EOF && (x || y))
//	{
//		while (x != y)
//		{
//			if (x > y)
//			{
//				if (x % y != 0)
//					x %= y;
//				else
//					x = y;
//			}
//			if (x < y)
//			{
//				if (y % x != 0)
//					y %= x;
//				else
//					y = x;
//			}
//		}
//		printf("%d\n", x);
//	}
//	return 0;
//}





//poj1   矩阵快速幂第1题，重点：1、构造矩阵；2、用结构体存矩阵；3、a矩阵和res矩阵的初始化；4、取模；
//#include <stdio.h>
//#include <string.h>
//struct juz
//{
//	int ar[2][2];
//};
//struct juz multiply(struct juz a, struct juz b, int n);
//int main()
//{
//	int i, j, u, k, n, m;
//	struct juz a, res;
//	while (scanf("%d", &n) != EOF && n != -1)
//	{
//		m = n;
//		a.ar[0][0] = 1;
//		a.ar[0][1] = 1;
//		a.ar[1][0] = 1;
//		a.ar[1][1] = 0;
//		res.ar[0][0] = 0;
//		res.ar[0][1] = 1;
//		while (m > 0)
//		{
//			if (m % 2)
//			{
//				res = multiply(res, a, 2);
//			}
//			a = multiply(a, a, 2);
//			m /= 2;
//		}
//		printf("%d\n", res.ar[0][0]);
//	}
//	return 0;
//}
//struct juz multiply(struct juz a, struct juz b, int n)
//{
//	struct juz temp;
//	int i, j, k;
//	memset(temp.ar, 0, sizeof(int)*n*n);
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			for (k = 0; k < n; k++)
//			{
//				temp.ar[i][j] += ((a.ar[i][k] % 10000) * (b.ar[k][j] % 10000)) % 10000;
//				temp.ar[i][j] %= 10000;
//			}
//		}
//	}
//	return temp;
//}





//1575 矩阵快速幂第2题     使用memset时注意；
//#include <stdio.h>
//#include <string.h>
//struct juz
//{
//	unsigned long long int ar[11][11];
//};
//
//struct juz multiply(struct juz a, struct juz b, int n);
//int main()
//{
//	int i, j, k, n, m, u, x, y;
//	struct juz a, res;
//	unsigned long long tr;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d", &x, &y);
//			memset(a.ar, 0, sizeof(a.ar));
//			for (i = 0; i < x; i++)
//			{
//				for (j = 0; j < x; j++)
//				{
//					scanf("%llu", &a.ar[i][j]);
//				}
//			}
//			memset(res.ar, 0, sizeof(res.ar));
//			for (i = 0; i < x; i++)
//				res.ar[i][i] = 1;
//			while (y > 0)
//			{
//				if (y % 2)
//				{
//					res = multiply(res, a, x);
//				}
//				a = multiply(a, a, x);
//				y /= 2;
//			}
//			tr = 0;
//			for (i = 0; i < x; i++)
//			{
//				tr += res.ar[i][i] % 9973;
//				tr %= 9973;
//			}
//			printf("%llu\n", tr);
//		}
//		
//	}
//	return 0;
//}
//struct juz multiply(struct juz a, struct juz b, int n)
//{
//	int i, j, k;
//	struct juz temp;
//	memset(temp.ar, 0, sizeof(temp.ar));
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			for (k = 0; k < n; k++)
//			{
//				temp.ar[i][j] += ((a.ar[i][k] % 9973) * (b.ar[k][j] % 9973)) % 9973;
//				temp.ar[i][j] %= 9973;
//			}
//		}
//	}
//	return temp;
//}







//poj2   矩阵快速幂第3题，注意构造矩阵，注意初始化的下标；
//#include <stdio.h>
//#include <string.h>
//struct juz
//{
//	int ar[81][81];
//};
//struct juz multiply(struct juz a, struct juz b, int n, int m);
//int main()
//{
//	int i, j, k, u, n, m, x, y, z;
//	struct juz a, res, temp;
//	while (scanf("%d %d %d", &x, &y, &z) != EOF)
//	{
//		for (i = 0; i < x; i++)
//		{
//			for (j = 0; j < x; j++)
//			{
//				scanf("%d", &a.ar[i][j]);
//			}
//		}
//		memset(res.ar, 0, sizeof(res.ar));
//		memset(temp.ar, 0, sizeof(temp.ar));
//
//		for (i = x; i < 2 * x; i++)
//		{
//			res.ar[i-x][i] = 1;
//		}
//		for (i = 0; i < x; i++)
//		{
//			for (j = 0; j < x; j++)
//			{
//				temp.ar[i][j] = a.ar[i][j];
//			}
//		}
//		for (i = x; i < x * 2; i++)
//		{
//			for (j = 0; j < x; j++)
//			{
//				temp.ar[i][j] = a.ar[i - x][j];
//			}
//		}
//		for (i = x; i < 2 * x; i++)
//		{
//			temp.ar[i][i] = 1;
//		}
//		while (y > 0)
//		{
//			if (y % 2)
//			{
//				res = multiply(res, temp, x * 2, z);
//			}
//			temp = multiply(temp, temp, x * 2, z);
//			y /= 2;
//		}
//		for (i = 0; i < x; i++)
//		{
//			for (j = 0; j < x; j++)
//			{
//				printf("%d ", res.ar[i][j]);
//			}
//			putchar('\n');
//		}
//	}
//	return 0;
//}
//
//struct juz multiply(struct juz a, struct juz b, int n, int m)
//{
//	int i, j, k;
//	struct juz temp;
//	memset(temp.ar, 0, sizeof(temp.ar));
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			for (k = 0; k < n; k++)
//			{
//				temp.ar[i][j] += ((a.ar[i][k] % m) * (b.ar[k][j] % m)) % m;
//				temp.ar[i][j] %= m;
//			}
//		}
//	}
//	return temp;
//}







//2604   矩阵快速幂第4题
//#include <stdio.h>
//#include <string.h>
//struct juz
//{
//	int ar[5][5];
//};
//struct juz multiply(struct juz a, struct juz b, int n, int m);
//int main()
//{
//	int i, j, k, u, n, m, t;
//	struct juz a, res;
//	while (scanf("%d %d", &n, &u) != EOF)
//	{
//		memset(res.ar, 0, sizeof(res.ar));
//		memset(a.ar, 0, sizeof(a.ar));
//		a.ar[0][0] = 1;
//		a.ar[0][1] = 1;
//		a.ar[1][2] = 1;
//		a.ar[2][0] = 1;
//		a.ar[2][3] = 1;
//		a.ar[3][0] = 1;
//		res.ar[0][0] = 6;
//		res.ar[0][1] = 4;
//		res.ar[0][2] = 2;
//		res.ar[0][3] = 1;
//		if (n == 0)
//		{
//			printf("%d\n", 1 % u );
//			continue;
//		}
//		else if (n == 1)
//		{
//			printf("%d\n", 2%u);
//			continue;
//		}
//		else if (n == 2)
//		{
//			printf("%d\n", 3%u);
//			continue;
//		}
//		else if (n == 3)
//		{
//			printf("%d\n", 6%u);
//			continue;
//		}
//		t = n - 3;
//		while (t > 0)
//		{
//			if (t % 2)
//			{
//				res = multiply(res, a, 4, u);
//			}
//			a = multiply(a, a, 4, u);
//			t /= 2;
//		}
//		printf("%d\n", res.ar[0][0]);
//	}
//	return 0;
//}
//struct juz multiply(struct juz a, struct juz b, int n, int m)
//{
//	int i, j, k;
//	struct juz temp;
//	memset(temp.ar, 0, sizeof(temp.ar));
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			for (k = 0; k < n; k++)
//			{
//				temp.ar[i][j] += ((a.ar[i][k] % m)*(b.ar[k][j] % m)) % m;
//				temp.ar[i][j] %= m;
//			}
//		}
//	}
//	return temp;
//}







//1757     矩阵快速幂第5题，注意初始化下标顺序；
//#include <stdio.h>
//#include <string.h>
//struct juz
//{
//	long long ar[10][10];
//};
//struct juz multiply(struct juz a, struct juz b, int n, int m);
//
//int main()
//{
//	int i, j, k, u, n, m, t;
//	struct juz a, res;
//	while (scanf("%d %d", &n, &m) != EOF)
//	{
//		memset(a.ar, 0, sizeof(a.ar));
//		memset(res.ar, 0, sizeof(res.ar));
//		for (i = 0; i < 10; i++)
//		{
//			scanf("%lld", &a.ar[i][0]);
//		}
//		for (i = 1; i < 10; i++)
//			a.ar[i - 1][i] = 1;
//		for (i = 0; i < 10; i++)
//			res.ar[0][i] = 9 - i;
//		if (n < 10)
//		{
//			printf("%lld\n", res.ar[0][n] % m);
//			continue;
//		}
//		else
//		{
//			t = n - 9;
//			while (t > 0)
//			{
//				if (t % 2)
//				{
//					res = multiply(res, a, 10, m);
//				}
//				a = multiply(a, a, 10, m);
//				t /= 2;
//			}
//			printf("%lld\n", res.ar[0][0]);
//		}
//	}
//	return 0;
//}
//struct juz multiply(struct juz a, struct juz b, int n, int m)
//{
//	int i, j, k;
//	struct juz temp;
//	memset(temp.ar, 0, sizeof(temp.ar));
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			for (k = 0; k < n; k++)
//			{
//				temp.ar[i][j] += ((a.ar[i][k] % m) * (b.ar[k][j] % m)) % m;
//				temp.ar[i][j] %= m;
//			}
//		}
//	}
//	return temp;
//}





//#include <stdio.h>
//#include <ctype.h>
//int main()
//{
//	char ar[2000];
//	int i, j, k, n, m, count;
//	while (scanf("%s", ar) != EOF)
//	{
//		count = 0;
//		for (i = 0; ar[i] != '\0'; i++)
//		{
//			if (isupper(ar[i]))
//			{
//				count++;
//			}
//		}
//		printf("%d\n", count);
//	}
//	return 0;
//}






//#include <stdio.h>
//int main()
//{
//	long long int i, j, k, u, n, m, count, S;
//	while (scanf("%lld", &n) != EOF)
//	{
//		i = 0;
//		j = 0;
//		count = 0;
//		m = n;
//		while (m > 0)
//		{
//			count += m / 10;
//			m /= 10;
//		}
//		m = n;
//		while (m > 0)
//		{
//			i += m / 2;
//			m /= 2;
//		}
//		m = n;
//		while (m > 0)
//		{
//			j += m / 5;
//			m /= 5;
//		}
//		if (i < j)
//		{
//			i -= count;
//			count += i;
//		}
//		else
//		{
//			j -= count;
//			count += j;
//		}
//		printf("%lld\n", count);
//	}
//	return 0;
//}



//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	int i, j, k, u, n, m, b, e, set[100010], max, temp;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &k);
//			memset(set, 0, sizeof(set));
//			for (u = 0; u < k; u++)
//			{
//				scanf("%d %d", &b, &e);
//				set[b]++;
//				set[e]--;
//			}
//
//			max = 0;
//			temp = 0;
//			for (i = 0; i < 100009; i++)
//			{
//				temp += set[i];
//				if (max < temp)
//					max = temp;
//			}
//			printf("%d\n", max);
//		}
//	}
//	return 0;
//}



//#include <stdio.h>
//int main()
//{
//	long long int i, j, n, m, k, u;
//	while (scanf("%lld", &n) != EOF)
//	{
//		m = 1;
//		k = 0;
//		while (m*3 <= n)
//		{
//			m *= 3;
//			k++;
//		}
//		if (m != n)
//			k += 1;
//		printf("%lld\n", k);
//	}
//	return 0;
//}




//#include <stdio.h>
//struct match
//{
//	int b;
//	int e;
//	int sta;
//};
//int main()
//{
//	int i, j, k, n, m, x, y, count, u, temp;
//	struct match ar[100010];
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &k);
//			
//			for (u = 1; u <= k; u++)
//			{
//				scanf("%d %d", &ar[u].b, &ar[u].e);
//				ar[u].sta = u;
//			}
//			for (i = 1; i <= k; i++)
//			{
//				if (ar[i].sta != i)
//					continue;
//				else
//					count++;
//				for (j = i; j <= k; j++)
//				{
//					if (ar[j].b >= ar[i].e || ar[j].e <= ar[i].b)
//						ar[j].sta = i;
//				}
//			}
//			printf("%d\n", count);
//		}
//	}
//	return 0;
//}













//dijkstra模板；
//#include <iostream>
//#include <cstdio>
//#include<fstream>
//using namespace std;
//const int maxnum = 100;
//const int maxint = 999999;
//void Dijkstra(int n, int v, int *dist, int *prev, int c[maxnum][maxnum])
//{
//	int i, j;
//	bool s[maxnum];    // 判断是否已存入该点到S集合中
//	for ( i = 1; i <= n; ++i)
//	{
//		dist[i] = c[v][i];
//		s[i] = 0;     // 初始都未用过该点
//		if (dist[i] == maxint)
//			prev[i] = 0;
//		else
//			prev[i] = v;
//	}
//	dist[v] = 0;
//	s[v] = 1;
//
//	// 依次将未放入S集合的结点中，取dist[]最小值的结点，放入结合S中
//	// 一旦S包含了所有V中顶点，dist就记录了从源点到所有其他顶点之间的最短路径长度
//	for (i = 2; i <= n; ++i)
//	{
//		int tmp = maxint;
//		int u = v;
//		// 找出当前未使用的点j的dist[j]最小值
//		for ( j = 1; j <= n; ++j)
//			if ((!s[j]) && dist[j]<tmp)
//			{
//				u = j;              // u保存当前邻接点中距离最小的点的号码
//				tmp = dist[j];
//			}
//		s[u] = 1;    // 表示u点已存入S集合中
//
//					 // 更新dist
//		for (j = 1; j <= n; ++j)
//			if ((!s[j]) && c[u][j]<maxint)
//			{
//				int newdist = dist[u] + c[u][j];
//				if (newdist < dist[j])
//				{
//					dist[j] = newdist;
//					prev[j] = u;
//				}
//			}
//	}
//}
//void searchPath(int *prev, int v, int u)
//{
//	int que[maxnum];
//	int tot = 1;
//	int i;
//	que[tot] = u;
//	tot++;
//	int tmp = prev[u];
//	while (tmp != v)
//	{
//		que[tot] = tmp;
//		tot++;
//		tmp = prev[tmp];
//	}
//	que[tot] = v;
//	for ( i = tot; i >= 1; --i)
//		if (i != 1)
//			cout << que[i] << " -> ";
//		else
//			cout << que[i] << endl;
//}
//
//int main()
//{
//	int i, j;
//	// 各数组都从下标1开始
//	int dist[maxnum];     // 表示当前点到源点的最短路径长度
//	int prev[maxnum];     // 记录当前点的前一个结点
//	int c[maxnum][maxnum];   // 记录图的两点间路径长度
//	int n, line;             // 图的结点数和路径数
//
//							 // 输入结点数
//	cin >> n;
//	// 输入路径数
//	cin >> line;
//	int p, q, len;          // 输入p, q两点及其路径长度
//							// 初始化c[][]为maxint
//	for (i = 1; i <= n; ++i)
//		for (j = 1; j <= n; ++j)
//			c[i][j] = maxint;
//	for (i = 1; i <= line; ++i)
//	{
//		cin >> p >> q >> len;
//		if (len < c[p][q])       // 有重边
//		{
//			c[p][q] = len;      // p指向q
//			c[q][p] = len;      // q指向p，这样表示无向图
//		}
//	}
//	for (i = 1; i <= n; ++i)
//		dist[i] = maxint;
//	for (i = 1; i <= n; ++i)
//	{
//		for (j = 1; j <= n; ++j)
//			printf("%8d", c[i][j]);
//		printf("\n");
//	}
//	Dijkstra(n, 1, dist, prev, c);
//	// 最短路径长度
//	cout << "源点到最后一个顶点的最短路径长度: " << dist[n] << endl;
//	// 路径
//	cout << "源点到最后一个顶点的路径为: ";
//	searchPath(prev, 1, n);
//	return 0;
//}







//迪杰斯特拉算法模板(2544)
//#include <iostream>  
//#define MAX 100  
//#define INF 1000000000  
//using namespace std;
//int dijkstra(int mat[][MAX], int n, int s, int f)
//{
//	int dis[MAX];
//	int mark[MAX];//记录被选中的结点   
//	int i, j, k = 0;
//	for (i = 0; i < n; i++)//初始化所有结点，每个结点都没有被选中   
//		mark[i] = 0;
//	for (i = 0; i < n; i++)//将每个结点到start结点weight记录为当前distance   
//	{
//		dis[i] = mat[s][i];
//		//path[i] = s;  
//	}
//	mark[s] = 1;//start结点被选中   
//				//path[s] = 0;  
//	dis[s] = 0;//将start结点的的距离设置为0   
//	int min;//设置最短的距离。   
//	for (i = 1; i < n; i++)
//	{
//		min = INF;
//		for (j = 0; j < n; j++)
//		{
//			if (mark[j] == 0 && dis[j] < min)//未被选中的结点中，距离最短的被选中   
//			{
//				min = dis[j];
//				k = j;
//			}
//		}
//		mark[k] = 1;//标记为被选中   
//		for (j = 0; j < n; j++)
//		{
//			if (mark[j] == 0 && (dis[j] >(dis[k] + mat[k][j])))//修改剩余结点的最短距离   
//			{
//				dis[j] = dis[k] + mat[k][j];
//			}
//		}
//	}
//	return dis[f];
//}
//int mat[MAX][MAX];
//int main()
//{
//	int n, m;
//	while (scanf("%d %d", &n, &m))
//	{
//		int a, b, dis;
//		if (n == 0 || m == 0)
//			break;
//		int i, j;
//		for (i = 0; i < n; i++)
//			for (j = 0; j < n; j++)
//				mat[i][j] = INF;
//		for (i = 0; i < m; i++)
//		{
//			scanf("%d %d %d", &a, &b, &dis);
//			--a, --b;
//			if (dis < mat[a][b] || dis < mat[b][a])
//				mat[a][b] = mat[b][a] = dis;
//		}
//		int ans = dijkstra(mat, n, 0, n - 1);
//		printf("%d\n", ans);
//	}
//
//}






//2544					最短路 第8题（dijkstra）
//#include <stdio.h>
//#define MAXINT 10000000
//
//int dijkstra(int (*ar)[101], int b, int e, int n);
//int main()
//{
//	int i, j, k, u, n, m, a, b, c, temp, (*s)[101], sa[101][101];
//	while (scanf("%d %d", &n, &m) != EOF && (n || m))
//	{
//		for (u = 1; u <= n; u++)
//			for (k = 1; k <= n; k++)
//				sa[u][k] = MAXINT;
//		for (u = 1; u <= m; u++)
//		{
//			scanf("%d %d %d", &a, &b, &c);
//			sa[b][a] = c;
//			sa[a][b] = c;
//		}
//		s = sa;
//		printf("%d\n", dijkstra(s, 1, n, n));
//	}
//	return 0;
//}
//
//int dijkstra(int(*ar)[101], int b, int e, int n)
//{
//	bool S[101];										 // 判断是否已存入该点到S集合中
//	int dist[101], pre[101];
//	int i, j, k, u, mindist;
//	for (i = 1; i <= e; i++)
//	{
//		dist[i] = ar[b][i];
//		S[i] = false;									 // 初始都未用过该点
//		if (dist[i] == MAXINT)
//			pre[i] = -1;
//		else
//			pre[i] = b;
//	}
//	dist[b] = 0;
//	S[b] = true;
//	for (i = 2; i <= e; i++)
//	{
//		mindist = MAXINT;
//		for (j = 1; j <= e; j++)								 // 找出当前未使用的点j的dist[j]最小值
//		{
//			if (S[j] == false && dist[j] < mindist)
//			{
//				u = j;												// u保存当前邻接点中距离最小的点的号码 
//				mindist = dist[j];
//			}
//		}
//		S[u] = true;
//		for (j = 1; j <= e; j++)
//		{
//			if (S[j] == false && dist[u] + ar[u][j] < dist[j])						//在通过新加入的u点路径找到离begin点更短的路径  
//			{
//				dist[j] = dist[u] + ar[u][j];													//更新dist 
//				pre[j] = u;																			//找到前一个点
//			}
//		}
//	}
//	return dist[e];
//}






//弗洛伊德算法模板
//#include<stdio.h>
//#include<stdlib.h>
//#define max 1000000000
//
//int d[1000][1000], path[1000][1000];
//int main()
//{
//	int i, j, k, m, n;
//	int x, y, z;
//	scanf("%d%d", &n, &m);
//
//	for (i = 1; i <= n; i++)
//		for (j = 1; j <= n; j++) {
//			d[i][j] = max;
//			if (i == j)
//				d[i][j] = 0;
//			path[i][j] = j;
//		}
//
//	for (i = 1; i <= m; i++)
//	{
//		scanf("%d%d%d", &x, &y, &z);
//		d[x][y] = z;
//		d[y][x] = z;
//	}
//
//	for (k = 1; k <= n; k++)
//		for (i = 1; i <= n; i++)
//			for (j = 1; j <= n; j++)
//			{
//				if (d[i][k] + d[k][j]<d[i][j]) {
//					d[i][j] = d[i][k] + d[k][j];
//					path[i][j] = path[i][k];
//				}
//			}
//
//	for (i = 1; i <= n; i++)
//		for (j = 1; j <= i; j++)
//			if (i != j) printf("%d->%d:%d\n", i, j, d[i][j]);
//
//	int f, en;
//	scanf("%d%d", &f, &en);
//	while (f != en) {
//		printf("%d->", f);
//		f = path[f][en];
//	}
//	printf("%d\n", en);
//
//	return 0;
//}
//弗洛伊德c++版;
//#include<iostream>
//#include<vector>
//using namespace std;
//const int &INF = 100000000;
//void floyd(vector<vector<int> > &distmap,//可被更新的邻接矩阵，更新后不能确定原有边
//	vector<vector<int> > &path)//路径上到达该点的中转点
//							   //福利：这个函数没有用除INF外的任何全局量，可以直接复制！
//{
//	const int &NODE = distmap.size();//用邻接矩阵的大小传递顶点个数，减少参数传递
//	path.assign(NODE, vector<int>(NODE, -1));//初始化路径数组 
//	for (int k = 1; k != NODE; ++k)//对于每一个中转点
//		for (int i = 0; i != NODE; ++i)//枚举源点
//			for (int j = 0; j != NODE; ++j)//枚举终点
//				if (distmap[i][j]>distmap[i][k] + distmap[k][j])//不满足三角不等式
//				{
//					distmap[i][j] = distmap[i][k] + distmap[k][j];//更新
//					path[i][j] = k;//记录路径
//				}
//}
//void print(const int &beg, const int &end,
//	const vector<vector<int> > &path)//传引用，避免拷贝，不占用内存空间
//									 //也可以用栈结构先进后出的特性来代替函数递归 
//{
//	if (path[beg][end] >= 0)
//	{
//		print(beg, path[beg][end], path);
//		print(path[beg][end], end, path);
//	}
//	else cout << "->" << end;
//}
//int main()
//{
//	int n_num, e_num, beg, end;//含义见下
//	cout << "（不处理负权回路）输入点数、边数：";
//	cin >> n_num >> e_num;
//	vector<vector<int> > path,
//		distmap(n_num, vector<int>(n_num, INF));//默认初始化邻接矩阵
//	for (int i = 0, p, q; i != e_num; ++i)
//	{
//		cout << "输入第" << i + 1 << "条边的起点、终点、长度（100000000代表无穷大，不联通）：";
//		cin >> p >> q;
//		cin >> distmap[p][q];
//	}
//	floyd(distmap, path);
//	cout << "计算完毕，可以开始查询，请输入出发点和终点：";
//	cin >> beg >> end;
//	cout << "最短距离为" << distmap[beg][end] << "，打印路径：" << beg;
//	print(beg, end, path);
//}

//floyd 模板；
//#include "stdio.h" 
//#include "stdlib.h" 
//#include "io.h" 
//#include "math.h" 
//#include "time.h"
//
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//#define MAXEDGE 20
//#define MAXVEX 20
//#define INFINITY 65535
//
//typedef int Status;    /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
//
//typedef struct
//{
//	int vexs[MAXVEX];
//	int arc[MAXVEX][MAXVEX];
//	int numVertexes, numEdges;
//}MGraph;
//
//typedef int Patharc[MAXVEX][MAXVEX];
//typedef int ShortPathTable[MAXVEX][MAXVEX];
//
///* 构件图 */
//void CreateMGraph(MGraph *G)
//{
//	int i, j;
//
//	/* printf("请输入边数和顶点数:"); */
//	G->numEdges = 16;
//	G->numVertexes = 9;
//
//	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
//	{
//		G->vexs[i] = i;
//	}
//
//	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
//	{
//		for (j = 0; j < G->numVertexes; j++)
//		{
//			if (i == j)
//				G->arc[i][j] = 0;
//			else
//				G->arc[i][j] = G->arc[j][i] = INFINITY;
//		}
//	}
//
//	G->arc[0][1] = 1;
//	G->arc[0][2] = 5;
//	G->arc[1][2] = 3;
//	G->arc[1][3] = 7;
//	G->arc[1][4] = 5;
//
//	G->arc[2][4] = 1;
//	G->arc[2][5] = 7;
//	G->arc[3][4] = 2;
//	G->arc[3][6] = 3;
//	G->arc[4][5] = 3;
//
//	G->arc[4][6] = 6;
//	G->arc[4][7] = 9;
//	G->arc[5][7] = 5;
//	G->arc[6][7] = 2;
//	G->arc[6][8] = 7;
//
//	G->arc[7][8] = 4;
//
//
//	for (i = 0; i < G->numVertexes; i++)
//	{
//		for (j = i; j < G->numVertexes; j++)
//		{
//			G->arc[j][i] = G->arc[i][j];
//		}
//	}
//
//}
//
///* Floyd算法，求网图G中各顶点v到其余顶点w的最短路径P[v][w]及带权长度D[v][w]。 */
//void ShortestPath_Floyd(MGraph G, Patharc *P, ShortPathTable *D)
//{
//	int v, w, k;
//	for (v = 0; v<G.numVertexes; ++v) /* 初始化D与P */
//	{
//		for (w = 0; w<G.numVertexes; ++w)
//		{
//			(*D)[v][w] = G.arc[v][w];    /* D[v][w]值即为对应点间的权值 */
//			(*P)[v][w] = w;                /* 初始化P */
//		}
//	}
//	for (k = 0; k<G.numVertexes; ++k)
//	{
//		for (v = 0; v<G.numVertexes; ++v)
//		{
//			for (w = 0; w<G.numVertexes; ++w)
//			{
//				if ((*D)[v][w]>(*D)[v][k] + (*D)[k][w])
//				{/* 如果经过下标为k顶点路径比原两点间路径更短 */
//					(*D)[v][w] = (*D)[v][k] + (*D)[k][w];/* 将当前两点间权值设为更小的一个 */
//					(*P)[v][w] = (*P)[v][k];/* 路径设置为经过下标为k的顶点 */
//				}
//			}
//		}
//	}
//}
//
//int main(void)
//{
//	int v, w, k;
//	MGraph G;
//
//	Patharc P;
//	ShortPathTable D; /* 求某点到其余各点的最短路径 */
//
//	CreateMGraph(&G);
//
//	ShortestPath_Floyd(G, &P, &D);
//
//	printf("各顶点间最短路径如下:\n");
//	for (v = 0; v<G.numVertexes; ++v)
//	{
//		for (w = v + 1; w<G.numVertexes; w++)
//		{
//			printf("v%d-v%d weight: %d ", v, w, D[v][w]);
//			k = P[v][w];                /* 获得第一个路径顶点下标 */
//			printf(" path: %d", v);    /* 打印源点 */
//			while (k != w)                /* 如果路径顶点下标不是终点 */
//			{
//				printf(" -> %d", k);    /* 打印路径顶点 */
//				k = P[k][w];            /* 获得下一个路径顶点下标 */
//			}
//			printf(" -> %d\n", w);    /* 打印终点 */
//		}
//		printf("\n");
//	}
//
//	printf("最短路径D\n");
//	for (v = 0; v<G.numVertexes; ++v)
//	{
//		for (w = 0; w<G.numVertexes; ++w)
//		{
//			printf("%d\t", D[v][w]);
//		}
//		printf("\n");
//	}
//	printf("最短路径P\n");
//	for (v = 0; v<G.numVertexes; ++v)
//	{
//		for (w = 0; w<G.numVertexes; ++w)
//		{
//			printf("%d ", P[v][w]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}









//1217     最短路第1题；（floyd）  找出字符串的下标,用下标表示dist的横纵坐标;
//#include <stdio.h>
//#include <string.h>
//
//void floyd(double(*dist)[31], int(*path)[31], int n);
//int main()
//{	int i, j, k, u, m, n, x, y, path[31][31], (*pat)[31], doudou, cas = 0;
//	double dist[31][31], temp, (*dis)[31];
//
//	char ar[31][100], a[100], b[100];
//	while (scanf("%d", &n) != EOF && n)
//	{
//		cas++;
//		for (i = 1; i <= n; i++)
//		{
//			scanf("%s", ar[i]);
//		}
//		for (i = 0; i <= n; i++)
//		{
//			for (j = 0; j <= n; j++)
//			{
//				dist[i][j] = 0;
//				if (i == j)
//					dist[i][j] = 0;
//				path[i][j] = j;
//			}
//		}
//		scanf("%d", &m);
//		for (i = 1; i <= m; i++)
//		{
//			scanf("%s %lf %s", a, &temp, b);
//			for (j = 1; j <= n; j++)
//			{
//				if (strcmp(ar[j], a) == 0)
//				{
//					x = j;
//					break;
//				}
//			}
//			for (j = 1; j <= n; j++)
//			{
//				if (strcmp(ar[j], b) == 0)
//				{
//					y = j;
//					break;
//				}
//			}
//			dist[x][y] = temp;
//		}
//		dis = dist;
//		pat = path;
//		floyd(dis, pat, n);
//		doudou = 0;
//		for (i = 1; i <= n; i++)
//			if (dist[i][i] > 1)
//				doudou = 1;
//		if (doudou)
//			printf("Case %d: Yes\n", cas);
//		else
//			printf("Case %d: No\n", cas);
//	}
//	return 0;
//}
//void floyd(double(*dist)[31], int(*path)[31], int n)
//{
//	int i, j, k, u;
//	for (k = 1; k <= n; k++)
//	{
//		for (i = 1; i <= n; i++)
//		{
//			for (j = 1; j <= n; j++)
//			{
//				if (dist[i][j] < dist[i][k] * dist[k][j])
//				{
//					dist[i][j] = dist[i][k] * dist[k][j];
//					path[i][j] = path[i][k];
//				}
//			}
//		}
//	}
//}





//1224  未过 用dp
//#include <stdio.h>
//void floyd(int(*dist)[101], int(*path)[101], int n);
//
//int main()
//{
//	int i, j, k, u, n, m, t, a, b, dist[101][101], (*dis)[101], path[101][101], (*pat)[101], ar[101], cas;
//	while (scanf("%d", &n) != EOF)
//	{
//		cas = 0;
//		for (m = 1; m <= n; m++)
//		{
//			cas++;
//			scanf("%d", &k);
//			for (u = 1; u <= k; u++)
//			{
//				scanf("%d", &ar[u]);
//			}
//			scanf("%d", &t);
//			for (i = 0; i <= k; i++)
//			{
//				for (j = 0; j <= k; j++)
//				{
//					dist[i][j] = 0;
//					path[i][j] = j;
//				}
//			}
//			for (u = 1; u <= t; u++)
//			{
//				scanf("%d %d", &a, &b);
//				dist[a][b] = ar[a];
//
//			}
//			dis = dist;
//			pat = path;
//			floyd(dis, pat, k);
//			printf("CASE %d#\npoints : %d\ncircuit : 1->", cas, dist[1][1]);
//			i = 1;
//			j = 1;
//			k = path[i][j];
//			while (k != 1)
//			{
//				printf("%d->", k);
//				k = path[k][j];
//			}
//			printf("1\n\n");
//		}
//	}
//}
//void floyd(int(*dist)[101], int(*path)[101], int n)
//{
//	int i, j, k, u;
//	for (k = 1; k <= n; k++)
//	{
//		for (i = 1; i <= n; i++)
//		{
//			for (j = 1; j <= n; j++)
//			{
//				if (dist[i][j] < dist[i][k] + dist[k][j] && dist[i][k] < dist[k][j])
//				{
//					dist[i][j] = dist[i][k] + dist[k][j];
//					path[i][j] = path[i][k];
//				}
//			}
//		}
//	}
//}









//1385   最短路第3题  注意按字典序输出，只需多判断一步dist[i][j]==dist[i][k]+dist[k][j]+ar[k] && path[i][j] > path[k][j];
//#include <stdio.h>
//#define MAXINT 10000000
//void floyd(int(*dist)[1002], int(*path)[1002], int *ar, int n);
//int main()
//{
//	int i, j, k, u, n, m, a, b, cost, dist[1002][1002], (*dis)[1002], path[1002][1002], (*pat)[1002], ar[1002];
//	while (scanf("%d", &n) != EOF && n)
//	{
//		for (i = 1; i <= n; i++)
//		{
//			for (j = 1; j <= n; j++)
//			{
//				scanf("%d", &dist[i][j]);
//				if (dist[i][j] == -1)
//					dist[i][j] = MAXINT;
//				path[i][j] = j;
//			}
//		}
//		for (i = 1; i <= n; i++)
//			scanf("%d", &ar[i]);
//		dis = dist;
//		pat = path;
//		floyd(dis, pat, ar, n);
//		while (scanf("%d %d", &a, &b) == 2 && (a != -1 && b != -1))
//		{
//			printf("From %d to %d :\n", a, b);
//			printf("Path: %d", a);
//
//			j = b;
//			k = a;
//			while (k != j)
//			{
//				printf("-->%d", path[k][j]);
//				k = path[k][j];
//			}
//			printf("\n");
//			printf("Total cost : %d\n\n", dist[a][b]);
//		}
//	}
//	return 0;
//}
//void floyd(int(*dist)[1002], int(*path)[1002], int *ar, int n)
//{
//	int i, j, k;
//	for (k = 1; k <= n; k++)
//	{
//		for (i = 1; i <= n; i++)
//		{
//			for (j = 1; j <= n; j++)
//			{
//				if (dist[i][j] > dist[i][k] + dist[k][j] + ar[k])
//				{
//					dist[i][j] = dist[i][k] + dist[k][j] + ar[k];
//					path[i][j] = path[i][k];
//				}
//				else if (dist[i][j] == dist[i][k] + dist[k][j] + ar[k])
//				{
//					if (path[i][j] > path[i][k])
//					{
//						path[i][j] = path[i][k];
//					}
//				}
//			}
//		}
//	}
//}








//1869   最短路第4题     没有真正理解Floyd的含义; (认识距离为0, 通过几个人认识距离为几就行了)
//#include <stdio.h>
//#define MAXINT 10000000
//void floyd(int(*dist)[101], int n);
//int main()
//{
//	int i, j, k, u, n, m, a, b, dist[101][101], doudou;
//	while (scanf("%d %d", &n, &m) != EOF)
//	{
//		for (i = 0; i < n; i++)
//		{
//			for (j = 0; j < n; j++)
//			{
//				dist[i][j] = MAXINT;
//				if (i == j)
//					dist[i][j] = 0;
//	
//			}
//		}
//		for (u = 0; u < m; u++)
//		{
//			scanf("%d %d", &a, &b);
//			dist[a][b] = 1;
//			dist[b][a] = 1;
//		}
//		floyd(dist, n);
//		doudou = 1;
//		for (i = 0; i < n; i++)
//		{
//			for (j = 0; j < n; j++)
//			{
//				if (dist[i][j] > 7)
//				{
//					doudou = 0;
//					break;
//				}
//			}
//			if (doudou == 0)
//				break;
//		}
//		if (doudou == 1)
//			printf("Yes\n");
//		else
//			printf("No\n");
//	}
//}
//void floyd(int(*dist)[101], int n)
//{
//	int i, j, k, u;
//	for (k = 0; k < n; k++)
//	{
//		for (i = 0; i < n; i++)
//		{
//			for (j = 0; j < n; j++)
//			{
//				if (dist[i][j] > dist[i][k] + dist[k][j])
//				{
//					dist[i][j] = dist[i][k] + dist[k][j];
//				}
//			}
//		}
//	}
//}






//1874     最短路第5题    太坑了  有可能相同的2个村庄有好多条长度不同的路
//#include <stdio.h>
//#define MAXINT 100000000
//void floyd(int(*dist)[205], int n);
//int main()
//{
//	int i, j, k, u, n, m, a, b, c, begin, end, dist[205][205];
//	while (scanf("%d %d", &n, &m) != EOF)
//	{
//		for (i = 0; i < n; i++)
//		{
//			for (j = 0; j < n; j++)
//			{
//				dist[i][j] = MAXINT;
//				if (i == j)
//					dist[i][j] = 0;
//			}
//		}
//		for (u = 1; u <= m; u++)
//		{
//			scanf("%d %d %d", &a, &b, &c);
//			if (dist[a][b] > c)
//			{
//				dist[a][b] = c;
//				dist[b][a] = c;
//			}
//		}
//		scanf("%d %d", &begin, &end);
//		floyd(dist, n);
//		if (dist[begin][end] != MAXINT)
//			printf("%d\n", dist[begin][end]);
//		else
//			printf("-1\n");
//	}
//	return 0;
//}
//void floyd(int(*dist)[205], int n)
//{
	//int i, j, k, u;
	//for (k = 0; k < n; k++)
	//{
	//	for (i = 0; i < n; i++)
	//	{
	//		for (j = 0; j <n; j++)
	//		{
	//			if (dist[i][j] > dist[i][k] + dist[k][j])
	//			{
	//				dist[i][j] = dist[i][k] + dist[k][j];
	//			}
	//		}
	//	}
	//}
//}







//2066    最短路第6题
//#include <stdio.h>
//#define MAXINT 100000000
//void floyd(int(*dist)[1002], int n);
//int main()
//{
//	int i, j, k, u, n, m, a, b, c, ar[1002], sa[1002], dist[1002][1002], S, D, T, min, max;
//	while (scanf("%d %d %d", &T, &S, &D) != EOF)
//	{
//		for (i = 1; i <= 1000; i++)
//		{
//			for (j = 1; j <= 1000; j++)
//			{
//				dist[i][j] = MAXINT;
//				if (i == j)
//					dist[i][j] = 0;
//			}
//		}
//		max = 0;
//		for (u = 1; u <= T; u++)
//		{
//			scanf("%d %d %d", &a, &b, &c);
//			if (dist[a][b] > c)
//			{
//				dist[a][b] = c;
//				dist[b][a] = c;
//			}
//			max = (max > a) ? max : a;
//			max = (max > b) ? max : b;
//		}
//		
//		for (u = 1; u <= S; u++)
//		{
//			scanf("%d", &ar[u]);
//		}
//		for (u = 1; u <= D; u++)
//			scanf("%d", &sa[u]);
//		floyd(dist, max);
//		min = MAXINT;
//		for (i = 1; i <= S; i++)
//		{
//			for (j = 1; j <= D; j++)
//			{
//				if (min > dist[ar[i]][sa[j]])
//					min = dist[ar[i]][sa[j]];
//			}
//		}
//		printf("%d\n", min);
//	}
//	return 0;
//}
//void floyd(int(*dist)[1002], int n)
//{
//	int i, j, k, u;
//	for (k = 1; k <= n; k++)
//	{
//		for (i = 1; i <= n; i++)
//		{
//			if (dist[i][k] != MAXINT)
//			{
//				for (j = 1; j <= n; j++)
//				{
//					if (dist[i][j] > dist[i][k] + dist[k][j])
//					{
//						dist[i][j] = dist[i][k] + dist[k][j];
//					}
//				}
//			}
//		}
//	}
//}







//#include <stdio.h>
//int main()
//{
//	int i, j, k, n, m, u, a, b, x, y, max, sum;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			max = -1;
//			scanf("%d %d", &a, &b);
//			for (i = a; i <= b; i++)
//			{
//				sum = 0;
//				for (j = 1; j <= i; j++)
//				{
//					if (i % j == 0)
//						sum += j;
//				}
//				sum -= 2 * i;
//				if (max < sum && sum > 0)
//					max = sum;
//			}
//			if (max != -1)
//				printf("%d\n", max);
//			else
//				printf("-1\n");
//		}
//	}
//	return 0;
//}






//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <math.h>
//struct acm
//{
//	int time;
//	char sta[20];
//	char id;
//};
//int main()
//{
//	int i, j, k, u, n, m, set[26];
//	struct acm ar[101];
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &k);
//			memset(set, 0, sizeof(set));
//			for (u = 1; u <= k; u++)
//			{
//				scanf("%d %c %s", &ar[u].time, &ar[u].id, ar[u].sta);
//				if (strcmp(ar[u].sta, "Accept") == 0)
//				{
//					set[ar[u].id - 'A'] = 1;
//				}
//				if (strcmp(ar[u].sta, "Wrong") == 0 && set[ar[u].id - 'A'] == 0)
//				{
//					set[ar[u].id - 'A'] = -1;
//				}
//			}
//			printf("Accept: ");
//			for (i = 0; i < 26; i++)
//				if (set[i] == 1)
//					printf("%c", i + 'A');
//			putchar('\n');
//			printf("Wrong: ");
//			for (i = 0; i < 26; i++)
//				if (set[i] == -1)
//					printf("%c", i + 'A');
//			putchar('\n');
//			putchar('\n');
//		}
//	}
//	return 0;
//}








//#include <stdio.h>
//#include <stdlib.h>
//
//#include <math.h>
//int comp(const void * p1, const void * p2);
//int main()
//{
//	int i, j, k, n, m, u, x, y, ar[10010];
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &k);
//			for (u = 0; u < k; u++)
//			{
//				scanf("%d", &ar[u]);
//			}
//			qsort(ar, k, sizeof(int), comp);
//			j = 0;
//			for (i = 0; i < k; i++)
//			{
//				if (i % 2 == 0)
//					printf("%d ", ar[k - 1 - j]);
//				else
//				{
//					printf("%d ", ar[j]);
//					j++;
//				}
//			}
//			putchar('\n');
//		}
//	}
//	return 0;
//}
//int comp(const void * p1, const void * p2)
//{
//	return *(int *)p1 - *(int *)p2;
//}








//#include <stdio.h>
//#include <math.h>
//int main()
//{
//	int i, j, k, u, n, m, ar[1010], num[1010][2], max;
//	while (scanf("%d", &n) != EOF && n)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &ar[m]);
//			num[m][0] = 0;
//			num[m][1] = 0;
//		}
//		num[1][1] = 1;
//		for (i = 2; i <= n; i++)
//		{
//			for (j = 1; j <= i; j++)
//			{
//				if (ar[i] < ar[j] && num[i][0] < num[j][1] + 1)
//					num[i][0] = num[j][1] + 1;
//					if (ar[i] > ar[j] && num[i][1] < num[j][0] + 1)
//						num[i][1] = num[j][0] + 1;
//			}
//		}
//		max = 0;
//		for (i = 1; i <= n; i++)
//		{
//			if (max < num[i][0])
//				max = num[i][0];
//			if (max < num[i][1])
//				max = num[i][1];
//		}
//		printf("%d\n", max);
//	}
//	return 0;
//}



//#include <stdio.h>
//int main()
//{
//	int i, j, k, n, m;
//	while (scanf("%d %d", &n, &m) != EOF && (n || m))
//	{
//
//		if ((m*n) % 8 == 0 && n >= 2 && m >= 2)
//			printf("YES\n");
//		else
//			printf("NO\n");
//	}
//	return 0;
//}






//#include <stdio.h>
//int main()
//{
//	long long int i, j, k, u, n, m, a, b, ar[110][110];
//	while (scanf("%lld %lld", &a, &b) != EOF)
//	{
//		for (i = 1; i <= 101; i++)
//		{
//			ar[i][0] = 1;
//			ar[0][i] = 0;
//		}
//		ar[0][0] = 0;
//		for (i =1; i <= a; i++)
//		{
//			for (j = 1; j <= b; j++)
//			{
//				ar[i][j] = ar[i - 1][j] * (j + 1) + ar[i - 1][j - 1] * (i - j);
//				ar[i][j] %= 2007;
//			}
//		}
//		printf("%lld\n", ar[a][b] % 2007);
//	}
//	return 0;
//}













//bfs模板；
//#include<cstdio>  
//#include<cstring>  
//#include<queue>  
//#include<algorithm>  
//using namespace std;
//const int maxn = 100;
//bool vst[maxn][maxn]; // 访问标记  
//int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // 方向向量  
//
//struct State // BFS 队列中的状态数据结构  
//{
//	int x, y; // 坐标位置  
//	int Step_Counter; // 搜索步数统计器  
//};
//
//State a[maxn];
//
//bool CheckState(State s) // 约束条件检验  
//{
//	if (!vst[s.x][s.y] && ...) // 满足条件         
//		return 1;
//	else // 约束条件冲突  
//		return 0;
//}
//
//void bfs(State st)
//{
//	queue <State> q; // BFS 队列  
//	State now, next; // 定义2 个状态，当前和下一个  
//	st.Step_Counter = 0; // 计数器清零  
//	q.push(st); // 入队     
//	vst[st.x][st.y] = 1; // 访问标记  
//	while (!q.empty())
//	{
//		now = q.front(); // 取队首元素进行扩展  
//		if (now == G) // 出现目标态，此时为Step_Counter 的最小值，可以退出即可  
//		{
//			...... // 做相关处理  
//				return;
//		}
//		for (int i = 0; i<4; i++)
//		{
//			next.x = now.x + dir[i][0]; // 按照规则生成   下一个状态  
//			next.y = now.y + dir[i][1];
//			next.Step_Counter = now.Step_Counter + 1; // 计数器加1  
//			if (CheckState(next)) // 如果状态满足约束条件则入队  
//			{
//				q.push(next);
//				vst[next.x][next.y] = 1; //访问标记  
//			}
//		}
//		q.pop(); // 队首元素出队  
//	}
//	return;
//}
//
//int main()
//{
//	......
//		return 0;
//}






//#include<cstdio>
//#include<queue>
//#include<cstring>
//using namespace std;
//struct point {
//	int x, y;
//	int time, step;//炸弹时间与步数
//};
//int dx[] = { 1,-1,0,0 };
//int dy[] = { 0,0,1,-1 };
//int n, m;
//int visit[10][10], map[10][10];
//int bfs(int sx, int sy)
//{
//	int i;
//	memset(visit, 0, sizeof(visit));
//	queue<point>Q;
//	point now, next;
//	now.x = sx; now.y = sy;
//	now.time = 6;
//	now.step = 0;
//	visit[now.x][now.y] = 1;
//	Q.push(now);
//	while (!Q.empty())
//	{
//		now = Q.front();
//		Q.pop();
//		if (map[now.x][now.y] == 3)
//			return now.step;
//		if (now.time <= 1)continue;
//		for (i = 0; i<4; i++)
//		{
//			next.x = now.x + dx[i];
//			next.y = now.y + dy[i];
//			if (next.x<1 || next.x>n || next.y<1 || next.y>m)continue;
//			if (map[next.x][next.y] == 0)continue;
//			if (visit[next.x][next.y] == 1)continue;
//			next.step = now.step + 1;
//			next.time = now.time - 1;
//			if (map[next.x][next.y] == 4)
//			{
//				next.time = 6;
//				visit[next.x][next.y] = 1;//确保只走一次,标记
//			}
//			Q.push(next);
//		}
//	}
//	return -1;
//}
//int main()
//{
//	int t, i, j, sx, sy;
//	while (~scanf("%d", &t)) {
//		while (t--)
//		{
//			scanf("%d %d", &n, &m);
//			sx = 1;
//			sy = 1;
//			for (i = 1; i <= n; i++)
//			{
//				for (j = 1; j <= m; j++)
//				{
//					scanf("%d", &map[i][j]);
//					if (map[i][j] == 2)
//					{
//						sx = i;
//						sy = j;
//					}
//				}
//			}
//			printf("%d\n", bfs(sx, sy));
//		}
//	}
//	return 0;
//}

//1072       搜索第1题，bfs；
//#include <cstdio>
//#include <queue>
//#include <cstring>
//using namespace std;
//struct node
//{
//	int x;
//	int y;
//	int time;
//	int step;
//};
//
//struct node now, after;
//int visit[10][10], ar[10][10], dir[4][2] = { { 1, 0 },{ -1, 0 },{ 0, 1 },{ 0, -1 } }, beginx, beginy, a, b;
//void bfs();
//int main()
//{
//	int i, j, k, u, n, m;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d", &a, &b);
//			beginx = 1;
//			beginy = 1;
//			for (i = 1; i <= a; i++)
//			{
//				for (j = 1; j <= b; j++)
//				{
//					scanf("%d", &ar[i][j]);
//					if (ar[i][j] == 2)
//					{
//						beginx = i;
//						beginy = j;
//					}
//				}
//			}
//			bfs();
//			printf("%d\n", now.step);
//		}
//	}
//	return 0;
//}
//void bfs()
//{
//	int i;
//	queue<node>q;
//	now.x = beginx;
//	now.y = beginy;
//	now.time = 6;
//	now.step = 0;
//	memset(visit, 0, sizeof(visit));
//	visit[now.x][now.y] = 1;
//	q.push(now);
//	while (q.empty() == 0)
//	{
//		now = q.front();
//		q.pop();
//		if (ar[now.x][now.y] == 3)
//			return;
//		if (now.time <= 1)
//			continue;
//		for (i = 0; i < 4; i++)
//		{
//			after.x = now.x + dir[i][0];
//			after.y = now.y + dir[i][1];
//			if (after.x < 1 || after.y < 1 || after.x > a || after.y > b)
//				continue;
//			if (visit[after.x][after.y] == 1)
//				continue;
//			if (ar[after.x][after.y] == 0)
//				continue;
//			after.step = now.step + 1;
//			after.time = now.time - 1;
//			if (ar[after.x][after.y] == 4)
//			{
//				after.time = 6;
//				visit[after.x][after.y] = 1;
//			}
//			q.push(after);
//		}
//	}
//	now.step = -1;
//}







//#include <stdio.h>
//int main()
//{
//	int i, j, k, u, n, m, a, b, ar[110], sum, S, doudou, x, y;
//	while (scanf("%d", &n) != EOF)
//	{
//		sum = 0;
//		S = 0;
//		doudou = 1;
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &ar[m]);
//			sum += ar[m];
//		}
//		if (sum % n != 0)
//		{
//			printf("silly linlihao159!\n");
//			continue;
//		}
//		sum /= n;
//		for (i = 1, j = n; i < n / 2, j > n / 2; i++, j--)
//		{
//			if (ar[i] > sum)
//			{
//				u = ar[i] - sum;
//				ar[i + 1] += u;
//				S += u;
//			}
//			if (ar[i] < sum)
//			{
//				u = sum - ar[i];
//				ar[i + 1] -= u;
//				S += u;
//			}
//			if (ar[j] > sum)
//			{
//				u = ar[j] - sum;
//				ar[j - 1] += u;
//				S += u;
//			}
//			if (ar[j] < sum)
//			{
//				u = sum - ar[j];
//				ar[j - 1] -= u;
//				S += u;
//			}
//		}
//		printf("%d\n", S);
//	}
//	return 0;
//}
//
//





// #include <iostream>
// #include <algorithm>
// #include <cstring>
//
// using namespace std;
//
// int t, n, m, dp[33333], v[30], p[30];
//
// int main()
// {
//     while (cin >> n >> m)
//     {
//         for (int i = 0; i<m; i++)
//             cin >> v[i] >> p[i];
//         memset(dp, 0, sizeof(dp));
//         for (int i = 0; i<m; i++)
//             for (int j = n; j >= v[i]; j--)
//                     dp[j] = max(dp[j], dp[j - v[i]] + v[i] * p[i]);
//         cout << dp[n] << endl;
//     }
//     return 0;
//}








//#include <stdio.h>
//#include <stdlib.h>
//struct shu
//{
//	int id;
//	unsigned long long int high;
//};
//int comp(const void * p1, const void * p2);
//int main()
//{
//	int i, j, k, u, n, m, h, count;
//	unsigned long long int d;
//	struct shu ar[110];
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			count = 0;
//			scanf("%d %llu", &k, &d);
//			for (u = 1; u <= k; u++)
//			{
//				scanf("%d %llu", &ar[u].id, &ar[u].high);
//			}
//			qsort(&ar[1], k, sizeof(struct shu), comp);
//			for (i = 1; i < k; i++)
//			{
//				if (ar[i + 1].high - ar[i].high != d)
//				{
//					count++;
//					ar[i + 1].high = ar[i].high + d;
//				}
//			}
//			printf("%d\n", count);
//		}
//	}
//	return 0;
//}
//int comp(const void * p1, const void * p2)
//{
//	const struct shu * a = (struct shu*)p1;
//	const struct shu * b = (struct shu*)p2;
//	return (a->id > b->id) ? 1 : -1;
//}








//#include <stdio.h>
//int main()
//{
//	int i, j, k, n, m;
//	while (scanf("%d", &n) != EOF)
//	{
//		m = 0;
//		while (n > 0)
//		{
//			m += n / 5;
//			n /= 5;
//		}
//		printf("%d\n", m);
//	}
//	return 0;
//}



//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//int main()
//{
//	int i, j, u, n, m, N, A, B, x, cnt, sum;
//	char k;
//	while (scanf("%d", &n) != EOF)
//	{
//		getchar();
//		for (m = 1; m <= n; m++)
//		{
//			cnt = 0;
//			sum = 0;
//			scanf("%c %d %d %d", &k, &N, &A, &B);
//			getchar();
//			if (k == 'k')
//				cnt++;
//			x = (int)k;
//			for (i = 1; i <= N; i++)
//			{
//				if ((x = ((x - 97) * A + B * i) % 26 + 97) == 107)
//				{
//					cnt++;
//					if (cnt == 7)
//					{
//						sum++;
//						cnt = 0;
//					}
//				}
//			}
//			printf("%d\n", sum);
//		}
//	}
//	return 0;
//}



//#include <stdio.h>
//int main()
//{
//	long long int n, p, q, a, b, c, doudou, i;
//	while (scanf("%lld %lld %lld", &n, &p, &q) != EOF)
//	{
//		if (n <= p)
//			printf("LOSE\n");
//		doudou = 0;
//		for (i = p; i <= q; i++)
//		{
//			if ((n - i) % (p + q) <= p)
//			{
//				printf("WIN\n");
//				doudou = 1;
//				break;
//			}
//		}
//		if (doudou == 0)
//			printf("LOSE\n");
//	}
//	return 0;
//}





//#include <stdio.h>
//#include <math.h>
//double C(int a, int b);
//double F(int a);
//int main()
//{
//	int i, j, k, u, n, m, L, a, b;
//	double x, y, l, sum;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d %lf", &a, &b, &x);
//			sum = 0.0;
//			for (i = a; i >= b; i--)
//			{
//				sum += C(a, i) * pow(x, i) * pow((1 - x), (a - i));
//			}
//			printf("%.3lf\n", sum);
//		}
//	}
//	return 0;
//}
//double C(int a, int b)
//{
//	return (double)F(a) / ((double)F(b) * (double)F(a - b));
//}
//double F(int a)
//{
//	double s = 1.0;
//	int i;
//	for (i = 1; i <= a; i++)
//		s *= i;
//	return s;
//}








//1175   搜索第2题 bfs；
//#include<cstdio>  
//#include<queue> 
//using namespace std;
//struct node
//{
//	int x;
//	int y;
//	int corner;
//	int sta;
//};
//queue<node>q;
//int dir[4][2] = { { -1,0 },{ 0,-1 },{ 1,0 },{ 0,1 } };
//int visit[1005][1005];
//int ar[1005][1005];
//int a, b;
//bool bfs(int x1, int y1, int x2, int y2);
//int main()
//{
//	int i, j, k, u, n, m, x1, x2, y1, y2;
//	struct node after;
//	while (scanf("%d %d", &a, &b) != EOF && (a || b))
//	{
//
//		for (i = 1; i <= a; i++)
//		{
//			for (j = 1; j <= b; j++)
//			{
//				scanf("%d", &ar[i][j]);
//			}
//		}
//		scanf("%d", &n);
//		for (u = 1; u <= n; u++)
//		{
//			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
//			if (ar[x1][y1] == 0 || ar[x2][y2] == 0 || ar[x1][y1] != ar[x2][y2] || (x1 == x2 && y1 == y2))
//			{
//				printf("NO\n");
//				continue;
//			}
//			for (i = 1; i <= a; i++)
//			{
//				for (j = 1; j <= b; j++)
//					visit[i][j] = 11;
//			}
//			visit[x1][y1] = 0;
//			while (!q.empty())
//				q.pop();
//			for (i = 0; i < 4; i++)
//			{
//				after.sta = i;
//				after.corner = 0;
//				after.x = x1;
//				after.y = y1;
//				q.push(after);
//			}
//			if (bfs(x1, y1, x2, y2) == true)
//				printf("YES\n");
//			else
//				printf("NO\n");
//		}
//	}
//	return 0;
//}
//bool bfs(int x1, int y1, int x2, int y2)
//{
//	int i, j;
//	struct node now, after;
//
//	while (q.empty() == 0)
//	{
//		now = q.front();
//		q.pop();
//
//		if (now.x == x2 && now.y == y2 && now.corner <= 2)
//			return true;
//
//		for (i = 0; i < 4; i++)
//		{
//			after.x = now.x + dir[i][0];
//			after.y = now.y + dir[i][1];
//
//			if (after.x < 1 || after.x > a || after.y < 1 || after.y > b)
//				continue;
//			if (now.sta == i)
//			{
//				after.corner = now.corner;
//				after.sta = now.sta;
//			}
//			else
//			{
//				after.corner = now.corner + 1;
//				after.sta = i;
//			}
//			if (after.corner > 2)
//				continue;
//			if (((after.x == x2 && after.y == y2) || ar[after.x][after.y] == 0) && after.corner <= visit[after.x][after.y])
//			{
//				q.push(after);
//				visit[after.x][after.y] = after.corner;
//			}
//		}
//	}
//	return false;
//}







//1180  搜索第3题bfs；
//#include <cstdio>
//#include <cstring>
//#include <queue>
//using namespace std;
//struct node
//{
//	int x;
//	int y;
//	int time;
//	int sta;
//};
//struct node now, after, temp;
//queue<node>q;
//int a, b, visit[25][25], dir[4][2] = { { 0, 1 },{ 0, -1 },{ -1, 0 },{ 1, 0 } };
//char ar[25][25];
//int bfs(int x1, int y1, int x2, int y2);
//int main()
//{
//	int i, j, k, n, m, x1, x2, y1, y2;
//	struct node temp;
//	while (scanf("%d %d", &a, &b) != EOF)
//	{
//		getchar();
//		for (i = 1; i <= a; i++)
//		{
//			for (j = 1; j <= b; j++)
//			{
//				scanf("%c", &ar[i][j]);
//				if (ar[i][j] == 'S')
//				{
//					x1 = i;
//					y1 = j;
//				}
//				if (ar[i][j] == 'T')
//				{
//					x2 = i;
//					y2 = j;
//				}
//			}
//			getchar();
//		}
//		/*printf("%d %d %d %d\n", x1, y1, x2, y2);
//		printf("%c %c\n", ar[x1][y1], ar[x2][y2]);*/
//		for (i = 0; i < 25; i++)
//		{
//			for (j = 0; j < 25; j++)
//				visit[i][j] = 1000;
//		}
//		visit[x1][y1] = 0;
//		while (!q.empty())
//			q.pop();
//		for (i = 0; i < 4; i++)
//		{
//			temp.x = x1;
//			temp.y = y1;
//			temp.sta = i;
//			temp.time = 0;
//			q.push(temp);
//		}
//		i = bfs(x1, y1, x2, y2);
//		printf("%d\n", visit[x2][y2]);
//	}
//	return 0;
//}
//int bfs(int x1, int y1, int x2, int y2)
//{
//	int i, j;
//
//	/*now.x = x1;
//	now.y = y1;
//	now.sta = -1;
//	now.time = 0;
//	visit[x1][y1] = 0;
//	q.push(now);*/
//
//	while (!q.empty())
//	{
//		now = q.front();
//		q.pop();
//		/*printf("%d %d\n", now.x, now.y);
//		printf("%c\n", ar[now.x][now.y]);*/
//
//		for (i = 0; i < 4; i++)
//		{
//			after.x = now.x + dir[i][0];
//			after.y = now.y + dir[i][1];
//			after.sta = i;
//			after.time = now.time + 1;
//
//			if (after.x < 1 || after.x > a || after.y < 1 || after.y > b)
//				continue;
//			if (ar[after.x][after.y] == '*')
//				continue;
//
//			if (ar[after.x][after.y] == '|')
//			{
//				if (now.time % 2 == 0)
//				{
//					if (after.sta == 0)
//						if (ar[after.x][after.y + 1] != '*')
//						{
//							after.y = after.y + 1;
//							after.time++;
//						}
//					if (after.sta == 1)
//						if (ar[after.x][after.y - 1] != '*')
//						{
//							after.y = after.y - 1;
//							after.time++;
//						}
//					if (after.sta == 2)
//					{
//						if (ar[after.x - 1][after.y] != '*')
//							after.x = after.x - 1;
//					}
//					if (after.sta == 3)
//					{
//						if (ar[after.x + 1][after.y] != '*')
//							after.x = after.x + 1;
//					}
//				}
//				if (now.time % 2 != 0)
//				{
//					if (after.sta == 0)
//					{
//						if (ar[after.x][after.y + 1] != '*')
//							after.y = after.y + 1;
//					}
//					if (after.sta == 1)
//					{
//						if (ar[after.x][after.y - 1] != '*')
//							after.y = after.y - 1;
//					}
//					if (after.sta == 2)
//					{
//						if (ar[after.x - 1][after.y] != '*')
//						{
//							after.x = after.x - 1;
//							after.time++;
//						}
//					}
//					if (after.sta == 3)
//					{
//						if (ar[after.x + 1][after.y] != '*')
//						{
//							after.x = after.x + 1;
//							after.time++;
//						}
//					}
//				}
//			}
//			if (ar[after.x][after.y] == '-')
//			{
//				if (now.time % 2 == 0)
//				{
//					if (after.sta == 0)
//					{
//						if (ar[after.x][after.y + 1] != '*')
//							after.y = after.y + 1;
//					}
//					if (after.sta == 1)
//					{
//						if (ar[after.x][after.y - 1] != '*')
//							after.y = after.y - 1;
//					}
//					if (after.sta == 2)
//					{
//						if (ar[after.x - 1][after.y] != '*')
//						{
//							after.x = after.x - 1;
//							after.time++;
//						}
//					}
//					if (after.sta == 3)
//					{
//						if (ar[after.x + 1][after.y] != '*')
//						{
//							after.x = after.x + 1;
//							after.time++;
//						}
//					}
//				}
//				if (now.time % 2 != 0)
//				{
//					if (after.sta == 0)
//						if (ar[after.x][after.y + 1] != '*')
//						{
//							after.y = after.y + 1;
//							after.time++;
//						}
//					if (after.sta == 1)
//						if (ar[after.x][after.y - 1] != '*')
//						{
//							after.y = after.y - 1;
//							after.time++;
//						}
//					if (after.sta == 2)
//					{
//						if (ar[after.x - 1][after.y] != '*')
//							after.x = after.x - 1;
//					}
//					if (after.sta == 3)
//					{
//						if (ar[after.x + 1][after.y] != '*')
//							after.x = after.x + 1;
//					}
//				}
//			}
//			if ((ar[after.x][after.y] == '.' || ar[after.x][after.y] == 'T') && after.time < visit[after.x][after.y])
//			{
//				q.push(after);
//				visit[after.x][after.y] = after.time;
//			}
//		}
//	}
//	return -1;
//}







//dfs模板；
//#include <iostream>
//#include <cstdio>
//#include <cstring>
//using namespace std;
//
//const int MAXN = 47;
//
//struct Pos
//{
//	int x, y;
//	bool operator == (const Pos &oth) const
//	{
//		return x == oth.x && y == oth.y;
//	}
//}src, tar;
//int n, m;
//char maze[MAXN][MAXN];
//bool vis[MAXN][MAXN];
//const int dir[4][2] = { -1, 0, 0, -1, 1, 0, 0, 1 };
//
//bool DFS(Pos crt)
//{
//	if (crt == tar)
//	{
//		return true;
//	}
//	Pos nxt;
//	for (int i = 0; i < 4; ++i)
//	{
//		nxt = crt;
//		nxt.x += dir[i][0];
//		nxt.y += dir[i][1];
//		if (nxt.x < 0 || nxt.x >= n || nxt.y < 0 || nxt.y >= m ||
//			'*' == maze[nxt.x][nxt.y] || true == vis[nxt.x][nxt.y])
//		{
//			continue;
//		}
//		vis[nxt.x][nxt.y] = true;
//		if (DFS(nxt))
//		{
//			return true;
//		}
//		vis[nxt.x][nxt.y] = false;
//	}
//	return false;
//}
//void ace()
//{
//	while (cin >> n >> m)
//	{
//		memset(vis, false, sizeof(vis));
//		for (int i = 0; i < n; ++i)
//		{
//			cin >> maze[i];
//		}
//		for (int i = 0; i < n; ++i)
//		{
//			for (int j = 0; j < m; ++j)
//			{
//				if ('S' == maze[i][j])
//				{
//					src.x = i;
//					src.y = j;
//				}
//				else if ('E' == maze[i][j])
//				{
//					tar.x = i;
//					tar.y = j;
//				}
//			}
//		}
//		vis[src.x][src.y] = true;
//		if (DFS(src))
//		{
//			cout << "I can find the path!" << endl;
//		}
//		else
//		{
//			cout << "No such a path!" << endl;
//		}
//	}
//	return;
//}
//int main()
//{
//	ace();
//	return 0;
//}







//1181  搜索第4题，dfs；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//using namespace std;
//struct node
//{
//	char begin;
//	char end;
//	char word;
//};
//struct node ar[10000];
//bool visit[10000];
//int k;
//bool doudou = false;
//bool dfs(char ch);
//int main()
//{
//	int i, j, u, n, m;
//	char sa[100];
//	while (scanf("%s", sa) != EOF)
//	{
//		k = 1;
//		while (strcmp(sa, "0") != 0)
//		{
//			ar[k].begin = sa[0];
//			ar[k].end = sa[strlen(sa) - 1];
//			k++;
//			scanf("%s", sa);
//		}
//		doudou = false;
//		for (i = 1; i < k; i++)
//		{
//			if (ar[i].begin == 'b')
//			{
//				memset(visit, false, sizeof(visit));
//				visit[i] = true;
//				if (dfs(ar[i].end) == true)
//				{
//					doudou = true;
//					break;
//				}
//			}
//		}
//		if (doudou)
//			printf("Yes.\n");
//		else
//			printf("No.\n");
//	}
//	return 0;
//}
//bool dfs(char ch)
//{
//	int i, j;
//	if (ch == 'm')
//		return true;
//	for (i = 1; i < k; i++)
//	{
//		if (ar[i].begin == ch && !visit[i])
//		{
//			visit[i] = true;
//			if (dfs(ar[i].end) == true)
//			{
//				return true;
//			}
//			visit[i] = false;
//		}
//	}
//	return false;
//}








//1242  搜索第5题 bfs   普通队列  一 ！ 定！要！ 搜！完！  不能中间return；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <queue>
//using namespace std;
//struct node
//{
//	int x;
//	int y;
//	int time;
//};
//struct node now, after;
//int visit[205][205], a, b;
//int dir[4][2] = { 0, 1, 0, -1, -1, 0, 1, 0 }; //右左上下
//char ar[205][205];
//void bfs(int x1, int y1, int x2, int y2);
//int main()
//{
//	int i, j, k, temp, min, x1, y1, x2, y2, n, m;
//	while (scanf("%d %d", &a, &b) != EOF)
//	{
//		getchar();
//		for (i = 1; i <= a; i++)
//		{
//			for (j = 1; j <= b; j++)
//			{
//				scanf("%c", &ar[i][j]);
//				if (ar[i][j] == 'a')
//				{
//					x2 = i;
//					y2 = j;
//				}
//			}
//			getchar();
//		}
//		min = 100000000;
//		for (i = 1; i <= a; i++)
//		{
//			for (j = 1; j <= b; j++)
//			{
//				if (ar[i][j] == 'r')
//				{
//					x1 = i;
//					y1 = j;
//					for (n = 0; n <= a; n++)
//					{
//						for (m = 0; m <= b; m++)
//							visit[n][m] = 1000000;
//					}
//					bfs(x1, y1, x2, y2);
//					temp = visit[x2][y2];
//					if (temp != 1000000)
//						min = (min <= temp) ? min : temp;
//				}
//			}
//		}
//		if (min != 100000000)
//			printf("%d\n", min);
//		else
//			printf("Poor ANGEL has to stay in the prison all his life.\n");
//	}
//	return 0;
//}
//void bfs(int x1, int y1, int x2, int y2)
//{
//	queue<node>q;
//	int i, j;
//	now.x = x1;
//	now.y = y1;
//	now.time = 0;
//	q.push(now);
//	while (!q.empty())
//	{
//		now = q.front();
//		q.pop();
//		for (i = 0; i < 4; i++)
//		{
//			after.x = now.x + dir[i][0];
//			after.y = now.y + dir[i][1];
//			after.time = now.time + 1;
//			if (after.x > a || after.x < 1 || after.y > b || after.y < 1)
//				continue;
//			if (ar[after.x][after.y] == '#')
//				continue;
//			if (ar[after.x][after.y] == 'x')
//			{
//				after.time++;
//				/*ar[after.x][after.y] = '.';*/
//			}
//			if ((ar[after.x][after.y] == '.' || ar[after.x][after.y] == 'a' || ar[after.x][after.y] == 'r' || ar[after.x][after.y] == 'x') && after.time < visit[after.x][after.y])
//			{
//				q.push(after);
//				visit[after.x][after.y] = after.time;
//			}
//		}
//	}
//	return;
//}
















//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int main()
//{
//	int i, j, k, n, m, u, d;
//	char ar[200][100], s[100];
//	while (scanf("%d %d", &m, &d) != EOF && (m || d))
//	{
//		if (d == 1)
//		{
//			printf("2\n");
//			continue;
//		}
//		ar[0][0] = '1';
//		ar[1][0] = '2';
//		for (i = 2; i <= d; i++)
//		{
//			if (i <= m)
//			{
//				if ((u = i + 1) < 10)
//				{
//					itoa(u, s, 10);
//					strcpy(ar[i], s);
//				}
//				else
//				{
//					itoa(u - 10, s, 10);
//					s[1] = '1';
//					strcpy(ar[i], s);
//				}
//			}
//			else
//			{
//				for (j = 0; ar[i-1][j] != '\0'; j++)
//				{
//					if (ar[i - m][j] + ar[i - 1][j] < '10')
//						ar[i][j] = ar[i - m][j] + ar[i - 1][j];
//					else
//					{
//						ar[i][j] = ar[i - m][j] + ar[i - 1][j] - '10';
//						ar[i - m][j + 1] = ar[i - m][j + 1] + '1';
//					}
//				}
//			}
//		}
//		if(ar[d - 1])
//		k = strlen(ar[d]);
//		for (j = k - 1; j >= 0; j--)
//			printf("%c", ar[d][j]);
//		putchar('\n');
//	}
//	return 0;
//}



//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//struct dict
//{
//	int sta;
//	struct dict *next[26];
//};
//void insert(struct dict *root, char *s);
//int search(struct dict *root, char *s);
//void del(struct dict *root);
//int main()
//{
//	int i, j, k, u, n, m, count, c;
//	char ar[110][110], s[110];
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			struct dict *root;
//			root = (struct dict *)malloc(sizeof(struct dict));
//			for (i = 0; i < 26; i++)
//				root->next[i] = NULL;
//			root->sta = 0;
//
//			scanf("%d", &k);
//			for (u = 0; u < k; u++)
//			{
//				scanf("%s", ar[u]);
//				insert(root, ar[u]);
//			}
//			count = 0;
//			for (j = 0; j < k; j++)
//			{
//				strcpy(s, ar[j]);
//				for (i = 0; s[i] != '\0'; i++)
//				{
//					if (s[i] == 'A')
//						s[i] = 'T';
//					else if (s[i] == 'T')
//						s[i] = 'A';
//					else if (s[i] == 'C')
//						s[i] = 'G';
//					else if (s[i] == 'G')
//						s[i] = 'C';
//				}
//				c = search(root, s);
//				if (c != 0)
//					count += c;
//			}
//			printf("%d\n", count / 2);
//			del(root);
//		}
//		
//	}
//	return 0;
//}
//void insert(struct dict *root, char *s)
//{
//	int i, j;
//	struct dict *temp, *p = root;
//
//	while (*s != '\0')
//	{
//		if (p->next[*s - 'A'] == NULL)
//		{
//			temp = (struct dict *)malloc(sizeof(struct dict));
//			for (i = 0; i < 26; i++)
//				temp->next[i] = NULL;
//			temp->sta = 0;
//
//			p->next[*s - 'A'] = temp;
//		}
//		p = p->next[*s - 'A'];
//		s++;
//	}
//	p->sta++;
//}
//int search(struct dict *root, char *s)
//{
//	int i;
//	struct dict *p = root;
//	char *q = s;
//	while (*q != '\0' && p != NULL)
//	{
//		p = p->next[*q - 'A'];
//		q++;
//	}
//	if (p != NULL && p->sta != 0)
//		return p->sta;
//	return 0;
//}
//void del(struct dict *root)
//{
//	int i;
//	for (i = 0; i < 26; i++)
//	{
//		if (root->next[i] != NULL)
//			del(root->next[i]);
//	}
//	free(root);
//}








//#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
//int main()
//{
//	int i, j, k, n, m, u, a, b, c, L, D, S;
//	double ang, sum, r, bng;
//	while (scanf("%d", &n) != EOF)
//	{
//
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d %d", &L, &D, &S);
//			if (D >= S)
//			{
//				printf("%.2lf\n", 3.1415926 * S * S);
//				continue;
//			}
//			ang = atan(2.0 * D / (1.0 * L));
//			r = S - pow(1.0*D*1.0*D + 1.0 * L * 1.0 * L / 4.0, 0.5);
//			if (r <= 0.5 * L)
//			{
//				sum = 1.0 / 4.0 * S * 1.0 * S * 3.1415926 + 1.0 / 2.0 * ang * S * S + 1.0 * L / 2.0 * 1.0 * D * 0.5 + 0.5 * r * r * (3.1415926 - ang);
//				printf("%.2lf\n", sum * 2.0);
//			}
//			else
//			{
//				bng = acos(1.0 * L / (2.0 * r));
//				sum = 1.0 / 4.0 * S * 1.0 * S * 3.1415926 + 1.0 / 2.0 * ang * S * S + 1.0 * L / 2.0 * 1.0 * D * 0.5 + 0.5 * r * r * (3.1415926 - ang) - bng * 0.5 * r * r + 0.25 * L * sqrt(r * r - 0.25 * L * L);
//				printf("%.2lf\n", sum * 2.0);
//			}
//		}
//	}
//	return 0;
//}



//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//struct wocao
//{
//	int count;
//	struct wocao *next[26];
//};
//void insert(struct wocao *root, char *ar);
//int search(struct wocao *root, char *ar);
//void del(struct wocao *root);
//int main()
//{
//	char ar[101], a[101], set[20001];
//	int i, j, k, u, n, m, count, doudou;
//	struct wocao * root;
//	while (scanf("%d", &n) != EOF && n)
//	{
//		scanf("%d", &m);
//		root = (struct wocao *)malloc(sizeof(struct wocao));
//		for (i = 0; i < 26; i++)
//		{
//			root->next[i] = NULL;
//		}
//		root->count = 0;
//		for (u = 1; u <= n; u++)
//		{
//			scanf("%s", ar);
//			insert(root, ar);
//		}
//		count = 0;
//		memset(set, 0, sizeof(set));
//		for (u = 1; u <= m; u++)
//		{
//			scanf("%s", a);
//			if (search(root, a))
//				count++;
//		}
//		printf("%d\n", n - count);
//		del(root);
//	}
//	return 0;
//}
//void insert(struct wocao * root, char *s)
//{
//	int i;
//	struct wocao *temp, *p = root;
//	while (*s != '\0')
//	{
//		if (p->next[*s - 'a'] == NULL)
//		{
//			temp = (struct wocao *)malloc(sizeof(struct wocao));
//			for (i = 0; i < 26; i++)
//				temp->next[i] = NULL;
//			p->count = 0;
//			p->next[*s - 'a'] = temp;
//		}
//		p = p->next[*s - 'a'];
//		s++;
//	}
//	p->count = 1;
//}
//int search(struct wocao *root, char *ar)
//{
//	int i;
//	struct wocao *p = root;
//	while (*ar != '\0' && p != NULL)
//	{
//		p = p->next[*ar - 'a'];
//		ar++;
//	}
//	if (p != NULL && p->count == 1)
//	{
//		p->count = 0;
//		return 1;
//	}
//}
//
//void del(struct wocao *root)
//{
//	int i;
//	for (i = 0; i < 26; i++)
//	{
//		if (root->next[i] != NULL)
//			del(root->next[i]);
//	}
//	free(root);
//}







//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//struct ss
//{
//	char a[110];
//};
//int comp(const void * p1, const void * p2);
//int main()
//{
//	int i, j, k, n, m, u;
//	struct ss ar[100];
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &k);
//			for (u = 0; u < k; u++)
//			{
//				scanf("%s", ar[u].a);
//			}
//			qsort(ar, k, sizeof(struct ss), comp);
//			for (i = 0; i < k; i++)
//			{
//				printf("%s", ar[i].a);
//			}
//			putchar('\n');
//		}
//	}
//	return 0;
//}
//int comp(const void * p1, const void * p2)
//{
//	struct ss * b = (struct ss *)p1;
//	struct ss * c = (struct ss *)p2;
//	char s[101], w[101];
//	strcpy(s, b->a);
//	strcpy(w, c->a);
//	strcat(s, c->a);
//	strcat(w, b->a);
//	return strcmp(s, w);
//}


//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int main()
//{
//	int a, b, c, i, j, k, n, m, ar[110], count;
//	while (scanf("%d", &n) != EOF && n)
//	{
//
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &ar[m]);
//		}
//		for (i = 1; i <= n; i++)
//		{
//			count = 1;
//			if (ar[i] == -1)
//				continue;
//			for (j = i + 1; j <= n; j++)
//			{
//				if (ar[i] == ar[j] && ar[j] != -1)
//				{
//					count++;
//					ar[j] = -1;
//				}
//			}
//			if (count % 2 != 0)
//			{
//				printf("%d\n", ar[i]);
//				break;
//			}
//		}
//	}
//	return 0;
//}










//1253    搜索第6题 bfs   三维的；
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <queue>
//using namespace std;
//struct node
//{
//	int x;
//	int y;
//	int z;
//	int time;
//};
//struct node now, after;
//int a, b, c, t;
//int dir[6][3] = { { 0, 0, 1 },{ 0, 0, -1 },{ 0, -1, 0 },{ 0, 1, 0 },{ 1, 0, 0 },{ -1, 0, 0 } };
//int visit[55][55][55], ar[55][55][55];
//void bfs();
//int main()
//{
//	int i, j, k, u, n, m;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 0; m < n; m++)
//		{
//			scanf("%d %d %d %d", &a, &b, &c, &t);
//			for (u = 1; u <= a; u++)
//			{
//				for (i = 1; i <= b; i++)
//				{
//					for (j = 1; j <= c; j++)
//					{
//						scanf("%d", &ar[u][i][j]);
//						visit[u][i][j] = 10000000;
//					}
//				}
//			}
//			bfs();
//			if (visit[a][b][c] != 10000000 && visit[a][b][c] <= t)
//				printf("%d\n", visit[a][b][c]);
//			else
//				printf("-1\n");
//		}
//	}
//	return 0;
//}
//void bfs()
//{
//	int i, j, k, u;
//	queue<node>q;
//	now.x = 1;
//	now.y = 1;
//	now.z = 1;
//	now.time = 0;
//	q.push(now);
//	while (!q.empty())
//	{
//		now = q.front();
//		q.pop();
//		for (i = 0; i < 6; i++)
//		{
//			after.x = now.x + dir[i][0];
//			after.y = now.y + dir[i][1];
//			after.z = now.z + dir[i][2];
//			after.time = now.time + 1;
//			if (after.x < 1 || after.y < 1 || after.z < 1 || after.x > b || after.y > c || after.z > a)
//				continue;
//			if (ar[after.z][after.x][after.y] == 1)
//				continue;
//			if (after.time > t || (after.time == t && (after.x != b || after.y != c || after.z != a)))
//				continue;
//			if (ar[after.z][after.x][after.y] == 0 && after.time < visit[after.z][after.x][after.y])
//			{
//				q.push(after);
//				visit[after.z][after.x][after.y] = after.time;
//			}
//		}
//	}
//	return;
//}








//1495  搜索bfs第7题   仍然三维  但是不要dir， 直接模拟；
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <queue>
//using namespace std;
//struct node
//{
//	int x;
//	int y;
//	int z;
//	int count;
//};
//struct node now, after;
//int s, m, n;
//int dir[6][3];
//int visit[102][102][102];
//void bfs();
//int main()
//{
//	int i, j, k, u, temp;
//	while (scanf("%d %d %d", &s, &n, &m) != EOF && (s || n || m))
//	{
//		if (s % 2 == 1)
//		{
//			printf("NO\n");
//			continue;
//		}
//		if (n < m)
//		{
//			temp = n;
//			n = m;
//			m = temp;
//		}
//		bfs();
//		if (visit[s / 2][s / 2][0] != 10000000)
//			printf("%d\n", visit[s / 2][s / 2][0]);
//		else
//			printf("NO\n");
//	}
//	return 0;
//}
//void bfs()
//{
//	int i, j, k, u;
//	queue<node>q;
//
//	for (i = 0; i <= s; i++)
//	{
//		for (j = 0; j <= n; j++)
//		{
//			for (k = 0; k <= m; k++)
//			{
//				visit[i][j][k] = 10000000;
//			}
//		}
//	}
//	now.x = s;
//	now.y = 0;
//	now.z = 0;
//	now.count = 0;
//	q.push(now);
//	while (!q.empty())
//	{
//		now = q.front();
//		q.pop();
//		for (i = 1; i <= 6; i++)
//		{
//			if (i == 1 && now.x)
//			{
//				if (now.x + now.y >= n)
//				{
//					after.x = now.x - n + now.y;
//					after.y = n;
//					after.z = now.z;
//					after.count = now.count + 1;
//				}
//				else
//				{
//					after.x = 0;
//					after.y = now.y + now.x;
//					after.z = now.z;
//					after.count = now.count + 1;
//				}
//				if (after.x < 0 || after.y < 0 || after.z < 0 || after.x > s || after.y > n || after.z > m)
//					continue;
//				if (after.count < visit[after.x][after.y][after.z])
//				{
//					q.push(after);
//					visit[after.x][after.y][after.z] = after.count;
//				}
//			}
//			if (i == 2 && now.x)
//			{
//				if (now.x + now.z >= m)
//				{
//					after.x = now.x - m + now.z;
//					after.y = now.y;
//					after.z = m;
//					after.count = now.count + 1;
//				}
//				else
//				{
//					after.x = 0;
//					after.y = now.y;
//					after.z = now.z + now.x;
//					after.count = now.count + 1;
//				}
//				if (after.x < 0 || after.y < 0 || after.z < 0 || after.x > s || after.y > n || after.z > m)
//					continue;
//				if (after.count < visit[after.x][after.y][after.z])
//				{
//					q.push(after);
//					visit[after.x][after.y][after.z] = after.count;
//				}
//			}
//			if (i == 3 && now.y)
//			{
//				if (now.y + now.x >= s)
//				{
//					after.x = s;
//					after.y = now.y - s + now.x;
//					after.z = now.z;
//					after.count = now.count + 1;
//				}
//				else
//				{
//					after.x = now.x + now.y;
//					after.y = 0;
//					after.z = now.z;
//					after.count = now.count + 1;
//				}
//				if (after.x < 0 || after.y < 0 || after.z < 0 || after.x > s || after.y > n || after.z > m)
//					continue;
//				if (after.count < visit[after.x][after.y][after.z])
//				{
//					q.push(after);
//					visit[after.x][after.y][after.z] = after.count;
//				}
//			}
//			if (i == 4 && now.y)
//			{
//				if (now.y + now.z >= m)
//				{
//					after.x = now.x;
//					after.y = now.y - m + now.z;
//					after.z = m;
//					after.count = now.count + 1;
//				}
//				else
//				{
//					after.x = now.x;
//					after.y = 0;
//					after.z = now.y + now.z;
//					after.count = now.count + 1;
//				}
//				if (after.x < 0 || after.y < 0 || after.z < 0 || after.x > s || after.y > n || after.z > m)
//					continue;
//				if (after.count < visit[after.x][after.y][after.z])
//				{
//					q.push(after);
//					visit[after.x][after.y][after.z] = after.count;
//				}
//			}
//			if (i == 5 && now.z)
//			{
//				if (now.z + now.x >= s)
//				{
//					after.x = s;
//					after.y = now.y;
//					after.z = now.z - s + now.x;
//					after.count = now.count + 1;
//				}
//				else
//				{
//					after.x = now.x + now.z;
//					after.y = now.y;
//					after.z = 0;
//					after.count = now.count + 1;
//				}
//				if (after.x < 0 || after.y < 0 || after.z < 0 || after.x > s || after.y > n || after.z > m)
//					continue;
//				if (after.count < visit[after.x][after.y][after.z])
//				{
//					q.push(after);
//					visit[after.x][after.y][after.z] = after.count;
//				}
//			}
//			if (i == 6 && now.z)
//			{
//				if (now.z + now.y >= n)
//				{
//					after.x = now.x;
//					after.y = n;
//					after.z = now.z - n + now.y;
//					after.count = now.count + 1;
//				}
//				else
//				{
//					after.x = now.x;
//					after.y = now.y + now.z;
//					after.z = 0;
//					after.count = now.count + 1;
//				}
//				if (after.x < 0 || after.y < 0 || after.z < 0 || after.x > s || after.y > n || after.z > m)
//					continue;
//				if (after.count < visit[after.x][after.y][after.z])
//				{
//					q.push(after);
//					visit[after.x][after.y][after.z] = after.count;
//				}
//			}
//		}
//	}
//	return;
//}







//1728   搜索第8题bfs;
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <queue>
//using namespace std;
//struct node
//{
//	int x;
//	int y;
//	int sta;
//	int turn;
//};
//struct node now, after;
//int dir[4][2] = { 0, 1, 0, -1, -1, 0, 1, 0 };
//int visit[105][105];
//char ar[105][105];
//int n, m, x1, y1, x2, y2, k;
//queue<node>q;
//void bfs();
//int main()
//{
//	int i, j, u, a, b;
//	struct node temp;
//	while (scanf("%d", &a) != EOF)
//	{
//		for (b = 1; b <= a; b++)
//		{
//			scanf("%d %d", &n, &m);
//			for (i = 1; i <= n; i++)
//			{
//				scanf("%s", ar[i] + 1);
//			}
//			scanf("%d %d %d %d %d", &k, &y1, &x1, &y2, &x2);
//			if (ar[x2][y2] == '*' || ar[x1][y1] == '*' || k < 0)
//			{
//				printf("no\n");
//				continue;
//			}
//			while (!q.empty())
//				q.pop();
//			for (i = 0; i <= n; i++)
//			{
//				for (j = 0; j <= m; j++)
//				{
//					visit[i][j] = 10000000;
//				}
//			}
//			for (i = 0; i < 4; i++)
//			{
//				temp.x = x1;
//				temp.y = y1;
//				temp.sta = i;
//				temp.turn = 0;
//				q.push(temp);
//			}
//			bfs();
//			if (visit[x2][y2] >= 0 && visit[x2][y2] <= k)
//				printf("yes\n");
//			else
//				printf("no\n");
//		}
//	}
//	return 0;
//}
//void bfs()
//{
//	int i, j, u;
//	while (!q.empty())
//	{
//		now = q.front();
//		q.pop();
//		for (i = 0; i < 4; i++)
//		{
//			after.x = now.x + dir[i][0];
//			after.y = now.y + dir[i][1];
//			if (now.sta != i)
//			{
//				after.sta = i;
//				after.turn = now.turn + 1;
//			}
//			else
//			{
//				after.sta = i;
//				after.turn = now.turn;
//			}
//			if (after.turn > k || (after.turn == k && after.x != x2 && after.y != y2))
//				continue;
//			if (after.x < 1 || after.y < 1 || after.x > n || after.y > m || ar[after.x][after.y] == '*')
//				continue;
//			if (ar[after.x][after.y] == '.' && visit[after.x][after.y] >= after.turn)
//			{
//				q.push(after);
//				visit[after.x][after.y] = after.turn;
//			}
//		}
//	}
//	return;
//}





//2544  朴素dijkstra；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//#define MAX 100000000
//int n, m;
//int ar[110][110], dist[110];
//bool visit[110];
//void dijkstra();
//int main()
//{
//	int i, j, k, u, a, b, c;
//
//	while (scanf("%d %d", &n, &m) != EOF && (n || m))
//	{
//		for (i = 0; i <= n; i++)
//		{
//			for (j = 0; j <= n; j++)
//			{
//				ar[i][j] = MAX;
//			}
//		}
//		memset(visit, false, sizeof(visit));
//		for (u = 1; u <= m; u++)
//		{
//			scanf("%d %d %d", &a, &b, &c);
//			ar[a][b] = c;
//			ar[b][a] = c;
//		}
//		dijkstra();
//		printf("%d\n", dist[n]);
//	}
//	return 0;
//}
//void dijkstra()
//{
//	int i, j, k, u, midmin, near;
//	for (i = 1; i <= n; i++)
//		dist[i] = ar[1][i];
//	dist[1] = 0;
//	visit[1] = true;
//	for (i = 2; i <= n; i++)
//	{
//		midmin = MAX;
//		near = MAX;
//		for (j = 2; j <= n; j++)
//		{
//			if (!visit[j] && dist[j] < midmin)
//			{
//				midmin = dist[j];
//				near = j;
//			}
//		}
//		visit[near] = true;
//		for (j = 2; j <= n; j++)
//		{
//			if (!visit[j] && ar[near][j] != MAX && dist[near] + ar[near][j] < dist[j])						
//			{
//				dist[j] = dist[near] + ar[near][j];																									
//			}
//		}
//	}
//}

//2544  朴素SPFA；
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <queue>
//#define MAX 100000000
//using namespace std;
//
//int num[110], ar[110][110], dist[110], n, m;
//bool visit[110];
//void SPFA();
//
//int main()
//{
//	int i, j, k, u, a, b, c;
//	while (scanf("%d %d", &n, &m) != EOF && (n || m))
//	{
//		for (i = 0; i <= n; i++)
//		{
//			for (j = 0; j <= n; j++)
//			{
//				ar[i][j] = MAX;
//			}
//		}
//		for (u = 1; u <= m; u++)
//		{
//			scanf("%d %d %d", &a, &b, &c);
//			ar[a][b] = c;
//			ar[b][a] = c;
//		}
//		SPFA();
//		printf("%d\n", dist[n]);
//	}
//	return 0;
//}
//void SPFA()
//{
//	int i, j, k, u, near;
//	queue<int>q;
//	memset(num, 0, sizeof(num));
//	memset(visit, false, sizeof(visit));
//	for (i = 0; i <= n; i++)
//		dist[i] = MAX;
//	dist[1] = 0;
//	q.push(1);
//	while (!q.empty())
//	{
//		near = q.front();
//		q.pop();
//		visit[near] = false;
//		for (i = 1; i <= n; i++)
//		{
//			if (dist[i] > dist[near] + ar[near][i])
//			{
//				dist[i] = dist[near] + ar[near][i];
//				if (!visit[i])
//				{
//					visit[i] = true;
//					num[i]++;
//					if (num[i] >= n)
//						return;
//					q.push(i);
//				}
//			}
//		}
//	}
//}

//1874    dijkstra堆优化模板；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <iostream>
//#include <queue>
//
//#include<vector>
//#define MAX 9999999
//
//using namespace std;
////pair 的first 保存的为最短距离, second保存的为顶点编号
//typedef pair<int, int >P;//对组  不知道请自行百度   
//
//struct node
//{
//	int v, w;//v 为到达的点, w为权重
//	int next;//记录下一个结构体的位置 ，就向链表的next功能是一样的
//};
//node edge[2003];//存所有的边，因为是无向图，所以*2
//int dis[203];//最短路径数组
//int cnt;//结构体的下标
//int n, s, t;//n 点数,s 起点,t止点
//int head[203];//和链表的头指针数组是一样的。只不过此处head[u]记录的为最后加入 edge 的且与u相连的边在 edge 中的位置，即下标
//struct cmp
//{
//	bool operator()(P a, P b)
//	{
//		return a.first>b.first;
//	}
//};
//void add(int u, int v, int w)//加边操作
//{
//	edge[cnt].v = v;
//	edge[cnt].w = w;
//	edge[cnt].next = head[u];//获得下一个结构体的位置
//	head[u] = cnt++;//记录头指针的下标
//}
//void dijkstra()
//{
//	int i, v;//v保存从队列中取出的数的第二个数  也就是顶点的编号
//	priority_queue<P, vector<P>, cmp> que;//优先队列 从小到大
//	node e;//保存边的信息，为了书写方便
//	P p;//保存从队列取出的数值
//
//	fill(dis, dis + n, MAX);//初始化，都为无穷大
//	dis[s] = 0;//s—>s  距离为0
//	que.push(P(0, s));//放入距离 为0   点为s
//	while (!que.empty()) {
//		p = que.top();//取出队列中最短距离最小的对组
//		que.pop();//删除
//		v = p.second;//获得最短距离最小的顶点编号
//		if (dis[v] < p.first)//若取出的不是最短距离
//			continue;//则进行下一次循环
//		for (i = head[v]; i != -1; i = edge[i].next)//对与此点相连的所有的点进行遍历
//		{
//			e = edge[i];//为了书写的方便。
//			if (dis[e.v] > dis[v] + e.w) {//进行松弛
//				dis[e.v] = dis[v] + e.w;//松弛成功
//				que.push(P(dis[e.v], e.v));//讲找到的松弛成功的距离 和顶点放入队列
//
//			}
//		}
//
//	}
//	printf("%d\n", dis[t] == MAX ? -1 : dis[t]);//输出结果
//}
//
//int main()
//{
//	int m, u, v, w;
//
//	while (scanf("%d %d", &n, &m) == 2) {//获取点数  边数
//		cnt = 0;//结构体下标从0开始
//		memset(head, -1, sizeof(head));//初始化head[N]数组
//		while (m--) {
//			scanf("%d %d %d", &u, &v, &w);//获取u,v,w(u,v)
//			add(u, v, w);//加边
//			add(v, u, w);//加边
//
//		}
//		scanf("%d %d", &s, &t);//获取起止点
//		dijkstra();
//
//	}
//	return 0;
//}


//2544   dijkstra+堆优化 模板;
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <queue>
//#include<vector>
//#define MAX 100000000
//using namespace std;
//struct node
//{
//	int now;
//	int val;
//	int next;
//};
//struct node ar[20010];
//typedef pair<int, int> P;
//struct comp
//{
//	bool operator () (P a, P b)
//	{
//		return a.first > b.first;
//	}
//};
//int dist[10010], head[10010], n, m, count;
//
//void P_dijkstra();
//
//int main()
//{
//	int i, j, k, u, a, b, c, count;
//	while (scanf("%d %d", &n, &m) != EOF && (n || m))
//	{
//		count = 0;
//		memset(head, -1, sizeof(head));
//		for (i = 0; i <= n; i++)
//			dist[i] = MAX;
//		for (u = 1; u <= m; u++)
//		{
//			scanf("%d %d %d", &a, &b, &c);
//			ar[count].now = b;
//			ar[count].val = c;
//			ar[count].next = head[a];
//			head[a] = count;
//			count++;
//			ar[count].now = a;
//			ar[count].val = c;
//			ar[count].next = head[b];
//			head[b] = count;
//			count++;
//		}
//		P_dijkstra();
//		printf("%d\n", dist[n]);
//	}
//	return 0;
//}
//void P_dijkstra()
//{
//	int i, j, k, u;
//	priority_queue<P, vector<P>, comp>q;
//	P temp, after;
//	temp.first = 0;
//	temp.second = 1;
//	dist[1] = 0;
//	q.push(temp);
//	while (!q.empty())
//	{
//		temp = q.top();
//		q.pop();
//
//		if (dist[temp.second] < temp.first)
//			continue;
//		for (i = head[temp.second]; i != -1; i = ar[i].next)
//		{
//			after.first = ar[i].val;
//			after.second = ar[i].now;
//			if (dist[after.second] > dist[temp.second] + after.first)
//			{
//				dist[after.second] = dist[temp.second] + after.first;
//				q.push(after);
//			}
//		}
//	}
//}

//2544  SPFA 前向星+双向队列 优化 模板；
//#include <cstdio>
//#include <cstring>
//#include <deque>
//#include <vector>
//#include <algorithm>
//#define MAX 100000000
//using namespace std;
//
//struct node
//{
//	int now;
//	int val;
//	int next;
//};
//struct node ar[20010];
//int head[10010], dist[10010], num[10010], n, m;
//bool visit[10010];
//void P_SPFA();
//
//int main()
//{
//	int i, j, k, u, a, b, c, count;
//	while (scanf("%d %d", &n, &m) != EOF && (n || m))
//	{
//		count = 0;
//		memset(head, -1, sizeof(head));
//		memset(visit, false, sizeof(visit));
//		memset(num, 0, sizeof(num));
//		for (u = 1; u <= m; u++)
//		{
//			scanf("%d %d %d", &a, &b, &c);
//			ar[count].now = b;
//			ar[count].val = c;
//			ar[count].next = head[a];
//			head[a] = count;
//			count++;
//			ar[count].now = a;
//			ar[count].val = c;
//			ar[count].next = head[b];
//			head[b] = count;
//			count++;
//		}
//		P_SPFA();
//		printf("%d\n", dist[n]);
//	}
//	return 0;
//}
//void P_SPFA()
//{
//	int i, j, k, u, temp, after;
//	deque<int>q;
//	for (i = 0; i <= n; i++)
//		dist[i] = MAX;
//	dist[1] = 0;
//	temp = 1;
//	q.push_back(temp);
//	while (!q.empty())
//	{
//		temp = q.front();
//		q.pop_front();
//		visit[temp] = false;
//		for (i = head[temp]; i != -1; i = ar[i].next)
//		{
//			after = ar[i].now;
//			if (dist[after] > dist[temp] + ar[i].val)
//			{
//				dist[after] = dist[temp] + ar[i].val;
//				if (!visit[after])
//				{
//					visit[after] = true;
//					num[after]++;
//					if (num[after] >= n)
//						return;
//					if (!q.empty() && dist[after] < dist[q.front()])
//						q.push_front(after);
//					else
//						q.push_back(after);
//				}
//			}
//		}
//	}
//}









//2680    dijkstra + 堆优化；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <queue>
//#include <vector>
//#define MAX 100000000
//using namespace std;
//
//struct node
//{
//	int now;
//	int val;
//	int next;
//};
//struct node ar[40010];
//int dist[1010], head[1010], n, m, d;
//typedef pair <int, int> P;
//struct comp
//{
//	bool operator () (P a, P b)
//	{
//		return a.first > b.first;
//	}
//};
//void P_dijkstra();
//
//int main()
//{
//	int i, j, k, u, count, a, b, c, min, begin;
//	while (scanf("%d %d %d", &n, &m, &d) != EOF)
//	{
//		count = 0;
//		memset(head, -1, sizeof(head));
//		for (u = 1; u <= m; u++)
//		{
//			scanf("%d %d %d", &a, &b, &c);
//			ar[count].now = a;
//			ar[count].val = c;
//			ar[count].next = head[b];
//			head[b] = count++;
//		}
//		P_dijkstra();
//		scanf("%d", &k);
//		min = MAX;
//		for (i = 1; i <= k; i++)
//		{
//			scanf("%d", &begin);
//			if (min >= dist[begin])
//			{
//				min = dist[begin];
//			}
//		}
//		if (min != MAX)
//			printf("%d\n", min);
//		else
//			printf("-1\n");
//	}
//	return 0;
//}
//void P_dijkstra()
//{
//	int i, k, j, u;
//	P temp, after;
//	priority_queue<P, vector<P>, comp>q;
//	for (i = 0; i <= n; i++)
//		dist[i] = MAX;
//	temp.first = 0;
//	temp.second = d;
//	dist[d] = 0;
//	q.push(temp);
//	while (!q.empty())
//	{
//		temp = q.top();
//		q.pop();
//		if (dist[temp.second] < temp.first)
//			continue;
//		for (i = head[temp.second]; i != -1; i = ar[i].next)
//		{
//			after.first = ar[i].val;
//			after.second = ar[i].now;
//			if (dist[after.second] > dist[temp.second] + after.first)
//			{
//				dist[after.second] = dist[temp.second] + after.first;
//				q.push(after);
//			}
//		}
//	}
//}



//2722 最短路第10题 朴素dijkstra  只是输入和构成ar数组比较难;
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#define MAX 100000000
//using namespace std;
//
//int ar[500][500];
//int dist[500], n, m;
//bool visit[500];
//
//void dijkstra();
//int main()
//{
//	int i, j, k, u, count;
//	char ch[20];
//	int temp;
//	while (scanf("%d %d", &n, &m) != EOF && (n || m))
//	{
//		count = 1;
//		for (i = 0; i <= (n + 2) * (m + 2); i++)
//		{
//			for (j = 0; j <= (n + 2) * (m + 2); j++)
//			{
//				ar[i][j] = MAX;
//			}
//		}
//		for (i = 1; i <= 2 * n + 1; i++)
//		{
//			if (i % 2 == 0)
//			{
//				u = count;
//				for (j = 1; j <= m + 1; j++)
//				{
//					scanf("%d %s", &temp, ch);
//
//					if (temp == 0)
//					{
//						count++;
//						continue;
//					}
//					temp = 2520 / temp;
//					if (ch[0] == '*')
//					{
//						ar[count][count - m - 1] = temp;
//						ar[count - m - 1][count] = temp;
//					}
//					else if (ch[0] == 'v')
//						ar[count - m - 1][count] = temp;
//					else if (ch[0] == '^')
//						ar[count][count - m - 1] = temp;
//					count++;
//				}
//				count = u;
//			}
//			else
//			{
//				for (j = 1; j <= m; j++)
//				{
//					scanf("%d %s", &temp, ch);
//
//					if (temp == 0)
//					{
//						count++;
//						continue;
//					}
//					temp = 2520 / temp;
//					if (ch[0] == '*')
//					{
//						ar[count][count + 1] = temp;
//						ar[count + 1][count] = temp;
//					}
//					else if (ch[0] == '<')
//						ar[count + 1][count] = temp;
//					else if (ch[0] == '>')
//						ar[count][count + 1] = temp;
//					count++;
//				}
//				count++;
//			}
//		}
//		//printf("%d\n", count);
//		dijkstra();
//		if (dist[(n + 1) * (m + 1)] != MAX)
//			printf("%d blips\n", dist[(n + 1) * (m + 1)]);
//		else
//			printf("Holiday\n");
//	}
//	return 0;
//}
//void dijkstra()
//{
//	int i, j, u, k, midmin;
//	memset(visit, false, sizeof(visit));
//	for (i = 1; i <= (n + 1) * (m + 1); i++)
//		dist[i] = ar[1][i];
//	visit[1] = true;
//	dist[1] = 0;
//	for (i = 2; i <= (n + 1) * (m + 1); i++)
//	{
//		midmin = MAX;
//		for (j = 2; j <= (n + 1) * (m + 1); j++)
//		{
//			if (!visit[j] && midmin > dist[j])
//			{
//				midmin = dist[j];
//				u = j;
//			}
//		}
//		visit[u] = true;
//		for (j = 2; j <= (n + 1) * (m + 1); j++)
//		{
//			if (!visit[j] && dist[j] > dist[u] + ar[u][j])
//			{
//				dist[j] = dist[u] + ar[u][j];
//			}
//		}
//	}
//}


//1224   SPFA + 链式；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#include <deque>
//#define MIN -10000000
//#define MAX 100000000
//using namespace std;
//struct node
//{
//	int now;
//	int val;
//	int next;
//};
//struct node ar[20010];
//
//int dist[110], head[110], pre[110], set[110], visit[110], k;
//void SPFA();
//void out(int q);
//int main()
//{
//	int i, j, u, a, b, c, n, m, count;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &k);
//			for (u = 1; u <= k; u++)
//			{
//				scanf("%d", &set[u]);
//			}
//			set[k + 1] = MAX;
//			count = 0;
//			memset(head, -1 , sizeof(head));
//			scanf("%d", &c);
//			for (u = 1; u <= c; u++)
//			{
//				scanf("%d %d", &a, &b);
//				ar[count].now = b;
//				ar[count].val = set[b];
//				ar[count].next = head[a];
//				head[a] = count++;
//			}
//			SPFA();
//			printf("CASE %d#\n", m);
//			printf("points : %d\n", dist[k + 1] - MAX);
//			printf("circuit : ");
//			out(pre[k+1]);
//			printf("1\n");
//			if (m < n)
//				printf("\n");
//		}
//	}
//	return 0;
//}
//void SPFA()
//{
//	int i, j, u, h, v;
//	queue<int>q;
//	memset(visit, false, sizeof(visit));
//	memset(pre, -1, sizeof(pre));
//	for (i = 1; i <= k + 1; i++)
//		dist[i] = MIN;
//	dist[1] = 0;
//	visit[1] = true;
//	q.push(1);
//	while (!q.empty())
//	{
//		u = q.front();
//		q.pop();
//		visit[u] = false;
//		for (i = head[u]; i != -1; i = ar[i].next)
//		{
//			v = ar[i].now;
//			if (dist[v] < dist[u] + ar[i].val)
//			{
//				dist[v] = dist[u] + ar[i].val;
//				pre[v] = u;
//				if (!visit[v])
//				{
//					visit[v] = true;
//					q.push(v);
//				}
//			}
//		}
//	}
//}
//void out(int q)
//{
//	if (pre[q] != -1)
//		out(pre[q]);
//	printf("%d->", q);
//	return;
//}







//2112    地名是字符串的   最短路第7题 dijkstra + 堆优化；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#define MAX 100000000
//using namespace std;
//
//struct node
//{
//	int now;
//	int val;
//	int next;
//};
//struct node ar[20010];
//int dist[200], head[200], n, m, countt;
//char sa[200][80], a[80], b[80];
//typedef pair<int, int>P;
//struct comp
//{
//	bool operator () (P a, P b)
//	{
//		return a.first > b.first;
//	}
//};
//void P_dijkstra();
//int main()
//{
//	int i, j, k, u, x1, x2, cnt, c;
//	while (scanf("%d", &n) != EOF && n != -1)
//	{
//		countt = 0;
//		scanf("%s %s", sa[countt], sa[countt + 1]);
//		countt += 2;
//		cnt = 0;
//		memset(head, -1, sizeof(head));
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%s %s %d", a, b, &c);
//			x1 = MAX;
//			x2 = MAX;
//			for (j = 0; j < countt; j++)
//			{
//				if (strcmp(a, sa[j]) == 0)
//				{
//					x1 = j;
//					break;
//				}
//			}
//			if (x1 == MAX)
//			{
//				strcpy(sa[countt], a);
//				x1 = countt;
//				countt++;
//			}
//			for (j = 0; j < countt; j++)
//			{
//				if (strcmp(b, sa[j]) == 0)
//				{
//					x2 = j;
//					break;
//				}
//			}
//			if (x2 == MAX)
//			{
//				strcpy(sa[countt], b);
//				x2 = countt;
//				countt++;
//			}
//			ar[cnt].now = x2;
//			ar[cnt].val = c;
//			ar[cnt].next = head[x1];
//			head[x1] = cnt++;
//			ar[cnt].now = x1;
//			ar[cnt].val = c;
//			ar[cnt].next = head[x2];
//			head[x2] = cnt++;
//		}
//		if (strcmp(sa[0], sa[1]) == 0)
//		{
//			printf("0\n");
//			continue;
//		}
//		P_dijkstra();
//		if (dist[1] != MAX)
//			printf("%d\n", dist[1]);
//		else
//			printf("-1\n");
//	}
//	return 0;
//}
//void P_dijkstra()
//{
//	int i, j, k, u;
//	P temp, after;
//	for (i = 0; i <= countt; i++)
//		dist[i] = MAX;
//	dist[0] = 0;
//	priority_queue<P, vector<P>, comp>q;
//	temp.first = 0;
//	temp.second = 0;
//	q.push(temp);
//	while (!q.empty())
//	{
//		temp = q.top();
//		q.pop();
//		if (dist[temp.second] < temp.first)
//			continue;
//		for (i = head[temp.second]; i != -1; i = ar[i].next)
//		{
//			after.first = ar[i].val;
//			after.second = ar[i].now;
//			if (dist[after.second] > dist[temp.second] + after.first)
//			{
//				dist[after.second] = dist[temp.second] + after.first;
//				q.push(after);
//			}
//		}
//	}
//}







//3790  dijkstra+堆优化  最短路第13题（双权值问题， 多加一个和dist一样功能的数组）；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#define MAX 100000000
//using namespace std;
//
//struct node
//{
//	int now;
//	int val;
//	int next;
//	int cost;
//};
//typedef pair <int, int> P;
//struct comp
//{
//	bool operator () (P a, P b)
//	{
//		return a.first > b.first;
//	}
//};
//struct node ar[200010];
//int dist[1010], head[1010], cost[1010];
//int n, m, s, t;
//void P_dijkstra();
//
//int main()
//{
//	int i, j, k, u, a, b, c, d, count;
//	while (scanf("%d %d", &n, &m) != EOF && (n || m))
//	{
//		count = 0;
//		memset(head, -1, sizeof(head));
//		for (u = 1; u <= m; u++)
//		{
//			scanf("%d %d %d %d", &a, &b, &c, &d);
//			ar[count].now = b;
//			ar[count].val = c;
//			ar[count].cost = d;
//			ar[count].next = head[a];
//			head[a] = count++;
//			ar[count].now = a;
//			ar[count].val = c;
//			ar[count].cost = d;
//			ar[count].next = head[b];
//			head[b] = count++;
//		}
//		scanf("%d %d", &s, &t);
//		P_dijkstra();
//		printf("%d %d\n", dist[t], cost[t]);
//	}
//	return 0;
//}
//void P_dijkstra()
//{
//	int i, j, k, u;
//	P temp, after;
//	priority_queue<P, vector<P>, comp>q;
//	for (i = 0; i <= n; i++)
//	{
//		dist[i] = MAX;
//		cost[i] = MAX;
//	}
//	dist[s] = 0;
//	cost[s] = 0;
//	temp.first = 0;
//	temp.second = s;
//	q.push(temp);
//	while (!q.empty())
//	{
//		temp = q.top();
//		q.pop();
//		if (dist[temp.second] < temp.first)
//			continue;
//		for (i = head[temp.second]; i != -1; i = ar[i].next)
//		{
//			after.first = ar[i].val;
//			after.second = ar[i].now;
//			if (dist[after.second] > dist[temp.second] + after.first)
//			{
//				dist[after.second] = dist[temp.second] + after.first;
//				cost[after.second] = cost[temp.second] + ar[i].cost;
//				q.push(after);
//			}
//			if (dist[after.second] == dist[temp.second] + after.first && cost[after.second] > cost[temp.second] + ar[i].cost)
//			{
//				dist[after.second] = dist[temp.second] + after.first;
//				cost[after.second] = cost[temp.second] + ar[i].cost;
//				q.push(after);
//			}
//		}
//	}
//}






//2923   WA17次！！！    复习floyd + 认识map；
//#include <cstdio>
//#include <string>
//#include <cstring>
//#include <algorithm>
//#include <map>
//#define MAX 999999999
//using namespace std;
//
//int n, c, r;
//map<string, int> ar;
//int dist[1100][1100];
//char sa[1100][110];
//void floyd();
//int main()
//{
//	int i, j, k, u, sum, count, cas = 1, d, x, y;
//	char a[110], b[110], f, g;
//	while (scanf("%d %d %d", &n, &c, &r) != EOF && (n || c || r))
//	{
//		ar.clear();
//		sum = 0;
//		for (i = 0; i <= n; i++)
//		{
//			for (j = 0; j <= n; j++)
//			{
//				dist[i][j] = MAX;
//			}
//		}
//		for (i = 0; i <= c; i++)
//		{
//			scanf("%s", sa[i]);
//		}
//		count = 1;
//		for (i = 0; i < r; i++)
//		{
//			scanf("%s %c-%d-%c %s", a, &f, &d, &g, b);
//			if (!ar[a])
//				ar[a] = count++;
//			x = ar[a];
//			if (!ar[b])
//				ar[b] = count++;
//			y = ar[b];
//			if (f == '<' && d < dist[y][x])
//				dist[y][x] = d;
//			if (g == '>' && d < dist[x][y])
//				dist[x][y] = d;
//		}
//		floyd();
//		for (i = 1; i <= n; i++)
//		{
//			for (j = 1; j <= n; j++)
//			{
//				printf("%d ", dist[i][j]);
//			}
//			putchar('\n');
//		}
//		for (i = 1; i <= c; i++)
//			sum += dist[ar[sa[0]]][ar[sa[i]]] + dist[ar[sa[i]]][ar[sa[0]]];
//		printf("%d. %d\n", cas++, sum);
//	}
//	return 0;
//}
//void floyd()
//{
//	int i, j, k;
//	for (k = 1; k <= n; k++)
//	{
//		for (i = 1; i <= n; i++)
//		{
//			for (j = 1; j <= n; j++)
//			{
//				if (dist[i][j] > dist[i][k] + dist[k][j])
//					dist[i][j] = dist[i][k] + dist[k][j];
//			}
//		}
//	}
//}







//3339   dijkstra堆优化 + 01背包，化找最小为找最大， 代价和体积换位置；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#define MAX 999999999
//using namespace std;
//
//struct node
//{
//	int now;
//	int val;
//	int next;
//};
//struct node ar[20010];
//typedef pair<int, int> P;
//struct comp
//{
//	bool operator () (P a, P b)
//	{
//		return a.first > b.first;
//	}
//};
//int dist[110], head[110], n, m;
//void P_dijkstra();
//int main()
//{
//	int t, cas, i, j, k, u, a, b, c, count, sum, S, power[110], bag[10010];
//	while (scanf("%d", &t) != EOF)
//	{
//		for (cas = 1; cas <= t; cas++)
//		{
//			scanf("%d %d", &n, &m);
//			count = 0;
//			memset(head, -1, sizeof(head));
//			for (i = 1; i <= m; i++)
//			{
//				scanf("%d %d %d", &a, &b, &c);
//				ar[count].now = b;
//				ar[count].val = c;
//				ar[count].next = head[a];
//				head[a] = count++;
//				ar[count].now = a;
//				ar[count].val = c;
//				ar[count].next = head[b];
//				head[b] = count++;
//			}
//			sum = 0;
//			for (i = 1; i <= n; i++)
//			{
//				scanf("%d", &power[i]);
//				sum += power[i];
//			}
//			P_dijkstra();
//			memset(bag, 0, sizeof(bag));
//			S = 0;
//			for (i = 0; i <= n; i++)
//				if (dist[i] != MAX)
//					S += dist[i];
//			for (i = 1; i <= n; i++)
//			{
//				for (j = S; j >= dist[i]; j--)
//				{
//					bag[j] = (bag[j] > bag[j - dist[i]] + power[i]) ? bag[j] : (bag[j - dist[i]] + power[i]);
//				}
//			}
//			for (i = 0; i < S; i++)
//			{
//				if (bag[i] > sum / 2)
//				{
//					printf("%d\n", i);
//					break;
//				}
//			}
//			if (i == S)
//				printf("impossible\n");
//		}
//	}
//	return 0;
//}
//void P_dijkstra()
//{
//	int i, j, k;
//	P temp, after;
//	priority_queue<P, vector<P>, comp>q;
//	for (i = 0; i <= n; i++)
//		dist[i] = MAX;
//	dist[0] = 0;
//	temp.first = 0;
//	temp.second = 0;
//	q.push(temp);
//	while (!q.empty())
//	{
//		temp = q.top();
//		q.pop();
//		if (dist[temp.second] < temp.first)
//			continue;
//		for (i = head[temp.second]; i != -1; i = ar[i].next)
//		{
//			after.second = ar[i].now;
//			after.first = ar[i].val;
//			if (dist[after.second] > dist[temp.second] + after.first)
//			{
//				dist[after.second] = dist[temp.second] + after.first;
//				q.push(after);
//			}
//		}
//	}
//}














//1370  中国剩余定理第1题（互质）模板；
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//typedef long long LL;
//const int N = 100;
//using namespace std;
//LL M;
//void extend_Euclid(LL a, LL b, LL &x, LL &y)
//{
//	if (b == 0)
//	{
//		x = 1;
//		y = 0;
//		return;
//	}
//	extend_Euclid(b, a % b, x, y);
//	LL tmp = x;
//	x = y;
//	y = tmp - (a / b) * y;
//}
//LL CRT(LL a[], LL m[], LL n)
//{
//	LL ans = 0;
//	for (int i = 1; i <= n; i++)
//		M *= m[i];
//	for (int i = 1; i <= n; i++)
//	{
//		LL x, y;
//		LL Mi = M / m[i];
//		extend_Euclid(Mi, m[i], x, y);
//		ans = (ans + Mi * x * a[i]) % M;
//	}
//	if (ans < 0) ans += M;
//	return ans;
//}
//int main()
//{
//	LL i, j, k, m[N], a[N], n, d, res, cas, L, J;
//	cin >> n;
//	cin.get();
//	cas = 1;
//	while (cin >> a[1] >> a[2] >> a[3] >> d)
//	{
//		if (a[1] == -1 && a[2] == -1 && a[3] == -1 && d == -1)
//			break;
//		M = 1;
//		m[1] = 23;
//		m[2] = 28;
//		m[3] = 33;
//		res = CRT(a, m, 3);
//		if (res > d)
//			cout << "Case " << cas++ << ": the next triple peak occurs in " << res - d << " days." << endl;
//		else
//			cout << "Case " << cas++ << ": the next triple peak occurs in " << M - ((d - res) % M)<< " days." << endl;
//	}
//	return 0;
//}









//中国剩余定理2
//#include <iostream>
//#include <string.h>
//#include <stdio.h>
//
//using namespace std;
//typedef long long LL;
//const int N = 1005;
//
//LL a[N], m[N];
//
//LL gcd(LL a, LL b)
//{
//	return b ? gcd(b, a % b) : a;
//}
//
//void extend_Euclid(LL a, LL b, LL &x, LL &y)
//{
//	if (b == 0)
//	{
//		x = 1;
//		y = 0;
//		return;
//	}
//	extend_Euclid(b, a % b, x, y);
//	LL tmp = x;
//	x = y;
//	y = tmp - (a / b) * y;
//}
//
//LL Inv(LL a, LL b)
//{
//	LL d = gcd(a, b);
//	if (d != 1) return -1;
//	LL x, y;
//	extend_Euclid(a, b, x, y);
//	return (x % b + b) % b;
//}
//
//bool merge(LL a1, LL m1, LL a2, LL m2, LL &a3, LL &m3)
//{
//	LL d = gcd(m1, m2);
//	LL c = a2 - a1;
//	if (c % d) return false;
//	c = (c % m2 + m2) % m2;
//	m1 /= d;
//	m2 /= d;
//	c /= d;
//	c *= Inv(m1, m2);
//	c %= m2;
//	c *= m1 * d;
//	c += a1;
//	m3 = m1 * m2 * d;
//	a3 = (c % m3 + m3) % m3;
//	return true;
//}
//
//LL CRT(LL a[], LL m[], int n)
//{
//	LL a1 = a[1];
//	LL m1 = m[1];
//	for (int i = 2; i <= n; i++)
//	{
//		LL a2 = a[i];
//		LL m2 = m[i];
//		LL m3, a3;
//		if (!merge(a1, m1, a2, m2, a3, m3))
//			return -1;
//		a1 = a3;
//		m1 = m3;
//	}
//	return (a1 % m1 + m1) % m1;
//}
//
//int main()
//{
//	int n;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (int i = 1; i <= n; i++)
//			scanf("%I64d%I64d", &m[i], &a[i]);
//		LL ans = CRT(a, m, n);
//		printf("%I64d\n", ans);
//	}
//	return 0;
//}
//



// 中国剩余定理第2题（不互质）模板；
//#include <iostream>
//#include <cstdio>
//#include <cstring>
//using namespace std;
//typedef long long int LL;
//const int N = 15;
//LL S;
//LL a[N], b[N];
//
//LL gcd(LL a, LL b)
//{
//	if (b == 0)
//		return a;
//	return gcd(b, a%b);
//}
//
//LL Extend_Euclid(LL a, LL b, LL&x, LL& y)
//{
//	if (b == 0)
//	{
//		x = 1, y = 0;
//		return a;
//	}
//	LL d = Extend_Euclid(b, a%b, x, y);
//	LL t = x;
//	x = y;
//	y = t - a / b*y;
//	return d;
//}
//
////a在模n乘法下的逆元，没有则返回-1
//LL inv(LL a, LL n)
//{
//	LL x, y;
//	LL t = Extend_Euclid(a, n, x, y);
//	if (t != 1)
//		return -1;
//	return (x%n + n) % n;
//}
//
////将两个方程合并为一个
//bool merge(LL a1, LL n1, LL a2, LL n2, LL& a3, LL& n3)
//{
//	LL d = gcd(n1, n2);
//	LL c = a2 - a1;
//	if (c%d)
//		return false;
//	c = (c%n2 + n2) % n2;
//	c /= d;
//	n1 /= d;
//	n2 /= d;
//	c *= inv(n1, n2);
//	c %= n2;
//	c *= n1*d;
//	c += a1;
//	n3 = n1*n2*d;
//	a3 = (c%n3 + n3) % n3;
//	return true;
//}
//
////求模线性方程组x=ai(mod ni),ni可以不互质
//LL China_Reminder2(int len, LL* a, LL* n)
//{
//	LL a1 = a[0], n1 = n[0];
//	LL a2, n2;
//	for (int i = 1; i < len; i++)
//	{
//		LL aa, nn;
//		a2 = a[i], n2 = n[i];
//		if (!merge(a1, n1, a2, n2, aa, nn))
//			return -1;
//		a1 = aa;
//		n1 = nn;
//	}
//	S = n1;
//	return (a1%n1 + n1) % n1;
//}
//
//// k是数组的元素个数， a是除数， b是余数；
//int main()
//{
//	int i;
//	int k;
//	int n;
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		scanf("%d%d", &n, &k);
//		for (i = 0; i < k; i++)
//			scanf("%lld", &a[i]);
//		for (int i = 0; i<k; i++)
//			scanf("%lld", &b[i]);
//		LL ans = China_Reminder2(k, b, a);
//		if (ans > n || ans == -1)
//			printf("0\n");
//		else
//			printf("%d\n", (n - ans) / S + 1 - (ans == 0 ? 1 : 0));
//	}
//	return 0;
//}






//#include <iostream>
//#include <cstdio>
//#include <cstring>
//using namespace std;
//typedef long long int LL;
//const int N = 15;
//LL M;
//
//LL gcd(LL a, LL b)
//{
//	if (b == 0)
//		return a;
//	return gcd(b, a%b);
//}
//
//LL Extend_Euclid(LL a, LL b, LL&x, LL& y)
//{
//	if (b == 0)
//	{
//		x = 1, y = 0;
//		return a;
//	}
//	LL d = Extend_Euclid(b, a%b, x, y);
//	LL t = x;
//	x = y;
//	y = t - a / b*y;
//	return d;
//}
//
////a在模n乘法下的逆元，没有则返回-1
//LL inv(LL a, LL n)
//{
//	LL x, y;
//	LL t = Extend_Euclid(a, n, x, y);
//	if (t != 1)
//		return -1;
//	return (x%n + n) % n;
//}
//
////将两个方程合并为一个
//bool merge(LL a1, LL n1, LL a2, LL n2, LL& a3, LL& n3)
//{
//	LL d = gcd(n1, n2);
//	LL c = a2 - a1;
//	if (c%d)
//		return false;
//	c = (c%n2 + n2) % n2;
//	c /= d;
//	n1 /= d;
//	n2 /= d;
//	c *= inv(n1, n2);
//	c %= n2;
//	c *= n1*d;
//	c += a1;
//	n3 = n1*n2*d;
//	a3 = (c%n3 + n3) % n3;
//	return true;
//}
//
////求模线性方程组x=ai(mod ni),ni可以不互质
//LL China_Reminder2(int len, LL* a, LL* n)
//{
//	LL a1 = a[0], n1 = n[0];
//	LL a2, n2;
//	for (int i = 1; i < len; i++)
//	{
//		LL aa, nn;
//		a2 = a[i], n2 = n[i];
//		if (!merge(a1, n1, a2, n2, aa, nn))
//			return -1;
//		a1 = aa;
//		n1 = nn;
//	}
//	M = n1;
//	return (a1%n1 + n1) % n1;
//}
//
//int main()
//{
//	int i, j, k, u, I;
//	LL a[N], m[N], res;
//	while (scanf("%d %d", &I, &u) != EOF && (I || u))
//	{
//		for (i = 0; i < I; i++)
//		{
//			scanf("%lld", &m[i]);
//			a[i] = m[i] - u;
//		}
//		res = China_Reminder2(I, a, m);
//		printf("%lld\n", res);
//	}
//}







//1010   dfs  终于他妈的水过去了，奇偶性剪枝；
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <cmath>
//const int MAX = 100000000;
//using namespace std;
//int dir[4][2] = { 0, -1, 0, 1, -1, 0, 1, 0 };
//struct Point
//{
//	int x, y;
//	Point() {}
//	Point(int a, int b) :x(a), y(b) {}
//	Point go(int direction_id) { return Point(x + dir[direction_id][0], y + dir[direction_id][1]); }
//};
//struct Point start, nextp;
//bool visit[10][10];
//bool doudou;	//标记；
//char ar[10][10];
//int T, a, b, x1, Y1, x2, y2;
//void dfs(int x, int y, int time);
//int main()
//{
//	int i, j, k, u, n, m;
//	while (scanf("%d %d %d", &a, &b, &T) != EOF && (a || b || T))
//	{
//		x1 = Y1 = x2 = y2 = MAX;
//		for (i = 1; i <= a; i++)
//		{
//			scanf("%s", ar[i] + 1);
//			if (x1 != MAX && x2 != MAX && Y1 != MAX && y2 != MAX)
//				continue;
//			for (j = 1; j <= b; j++)
//			{
//				if (ar[i][j] == 'S')
//				{
//					x1 = i;
//					Y1 = j;
//				}
//				if (ar[i][j] == 'D')
//				{
//					x2 = i;
//					y2 = j;
//				}
//			}
//		}
//		
//		if (T < abs(x1 - x2) + abs(Y1 - y2) || (x1 + Y1 + x2 + y2 + T) % 2 != 0)
//		{
//			printf("NO\n");
//			continue;
//		}
//		doudou = false;
//		memset(visit, false, sizeof(visit));
//		visit[x1][Y1] = true;
//		dfs(x1, Y1, 0);
//		if (doudou)
//		{
//			printf("YES\n");
//		}
//		else
//			printf("NO\n");
//	}
//	return 0;
//}
//void dfs(int x, int y, int time)
//{
//	int i, temp;
//	Point start(x, y);
//	if (doudou)
//		return;
//	if (start.x == x2 && start.y == y2 && time == T)
//	{
//		doudou = true;
//		return;
//	}
//	if (start.x == x2 && start.y == y2 && time != T)
//		return;
//	if (start.x < 1 || start.y < 1 || start.x > a || start.y > b || ar[start.x][start.y] == 'X')
//		return;
//	if ((start.x != x2 || start.y != y2) && time == T)
//		return;
//	if (visit[start.x][start.y] && time != 0)
//		return;
//	temp = T - time - abs(start.x - x2) - abs(start.y - y2);
//	if (temp < 0 || temp % 2 != 0)
//		return;
//	for (i = 0; i < 4; i++)
//	{
//		nextp = start.go(i);
//		visit[start.x][start.y] = true;
//		dfs(nextp.x, nextp.y, time + 1);
//		visit[start.x][start.y] = false;
//		if (doudou)
//			return;
//	}
//}








//   期望第一题
//#include <cstdio>
//#include <cmath>
//using namespace std;
//int main()
//{
//	int i, j, k, n;
//	double m, ar[10000], sa[10000];
//	while (scanf("%d", &k) != EOF && k)
//	{
//		scanf("%lf", &m);
//		ar[k] = 0;
//		sa[k] = 0;
//		for (i = k - 1; i >= 0; i--)
//		{
//			ar[i] = ar[i + 1] + 1.0 / m;
//			sa[i] = 2.0 / m * ar[i] + 1.0 / m - 2.0 * ar[i] + 2.0 * ar[i + 1] + sa[i + 1];
//		}
//		printf("%.3lf %.3lf\n", ar[0], sa[0]);
//	}
//	return 0;
//}
//#include<stdio.h>
//int main() {
//	double k, p;
//	while (~scanf("%lf", &k) && k)
//	{
//		scanf("%lf", &p);
//
//		double E_x = k / p;
//		double sumE_X = E_x *(k + 1) / p - E_x;
//		printf("%.3f %.3f\n", E_x, sumE_X);
//	}
//	return 0;
//}





//期望第二题；
//#include <cstdio>
//#include <cmath>
//#include <cstring>
//using namespace std;
//int main()
//{
//	int i, j, k, u, n, m;
//	double a, b, c, ar[1002][1002][3], bag[1002][1002];
//	while (scanf("%d %d", &n, &m) != EOF)
//	{
//		for (i = 1; i <= n; i++)
//		{
//			for (j = 1; j <= m; j++)
//			{
//				scanf("%lf %lf %lf", &ar[i][j][0], &ar[i][j][1], &ar[i][j][2]);
//			}
//		}
//		memset(bag, 0, sizeof(bag));
//		for (i = n; i > 0; i--)
//		{
//			for (j = m; j > 0; j--)
//			{
//				if (i == n && j == m)
//					continue;
//				if (fabs(1 - ar[i][j][0]) < 1e-8)
//					continue;
//				bag[i][j] = (bag[i + 1][j] * ar[i][j][2] + bag[i][j + 1] * ar[i][j][1] + 2.0) / (1.0 - ar[i][j][0]);
//			}
//		}
//		printf("%.3lf\n", bag[1][1]);
//	}
//	return 0;
//}










//最大团   第一题；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//using namespace std;
//
//int ar[55][55], vertex[55], res, n;
//void dfs(int sum, int to);
//bool isClique(int sum, int to);
//int main()
//{
//	int i, j, k, u, m;
//	while (scanf("%d", &n) != EOF && n)
//	{
//		for (i = 1; i <= n; i++)
//		{
//			for (j = 1; j <= n; j++)
//			{
//				scanf("%d", &ar[i][j]);
//			}
//		}
//		res = 0;
//		for (i = 1; i <= n; i++)
//		{
//			vertex[1] = i;
//			dfs(1, i);
//		}
//		printf("%d\n", res);
//	}
//	return 0;
//}
//bool isClique(int sum, int to)
//{
//	int i;
//	for (i = 1; i <= sum; i++)
//	{
//		if (!ar[vertex[i]][to])
//			return false;
//	}
//	return true;
//}
//void dfs(int sum, int to)
//{
//	int i, j, k;
//	if (res < sum)
//		res = sum;
//	if (sum + n - to < res)
//		return;
//	for (i = to + 1; i <= n; i++)
//	{
//		if (isClique(sum, i))
//		{
//			vertex[sum + 1] = i;
//			dfs(sum + 1, i);
//		}
//	}
//}









//1231      dp;
//#include <cstdio>
//#include <cstring>
//const int MIN = -10000000;
//using namespace std;
//
//int main()
//{
//	int i, j, k, u, n, m, ar[10010], sum[10010], begin, end, max, doudou, tbegin, tend;
//	while (scanf("%d", &n) != EOF && n)
//	{
//		doudou = 0;
//		for (i = 1; i <= n; i++)
//		{
//			scanf("%d", &ar[i]);
//			if (ar[i] >= 0)
//				doudou = 1;
//		}
//		if (!doudou)
//		{
//			printf("0 %d %d\n", ar[1], ar[n]);
//			continue;
//		}
//		max = MIN;
//		sum[0] = MIN;
//		begin = tbegin = tend = end = ar[1];
//		for (i = 1; i <= n; i++)
//		{
//			if (sum[i - 1] < 0)
//			{
//				tbegin = ar[i];
//				tend = ar[i];
//				sum[i] = ar[i];
//			}
//			else
//			{
//				tend = ar[i];
//				sum[i] = sum[i - 1] + ar[i];
//			}
//			if (sum[i] > max)
//			{
//				begin = tbegin;
//				end = tend;
//				max = sum[i];
//			}
//		}
//		printf("%d %d %d\n", max, begin, end);
//	}
//	return 0;
//}








//2111     分组背包；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//struct node
//{
//	int val;
//	int m;
//};
//int main()
//{
//	struct node ar[150];
//	int bag[150], i, j, k, u, n, a, b, cnt, count, tempp, tempm;
//	while (scanf("%d", &a) != EOF && a)
//	{
//		scanf("%d", &b);
//		for (i = 1; i <= b; i++)
//		{
//			scanf("%d %d", &ar[i].val, &ar[i].m);
//		}
//		memset(bag, 0, sizeof(bag));
//		for (i = 1; i <= b; i++)
//		{
//			for (j = a; j >= 0; j--)
//			{
//				for (k = 1; k <= ar[i].m; k++)
//				{
//					tempm = k;
//					tempp = k * ar[i].val;
//					if (j < tempm)
//						continue;
//					bag[j] = (bag[j] > bag[j - tempm] + tempp) ? bag[j] : (bag[j - tempm] + tempp);
//				}
//			}
//		}
//		printf("%d\n", bag[a]);
//	}
//	return 0;
//}








//1421       二维dp；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//const int MAX = 100000000;
//const int MIN = -10000000;
//using namespace std;
//bool comp(int a, int b)
//{
//	return a > b;
//}
//int main()
//{
//	int i, j, k, u, n, m, ar[2010], bag[2010][1010];
//	while (scanf("%d %d", &n, &k) != EOF)
//	{
//		for (i = 1; i <= n; i++)
//		{
//			scanf("%d", &ar[i]);
//		}
//		sort(ar + 1, ar + n + 1, comp);
//		for (i = 0; i <= n; i++)
//		{
//			for (j = 1; j <= k; j++)
//			{
//				bag[i][j] = MAX;
//			}
//		}
//		for (i = 0; i <= k; i++)
//			bag[i][0] = 0;
//		for (i = 1; i <= n; i++)
//		{
//			for (j = 1; j <= k && i >= 2 * j; j++)
//			{
//				bag[i][j] = (bag[i - 1][j] < bag[i - 2][j - 1] + (ar[i] - ar[i - 1]) * (ar[i] - ar[i - 1])) ? bag[i - 1][j] : (bag[i - 2][j - 1] + (ar[i] - ar[i - 1]) * (ar[i] - ar[i - 1]));
//			}
//		}
//		printf("%d\n", bag[n][k]);
//	}
//	return 0;
//}




//网易1.1
//#include <cstdio>
//#include <cstring>
//#include <string>
//#include <cstdlib>
//#include <cmath>
//const int MAX = 10010;
//using namespace std;
//
//int main()
//{
//	char ar[MAX], sa[MAX];
//	int i, j, k, u, n, m, L, cnt;
//	char temp, t;
//	while (scanf("%s", ar) != EOF)
//	{
//		L = strlen(ar);
//		temp = ar[0];
//		n = 0;
//		cnt = 0;
//		for (i = 0; i <= L; i++)
//		{
//			if (ar[i] != temp || i == L)
//			{
//				m = cnt;
//				while (n)
//				{
//					sa[cnt++] = n % 10 + '0';
//					n /= 10;
//				}
//				for (j = 0; j < (cnt - m) / 2; j++)
//				{
//					t = sa[m + j];
//					sa[m + j] = sa[cnt - j - 1];
//					sa[cnt - j - 1] = t;
//				}
//				sa[cnt++] = temp;
//				temp = ar[i];
//				n = 0;
//			}
//			n++;
//		}
//		sa[cnt] = '\0';
//		printf("%s", sa);
//	}
//	return 0;
//}
// 简化版
//#include <cstdio>
//#include <cstring>
//#include <string>
//#include <cstdlib>
//#include <cmath>
//const int MAX = 10010;
//using namespace std;
//
//int main()
//{
//	char ar[MAX], sa[MAX];
//	int i, j, k, u, n, m, L, cnt;
//	char temp, t;
//	while (scanf("%s", ar) != EOF)
//	{
//		L = strlen(ar);
//		temp = ar[0];
//		n = 0;
//		cnt = 0;
//		for (i = 0; i < L; i++)
//		{
//			if (temp == ar[i])
//			{
//				n++;
//				continue;
//			}
//			printf("%d%c", n, temp);
//			temp = ar[i];
//			n = 1;
//		}
//		printf("%d%c\n", n, temp);
//	}
//	return 0;
//}





//网易1.2
//#include <cstdio>
//#include <cstring>
//#include <queue>
//#include <algorithm>
//const int MAX = 100000000;
//const int MIN = -10000000;
//using namespace std;
//
//int ar[110][110], n, d;
//
//int main()
//{
//	int i, j, k, u, max, temp;
//	while (scanf("%d %d", &n, &d) != EOF)
//	{
//		for (i = 1; i <= n; i++)
//		{
//			for (j = 1; j <= n; j++)
//			{
//				scanf("%d", &ar[i][j]);
//			}
//		}
//		max = MIN;
//		for (i = 1; i <= n; i++)
//		{
//			for (j = 1; j <= n; j++)
//			{
//				temp = ar[i][j];
//				for (k = 1; k < d; k++)
//				{
//					temp += ar[i - k][j];
//					if (i - k < 1)
//					{
//						temp = MIN;
//						break;
//					}
//				}
//				if (max < temp)
//					max = temp;
//				temp = ar[i][j];
//				for (k = 1; k < d; k++)
//				{
//					temp += ar[i][j - k];
//					if (j - k < 1)
//					{
//						temp = MIN;
//						break;
//					}
//				}
//				if (max < temp)
//					max = temp;
//				temp = ar[i][j];
//				for (k = 1; k < d; k++)
//				{
//					temp += ar[i + k][j];
//					if (i + k > n)
//					{
//						temp = MIN;
//						break;
//					}
//				}
//				if (max < temp)
//					max = temp;
//				temp = ar[i][j];
//				for (k = 1; k < d; k++)
//				{
//					temp += ar[i][j + k];
//					if (j + k > n)
//					{
//						temp = MIN;
//						break;
//					}
//				}
//				if (max < temp)
//					max = temp;
//				temp = ar[i][j];
//				for (k = 1; k < d; k++)
//				{
//					temp += ar[i - k][j - k];
//					if (i - k < 1 || j - k < 1)
//					{
//						temp = MIN;
//						break;
//					}
//				}
//				if (max < temp)
//					max = temp;
//				temp = ar[i][j];
//				for (k = 1; k < d; k++)
//				{
//					temp += ar[i - k][j + k];
//					if (i - k < 1 || j + k > n)
//					{
//						temp = MIN;
//						break;
//					}
//				}
//				if (max < temp)
//					max = temp;
//				temp = ar[i][j];
//				for (k = 1; k < d; k++)
//				{
//					temp += ar[i + k][j - k];
//					if (i + k > n || j - k < 1)
//					{
//						temp = MIN;
//						break;
//					}
//				}
//				if (max < temp)
//					max = temp;
//				temp = ar[i][j];
//				for (k = 1; k < d; k++)
//				{
//					temp += ar[i + k][j + k];
//					if (i + k > n || j + k > n)
//					{
//						temp = MIN;
//						break;
//					}
//				}
//				if (max < temp)
//					max = temp;
//			}
//		}
//		printf("%d\n", max);
//	}
//	return 0;
//}
//简化版
//#include <cstdio>
//#include <cstring>
//#include <queue>
//#include <algorithm>
//const int MAX = 100000000;
//const int MIN = -10000000;
//using namespace std;
//
//int ar[110][110], n, d;
//int dir[8][2] = { -1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1 };
//int main()
//{
//	int i, j, k, u, max, temp;
//	while (scanf("%d %d", &n, &d) != EOF)
//	{
//		for (i = 1; i <= n; i++)
//		{
//			for (j = 1; j <= n; j++)
//			{
//				scanf("%d", &ar[i][j]);
//			}
//		}
//		max = MIN;
//		for (i = 1; i <= n; i++)
//		{
//			for (j = 1; j <= n; j++)
//			{
//				for (u = 0; u < 8; u++)
//				{
//					temp = ar[i][j];
//					for (k = 1; k < d; k++)
//					{
//						temp += ar[i + dir[u][0] * k][j + dir[u][1] * k];
//						if (i + dir[u][0] * k < 1 || i + dir[u][0] * k > n || j + dir[u][1] * k < 1 || j + dir[u][1] * k > n)
//						{
//							temp = MIN;
//							break;
//						}
//					}
//					if (max < temp)
//						max = temp;
//				}
//			}
//		}
//		printf("%d\n", max);
//	}
//	return 0;
//}



//2717    bfs+优先队列；
//#include <cstdio>
//#include <cstring>
//#include <queue>
//#include <algorithm>
//#include <cstdlib>
//const int MAX = 100000000;
//const int MIN = -100000000;
//using namespace std;
//struct node
//{
//	int x;
//	int step;
//	friend bool operator < (node a, node b)
//	{
//		return a.step > b.step;
//	}
//};
//struct node now, after;
//int n, m, visit[200100];
//void bfs();
//int main()
//{
//	int i, j, k;
//	while (scanf("%d %d", &n, &m) != EOF)
//	{
//		bfs();
//		printf("%d\n", now.step);
//	}
//	return 0;
//}
//void bfs()
//{
//	priority_queue<node>q;
//	int i, j, k;
//	for (i = 0; i < 200100; i++)
//		visit[i] = MAX;
//	now.x = n;
//	now.step = 0;
//	visit[n] = 0;
//	q.push(now);
//	while (!q.empty())
//	{
//		now = q.top();
//		q.pop();
//		if (now.x == m)
//			return;
//		after.x = now.x * 2;
//		after.step = now.step + 1;
//		if (visit[after.x] > after.step && after.x >= 0 && after.x < 200100)
//		{
//			q.push(after);
//			visit[after.x] = after.step;
//		}
//		after.x = now.x + 1;
//		after.step = now.step + 1;
//		if (visit[after.x] > after.step && after.x >= 0 && after.x < 200100)
//		{
//			q.push(after);
//			visit[after.x] = after.step;
//		}
//		after.x = now.x - 1;
//		after.step = now.step + 1;
//		if (visit[after.x] > after.step && after.x >= 0 && after.x < 200100)
//		{
//			q.push(after);
//			visit[after.x] = after.step;
//		}
//	}
//}






//2102  bfs+优先队列；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <queue>
//#include <algorithm>
//const int MAX = 100000000;
//using namespace std;
//struct node
//{
//	int x;
//	int y;
//	int z;
//	int step;
//	friend bool operator < (node a, node b)
//	{
//		return a.step > b.step;
//	}
//};
//struct node now, after;
//int visit[2][20][20], a, b, t, x1, y1, x2, y2, z1, z2;
//int dir[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };
//char ar[2][20][20];
//void bfs();
//int main()
//{
//	int i, j, k, n, m, u;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d %d", &a, &b, &t);
//			for (u = 0; u < 2; u++)
//			{
//				for (i = 1; i <= a; i++)
//				{
//					scanf("%s", ar[u][i] + 1);
//
//					for (j = 1; j <= b; j++)
//					{
//						if (ar[u][i][j] == 'S')
//						{
//							x1 = i;
//							y1 = j;
//							z1 = u;
//						}
//						if (ar[u][i][j] == 'P')
//						{
//							x2 = i;
//							y2 = j;
//							z2 = u;
//						}
//					}
//
//				}
//			}
//			bfs();
//			if (ar[now.z][now.x][now.y] == 'P' && now.step <= t)
//				printf("YES\n");
//			else
//				printf("NO\n");
//		}
//	}
//	return 0;
//}
//void bfs()
//{
//	int u, i, j, k, temp;
//	priority_queue<node>q;
//	for (u = 0; u < 2; u++)
//	{
//		for (i = 0; i <= a; i++)
//		{
//			for (j = 0; j <= b; j++)
//			{
//				visit[u][i][j] = MAX;
//			}
//		}
//	}
//	now.x = x1;
//	now.y = y1;
//	now.z = z1;
//	now.step = 0;
//	visit[z1][x1][y1] = 0;
//	q.push(now);
//	while (!q.empty())
//	{
//		now = q.top();
//		q.pop();
//		if (ar[now.z][now.x][now.y] == 'P' && now.step <= t)
//			return;
//		for (i = 0; i < 4; i++)
//		{
//			after.x = now.x + dir[i][0];
//			after.y = now.y + dir[i][1];
//			after.z = now.z;
//			after.step = now.step + 1;
//			if (after.x < 1 || after.x > a || after.y < 1 || after.y > b || ar[after.z][after.x][after.y] == '*' || after.step > t)
//				continue;
//
//			if (ar[after.z][after.x][after.y] == '#')
//			{
//				temp = (after.z == 0) ? 1 : 0;
//				if (ar[temp][after.x][after.y] == '#' || ar[temp][after.x][after.y] == '*')
//					continue;
//
//				if (visit[temp][after.x][after.y] > after.step && visit[after.z][after.x][after.y] > after.step)
//				{
//					visit[after.z][after.x][after.y] = after.step;
//					after.z = temp;
//					q.push(after);
//					visit[temp][after.x][after.y] = after.step;
//				}
//				continue;
//			}
//			if ((ar[after.z][after.x][after.y] == '.' || ar[after.z][after.x][after.y] == 'P') && visit[after.z][after.x][after.y] > after.step)
//			{
//				q.push(after);
//				visit[after.z][after.x][after.y] = after.step;
//			}
//		}
//	}
//	now.step = MAX;
//}







//1150 二分匹配第1题， 匈牙利算法dfs；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <cstdlib>
//const int MAX = 100000000;
//using namespace std;
//int visit[110];
//int ar[110][110];
//int link[110];
//int leftN, rightN, res;
//bool dfs(int f);
//
//int main()
//{
//	int i, j, k, u, n, m, num;
//	while (scanf("%d", &leftN) != EOF && leftN)
//	{
//		scanf("%d %d", &rightN, &num);
//		memset(ar, 0, sizeof(ar));
//		memset(link, -1, sizeof(link));
//		res = 0;
//		for (i = 0; i < num; i++)
//		{
//			scanf("%d %d %d", &k, &n, &m);
//			ar[n][m] = 1;
//		}
//		for (i = 1; i < leftN; i++)
//		{
//			memset(visit, false, sizeof(visit));
//			if (dfs(i))
//				res++;
//		}
//		printf("%d\n", res);
//	}
//	return 0;
//}
//bool dfs(int f)
//{
//	int i, j, k, u;
//	for (i = 1; i <= rightN; i++)
//	{
//		if (!visit[i] && ar[f][i])
//		{
//			visit[i] = true;
//			if (link[i] == -1 || dfs(link[i]))
//			{
//				link[i] = f;
//				return true;
//			}
//		}
//	}
//	return false;
//}







//1151  二分匹配第2题  匈牙利算法dfs；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//using namespace std;
//bool visit[200];
//int ar[200][200];
//int leftN[200], rightN[200], res, a;
//int link[200];
//bool dfs(int f);
//int main()
//{
//	int i, j, k, b, n, m, p, q;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d", &a, &b);
//			memset(ar, 0, sizeof(ar));
//			memset(leftN, 0, sizeof(leftN));
//			memset(rightN, 0, sizeof(rightN));
//			memset(link, -1, sizeof(link));
//			res = 0;
//			for (i = 1; i <= b; i++)
//			{
//				scanf("%d %d", &p, &q);
//				ar[p][q] = 1;
//				leftN[p] = 1;
//				rightN[q] = 1;
//			}
//			for (i = 1; i <= a; i++)
//			{
//				if (leftN[i])
//				{
//					memset(visit, false, sizeof(visit));
//					if (dfs(i))
//						res++;
//				}
//			}
//			printf("%d\n", a - res);
//		}
//	}
//	return 0;
//}
//bool dfs(int f)
//{
//	int i, j, k, u;
//	for (i = 1; i <= a; i++)
//	{
//		if (rightN[i] && ar[f][i] && !visit[i])
//		{
//			visit[i] = true;
//			if (link[i] == -1 || dfs(link[i]))
//			{
//				link[i] = f;
//				return true;
//			}
//		}
//	}
//	return false;
//}









//1281   二分匹配第3题 依然匈牙利；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//using namespace std;
//
//bool visit[110];
//int ar[110][110];
//int leftN[110], rightN[110], res, ans, b;
//int link[110];
//bool dfs(int f);
//int main()
//{
//	int i, j, k, n, m, u, a, p, q, count, cas = 1;
//	while (scanf("%d %d %d", &a, &b, &n) != EOF)
//	{
//		memset(ar, 0, sizeof(ar));
//		memset(link, -1, sizeof(link));
//		memset(leftN, 0, sizeof(leftN));
//		memset(rightN, 0, sizeof(rightN));
//		res = 0;
//		ans = 0;
//		count = 0;
//		for (i = 1; i <= n; i++)
//		{
//			scanf("%d %d", &leftN[i], &rightN[i]);
//			ar[leftN[i]][rightN[i]] = 1;
//		}
//		for (i = 1; i <= a; i++)
//		{
//			memset(visit, false, sizeof(visit));
//			if (dfs(i))
//				res++;
//		}
//		for (i = 1; i <= n; i++)
//		{
//			ar[leftN[i]][rightN[i]] = 0;
//			memset(link, -1, sizeof(link));
//			ans = 0;
//			for (j = 1; j <= a; j++)
//			{
//				memset(visit, false, sizeof(visit));
//				if (dfs(j))
//					ans++;
//			}
//			if (ans != res)
//				count++;
//			ar[leftN[i]][rightN[i]] = 1;
//		}
//		printf("Board %d have %d important blanks for %d chessmen.\n", cas++, count, res);
//	}
//	return 0;
//}
//bool dfs(int f)
//{
//	int i, j, k, u;
//	for (i = 1; i <= b; i++)
//	{
//		if (!visit[i] && ar[f][i])
//		{
//			visit[i] = true;
//			if (link[i] == -1 || dfs(link[i]))
//			{
//				link[i] = f;
//				return true;
//			}
//		}
//	}
//	return false;
//}







//1498   二分匹配 匈牙利；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//using namespace std;
//bool visit[110];
//int ar[110][110];
//int sa[110];
//int res, a, b;
//int link[110];
//bool dfs(int f, int g);
//int main()
//{
//	int i, j, k, u, n, m, p, q, cnt;
//	while (scanf("%d %d", &a, &b) != EOF && (a || b))
//	{
//		for (i = 1; i <= a; i++)
//		{
//			for (j = 1; j <= a; j++)
//			{
//				scanf("%d", &ar[i][j]);
//			}
//		}
//		cnt = 0;
//		for (u = 1; u <= 100; u++)
//		{
//			memset(link, -1, sizeof(link));
//			res = 0;
//			for (i = 1; i <= a; i++)
//			{
//				memset(visit, false, sizeof(visit));
//				if (dfs(i, u))
//					res++;
//			}
//			if (res > b)
//				sa[cnt++] = u;
//		}
//		if (!cnt)
//			printf("-1\n");
//		else
//		{
//			for (i = 0; i < cnt; i++)
//			{
//				if (i == 0)
//					printf("%d", sa[i]);
//				else
//					printf(" %d", sa[i]);
//			}
//			putchar('\n');
//		}
//	}
//	return 0;
//}
//bool dfs(int f, int g)
//{
//	int i, j, k, u;
//	for (i = 1; i <= a; i++)
//	{
//		if (ar[f][i] == g && !visit[i])
//		{
//			visit[i] = true;
//			if (link[i] == -1 || dfs(link[i], g))
//			{
//				link[i] = f;
//				return true;
//			}
//		}
//	}
//	return false;
//}







//1528   二分匹配第5题 匈牙利
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//using namespace std;
//bool visit[30];
//int ar[30][30];
//int res, a;
//int link[30];
//bool dfs(int f);
//int main()
//{
//	int i, j, k, n, m, u;
//	char leftN[30][3], rightN[30][3];
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &a);
//			for (i = 1; i <= a; i++)
//			{
//				scanf("%s", rightN[i]);
//				if (rightN[i][1] == 'H')
//					rightN[i][1] = '4';
//				else if (rightN[i][1] == 'S')
//					rightN[i][1] = '3';
//				else if (rightN[i][1] == 'D')
//					rightN[i][1] = '2';
//				else if (rightN[i][1] == 'C')
//					rightN[i][1] = '1';
//				if (rightN[i][0] == 'T')
//					rightN[i][0] = 'A';
//				else if (rightN[i][0] == 'A')
//					rightN[i][0] = 'T';
//				else if (rightN[i][0] == 'K')
//					rightN[i][0] = 'Q';
//				else if (rightN[i][0] == 'Q')
//					rightN[i][0] = 'K';
//				rightN[i][2] = '\0';
//			}
//			for (i = 1; i <= a; i++)
//			{
//				scanf("%s", leftN[i]);
//				if (leftN[i][1] == 'H')
//					leftN[i][1] = '4';
//				else if (leftN[i][1] == 'S')
//					leftN[i][1] = '3';
//				else if (leftN[i][1] == 'D')
//					leftN[i][1] = '2';
//				else if (leftN[i][1] == 'C')
//					leftN[i][1] = '1';
//				if (leftN[i][0] == 'T')
//					leftN[i][0] = 'A';
//				else if (leftN[i][0] == 'A')
//					leftN[i][0] = 'T';
//				else if (leftN[i][0] == 'K')
//					leftN[i][0] = 'Q';
//				else if (leftN[i][0] == 'Q')
//					leftN[i][0] = 'K';
//				leftN[i][2] = '\0';
//			}
//			memset(ar, 0, sizeof(ar));
//			memset(link, -1, sizeof(link));
//			res = 0;
//			for (i = 1; i <= a; i++)
//			{
//				for (j = 1; j <= a; j++)
//				{
//					if (strcmp(leftN[i], rightN[j]) > 0)
//						ar[i][j] = 1;
//				}
//			}
//			for (i = 1; i <= a; i++)
//			{
//				memset(visit, false, sizeof(visit));
//				if (dfs(i))
//					res++;
//			}
//			printf("%d\n", res);
//		}
//	}
//	return 0;
//}
//bool dfs(int f)
//{
//	int i, j, k;
//	for (i = 1; i <= a; i++)
//	{
//		if (!visit[i] && ar[f][i])
//		{
//			visit[i] = true;
//			if (link[i] == -1 || dfs(link[i]))
//			{
//				link[i] = f;
//				return true;
//			}
//		}
//	}
//	return false;
//}




//二分匹配第7题  匈牙利算法
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//using namespace std;
//bool visit[1010];
//int ar[1010][1010];
//int res, n;
//int link[1010];
//bool dfs(int f);
//int main()
//{
//	int i, j, k, u, m, p, q;
//	while (scanf("%d", &n) != EOF)
//	{
//		memset(ar, 0, sizeof(ar));
//		memset(link, -1, sizeof(link));
//		res = 0;
//		for (m = 0; m < n; m++)
//		{
//			scanf("%d: (%d)", &i, &j);
//			for (u = 1; u <= j; u++)
//			{
//				scanf("%d", &p);
//				ar[i][p] = 1;
//			}
//		}
//		for (i = 0; i < n; i++)
//		{
//			memset(visit, false, sizeof(visit));
//			if (dfs(i))
//				res++;
//		}
//		printf("%d\n", n - res/2);
//	}
//	return 0;
//}
//bool dfs(int f)
//{
//	int i, j, k, u;
//	for (i = 0; i < n; i++)
//	{
//		if (ar[f][i] && !visit[i])
//		{
//			visit[i] = true;
//			if (link[i] == -1 || dfs(link[i]))
//			{
//				link[i] = f;
//				return true;
//			}
//		}
//	}
//	return false;
//}







//1045   一道深搜dfs 套 DP；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//using namespace std;
//struct point
//{
//	int x;
//	int y;
//};
//struct point ar[20];
//char sa[10][10];
//int n, res, cnt;
//int dir[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };
//void dfs(int a, int num);
//bool check(int c);
//int main()
//{
//	int i, j, k, u, a, b;
//	while (scanf("%d", &n) != EOF && n)
//	{
//		cnt = 0;
//		for (i = 1; i <= n; i++)
//		{
//			scanf("%s", sa[i] + 1);
//			for (j = 1; j <= n; j++)
//			{
//				if (sa[i][j] == '.')
//				{
//					ar[cnt].x = i;
//					ar[cnt++].y = j;
//				}
//			}
//		}
//		res = 0;
//		dfs(0, 0);
//		printf("%d\n", res);
//	}
//	return 0;
//}
//void dfs(int a, int num)
//{
//	if (num > res)
//		res = num;
//	if (a == cnt)
//		return;
//	dfs(a + 1, num);
//	if (check(a))
//	{
//		sa[ar[a].x][ar[a].y] = '#';
//		dfs(a + 1, num + 1);
//		sa[ar[a].x][ar[a].y] = '.';
//	}
//
//}
//bool check(int c)
//{
//	int i, doudou = 0;
//	struct point now;
//	for (i = 0; i < 4; i++)
//	{
//		if (doudou)
//			return false;
//		now.x = ar[c].x + dir[i][0];
//		now.y = ar[c].y + dir[i][1];
//		while (now.x <= n && now.y <= n && now.x >= 1 && now.y >= 1)
//		{
//			if (sa[now.x][now.y] == '#')
//			{
//				doudou = 1;
//				break;
//			}
//			if (sa[now.x][now.y] == 'X')
//			{
//				break;
//			}
//			now.x += dir[i][0];
//			now.y += dir[i][1];
//		}
//	}
//	if (doudou)
//		return false;
//	return true;
//}







// 1083     二分匹配  匈牙利；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//using namespace std;
//bool visit[310];
//int link[310];
//int ar[110][310];
//int res, P, N;
//bool dfs(int f);
//int main()
//{
//	int i, j, u, n, m, a, b, k, p;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d", &P, &N);
//			memset(ar, 0, sizeof(ar));
//			memset(link, -1, sizeof(link));
//			res = 0;
//			for (i = 1; i <= P; i++)
//			{
//				scanf("%d", &k);
//				for (j = 1; j <= k; j++)
//				{
//					scanf("%d", &p);
//					ar[i][p] = 1;
//				}
//			}
//			for (i = 1; i <= P; i++)
//			{
//				memset(visit, false, sizeof(visit));
//				if (dfs(i))
//					res++;
//			}
//			if (res == P)
//				printf("YES\n");
//			else
//				printf("NO\n");
//		}
//	}
//	return 0;
//}
//bool dfs(int f)
//{
//	int i, j;
//	for (i = 1; i <= N; i++)
//	{
//		if (ar[f][i] && !visit[i])
//		{
//			visit[i] = true;
//			if (link[i] == -1 || dfs(link[i]))
//			{
//				link[i] = f;
//				return true;
//			}
//		}
//	}
//	return false;
//}







//2063   二分匹配第10题 匈牙利；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//using namespace std;
//bool visit[510];
//int ar[510][510];
//int link[510];
//int res, M, N;
//bool dfs(int f);
//int main()
//{
//	int i, j, k, u, a, b, n, m;
//	while (scanf("%d", &k) != EOF && k)
//	{
//		scanf("%d %d", &M, &N);
//		memset(ar, 0, sizeof(ar));
//		memset(link, -1, sizeof(link));
//		res = 0;
//		for (i = 1; i <= k; i++)
//		{
//			scanf("%d %d", &a, &b);
//			ar[a][b] = 1;
//		}
//		for (i = 1; i <= M; i++)
//		{
//			memset(visit, false, sizeof(visit));
//			if (dfs(i))
//				res++;
//		}
//		printf("%d\n", res);
//	}
//	return 0;
//}
//bool dfs(int f)
//{
//	int i, j;
//	for (i = 1; i <= N; i++)
//	{
//		if (ar[f][i] && !visit[i])
//		{
//			visit[i] = true;
//			if (link[i] == -1 || dfs(link[i]))
//			{
//				link[i] = f;
//				return true;
//			}
//		}
//	}
//	return false;
//}






//1009   贪心；
//#include <cstdio>
//#include <cstdlib>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//const int MAX = 100000000;
//struct point
//{
//	int a;
//	int b;
//	double c;
//};
//bool comp(const point &a, const point &b)
//{
//	return a.c > b.c;
//}
//
//int main()
//{
//	int i, j, k, u, n, m;
//	double sum;
//	point ar[100010];
//	while (scanf("%d %d", &n, &m) != EOF && (n != -1 || m != -1))
//	{
//		for (i = 1; i <= m; i++)
//		{
//			scanf("%d %d", &ar[i].a, &ar[i].b);
//			if (ar[i].b == 0)
//				ar[i].c = MAX;
//			else
//				ar[i].c = (double)ar[i].a / (double)ar[i].b;
//		}
//		sort(ar + 1, ar + 1 + m, comp);
//		//for (i = 1; i <= m; i++)
//		//{
//		//	printf("%.3lf ", ar[i].c);
//		//}
//		//putchar('\n');
//		i = 1;
//		sum = 0.0;
//		while (n >= ar[i].b && i <= m)
//		{
//			sum += (double)ar[i].a;
//			n -= ar[i].b;
//			i++;
//		}
//		if(i <= m)
//			sum += ar[i].c * (double)n;
//		printf("%.3lf\n", sum);
//	}
//	return 0;
//}








//1050  贪心；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//using namespace std;
//const int MAX = 100000000;
//int main()
//{
//	int i, j, k, u, n, m, set[300], a, b, temp, max;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &k);
//			memset(set, 0, sizeof(set));
//			max = 0;
//			for (i = 1; i <= k; i++)
//			{
//				scanf("%d %d", &a, &b);
//				if (a % 2 == 0)
//					a /= 2;
//				else
//					a = (a + 1) / 2;
//				if (b % 2 == 0)
//					b /= 2;
//				else
//					b = (b + 1) / 2;
//				if (a > b)
//				{
//					temp = a;
//					a = b;
//					b = temp;
//				}
//				for (j = a; j <= b; j++)
//					set[j]++;
//			}
//			for (i = 1; i <= 200; i++)
//				max = (max < set[i]) ? set[i] : max;
//			printf("%d\n", max*10);
//		}
//	}
//	return 0;
//}








//1789   贪心；
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <algorithm>
//const int MAX = 100000000;
//using namespace std;
//struct point
//{
//	int data;
//	int score;
//};
//bool comp(const point a, const point b)
//{
//	if (a.score != b.score)
//		return a.score > b.score;
//	else
//		return a.data < b.data;
//}
//int main()
//{
//	int i, j, k, u, n, m, set[100010], sum, doudou;
//	struct point ar[100010], temp;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &k);
//			for (i = 1; i <= k; i++)
//			{
//				scanf("%d", &ar[i].data);
//			}
//			for (i = 1; i <= k; i++)
//			{
//				scanf("%d", &ar[i].score);
//			}
//			sort(ar + 1, ar + 1 + k, comp);
//			sum = 0;
//			memset(set, 0, sizeof(set));
//			doudou = 0;
//			for (i = 1; i <= k; i++)
//			{
//				if (set[ar[i].data])
//				{
//					for (j = ar[i].data; j >= 1; j--)
//					{
//						if (!set[j])
//						{
//							set[j] = i;
//							break;
//						}
//					}
//					if (!j)
//					{
//						sum += ar[i].score;
//					}
//				}
//				else
//				{
//					set[ar[i].data] = i;
//				}
//			}
//			printf("%d\n", sum);
//		}
//	}
//	return 0;
//}










//1241  dfs(连成块问题)；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//using namespace std;
//const int MAX = 10000000;
//int visit[110][110];
//char ar[110][110];
//int cnt, a, b, N;
//int dir[8][2] = { -1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1 };
//bool dfs(int x, int y);
//int main()
//{
//	int i, j, k, u, n, m;
//	while (scanf("%d %d", &a, &b) != EOF && (a || b))
//	{
//		for (i = 1; i <= a; i++)
//		{
//			scanf("%s", ar[i] + 1);
//		}
//		memset(visit, 0, sizeof(visit));
//		cnt = 0;
//		N = 1;
//		for (i = 1; i <= a; i++)
//		{
//			for (j = 1; j <= b; j++)
//			{
//				if (ar[i][j] == '@' && !visit[i][j])
//				{
//					dfs(i, j);
//					cnt++;
//				}
//				N++;
//			}
//		}
//		printf("%d\n", cnt);
//	}
//	return 0;
//}
//bool dfs(int x, int y)
//{
//	int i, j, k, u, doudou = 0;
//	int nowx, nowy;
//	for (i = 0; i < 8; i++)
//	{
//		nowx = x + dir[i][0];
//		nowy = y + dir[i][1];
//		if (nowx > a || nowy > b || nowx < 1 || nowy < 1 || ar[nowx][nowy] == '*')
//			continue;
//		if (visit[nowx][nowy])
//			continue;
//		visit[nowx][nowy] = N;
//		doudou = 1;
//		dfs(nowx, nowy);
//	}
//	if (doudou)
//		return true;
//	else
//		return false;
//}







//1254    搜索第9题  bfs+bfs 可以走回头路只需visit[i][j][u]三维  多一个方向就行了；
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <queue>
//#include <algorithm>
//using namespace std;
//const int MAX = 100000000;
//const int MIN = -10000000;
//int visit[10][10][4];
//int vis[10][10][4];
//int ar[10][10];
//int dir[4][2] = { -1, 0, 1, 0, 0, 1, 0, -1 };
//int xb, yb, a, b, xr, yr;
//struct point
//{
//	int x;
//	int y;
//	int step;
//	int renx;
//	int reny;
//	friend bool operator < (point a, point b)
//	{
//		return a.step > b.step;
//	}
//};
//point now, after;
//struct node
//{
//	int x;
//	int y;
//	int step;
//	friend bool operator < (node t, node s)
//	{
//		return t.step > s.step;
//	}
//};
//bool r_bfs();
//void x_bfs();
//int main()
//{
//	int i, j, k, u, n, m;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d", &a, &b);
//			for (i = 1; i <= a; i++)
//			{
//				for (j = 1; j <= b; j++)
//				{
//					scanf("%d", &ar[i][j]);
//					if (ar[i][j] == 2)
//					{
//						xb = i;
//						yb = j;
//					}
//					if (ar[i][j] == 4)
//					{
//						xr = i;
//						yr = j;
//					}
//				}
//			}
//			x_bfs();
//			if (ar[now.x][now.y] == 3)
//				printf("%d\n", now.step);
//			else
//				printf("-1\n");
//		}
//	}
//	return 0;
//}
//void x_bfs()
//{
//	int i, j, k, u;
//	priority_queue<point>q;
//	for (i = 0; i <= a + 1; i++)
//	{
//		for (j = 0; j <= b + 1; j++)
//		{
//			for (u = 0; u < 4; u++)
//			{
//				visit[i][j][u] = MAX;
//			}
//		}
//	}
//	for (u = 0; u < 4; u++)
//	{
//		now.x = xb;
//		now.y = yb;
//		now.step = 0;
//		now.renx = xr;
//		now.reny = yr;
//		visit[xb][yb][u] = 0;
//		q.push(now);
//		while (!q.empty())
//		{
//			now = q.top();
//			q.pop();
//			if (ar[now.x][now.y] == 3)
//				return;
//			for (i = 0; i < 4; i++)
//			{
//				after.x = now.x + dir[i][0];
//				after.y = now.y + dir[i][1];
//				after.step = now.step + 1;
//				after.renx = now.x - dir[i][0];
//				after.reny = now.y - dir[i][1];
//				if (after.x > a || after.y > b || after.x < 1 || after.y < 1 || ar[after.x][after.y] == 1)
//					continue;
//				if (after.step <= visit[after.x][after.y][i] && r_bfs())
//				{
//					after.renx = now.x;
//					after.reny = now.y;
//					q.push(after);
//					visit[after.x][after.y][i] = after.step;
//				}
//			}
//		}
//	}
//	now.step = MAX;
//	return;
//}
//bool r_bfs()
//{
//	int i, j, k, u;
//	node qq, hh;
//	priority_queue<node>p;
//	memset(vis, 0, sizeof(vis));
//	qq.x = now.renx;
//	qq.y = now.reny;
//	qq.step = 0;
//	for (u = 0; u < 4; u++)
//	{
//		vis[qq.x][qq.y][u] = 1;
//		p.push(qq);
//		while (!p.empty())
//		{
//			qq = p.top();
//			p.pop();
//			if (qq.x == after.renx && qq.y == after.reny)
//				return true;
//			for (i = 0; i < 4; i++)
//			{
//				hh.x = qq.x + dir[i][0];
//				hh.y = qq.y + dir[i][1];
//				hh.step = qq.step + 1;
//				if (hh.x > a || hh.y > b || hh.x < 1 || hh.y < 1 || ar[hh.x][hh.y] == 1 || (hh.x == now.x && hh.y == now.y))
//					continue;
//				if (vis[hh.x][hh.y][i])
//					continue;
//				p.push(hh);
//				vis[hh.x][hh.y][i] = 1;
//			}
//		}
//	}
//	return false;
//}


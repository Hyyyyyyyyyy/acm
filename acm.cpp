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


//1171  还是生成函数 有 sum 0 这种情况。。。醉了；
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	int n, m;
//	long long sum, halfsum, i, j, k, num[1005], value[55], pre[260000], cur[260000];
//	while (scanf("%d", &n) != EOF && n > 0)
//	{
//		sum = 0;
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%lld %lld", &value[m], &num[m]);
//			sum += num[m] * value[m];
//		}
//		halfsum = sum / 2;
//		memset(pre, 0, sizeof(long long) * 260000);
//		memset(cur, 0, sizeof(long long) * 260000);
//		for (i = 0; i <= num[1] * value[1]; i += value[1])
//			pre[i] = 1;
//		for (i = 2; i <= n; i++)
//		{
//			for (j = 0; j <= halfsum; j++)
//			{
//
//				for (k = 0; k <= num[i] * value[i] && k + j <= halfsum; k += value[i])
//					cur[k + j] += pre[j];
//			}
//
//			for (j = 0; j <= halfsum; j++)
//			{
//				pre[j] = cur[j];
//				cur[j] = 0;
//			}
//		}
//
//		for (i = halfsum; i >= 0; i--)
//		{
//			if (pre[i])
//			{
//				if (i <= sum - i)
//					printf("%lld %lld\n", sum - i, i);
//				else
//					printf("%lld %lld\n", i, sum - i);
//				break;
//			}
//		}
//
//	}
//	return 0;
//}


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
//
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




//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//#include <cmath>
//using namespace std;
//const int MAX = 100000000;
//const int MIN = -1000000;
//int main()
//{
//	int i, j, k, u, a, b, c, n, m, d, bag[500010], ar[5];
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d %d %d", &a, &b, &c, &d);
//			for (i = 0; i <= d; i++)
//			{
//				bag[i] = MIN;
//			}
//			bag[0] = 0;
//			ar[1] = a;
//			ar[2] = b;
//			ar[3] = c;
//			for (i = 1; i <= 3; i++)
//			{
//				for (j = ar[i]; j <= d; j++)
//				{
//					bag[j] = (bag[j] > bag[j - ar[i]] + ar[i]) ? bag[j] : (bag[j - ar[i]] + ar[i]);
//				}
//			}
//			for (i = 0; i <= d; i++)
//				printf("%d ", bag[i]);
//			if (bag[d] > 0)
//				printf("Yes\n");
//			else
//				printf("No\n");
//		}
//	}
//	return 0;
//}






//1429  bfs + 状态压缩;
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <queue>
//#include <algorithm>
//using namespace std;
//const int MAX = 100000000;
//struct node
//{
//	int x;
//	int y;
//	int time;
//	int key;
//	friend bool operator < (node a, node b)
//	{
//		return a.time > b.time;
//	}
//};
//node now, after;
//int visit[25][25][1050], keys[15];
//char ar[25][25];
//int dir[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };
//int a, b, T, xb, yb;
//void bfs();
//int main()
//{
//	int i, j, k, u, n, m, doudou = 0;
//	while (scanf("%d %d %d", &a, &b, &T) != EOF)
//	{
//		xb = yb = MAX;
//		for (i = 1; i <= a; i++)
//		{
//			scanf("%s", ar[i] + 1);
//			if (xb == MAX && yb == MAX)
//			{
//				for (j = 1; j <= b; j++)
//				{
//					if (ar[i][j] == '@')
//					{
//						xb = i;
//						yb = j;
//					}
//				}
//			}
//		}
//		for (i = 0; i <= 11; i++)
//			keys[i] = 1 << i;
//		bfs();
//		//if (doudou)
//		//	putchar('\n');
//		//doudou = 1;
//		if (now.time < T && ar[now.x][now.y] == '^')
//			printf("%d\n", now.time);
//		else
//			printf("-1\n");
//	}
//	return 0;
//}
//void bfs()
//{
//	int i, j, k, u;
//	priority_queue<node>q;
//	memset(visit, 0, sizeof(visit));
//	now.x = xb;
//	now.y = yb;
//	now.time = 0;
//	now.key = 0;
//	visit[xb][yb][0] = 1;
//	q.push(now);
//	while (!q.empty())
//	{
//		now = q.top();
//		q.pop();
//		if (ar[now.x][now.y] == '^' && now.time < T)
//			return;
//		for (i = 0; i < 4; i++)
//		{
//			after.x = now.x + dir[i][0];
//			after.y = now.y + dir[i][1];
//			after.time = now.time + 1;
//			after.key = now.key;
//			if (after.x > a || after.y > b || after.x < 1 || after.y < 1 || ar[after.x][after.y] == '*')
//				continue;
//			if (after.time == T && ar[after.x][after.y] != '^')
//				continue;
//			if (ar[after.x][after.y] == '^' && after.time >= T)
//				continue;
//			if (ar[after.x][after.y] >= 'a' && ar[after.x][after.y] <= 'z')
//			{
//				k = ar[after.x][after.y] - 'a';
//				if (!visit[after.x][after.y][after.key | keys[k]])
//				{
//					after.key = after.key | keys[k];
//					q.push(after);
//					visit[after.x][after.y][after.key] = 1;
//				}
//			}
//			if (ar[after.x][after.y] >= 'A' && ar[after.x][after.y] <= 'Z')
//			{
//				k = ar[after.x][after.y] - 'A';
//				if (!visit[after.x][after.y][after.key] && after.key & keys[k])
//				{
//					q.push(after);
//					visit[after.x][after.y][after.key] = 1;
//				}
//			}
//			if ((ar[after.x][after.y] == '.' || ar[after.x][after.y] == '^' || ar[after.x][after.y] == '@') && !visit[after.x][after.y][after.key])
//			{
//				q.push(after);
//				visit[after.x][after.y][after.key] = 1;
//			}
//		}
//	}
//	now.time = MAX;
//}






//1195  bfs;
//#include <cstdio>
//#include <cstring>
//#include <queue>
//#include <algorithm>
//#include <cstdlib>
//using namespace std;
//const int MAX = 100000000;
//struct node
//{
//	int x1;
//	int x2;
//	int x3;
//	int x4;
//	int step;
//	friend bool operator < (node a, node b)
//	{
//		return a.step > b.step;
//	}
//};
//node now, after;
//int visit[11][11][11][11];
//char ar[5], tar[5];
//void bfs();
//int main()
//{
//	int i, j, k, u, n, m;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%s", ar + 1);
//			scanf("%s", tar + 1);
//			bfs();
//			printf("%d\n", now.step);
//		}
//	}
//	return 0;
//}
//void bfs()
//{
//	int i, j, k, u;
//	memset(visit, 0, sizeof(visit));
//	priority_queue<node>q;
//	now.x1 = ar[1] - '0';
//	now.x2 = ar[2] - '0';
//	now.x3 = ar[3] - '0';
//	now.x4 = ar[4] - '0';
//	now.step = 0;
//	visit[now.x1][now.x2][now.x3][now.x4] = 1;
//	q.push(now);
//	while (!q.empty())
//	{
//		now = q.top();
//		q.pop();
//		if (now.x1 == tar[1] - '0' && now.x2 == tar[2] - '0' && now.x3 == tar[3] - '0' && now.x4 == tar[4] - '0')
//			return;
//
//		after = now;
//		after.x1--;
//		after.step = now.step + 1;
//		if (after.x1 < '1' - '0')
//			after.x1 = '9' - '0';
//		if (!visit[after.x1][after.x2][after.x3][after.x4])
//		{
//			q.push(after);
//			visit[after.x1][after.x2][after.x3][after.x4] = 1;
//		}
//		after = now;
//		after.x2--;
//		after.step = now.step + 1;
//		if (after.x2 < '1' - '0')
//			after.x2 = '9' - '0';
//		if (!visit[after.x1][after.x2][after.x3][after.x4])
//		{
//			q.push(after);
//			visit[after.x1][after.x2][after.x3][after.x4] = 1;
//		}
//		after = now;
//		after.x3--;
//		after.step = now.step + 1;
//		if (after.x3 < '1' - '0')
//			after.x3 = '9' - '0';
//		if (!visit[after.x1][after.x2][after.x3][after.x4])
//		{
//			q.push(after);
//			visit[after.x1][after.x2][after.x3][after.x4] = 1;
//		}
//		after = now;
//		after.x4--;
//		after.step = now.step + 1;
//		if (after.x4 < '1' - '0')
//			after.x4 = '9' - '0';
//		if (!visit[after.x1][after.x2][after.x3][after.x4])
//		{
//			q.push(after);
//			visit[after.x1][after.x2][after.x3][after.x4] = 1;
//		}
//		after = now;
//		after.x1++;
//		after.step = now.step + 1;
//		if (after.x1 > '9' - '0')
//			after.x1 = '1' - '0';
//		if (!visit[after.x1][after.x2][after.x3][after.x4])
//		{
//			q.push(after);
//			visit[after.x1][after.x2][after.x3][after.x4] = 1;
//		}
//		after = now;
//		after.x2++;
//		after.step = now.step + 1;
//		if (after.x2 > '9' - '0')
//			after.x2 = '1' - '0';
//		if (!visit[after.x1][after.x2][after.x3][after.x4])
//		{
//			q.push(after);
//			visit[after.x1][after.x2][after.x3][after.x4] = 1;
//		}
//		after = now;
//		after.x3++;
//		after.step = now.step + 1;
//		if (after.x3 > '9' - '0')
//			after.x3 = '1' - '0';
//		if (!visit[after.x1][after.x2][after.x3][after.x4])
//		{
//			q.push(after);
//			visit[after.x1][after.x2][after.x3][after.x4] = 1;
//		}
//		after = now;
//		after.x4++;
//		after.step = now.step + 1;
//		if (after.x4 > '9' - '0')
//			after.x4 = '1' - '0';
//		if (!visit[after.x1][after.x2][after.x3][after.x4])
//		{
//			q.push(after);
//			visit[after.x1][after.x2][after.x3][after.x4] = 1;
//		}
//		after = now;
//		u = after.x1;
//		after.x1 = after.x2;
//		after.x2 = u;
//		after.step = now.step + 1;
//		if (!visit[after.x1][after.x2][after.x3][after.x4])
//		{
//			q.push(after);
//			visit[after.x1][after.x2][after.x3][after.x4] = 1;
//		}
//		after = now;
//		u = after.x2;
//		after.x2 = after.x3;
//		after.x3 = u;
//		after.step = now.step + 1;
//		if (!visit[after.x1][after.x2][after.x3][after.x4])
//		{
//			q.push(after);
//			visit[after.x1][after.x2][after.x3][after.x4] = 1;
//		}
//		after = now;
//		u = after.x3;
//		after.x3 = after.x4;
//		after.x4 = u;
//		after.step = now.step + 1;
//		if (!visit[after.x1][after.x2][after.x3][after.x4])
//		{
//			q.push(after);
//			visit[after.x1][after.x2][after.x3][after.x4] = 1;
//		}
//	}
//}





//1532    最大流第一题注意now的初始化，注意before[]的初始化；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <queue>
//#include <algorithm>
//using namespace std;
//const int MAX = 100000000;
//const int MIN = -100000000;
//int ar[210][210];
//int before[210], flow[210];
//int Begin, End, n, m;
//int bfs();
//int EK();
//int main()
//{
//	int i, j, k, u, a, b, c;
//	while (scanf("%d %d", &m, &n) != EOF)
//	{
//		memset(ar, 0, sizeof(ar));
//		Begin = 1;
//		End = n;
//		for (i = 1; i <= m; i++)
//		{
//			scanf("%d %d %d", &a, &b, &c);
//			ar[a][b] += c;
//		}
//		printf("%d\n", EK());
//	}
//	return 0;
//}
//int EK()
//{
//	int i, j, k, u, maxflow = 0, temp, pre, now;
//	while ((temp = bfs()) != -1)
//	{
//		now = End;
//		maxflow += temp;
//		while (now != Begin)
//		{
//			pre = before[now];
//			ar[pre][now] -= temp;
//			ar[now][pre] += temp;
//			now = pre;
//		}
//	}
//	return maxflow;
//}
//int bfs()
//{
//	queue<int>q;
//	int i, j, k, t;
//	memset(before, -1, sizeof(before));
//	before[Begin] = 0;
//	flow[Begin] = MAX;
//	q.push(Begin);
//	while (!q.empty())
//	{
//		t = q.front();
//		q.pop();
//		if (t == End)
//			break;
//		for (i = 1; i <= n; i++)
//		{
//			if (i != Begin && before[i] == -1 && ar[t][i])
//			{
//				flow[i] = (flow[t] < ar[t][i]) ? flow[t] : ar[t][i];
//				before[i] = t;
//				q.push(i);
//			}
//		}
//	}
//	return (before[End] == -1) ? -1 : flow[n];
//}







//3549  最大流第2题；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <queue>
//#include <algorithm>
//using namespace std;
//const int MAX = 100000000;
//const int MIN = -100000000;
//int ar[20][20];
//int before[20], flow[20];
//int n, m, Begin, End;
//int bfs();
//int EK();
//int main()
//{
//	int i, j, k, u, a, b, c, h, cas = 1;
//	while (scanf("%d", &k) != EOF)
//	{
//		for (u = 1; u <= k; u++)
//		{
//			scanf("%d %d", &n, &m);
//			memset(ar, 0, sizeof(ar));
//			Begin = 1;
//			End = n;
//			for (h = 1; h <= m; h++)
//			{
//				scanf("%d %d %d", &a, &b, &c);
//				ar[a][b] += c;
//			}
//			printf("Case %d: %d\n", cas++, EK());
//		}
//	}
//	return 0;
//}
//int EK()
//{
//	int i, j, k, now, pre, maxflow = 0, temp;
//	while ((temp = bfs()) != -1)
//	{
//		now = End;
//		maxflow += temp;
//		while (now != Begin)
//		{
//			pre = before[now];
//			ar[pre][now] -= temp;
//			ar[now][pre] += temp;
//			now = pre;
//		}
//	}
//	return maxflow;
//}
//
//int bfs()
//{
//	int i, j, k, t;
//	queue<int>q;
//	memset(before, -1, sizeof(before));
//	before[Begin] = 0;
//	flow[Begin] = MAX;
//	q.push(Begin);
//	while (!q.empty())
//	{
//		t = q.front();
//		q.pop();
//		if (t == End)
//			break;
//		for (i = 1; i <= n; i++)
//		{
//			if (i != Begin && before[i] == -1 && ar[t][i])
//			{
//				before[i] = t;
//				flow[i] = (flow[t] < ar[t][i]) ? flow[t] : ar[t][i];
//				q.push(i);
//			}
//		}
//	}
//	return (before[End] == -1) ? -1 : flow[n];
//}







//1565 最大流第7题  用状态压缩DP+dfs；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//using namespace std;
//const int MAX = 100000000;
//const int MIN = -100000000;
//
//unsigned long long now[1000000], pre[1000000];
//unsigned long long ar[30][30];
//unsigned long long temp[1000000], dp[1000000], ans[1000000];
//unsigned long long now_size, pre_size, n;
//void dfs(unsigned long long x, unsigned long long y, unsigned long long sta, unsigned long long sum);
//void DP();
//int main()
//{
//	unsigned long long i, j, k, u, a, b, c, res;
//	while (scanf("%llu", &n) != EOF)
//	{
//		for (i = 1; i <= n; i++)
//		{
//			for (j = 1; j <= n; j++)
//			{
//				scanf("%llu", &ar[i][j]);
//			}
//		}
//		pre_size = 2;
//		temp[1] = pre[1] = 0;
//		DP();
//		res = 0;
//		for (i = 1; i < pre_size; i++)
//		{
//			if (res < temp[i])
//				res = temp[i];
//		}
//		printf("%llu\n", res);
//	}
//	return 0;
//}
//void DP()
//{
//	unsigned long long i, j, k;
//	for (k = 1; k <= n; k++)
//	{
//		now_size = 1;
//		dfs(k, 1, 0, 0);
//		memset(dp, 0, sizeof(dp));
//		for (i = 1; i < now_size; i++)
//		{
//			for (j = 1; j < pre_size; j++)
//			{
//				if (!(now[i] & pre[j]))
//					dp[i] = (dp[i] > temp[j] + ans[i]) ? dp[i] : (temp[j] + ans[i]);
//			}
//		}
//		for (i = 1; i < now_size; i++)
//		{
//			pre[i] = now[i];
//			temp[i] = dp[i];
//		}
//		pre_size = now_size;
//	}
//}
//
//void dfs(unsigned long long x, unsigned long long y, unsigned long long sta, unsigned long long sum)
//{
//	while (y > n)
//	{
//		now[now_size] = sta;
//		ans[now_size++] = sum;
//		return;
//	}
//	dfs(x, y + 1, sta, sum);
//	dfs(x, y + 2, (sta | 1 << y), sum + ar[x][y]);
//}




//zoj 矩阵快速幂第6题；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <cctype>
//using namespace std;
//const int MAX = 100000000;
//const int MIN = -100000000;
//struct node
//{
//	long long int ar[50][50];
//};
//node temp, res, start, temp1;
//node multiply(node a, node b, int r, int c);
//int main()
//{
//	int i, j, k, u, n, m, a, b, c, t, doudou;
//	int x1, x2, x3, x4, y1, y2, y3, y4;
//	while (scanf("%d", &n) != EOF)
//	{
//		getchar();
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d", &a, &b);
//			getchar();
//			memset(start.ar, 0, sizeof(start.ar));
//			c = a * b;
//			for (i = 1; i <= a; i++)
//			{
//				for (j = 1; j <= b; j++)
//				{
//					scanf("((%d,%d),(%d,%d),(%d,%d),(%d,%d))", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4); 
//					getchar();
//					if (i == a && j == b)
//						continue;
//					start.ar[(i - 1)*b + j][(x1 - 1)*b + y1] = 1;
//					start.ar[(i - 1)*b + j][(x2 - 1)*b + y2] = 1;
//					start.ar[(i - 1)*b + j][(x3 - 1)*b + y3] = 1;
//					start.ar[(i - 1)*b + j][(x4 - 1)*b + y4] = 1;
//				}
//			}
//			scanf("%d", &k);
//			getchar();
//			for (u = 1; u <= k; u++)
//			{
//				memset(res.ar, 0, sizeof(res.ar));
//				for (i = 1; i <= c; i++)
//					res.ar[i][i] = 1;
//				temp1 = start;
//				scanf("%d", &t);
//				getchar();
//				while (t)
//				{
//					if (t % 2)
//					{
//						res = multiply(temp1, res, c, c);
//					}
//					temp1 = multiply(temp1,temp1, c, c);
//					t /= 2;
//				}
//				//for (i = 1; i <= c;i++)
//				//{
//				//	for (j = 1; j <= c; j++)
//				//	{
//				//		printf("%d ", res.ar[i][j]);
//				//	}
//				//	putchar('\n');
//				//}
//				if (!res.ar[1][c])
//					printf("False\n");
//				else
//				{
//					doudou = 0;
//					for (i = 1; i < c; i++)
//					{
//						if (res.ar[1][i])
//						{
//							doudou = 1;
//							break;
//						}
//					}
//					if (doudou)
//						printf("Maybe\n");
//					else
//						printf("True\n");
//				}
//			}
//			getchar();
//			putchar('\n');
//		}
//	}
//	return 0;
//}
//node multiply(node a, node b, int r, int c)
//{
//	int i, j, k;
//	memset(temp.ar, 0, sizeof(temp.ar));
//	for (i = 1; i <= r; i++)
//	{
//		for (j = 1; j <= c; j++)
//		{
//			for (k = 1; k <= c; k++)
//			{
//				temp.ar[i][j] += a.ar[i][k] * b.ar[k][j];
//			}
//		}
//	}
//	return temp;
//}







//2563  递推；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//#include <queue>
//using namespace std;
//const int MAX = 100000000;
//
//int main()
//{
//	int i, j, k, n, m, num, t;
//	int ar[50];
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &t);
//			ar[1] = 3;
//			ar[2] = 7;
//			if (t == 1)
//			{
//				printf("3\n");
//				continue;
//			}
//			else if (t == 2)
//			{
//				printf("7\n");
//				continue;
//			}
//			else
//			{
//				for (i = 3; i <= t; i++)
//				{
//					ar[i] = 2 * ar[i - 1] + ar[i - 2];
//				}
//				printf("%d\n", ar[t]);
//			}
//		}
//	}
//	return 0;
//}






//2190  递推；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//#include <queue>
//using namespace std;
//const int MAX = 100000000;
//
//int main()
//{
//	int i, j, k, n, m, t;
//	int ar[50];
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &t);
//			ar[1] = 1;
//			ar[2] = 3;
//			if (t == 1)
//			{
//				printf("1\n");
//				continue;
//			}
//			else if (t == 2)
//			{
//				printf("3\n");
//				continue;
//			}
//			else
//			{
//				for (i = 3; i <= t; i++)
//				{
//					ar[i] = ar[i - 1] + 2 * ar[i - 2];
//				}
//				printf("%d\n", ar[t]);
//			}
//		}
//	}
//	return 0;
//}








//zoj 矩阵快速幂第7题；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <cctype>
//#include <cmath>
//using namespace std;
//const int MAX = 100000000;
//struct node
//{
//	double ar[205][205];
//};
//struct node temp, res, start;
//void multiply(node &a, node &b, int c);
//int main()
//{
//	int i, j, k, u, n, m, sa[205], a, b, x, y, s;
//	double p, t, ans;
//	while (scanf("%d %d", &n, &m) != EOF && (n || m))
//	{
//		memset(start.ar, 0.0, sizeof(start.ar));
//		for (i = 1; i <= n; i++)
//		{
//			scanf("%d", &sa[i]);
//		}
//		scanf("%d", &k);
//		for (i = 1; i <= k; i++)
//		{
//			scanf("%d %d %lf", &x, &y, &p);
//			start.ar[x+1][y+1] += p;
//		}
//		t = 0.0;
//		for (i = 1; i <= n; i++)
//		{
//			t = 0.0;
//			for (j = 1; j <= n; j++)
//			{
//				t += start.ar[i][j];
//			}
//			start.ar[i][i] = 1.0 - t;
//		}
//		memset(res.ar, 0.0, sizeof(res.ar));
//		for (i = 1; i <= n; i++)
//		{
//			res.ar[i][i] = 1.0;
//		}
//		while (m)
//		{
//			if (m % 2)
//			{
//				multiply(res, start, n);
//			}
//			multiply(start, start, n);
//			m /= 2;
//		}
//		ans = 0.0;
//		for (i = 1; i <= n; i++)
//		{
//			ans += sa[i] * res.ar[i][n];
//		}
//		printf("%.0lf\n", ans);
//	}
//	return 0;
//}
//void multiply(node &a, node &b, int c)
//{
//	int i, j, k;
//	memset(temp.ar, 0, sizeof(temp.ar));
//	for (i = 1; i <= c; i++)
//	{
//		for (j = 1; j <= c; j++)
//		{
//			for (k = 1; k <= c; k++)
//			{
//				temp.ar[i][j] += a.ar[i][k] * b.ar[k][j];
//			}
//		}
//	}
//	a = temp;
//}








//2187  贪心；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <cstdlib>
//using namespace std;
//const int MAX = 100000000;
//struct node
//{
//	int val;
//	double per;
//	int num;
//};
//struct node ar[1010];
//bool comp(node a, node b)
//{
//	return a.per > b.per;
//}
//int main()
//{
//	int i, j, k, u, n, m, a, b, c, cost, cnt;
//	double bag;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d", &cost, &cnt);
//			for (i = 1; i <= cnt; i++)
//			{
//				scanf("%d %d", &ar[i].val, &ar[i].num);
//				ar[i].per = 1.0 / (double)ar[i].val;
//			}
//			sort(ar + 1, ar + 1 + cnt, comp);
//			bag = 0.0;
//			for (i = 1; i <= cnt; i++)
//			{
//				if (cost >= ar[i].val * ar[i].num)
//				{
//					cost -= ar[i].val*ar[i].num;
//					bag += (double)ar[i].num;
//				}
//				else
//				{
//					bag += (double)cost * ar[i].per;
//					break;
//				}
//			}
//			printf("%.2lf\n", bag);
//		}
//	}
//	return 0;
//}







//贪心 青蛙邻居；
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//struct node
//{
//	int num;
//	int index;
//};
//bool comp(node a, node b)
//{
//	return a.num > b.num;
//}
//int main()
//{
//	int i, j, k, n, m, u, a, b, c, sa[20][20], doudou;
//	struct node ar[20];
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &k);
//			for (i = 1; i <= k; i++)
//			{
//				scanf("%d", &ar[i].num);
//				ar[i].index = i;
//			}
//			memset(sa, 0, sizeof(sa));
//			sort(ar + 1, ar + 1 + k, comp);
//			doudou = 1;
//			for (i = 1; i <= k; i++)
//			{
//				for (j = i + 1; j <= i + ar[i].num && j <= k; j++)
//				{
//					sa[ar[i].index][ar[j].index] = 1;
//					sa[ar[j].index][ar[i].index] = 1;
//					ar[j].num -= 1;
//					if (ar[j].num < 0)
//					{
//						doudou = 0;
//						break;
//					}
//				}
//				if (!doudou)
//					break;
//				sort(ar + i + 1, ar + k + 1, comp);
//			}
//			if (doudou)
//			{
//				printf("YES\n");
//				for (i = 1; i <= k; i++)
//				{
//					for (j = 1; j <= k; j++)
//					{
//						printf("%d ", sa[i][j]);
//					}
//					putchar('\n');
//				}
//				putchar('\n');
//			}
//			else
//			{
//				printf("NO\n");
//				putchar('\n');
//			}
//		}
//	}
//}
//






//最近点6个；
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <algorithm>
//#include <cmath>
//using namespace std;
//const int MAX = 100000000;
//struct node
//{
//	double x;
//	double y;
//	double s;
//};
//bool comp(node a, node b)
//{
//	return a.s < b.s;
//}
//int main()
//{
//	int i, j, k, u, n, m, cnt;
//	struct node ar[100010];
//	double sa[1000010], a, b, c, min;
//	while (scanf("%d", &n) != EOF && n)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%lf %lf", &ar[m].x, &ar[m].y);
//			ar[m].s = ar[m].x + ar[m].y;
//		}
//		sort(ar + 1, ar + 1 + n, comp);
//		cnt = 1;
//		min = MAX;
//		for (i = 1; i <= n; i++)
//		{
//			for (j = i + 1; j <= i + 1 + 6 && j <= n; j++)
//			{
//				sa[cnt] = sqrt((ar[i].x - ar[j].x)*(ar[i].x - ar[j].x) + (ar[i].y - ar[j].y)*(ar[i].y - ar[j].y));
//				if (min > sa[cnt])
//					min = sa[cnt];
//				cnt++;
//			}
//		}
//		printf("%.2lf\n", min / 2.0);
//	}
//	return 0;
//}









//1533  权值二分图 KM算法；
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <algorithm>
//#include <cmath>
//using namespace std;
//const int MAX = 100000000;
//const int MIN = -100000000;
//int ar[110][110];
//char sa[110][110];
//bool visitx[110], visity[110];
//int lx[110], ly[110];
//int link[110];
//int N, M, Cntx, Cnty;
//int KM();
//bool dfs(int f);
//int main()
//{
//	int i, j, k, u, n, m, a, b, c, res;
//	while (scanf("%d %d", &N, &M) != EOF && (N || M))
//	{
//		for (i = 1; i <= N; i++)
//		{
//			scanf("%s", sa[i] + 1);
//		}
//		memset(link, -1, sizeof(link));
//		memset(ar, 0, sizeof(ar));
//		Cntx = Cnty = 1;
//		for (i = 1; i <= N; i++)
//		{
//			for (j = 1; j <= M; j++)
//			{
//				if (sa[i][j] == 'm')
//				{
//					for (a = 1; a <= N; a++)
//					{
//						for (b = 1; b <= M; b++)
//						{
//							if (sa[a][b] == 'H')
//							{
//								ar[Cntx][Cnty++] = (-1)*(abs(i - a) + abs(j - b));
//							}
//						}
//					}
//					Cntx++;
//					Cnty = 1;
//				}
//			}
//		}
//		//for (i = 1; i < Cntx; i++)
//		//{
//		//	for (j = 1; j < Cntx; j++)
//		//	{
//		//		printf("%d ", ar[i][j]);
//		//	}
//		//	putchar('\n');
//		//}
//		Cntx -= 1;
//		Cnty = Cntx;
//		printf("%d\n", -KM());
//	}
//	return 0;
//}
//int KM()
//{
//	int i, j, k, u, n, m, temp, d, res;
//	for (i = 1; i <= Cnty; i++)
//		lx[i] = MIN;
//	memset(ly, 0, sizeof(ly));
//	for (i = 1; i <= Cntx; i++)
//	{
//		for (j = 1; j <= Cnty; j++)
//		{
//			lx[i] = (lx[i] < ar[i][j]) ? ar[i][j] : lx[i];
//		}
//	}
//	for (i = 1; i <= Cntx; i++)
//	{
//		while (1)
//		{
//			memset(visitx, false, sizeof(visitx));
//			memset(visity, false, sizeof(visity));
//			temp = MAX;
//			if (dfs(i))
//				break;
//			for (u = 1; u <= Cntx; u++)
//			{
//				if (visitx[u])
//				{
//					for (j = 1; j <= Cnty; j++)
//					{
//						if (!visity[j])
//						{
//							temp = (temp < lx[u] + ly[j] - ar[u][j]) ? temp : (lx[u] + ly[j] - ar[u][j]);
//						}
//					}
//				}
//			}
//			for (k = 1; k <= Cntx; k++)
//			{
//				if (visitx[k])
//					lx[k] -= temp;
//				if (visity[k])
//					ly[k] += temp;
//			}
//		}
//	}
//	//printf("%d %d\n", Cntx, Cnty);
//	//for (i = 1; i <= Cntx; i++)
//	//	printf("%d ", link[i]);
//	//putchar('\n');
//	res = 0;
//	for (i = 1; i <= Cntx; i++)
//		if (link[i] != -1)
//			res += ar[link[i]][i];
//	return res;
//}
//bool dfs(int f)
//{
//	int i, j, k, temp;
//	visitx[f] = true;
//	for (i = 1; i <= Cnty; i++)
//	{
//		if (!visity[i] && lx[f] + ly[i] == ar[f][i])
//		{
//			visity[i] = true;
//			if (link[i] == -1 || dfs(link[i]))
//			{
//				link[i] = f;
//				return true;
//			}
//		}
//	}
//	return false;
//}









//1052  田忌赛马二分版；
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <cmath>
//using namespace std;
//const int MAX = 100000000;
//const int MIN = -100000000;
//int ar[1010][1010];
//int link[1010];
//int visitx[1010], visity[1010], lx[1010], ly[1010];
//int N;
//bool dfs(int f);
//int KM();
//int main()
//{
//	int i, j, k, u, n, m, a[1010], b[1010];
//	while (scanf("%d", &N) != EOF && N)
//	{
//		for (i = 1; i <= N; i++)
//		{
//			scanf("%d", &a[i]);
//		}
//		for (i = 1; i <= N; i++)
//		{
//			scanf("%d", &b[i]);
//		}
//		for (i = 1; i <= N; i++)
//		{
//			for (j = 1; j <= N; j++)
//			{
//				if (a[i] > b[j])
//					ar[i][j] = 1;
//				else if (a[i] == b[j])
//					ar[i][j] = 0;
//				else
//					ar[i][j] = -1;
//			}
//		}
//		printf("%d\n", 200 * KM());
//	}
//	return 0;
//}
//int KM()
//{
//	int i, j, k, u, n, m, temp, res, a, b;
//	memset(link, -1, sizeof(link));
//	memset(ly, 0, sizeof(ly));
//	for (i = 1; i <= N; i++)
//	{
//		lx[i] = MIN;
//	}
//	for (i = 1; i <= N; i++)
//	{
//		for (j = 1; j <= N; j++)
//		{
//			lx[i] = (lx[i] < ar[i][j]) ? ar[i][j] : lx[i];
//		}
//	}
//	for (i = 1; i <= N; i++)
//	{
//		memset(visitx, 0, sizeof(visitx));
//		memset(visity, 0, sizeof(visity));
//		temp = MAX;
//		while (1)
//		{
//			if (dfs(i))
//				break;
//			for (a = 1; a <= N; a++)
//			{
//				if (visitx[a])
//				{
//					for (b = 1; b <= N; b++)
//					{
//						if (!visity[b])
//						{
//							temp = (temp > lx[a] + ly[b] - ar[a][b]) ? (lx[a] + ly[b] - ar[a][b]) : temp;
//						}
//					}
//				}
//			}
//			for (a = 1; a <= N; a++)
//			{
//				if (visitx[a])
//					lx[a] -= temp;
//				if (visity[a])
//					ly[a] += temp;
//			}
//		}
//	}
//	res = 0;
//	for (i = 1; i <= N; i++)
//	{
//		if (link[i] != -1)
//			res += ar[link[i]][i];
//	}
//	return res;
//}
//bool dfs(int f)
//{
//	int i, j, k;
//	visitx[f] = 1;
//	for (i = 1; i <= N; i++)
//	{
//		if (!visity[i] && lx[f] + ly[i] == ar[f][i])
//		{
//			visity[i] = 1;
//			if (link[i] == -1 || dfs(link[i]))
//			{
//				link[i] = f;
//				return true;
//			}
//		}
//	}
//	return false;
//}








//1052  田忌赛马  贪心；
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//const int MAX = 100000000;
//const int MIN = -100000000;
//bool comp(int a, int b)
//{
//	return a > b;
//}
//int main()
//{
//	int i, j, k, u, n, m, ar[1010], sa[1010], win, lose, t_slow, t_fast, k_fast, k_slow;
//	while (scanf("%d", &n) != EOF && n)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &ar[m]);
//		}
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &sa[m]);
//		}
//		sort(ar + 1, ar + 1 + n, comp);
//		sort(sa + 1, sa + 1 + n, comp);
//		win = lose = 0;
//		t_fast = k_fast = 1;
//		t_slow = k_slow = n;
//		while (t_slow >= t_fast)
//		{
//			if (ar[t_slow] > sa[k_slow])
//			{
//				win++;
//				t_slow--;
//				k_slow--;
//			}
//			else if (ar[t_slow] < sa[k_slow])
//			{
//				lose++;
//				t_slow--;
//				k_fast++;
//			}
//			else
//			{
//				if (ar[t_fast] > sa[k_fast])
//				{
//					win++;
//					t_fast++;
//					k_fast++;
//				}
//				else
//				{
//					if (ar[t_slow] < sa[k_fast])
//					{
//						lose++;
//					}
//					t_slow--;
//					k_fast++;
//				}
//			}
//		}
//		printf("%d\n", 200 * (win - lose));
//	}
//	return 0;
//}






//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <queue>
//#include <algorithm>
//using namespace std;
//const int MAX = 100000000;
//int ar[505][505];
//int Max;
//int dinic();
//int dfs(int st, int ed, int fl);
//int bfs(int st, int ed);
//int dep[600];
//int main()
//{
//	int i, j, k, u, n, m, a, b, c, p, q, r, cas = 1, sum;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			memset(ar, 0, sizeof(ar));
//			Max = 0;
//			sum = 0;
//			scanf("%d %d", &a, &b);
//			for (i = 1; i <= a; i++)
//			{
//				scanf("%d %d %d", &r, &p, &q);
//				sum += r;
//				Max = (Max < q) ? q : Max;
//				ar[0][i] = r;
//				for (j = p; j <= q; j++)
//				{
//					ar[i][j] = 1;
//				}
//			}
//			for (i = 1; i <= Max; i++)
//			{
//				ar[i][Max + 1] = b;
//			}
//			if ((k = dinic()) == sum)
//				printf("Case %d: Yes\n", cas++);
//			else
//				printf("Case %d: No\n", cas++);
//		}
//	}
//	return 0;
//}
//int dinic()
//{
//	int i, j, res = 0, temp;
//	while (bfs(0, Max + 1))
//	{
//		while (1)
//		{
//			temp = dfs(0, Max + 1, MAX);
//			if (temp == 0)
//				break;
//			res += temp;
//		}
//	}
//	return res;
//}
//int dfs(int st, int ed, int fl)
//{
//	int i, j, k, temp, flow;
//	if (st == ed)
//		return fl;
//	for (i = 0; i <= Max + 1; i++)
//	{
//		if (ar[st][i] && dep[i] == dep[st] + 1)
//		{
//			flow = (fl < ar[st][i]) ? fl : ar[st][i];
//			if (temp = dfs(i, ed, flow))
//			{
//				ar[st][i] -= temp;
//				ar[i][st] += temp;
//				return temp;
//			}
//		}
//	}
//	return 0;
//}
//int bfs(int st, int ed)
//{
//	int i, j, k, u, t;
//	queue<int>q;
//	memset(dep, -1, sizeof(dep));
//	dep[st] = 0;
//	q.push(st);
//	while (!q.empty())
//	{
//		t = q.front();
//		q.pop();
//		for (i = 1; i <= Max + 1; i++)
//		{
//			if (dep[i] == -1 && ar[t][i])
//			{
//				dep[i] = dep[t] + 1;
//				q.push(i);
//			}
//		}
//	}
//	if (dep[ed] == -1)
//		return 0;
//	return 1;
//}
//#include<iostream>  
//#include<queue>  
//#include<cstdio>  
//#include<cstring>  
//using namespace std;
//const int inf = 0x3f3f3f3f;
//const int maxv = 1001, maxe = 200101;
//int nume = 0; int head[maxv]; int e[maxe][3];
//void inline adde(int i, int j, int c)
//{
//	e[nume][0] = j; e[nume][1] = head[i]; head[i] = nume;
//	e[nume++][2] = c;
//	e[nume][0] = i; e[nume][1] = head[j]; head[j] = nume;
//	e[nume++][2] = 0;
//}
//int ss, tt, n, m, all;
//int vis[maxv]; int lev[maxv];
//bool bfs()
//{
//	for (int i = 0; i<maxv; i++)
//		vis[i] = lev[i] = 0;
//	queue<int>q;
//	q.push(ss);
//	vis[ss] = 1;
//	while (!q.empty())
//	{
//		int cur = q.front();
//		q.pop();
//		for (int i = head[cur]; i != -1; i = e[i][1])
//		{
//			int v = e[i][0];
//			if (!vis[v] && e[i][2]>0)
//			{
//				lev[v] = lev[cur] + 1;
//				vis[v] = 1;
//				q.push(v);
//			}
//		}
//	}
//	return vis[tt];
//}
//int dfs(int u, int minf)
//{
//	if (u == tt || minf == 0)return minf;
//	int sumf = 0, f;
//	for (int i = head[u]; i != -1 && minf; i = e[i][1])
//	{
//		int v = e[i][0];
//		if (lev[v] == lev[u] + 1 && e[i][2]>0)
//		{
//			f = dfs(v, minf<e[i][2] ? minf : e[i][2]);
//			e[i][2] -= f; e[i ^ 1][2] += f;
//			sumf += f; minf -= f;
//		}
//	}
//	if (!sumf) lev[u] = -1;
//	return sumf;
//}
//int dinic()
//{
//	int sum = 0;
//	while (bfs())sum += dfs(ss, inf);
//	return sum;
//}
//void read_build()
//{
//	int pi, si, ei;
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d%d%d", &pi, &si, &ei);
//		all += pi;
//		adde(ss, i, pi);
//		for (int j = si; j <= ei; j++)
//		{
//			adde(i, n + j, 1);
//		}
//	}
//	for (int i = 1; i <= 500; i++)
//	{
//		adde(i + n, tt, m);
//	}
//}
//void init()
//{
//	scanf("%d%d", &n, &m);
//	nume = 0; all = 0;
//	memset(head, -1, sizeof(head));
//	ss = n + 501; tt = n + 502;
//}
//int main()
//{
//	int T;
//	scanf("%d", &T); int ct = 1;
//	while (T--)
//	{
//		init();
//		read_build();
//		int ans = dinic();
//		if (ans == all)printf("Case %d: Yes\n\n", ct++);
//		else printf("Case %d: No\n\n", ct++);
//	}
//}








//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <cmath>
//using namespace std;
//int main()
//{
//	int i, j, k, n, m, u;
//	long long ar[100010], res, S, T, temp;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &k);
//			S = 0;
//			T = 1;
//			for (u = 1; u <= k; u++)
//			{
//				scanf("%lld", &ar[u]);
//				S += ar[u];
//			}
//			res = T = ar[1];
//			for (i = 2; i <= k; i++)
//			{
//				T = res;
//				temp = ar[i];
//				while (temp)
//				{
//					if (temp % 2)
//					{
//						res = (res + T) % S;
//					}
//					T = (T + T) % S;
//					temp /= 2;
//				}
//			}
//			printf("%lld\n", res);
//		}
//	}
//	return 0;
//}










//快速乘法；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <cmath>
//using namespace std;
//long long MUL(long long a, long long b, long long c);
//int main()
//{
//	int i, j, k, n, m, u;
//	long long ar[100010], res, S, T, temp;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &k);
//			S = 0;
//			T = 1;
//			for (u = 1; u <= k; u++)
//			{
//				scanf("%lld", &ar[u]);
//				S += ar[u];
//			}
//			res = ar[1];
//			for (i = 2; i <= k; i++)
//			{
//				res = MUL(res, ar[i], S);
//			}
//			printf("%lld\n", res);
//		}
//	}
//	return 0;
//}
//long long MUL(long long a, long long b, long long c)
//{
//	long long res = 0, temp, i, k;
//	while (b)
//	{
//		if (b % 2)
//		{
//			res = (res + a) % c;
//		}
//		a = (a + a) % c;
//		b /= 2;
//	}
//	return res;
//}












//这是3个变量2个等式问题；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <cmath>
//#include <cctype>
//using namespace std;
//const int MAX = 100000000;
//const int MIN = -100000000;
//int main()
//{
//	long long i, j, k, u, n, m, a, b, c, p, doudou, q, r, t, s;
//	while (scanf("%lld %lld %lld %lld %lld", &n, &k, &a, &b, &c) != EOF)
//	{
//		doudou = 0;
//		p = a - c;
//		q = b - c;
//		r = n - c*k;
//		t = n / a;
//		t += n % a;
//		s = n / b;
//		s += n % b;
//		for (i = 0; i <= t; i++)
//		{
//			for (j = 0; j <= s; j++)
//			{
//				if (p*i + q*j == r && k -i -j >= 0)
//				{
//					doudou = 1;
//					break;
//				}
//			}
//			if (doudou)
//				break;
//		}
//		//printf("%d %d %d\n", i, j, k - i - j);
//		if (doudou)
//			printf("Yes\n");
//		else
//			printf("No\n");
//	}
//	return 0;
//}






//同源数； 如果x和y的质因子集合完全相同，那么我们就说他们是同源的；
//				令 d=gcd(x,y)，将x和y不断与d进行约分。  
//				若此时x=y=1，那么说明其质因子集合相同。 
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <cmath>
//#include <cctype>
//using namespace std;
//typedef long long ll;
//const int MAX = 100000000;
//const int MIN = -100000000;
//ll gcd(ll a, ll b);
//int main()
//{
//	ll i, j, k, u, n, m, p, q, a, b, temp, doudou;
//	while (scanf("%lld %lld", &n, &m) != EOF)
//	{
//		doudou = 0;
//		q = gcd(n, m);
//		temp = q;
//		while (temp != 1)
//		{
//			temp = gcd(n, temp);
//			n /= temp;
//			if (n == 1)
//			{
//				doudou = 1;
//				break;
//			}
//		}
//		if (!doudou)
//		{
//			printf("No\n");
//			continue;
//		}
//		temp = q;
//		while (temp != 1)
//		{
//			temp = gcd(m, temp);
//			m /= temp;
//			if (temp == 1)
//			{
//				if (m != 1)
//					doudou = 0;
//				break;
//			}
//		}
//		if (doudou)
//			printf("Yes\n");
//		else
//			printf("No\n");
//	}
//	return 0;
//}
//ll gcd(ll a, ll b)
//{
//	ll temp;
//	while (b)
//	{
//		temp = b;
//		b = a % b;
//		a = temp;
//	}
//	return a;
//}







//加减背包， 无非就是范围开成2倍的sum；
//#include<cstdio>
//#include<cstring>
//#include<cmath>
//using namespace std;
//int main()
//{
//	int i, j, k, u, n, m, ar[110], dp[30010], sum, p, q;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &p);
//			sum = 0;
//			for (i = 1; i <= p; i++)
//			{
//				scanf("%d", &ar[i]);
//				sum += ar[i];
//			}
//			for (i = 0; i <= sum * 2; i++)
//			{
//				dp[i] = -sum;
//			}
//			for (i = 1; i <= p; i++)
//			{
//				for (k = 1; k <= 2; k++)
//				{
//					for (j = 2 * sum; j >= ar[i]; j--)
//					{
//						dp[j] = (dp[j] > dp[j - ar[i]] + ar[i]) ? dp[j] : (dp[j - ar[i]] + ar[i]);
//					}
//				}
//			}
//			//for (i = 0; i <= sum * 2; i++)
//			//	printf("%d ", dp[i]);
//			//putchar('\n');
//			scanf("%d", &k);
//			for (i = 1; i <= k; i++)
//			{
//				scanf("%d", &q);
//				if (dp[q+sum] == q)
//					printf("YES\n");
//				else
//					printf("NO\n");
//			}
//		}
//	}
//	return 0;
//}








//双指针，滑动区间；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <queue>
//#include <algorithm>
//#include <cmath>
//using namespace std;
//int main()
//{
//	long long int i, j, k, u, n, m, a, b, c, t, sum, max, cost, ar[50100], sa[50100], hap, M, doudou;
//	long long int *p, *q;
//	while (scanf("%lld", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%lld %lld", &c, &cost);
//			for (i = 1; i <= c; i++)
//			{
//				scanf("%lld", &ar[i]);
//			}
//			for (i = 1; i <= c; i++)
//			{
//				scanf("%lld", &sa[i]);
//			}
//			sum = 0;
//			max = 0;
//			hap = 0;
//			M = 0;
//			for (p = ar+1, q = ar, i = 0, j = 1; i <= c;)
//			{
//				if (sum - max <= cost)
//				{
//					if (M < hap)
//						M = hap;
//					q++;
//					i++;
//					if (i > c)
//						break;
//					sum += *q;
//					hap += sa[i];
//					max = (max > *q) ? max : *q;
//				}
//				else
//				{
//					sum -= *p;
//					hap -= sa[j];
//					p++;
//					j++;
//					max = 0;
//					for (k = j; k <= i; k++)
//					{
//						if (max < ar[k])
//							max = ar[k];
//					}
//				}
//			}
//			printf("%lld\n", M);
//		}
//	}
//	return 0;
//}








//1166   树状数组第一题；
//#include <cstdio>
//#include <iostream>
//#include <string>
//#include <cstring>
//#include <cstdlib>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//const int MAX = 100000000;
//const int MIN = -100000000;
//int main()
//{
//	int i, n, m, j, k, u, p, q, a, b, ar[50010], sum, cas, doudou, temp;
//	string s;
//	while (scanf("%d", &n) != EOF)
//	{
//		cas = 1;
//		for (m = 1; m <= n; m++)
//		{
//			doudou = 0;
//			memset(ar, 0, sizeof(ar));
//			scanf("%d", &p);
//			for (i = 1; i <= p; i++)
//			{
//				scanf("%d", &temp);
//				k = i;
//				while (k <= p)
//				{
//					ar[k] += temp;
//					k += k & -k;
//				}
//			}
//			//ar[0] = 0;
//			while (cin >> s && s != "End")
//			{
//				scanf("%d %d", &a, &b);
//				if (s == "Query")
//				{
//					k = b;
//					sum = 0;
//					while (k > 0)
//					{
//						sum += ar[k];
//						k -= k & -k;
//					}
//					k = a - 1;
//					while (k > 0)
//					{
//						sum -= ar[k];
//						k -= k & -k;
//					}
//					if (!doudou)
//					{
//						printf("Case %d:\n", cas++);
//					}
//					doudou = 1;
//					printf("%d\n", sum);
//				}
//				else if (s == "Add")
//				{
//					k = a;
//					while (k <= p)
//					{
//						ar[k] += b;
//						k += k & (-k);
//					}
//				}
//				else if (s == "Sub")
//				{
//					k = a;
//					while (k <= p)
//					{
//						ar[k] -= b;
//						k += k & (-k);
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}





//1556 树状数组第二题；
//#include <cstdio>
//#include <iostream>
//#include <cstring>
//#include <cstdlib>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//const int MAX = 100000000;
//const int MIN = -100000000;
//int main()
//{
//	int i, n, m, j, k, u, p, q, a, b, ar[100010], sum, cas, doudou;
//	while (scanf("%d", &n) != EOF && n)
//	{
//		memset(ar, 0, sizeof(ar));
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d", &a, &b);
//			k = a;
//			while (k <= n)
//			{
//				ar[k]++;
//				k += k & -k;
//			}
//			k = b+1;
//			while (k <= n)
//			{
//				ar[k]--;
//				k += k & -k;
//			}
//		}
//		for (i = 1; i <= n; i++)
//		{
//			k = i;
//			sum = 0;
//			while (k)
//			{
//				sum += ar[k];
//				k -= k & -k;
//			}
//			printf("%s%d", (i == 1) ? "\0":" ", (i == 1) ? ar[i]:sum );
//		}
//		putchar('\n');
//	}
//	return 0;
//}








//3743   归并排序；
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <algorithm>
//#include <cmath>
//using namespace std;
//typedef long long ll;
//ll res;
//int ar[1000010], temp[1000010];
//void merge(int left, int mid, int right);
//void merge_sort(int left, int right);
//int main()
//{
//	int i, j, k, u, n, m, b;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &ar[m]);
//		}
//		res = 0;
//		merge_sort(1, n);
//		//for (i = 1; i <= n; i++)
//		//    printf("%d\n", ar[i]);
//		printf("%lld\n", res);
//	}
//	return 0;
//}
//void merge_sort(int left, int right)
//{
//	if (left >= right)
//		return;
//	int mid;
//	mid = (left + right) / 2;
//	merge_sort(left, mid);
//	merge_sort(mid + 1, right);
//	merge(left, mid, right);
//}
//void merge(int left, int mid, int right)
//{
//	int i, j, k;
//	i = left;
//	j = mid + 1;
//	for (k = left; k <= right; k++)
//	{
//		temp[k] = ar[k];
//	}
//	for (k = left; k <= right; k++)
//	{
//		if (i > mid)
//			ar[k] = temp[j++];
//		else if (j > right)
//			ar[k] = temp[i++];
//		else if (temp[i] <= temp[j])
//			ar[k] = temp[i++];
//		else
//		{
//			ar[k] = temp[j++];
//			res += mid - i + 1;
//		}
//	}
//}








//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <cmath>
//using namespace std;
//const int MAX = 100000000;
//int main()
//{
//	int i, j, k, n, m, a, b, c, p, q, ar[1000010], cas, sum, doudou, x1, y1, x2, y2, temp;
//	char s[10];
//	while (scanf("%d", &n) != EOF)
//	{
//		cas = 1;
//		for (m = 1; m <= n; m++)
//		{
//			doudou = 0;
//			memset(ar, 0, sizeof(ar));
//			for (i = 1; i <= 1000000; i++)
//			{
//				k = i;
//				while (k <= 1000000)
//				{
//					ar[k] += 1;
//					k += k & -k;
//				}
//			}
//			scanf("%d", &p);
//			for (q = 1; q <= p; q++)
//			{
//				scanf("%s", s);
//				if (!strcmp(s, "S"))
//				{
//					sum = 0;
//					scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
//					if (x1 > x2)
//					{
//						temp = x1;
//						x1 = x2;
//						x2 = temp;
//					}
//					if (y1 > y2)
//					{
//						temp = y1;
//						y1 = y2;
//						y2 = temp;
//					}
//					k = (x2 ) * 1000 + y2;
//					while (k)
//					{
//						sum += ar[k];
//						k -= k & -k;
//					}
//					k = (x1 - 1) * 1000 + y2;
//					while (k)
//					{
//						sum -= ar[k];
//						k -= k & -k;
//					}
//					k = (x2) * 1000 + y1-1;
//					while (k)
//					{
//						sum -= ar[k];
//						k -= k & -k;
//					}
//					k = (x1 - 1) * 1000 + y1-1;
//					while (k)
//					{
//						sum += ar[k];
//						k -= k & -k;
//					}
//					if (!doudou)
//						printf("Case %d:\n", cas++);
//					doudou = 1;
//					printf("%d\n", sum);
//				}
//				else if (!strcmp(s, "A"))
//				{
//					scanf("%d %d %d", &x1, &y1, &c);
//					k = (x1 - 1) * 1000 + y1;
//					while (k <= 1000000)
//					{
//						ar[k] += c;
//						k += k & -k;
//					}
//				}
//				else if (!strcmp(s, "D"))
//				{
//					scanf("%d %d %d", &x1, &y1, &c);
//					k = (x1 - 1) * 1000 + y1;
//					while (k <= 1000000)
//					{
//						ar[k] -= c;
//						if (ar[k] < 0)
//							ar[k] = 0;
//						k += k & -k;
//					}
//				}
//				else
//				{
//					scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &c);
//					k = (x1 - 1) * 1000 + y1;
//					while (k <= 1000000)
//					{
//						ar[k] -= c;
//						if (ar[k] < 0)
//							ar[k] = 0;
//						k += k & -k;
//					}
//					k = (x2 - 1) * 1000 + y2;
//					while (k <= 1000000)
//					{
//						ar[k] += c;
//						k += k & -k;
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}







//4540   dp(打地鼠);
//#include <cstdio>
//#include <cstring>
//#include <cmath>
//#include <algorithm>
//#include <cstdlib>
//using namespace std;
//const int MAX = 100000000;
//const int MIN = -100000000;
//int main()
//{
//	int i, j, k, n, m, u, a, b, bag[30][510], ar[30][510], max, min;
//	while (scanf("%d %d", &n, &m) != EOF)
//	{
//		memset(ar, 0, sizeof(ar));
//		max = MIN;
//		for (i = 1; i <= n; i++)
//		{
//			for (j = 1; j <= m; j++)
//			{
//				scanf("%d", &a);
//				ar[i][a] = 1;
//				max = (max < a) ? a : max;
//			}
//		}
//		for (i = 1; i <= n; i++)
//		{
//			for (j = 1; j <= max; j++)
//			{
//				if (i == 1)
//					bag[i][j] = 0;
//				else
//					bag[i][j] = MAX;
//			}
//		}
//		min = MAX;
//		for (i = 2; i <= n; i++)
//		{
//			for (j = 1; j <= max; j++)
//			{
//				if (!ar[i][j])
//					continue;
//				for (k = 1; k <= max; k++)
//				{
//					if (!ar[i - 1][k])
//						continue;
//					bag[i][j] = (bag[i][j] > bag[i - 1][k] + abs(k - j)) ? (bag[i - 1][k] + abs(k - j)) : bag[i][j];
//				}
//			}
//		}
//		for (i = 1; i <= max; i++)
//			if (min > bag[n][i])
//				min = bag[n][i];
//		printf("%d\n", min);
//	}
//	return 0;
//}







//1058  第一次打表，很实用；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//typedef long long ll;
//const int MAX = 100000000;
//const int MIN = -100000000;
//int main()
//{
//	ll i, j, k, u, n, m, a, b, c, h, t;
//	freopen("D:\\ProgramData\\information.txt", "w", stdout);
//	for (i = 1; i <= 2000000000; i++)
//	{
//		t = i;
//		while (t % 2 == 0)
//		{
//			t /= 2;
//		}
//		while (t % 3 == 0)
//		{
//			t /= 3;
//		}
//		while (t % 5 == 0)
//		{
//			t /= 5;
//		}
//		while (t % 7 == 0)
//		{
//			t /= 7;
//		}
//		if (t == 1)
//			printf("%lld,", i);
//	}
//	return 0;
//}

//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//typedef long long ll;
//const int MAX = 100000000;
//const int MIN = -100000000;
//int main()
//{
//	int i, j, k, u, n, m, a, b, c, h;
//	ll ar[] = { 1,2,3,4,5,6,7,8,9,10,12,14,15,16,18,20,21,24,25,27,28,30,32,35,36,40,42,45,48,49,50,54,56,60,63,64,70,72,75,80,81,84,90,96,98,100,105,108,112,120,125,126,128,135,140,144,147,150,160,162,168,175,180,189,192,196,200,210,216,224,225,240,243,245,250,252,256,270,280,288,294,300,315,320,324,336,343,350,360,375,378,384,392,400,405,420,432,441,448,450,480,486,490,500,504,512,525,540,560,567,576,588,600,625,630,640,648,672,675,686,700,720,729,735,750,756,768,784,800,810,840,864,875,882,896,900,945,960,972,980,1000,1008,1024,1029,1050,1080,1120,1125,1134,1152,1176,1200,1215,1225,1250,1260,1280,1296,1323,1344,1350,1372,1400,1440,1458,1470,1500,1512,1536,1568,1575,1600,1620,1680,1701,1715,1728,1750,1764,1792,1800,1875,1890,1920,1944,1960,2000,2016,2025,2048,2058,2100,2160,2187,2205,2240,2250,2268,2304,2352,2400,2401,2430,2450,2500,2520,2560,2592,2625,2646,2688,2700,2744,2800,2835,2880,2916,2940,3000,3024,3072,3087,3125,3136,3150,3200,3240,3360,3375,3402,3430,3456,3500,3528,3584,3600,3645,3675,3750,3780,3840,3888,3920,3969,4000,4032,4050,4096,4116,4200,4320,4374,4375,4410,4480,4500,4536,4608,4704,4725,4800,4802,4860,4900,5000,5040,5103,5120,5145,5184,5250,5292,5376,5400,5488,5600,5625,5670,5760,5832,5880,6000,6048,6075,6125,6144,6174,6250,6272,6300,6400,6480,6561,6615,6720,6750,6804,6860,6912,7000,7056,7168,7200,7203,7290,7350,7500,7560,7680,7776,7840,7875,7938,8000,8064,8100,8192,8232,8400,8505,8575,8640,8748,8750,8820,8960,9000,9072,9216,9261,9375,9408,9450,9600,9604,9720,9800,10000,10080,10125,10206,10240,10290,10368,10500,10584,10752,10800,10935,10976,11025,11200,11250,11340,11520,11664,11760,11907,12000,12005,12096,12150,12250,12288,12348,12500,12544,12600,12800,12960,13122,13125,13230,13440,13500,13608,13720,13824,14000,14112,14175,14336,14400,14406,14580,14700,15000,15120,15309,15360,15435,15552,15625,15680,15750,15876,16000,16128,16200,16384,16464,16800,16807,16875,17010,17150,17280,17496,17500,17640,17920,18000,18144,18225,18375,18432,18522,18750,18816,18900,19200,19208,19440,19600,19683,19845,20000,20160,20250,20412,20480,20580,20736,21000,21168,21504,21600,21609,21870,21875,21952,22050,22400,22500,22680,23040,23328,23520,23625,23814,24000,24010,24192,24300,24500,24576,24696,25000,25088,25200,25515,25600,25725,25920,26244,26250,26460,26880,27000,27216,27440,27648,27783,28000,28125,28224,28350,28672,28800,28812,29160,29400,30000,30240,30375,30618,30625,30720,30870,31104,31250,31360,31500,31752,32000,32256,32400,32768,32805,32928,33075,33600,33614,33750,34020,34300,34560,34992,35000,35280,35721,35840,36000,36015,36288,36450,36750,36864,37044,37500,37632,37800,38400,38416,38880,39200,39366,39375,39690,40000,40320,40500,40824,40960,41160,41472,42000,42336,42525,42875,43008,43200,43218,43740,43750,43904,44100,44800,45000,45360,45927,46080,46305,46656,46875,47040,47250,47628,48000,48020,48384,48600,49000,49152,49392,50000,50176,50400,50421,50625,51030,51200,51450,51840,52488,52500,52920,53760,54000,54432,54675,54880,55125,55296,55566,56000,56250,56448,56700,57344,57600,57624,58320,58800,59049,59535,60000,60025,60480,60750,61236,61250,61440,61740,62208,62500,62720,63000,63504,64000,64512,64800,64827,65536,65610,65625,65856,66150,67200,67228,67500,68040,68600,69120,69984,70000,70560,70875,71442,71680,72000,72030,72576,72900,73500,73728,74088,75000,75264,75600,76545,76800,76832,77175,77760,78125,78400,78732,78750,79380,80000,80640,81000,81648,81920,82320,82944,83349,84000,84035,84375,84672,85050,85750,86016,86400,86436,87480,87500,87808,88200,89600,90000,90720,91125,91854,91875,92160,92610,93312,93750,94080,94500,95256,96000,96040,96768,97200,98000,98304,98415,98784,99225,100000,100352,100800,100842,101250,102060,102400,102900,103680,104976,105000,105840,107163,107520,108000,108045,108864,109350,109375,109760,110250,110592,111132,112000,112500,112896,113400,114688,115200,115248,116640,117600,117649,118098,118125,119070,120000,120050,120960,121500,122472,122500,122880,123480,124416,125000,125440,126000,127008,127575,128000,128625,129024,129600,129654,131072,131220,131250,131712,132300,134400,134456,135000,136080,137200,137781,138240,138915,139968,140000,140625,141120,141750,142884,143360,144000,144060,145152,145800,147000,147456,148176,150000,150528,151200,151263,151875,153090,153125,153600,153664,154350,155520,156250,156800,157464,157500,158760,160000,161280,162000,163296,163840,164025,164640,165375,165888,166698,168000,168070,168750,169344,170100,171500,172032,172800,172872,174960,175000,175616,176400,177147,178605,179200,180000,180075,181440,182250,183708,183750,184320,185220,186624,187500,188160,189000,190512,192000,192080,193536,194400,194481,196000,196608,196830,196875,197568,198450,200000,200704,201600,201684,202500,204120,204800,205800,207360,209952,210000,211680,212625,214326,214375,215040,216000,216090,217728,218700,218750,219520,220500,221184,222264,224000,225000,225792,226800,229376,229635,230400,230496,231525,233280,234375,235200,235298,236196,236250,238140,240000,240100,241920,243000,244944,245000,245760,246960,248832,250000,250047,250880,252000,252105,253125,254016,255150,256000,257250,258048,259200,259308,262144,262440,262500,263424,264600,268800,268912,270000,272160,273375,274400,275562,275625,276480,277830,279936,280000,281250,282240,283500,285768,286720,288000,288120,290304,291600,294000,294912,295245,296352,297675,300000,300125,301056,302400,302526,303750,306180,306250,307200,307328,308700,311040,312500,313600,314928,315000,317520,320000,321489,322560,324000,324135,326592,327680,328050,328125,329280,330750,331776,333396,336000,336140,337500,338688,340200,343000,344064,345600,345744,349920,350000,351232,352800,352947,354294,354375,357210,358400,360000,360150,362880,364500,367416,367500,368640,370440,373248,375000,376320,378000,381024,382725,384000,384160,385875,387072,388800,388962,390625,392000,393216,393660,393750,395136,396900,400000,401408,403200,403368,405000,408240,409600,411600,413343,414720,416745,419904,420000,420175,421875,423360,425250,428652,428750,430080,432000,432180,435456,437400,437500,439040,441000,442368,444528,448000,450000,451584,453600,453789,455625,458752,459270,459375,460800,460992,463050,466560,468750,470400,470596,472392,472500,476280,480000,480200,483840,486000,489888,490000,491520,492075,493920,496125,497664,500000,500094,501760,504000,504210,506250,508032,510300,512000,514500,516096,518400,518616,524288,524880,525000,526848,529200,531441,535815,537600,537824,540000,540225,544320,546750,546875,548800,551124,551250,552960,555660,559872,560000,562500,564480,567000,571536,573440,576000,576240,580608,583200,583443,588000,588245,589824,590490,590625,592704,595350,600000,600250,602112,604800,605052,607500,612360,612500,614400,614656,617400,622080,625000,627200,629856,630000,635040,637875,640000,642978,643125,645120,648000,648270,653184,655360,656100,656250,658560,661500,663552,666792,672000,672280,675000,677376,680400,686000,688128,688905,691200,691488,694575,699840,700000,702464,703125,705600,705894,708588,708750,714420,716800,720000,720300,725760,729000,734832,735000,737280,740880,746496,750000,750141,752640,756000,756315,759375,762048,765450,765625,768000,768320,771750,774144,777600,777924,781250,784000,786432,787320,787500,790272,793800,800000,802816,806400,806736,810000,816480,819200,820125,823200,823543,826686,826875,829440,833490,839808,840000,840350,843750,846720,850500,857304,857500,860160,864000,864360,870912,874800,875000,878080,882000,884736,885735,889056,893025,896000,900000,900375,903168,907200,907578,911250,917504,918540,918750,921600,921984,926100,933120,937500,940800,941192,944784,945000,952560,960000,960400,964467,967680,972000,972405,979776,980000,983040,984150,984375,987840,992250,995328,1000000,1000188,1003520,1008000,1008420,1012500,1016064,1020600,1024000,1029000,1032192,1036800,1037232,1048576,1049760,1050000,1053696,1058400,1058841,1062882,1063125,1071630,1071875,1075200,1075648,1080000,1080450,1088640,1093500,1093750,1097600,1102248,1102500,1105920,1111320,1119744,1120000,1125000,1128960,1134000,1143072,1146880,1148175,1152000,1152480,1157625,1161216,1166400,1166886,1171875,1176000,1176490,1179648,1180980,1181250,1185408,1190700,1200000,1200500,1204224,1209600,1210104,1215000,1224720,1225000,1228800,1229312,1234800,1240029,1244160,1250000,1250235,1254400,1259712,1260000,1260525,1265625,1270080,1275750,1280000,1285956,1286250,1290240,1296000,1296540,1306368,1310720,1312200,1312500,1317120,1323000,1327104,1333584,1344000,1344560,1350000,1354752,1360800,1361367,1366875,1372000,1376256,1377810,1378125,1382400,1382976,1389150,1399680,1400000,1404928,1406250,1411200,1411788,1417176,1417500,1428840,1433600,1440000,1440600,1451520,1458000,1469664,1470000,1474560,1476225,1481760,1488375,1492992,1500000,1500282,1500625,1505280,1512000,1512630,1518750,1524096,1530900,1531250,1536000,1536640,1543500,1548288,1555200,1555848,1562500,1568000,1572864,1574640,1575000,1580544,1587600,1594323,1600000,1605632,1607445,1612800,1613472,1620000,1620675,1632960,1638400,1640250,1640625,1646400,1647086,1653372,1653750,1658880,1666980,1679616,1680000,1680700,1687500,1693440,1701000,1714608,1715000,1720320,1728000,1728720,1741824,1749600,1750000,1750329,1756160,1764000,1764735,1769472,1771470,1771875,1778112,1786050,1792000,1800000,1800750,1806336,1814400,1815156,1822500,1835008,1837080,1837500,1843200,1843968,1852200,1866240,1875000,1881600,1882384,1889568,1890000,1905120,1913625,1920000,1920800,1928934,1929375,1935360,1944000,1944810,1953125,1959552,1960000,1966080,1968300,1968750,1975680,1984500,1990656,2000000,2000376,2007040,2016000,2016840,2025000,2032128,2041200,2048000,2058000,2064384,2066715,2073600,2074464,2083725,2097152,2099520,2100000,2100875,2107392,2109375,2116800,2117682,2125764,2126250,2143260,2143750,2150400,2151296,2160000,2160900,2177280,2187000,2187500,2195200,2204496,2205000,2211840,2222640,2239488,2240000,2250000,2250423,2257920,2268000,2268945,2278125,2286144,2293760,2296350,2296875,2304000,2304960,2315250,2322432,2332800,2333772,2343750,2352000,2352980,2359296,2361960,2362500,2370816,2381400,2400000,2401000,2408448,2419200,2420208,2430000,2449440,2450000,2457600,2458624,2460375,2469600,2470629,2480058,2480625,2488320,2500000,2500470,2508800,2519424,2520000,2521050,2531250,2540160,2551500,2560000,2571912,2572500,2580480,2592000,2593080,2612736,2621440,2624400,2625000,2634240,2646000,2654208,2657205,2667168,2679075,2688000,2689120,2700000,2701125,2709504,2721600,2722734,2733750,2734375,2744000,2752512,2755620,2756250,2764800,2765952,2778300,2799360,2800000,2809856,2812500,2822400,2823576,2834352,2835000,2857680,2867200,2880000,2881200,2893401,2903040,2916000,2917215,2939328,2940000,2941225,2949120,2952450,2953125,2963520,2976750,2985984,3000000,3000564,3001250,3010560,3024000,3025260,3037500,3048192,3061800,3062500,3072000,3073280,3087000,3096576,3110400,3111696,3125000,3136000,3145728,3149280,3150000,3161088,3175200,3176523,3188646,3189375,3200000,3211264,3214890,3215625,3225600,3226944,3240000,3241350,3265920,3276800,3280500,3281250,3292800,3294172,3306744,3307500,3317760,3333960,3359232,3360000,3361400,3375000,3386880,3402000,3429216,3430000,3440640,3444525,3456000,3457440,3472875,3483648,3499200,3500000,3500658,3512320,3515625,3528000,3529470,3538944,3542940,3543750,3556224,3572100,3584000,3600000,3601500,3612672,3628800,3630312,3645000,3670016,3674160,3675000,3686400,3687936,3704400,3720087,3732480,3750000,3750705,3763200,3764768,3779136,3780000,3781575,3796875,3810240,3827250,3828125,3840000,3841600,3857868,3858750,3870720,3888000,3889620,3906250,3919104,3920000,3932160,3936600,3937500,3951360,3969000,3981312,4000000,4000752,4014080,4032000,4033680,4050000,4064256,4082400,4084101,4096000,4100625,4116000,4117715,4128768,4133430,4134375,4147200,4148928,4167450,4194304,4199040,4200000,4201750,4214784,4218750,4233600,4235364,4251528,4252500,4286520,4287500,4300800,4302592,4320000,4321800,4354560,4374000,4375000,4390400,4408992,4410000,4423680,4428675,4445280,4465125,4478976,4480000,4500000,4500846,4501875,4515840,4536000,4537890,4556250,4572288,4587520,4592700,4593750,4608000,4609920,4630500,4644864,4665600,4667544,4687500,4704000,4705960,4718592,4723920,4725000,4741632,4762800,4782969,4800000,4802000,4816896,4822335,4838400,4840416,4860000,4862025,4898880,4900000,4915200,4917248,4920750,4921875,4939200,4941258,4960116,4961250,4976640,5000000,5000940,5017600,5038848,5040000,5042100,5062500,5080320,5103000,5120000,5143824,5145000,5160960,5184000,5186160,5225472,5242880,5248800,5250000,5250987,5268480,5292000,5294205,5308416,5314410,5315625,5334336,5358150,5359375,5376000,5378240,5400000,5402250,5419008,5443200,5445468,5467500,5468750,5488000,5505024,5511240,5512500,5529600,5531904,5556600,5598720,5600000,5619712,5625000,5644800,5647152,5668704,5670000,5715360,5734400,5740875,5760000,5762400,5764801,5786802,5788125,5806080,5832000,5834430,5859375,5878656,5880000,5882450,5898240,5904900,5906250,5927040,5953500,5971968,6000000,6001128,6002500,6021120,6048000,6050520,6075000,6096384,6123600,6125000,6144000,6146560,6174000,6193152,6200145,6220800,6223392,6250000,6251175,6272000,6291456,6298560,6300000,6302625,6322176,6328125,6350400,6353046,6377292,6378750,6400000,6422528,6429780,6431250,6451200,6453888,6480000,6482700,6531840,6553600,6561000,6562500,6585600,6588344,6613488,6615000,6635520,6667920,6718464,6720000,6722800,6750000,6751269,6773760,6804000,6806835,6834375,6858432,6860000,6881280,6889050,6890625,6912000,6914880,6945750,6967296,6998400,7000000,7001316,7024640,7031250,7056000,7058940,7077888,7085880,7087500,7112448,7144200,7168000,7200000,7203000,7225344,7257600,7260624,7290000,7340032,7348320,7350000,7372800,7375872,7381125,7408800,7411887,7440174,7441875,7464960,7500000,7501410,7503125,7526400,7529536,7558272,7560000,7563150,7593750,7620480,7654500,7656250,7680000,7683200,7715736,7717500,7741440,7776000,7779240,7812500,7838208,7840000,7864320,7873200,7875000,7902720,7938000,7962624,7971615,8000000,8001504,8028160,8037225,8064000,8067360,8100000,8103375,8128512,8164800,8168202,8192000,8201250,8203125,8232000,8235430,8257536,8266860,8268750,8294400,8297856,8334900,8388608,8398080,8400000,8403500,8429568,8437500,8467200,8470728,8503056,8505000,8573040,8575000,8601600,8605184,8640000,8643600,8680203,8709120,8748000,8750000,8751645,8780800,8817984,8820000,8823675,8847360,8857350,8859375,8890560,8930250,8957952,8960000,9000000,9001692,9003750,9031680,9072000,9075780,9112500,9144576,9175040,9185400,9187500,9216000,9219840,9261000,9289728,9331200,9335088,9375000,9408000,9411920,9437184,9447840,9450000,9483264,9525600,9529569,9565938,9568125,9600000,9604000,9633792,9644670,9646875,9676800,9680832,9720000,9724050,9765625,9797760,9800000,9830400,9834496,9841500,9843750,9878400,9882516,9920232,9922500,9953280,10000000,10001880,10035200,10077696,10080000,10084200,10125000,10160640,10206000,10240000,10287648,10290000,10321920,10333575,10368000,10372320,10418625,10450944,10485760,10497600,10500000,10501974,10504375,10536960,10546875,10584000,10588410,10616832,10628820,10631250,10668672,10716300,10718750,10752000,10756480,10800000,10804500,10838016,10886400,10890936,10935000,10937500,10976000,11010048,11022480,11025000,11059200,11063808,11113200,11160261,11197440,11200000,11239424,11250000,11252115,11289600,11294304,11337408,11340000,11344725,11390625,11430720,11468800,11481750,11484375,11520000,11524800,11529602,11573604,11576250,11612160,11664000,11668860,11718750,11757312,11760000,11764900,11796480,11809800,11812500,11854080,11907000,11943936,12000000,12002256,12005000,12042240,12096000,12101040,12150000,12192768,12247200,12250000,12252303,12288000,12293120,12301875,12348000,12353145,12386304,12400290,12403125,12441600,12446784,12500000,12502350,12544000,12582912,12597120,12600000,12605250,12644352,12656250,12700800,12706092,12754584,12757500,12800000,12845056,12859560,12862500,12902400,12907776,12960000,12965400,13063680,13107200,13122000,13125000,13171200,13176688,13226976,13230000,13271040,13286025,13335840,13395375,13436928,13440000,13445600,13500000,13502538,13505625,13547520,13608000,13613670,13668750,13671875,13716864,13720000,13762560,13778100,13781250,13824000,13829760,13891500,13934592,13996800,14000000,14002632,14049280,14062500,14112000,14117880,14155776,14171760,14175000,14224896,14288400,14336000,14348907,14400000,14406000,14450688,14467005,14515200,14521248,14580000,14586075,14680064,14696640,14700000,14706125,14745600,14751744,14762250,14765625,14817600,14823774,14880348,14883750,14929920,15000000,15002820,15006250,15052800,15059072,15116544,15120000,15126300,15187500,15240960,15309000,15312500,15360000,15366400,15431472,15435000,15482880,15552000,15558480,15625000,15676416,15680000,15728640,15746400,15750000,15752961,15805440,15876000,15882615,15925248,15943230,15946875,16000000,16003008,16056320,16074450,16078125,16128000,16134720,16200000,16206750,16257024,16329600,16336404,16384000,16402500,16406250,16464000,16470860,16515072,16533720,16537500,16588800,16595712,16669800,16777216,16796160,16800000,16807000,16859136,16875000,16934400,16941456,17006112,17010000,17146080,17150000,17203200,17210368,17222625,17280000,17287200,17294403,17360406,17364375,17418240,17496000,17500000,17503290,17561600,17578125,17635968,17640000,17647350,17694720,17714700,17718750,17781120,17860500,17915904,17920000,18000000,18003384,18007500,18063360,18144000,18151560,18225000,18289152,18350080,18370800,18375000,18432000,18439680,18522000,18579456,18600435,18662400,18670176,18750000,18753525,18816000,18823840,18874368,18895680,18900000,18907875,18966528,18984375,19051200,19059138,19131876,19136250,19140625,19200000,19208000,19267584,19289340,19293750,19353600,19361664,19440000,19448100,19531250,19595520,19600000,19660800,19668992,19683000,19687500,19756800,19765032,19840464,19845000,19906560,20000000,20003760,20070400,20155392,20160000,20168400,20250000,20253807,20321280,20412000,20420505,20480000,20503125,20575296,20580000,20588575,20643840,20667150,20671875,20736000,20744640,20837250,20901888,20971520,20995200,21000000,21003948,21008750,21073920,21093750,21168000,21176820,21233664,21257640,21262500,21337344,21432600,21437500,21504000,21512960,21600000,21609000,21676032,21772800,21781872,21870000,21875000,21952000,22020096,22044960,22050000,22118400,22127616,22143375,22226400,22235661,22320522,22325625,22394880,22400000,22478848,22500000,22504230,22509375,22579200,22588608,22674816,22680000,22689450,22781250,22861440,22937600,22963500,22968750,23040000,23049600,23059204,23147208,23152500,23224320,23328000,23337720,23437500,23514624,23520000,23529800,23592960,23619600,23625000,23708160,23814000,23887872,23914845,24000000,24004512,24010000,24084480,24111675,24192000,24202080,24300000,24310125,24385536,24494400,24500000,24504606,24576000,24586240,24603750,24609375,24696000,24706290,24772608,24800580,24806250,24883200,24893568,25000000,25004700,25088000,25165824,25194240,25200000,25210500,25288704,25312500,25401600,25412184,25509168,25515000,25600000,25690112,25719120,25725000,25804800,25815552,25920000,25930800,26040609,26127360,26214400,26244000,26250000,26254935,26342400,26353376,26453952,26460000,26471025,26542080,26572050,26578125,26671680,26790750,26796875,26873856,26880000,26891200,27000000,27005076,27011250,27095040,27216000,27227340,27337500,27343750,27433728,27440000,27525120,27556200,27562500,27648000,27659520,27783000,27869184,27993600,28000000,28005264,28098560,28125000,28224000,28235760,28311552,28343520,28350000,28449792,28576800,28588707,28672000,28697814,28704375,28800000,28812000,28824005,28901376,28934010,28940625,29030400,29042496,29160000,29172150,29296875,29360128,29393280,29400000,29412250,29491200,29503488,29524500,29531250,29635200,29647548,29760696,29767500,29859840,30000000,30005640,30012500,30105600,30118144,30233088,30240000,30252600,30375000,30481920,30618000,30625000,30720000,30732800,30862944,30870000,30965760,31000725,31104000,31116960,31250000,31255875,31352832,31360000,31457280,31492800,31500000,31505922,31513125,31610880,31640625,31752000,31765230,31850496,31886460,31893750,32000000,32006016,32112640,32148900,32156250,32256000,32269440,32400000,32413500,32514048,32659200,32672808,32768000,32805000,32812500,32928000,32941720,33030144,33067440,33075000,33177600,33191424,33339600,33480783,33554432,33592320,33600000,33614000,33718272,33750000,33756345,33868800,33882912,34012224,34020000,34034175,34171875,34292160,34300000,34406400,34420736,34445250,34453125,34560000,34574400,34588806,34720812,34728750,34836480,34992000,35000000,35006580,35123200,35156250,35271936,35280000,35294700,35389440,35429400,35437500,35562240,35721000,35831808,35840000,36000000,36006768,36015000,36126720,36288000,36303120,36450000,36578304,36700160,36741600,36750000,36756909,36864000,36879360,36905625,37044000,37059435,37158912,37200870,37209375,37324800,37340352,37500000,37507050,37515625,37632000,37647680,37748736,37791360,37800000,37815750,37933056,37968750,38102400,38118276,38263752,38272500,38281250,38400000,38416000,38535168,38578680,38587500,38707200,38723328,38880000,38896200,39062500,39191040,39200000,39321600,39337984,39366000,39375000,39513600,39530064,39680928,39690000,39813120,39858075,40000000,40007520,40140800,40186125,40310784,40320000,40336800,40353607,40500000,40507614,40516875,40642560,40824000,40841010,40960000,41006250,41015625,41150592,41160000,41177150,41287680,41334300,41343750,41472000,41489280,41674500,41803776,41943040,41990400,42000000,42007896,42017500,42147840,42187500,42336000,42353640,42467328,42515280,42525000,42674688,42865200,42875000,43008000,43025920,43046721,43200000,43218000,43352064,43401015,43545600,43563744,43740000,43750000,43758225,43904000,44040192,44089920,44100000,44118375,44236800,44255232,44286750,44296875,44452800,44471322,44641044,44651250,44789760,44800000,44957696,45000000,45008460,45018750,45158400,45177216,45349632,45360000,45378900,45562500,45722880,45875200,45927000,45937500,46080000,46099200,46118408,46294416,46305000,46448640,46656000,46675440,46875000,47029248,47040000,47059600,47185920,47239200,47250000,47258883,47416320,47628000,47647845,47775744,47829690,47840625,48000000,48009024,48020000,48168960,48223350,48234375,48384000,48404160,48600000,48620250,48771072,48828125,48988800,49000000,49009212,49152000,49172480,49207500,49218750,49392000,49412580,49545216,49601160,49612500,49766400,49787136,50000000,50009400,50176000,50331648,50388480,50400000,50421000,50577408,50625000,50803200,50824368,51018336,51030000,51200000,51380224,51438240,51450000,51609600,51631104,51667875,51840000,51861600,51883209,52081218,52093125,52254720,52428800,52488000,52500000,52509870,52521875,52684800,52706752,52734375,52907904,52920000,52942050,53084160,53144100,53156250,53343360,53581500,53593750,53747712,53760000,53782400,54000000,54010152,54022500,54190080,54432000,54454680,54675000,54687500,54867456,54880000,55050240,55112400,55125000,55296000,55319040,55566000,55738368,55801305,55987200,56000000,56010528,56197120,56250000,56260575,56448000,56471520,56623104,56687040,56700000,56723625,56899584,56953125,57153600,57177414,57344000,57395628,57408750,57421875,57600000,57624000,57648010,57802752,57868020,57881250,58060800,58084992,58320000,58344300,58593750,58720256,58786560,58800000,58824500,58982400,59006976,59049000,59062500,59270400,59295096,59521392,59535000,59719680,60000000,60011280,60025000,60211200,60236288,60466176,60480000,60505200,60750000,60761421,60963840,61236000,61250000,61261515,61440000,61465600,61509375,61725888,61740000,61765725,61931520,62001450,62015625,62208000,62233920,62500000,62511750,62705664,62720000,62914560,62985600,63000000,63011844,63026250,63221760,63281250,63504000,63530460,63700992,63772920,63787500,64000000,64012032,64225280,64297800,64312500,64512000,64538880,64800000,64827000,65028096,65318400,65345616,65536000,65610000,65625000,65856000,65883440,66060288,66134880,66150000,66355200,66382848,66430125,66679200,66706983,66961566,66976875,67108864,67184640,67200000,67228000,67436544,67500000,67512690,67528125,67737600,67765824,68024448,68040000,68068350,68343750,68359375,68584320,68600000,68812800,68841472,68890500,68906250,69120000,69148800,69177612,69441624,69457500,69672960,69984000,70000000,70013160,70246400,70312500,70543872,70560000,70589400,70778880,70858800,70875000,71124480,71442000,71663616,71680000,71744535,72000000,72013536,72030000,72253440,72335025,72576000,72606240,72900000,72930375,73156608,73400320,73483200,73500000,73513818,73530625,73728000,73758720,73811250,73828125,74088000,74118870,74317824,74401740,74418750,74649600,74680704,75000000,75014100,75031250,75264000,75295360,75497472,75582720,75600000,75631500,75866112,75937500,76204800,76236552,76527504,76545000,76562500,76800000,76832000,77070336,77157360,77175000,77414400,77446656,77760000,77792400,78121827,78125000,78382080,78400000,78643200,78675968,78732000,78750000,78764805,79027200,79060128,79361856,79380000,79413075,79626240,79716150,79734375,80000000,80015040,80281600,80372250,80390625,80621568,80640000,80673600,80707214,81000000,81015228,81033750,81285120,81648000,81682020,81920000,82012500,82031250,82301184,82320000,82354300,82575360,82668600,82687500,82944000,82978560,83349000,83607552,83886080,83980800,84000000,84015792,84035000,84295680,84375000,84672000,84707280,84934656,85030560,85050000,85349376,85730400,85750000,85766121,86016000,86051840,86093442,86113125,86400000,86436000,86472015,86704128,86802030,86821875,87091200,87127488,87480000,87500000,87516450,87808000,87890625,88080384,88179840,88200000,88236750,88473600,88510464,88573500,88593750,88905600,88942644,89282088,89302500,89579520,89600000,89915392,90000000,90016920,90037500,90316800,90354432,90699264,90720000,90757800,91125000,91445760,91750400,91854000,91875000,92160000,92198400,92236816,92588832,92610000,92897280,93002175,93312000,93350880,93750000,93767625,94058496,94080000,94119200,94371840,94478400,94500000,94517766,94539375,94832640,94921875,95256000,95295690,95551488,95659380,95681250,95703125,96000000,96018048,96040000,96337920,96446700,96468750,96768000,96808320,97200000,97240500,97542144,97656250,97977600,98000000,98018424,98304000,98344960,98415000,98437500,98784000,98825160,99090432,99202320,99225000,99532800,99574272,100000000,100018800,100352000,100442349,100663296,100776960,100800000,100842000,101154816,101250000,101269035,101606400,101648736,102036672,102060000,102102525,102400000,102515625,102760448,102876480,102900000,102942875,103219200,103262208,103335750,103359375,103680000,103723200,103766418,104162436,104186250,104509440,104857600,104976000,105000000,105019740,105043750,105369600,105413504,105468750,105815808,105840000,105884100,106168320,106288200,106312500,106686720,107163000,107187500,107495424,107520000,107564800,108000000,108020304,108045000,108380160,108864000,108909360,109350000,109375000,109734912,109760000,110100480,110224800,110250000,110270727,110592000,110638080,110716875,111132000,111178305,111476736,111602610,111628125,111974400,112000000,112021056,112394240,112500000,112521150,112546875,112896000,112943040,113246208,113374080,113400000,113447250,113799168,113906250,114307200,114354828,114688000,114791256,114817500,114843750,115200000,115248000,115296020,115605504,115736040,115762500,116121600,116169984,116640000,116688600,117187500,117440512,117573120,117600000,117649000,117964800,118013952,118098000,118125000,118540800,118590192,119042784,119070000,119439360,119574225,120000000,120022560,120050000,120422400,120472576,120558375,120932352,120960000,121010400,121060821,121500000,121522842,121550625,121927680,122472000,122500000,122523030,122880000,122931200,123018750,123046875,123451776,123480000,123531450,123863040,124002900,124031250,124416000,124467840,125000000,125023500,125411328,125440000,125829120,125971200,126000000,126023688,126052500,126443520,126562500,127008000,127060920,127401984,127545840,127575000,128000000,128024064,128450560,128595600,128625000,129024000,129077760,129140163,129600000,129654000,130056192,130203045,130636800,130691232,131072000,131220000,131250000,131274675,131712000,131766880,132120576,132269760,132300000,132355125,132710400,132765696,132860250,132890625,133358400,133413966,133923132,133953750,133984375,134217728,134369280,134400000,134456000,134873088,135000000,135025380,135056250,135475200,135531648,136048896,136080000,136136700,136687500,136718750,137168640,137200000,137625600,137682944,137781000,137812500,138240000,138297600,138355224,138883248,138915000,139345920,139968000,140000000,140026320,140492800,140625000,141087744,141120000,141178800,141557760,141717600,141750000,141776649,142248960,142884000,142943535,143327232,143360000,143489070,143521875,144000000,144027072,144060000,144120025,144506880,144670050,144703125,145152000,145212480,145800000,145860750,146313216,146484375,146800640,146966400,147000000,147027636,147061250,147456000,147517440,147622500,147656250,148176000,148237740,148635648,148803480,148837500,149299200,149361408,150000000,150028200,150062500,150528000,150590720,150994944,151165440,151200000,151263000,151732224,151875000,152409600,152473104,153055008,153090000,153125000,153600000,153664000,154140672,154314720,154350000,154828800,154893312,155003625,155520000,155584800,155649627,156243654,156250000,156279375,156764160,156800000,157286400,157351936,157464000,157500000,157529610,157565625,158054400,158120256,158203125,158723712,158760000,158826150,159252480,159432300,159468750,160000000,160030080,160563200,160744500,160781250,161243136,161280000,161347200,161414428,162000000,162030456,162067500,162570240,163296000,163364040,163840000,164025000,164062500,164602368,164640000,164708600,165150720,165337200,165375000,165888000,165957120,166698000,167215104,167403915,167772160,167961600,168000000,168031584,168070000,168591360,168750000,168781725,169344000,169414560,169869312,170061120,170100000,170170875,170698752,170859375,171460800,171500000,171532242,172032000,172103680,172186884,172226250,172265625,172800000,172872000,172944030,173408256,173604060,173643750,174182400,174254976,174960000,175000000,175032900,175616000,175781250,176160768,176359680,176400000,176473500,176947200,177020928,177147000,177187500,177811200,177885288,178564176,178605000,179159040,179200000,179830784,180000000,180033840,180075000,180633600,180708864,181398528,181440000,181515600,182250000,182284263,182891520,183500800,183708000,183750000,183784545,184320000,184396800,184473632,184528125,185177664,185220000,185297175,185794560,186004350,186046875,186624000,186701760,187500000,187535250,187578125,188116992,188160000,188238400,188743680,188956800,189000000,189035532,189078750,189665280,189843750,190512000,190591380,191102976,191318760,191362500,191406250,192000000,192036096,192080000,192675840,192893400,192937500,193536000,193616640,194400000,194481000,195084288,195312500,195955200,196000000,196036848,196608000,196689920,196830000,196875000,197568000,197650320,198180864,198404640,198450000,199065600,199148544,199290375,200000000,200037600,200120949,200704000,200884698,200930625,201326592,201553920,201600000,201684000,201768035,202309632,202500000,202538070,202584375,203212800,203297472,204073344,204120000,204205050,204800000,205031250,205078125,205520896,205752960,205800000,205885750,206438400,206524416,206671500,206718750,207360000,207446400,207532836,208324872,208372500,209018880,209715200,209952000,210000000,210039480,210087500,210739200,210827008,210937500,211631616,211680000,211768200,212336640,212576400,212625000,213373440,214326000,214375000,214990848,215040000,215129600,215233605,216000000,216040608,216090000,216760320,217005075,217728000,217818720,218700000,218750000,218791125,219469824,219520000,220200960,220449600,220500000,220541454,220591875,221184000,221276160,221433750,221484375,222264000,222356610,222953472,223205220,223256250,223948800,224000000,224042112,224788480,225000000,225042300,225093750,225792000,225886080,226492416,226748160,226800000,226894500,227598336,227812500,228614400,228709656,229376000,229582512,229635000,229687500,230400000,230496000,230592040,231211008,231472080,231525000,232243200,232339968,233280000,233377200,234365481,234375000,234881024,235146240,235200000,235298000,235929600,236027904,236196000,236250000,236294415,237081600,237180384,238085568,238140000,238239225,238878720,239148450,239203125,240000000,240045120,240100000,240844800,240945152,241116750,241171875,241864704,241920000,242020800,242121642,243000000,243045684,243101250,243855360,244140625,244944000,245000000,245046060,245760000,245862400,246037500,246093750,246903552,246960000,247062900,247726080,248005800,248062500,248832000,248935680,250000000,250047000,250822656,250880000,251658240,251942400,252000000,252047376,252105000,252887040,253125000,254016000,254121840,254803968,255091680,255150000,256000000,256048128,256901120,257191200,257250000,257298363,258048000,258155520,258280326,258339375,259200000,259308000,259416045,260112384,260406090,260465625,261273600,261382464,262144000,262440000,262500000,262549350,262609375,263424000,263533760,263671875,264241152,264539520,264600000,264710250,265420800,265531392,265720500,265781250,266716800,266827932,267846264,267907500,267968750,268435456,268738560,268800000,268912000,269746176,270000000,270050760,270112500,270950400,271063296,272097792,272160000,272273400,273375000,273437500,274337280,274400000,275251200,275365888,275562000,275625000,276480000,276595200,276710448,277766496,277830000,278691840,279006525,279936000,280000000,280052640,280985600,281250000,281302875,282175488,282240000,282357600,282475249,283115520,283435200,283500000,283553298,283618125,284497920,284765625,285768000,285887070,286654464,286720000,286978140,287043750,287109375,288000000,288054144,288120000,288240050,289013760,289340100,289406250,290304000,290424960,291600000,291721500,292626432,292968750,293601280,293932800,294000000,294055272,294122500,294912000,295034880,295245000,295312500,296352000,296475480,297271296,297606960,297675000,298598400,298722816,300000000,300056400,300125000,301056000,301181440,301327047,301989888,302330880,302400000,302526000,303464448,303750000,303807105,304819200,304946208,306110016,306180000,306250000,306307575,307200000,307328000,307546875,308281344,308629440,308700000,308828625,309657600,309786624,310007250,310078125,311040000,311169600,311299254,312487308,312500000,312558750,313528320,313600000,314572800,314703872,314928000,315000000,315059220,315131250,316108800,316240512,316406250,317447424,317520000,317652300,318504960,318864600,318937500,320000000,320060160,321126400,321489000,321562500,322486272,322560000,322694400,322828856,324000000,324060912,324135000,325140480,326592000,326728080,327680000,328050000,328125000,329204736,329280000,329417200,330301440,330674400,330750000,330812181,331776000,331914240,332150625,333396000,333534915,334430208,334807830,334884375,335544320,335923200,336000000,336063168,336140000,337182720,337500000,337563450,337640625,338688000,338829120,339738624,340122240,340200000,340341750,341397504,341718750,341796875,342921600,343000000,343064484,344064000,344207360,344373768,344452500,344531250,345600000,345744000,345888060,346816512,347208120,347287500,348364800,348509952,349920000,350000000,350065800,351232000,351562500,352321536,352719360,352800000,352947000,353894400,354041856,354294000,354375000,355622400,355770576,357128352,357210000,358318080,358400000,358722675,359661568,360000000,360067680,360150000,361267200,361417728,361675125,362797056,362880000,363031200,363182463,364500000,364568526,364651875,365783040,367001600,367416000,367500000,367569090,367653125,368640000,368793600,368947264,369056250,369140625,370355328,370440000,370594350,371589120,372008700,372093750,373248000,373403520,375000000,375070500,375156250,376233984,376320000,376476800,377487360,377913600,378000000,378071064,378157500,379330560,379687500,381024000,381182760,382205952,382637520,382725000,382812500,384000000,384072192,384160000,385351680,385786800,385875000,387072000,387233280,387420489,388800000,388962000,390168576,390609135,390625000,391910400,392000000,392073696,393216000,393379840,393660000,393750000,393824025,395136000,395300640,396361728,396809280,396900000,397065375,398131200,398297088,398580750,398671875,400000000,400075200,400241898,401408000,401769396,401861250,401953125,402653184,403107840,403200000,403368000,403536070,404619264,405000000,405076140,405168750,406425600,406594944,408146688,408240000,408410100,409600000,410062500,410156250,411041792,411505920,411600000,411771500,412876800,413048832,413343000,413437500,414720000,414892800,415065672,416649744,416745000,418037760,419430400,419904000,420000000,420078960,420175000,421478400,421654016,421875000,423263232,423360000,423536400,424673280,425152800,425250000,425329947,426746880,428652000,428750000,428830605,429981696,430080000,430259200,430467210,430565625,432000000,432081216,432180000,432360075,433520640,434010150,434109375,435456000,435637440,437400000,437500000,437582250,438939648,439040000,439453125,440401920,440899200,441000000,441082908,441183750,442368000,442552320,442867500,442968750,444528000,444713220,445906944,446410440,446512500,447897600,448000000,448084224,449576960,450000000,450084600,450187500,451584000,451772160,452984832,453496320,453600000,453789000,455196672,455625000,457228800,457419312,458752000,459165024,459270000,459375000,460800000,460992000,461184080,462422016,462944160,463050000,464486400,464679936,465010875,466560000,466754400,466948881,468730962,468750000,468838125,469762048,470292480,470400000,470596000,471859200,472055808,472392000,472500000,472588830,472696875,474163200,474360768,474609375,476171136,476280000,476478450,477757440,478296900,478406250,478515625,480000000,480090240,480200000,481689600,481890304,482233500,482343750,483729408,483840000,484041600,484243284,486000000,486091368,486202500,487710720,488281250,489888000,490000000,490092120,491520000,491724800,492075000,492187500,493807104,493920000,494125800,495452160,496011600,496125000,497664000,497871360,500000000,500094000,501645312,501760000,502211745,503316480,503884800,504000000,504094752,504210000,505774080,506250000,506345175,508032000,508243680,509607936,510183360,510300000,510512625,512000000,512096256,512578125,513802240,514382400,514500000,514596726,514714375,516096000,516311040,516560652,516678750,516796875,518400000,518616000,518832090,520224768,520812180,520931250,522547200,522764928,524288000,524880000,525000000,525098700,525218750,526848000,527067520,527343750,528482304,529079040,529200000,529420500,530841600,531062784,531441000,531562500,533433600,533655864,535692528,535815000,535937500,536870912,537477120,537600000,537824000,539492352,540000000,540101520,540225000,541900800,542126592,544195584,544320000,544546800,546750000,546852789,546875000,548674560,548800000,550502400,550731776,551124000,551250000,551353635,552960000,553190400,553420896,553584375,555532992,555660000,555891525,557383680,558013050,558140625,559872000,560000000,560105280,561971200,562500000,562605750,562734375,564350976,564480000,564715200,564950498,566231040,566870400,567000000,567106596,567236250,568995840,569531250,571536000,571774140,573308928,573440000,573956280,574087500,574218750,576000000,576108288,576240000,576480100,578027520,578680200,578812500,580608000,580849920,583200000,583443000,585252864,585937500,587202560,587865600,588000000,588110544,588245000,589824000,590069760,590490000,590625000,592704000,592950960,594542592,595213920,595350000,597196800,597445632,597871125,600000000,600112800,600250000,600362847,602112000,602362880,602654094,602791875,603979776,604661760,604800000,605052000,605304105,606928896,607500000,607614210,607753125,609638400,609892416,612220032,612360000,612500000,612615150,614400000,614656000,615093750,615234375,616562688,617258880,617400000,617657250,619315200,619573248,620014500,620156250,622080000,622339200,622598508,624974616,625000000,625117500,627056640,627200000,629145600,629407744,629856000,630000000,630118440,630262500,632217600,632481024,632812500,634894848,635040000,635304600,637009920,637729200,637875000,640000000,640120320,642252800,642978000,643125000,644972544,645120000,645388800,645657712,645700815,648000000,648121824,648270000,650280960,651015225,653184000,653456160,655360000,656100000,656250000,656373375,658409472,658560000,658834400,660602880,661348800,661500000,661624362,661775625,663552000,663828480,664301250,664453125,666792000,667069830,668860416,669615660,669768750,669921875,671088640,671846400,672000000,672126336,672280000,674365440,675000000,675126900,675281250,677376000,677658240,679477248,680244480,680400000,680683500,682795008,683437500,683593750,685843200,686000000,686128968,688128000,688414720,688747536,688905000,689062500,691200000,691488000,691776120,693633024,694416240,694575000,696729600,697019904,699840000,700000000,700131600,702464000,703096443,703125000,704643072,705438720,705600000,705894000,707788800,708083712,708588000,708750000,708883245,711244800,711541152,714256704,714420000,714717675,716636160,716800000,717445350,717609375,719323136,720000000,720135360,720300000,720600125,722534400,722835456,723350250,723515625,725594112,725760000,726062400,726364926,729000000,729137052,729303750,731566080,732421875,734003200,734832000,735000000,735138180,735306250,737280000,737587200,737894528,738112500,738281250,740710656,740880000,741188700,743178240,744017400,744187500,746496000,746807040,750000000,750141000,750312500,752467968,752640000,752953600,754974720,755827200,756000000,756142128,756315000,758661120,759375000,762048000,762365520,764411904,765275040,765450000,765625000,768000000,768144384,768320000,770703360,771573600,771750000,771895089,774144000,774466560,774840978,775018125,777600000,777924000,778248135,780337152,781218270,781250000,781396875,783820800,784000000,784147392,786432000,786759680,787320000,787500000,787648050,787828125,790272000,790601280,791015625,792723456,793618560,793800000,794130750,796262400,796594176,797161500,797343750,800000000,800150400,800483796,802816000,803538792,803722500,803906250,805306368,806215680,806400000,806736000,807072140,809238528,810000000,810152280,810337500,812851200,813189888,816293376,816480000,816820200,819200000,820125000,820312500,822083584,823011840,823200000,823543000,825753600,826097664,826686000,826875000,829440000,829785600,830131344,833299488,833490000,836075520,837019575,838860800,839808000,840000000,840157920,840350000,842956800,843308032,843750000,843908625,846526464,846720000,847072800,847425747,849346560,850305600,850500000,850659894,850854375,853493760,854296875,857304000,857500000,857661210,859963392,860160000,860518400,860934420,861131250,861328125,864000000,864162432,864360000,864720150,867041280,868020300,868218750,870912000,871274880,874800000,875000000,875164500,877879296,878080000,878906250,880803840,881798400,882000000,882165816,882367500,884736000,885104640,885735000,885937500,889056000,889426440,891813888,892820880,893025000,895795200,896000000,896168448,899153920,900000000,900169200,900375000,903168000,903544320,903981141,905969664,906992640,907200000,907578000,910393344,911250000,911421315,914457600,914838624,917504000,918330048,918540000,918750000,918922725,921600000,921984000,922368160,922640625,924844032,925888320,926100000,926485875,928972800,929359872,930021750,930234375,933120000,933508800,933897762,937461924,937500000,937676250,937890625,939524096,940584960,940800000,941192000,943718400,944111616,944784000,945000000,945177660,945393750,948326400,948721536,949218750,952342272,952560000,952956900,955514880,956593800,956812500,957031250,960000000,960180480,960400000,963379200,963780608,964467000,964687500,967458816,967680000,968083200,968486568,972000000,972182736,972405000,975421440,976562500,979776000,980000000,980184240,983040000,983449600,984150000,984375000,987614208,987840000,988251600,990904320,992023200,992250000,992436543,995328000,995742720,996451875,1000000000,1000188000,1000604745,1003290624,1003520000,1004423490,1004653125,1006632960,1007769600,1008000000,1008189504,1008420000,1008840175,1011548160,1012500000,1012690350,1012921875,1016064000,1016487360,1019215872,1020366720,1020600000,1021025250,1024000000,1024192512,1025156250,1025390625,1027604480,1028764800,1029000000,1029193452,1029428750,1032192000,1032622080,1033121304,1033357500,1033593750,1036800000,1037232000,1037664180,1040449536,1041624360,1041862500,1045094400,1045529856,1048576000,1049760000,1050000000,1050197400,1050437500,1053696000,1054135040,1054687500,1056964608,1058158080,1058400000,1058841000,1061683200,1062125568,1062882000,1063125000,1066867200,1067311728,1071385056,1071630000,1071875000,1073741824,1074954240,1075200000,1075648000,1076168025,1078984704,1080000000,1080203040,1080450000,1083801600,1084253184,1085025375,1088391168,1088640000,1089093600,1089547389,1093500000,1093705578,1093750000,1093955625,1097349120,1097600000,1101004800,1101463552,1102248000,1102500000,1102707270,1102959375,1105920000,1106380800,1106841792,1107168750,1107421875,1111065984,1111320000,1111783050,1114767360,1116026100,1116281250,1119744000,1120000000,1120210560,1123942400,1125000000,1125211500,1125468750,1128701952,1128960000,1129430400,1129900996,1132462080,1133740800,1134000000,1134213192,1134472500,1137991680,1139062500,1143072000,1143548280,1146617856,1146880000,1147912560,1148175000,1148437500,1152000000,1152216576,1152480000,1152960200,1156055040,1157360400,1157625000,1161216000,1161699840,1162261467,1166400000,1166886000,1170505728,1171827405,1171875000,1174405120,1175731200,1176000000,1176221088,1176490000,1179648000,1180139520,1180980000,1181250000,1181472075,1185408000,1185901920,1189085184,1190427840,1190700000,1191196125,1194393600,1194891264,1195742250,1196015625,1200000000,1200225600,1200500000,1200725694,1204224000,1204725760,1205308188,1205583750,1205859375,1207959552,1209323520,1209600000,1210104000,1210608210,1213857792,1215000000,1215228420,1215506250,1219276800,1219784832,1220703125,1224440064,1224720000,1225000000,1225230300,1228800000,1229312000,1230187500,1230468750,1233125376,1234517760,1234800000,1235314500,1238630400,1239146496,1240029000,1240312500,1244160000,1244678400,1245197016,1249949232,1250000000,1250235000,1254113280,1254400000,1258291200,1258815488,1259712000,1260000000,1260236880,1260525000,1264435200,1264962048,1265625000,1269789696,1270080000,1270609200,1274019840,1275458400,1275750000,1275989841,1280000000,1280240640,1284505600,1285956000,1286250000,1286491815,1289945088,1290240000,1290777600,1291315424,1291401630,1291696875,1296000000,1296243648,1296540000,1297080225,1300561920,1302030450,1302328125,1306368000,1306912320,1310720000,1312200000,1312500000,1312746750,1313046875,1316818944,1317120000,1317668800,1318359375,1321205760,1322697600,1323000000,1323248724,1323551250,1327104000,1327656960,1328602500,1328906250,1333584000,1334139660,1337720832,1339231320,1339537500,1339843750,1342177280,1343692800,1344000000,1344252672,1344560000,1348730880,1350000000,1350253800,1350562500,1354752000,1355316480,1358954496,1360488960,1360800000,1361367000,1365590016,1366875000,1367187500,1371686400,1372000000,1372257936,1376256000,1376829440,1377495072,1377810000,1378125000,1382400000,1382976000,1383552240,1387266048,1388832480,1389150000,1393459200,1394039808,1395032625,1399680000,1400000000,1400263200,1400846643,1404928000,1406192886,1406250000,1406514375,1409286144,1410877440,1411200000,1411788000,1412376245,1415577600,1416167424,1417176000,1417500000,1417766490,1418090625,1422489600,1423082304,1423828125,1428513408,1428840000,1429435350,1433272320,1433600000,1434890700,1435218750,1435546875,1438646272,1440000000,1440270720,1440600000,1441200250,1445068800,1445670912,1446700500,1447031250,1451188224,1451520000,1452124800,1452729852,1458000000,1458274104,1458607500,1463132160,1464843750,1468006400,1469664000,1470000000,1470276360,1470612500,1474560000,1475174400,1475789056,1476225000,1476562500,1481421312,1481760000,1482377400,1486356480,1488034800,1488375000,1492992000,1493614080,1500000000,1500282000,1500625000,1504935936,1505280000,1505907200,1506635235,1509949440,1511654400,1512000000,1512284256,1512630000,1517322240,1518750000,1519035525,1524096000,1524731040,1528823808,1530550080,1530900000,1531250000,1531537875,1536000000,1536288768,1536640000,1537734375,1541406720,1543147200,1543500000,1543790178,1544143125,1548288000,1548933120,1549681956,1550036250,1550390625,1555200000,1555848000,1556496270,1560674304,1562436540,1562500000,1562793750,1567641600,1568000000,1568294784,1572864000,1573519360,1574640000,1575000000,1575296100,1575656250,1580544000,1581202560,1582031250,1585446912,1587237120,1587600000,1588261500,1592524800,1593188352,1594323000,1594687500,1600000000,1600300800,1600967592,1605632000,1607077584,1607445000,1607812500,1610612736,1612431360,1612800000,1613472000,1614144280,1618477056,1620000000,1620304560,1620675000,1625702400,1626379776,1632586752,1632960000,1633640400,1638400000,1640250000,1640558367,1640625000,1644167168,1646023680,1646400000,1647086000,1651507200,1652195328,1653372000,1653750000,1654060905,1658880000,1659571200,1660262688,1660753125,1666598976,1666980000,1667674575,1672151040,1674039150,1674421875,1677721600,1679616000,1680000000,1680315840,1680700000,1685913600,1686616064,1687500000,1687817250,1688203125,1693052928,1693440000,1694145600,1694851494,1698693120,1700611200,1701000000,1701319788,1701708750,1706987520,1708593750,1708984375,1714608000,1715000000,1715322420,1719926784,1720320000,1721036800,1721868840,1722262500,1722656250,1728000000,1728324864,1728720000,1729440300,1734082560,1736040600,1736437500,1741824000,1742549760,1749600000,1750000000,1750329000,1755758592,1756160000,1757812500,1761607680,1763596800,1764000000,1764331632,1764735000,1769472000,1770209280,1771470000,1771875000,1778112000,1778852880,1783627776,1785641760,1786050000,1791590400,1792000000,1792336896,1793613375,1798307840,1800000000,1800338400,1800750000,1801088541,1806336000,1807088640,1807962282,1808375625,1811939328,1813985280,1814400000,1815156000,1815912315,1820786688,1822500000,1822842630,1823259375,1828915200,1829677248,1835008000,1836660096,1837080000,1837500000,1837845450,1838265625,1843200000,1843968000,1844736320,1845281250,1845703125,1849688064,1851776640,1852200000,1852971750,1857945600,1858719744,1860043500,1860468750,1866240000,1867017600,1867795524,1874923848,1875000000,1875352500,1875781250,1879048192,1881169920,1881600000,1882384000,1887436800,1888223232,1889568000,1890000000,1890355320,1890787500,1896652800,1897443072,1898437500,1904684544,1905120000,1905913800,1911029760,1913187600,1913625000,1914062500,1920000000,1920360960,1920800000,1926758400,1927561216,1928934000,1929375000,1934917632,1935360000,1936166400,1936973136,1937102445,1944000000,1944365472,1944810000,1950842880,1953045675,1953125000,1959552000,1960000000,1960368480,1966080000,1966899200,1968300000,1968750000,1969120125,1975228416,1975680000,1976503200,1977326743,1981808640,1984046400,1984500000,1984873086,1985326875,1990656000,1991485440,1992903750,1993359375,2000000000 };
//	while (scanf("%d", &n) != EOF && n)
//	{
//		if (n % 10 == 1 && n % 100 != 11)
//			printf("The %dst humble number is %lld.\n", n, ar[n-1]);
//		else if (n % 10 == 2 && n % 100 != 12)
//			printf("The %dnd humble number is %lld.\n", n, ar[n-1]);
//		else if (n % 10 == 3 && n % 100 != 13)
//			printf("The %drd humble number is %lld.\n", n, ar[n-1]);
//		else
//		{
//			printf("The %dth humble number is %lld.\n", n, ar[n-1]);
//		}
//	}
//	return 0;
//}









//1892  树状数组第4题；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <cmath>
//using namespace std;
//const int MAX = 100000000;
//int main()
//{
//	int i, j, k, n, m, a, b, c, p, q, ar[1010][1010], sa[1010][1010], cas, sum, doudou, x1, x2, y1, y2, temp;
//	char s[5];
//	while (scanf("%d", &n) != EOF)
//	{
//		cas = 1;
//		for (m = 1; m <= n; m++)
//		{
//			doudou = 0;
//			scanf("%d", &p);
//			memset(ar, 0, sizeof(ar));
//			memset(sa, 0, sizeof(sa));
//			for (i = 1; i <= 1005; i++)
//			{
//				for (j = 1; j <= 1005; j++)
//				{
//					ar[i][j] = 1;
//					for (a = i; a <= 1005; a += (a & (-a)))
//					{
//						for (b = j; b <= 1005; b += (b & (-b)))
//						{
//							sa[a][b] += 1;
//						}
//					}
//				}
//			}
//			for (q = 1; q <= p; q++)
//			{
//				scanf("%s", s);
//				if (!strcmp(s, "S"))
//				{
//					sum = 0;
//					scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
//					x1++;
//					y1++;
//					x2++;
//					y2++;
//					if (x1 > x2)
//					{
//						temp = x1;
//						x1 = x2;
//						x2 = temp;
//					}
//					if (y1 > y2)
//					{
//						temp = y1;
//						y1 = y2;
//						y2 = temp;
//					}
//					for (i = x2; i > 0; i -= (i & (-i)))
//					{
//						for (j = y2; j > 0; j -= (j & (-j)))
//						{
//							sum += sa[i][j];
//						}
//					}
//					for (i = x1 - 1; i > 0; i -= (i & (-i)))
//					{
//						for (j = y2; j > 0; j -= (j & (-j)))
//						{
//							sum -= sa[i][j];
//						}
//					}
//					for (i = x2; i > 0; i -= (i & (-i)))
//					{
//						for (j = y1 - 1; j > 0; j -= (j & (-j)))
//						{
//							sum -= sa[i][j];
//						}
//					}
//					for (i = x1 - 1; i > 0; i -= (i & (-i)))
//					{
//						for (j = y1 - 1; j > 0; j -= (j & (-j)))
//						{
//							sum += sa[i][j];
//						}
//					}
//					if (!doudou)
//						printf("Case %d:\n", cas++);
//					doudou = 1;
//					printf("%d\n", sum);
//				}
//				else if (!strcmp(s, "A"))
//				{
//					scanf("%d %d %d", &x1, &y1, &c);
//					x1++;
//					y1++;
//					for (i = x1; i <= 1005; i += (i & (-i)))
//					{
//						for (j = y1; j <= 1005; j += (j & (-j)))
//						{
//							sa[i][j] += c;
//						}
//					}
//					ar[x1][y1] += c;
//				}
//				else if (!strcmp(s, "D"))
//				{
//					scanf("%d %d %d", &x1, &y1, &c);
//					x1++;
//					y1++;
//					if (c >= ar[x1][y1])
//						c = ar[x1][y1];
//					for (i = x1; i <= 1005; i += (i & (-i)))
//					{
//						for (j = y1; j <= 1005; j += (j & (-j)))
//						{
//							sa[i][j] -= c;
//						}
//					}
//					ar[x1][y1] -= c;
//				}
//				else if (!strcmp(s, "M"))
//				{
//					scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &c);
//					x1++;
//					y1++;
//					x2++;
//					y2++;
//					if (c >= ar[x1][y1])
//						c = ar[x1][y1];
//					for (i = x1; i <= 1005; i += (i & (-i)))
//					{
//						for (j = y1; j <= 1005; j += (j & (-j)))
//						{
//							sa[i][j] -= c;
//						}
//					}
//					for (i = x2; i <= 1005; i += (i & (-i)))
//					{
//						for (j = y2; j <= 1005; j += (j & (-j)))
//						{
//							sa[i][j] += c;
//						}
//					}
//					ar[x1][y1] -= c;
//					ar[x2][y2] += c;
//				}
//			}
//		}
//	}
//	return 0;
//}








//1541  树状数组第5题；
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//const int MAN = 100000000;
//int main()
//{
//	int i, j, k, n, m, u, a, b;
//	int ar[32010], sa[32010], sum;
//	while (scanf("%d", &n) != EOF)
//	{
//		memset(ar, 0, sizeof(ar));
//		memset(sa, 0, sizeof(sa));
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d", &a, &b);
//			a++;
//			k = a;
//			sum = 0;
//			while (k)
//			{
//				sum += ar[k];
//				k -= k & -k;
//			}
//			sa[sum]++;
//			k = a;
//			while (k <= 32000)
//			{
//				ar[k] += 1;
//				k += k & -k;
//			}
//		}
//		for (i = 0; i < n; i++)
//		{
//			printf("%d\n", sa[i]);
//		}
//	}
//	return 0;
//}










//1159 最长公共子列；
//#include <cstdio>
//#include <cstring>
//#include <string>
//#include <cctype>
//using namespace std;
//int main()
//{
//	int i, j, k, u, n, m, max, L1, L2;
//	char s1[1000], s2[1000];
//	int ar[1000][1000];
//	while (scanf("%s %s", s1+1, s2+1) != EOF)
//	{
//		L1 = strlen(s1+1);
//		L2 = strlen(s2+1);
//		for (i = 0; i <= L1; i++)
//		{
//			for (j = 0; j <= L2; j++)
//			{
//				if (i == 0 || j == 0)
//				{
//					ar[i][j] = 0;
//					continue;
//				}
//				if (s1[i] != s2[j])
//				{
//					ar[i][j] = (ar[i - 1][j] > ar[i][j - 1]) ? ar[i - 1][j] : ar[i][j - 1];
//				}
//				if (s1[i] == s2[j])
//					ar[i][j] = ar[i - 1][j - 1] + 1;
//			}
//		}
//		printf("%d\n", ar[L1][L2]);
//	}
//	return 0;
//}
//最长公共上升子列；
//#include <cstdio>
//#include <cstring>
//using namespace std;
//int main()
//{
//	int i, j, k, n, m, max, L1, L2;
//	char ar[100];
//	char a[100], b[100];
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%s %s", a + 1, b + 1);
//			L1 = strlen(a + 1);
//			L2 = strlen(b + 1);
//			memset(ar, 0, sizeof(ar));
//			for (i = 1; i <= L1; i++)
//			{
//				max = 0;
//				for (j = 1; j <= L2; j++)
//				{
//					if (a[i] > b[j] && max < ar[j])
//						max = ar[j];
//					if (a[i] == b[j])
//						ar[j] = max + 1;
//				}
//			}
//			max = 0;
//			for (i = 1; i <= L2; i++)
//				if (max < ar[i])
//					max = ar[i];
//			printf("%d\n", max);
//		}
//	}
//	return 0;
//}









//3555 数位dp第一题；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//#include <cctype>
//#include <cmath>
//using namespace std;
//typedef long long ll;
//ll dp[30][2][2];
//ll ar[30];
//int cnt;
//ll dfs(int pos, int pre, int limit, int sta);
//int main()
//{
//	int i, j, u, n, m, count, a, b, c;
//	ll k, t;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%lld", &k);
//			t = k;
//			memset(dp, -1, sizeof(dp));
//			cnt = 0;
//			count = 0;
//			while (k)
//			{
//				ar[count++] = k % 10;
//				k /= 10;
//			}
//			printf("%lld\n", t - dfs(count - 1, -1, 1, 0) + 1);
//		}
//	}
//	return 0;
//}
//ll dfs(int pos, int pre, int limit, int sta)
//{
//	int i, j, k, max;
//	ll res = 0;
//	if (pos == -1)
//		return 1;
//	if (dp[pos][limit][sta] != -1)
//		return dp[pos][limit][sta];
//	if (limit)
//	{
//		for (i = 0; i <= ar[pos]; i++)
//		{
//			if (pre == 4 && i == 9)
//				continue;
//			res += dfs(pos - 1, i, limit && (i == ar[pos]), i == 4);
//		}
//		dp[pos][1][sta] = res;
//		return res;
//	}
//	else
//	{
//		for (i = 0; i <= 9; i++)
//		{
//			if (pre == 4 && i == 9)
//				continue;
//			res += dfs(pos - 1, i, 0, i == 4);
//		}
//		dp[pos][0][sta] = res;
//		return res;
//	}
//}







//3652   数位dp第二题    最好不要用dp+limit          (mod* 10 + i)%13这个是求最终数能否被某某整除的必备技能；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//#include <cctype>
//#include <cmath>
//using namespace std;
//typedef long long ll;
//ll dp[20][2][2][2][20];
//int ar[20];
//ll dfs(int pos, int pre, int limit, int sta1, int stam, int mod);
//int main()
//{
//	int i, j, u, count;
//	ll n, m, k, t;
//	while (scanf("%lld", &n) != EOF)
//	{
//		memset(dp, -1, sizeof(dp));
//		t = n;
//		count = -1;
//		while (t)
//		{
//			ar[++count] = t % 10;
//			t /= 10;
//		}
//		printf("%lld\n", dfs(count, -1, 1, 0, 0, 0));
//	}
//	return 0;
//}
//ll dfs(int pos, int pre, int limit, int sta1, int stam, int mod)
//{
//	int i, j, k, u, t;
//	ll res = 0;
//	if (pos == -1)
//		return (stam && mod == 0);
//	if (dp[pos][limit][sta1][stam][mod] != -1)
//		return dp[pos][limit][sta1][stam][mod];
//	if (limit)
//	{
//		for (i = 0; i <= ar[pos]; i++)
//		{
//			t = (mod* 10 + i)%13;
//			res += dfs(pos - 1, i, limit && (i == ar[pos]), i == 1, stam || (pre == 1 && i == 3), t);
//		}
//		dp[pos][1][sta1][stam][mod] = res;
//		return res;
//	}
//	else
//	{
//		for (i = 0; i <= 9; i++)
//		{
//			t = (mod * 10 + i)%13;
//			res += dfs(pos - 1, i, 0, i == 1, stam || (pre == 1 && i == 3), t);
//		}
//		dp[pos][0][sta1][stam][mod] = res;
//		return res;
//	}
//}









//3709    数位dp第3题；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <cmath>
//#include <cctype>
//#include <algorithm>
//using namespace std;
//typedef __int64 ll;
//ll dp[20][20][3005];
//int ar[20];
//ll solve(ll n);
//ll dfs(int pos, int limit, int stand, int L);
//int main()
//{
//	int i, j, u, max, a, b, c;
//	ll n, m, k, s, res;
//	memset(dp, -1, sizeof(dp));
//	while (scanf("%d", &a) != EOF)
//	{
//		for (b = 1; b <= a; b++)
//		{
//			scanf("%I64d %I64d", &n, &m);
//			if (n == 0)
//			{
//				printf("%I64d\n", solve(m));
//				continue;
//			}
//			printf("%I64d %I64d\n", solve(n - 1), solve(m));
//			printf("%I64d\n", solve(m) - solve(n-1));
//		}
//	}
//	return 0;
//}
//ll solve(ll n)
//{
//	int i, j, count = 0;
//	ll res = 0;
//	memset(ar, 0, sizeof(ar));
//	while (n)
//	{
//		ar[count++] = n % 10;
//		printf("%I64d\n", n % 10);
//		n /= 10;
//	}
//	for (i = 0; i < count; i++)
//	{
//		res += dfs(count - 1, 1, i, 0);
//	}
//	return (res - count + 1);
//}
//ll dfs(int pos, int limit, int stand, int L)
//{
//	int i, j, k, u, max;
//	ll res = 0;
//	if (pos == -1)
//		return (L == 0);
//	if (L < 0)
//		return 0;
//	if (!limit && dp[pos][stand][L] != -1)
//		return dp[pos][stand][L];
//	max = (limit) ? ar[pos] : 9;
//	for (i = 0; i <= max; i++)
//	{
//		res += dfs(pos - 1, limit && i == ar[pos], stand, L + i*(pos - stand));
//	}
//	if (!limit)
//		dp[pos][stand][L] = res;
//	return res;
//}
//
//








//3886   数位dp第四题    能往后退就往后退，不满足了就看上一个能否满足，满足这一个就挂着，最后比较是不是到最后一个+1了；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <cmath>
//#include <cctype>
//#include <algorithm>
//using namespace std;
//typedef long long ll;
//const int Mod = 100000000;
//ll dp[110][10][110];
//char a[110], b[110], c[110];
//int ar[110];
//int Len;
//bool check(int pre, int cur, char s);
//ll dfs(int pos, int pre, int limit, int p, int first);
//ll solve(char *s, bool d);
//int main()
//{
//	int i, j, u;
//	ll n, m, k, res;
//	while (scanf("%s", c) != EOF)
//	{
//		memset(dp, -1, sizeof(dp));
//		Len = strlen(c);
//		scanf("%s %s", a, b);
//		printf("%08lld\n", (solve(b, false) - solve(a, true) + Mod) % Mod);
//	}
//	return 0;
//}
//ll solve(char *s, bool d)
//{
//	int L, i, j, u, count = 0;
//	L = strlen(s);
//	i = 0;
//	while (s[i] == '0')
//		i++;
//	for (j = L - 1; j >= i; j--)
//		ar[count++] = s[j] - '0';
//	if (d)
//	{
//		for (i = 0; i < count; i++)
//		{
//			if (ar[i])
//			{
//				ar[i]--;
//				break;
//			}
//			else
//				ar[i] = 9;
//		}
//		if (i == count - 1 && ar[i] == 0)
//			count--;
//	}
//	return dfs(count - 1, -1, 1, 0, 1);
//}
//ll dfs(int pos, int pre, int limit, int p, int first)
//{
//	int i, j, u, max;
//	ll res = 0;
//	if (pos == -1)
//		return p == Len;
//	if (!limit && dp[pos][pre][p] != -1)
//		return dp[pos][pre][p];
//	max = limit ? ar[pos] : 9;
//	for (i = 0; i <= max; i++)
//	{
//		if (first)
//		{
//			res = (res + dfs(pos - 1, i, limit && i == ar[pos], p, first && i == 0)) % Mod;
//		}
//		else if (p < Len && check(pre, i, c[p]))
//		{
//			res = (res + dfs(pos - 1, i, limit && i == ar[pos], p + 1, first && i == 0)) % Mod;
//		}
//		else if (p > 0 && check(pre, i, c[p - 1]))
//		{
//			res = (res + dfs(pos - 1, i, limit && i == ar[pos], p, first && i == 0)) % Mod;
//		}
//	}
//	if (!limit)
//		dp[pos][pre][p] = res;
//	return res;
//}
//bool check(int pre, int cur, char s)
//{
//	if (s == '/')
//		return pre < cur;
//	if (s == '\\')
//		return pre > cur;
//	if (s == '-')
//		return pre == cur;
//}








//4507    数位dp第五题    不仅记录个数，还要求平方和，需要count，sum， square三个同时记录， cur.square = （next.count * i² + 2 * next.sum * i + next.square）；
//如果求和，就是next.count * i + next.sum;
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <cmath>
//#include <cctype>
//#include <algorithm>
//using namespace std;
//typedef long long ll;
//const int Mod = 1000000007;
//struct node
//{
//	ll count;
//	ll sum;
//	ll square;
//	ll visit;
//	node() {}
//	node(ll c, ll s, ll sq, ll v) : count(c), sum(s), square(sq), visit(v) {}
//};
//node dp[20][8][8];
//ll Pow[20];
//int ar[20];
//ll solve(ll n);
//node dfs(int pos, int limit, int sta1, int sta2);
//int main()
//{
//	int i, j, u, count, k;
//	ll n, m, res;
//	Pow[0] = 1;
//	for (i = 1; i < 20; i++)
//		Pow[i] = Pow[i - 1] * 10;
//	memset(dp, -1, sizeof(dp));
//	while (scanf("%d", &k) != EOF)
//	{
//		for (u = 1; u <= k; u++)
//		{
//			scanf("%lld %lld", &n, &m);
//			printf("%lld\n", ((solve(m) - solve(n - 1)) % Mod + Mod) % Mod);
//		}
//	}
//	return 0;
//}
//ll solve(ll n)
//{
//	int count = 0, i, j;
//	memset(ar, 0, sizeof(ar));
//	while (n)
//	{
//		ar[++count] = n % 10;
//		n /= 10;
//	}
//	return dfs(count, 1, 0, 0).square;
//}
//node dfs(int pos, int limit, int sta1, int sta2)
//{
//	int i, j, u, max;
//	node res(0, 0, 0, 0);
//	node next;
//	if (pos == 0)
//		return (sta1 && sta2) ? node(1, 0, 0, 0) : node(0, 0, 0, 0);
//	if (!limit && dp[pos][sta1][sta2].visit != -1)
//		return dp[pos][sta1][sta2];
//	max = limit ? ar[pos] : 9;
//	for (i = 0; i <= max; i++)
//	{
//		if (i == 7)
//			continue;
//		next = dfs(pos - 1, limit && i == ar[pos], (i + sta1) % 7, (i + 10 * sta2) % 7);
//		ll temp = (i * Pow[pos - 1]) % Mod;
//		res.count = (res.count + next.count) % Mod;
//		res.sum = (res.sum + (next.sum + next.count * temp) % Mod) % Mod;
//		res.square = (res.square + ((next.count*temp%Mod*temp%Mod + 2 *temp*next.sum%Mod) % Mod + next.square) % Mod) % Mod;
//	}
//	if (!limit)
//	{
//		res.visit = 1;
//		dp[pos][sta1][sta2] = res;
//	}
//	return res;
//}
//







//4734   数位dp第六题    能从上限往下限算，就不从下限往上限算，因为从上往下dp数组可以共用（每一个下限都是相同的0）；
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <algorithm>
//#include <cctype>
//#include <cmath>
//using namespace std;
//typedef long long ll;
//ll dp[11][5000];
//int ar[11];
//ll Pow[13];
//ll RES;
//ll dfs(int pos, int limit, int sta);
//int main()
//{
//	int i, j, u, a, b, cas, count;
//	ll n, m, k;
//	Pow[1] = 1;
//	for (i = 2; i < 13; i++)
//	{
//		Pow[i] = Pow[i - 1] * 2;
//	}
//	memset(dp, -1, sizeof(dp));
//	while (scanf("%d", &a) != EOF)
//	{
//		cas = 1;
//		for (b = 1; b <= a; b++)
//		{
//			scanf("%lld %lld", &n, &m);
//			RES = 0;
//			i = 1;
//			while (n)
//			{
//				RES += (n % 10) * Pow[i++];
//				n /= 10;
//			}
//			count = 0;
//			while (m)
//			{
//				ar[++count] = m % 10;
//				m /= 10;
//			}
//			printf("Case #%d: %lld\n", cas++, dfs(count, 1, RES));
//		}
//	}
//	return 0;
//}
//ll dfs(int pos, int limit, int sta)
//{
//	int i, j, k, max, temp;
//	ll res = 0;
//	if (pos == 0)
//		return sta >= 0;
//	if (!limit && dp[pos][sta] != -1)
//		return dp[pos][sta];
//	max = limit ? ar[pos] : 9;
//	for (i = 0; i <= max; i++)
//	{
//		temp = sta - i * Pow[pos];
//		if (temp < 0)
//			continue;
//		res += dfs(pos - 1, limit && i == ar[pos], temp);
//	}
//	if (!limit)
//		dp[pos][sta] = res;
//	return res;
//}









//5179  数位dp第七题     每个数位上的数地位不平等，需要dp数组有pre；
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <algorithm>
//#include <cctype>
//#include <cmath>
//using namespace std;
//typedef long long ll;
//const int MAX = 11;
//ll dp[11][11];
//int ar[11];
//int Count;
//ll dfs(int pos, int pre, int limit, int first);
//ll solve(ll n);
//int main()
//{
//	int i, j, u, max, a, b;
//	ll n, m, k, res;
//	memset(dp, -1, sizeof(dp));
//	while (scanf("%d", &a) != EOF)
//	{
//		for (b = 1; b <= a; b++)
//		{
//			scanf("%lld %lld", &n, &m);
//			//printf("%lld %lld\n", solve(m), solve(n - 1));
//			printf("%lld\n", solve(m) - solve(n - 1));
//		}
//	}
//	return 0;
//}
//ll solve(ll n)
//{
//	int i, j;
//	Count = 0;
//	while (n)
//	{
//		ar[++Count] = n % 10;
//		n /= 10;
//	}
//	return dfs(Count, 0, 1, 1);
//}
//ll dfs(int pos, int pre, int limit, int first)
//{
//	int i, j, k, max;
//	ll res = 0;
//	if (pos == 0)
//		return 1;
//	if (!limit && dp[pos][pre] != -1)
//		return dp[pos][pre];
//	max = limit ? ar[pos] : 9;
//	for (i = 0; i <= max; i++)
//	{
//		if (first)
//			res += dfs(pos - 1, i, limit && i == ar[pos], first && i == 0);
//		else if (i == 0)
//			continue;
//		else if (i > pre || pre % i)
//			continue;
//		else
//			res += dfs(pos - 1, i, limit && i == ar[pos], first && i == 0);
//	}
//	if (!limit)
//		dp[pos][pre] = res;
//	return res;
//}







//1002   高精度加法；
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <cmath>
//#include <cctype>
//using namespace std;
//const int LEN = 10000;
//char t[LEN + 10];
//char * G_plus(char *a, char *b);
//int main()
//{
//	int i, j, k, n, m, doudou;
//	char a[LEN], b[LEN];
//	while (scanf("%d", &n) != EOF)
//	{
//		doudou = 0;
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%s %s", a, b);
//			if (doudou)
//				putchar('\n');
//			doudou = 1;
//			printf("Case %d:\n", m);
//			printf("%s + %s = %s\n", a, b, G_plus(a, b));
//		}
//	}
//	return 0;
//}
//char * G_plus(char *a, char *b)
//{
//	int L1, L2, L3, i, j, k, u;
//	char temp[LEN + 10], c[LEN + 10];
//	memset(c, 48, sizeof(c));
//	memset(t, 48, sizeof(t));
//	//puts(a);
//	//puts(b);
//	L1 = strlen(a);
//	L2 = strlen(b);
//	for (i = L1 - 1, j = L2 - 1, k = 0; i >= 0 || j >= 0; i--, j--, k++)
//	{
//		if (j < 0)
//		{
//			u = c[k] + a[i] - '0' - '0';
//			if (u >= 10)
//			{
//				c[k + 1] += u / 10;
//				c[k] = u % 10 + '0';
//			}
//			else
//				c[k] = u + '0';
//		}
//		if (i < 0)
//		{
//			u = c[k] + b[j] - '0' - '0';
//			if (u >= 10)
//			{
//				c[k + 1] += u / 10;
//				c[k] = u % 10 + '0';
//			}
//			else
//				c[k] = u + '0';
//		}
//		if (i >= 0 && j >= 0)
//		{
//			u = c[k] + a[i] + b[j] - '0' - '0' - '0';
//			//printf("%d\n", u);
//			if (u >= 10)
//			{
//				c[k + 1] += u / 10;
//				c[k] = u % 10 + '0';
//			}
//			else
//			{
//				c[k] = u + '0';
//			}
//		}
//	}
//	c[k+1] = '\0';
//	i = strlen(c) - 1;
//	while (c[i] == '0')
//		i--;
//	if (i == -1)
//		return "0";
//	for (j = 0; i >= 0; i--, j++)
//		t[j] = c[i];
//	t[j] = '\0';
//	return t;
//}








//高精度减法；
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <cmath>
//#include <cctype>
//using namespace std;
//const int LEN = 10010;
//char a[LEN], b[LEN], c[LEN + 10];
//char ta[LEN], tb[LEN];
//char t[LEN + 10];
//char * G_minus(char *a, char *b);
//char * G_plus(char *a, char *b);
//int main()
//{
//	int i, j, k, n, m, doudou;
//	bool flag1, flag2;
//	printf("请输入测试组数：\n");
//	while (scanf("%d", &n) != EOF)
//	{
//		doudou = 0;
//		for (m = 1; m <= n; m++)
//		{
//			printf("请输入两个数做减法：（例如 a b）\n");
//			flag1 = false;
//			flag2 = false;
//			scanf("%s %s", a, b);
//			if (a[0] == '-')
//				flag1 = true;
//			if (b[0] == '-')
//				flag2 = true;
//			if (!flag1 && !flag2)
//			{
//				if (doudou)
//					putchar('\n');
//				doudou = 1;
//				printf("Case %d:\n", m);
//				printf("%s - %s = %s\n", a, b, G_minus(a, b));
//			}
//			else if (flag1 && !flag2)
//			{
//				if (doudou)
//					putchar('\n');
//				doudou = 1;
//				printf("Case %d:\n", m);
//				printf("%s - %s = -%s\n", a, b, G_plus(a+1, b));
//			}
//			else if (!flag1 && flag2)
//			{
//				if (doudou)
//					putchar('\n');
//				doudou = 1;
//				printf("Case %d:\n", m);
//				printf("%s - %s = %s\n", a, b, G_plus(a, b+1));
//			}
//			else
//			{
//				if (doudou)
//					putchar('\n');
//				doudou = 1;
//				printf("Case %d:\n", m);
//				printf("%s - %s = %s\n", a, b, G_minus(b+1, a+1));
//			}
//		}
//	}
//	return 0;
//}
//char * G_minus(char *a, char *b)
//{
//	int L1, L2, L3, i, j, k, u;
//	bool flag = false;
//	memset(c, 48, sizeof(c));
//	memset(t, 48, sizeof(t));
//	L1 = strlen(a);
//	L2 = strlen(b);
//	if (L1 < L2 || (L1 == L2 && strcmp(a, b) < 0))
//	{
//		strcpy(ta, b);
//		strcpy(tb, a);
//		flag = true;
//	}
//	else
//	{
//		strcpy(ta, a);
//		strcpy(tb, b);
//	}
//	L1 = strlen(ta);
//	L2 = strlen(tb);
//	for (i = L1 - 1, j = L2 - 1, k = 0; i >= 0 || j >= 0; i--, j--, k++)
//	{
//		if (j < 0)
//		{
//			u = c[k] + ta[i] - '0' - '0';
//			if (u < 0)
//			{
//				c[k + 1] -= 1;
//				c[k] = u + 10 + '0';
//			}
//			else
//				c[k] = u + '0';
//		}
//		if (i < 0)
//		{
//			u = c[k] + tb[j] - '0' - '0';
//			if (u < 0)
//			{
//				c[k + 1] -= 1;
//				c[k] = u + 10 + '0';
//			}
//			else
//				c[k] = u + '0';
//		}
//		if (i >= 0 && j >= 0)
//		{
//			u = c[k] + ta[i] - tb[j] + '0' - '0' - '0';
//			//printf("%d\n", u);
//			if (u < 0)
//			{
//				c[k + 1] -= 1;
//				c[k] = u + 10 + '0';
//			}
//			else
//			{
//				c[k] = u + '0';
//			}
//		}
//	}
//	c[k + 1] = '\0';
//	i = strlen(c) - 1;
//	while (c[i] == '0')
//		i--;
//	if (i == -1)
//		return "0";
//	if (flag)
//	{
//		t[0] = '-';
//		for (j = 1; i >= 0; i--, j++)
//			t[j] = c[i];
//		t[j] = '\0';
//		return t;
//	}
//	else
//	{
//		for (j = 0; i >= 0; i--, j++)
//			t[j] = c[i];
//		t[j] = '\0';
//		return t;
//	}
//}
//char * G_plus(char *a, char *b)
//{
//	int L1, L2, L3, i, j, k, u;
//	memset(c, 48, sizeof(c));
//	memset(t, 48, sizeof(t));
//	//puts(a);
//	//puts(b);
//	L1 = strlen(a);
//	L2 = strlen(b);
//	for (i = L1 - 1, j = L2 - 1, k = 0; i >= 0 || j >= 0; i--, j--, k++)
//	{
//		if (j < 0)
//		{
//			u = c[k] + a[i] - '0' - '0';
//			if (u >= 10)
//			{
//				c[k + 1] += u / 10;
//				c[k] = u % 10 + '0';
//			}
//			else
//				c[k] = u + '0';
//		}
//		if (i < 0)
//		{
//			u = c[k] + b[j] - '0' - '0';
//			if (u >= 10)
//			{
//				c[k + 1] += u / 10;
//				c[k] = u % 10 + '0';
//			}
//			else
//				c[k] = u + '0';
//		}
//		if (i >= 0 && j >= 0)
//		{
//			u = c[k] + a[i] + b[j] - '0' - '0' - '0';
//			//printf("%d\n", u);
//			if (u >= 10)
//			{
//				c[k + 1] += u / 10;
//				c[k] = u % 10 + '0';
//			}
//			else
//			{
//				c[k] = u + '0';
//			}
//		}
//	}
//	c[k + 1] = '\0';
//	i = strlen(c) - 1;
//	while (c[i] == '0')
//		i--;
//	if (i == -1)
//		return "0";
//	for (j = 0; i >= 0; i--, j++)
//		t[j] = c[i];
//	t[j] = '\0';
//	return t;
//}

//高精度减法；
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <cmath>
//#include <cctype>
//using namespace std;
//const int LEN = 10010;
//char p[LEN], q[LEN], c[LEN + 10];
//char ta[LEN], tb[LEN];
//char t[LEN + 10];
//char * G_minus(char *a, char *b);
//char * G_plus(char *a, char *b);
//void Print_G_minus(char *a, char *b);
//int main()
//{
//	int i, j, k, n, m;
//	printf("请输入测试组数：\n");
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			printf("请输入两个数做减法：（例如 a b）\n");
//			scanf("%s %s", p, q);
//			Print_G_minus(p, q);
//		}
//	}
//	return 0;
//}
//char * G_minus(char *a, char *b)
//{
//	int L1, L2, L3, i, j, k, u;
//	bool flag = false;
//	memset(c, 48, sizeof(c));
//	memset(t, 48, sizeof(t));
//	L1 = strlen(a);
//	L2 = strlen(b);
//	if (L1 < L2 || (L1 == L2 && strcmp(a, b) < 0))
//	{
//		strcpy(ta, b);
//		strcpy(tb, a);
//		flag = true;
//	}
//	else
//	{
//		strcpy(ta, a);
//		strcpy(tb, b);
//	}
//	L1 = strlen(ta);
//	L2 = strlen(tb);
//	for (i = L1 - 1, j = L2 - 1, k = 0; i >= 0 || j >= 0; i--, j--, k++)
//	{
//		if (j < 0)
//		{
//			u = c[k] + ta[i] - '0' - '0';
//			if (u < 0)
//			{
//				c[k + 1] -= 1;
//				c[k] = u + 10 + '0';
//			}
//			else
//				c[k] = u + '0';
//		}
//		if (i < 0)
//		{
//			u = c[k] + tb[j] - '0' - '0';
//			if (u < 0)
//			{
//				c[k + 1] -= 1;
//				c[k] = u + 10 + '0';
//			}
//			else
//				c[k] = u + '0';
//		}
//		if (i >= 0 && j >= 0)
//		{
//			u = c[k] + ta[i] - tb[j] + '0' - '0' - '0';
//			//printf("%d\n", u);
//			if (u < 0)
//			{
//				c[k + 1] -= 1;
//				c[k] = u + 10 + '0';
//			}
//			else
//			{
//				c[k] = u + '0';
//			}
//		}
//	}
//	c[k + 1] = '\0';
//	i = strlen(c) - 1;
//	while (c[i] == '0')
//		i--;
//	if (i == -1)
//		return "0";
//	if (flag)
//	{
//		t[0] = '-';
//		for (j = 1; i >= 0; i--, j++)
//			t[j] = c[i];
//		t[j] = '\0';
//		return t;
//	}
//	else
//	{
//		for (j = 0; i >= 0; i--, j++)
//			t[j] = c[i];
//		t[j] = '\0';
//		return t;
//	}
//}
//char * G_plus(char *a, char *b)
//{
//	int L1, L2, L3, i, j, k, u;
//	char temp[LEN + 10], c[LEN + 10];
//	memset(c, 48, sizeof(c));
//	memset(t, 48, sizeof(t));
//	//puts(a);
//	//puts(b);
//	L1 = strlen(a);
//	L2 = strlen(b);
//	//不管谁长谁短一起搞，一个没了只加入另一个就行了，两个都没了结束；
//	for (i = L1 - 1, j = L2 - 1, k = 0; i >= 0 || j >= 0; i--, j--, k++)
//	{
//		if (j < 0)
//		{
//			u = c[k] + a[i] - '0' - '0';
//			if (u >= 10)
//			{
//				c[k + 1] += 1;
//				c[k] = u % 10 + '0';
//			}
//			else
//				c[k] = u + '0';
//		}
//		if (i < 0)
//		{
//			u = c[k] + b[j] - '0' - '0';
//			if (u >= 10)
//			{
//				c[k + 1] += 1;
//				c[k] = u % 10 + '0';
//			}
//			else
//				c[k] = u + '0';
//		}
//		if (i >= 0 && j >= 0)
//		{
//			u = c[k] + a[i] + b[j] - '0' - '0' - '0';
//			//printf("%d\n", u);
//			if (u >= 10)
//			{
//				c[k + 1] += 1;
//				c[k] = u % 10 + '0';
//			}
//			else
//			{
//				c[k] = u + '0';
//			}
//		}
//	}
//	c[k + 1] = '\0';
//	i = strlen(c) - 1;
//	//去掉前导0；
//	while (c[i] == '0')
//		i--;
//	//如果结果是0，输出“0”
//	if (i == -1)
//		return "0";
//	//把反向改为正向输出
//	for (j = 0; i >= 0; i--, j++)
//		t[j] = c[i];
//	t[j] = '\0';
//	return t;
//}
//
//void Print_G_minus(char *a, char *b)
//{
//	bool flag1 = false, flag2 = false;
//	if (a[0] == '-')
//		flag1 = true;
//	if (b[0] == '-')
//		flag2 = true;
//	if (!flag1 && !flag2)
//	{
//		printf("%s - %s = %s\n", a, b, G_minus(a, b));
//	}
//	else if (flag1 && !flag2)
//	{
//		printf("%s - %s = -%s\n", a, b, G_plus(a + 1, b));
//	}
//	else if (!flag1 && flag2)
//	{
//		printf("%s - %s = %s\n", a, b, G_plus(a, b + 1));
//	}
//	else
//	{
//		printf("%s - %s = %s\n", a, b, G_minus(b + 1, a + 1));
//	}
//}







//BC93
//#include <cstdio>
//#include <cstring>
//#include <cctype>
//#include <cstdlib>
//#include <algorithm>
//#include <map>
//using namespace std;
//typedef __int64 ll;
//ll ar[100010];
//map<ll, ll>q;
//int main()
//{
//	int i, j, k, u, n, m, flag, a, b;
//	ll f;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &a);
//			flag = 1;
//			q.clear();
//			for (b = 1; b <= a; b++)
//			{
//				scanf("%I64d", &ar[b]);
//				if (q[ar[b]])
//				{
//					flag++;
//					q.clear();
//				}
//				if (q[ar[b]] == 0)
//					q[ar[b]] = 1;
//			}
//			printf("%d\n", flag);
//		}
//	}
//	return 0;
//}






//1358  KMP第一题；
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <string>
//#include <algorithm>
//using namespace std;
//int Mainl, Assl;
//char ar[1000010];
//int Next[1000010];
//void Cal_Next();
//int main()
//{
//	int n, m, i, j, doudou = 0, cas = 1;
//	while (scanf("%d", &n) != EOF && n)
//	{
//		scanf("%s", ar + 1);
//		Assl = n;
//		Cal_Next();
//		//for (i = 1; i <= n; i++)
//		//	printf("%d ", Next[i]);
//		//putchar('\n');
//		printf("Test case #%d\n", cas++);
//		for (i = 2; i <= n; i++)
//		{
//			if (i % (i - Next[i]) == 0 && Next[i] != 0)
//				printf("%d %d\n", i, i / (i - Next[i]));
//		}
//		putchar('\n');
//	}
//	return 0;
//}
//void Cal_Next()
//{
//	int i, j, L = 1;
//	Next[1] = 0;
//	for (i = 2; i <= Assl; i++)
//	{
//		j = Next[i - 1];
//		while (ar[j + 1] != ar[i] && j >= 1)
//		{
//			j = Next[j];
//		}
//		if (ar[j + 1] == ar[i])
//		{
//			Next[i] = j + 1;
//		}
//		else
//			Next[i] = 0;
//	}
//}






//1171  KMP第二题；
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <string>
//#include <algorithm>
//using namespace std;
//int Mainl, Assl;
//int sa[10010], ar[1000010];
//int Next[10010];
//void Cal_Next();
//int KMP();
//int main()
//{
//	int i, j, k, n, m;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d", &Mainl, &Assl);
//			for (i = 1; i <= Mainl; i++)
//				scanf("%d", &ar[i]);
//			for (i = 1; i <= Assl; i++)
//				scanf("%d", &sa[i]);
//			Cal_Next();
//			printf("%d\n", KMP());
//		}
//	}
//	return 0;
//}
//int KMP()
//{
//	int i, j, L1, L2, doudou = 0;
//	i = 1;
//	j = 1;
//	while (i <= Mainl && j <= Assl)
//	{
//		if (ar[i] == sa[j])
//		{
//			if (j == Assl)
//			{
//				doudou = 1;
//				break;
//			}
//			else;
//			i++;
//			j++;
//		}
//		else
//		{
//			if (j == 1)
//			{
//				i++;
//			}
//			else
//			{
//				j = Next[j - 1] + 1;
//			}
//		}
//	}
//	if (doudou)
//		return i - Assl + 1;
//	return -1;
//}
//void Cal_Next()
//{
//	int i, j, k, L1, L2;
//	Next[1] = 0;
//	for (i = 2; i <= Assl; i++)
//	{
//		j = Next[i - 1];
//		while (sa[i] != sa[j + 1] && j > 0)
//		{
//			j = Next[j];
//		}
//		if (sa[i] == sa[j + 1])
//			Next[i] = j + 1;
//		else
//			Next[i] = 0;
//	}
//}










//1238  KMP专题第3题；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//using namespace std;
//const int MAX = 100000000;
//char ar[110][110], a[110], b[110];
//int main()
//{
//	int i, j, k, n, m, u, min, Len, count, index, p, q, max, doudou;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &k);
//			min = MAX;
//			for (u = 1; u <= k; u++)
//			{
//				scanf("%s", ar[u] + 1);
//				Len = strlen(ar[u] + 1);
//				if (min > Len)
//				{
//					min = Len;
//					index = u;
//				}
//			}
//			max = 0;
//			for (i = 1; i <= min; i++)
//			{
//				for (j = min; j >= i; j--)
//				{
//					for (u = i; u <= j; u++)
//					{
//						a[u - i + 1] = ar[index][u];
//						b[j - u + 1] = ar[index][u];
//					}
//					a[j - i + 2] = '\0';
//					b[j - i + 2] = '\0';
//					//puts(a+1);
//					//puts(b+1);
//					count = 0;
//					for (u = 1; u <= k; u++)
//					{
//						if (strstr(ar[u]+1, a+1) || strstr(ar[u]+1, b+1))
//							count++;
//					}
//					//printf("%d\n\n", count);
//					if (count == k && max < j-i+1)
//						max = j-i+1;
//				}
//			}
//			printf("%d\n", max);
//		}
//	}
//	return 0;
//}







//浙大校赛1；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int i, j, k, n, m, u, a, b, c, x, y, ta, tb, sum;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d %d %d", &x, &y, &a, &b);
//			if ((x == 1 && a > 0) || (y == 1 && b > 0) || (x == (x*x - a) / b * y))
//			{
//				printf("INF\n");
//				continue;
//			}
//			sum = 0;
//			while (a >= x || b >= y)
//			{
//				i = a / x;
//				j = b / y;
//				sum += i;
//				sum += j;
//				a = a % x + j + i;
//				b = b % y + i + j;
//			}
//			printf("%d\n", sum);
//		}
//	}
//	return 0;
//}







//浙大校赛 10；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//int Mainl, Assl;
//void Cal_Next();
//int KMP();
//int Next[10];
//char ar[1010], sa[10];
//int main()
//{
//	int i, j, k, u, n, m, a, b, sum;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%s", ar + 1);
//			Mainl = strlen(ar + 1);
//			sum = 0;
//			sa[1] = 'd';
//			sa[2] = 'o';
//			sa[3] = 'g';
//			sa[4] = '\0';
//			Assl = strlen(sa + 1);
//			Cal_Next();
//			sum += KMP();
//			sa[1] = 'c';
//			sa[2] = 'a';
//			sa[3] = 't';
//			sa[4] = '\0';
//			sum += KMP();
//			printf("%d\n", sum);
//		}
//	}
//}
//int KMP()
//{
//	int i, j, L1, L2, doudou = 0, s = 0;
//	i = 1;
//	j = 1;
//	while (i <= Mainl)
//	{
//		if (ar[i] == sa[j])
//		{
//			if (j == Assl)
//			{
//				s++;
//				j = 1;
//				i++;
//			}
//			else;
//			i++;
//			j++;
//		}
//		else
//		{
//			if (j == 1)
//			{
//				i++;
//			}
//			else
//			{
//				j = Next[j - 1] + 1;
//			}
//		}
//	}
//	return s;
//}
//void Cal_Next()
//{
//	int i, j, k, L1, L2;
//	Next[1] = 0;
//	for (i = 2; i <= Assl; i++)
//	{
//		j = Next[i - 1];
//		while (sa[i] != sa[j + 1] && j > 0)
//		{
//			j = Next[j];
//		}
//		if (sa[i] == sa[j + 1])
//			Next[i] = j + 1;
//		else
//			Next[i] = 0;
//	}
//}







//2203  KMP第4题；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//using namespace std;
//int Mainl, Assl;
//int Next[100010];
//char ar[200020], sa[100010], t[100010];
//void Cal_Next();
//bool KMP();
//int main()
//{
//	int i, j, k;
//	while (scanf("%s%s", t + 1, sa + 1) != EOF)
//	{
//		Mainl = strlen(t + 1);
//		Assl = strlen(sa + 1);
//		strcpy(ar + 1, t + 1);
//		strcat(ar + Mainl + 1, t + 1);
//		Mainl = strlen(ar + 1);
//		Cal_Next();
//		if (KMP())
//			printf("yes\n");
//		else
//			printf("no\n");
//	}
//	return 0;
//}
//void Cal_Next()
//{
//	int i, j, L;
//	Next[1] = 0;
//	for (i = 2; i <= Assl; i++)
//	{
//		j = Next[i - 1];
//		while (sa[j + 1] != sa[i] && j > 0)
//			j = Next[j];
//		if (sa[j + 1] == sa[i])
//			Next[i] = j + 1;
//		else
//			Next[i] = 0;
//	}
//}
//bool KMP()
//{
//	int i = 1, j = 1, k, L;
//	while (i <= Mainl && j <= Assl)
//	{
//		if (ar[i] == sa[j])
//		{
//			if (j == Assl)
//				return true;
//			i++;
//			j++;
//		}
//		else
//		{
//			if (j == 1)
//				i++;
//			else
//				j = Next[j - 1] + 1;
//		}
//	}
//	return false;
//}







//3336 KMP第5题；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//using namespace std;
//int Mainl, Assl;
//int Sum;
//char ar[200010];
//int Next[200010], set[200010];
//void Cal_Next();
////int KMP();
//int main()
//{
//	int i, j, k, n, m, a, b, sum;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &Mainl);
//			scanf("%s", ar + 1);
//			memset(set, 0, sizeof(set));
//			Sum = 0;
//			Cal_Next();
//			//for(i = 1; i <= Mainl; i++)
//			//{
//			//    printf("%d ", Next[i]);
//			//}
//			//for(i = 1; i <= Mainl; i++)
//			//{
//			//    set[Next[i]]++;
//			//}
//
//			for (i = 1; i <= Mainl; i++)
//			{
//				Sum = (set[i] + Sum) % 10007;
//			}
//			printf("%d\n", (Sum + Mainl) % 10007);
//		}
//	}
//	return 0;
//}
//void Cal_Next()
//{
//	int i, j, k;
//	Next[1] = 0;
//	for (i = 2; i <= Mainl; i++)
//	{
//		j = Next[i - 1];
//		while (ar[j + 1] != ar[i] && j > 0)
//		{
//			j = Next[j];
//		}
//		if (ar[j + 1] == ar[i])
//		{
//			Next[i] = j + 1;
//			set[Next[i]]++;
//		}
//		else
//			Next[i] = 0;
//	}
//}





//3613  KMP第6题，回文串匹配；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//const int MAX = 100000000;
//int Mainl, Assl;
//int Next[500010];
//char ar[500010], sa[500010];
//int pos1[500010], pos2[500010];
//int val[30], sum[500010];
//int KMP(char *s, char *t);
//void Cal_Next(char *s);
//int main()
//{
//	int i, j, k1, k2, n, m, temp, max;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			for (i = 0; i < 26; i++)
//				scanf("%d", &val[i]);
//			scanf("%s", ar);
//			Mainl = strlen(ar);
//			sum[0] = 0;
//			for (i = 0; i < Mainl; i++)
//			{
//				sa[i] = ar[Mainl - i - 1];
//				sum[i + 1] = sum[i] + val[ar[i] - 'a'];
//			}
//			Cal_Next(ar);
//			k1 = KMP(ar, sa);
//			while (k1)
//			{
//				pos1[k1] = m;
//				k1 = Next[k1];
//			}
//			Cal_Next(sa);
//			k2 = KMP(sa, ar);
//			while (k2)
//			{
//				pos2[k2] = m;
//				k2 = Next[k2];
//			}
//			max = -MAX;
//			for (i = 1; i < Mainl; i++)
//			{
//				temp = 0;
//				if (pos1[i] == m)
//					temp += sum[i];
//				if (pos2[Mainl - i] == m)
//					temp += sum[Mainl] - sum[i];
//				if (temp > max)
//					max = temp;
//			}
//			printf("%d\n", max);
//		}
//	}
//	return 0;
//}
//void Cal_Next(char *s)
//{
//	int i = -1, j = 0, L;
//	Next[0] = -1;
//	while (j < Mainl)
//	{
//		if (i == -1 || s[i] == s[j])
//			Next[++j] = ++i;
//		else
//			i = Next[i];
//	}
//}
//
//int KMP(char *s, char *t)
//{
//	int i = 0, j = 0;
//	while (i < Mainl && j < Mainl)
//	{
//		if (i == -1 || s[i] == t[j])
//		{
//			i++;
//			j++;
//		}
//		else
//			i = Next[i];
//	}
//	return i;
//}
//3613 EKMP;
//#include<iostream>  
//#include<cstdio>  
//#include<cstdlib>  
//#include<cstring>  
//#include<string>  
//#include<queue>  
//#include<algorithm>  
//#include<map>  
//#include<iomanip>  
//#define INF 99999999  
//using namespace std;
//
//const int MAX = 500000 + 10;
//char s1[MAX], s2[MAX];
//int Next[MAX], extend1[MAX], extend2[MAX];
//int sum[MAX], val[27];
//
//void get_Next(char *a, int len) {
//	int k = 0, i = 1, j;
//	Next[0] = len;
//	while (k + 1<len && a[k] == a[k + 1])++k;
//	Next[1] = k;
//	k = 1;
//	for (i = 2; i < len; i++)
//	{
//		if (Next[i - k] + i < Next[k] + k)
//			Next[i] = Next[i - k];
//		else
//		{
//			j = Next[k] + k - i;
//			if (j < 0)
//				j = 0;
//			while (a[i + j] == a[j] && i + j < len)
//				j++;
//			Next[i] = j;
//			k = i;
//		}
//	}
//}
//
//void EKMP(char *a, char *b, int *extend, int len) {
//	get_Next(a, len);
//	int k = 0, i = 0, j;
//	while (k < len && a[k] == b[k])++k;
//	extend[0] = k;
//	k = 0;
//	for (i = 1; i < len; i++)
//	{
//		if (Next[i - k] + i < extend[k] + k)
//			extend[i] = Next[i - k];
//		else
//		{
//			j = extend[k] + k - i;
//			if (j < 0)
//				j = 0;
//			while (b[i + j] == a[j] && i + j < len)
//				j++;
//			extend[i] = j;
//			k = i;
//		}
//	}
//}
//
//int main() {
//	int n;
//	cin >> n;
//	while (n--) {
//		for (int i = 0; i<26; ++i)cin >> val[i];
//		scanf("%s", s1);
//		int len = strlen(s1);
//		for (int i = 1; i <= len; ++i) {
//			sum[i] = sum[i - 1] + val[s1[i - 1] - 'a'];
//			s2[i - 1] = s1[len - i];
//		}
//		EKMP(s1, s2, extend1, len);
//		EKMP(s2, s1, extend2, len);
//		int ans = 0, temp = 0;
//		for (int i = 1; i<len; ++i) {
//			if (extend1[len - i] == i)temp += sum[i];//???i???????  
//			if (extend2[i] == len - i)temp += sum[len] - sum[i];//???len-i???????  
//			if (temp>ans)ans = temp;
//			temp = 0;
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}






//3746  KMP第7题；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//using namespace std;
//int Mainl, Assl;
//char ar[100010];
//int Next[100010];
//void Cal_Next();
//int main()
//{
//	int i, j, k, n, m, re, t;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%s", ar);
//			Mainl = strlen(ar);
//			Cal_Next();
//			re = Mainl - Next[Mainl];
//			if (Next[Mainl] && Mainl % re == 0)
//			{
//				printf("0\n");
//			}
//			else
//			{
//				t = re - Mainl % re;
//				printf("%d\n", t);
//			}
//		}
//	}
//	return 0;
//}
//void Cal_Next()
//{
//	int i = 0, j = -1;
//	Next[0] = -1;
//	while (i < Mainl)
//	{
//		if (j == -1 || ar[i] == ar[j])
//		{
//			Next[++i] = ++j;
//		}
//		else
//			j = Next[j];
//	}
//}





//4300 KMP第8题，EKMP+MAP；
//#include <stdio.h>
//#include <cstring>
//#include <map>
//using namespace std;
//int Mainl, Assl;
//char ar[100010], sa[100010], s[100010];
//int Next[100010], EX[100010];
//void Cal_Next();
//void EKMP();
//map<char, char>q;
//int main()
//{
//	int i, j, k, n, m;
//	char ch;
//	while (scanf("%d", &n)  != EOF)
//	{
//		getchar();
//		q.clear();
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%s", ar);
//			for (i = 0; i < 26; i++)
//			{
//				q[ar[i]] = 'a'+i;
//			}
//			scanf("%s", sa);
//			Mainl = strlen(sa);
//			strcpy(s, sa);
//			for (i = 0; i < Mainl; i++)
//			{
//				sa[i] = q[sa[i]];
//			}
//			EKMP();
//			//for (i = 0; i < Mainl; i++)
//			//{
//			//	printf("%d ", EX[i]);
//			//}
//			//for (i = 0; i < Mainl; i++)
//			//{
//			//	printf("%d ", Next[i]);
//			//}
//			for (i = 0; i < Mainl; i++)
//			{
//				if (i >= EX[i] && i + EX[i] == Mainl)
//					break;
//			}
//			//puts(sa);
//			//puts(s);
//			for (j = 0; j < i; j++)
//				putchar(s[j]);
//			for (j = 0; j < i; j++)
//				putchar(sa[j]);
//			putchar('\n');
//		}
//	}
//	return 0;
//}
//void EKMP()
//{
//	int i = 0, j = 0, k, po = 0;
//	Cal_Next();
//	while (s[i] == sa[i] && i < Mainl)
//		i++;
//	EX[0] = i;
//	for (i = 1; i < Mainl; i++)
//	{
//		if (Next[i - po] + i < EX[po] + po)
//			EX[i] = Next[i - po];
//		else
//		{
//			j = EX[po] + po - i;
//			if (j < 0)
//				j = 0;
//			while (s[i + j] == sa[j] && i + j < Mainl)
//				j++;
//			EX[i] = j;
//			po = i;
//		}
//	}
//}
//void Cal_Next()
//{
//	int i, j = 0, po = 1;
//	Next[0] = Mainl - 1;
//	while (sa[j] == sa[j + 1] && j < Mainl)
//		j++;
//	Next[1] = j;
//	for (i = 2; i < Mainl; i++)
//	{
//		if (Next[i - po] + i < Next[po] + po)
//			Next[i] = Next[i - po];
//		else
//		{
//			j = Next[po] + po - i;
//			if (j < 0)
//				j = 0;
//			while (sa[i + j] == sa[j] && i + j < Mainl)
//				j++;
//			Next[i] = j;
//			po = i;
//		}
//	}
//}






//1269   强连通第一题；
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//int Stack[100010], Instack[100010];
//int dfn[100010], low[100010];
//int head[100010];
//int num[100010];
//int Sccc, cnt, top, Index;
//struct point
//{
//	int to;
//	int next;
//};
//point edge[100010];
//void addedge(int t, int n);
//bool solve(int n);
//void Tarjan(int f);
//int main()
//{
//	int i, j, k, n, m, a, b, doudou;
//	while (scanf("%d %d", &n, &m) != EOF && (n || m))
//	{
//		Sccc = 0;
//		cnt = 0;
//		top = 0;
//		Index = 0;
//		memset(head, -1, sizeof(head));
//		memset(Instack, 0, sizeof(Instack));
//		memset(dfn, 0, sizeof(dfn));
//		memset(num, 0, sizeof(num));
//		for (i = 1; i <= m; i++)
//		{
//			scanf("%d %d", &a, &b);
//			addedge(a, b);
//		}
//		if (solve(n))
//			printf("Yes\n");
//		else
//			printf("No\n");
//	}
//	return 0;
//}
//void addedge(int a, int b)
//{
//	edge[cnt].to = b;
//	edge[cnt].next = head[a];
//	head[a] = cnt++;
//}
//bool solve(int n)
//{
//	int i, j;
//	for (i = 1; i <= n; i++)
//	{
//		if (!dfn[i])
//			Tarjan(i);
//		if (num[i] == n)
//			return true;
//	}
//	return false;
//}
//void Tarjan(int f)
//{
//	int i, k, j, temp;
//	low[f] = dfn[f] = ++Index;
//	Stack[top++] = f;
//	Instack[f] = 1;
//	for (i = head[f]; i != -1; i = edge[i].next)
//	{
//		temp = edge[i].to;
//		if (!dfn[temp])
//		{
//			Tarjan(temp);
//			if (low[f] > low[temp])
//				low[f] = low[temp];
//		}
//		else if (Instack[temp] && low[f] > dfn[temp])
//			low[f] = dfn[temp];
//	}
//	if (low[f] == dfn[f])
//	{
//		Sccc = f;
//		do
//		{
//			temp = Stack[--top];
//			Instack[temp] = 0;
//			num[Sccc]++;
//		} while (temp != f);
//	}
//}






//1827  强连通第2题，找强连通分量，处理一下，可以找到需要打多少个电话；
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//using namespace std;
//const int MAX = 100000000;
//int Stack[1010], Instack[1010];
//int dfn[1010], low[1010];
//int head[1010];
//int val[1010];
//int num[1010], set[1010];
//int Sccc, top, cnt, Index;
//struct node
//{
//	int from;
//	int to;
//	int next;
//};
//node edge[2010];
//void add(int a, int b);
//void Tarjan(int f);
//int solve(int n);
//int main()
//{
//	int i, j, k, x, y, n, m;
//	while (scanf("%d %d", &n, &m) != EOF)
//	{
//		for (i = 1; i <= n; i++)
//			scanf("%d", &val[i]);
//		Index = Sccc = top = cnt = 0;
//		memset(head, -1, sizeof(head));
//		memset(Instack, 0, sizeof(Instack));
//		memset(dfn, 0, sizeof(dfn));
//		memset(set, 0, sizeof(set));
//		memset(num, -1, sizeof(num));
//		for (i = 1; i <= m; i++)
//		{
//			scanf("%d %d", &x, &y);
//			add(x, y);
//		}
//		j = solve(n);
//		printf("%d %d\n", Sccc, j);
//	}
//}
//void add(int a, int b)
//{
//	edge[cnt].from = a;
//	edge[cnt].to = b;
//	edge[cnt].next = head[a];
//	head[a] = cnt++;
//}
//int solve(int n)
//{
//	int i, j, sum = 0, min;
//	for (i = 1; i <= n; i++)
//	{
//		if (!dfn[i])
//			Tarjan(i);
//	}
//	for (i = 0; i < cnt; i++)
//	{
//		if (num[edge[i].from] == num[edge[i].to])
//			continue;
//		set[num[edge[i].to]]++;
//	}
//	for (i = 1; i <= n; i++)
//	{
//		if (num[i] != i)
//			continue;
//		if (set[i])
//			continue;
//		Sccc++;
//		min = MAX;
//		for (j = 1; j <= n; j++)
//		{
//			if (num[j] == i && val[j] < min)
//				min = val[j];
//		}
//		sum += min;
//	}
//	return sum;
//}
//void Tarjan(int f)
//{
//	int i, k, j, temp;
//	low[f] = dfn[f] = ++Index;
//	Stack[top++] = f;
//	Instack[f] = 1;
//	for (i = head[f]; i != -1; i = edge[i].next)
//	{
//		temp = edge[i].to;
//		if (!dfn[temp])
//		{
//			Tarjan(temp);
//			if (low[f] > low[temp])
//				low[f] = low[temp];
//		}
//		else if (Instack[temp] && low[f] > dfn[temp])
//			low[f] = dfn[temp];
//	}
//	if (low[f] == dfn[f])
//	{
//		do
//		{
//			temp = Stack[--top];
//			Instack[temp] = 0;
//			num[temp] = f;
//		} while (temp != f);
//	}
//}









//2767   强连通  缩点；
//#include <cstdio>
//#include <cstring>
//using namespace std;
//struct node
//{
//	int from;
//	int to;
//	int next;
//};
//node edge[50010];
//int Stack[20010], Instack[20010];
//int dfn[20010], low[20010];
//int head[20010];
//int belong[20010];
//int in[20010], out[20010];
//int Sccc, top, Index, cnt;
//int IN, OUT;
//void add(int x, int y);
//void Tarjan(int f);
//void solve(int n, int m);
//int main()
//{
//	int i, j, k, n, m, a, b, p, q;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			Sccc = top = Index = cnt = IN = OUT = 0;
//			memset(head, -1, sizeof(head));
//			memset(Instack, 0, sizeof(Instack));
//			memset(dfn, 0, sizeof(dfn));
//			memset(in, 0, sizeof(in));
//			memset(out, 0, sizeof(out));
//			memset(belong, -1, sizeof(belong));
//			scanf("%d %d", &a, &b);
//			for (i = 1; i <= b; i++)
//			{
//				scanf("%d %d", &p, &q);
//				add(p, q);
//			}
//			solve(a, b);
//			if (Sccc == 1)
//				printf("0\n");
//			else
//			{
//				printf("%d\n", IN > OUT ? IN : OUT);
//			}
//		}
//	}
//	return 0;
//}
//void add(int x, int y)
//{
//	edge[cnt].from = x;
//	edge[cnt].to = y;
//	edge[cnt].next = head[x];
//	head[x] = cnt++;
//}
//void solve(int n, int m)
//{
//	int i, j, k;
//	for (i = 1; i <= n; i++)
//		if (!dfn[i])
//			Tarjan(i);
//	for (i = 0; i < cnt; i++)
//	{
//		if (belong[edge[i].from] != belong[edge[i].to])
//		{
//			in[belong[edge[i].to]]++;
//			out[belong[edge[i].from]]++;
//		}
//	}
//	for (i = 1; i <= Sccc; i++)
//	{
//		if (in[i] == 0)
//			IN++;
//		if (out[i] == 0)
//			OUT++;
//	}
//}
//void Tarjan(int f)
//{
//	int i, j, temp;
//	low[f] = dfn[f] = ++Index;
//	Stack[top++] = f;
//	Instack[f] = 1;
//	for (i = head[f]; i != -1; i = edge[i].next)
//	{
//		temp = edge[i].to;
//		if (!dfn[temp])
//		{
//			Tarjan(temp);
//			if (low[f] > low[temp])
//				low[f] = low[temp];
//		}
//		else if (Instack[temp] && low[f] > dfn[temp])
//			low[f] = dfn[temp];
//	}
//	if (low[f] == dfn[f])
//	{
//		Sccc++;
//		do
//		{
//			temp = Stack[--top];
//			Instack[temp] = 0;
//			belong[temp] = Sccc;
//		} while (temp != f);
//	}
//}









//3639  强连通第3题   缩点+反向建图+dfs；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//using namespace std;
//int Stack[5010], Instack[5010];
//int dfn[5010], low[5010];
//int head[5010], hd[5010];
//int belong[5010], num[5010], res[5010], visit[5010], in[5010];
//int Index, top, cnt, Sccc, tot;
//int ans;
//struct node
//{
//	int from;
//	int next;
//	int to;
//};
//node edge[60010], e[60010];
//void add(int x, int y);
//void ad(int x, int y);
//void Tarjan(int f);
//int dfs(int n);
//void solve(int n, int m, int cas);
//int main()
//{
//	int i, j, k, n, m, a, b, c, p, q, N, M;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			top = Index = cnt = Sccc = ans = tot = 0;
//			memset(dfn, 0, sizeof(dfn));
//			memset(Instack, 0, sizeof(Instack));
//			memset(head, -1, sizeof(head));
//			memset(belong, -1, sizeof(belong));
//			memset(num, 0, sizeof(num));
//			memset(res, -1, sizeof(res));
//			memset(visit, 0, sizeof(visit));
//			memset(in, 0, sizeof(in));
//			memset(hd, -1, sizeof(hd));
//			scanf("%d %d", &N, &M);
//			for (i = 1; i <= M; i++)
//			{
//				scanf("%d %d", &p, &q);
//				add(p, q);
//			}
//			solve(N, M, m);
//		}
//	}
//	return 0;
//}
//void add(int x, int y)
//{
//	edge[cnt].from = x;
//	edge[cnt].to = y;
//	edge[cnt].next = head[x];
//	head[x] = cnt++;
//}
//void ad(int x, int y)
//{
//	e[tot].to = y;
//	e[tot].from = x;
//	e[tot].next = hd[x];
//	hd[x] = tot++;
//}
//void Tarjan(int f)
//{
//	int i, j, k, temp;
//	low[f] = dfn[f] = ++Index;
//	Stack[top++] = f;
//	Instack[f] = 1;
//	for (i = head[f]; i != -1; i = edge[i].next)
//	{
//		temp = edge[i].to;
//		if (!dfn[temp])
//		{
//			Tarjan(temp);
//			low[f] = (low[f] > low[temp]) ? low[temp] : low[f];
//		}
//		else if (Instack[temp] && low[f] > dfn[temp])
//			low[f] = dfn[temp];
//	}
//	if (low[f] == dfn[f])
//	{
//		Sccc++;
//		do
//		{
//			temp = Stack[--top];
//			Instack[temp] = 0;
//			num[Sccc]++;
//			belong[temp] = Sccc;
//		} while (temp != f);
//	}
//}
//int dfs(int n)
//{
//	int i, j, k, t, sum = num[n];
//	visit[n] = 1;
//	for (i = hd[n]; i != -1; i = e[i].next)
//		if (!visit[e[i].to])
//			sum += dfs(e[i].to);
//	return sum;
//}
//void solve(int n, int m, int cas)
//{
//	int i, j, k, s, t;
//	for (i = 0; i < n; i++)
//	{
//		if (!dfn[i])
//			Tarjan(i);
//	}
//	for (i = 0; i < n; i++)
//	{
//		for (j = head[i]; j != -1; j = edge[j].next)
//		{
//			if (belong[i] != belong[edge[j].to])
//			{
//				ad(belong[edge[j].to], belong[i]);
//				in[belong[i]]++;
//			}
//		}
//	}
//	ans = -1;
//	for (i = 1; i <= Sccc; i++)
//	{
//		if (!in[i])
//		{
//			memset(visit, 0, sizeof(visit));
//			res[i] = dfs(i);
//			if (ans < res[i])
//				ans = res[i];
//		}
//	}
//	printf("Case %d: %d\n", cas, ans-1);
//	bool doudou = false;
//	for (i = 0; i < n; i++)
//		if (res[belong[i]] == ans)
//		{
//			if (doudou)
//				putchar(' ');
//			doudou = true;
//			printf("%d", i);
//		}
//	putchar('\n');
//}






//3861  强连通Tarjan（缩点+正向建图）+二分匹配匈牙利；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//using namespace std;
//int dfn[5010], low[5010];
//int Instack[5010], Stack[5010];
//int num[5010], belong[5010], head[5010], hd[5010];
//int visit[5010];
//int link[5010];
//struct node
//{
//	int from;
//	int to;
//	int next;
//};
//node edge[100010], e[100010];
//int Sccc, top, cnt, tot, Index;
//void addedge(int x, int y);
//void add(int x, int y);
//void Tarjan(int f);
//void solve(int n, int m);
//bool dfs(int f);
//int main()
//{
//	int i, j, k, u, N, M, n, m, a, b;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			Sccc = top = cnt = tot = Index = 0;
//			memset(head, -1, sizeof(head));
//			memset(hd, -1, sizeof(hd));
//			memset(Instack, 0, sizeof(Instack));
//			memset(dfn, 0, sizeof(dfn));
//			memset(belong, -1, sizeof(belong));
//			memset(num, 0, sizeof(num));
//			memset(visit, 0, sizeof(visit));
//			memset(link, -1, sizeof(link));
//			scanf("%d %d", &N, &M);
//			for (i = 1; i <= M; i++)
//			{
//				scanf("%d %d", &a, &b);
//				addedge(a, b);
//			}
//			solve(N, M);
//		}
//	}
//	return 0;
//}
//void addedge(int x, int y)
//{
//	edge[cnt].from = x;
//	edge[cnt].to = y;
//	edge[cnt].next = head[x];
//	head[x] = cnt++;
//}
//void add(int x, int y)
//{
//	e[tot].from = x;
//	e[tot].to = y;
//	e[tot].next = hd[x];
//	hd[x] = tot++;
//}
//void Tarjan(int f)
//{
//	int i, j, k, temp;
//	dfn[f] = low[f] = ++Index;
//	Stack[top++] = f;
//	Instack[f] = 1;
//	for (i = head[f]; i != -1; i = edge[i].next)
//	{
//		temp = edge[i].to;
//		if (!dfn[temp])
//		{
//			Tarjan(temp);
//			if (low[f] > low[temp])
//				low[f] = low[temp];
//		}
//		else if (Instack[temp] && low[f] > dfn[temp])
//			low[f] = dfn[temp];
//	}
//	if (low[f] == dfn[f])
//	{
//		Sccc++;
//		do
//		{
//			temp = Stack[--top];
//			Instack[temp] = 0;
//			num[Sccc]++;
//			belong[temp] = Sccc;
//		} while (temp != f);
//	}
//}
//void solve(int n, int m)
//{
//	int i, j, k, sum = 0;
//	for (i = 1; i <= n; i++)
//	{
//		if (!dfn[i])
//			Tarjan(i);
//	}
//	for (i = 1; i <= n; i++)
//	{
//		for (j = head[i]; j != -1; j = edge[j].next)
//		{
//			if (belong[i] != belong[edge[j].to])
//			{
//				add(belong[i], belong[edge[j].to]);
//			}
//		}
//	}
//	for (i = 1; i <= Sccc; i++)
//	{
//		memset(visit, 0, sizeof(visit));
//		if (!visit[i])
//			if (dfs(i))
//				sum++;
//	}
//	printf("%d\n", Sccc - sum);
//}
//bool dfs(int f)
//{
//	int i, j, k;
//	visit[f] = 1;
//	for (i = hd[f]; i != -1; i = e[i].next)
//	{
//		if (!visit[e[i].to])
//		{
//			visit[e[i].to] = 1;
//			if (link[e[i].to] == -1 || dfs(link[e[i].to]))
//			{
//				link[e[i].to] = f;
//				return true;
//			}
//		}
//	}
//	return false;
//}








//3836  强连通第6题 缩点+入度、初度为0的组的最大个数；
//#include <cstdio>
//#include <cstring>
//using namespace std;
//int dfn[20010], low[20010];
//int Instack[20010], Stack[20010];
//int head[20010], belong[20010];
//int in[50010], out[50010];
//int top, Index, Sccc, IN, OUT, cnt;
//struct node
//{
//	int from;
//	int to;
//	int next;
//};
//node edge[50010];
//void addedge(int x, int y);
//void solve(int n, int m);
//void Tarjan(int f);
//int main()
//{
//	int i, j, k, n, m, a, b;
//	while (scanf("%d %d", &n, &m) != EOF)
//	{
//		top = Index = Sccc = cnt = IN = OUT = 0;
//		memset(Instack, 0, sizeof(Instack));
//		memset(head, -1, sizeof(head));
//		memset(dfn, 0, sizeof(dfn));
//		memset(in, 0, sizeof(in));
//		memset(out, 0, sizeof(out));
//		memset(belong, -1, sizeof(belong));
//		for (i = 1; i <= m; i++)
//		{
//			scanf("%d %d", &a, &b);
//			addedge(a, b);
//		}
//		solve(n, m);
//	}
//	return 0;
//}
//void addedge(int x, int y)
//{
//	edge[cnt].from = x;
//	edge[cnt].to = y;
//	edge[cnt].next = head[x];
//	head[x] = cnt++;
//}
//void Tarjan(int f)
//{
//	int i, j, temp;
//	low[f] = dfn[f] = ++Index;
//	Instack[f] = 1;
//	Stack[top++] = f;
//	for (i = head[f]; i != -1; i = edge[i].next)
//	{
//		temp = edge[i].to;
//		if (!dfn[temp])
//		{
//			Tarjan(temp);
//			if (low[f] > low[temp])
//				low[f] = low[temp];
//		}
//		else if (Instack[temp] && low[f] > dfn[temp])
//			low[f] = dfn[temp];
//	}
//	if (low[f] == dfn[f])
//	{
//		Sccc++;
//		do
//		{
//			temp = Stack[--top];
//			Instack[temp] = 0;
//			belong[temp] = Sccc;
//		} while (temp != f);
//	}
//}
//void solve(int n, int m)
//{
//	int i, j, k, sum, t;
//	for (i = 1; i <= n; i++)
//		if (!dfn[i])
//			Tarjan(i);
//	for (i = 1; i <= n; i++)
//	{
//		for (j = head[i]; j != -1; j = edge[j].next)
//		{
//			t = edge[j].to;
//			if (belong[i] != belong[t])
//			{
//				in[belong[t]]++;
//				out[belong[i]]++;
//			}
//		}
//	}
//	for (i = 1; i <= Sccc; i++)
//	{
//		if (!in[i])
//			IN++;
//		if (!out[i])
//			OUT++;
//	}
//	if (Sccc == 1)
//		printf("0\n");
//	else
//		printf("%d\n", IN > OUT ? IN : OUT);
//}






//3027  强连通第7题  缩点+数组记录组之间的费用，在所有路径中找到达某点最小的费用即可；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//using namespace std;
//const int MAX = 100000000;
//typedef long long ll;
//int dfn[50010], low[50010];
//int Stack[50010], Instack[50010];
//int head[50010], belong[50010], hd[50010];
//int visit[100010];
//int cost[100010];
//struct node
//{
//	int from;
//	int to;
//	int val;
//	int next;
//};
//struct node edge[100010], e[100010];
//int Sccc, top, tot, Index, cnt;
//void addedge(int x, int y, int z);
//void solve(int n, int m);
//void Tarjan(int f);
//bool comp(int a, int b)
//{
//	return a > b;
//}
//int main()
//{
//	int i, j, k, n, m, a, b, c;
//	while (scanf("%d %d", &n, &m) != EOF)
//	{
//		top = Index = Sccc = cnt = tot = 0;
//		memset(dfn, 0, sizeof(dfn));
//		memset(Instack, 0, sizeof(Instack));
//		memset(head, -1, sizeof(head));
//		memset(hd, -1, sizeof(hd));
//		memset(belong, -1, sizeof(belong));
//		memset(cost, 0, sizeof(cost));
//		for (i = 1; i <= m; i++)
//		{
//			scanf("%d %d %d", &a, &b, &c);
//			addedge(a, b, c);
//		}
//		solve(n, m);
//	}
//	return 0;
//}
//void addedge(int x, int y, int z)
//{
//	edge[cnt].from = x;
//	edge[cnt].to = y;
//	edge[cnt].val = z;
//	edge[cnt].next = head[x];
//	head[x] = cnt++;
//}
//void Tarjan(int f)
//{
//	int i, j, t;
//	Stack[top++] = f;
//	Instack[f] = 1;
//	low[f] = dfn[f] = ++Index;
//	for (i = head[f]; i != -1; i = edge[i].next)
//	{
//		t = edge[i].to;
//		if (!dfn[t])
//		{
//			Tarjan(t);
//			if (low[t] < low[f])
//				low[f] = low[t];
//		}
//		else if (Instack[t] && low[f] > dfn[t])
//			low[f] = dfn[t];
//	}
//	if (low[f] == dfn[f])
//	{
//		Sccc++;
//		do
//		{
//			t = Stack[--top];
//			Instack[t] = 0;
//			belong[t] = Sccc;
//		} while (t != f);
//	}
//}
//void solve(int n, int m)
//{
//	int i, j, k, t;
//	ll sum = 0;
//	for (i = 0; i < n; i++)
//	{
//		if (!dfn[i])
//			Tarjan(i);
//	}
//	for (i = 0; i < n; i++)
//		cost[i] = MAX;
//	for (i = 0; i < n; i++)
//	{
//		for (j = head[i]; j != -1; j = edge[j].next)
//		{
//			if (belong[i] != belong[edge[j].to])
//			{
//				cost[belong[edge[j].to]] = (cost[belong[edge[j].to]] > edge[j].val) ? edge[j].val : cost[belong[edge[j].to]];
//			}
//		}
//	}
//	sort(cost, cost + n, comp);
//	for (i = 0; i < n; i++)
//		if (cost[i] != MAX)
//			sum += cost[i];
//	printf("%lld\n", sum);
//}







//强连通第9题；
//#include <cstdio>
//#include <cstring>
//using namespace std;
//const int MAX = 1000000000;
//struct node
//{
//	int to;
//	int from;
//	int next;
//};
//node edge[50010];
//int dfn[10010], low[10010];
//int Instack[10010], Stack[10010];
//int head[10010];
//int num[10010], belong[10010];
//int out[10010];
//int top, Index, Sccc, cnt;
//void addedge(int x, int y);
//void solve(int n, int m);
//void Tarjan(int f);
//int main()
//{
//	int i, j, k, n, m, a, b, p, q;
//	while (scanf("%d %d", &n, &m) != EOF)
//	{
//		top = Index = cnt = Sccc = 0;
//		memset(head, -1, sizeof(head));
//		memset(Instack, 0, sizeof(Instack));
//		memset(dfn, 0, sizeof(dfn));
//		memset(num, 0, sizeof(num));
//		memset(out, 0, sizeof(out));
//		for (i = 1; i <= m; i++)
//		{
//			scanf("%d %d", &a, &b);
//			addedge(a, b);
//		}
//		solve(n, m);
//	}
//	return 0;
//}
//void addedge(int x, int y)
//{
//	edge[cnt].to = y;
//	edge[cnt].from = x;
//	edge[cnt].next = head[x];
//	head[x] = cnt++;
//}
//void Tarjan(int f)
//{
//	int i, j, t;
//	Stack[top++] = f;
//	Instack[f] = 1;
//	low[f] = dfn[f] = ++Index;
//	for (i = head[f]; i != -1; i = edge[i].next)
//	{
//		t = edge[i].to;
//		if (!dfn[t])
//		{
//			Tarjan(t);
//			if (low[f] > low[t])
//				low[f] = low[t];
//		}
//		else if (Instack[t] && low[f] > dfn[t])
//			low[f] = dfn[t];
//	}
//	if (low[f] == dfn[f])
//	{
//		Sccc++;
//		do
//		{
//			t = Stack[--top];
//			Instack[t] = 0;
//			num[Sccc]++;
//			belong[t] = Sccc;
//		} while (t != f);
//	}
//}
//void solve(int n, int m)
//{
//	int i, j, k, sum = 0;
//	for (i = 1; i <= n; i++)
//	{
//		if (!dfn[i])
//			Tarjan(i);
//	}
//	for (i = 1; i <= n; i++)
//	{
//		for (j = head[i]; j != -1; j = edge[j].next)
//		{
//			if (belong[i] != belong[edge[j].to])
//			{
//				out[belong[i]]++;
//			}
//		}
//	}
//	if (Sccc == 1)
//	{
//		printf("%d\n", n);
//		return;
//	}
//	for (i = 1; i <= Sccc; i++)
//	{
//		if (!out[i])
//			sum++;
//	}
//	if (sum == 1)
//	{
//		for (i = 1; i <= Sccc; i++)
//		{
//			if (!out[i])
//			{
//				printf("%d\n", num[i]);
//				return;
//			}
//		}
//	}
//	else
//		printf("0\n");
//}






//poj 3114  强连通第10题+dij堆优化；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//#include <queue>
//#include <vector>
//using namespace std;
//const int MAX = 100000000;
//int dfn[505], low[505], Instack[505], Stack[505], head[250005], belong[505], hd[250005];
//int dist[505];
//int Sccc, top, Index, cnt, tot;
//struct node
//{
//	int to;
//	int next;
//	int val;
//	node() {}
//	node(int a, int b, int c) : to(a), next(b), val(c) {}
//	bool operator < (const node &p) const
//	{
//		return val > p.val;
//	}
//};
//node edge[250005], e[250005];
//void addedge(int x, int y, int z);
//void add(int x, int y, int z);
//void Tarjan(int f);
//void solve(int n, int m);
//void dijkstra(int begin, int end);
//int main()
//{
//	int i, j, k, n, m, u, a, b, c;
//	while (scanf("%d", &n) != EOF && n)
//	{
//		scanf("%d", &m);
//		top = Index = cnt = Sccc = tot = 0;
//		memset(head, -1, sizeof(head));
//		memset(hd, -1, sizeof(hd));
//		memset(Instack, 0, sizeof(Instack));
//		memset(dfn, 0, sizeof(dfn));
//		for (i = 1; i <= m; i++)
//		{
//			scanf("%d %d %d", &a, &b, &c);
//			addedge(a, b, c);
//		}
//		solve(n, m);
//		putchar('\n');
//	}
//	return 0;
//}
//void addedge(int x, int y, int z)
//{
//	edge[cnt].to = y;
//	edge[cnt].val = z;
//	edge[cnt].next = head[x];
//	head[x] = cnt++;
//}
//void add(int x, int y, int z)
//{
//	e[tot].to = y;
//	e[tot].next = hd[x];
//	e[tot].val = z;
//	hd[x] = tot++;
//}
//void Tarjan(int f)
//{
//	int i, j, t;
//	low[f] = dfn[f] = ++Index;
//	Stack[top++] = f;
//	Instack[f] = 1;
//	for (i = head[f]; i != -1; i = edge[i].next)
//	{
//		t = edge[i].to;
//		if (!dfn[t])
//		{
//			Tarjan(t);
//			if (low[f] > low[t])
//				low[f] = low[t];
//		}
//		else if (Instack[t] && low[f] > dfn[t])
//			low[f] = dfn[t];
//	}
//	if (low[f] == dfn[f])
//	{
//		Sccc++;
//		do
//		{
//			t = Stack[--top];
//			Instack[t] = 0;
//			belong[t] = Sccc;
//		} while (t != f);
//	}
//}
//void solve(int n, int m)
//{
//	int i, j, k, u, a, b, c;
//	for (i = 1; i <= n; i++)
//		if (!dfn[i])
//			Tarjan(i);
//	for (i = 1; i <= n; i++)
//	{
//		for (j = head[i]; j != -1; j = edge[j].next)
//		{
//			if (belong[i] != belong[edge[j].to])
//			{
//				add(belong[i], belong[edge[j].to], edge[j].val);
//			}
//		}
//	}
//	//for (i = 1; i <= n; i++)
//	//	printf("%d ", belong[i]);
//	//putchar('\n');
//	scanf("%d", &k);
//	for (u = 1; u <= k; u++)
//	{
//		scanf("%d %d", &a, &b);
//		dijkstra(belong[a], belong[b]);
//		if (belong[a] == belong[b])
//			printf("0\n");
//		else if (dist[belong[b]] != MAX)
//			printf("%d\n", dist[belong[b]]);
//		else
//			printf("Nao e possivel entregar a carta\n");
//	}
//}
//void dijkstra(int begin, int end)
//{
//	int i, j, k, u;
//	priority_queue<node>q;
//	for (i = 1; i <= Sccc * 2; i++)
//		dist[i] = MAX;
//	node temp(begin, hd[begin], 0), after;
//	dist[begin] = 0;
//	q.push(temp);
//	while (!q.empty())
//	{
//		temp = q.top();
//		q.pop();
//
//		if (dist[temp.to] < temp.val)
//			continue;
//		for (i = hd[temp.to]; i != -1; i = e[i].next)
//		{
//			after.val = e[i].val;
//			after.to = e[i].to;
//			if (dist[after.to] > dist[temp.to] + after.val)
//			{
//				dist[after.to] = dist[temp.to] + after.val;
//				q.push(after);
//			}
//		}
//	}
//}
//下面这个版本以前喜欢用  但是看起来很乱；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//#include <queue>
//#include <vector>
//using namespace std;
//const int MAX = 100000000;
//int dfn[505], low[505], Instack[505], Stack[505], head[250005], belong[505], hd[250005];
//int dist[505];
//int Sccc, top, Index, cnt, tot;
//struct node
//{
//	int to;
//	int next;
//	int val;
//};
//node edge[250005], e[250005];
//typedef pair<int, int>P;
//struct comp
//{
//	bool operator () (P a, P b)
//	{
//		return a.second > b.second;
//	}
//};
//void addedge(int x, int y, int z);
//void add(int x, int y, int z);
//void Tarjan(int f);
//void solve(int n, int m);
//void dijkstra(int begin, int end);
//int main()
//{
//	int i, j, k, n, m, u, a, b, c;
//	while (scanf("%d", &n) != EOF && n)
//	{
//		scanf("%d", &m);
//		top = Index = cnt = Sccc = tot = 0;
//		memset(head, -1, sizeof(head));
//		memset(hd, -1, sizeof(hd));
//		memset(Instack, 0, sizeof(Instack));
//		memset(dfn, 0, sizeof(dfn));
//		for (i = 1; i <= m; i++)
//		{
//			scanf("%d %d %d", &a, &b, &c);
//			addedge(a, b, c);
//		}
//		solve(n, m);
//		putchar('\n');
//	}
//	return 0;
//}
//void addedge(int x, int y, int z)
//{
//	edge[cnt].to = y;
//	edge[cnt].val = z;
//	edge[cnt].next = head[x];
//	head[x] = cnt++;
//}
//void add(int x, int y, int z)
//{
//	e[tot].to = y;
//	e[tot].next = hd[x];
//	e[tot].val = z;
//	hd[x] = tot++;
//}
//void Tarjan(int f)
//{
//	int i, j, t;
//	low[f] = dfn[f] = ++Index;
//	Stack[top++] = f;
//	Instack[f] = 1;
//	for (i = head[f]; i != -1; i = edge[i].next)
//	{
//		t = edge[i].to;
//		if (!dfn[t])
//		{
//			Tarjan(t);
//			if (low[f] > low[t])
//				low[f] = low[t];
//		}
//		else if (Instack[t] && low[f] > dfn[t])
//			low[f] = dfn[t];
//	}
//	if (low[f] == dfn[f])
//	{
//		Sccc++;
//		do
//		{
//			t = Stack[--top];
//			Instack[t] = 0;
//			belong[t] = Sccc;
//		} while (t != f);
//	}
//}
//void solve(int n, int m)
//{
//	int i, j, k, u, a, b, c;
//	for (i = 1; i <= n; i++)
//		if (!dfn[i])
//			Tarjan(i);
//	for (i = 1; i <= n; i++)
//	{
//		for (j = head[i]; j != -1; j = edge[j].next)
//		{
//			if (belong[i] != belong[edge[j].to])
//			{
//				add(belong[i], belong[edge[j].to], edge[j].val);
//			}
//		}
//	}
//	//for (i = 1; i <= n; i++)
//	//	printf("%d ", belong[i]);
//	//putchar('\n');
//	scanf("%d", &k);
//	for (u = 1; u <= k; u++)
//	{
//		scanf("%d %d", &a, &b);
//		dijkstra(belong[a], belong[b]);
//		if (belong[a] == belong[b])
//			printf("0\n");
//		else if (dist[belong[b]] != MAX)
//			printf("%d\n", dist[belong[b]]);
//		else
//			printf("Nao e possivel entregar a carta\n");
//	}
//}
//void dijkstra(int begin, int end)
//{
//	int i, j, k, u;
//	priority_queue<P, vector<P>, comp>q;
//	for (i = 1; i <= Sccc*2; i++)
//		dist[i] = MAX;
//	P temp, after;
//	temp.first = 0;
//	temp.second = begin;
//	dist[begin] = 0;
//	q.push(temp);
//	while (!q.empty())
//	{
//		temp = q.top();
//		q.pop();
//
//		if (dist[temp.second] < temp.first)
//			continue;
//		for (i = hd[temp.second]; i != -1; i = e[i].next)
//		{
//			after.first = e[i].val;
//			after.second = e[i].to;
//			if (dist[after.second] > dist[temp.second] + after.first)
//			{
//				dist[after.second] = dist[temp.second] + after.first;
//				q.push(after);
//			}
//		}
//	}
//}






//1856  并查集；
//#include <cstdio>
//#include <cstring>
//using namespace std;
//int set[10000002], s[10000002];
//int main()
//{
//	int i, j, k, n, m, N, M, a, b, sum, max;
//	while (scanf("%d", &n) != EOF)
//	{
//		if (n == 0)
//		{
//			printf("1\n");
//			continue;
//		}
//		for (i = 0; i < 10000000; i++)
//		{
//			set[i] = i;
//			s[i] = 1;
//		}
//		max = 0;
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d", &a, &b);
//			if (max < a)
//				max = a;
//			if (max < b)
//				max = b;
//			while (a != set[a])
//				a = set[a];
//			while (b != set[b])
//				b = set[b];
//			if (a != b)
//			{
//				if (s[a] > s[b])
//				{
//					set[b] = a;
//					s[a] += s[b];
//				}
//				else
//				{
//					set[a] = b;
//					s[b] += s[a];
//				}
//			}
//		}
//		sum = 0;
//		for (i = 1; i <= max; i++)
//		{
//			if (sum < s[i])
//				sum = s[i];
//		}
//		printf("%d\n", sum);
//	}
//	return 0;
//}






//1102 并查集；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//struct node
//{
//	int val;
//	int to;
//	int from;
//};
//node d[10001];
//bool comp(node a, node b)
//{
//	return a.val < b.val;
//}
//int main()
//{
//	int i, j, k, u, n, m, a, b, c, ar[110][110], set[110], flag;
//	long long sum;
//	while (scanf("%d", &n) != EOF)
//	{
//		c = 0;
//		for (i = 1; i <= n; i++)
//		{
//			for (j = 1; j <= n; j++)
//			{
//				scanf("%d", &ar[i][j]);
//			}
//		}
//		scanf("%d", &k);
//		for (u = 1; u <= k; u++)
//		{
//			scanf("%d %d", &a, &b);
//			ar[a][b] = 0;
//			ar[b][a] = 0;
//		}
//		for (i = 1; i <= n; i++)
//		{
//			for (j = i; j <= n; j++)
//			{
//				d[c].val = ar[i][j];
//				d[c].from = i;
//				d[c++].to = j;
//			}
//		}
//		for (i = 0; i <= n; i++)
//			set[i] = i;
//		sum = 0;
//		flag = 0;
//		sort(d, d + c, comp);
//		for (i = 0; i < c; i++)
//			printf("%d %d %d\n", d[i].val, d[i].from, d[i].to);
//		for (i = 0; i < c; i++)
//		{
//			a = d[i].from;
//			b = d[i].to;
//			while (a != set[a])
//				a = set[a];
//			while (b != set[b])
//				b = set[b];
//			if (a != b)
//			{
//				set[b] = a;
//				sum += d[i].val;
//				flag++;
//			}
//			if (flag == n - 1)
//			{
//				printf("%lld\n", sum);
//				break;
//			}
//		}
//	}
//	return 0;
//}






//1814   2-set；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//int head[40010];
//int Stack[40010];
//int cnt, top, n, m;
//struct node
//{
//	int from;
//	int to;
//	int next;
//};
//node edge[40010];
//int set[40010];
//void addedge(int x, int y);
//bool judge();
//bool dfs(int n);
//int main()
//{
//	int i, j, k, u, a, b, c;
//	while (scanf("%d %d", &n, &m) != EOF)
//	{
//		cnt = 0;
//		memset(head, -1, sizeof(head));
//		for (u = 1; u <= m; u++)
//		{
//			scanf("%d %d", &a, &b);
//			a -= 1;
//			b -= 1;
//			addedge(a, b ^ 1);
//			addedge(b, a ^ 1);
//		}
//		memset(set, 0, sizeof(set));
//		if (judge())
//		{
//			for (i = 0; i < 2 * n; i++)
//			{
//				if (set[i])
//					printf("%d\n", i + 1);
//			}
//		}
//		else
//			printf("NIE\n");
//	}
//	return 0;
//}
//void addedge(int x, int y)
//{
//	edge[cnt].from = x;
//	edge[cnt].to = y;
//	edge[cnt].next = head[x];
//	head[x] = cnt++;
//}
//bool judge()
//{
//	int i, j, k;
//	for (i = 0; i < 2 * n; i++)
//	{
//		if (set[i] || set[i ^ 1])
//			continue;
//		top = 0;
//		if (!dfs(i))
//		{
//			for (j = 0;j < top; j++)
//				set[Stack[j]] = 0;
//			top = 0;
//			if (!dfs(i ^ 1))
//				return false;
//		}
//	}
//	return true;
//}
//bool dfs(int n)
//{
//	int i, j, k, t;
//	if (set[n])
//		return true;
//	if (set[n ^ 1])
//		return false;
//	Stack[top++] = n;
//	set[n] = 1;
//	for (i = head[n]; i != -1; i = edge[i].next)
//	{
//		t = edge[i].to;
//		if (!dfs(t))
//		{
//			return false;
//		}
//	}
//	return true;
//}





//1384   差分约束；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <cstdlib>
//#include <deque>
//using namespace std;
//const int MAX = 100000000;
//const int MIN = -100000000;
//int visit[50010], head[100010], dist[50010];
//struct node
//{
//	int val;
//	int next;
//	int to;
//};
//node edge[400010];
//int Max, Min, cnt, top;
//void addedge(int x, int y, int z);
//int SPFA();
//int main()
//{
//	int i, j, k, u, n, m, a, b, c;
//	while (scanf("%d", &n) != EOF)
//	{
//		Max = MIN;
//		Min = MAX;
//		memset(head, -1, sizeof(head));
//		cnt = 0;
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d %d", &a, &b, &c);
//			if (Max < b)
//				Max = b;
//			if (Min > a)
//				Min = a;
//			addedge(a - 1, b, c);
//		}
//		for (m = Min; m <= Max; m++)
//		{
//			addedge(m - 1, m, 0);
//			addedge(m, m - 1, -1);
//		}
//		printf("%d\n", SPFA());
//	}
//	return 0;
//}
//void addedge(int x, int y, int z)
//{
//	edge[cnt].to = y;
//	edge[cnt].val = z;
//	edge[cnt].next = head[x];
//	head[x] = cnt++;
//}
//int SPFA()
//{
//	int i, j, u, t, v;
//	deque<int>q;
//	memset(visit, 0, sizeof(visit));
//	memset(dist, -1, sizeof(dist));
//	dist[Min - 1] = 0;
//	q.push_back(Min - 1);
//	visit[Min - 1] = 1;
//	while (!q.empty())
//	{
//		t = q.front();
//		q.pop_front();
//		visit[t] = 0;
//		for (i = head[t]; i != -1; i = edge[i].next)
//		{
//			u = edge[i].to;
//			v = edge[i].val;
//			if (dist[u] < dist[t] + v)
//			{
//				dist[u] = dist[t] + v;
//				if (!visit[u])
//				{
//					visit[u]++;
//					if (!q.empty() && dist[u] > dist[q.front()])
//						q.push_front(u);
//					else
//						q.push_back(u);
//				}
//			}
//		}
//	}
//	return dist[Max];
//}





//1529 差分约束第2题
//ar[i]表示第i个时刻需要的人数
//num[i]表示第i个时刻有多少个人报名
//x[i]表示第i个时刻实际雇佣了多少人
//s[i]表示前i个时刻的实际雇佣了多少个人 s[i]=  x[1] + x[2] +...+x[i]
//则x[i] + x[i-1] + x[i-2] + ... + x[i-7] >= ar[i]
//则s[i] - s[i-8] >= ar[i]
//且0 <= s[i] - s[i-1] <= num[i]
//那么问题来了 如果i <= 8 怎么办？
//可以这样表示s[i] + s[24] - s[i+16] >= ar[i]
//好了 这样约束条件就列举完了, 只需要把所有的条件改成 >= 的形式，并且常数在右边就行了；
//if(i >= 8)
//	s[i] - s[i-8] >= ar[i]
//else
//	s[i] -s[i+16]  >= ar[i] + ar[24]
//s[i] - s[i-1] >= 0
//s[i-1] - s[i] >= -num[i]
//这里在循环的时候没有0，24  和24，0这两个边，所以补上s[24] - s[0] >= s[24], s[24] - s[0] <= s[24];
//最后发现，其实s[24]并不知道，枚举其值为0~24即可，这里可以用二分查找，更快；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <deque>
//#include <algorithm>
//using namespace std;
//const int MAX = 100000000;
//int visit[30], dist[30], head[10000], ar[30], num[30], in[30];
//struct node
//{
//	int to;
//	int next;
//	int val;
//};
//node edge[10000];
//int cnt;
//bool SPFA();
//bool judge(int M);
//void addedge(int x, int y, int z);
//int main()
//{
//	int i, j, k, u, n, m, a, b, c, l, r, h, res;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			memset(head, -1, sizeof(head));
//			memset(num, 0, sizeof(num));
//			memset(ar, 0, sizeof(ar));
//			cnt = 0;
//			for (i = 1; i <= 24; i++)
//			{
//				scanf("%d", &ar[i]);
//			}
//			scanf("%d", &k);
//			for (u = 1; u <= k; u++)
//			{
//				scanf("%d", &a);
//				num[a + 1]++;
//			}
//			l = 0;
//			r = k;
//			res = -1;
//			while (l <= r)
//			{
//				h = (l + r) / 2;
//				if (judge(h))
//				{
//					r = h - 1;
//					res = h;
//				}
//				else
//					l = h + 1;
//			}
//			if (res == -1)
//				printf("No Solution\n");
//			else
//				printf("%d\n", res);
//		}
//	}
//	return 0;
//}
//void addedge(int x, int y, int z)
//{
//	edge[cnt].to = y;
//	edge[cnt].next = head[x];
//	edge[cnt].val = z;
//	head[x] = cnt++;
//}
//bool judge(int M)
//{
//	int i, j, t;
//	memset(head, -1, sizeof(head));
//	cnt = 0;
//	for (i = 1; i <= 24; i++)
//	{
//		addedge(i, i - 1, -num[i]);
//		addedge(i - 1, i, 0);
//		if (i >= 8)
//			addedge(i - 8, i, ar[i]);
//		else
//			addedge(i + 16, i, ar[i] - M);
//	}
//	addedge(0, 24, M);
//	addedge(24, 0, -M);
//	return SPFA();
//}
//bool SPFA()
//{
//	int i, j, now, after, u, v, t;
//	deque<int>q;
//	memset(visit, 0, sizeof(visit));
//	memset(in, 0, sizeof(in));
//	for (i = 0; i <= 24; i++)
//		dist[i] = -MAX;
//	dist[0] = 0;
//	visit[0] = 1;
//	in[0] = 1;
//	q.push_back(0);
//	while (!q.empty())
//	{
//		now = q.front();
//		q.pop_front();
//		visit[now] = 0;
//		for (i = head[now]; i != -1; i = edge[i].next)
//		{
//			t = edge[i].to;
//			v = edge[i].val;
//			if (dist[t] < dist[now] + v)
//			{
//				dist[t] = dist[now] + v;
//				if (!visit[t])
//				{
//					visit[t] = 1;
//					if (++in[t] > 24)
//						return false;
//					if (!q.empty() && dist[t] > dist[q.front()])
//						q.push_front(t);
//					else
//						q.push_back(t);
//				}
//			}
//		}
//	}
//	return true;
//}








//6度分离，强数据版；
/**
Problem C Friends

题意:给n个人，有n-1个朋友关系，形成一棵树，如果两个人能够通过不超过5个人可以联系到，那么那两个人也是朋友,问你每个人有多少个朋友,
比如(1-2-3-4-5-6-7-8)，1可以联系到2 3 4 5 6 7,所以1有6个朋友

思路：先对树进行dfs搜索形成有向树，根节点为1(任意),在设son[o][i]表示以o为节点在通过恰好i个人联系可以成为朋友的个数，只计算在根为o的子树中
的结果，那么设p1,p2,p3,p4,p5,p6为o的一级祖先、二级祖先、..六级祖先那么对于节点o来说，
不通过p1能成为朋友的个数为 sigma {son[o][i] | 0 <= i <= 6}， 计算的是包含o节点的
不通过p2而通过p1能成为朋友的个数为 sigma {son[p1][i] | 0 <= i <= 5}
但是这里再次计算了经过o的情况， 所以需要减去 sigma {son[o][i] | 0 <= i <= 4}

同理需要经过Pj祖先的时候， 总个数为 sigma {son[Pj][i] | 0 <= i <= 6 - j}
但是不能再通过Pj-1, 所以减去 sigma {son[Pj-1][i] | 0 <= i <= 6 - j - 1}

所有pj的结果加起来再减去1就是答案了， 因为把o节点自己计算了在内
**/
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <cmath>
//#include <cctype>
//#include <algorithm>
//#include <queue>
//#include <map>
//#include <vector>
//#include <deque>
//using namespace std;
//const int MIN = -100000000;
//const int MAX = 100000000;
//typedef long long ll;
//vector<int>G[100010];
//int pre[100010], node[100010][7];
//void dfs(int *fa, int n);
//int main()
//{
//	int i, j, k, u, n, m, a, b, c, res, doudou;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			memset(node, 0, sizeof(node));
//			scanf("%d", &k);
//			for (i = 0; i <= k; i++)
//			{
//				G[i].clear();
//				node[i][0] = 1;
//			}
//			for (i = 1; i < k; i++)
//			{
//				scanf("%d %d", &a, &b);
//				G[a].push_back(b);
//				G[b].push_back(a);
//			}
//			int fa[] = { 0, 0, 0, 0, 0, 0 };
//			dfs(fa, 1);
//			res = 0;
//			for (i = 1; i <= k; i++)
//			{
//				res = 0;
//				for (j = 1; j <= 6; j++)
//					res += node[i][j];
//				c = i;
//				for (u = 1; u <= 6; u++)
//				{
//					b = c;
//					c = pre[c];
//					if (c == 0)
//						break;
//					for (j = 0; j <= 6 - u; j++)
//						res += node[c][j];
//					for (j = 0; j <= 6 - u - 1; j++)
//						res -= node[b][j];
//				}
//				if (i == 1)
//					printf("Case #%d:\n", m);
//				printf("%d\n", res);
//			}
//		}
//	}
//	return 0;
//}
//void dfs(int *fa, int n)
//{
//	int i, j, k;
//	pre[n] = fa[5];
//	for (i = 0; i <= 5; i++)
//	{
//		node[fa[i]][6 - i]++;
//	}
//	int f[] = { fa[1], fa[2], fa[3], fa[4], fa[5], n };
//	for (i = 0; i < G[n].size(); i++)
//	{
//		if (G[n][i] != fa[5])
//		{
//			dfs(f, G[n][i]);
//		}
//	}
//}






//spfa是判断是否成环，如果求最短路就是判断的负环（因为该环中的点在无限的更新最短距离），如果求最长路就是判断正环（因为该环中的点在无限的更新最长距离）；
//至于为什么一定要入队次数大于顶点数，因为bfs在第一次入到环时并不认识她，为了防止是所有顶点都在环中（反正遇到了正/负环会一直更新下去肯定会到顶点数的），所以必须要入队次数大于顶点数（这就是为什么bfs判环比dfs慢，dfs判断的是一个点是否在一条路径中出现超过1次，所以在第一次遇到环时就能认识她）
//1531   差分约束第6题  SPFA()判环，因为是把所有条件转化为求最短路 所以判负环（如果把所有条件转化为求最长路，就是判正环）；
//最短路版
//差分系统<=;
//算出解的最大值；
//差分约束系统的解法利用到了单源最短路径问题中的三角形不等式。即对于任何一条边u -> v，都有：
//d(v) <= d(u) + w(u, v)
//其中d(u)和d(v)是从源点分别到点u和点v的最短路径的权值，w(u, v)是边u->v的权值。
//显然以上不等式就是d(v) - d(u) <= w(u, v)
//另外还要有一个总源点，到所有点的距离为0， 防止图不连通；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//#include <cctype>
//#include <queue>
//#include <deque>
//#include <vector>
//#include <map>
//using namespace std;
//const int MAX = 100000000;
//struct node
//{
//	int to;
//	int next;
//	int val;
//};
//node edge[500];
//int head[500], dist[500], visit[500], in[500];
//int cnt, n;
//void addedge(int x, int y, int z);
//bool SPFA(int s);
//int main()
//{
//	int i, j, k, m, a, b, c, u, v;
//	char ch, s[5];
//	while (scanf("%d", &n) != EOF && n)
//	{
//		scanf("%d", &m);
//		cnt = 0;
//		memset(head, -1, sizeof(head));
//		for (i = 1; i <= m; i++)
//		{
//			scanf("%d %d %s %d", &u, &v, s, &k);
//			if (s[0] == 'g')
//			{
//				addedge(u + v, u - 1, -k - 1);
//			}
//			else
//			{
//				addedge(u - 1, u + v, k - 1);
//			}
//		}
//		int st = n + 10;
//		for (i = 0; i <= n; i++)
//			addedge(st, i, 0);
//		if (SPFA(st))
//		{
//			printf("lamentable kingdom\n");
//		}
//		else
//		{
//			printf("successful conspiracy\n");
//		}
//	}
//	return 0;
//}
//void addedge(int x, int y, int z)
//{
//	edge[cnt].to = y;
//	edge[cnt].val = z;
//	edge[cnt].next = head[x];
//	head[x] = cnt++;
//}
//bool SPFA(int s)
//{
//	int i, j, k, u, v;
//	deque<int>q;
//	for (i = 0; i <= n + 1; i++)
//		dist[i] = MAX;
//	memset(visit, 0, sizeof(visit));
//	memset(in, 0, sizeof(in));
//	dist[s] = 0;
//	visit[s] = 1;
//	q.push_back(s);
//	while (!q.empty())
//	{
//		u = q.front();
//		q.pop_front();
//		visit[u] = 0;
//		for (i = head[u]; i != -1; i = edge[i].next)
//		{
//			v = edge[i].to;
//			if (dist[v] > dist[u] + edge[i].val)
//			{
//				dist[v] = dist[u] + edge[i].val;
//				if (!visit[v])
//				{
//					visit[v] = 1;
//					if (++in[v] > n + 1)
//						return 0;
//					if (!q.empty() && dist[v] < dist[q.front()])
//						q.push_front(v);
//					else
//						q.push_back(v);
//				}
//			}
//		}
//	}
//	return 1;
//}
//最长路版
//差分系统>=；
//算出解的最小值；
//总源点到所有点的距离仍为0，dist初始化为最小值，if(dist[v] <dist[u] + edge[i].val)      dist[v] = dist[u] + edge[i].val
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//#include <cctype>
//#include <queue>
//#include <deque>
//#include <vector>
//#include <map>
//using namespace std;
//const int MAX = 100000000;
//struct node
//{
//	int to;
//	int next;
//	int val;
//};
//node edge[500];
//int head[500], dist[500], visit[500], in[500];
//int cnt, n;
//void addedge(int x, int y, int z);
//bool SPFA(int s);
//int main()
//{
//	int i, j, k, m, a, b, c, u, v;
//	char ch, s[5];
//	while (scanf("%d", &n) != EOF && n)
//	{
//		scanf("%d", &m);
//		cnt = 0;
//		memset(head, -1, sizeof(head));
//		for (i = 1; i <= m; i++)
//		{
//			scanf("%d %d %s %d", &u, &v, s, &k);
//			if (s[0] == 'g')
//			{
//				addedge(u -1, u +v, k+1);
//			}
//			else
//			{
//				addedge(u+v, u-1, -k + 1);
//			}
//		}
//		int st = n+10;
//		for (i = 0; i <= n; i++)
//			addedge(st, i, 0);
//		if (SPFA(st))
//		{
//			printf("lamentable kingdom\n");
//		}
//		else
//		{
//			printf("successful conspiracy\n");
//		}
//	}
//	return 0;
//}
//void addedge(int x, int y, int z)
//{
//	edge[cnt].to = y;
//	edge[cnt].val = z;
//	edge[cnt].next = head[x];
//	head[x] = cnt++;
//}
//bool SPFA(int s)
//{
//	int i, j, k, u, v;
//	deque<int>q;
//	for (i = 0; i <= n + 1; i++)
//		dist[i] = -MAX;
//	memset(visit, 0, sizeof(visit));
//	memset(in, 0, sizeof(in));
//	dist[s] = 0;
//	visit[s] = 1;
//	q.push_back(s);
//	while (!q.empty())
//	{
//		u = q.front();
//		q.pop_front();
//		visit[u] = 0;
//		for (i = head[u]; i != -1; i = edge[i].next)
//		{
//			v = edge[i].to;
//			if (dist[v] < dist[u] + edge[i].val)
//			{
//				dist[v] = dist[u] + edge[i].val;
//				if (!visit[v])
//				{
//					visit[v] = 1;
//					if (++in[v] > n + 1)
//						return 0;
//					if (!q.empty() && dist[v] > dist[q.front()])
//						q.push_front(v);
//					else
//						q.push_back(v);
//				}
//			}
//		}
//	}
//	return 1;
//}






//1534  差分约束第7题，  最长路；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//#include <cctype>
//#include <queue>
//#include <deque>
//#include <vector>
//#include <map>
//using namespace std;
//const int MAX = 100000000;
//const int MAXN = 100010;
//bool SPFA();
//void addedge(int x, int y, int z);
//int ar[MAXN], head[MAXN], visit[MAXN], in[MAXN], dist[MAXN];
//struct node
//{
//	int to;
//	int next;
//	int val;
//};
//node edge[MAXN * 4];
//int cnt, n;
//int main()
//{
//	int i, j, k, u, m, a, b, c, cas = 1;
//	char s[5];
//	while (scanf("%d", &n) != EOF && n)
//	{
//		cnt = 0;
//		memset(head, -1, sizeof(head));
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &ar[m]);
//		}
//		while (scanf("%s", s) != NULL && strcmp(s, "#"))
//		{
//			scanf("%d %d", &a, &b);
//			if (s[0] == 'S' && s[2] == 'S')
//				addedge(b, a, 0);
//			if (s[0] == 'S' && s[2] == 'F')
//				addedge(b, a, ar[b]);
//			if (s[0] == 'F' && s[2] == 'S')
//				addedge(b, a, -ar[a]);
//			if (s[0] == 'F' && s[2] == 'F')
//				addedge(b, a, ar[b] - ar[a]);
//		}
//		for (i = 1; i <= n; i++)
//			addedge(0, i, 0);
//		printf("Case %d:\n", cas++);
//		if (SPFA())
//		{
//			for (i = 1; i <= n; i++)
//				printf("%d %d\n", i, dist[i]);
//		}
//		else
//			printf("impossible\n");
//		printf("\n");
//	}
//	return 0;
//}
//void addedge(int x, int y, int z)
//{
//	edge[cnt].to = y;
//	edge[cnt].next = head[x];
//	edge[cnt].val = z;
//	head[x] = cnt++;
//}
//bool SPFA()
//{
//	int i, j, k, u, v, t;
//	deque<int>q;
//	memset(visit, 0, sizeof(visit));
//	memset(in, 0, sizeof(in));
//	for (i = 1; i <= n; i++)
//		dist[i] = -MAX;
//	dist[0] = 0;
//	visit[0] = 1;
//	q.push_back(0);
//	while (!q.empty())
//	{
//		u = q.front();
//		q.pop_front();
//		visit[u] = 0;
//		for (i = head[u]; i != -1; i = edge[i].next)
//		{
//			v = edge[i].to;
//			if (dist[v] < dist[u] + edge[i].val)
//			{
//				dist[v] = dist[u] + edge[i].val;
//				if (!visit[v])
//				{
//					visit[v] = 1;
//					if (++in[v] > n + 1)
//						return false;
//					if (!q.empty() && dist[v] > dist[q.front()])
//						q.push_front(v);
//					else
//						q.push_back(v);
//				}
//			}
//		}
//	}
//	return true;
//}





//1535  双SPFA；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//#include <cctype>
//#include <queue>
//#include <deque>
//#include <vector>
//#include <map>
//using namespace std;
//typedef long long ll;
//const int MAX = 100000000;
//const int MAXN = 1000010;
//struct node
//{
//	int to;
//	int next;
//	int val;
//};
//node edge[4 * MAXN], e[4 * MAXN];
//int visit[MAXN], dist[MAXN], head[MAXN], hd[MAXN], in[MAXN];
//int cnt, Count, P, Q;
//void addedge(int x, int y, int z);
//void add(int x, int y, int z);
//void SPFA1();
//void SPFA2();
//int main()
//{
//	int i, j, k, n, m, u, a, b, c;
//	ll sum;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			memset(head, -1, sizeof(head));
//			memset(hd, -1, sizeof(hd));
//			cnt = Count = 0;
//			scanf("%d %d", &P, &Q);
//			for (u = 1; u <= Q; u++)
//			{
//				scanf("%d %d %d", &a, &b, &c);
//				addedge(a, b, c);
//				add(b, a, c);
//			}
//			SPFA1();
//			sum = 0;
//			for (i = 1; i <= P; i++)
//			{
//				sum += dist[i];
//			}
//			SPFA2();
//			for (i = 1; i <= P; i++)
//			{
//				sum += dist[i];
//			}
//			printf("%lld\n", sum);
//		}
//	}
//	return 0;
//}
//void addedge(int x, int y, int z)
//{
//	edge[cnt].to = y;
//	edge[cnt].val = z;
//	edge[cnt].next = head[x];
//	head[x] = cnt++;
//}
//void add(int x, int y, int z)
//{
//	e[Count].to = y;
//	e[Count].val = z;
//	e[Count].next = hd[x];
//	hd[x] = Count++;
//}
//void SPFA1()
//{
//	int i, j, k, u, v, t;
//	deque<int>q;
//	memset(visit, 0, sizeof(visit));
//	memset(in, 0, sizeof(in));
//	for (i = 1; i <= P; i++)
//		dist[i] = MAX;
//	dist[1] = 0;
//	visit[1] = 1;
//	q.push_back(1);
//	while (!q.empty())
//	{
//		u = q.front();
//		q.pop_front();
//		visit[u] = 0;
//		for (i = head[u]; i != -1; i = edge[i].next)
//		{
//			v = edge[i].to;
//			if (dist[v] > dist[u] + edge[i].val)
//			{
//				dist[v] = dist[u] + edge[i].val;
//				if (!visit[v])
//				{
//					visit[v] = 1;
//					if (++in[v] > P)
//						return;
//					if (!q.empty() && dist[v] < dist[q.front()])
//						q.push_front(v);
//					else
//						q.push_back(v);
//				}
//			}
//		}
//	}
//}
//void SPFA2()
//{
//	int i, j, k, u, v, t;
//	deque<int>q;
//	memset(visit, 0, sizeof(visit));
//	memset(in, 0, sizeof(in));
//	for (i = 1; i <= P; i++)
//		dist[i] = MAX;
//	dist[1] = 0;
//	visit[1] = 1;
//	q.push_back(1);
//	while (!q.empty())
//	{
//		u = q.front();
//		q.pop_front();
//		visit[u] = 0;
//		for (i = hd[u]; i != -1; i = e[i].next)
//		{
//			v = e[i].to;
//			if (dist[v] > dist[u] + e[i].val)
//			{
//				dist[v] = dist[u] + e[i].val;
//				if (!visit[v])
//				{
//					visit[v] = 1;
//					if (++in[v] > P)
//						return;
//					if (!q.empty() && dist[v] < dist[q.front()])
//						q.push_front(v);
//					else
//						q.push_back(v);
//				}
//			}
//		}
//	}
//}





//1317   一道bfs勉强c++过了
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <queue>
//#include <deque>
//#include <algorithm>
//using namespace std;
//const int MAX = 100000000;
//const int MAXN = 110;
//struct node
//{
//	int to;
//	int val;
//	int next;
//	//bool operator < (const node &p) const
//	//{
//	//    return val > p.val;
//	//}
//};
//struct point
//{
//	int to;
//	int val;
//	bool operator < (const point &p) const
//	{
//		return val > p.val;
//	}
//};
//node edge[MAXN * 100];
//int head[MAXN], visit[MAXN][10010];
//bool bfs();
//void addedge(int x, int y, int z);
//int ar[MAXN][MAXN], va[MAXN];
//int cnt, n;
//int main()
//{
//	int i, j, k, u, m, a, b, c;
//	while (scanf("%d", &n) != EOF && n != -1)
//	{
//		memset(ar, 0, sizeof(ar));
//		memset(head, -1, sizeof(head));
//		cnt = 0;
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d", &a, &b);
//			va[m] = a;
//			for (i = 1; i <= b; i++)
//			{
//				scanf("%d", &c);
//				ar[m][c] = 1;
//			}
//		}
//		for (i = 1; i <= n; i++)
//		{
//			for (j = 1; j <= n; j++)
//			{
//				if (i == j)
//					continue;
//				if (ar[i][j])
//				{
//					addedge(i, j, va[j]);
//				}
//			}
//		}
//		if (bfs())
//			printf("winnable\n");
//		else
//			printf("hopeless\n");
//	}
//	return 0;
//}
//void addedge(int x, int y, int z)
//{
//	edge[cnt].to = y;
//	edge[cnt].val = z;
//	edge[cnt].next = head[x];
//	head[x] = cnt++;
//}
//bool bfs()
//{
//	int i, j, k, u, v, t;
//	point now, after;
//	priority_queue<point>q;
//	memset(visit, 0, sizeof(visit));
//	visit[1][100] = 1;
//	now.to = 1;
//	now.val = 100;
//	q.push(now);
//	while (!q.empty())
//	{
//		now = q.top();
//		q.pop();
//		if (now.to == n && now.val > 0)
//			return true;
//		for (i = head[now.to]; i != -1; i = edge[i].next)
//		{
//			after.to = edge[i].to;
//			after.val = edge[i].val + now.val;
//			if (after.val <= 0)
//				continue;
//			if (visit[after.to][after.val])
//				continue;
//			q.push(after);
//			visit[after.to][after.val] = 1;
//		}
//	}
//	return false;
//}








//4857   拓补排序， 反向建图 小的在大的前面且小的数优先级高
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//#include <cctype>
//#include <queue>
//#include <deque>
//#include <vector>
//#include <map>
//using namespace std;
//const int MAX = 100000000;
//const int MAXN = 30010;
//struct node
//{
//	int to;
//	int next;
//};
//node edge[100010];
//int head[MAXN], in[MAXN];
//int cnt, N, M;
//void tuobu();
//void addedge(int x, int y);
//int main()
//{
//	int i, j, k, u, n, m, a, b, c;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			memset(in, 0, sizeof(in));
//			memset(head, -1, sizeof(head));
//			cnt = 0;
//			scanf("%d %d", &N, &M);
//			for (u = 1; u <= M; u++)
//			{
//				scanf("%d %d", &a, &b);
//				addedge(b, a);
//				in[a]++;
//			}
//			tuobu();
//			printf("\n");
//		}
//	}
//	return 0;
//}
//void addedge(int x, int y)
//{
//	edge[cnt].to = y;
//	edge[cnt].next = head[x];
//	head[x] = cnt++;
//}
//void tuobu()
//{
//	vector<int>ar;
//	ar.clear();
//	int i, j, k, u, v, sta = 0;
//	priority_queue<int>q;
//	for (i = 1; i <= N; i++)
//		if (in[i] == 0)
//		{
//			in[i]--;
//			q.push(i);
//		}
//	while (!q.empty())
//	{
//		u= q.top();
//		q.pop();
//		ar.push_back(u);
//		for (i = head[u]; i != -1; i = edge[i].next)
//		{
//			in[edge[i].to]--;
//			if (in[edge[i].to] == 0)
//			{
//				q.push(edge[i].to);
//			}
//		}
//	}
//	for (i = ar.size() - 1; i >= 0; i--)
//	{
//		if (i != ar.size() - 1)
//			putchar(' ');
//		printf("%d", ar[i]);
//	}
//}






//1285  拓补排序第2题， 字典序；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//#include <queue>
//#include <vector>
//using namespace std;
//const int MAX = 100000000;
//const int MAXN = 510;
//struct node
//{
//	int to;
//	int next;
//	bool operator < (const node &p) const
//	{
//		return to > p.to;
//	}
//};
//node edge[MAXN * 10];
//int head[MAXN], in[MAXN];
//int cnt, N;
//void addedge(int x, int y);
//void tuobu();
//int main()
//{
//	int i, j, k, u, n, m, a, b;
//	while (scanf("%d %d", &N, &m) != EOF)
//	{
//		memset(head, -1, sizeof(head));
//		memset(in, 0, sizeof(in));
//		cnt = 0;
//		for (u = 1; u <= m; u++)
//		{
//			scanf("%d %d", &a, &b);
//			addedge(a, b);
//			in[b]++;
//		}
//		tuobu();
//		putchar('\n');
//	}
//	return 0;
//}
//void addedge(int x, int y)
//{
//	edge[cnt].to = y;
//	edge[cnt].next = head[x];
//	head[x] = cnt++;
//}
//void tuobu()
//{
//	int i, j, k, u, v, t, doudou = 0;
//	node now, after;
//	priority_queue<node>q;
//	for (i = 1; i <= N; i++)
//	{
//		if (in[i] == 0)
//		{
//			now.to = i;
//			now.next = head[i];
//			q.push(now);
//			in[i]--;
//		}
//	}
//	while (!q.empty())
//	{
//		now = q.top();
//		q.pop();
//		if (doudou)
//			putchar(' ');
//		doudou = 1;
//		printf("%d", now.to);
//		for (i = head[now.to]; i != -1; i = edge[i].next)
//		{
//			after = edge[i];
//			in[after.to]--;
//			if (in[after.to] == 0)
//			{
//				q.push(after);
//			}
//		}
//	}
//}




//1811     拓补排序，并查集+是否成环；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//#include <queue>
//#include <vector>
//using namespace std;
//const int MAX = 100000000;
//const int MAXN = 10010;
//vector<int>ar[MAXN * 3];
//int in[MAXN], set[MAXN];
//int l[MAXN], r[MAXN];
//char ss[MAXN];
//int N, M;
//int find(int n);
//int main()
//{
//	int i, j, k, u, a, b, c, n, m, p, e, sum, flag, doudou, t;
//	char s[5];
//	while (scanf("%d %d", &N, &M) != EOF)
//	{
//		sum = N;
//		flag = 0;
//		doudou = 0;
//		memset(in, 0, sizeof(in));
//		for (i = 0; i < N; i++)
//		{
//			set[i] = i;
//			ar[i].clear();
//		}
//		for (m = 0; m < M; m++)
//		{
//			scanf("%d %s %d", &a, s, &b);
//			l[m] = a;
//			r[m] = b;
//			ss[m] = s[0];
//			if (strcmp(s, "=") == 0)
//			{
//				a = find(a);
//				b = find(b);
//				if (a != b)
//				{
//					set[b] = a;
//					sum--;
//				}
//			}
//		}
//		for (i = 0; i < M; i++)
//		{
//			if (ss[i] == '=')
//				continue;
//			else if (ss[i] == '<')
//			{
//				l[i] = find(l[i]);
//				r[i] = find(r[i]);
//				if (l[i] == r[i])
//					flag = 1;
//				ar[r[i]].push_back(l[i]);
//				in[l[i]]++;
//			}
//			else if (ss[i] == '>')
//			{
//				l[i] = find(l[i]);
//				r[i] = find(r[i]);
//				if (l[i] == r[i])
//					flag = 1;
//				ar[l[i]].push_back(r[i]);
//				in[r[i]]++;
//			}
//		}
//		if (flag)
//		{
//			printf("CONFLICT\n");
//		}
//		else
//		{
//			queue<int>q;
//			for (i = 0; i < N; i++)
//			{
//				t = find(i);
//				if (in[i] == 0 && t == i)
//				{
//					q.push(i);
//					sum--;
//				}
//			}
//			while (!q.empty())
//			{
//				if (q.size() > 1)
//					doudou = 1;
//				u = q.front();
//				q.pop();
//				for (i = 0; i < ar[u].size(); i++)
//				{
//					in[ar[u][i]]--;
//					if (in[ar[u][i]] == 0)
//					{
//						q.push(ar[u][i]);
//						sum--;
//					}
//				}
//			}
//			if (sum > 0)
//				printf("CONFLICT\n");
//			else if (doudou == 1)
//				printf("UNCERTAIN\n");
//			else
//				printf("OK\n");
//		}
//	}
//	return 0;
//}
//int find(int n)
//{
//	if (set[n] != n)
//		set[n] = find(set[n]);
//	return set[n];
//}






//3357    拓补排序，判断有几条成环的边；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//#include <queue>
//#include <vector>
//using namespace std;
//const int MAX = 100000000;
//const int MAXN = 250;
//int ar[MAXN][MAXN];
//int N, M;
//int main()
//{
//	int i, j, k, u, n, m, a, b, c, sum, cas = 1;
//	while (scanf("%d %d", &N, &M) != EOF && (N || M))
//	{
//		memset(ar, 0, sizeof(ar));
//		sum = 0;
//		for (m = 1; m <= M; m++)
//		{
//			scanf("%d %d", &a, &b);
//			if (ar[b][a] || a == b)
//			{
//				sum++;
//				continue;
//			}
//			if (ar[a][b])
//				continue;
//			ar[a][b] = 1;
//			for (i = 1; i <= N; i++)
//			{
//				if (ar[i][a])
//				{
//					ar[i][b] = 1;
//				}
//				if (ar[b][i])
//				{
//					ar[a][i] = 1;
//				}
//			}
//			for (i = 1; i <= N; i++)
//			{
//				if (ar[i][a])
//				{
//					for (j = 1; j <= N; j++)
//					{
//						if (ar[b][j])
//						{
//							ar[i][j] = 1;
//						}
//					}
//				}
//			}
//		}
//		printf("%d. %d\n", cas++, sum);
//	}
//	return 0;
//}







//3342    拓补排序，判断有没有环；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//#include <queue>
//#include <vector>
//using namespace std;
//const int MAX = 100000000;
//const int MAXN = 110;
//vector<int>G[500];
//int in[MAXN];
//int N, M, Sum;
//int main()
//{
//	int i, j, k, u, n, m, a, b, c;
//	while (scanf("%d %d", &N, &M) != EOF && (N || M))
//	{
//		memset(in, 0, sizeof(in));
//		Sum = N;
//		for (i = 0; i < 500; i++)
//			G[i].clear();
//		for (m = 1; m <= M; m++)
//		{
//			scanf("%d %d", &a, &b);
//			G[a].push_back(b);
//			in[b]++;
//		}
//		queue<int>q;
//		for (i = 0; i < N; i++)
//		{
//			if (in[i] == 0)
//			{
//				q.push(i);
//				Sum--;
//			}
//		}
//		while (!q.empty())
//		{
//			u = q.front();
//			q.pop();
//			for (i = 0; i < G[u].size(); i++)
//			{
//				in[G[u][i]]--;
//				if (in[G[u][i]] == 0)
//				{
//					Sum--;
//					q.push(G[u][i]);
//				}
//			}
//		}
//		if (Sum == 0)
//			printf("YES\n");
//		else
//			printf("NO\n");
//	}
//	return 0;
//}







//1166    线段树第一题，求区间和，一定要记住，数组是元素个数的4倍！；
//#include <cstdio>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//const int MAX = 100000000;
//int ar[50010*4];
//int sa[50010*4];
//void build(int root, int begin, int end);
//void update(int root, int begin, int end, int index, int val);
//int query(int root, int begin, int end, int b, int e);
//int main()
//{
//	int i, j, k, u, n, m, a, b, c, d, doudou;
//	char s[10];
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			doudou = 0;
//			memset(ar, 0, sizeof(ar));
//			scanf("%d", &k);
//			for (u = 1; u <= k; u++)
//			{
//				scanf("%d", &ar[u]);
//			}
//			memset(sa, 0, sizeof(sa));
//			build(1, 1, k);
//			scanf("%s", s);
//			while (strcmp(s, "End"))
//			{
//				if (strcmp(s, "Add") == 0)
//				{
//					scanf("%d %d", &a, &b);
//					update(1, 1, k, a, b);
//				}
//				else if (strcmp(s, "Sub") == 0)
//				{
//					scanf("%d %d", &a, &b);
//					update(1, 1, k, a, -b);
//				}
//				else
//				{
//					scanf("%d %d", &a, &b);
//					if (doudou == 0)
//						printf("Case %d:\n", m);
//					doudou = 1;
//					printf("%d\n", query(1, 1, k, a, b));
//				}
//				scanf("%s", s);
//			}
//		}
//	}
//	return 0;
//}
//void build(int root, int begin, int end)
//{
//	if (begin == end)
//		sa[root] = ar[begin];
//	else
//	{
//		build(root * 2, begin, (begin + end) / 2);
//		build(root * 2 + 1, (begin + end) / 2 + 1, end);
//		sa[root] = sa[root * 2] + sa[root * 2 + 1];
//	}
//}
//void update(int root, int begin, int end, int index, int val)
//{
//	if (begin == end)
//	{
//			sa[root] += val;
//		return;
//	}
//	int mid = (begin + end) / 2;
//	if (index <= mid)
//		update(root * 2, begin, mid, index, val);
//	else
//		update(root * 2 + 1, mid + 1, end, index, val);
//	sa[root] = sa[root * 2] + sa[root * 2 + 1];
//}
//int query(int root, int begin, int end, int b, int e)
//{
//	int mid = (begin + end) / 2;
//	int res = 0;
//	if (begin >= b && end <= e)
//		return sa[root];
//
//	if (mid < b)
//		return query(root * 2 + 1, mid + 1, end, b, e);
//	else if (mid >= e)
//		return query(root * 2, begin, mid, b, e);
//	else
//		return query(root * 2, begin, mid, b, e) + query(root * 2 + 1, mid + 1, end, b, e);
//
//}






//1754  线段树第2题，求区间最大值；
//#include <cstdio>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//const int MAX = 100000000;
//int max(int a, int b) { return (a > b) ? a : b; }
//int ar[200000 * 4];
//int sa[200000 * 4];
//void build(int root, int begin, int end);
//void update(int root, int begin, int end, int index, int val);
//int query(int root, int begin, int end, int b, int e);
//int main()
//{
//	int i, j, k, u, n, m, a, b;
//	char s[10];
//	while (scanf("%d %d", &n, &m) != EOF)
//	{
//		memset(ar, 0, sizeof(ar));
//		for (i = 1; i <= n; i++)
//			scanf("%d", &ar[i]);
//		build(1, 1, n);
//		for (u = 1; u <= m; u++)
//		{
//			scanf("%s%d%d", s, &a, &b);
//			if (strcmp(s, "Q") == 0)
//			{
//				printf("%d\n", query(1, 1, n, a, b));
//			}
//			if (strcmp(s, "U") == 0)
//			{
//				update(1, 1, n, a, b);
//			}
//		}
//	}
//	return 0;
//}
//void build(int root, int begin, int end)
//{
//	if (begin == end)
//		sa[root] = ar[begin];
//	else
//	{
//		build(root * 2, begin, (begin + end) / 2);
//		build(root * 2 + 1, (begin + end) / 2 + 1, end);
//		sa[root] = max(sa[root * 2], sa[root * 2 + 1]);
//	}
//}
//void update(int root, int begin, int end, int index, int val)
//{
//	if (begin == end)
//		sa[root] = val;
//	else
//	{
//		int mid = (begin + end) / 2;
//		if (mid < index)
//			update(root * 2 + 1, mid + 1, end, index, val);
//		else
//			update(root * 2, begin, mid, index, val);
//		sa[root] = max(sa[root * 2], sa[root * 2 + 1]);
//	}
//}
//int query(int root, int begin, int end, int b, int e)
//{
//	int mid = (begin + end) / 2;
//	if (begin >= b && end <= e)
//		return sa[root];
//	if (begin > e || end < b)
//		return 0;
//	else
//		return max(query(root * 2, begin, mid, b, e), query(root * 2 + 1, mid + 1, end, b, e));
//}






//线段树，区间更新（标记）；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//const int MAX = 100000000;
//int ar[50000 * 4];
//int sa[50000 * 4];
//int visit[50000 * 4];
//void build(int root, int begin, int end);
//void update(int root, int begin, int end, int b, int e, int val);
//void pushdown(int root);
//int query(int root, int begin, int end, int index);
//int main()
//{
//	int i, j, k, u, n, m, a, b, c, d, e;
//	while (scanf("%d", &n) != EOF)
//	{
//		memset(ar, 0, sizeof(ar));
//		for (i = 1; i <= n; i++)
//		{
//			scanf("%d", &ar[i]);
//		}
//		build(1, 1, n);
//
//		scanf("%d", &k);
//		for (u = 1; u <= k; u++)
//		{
//			scanf("%d", &a);
//			if (a == 2)
//			{
//				scanf("%d", &b);
//				printf("%d\n", query(1, 1, n, b));
//			}
//			else
//			{
//				scanf("%d %d %d %d", &b, &c, &d, &e);
//				update(1, 1, n, b, c, e);
//			}
//		}
//	}
//	return 0;
//}
//void build(int root, int begin, int end)
//{
//	visit[root] = 0;
//	if (begin == end)
//		sa[root] = ar[begin];
//	else
//	{
//		build(root * 2, begin, (begin + end) / 2);
//		build(root * 2 + 1, (begin + end) / 2 + 1, end);
//	}
//}
//void update(int root, int begin, int end, int b, int e, int val)
//{
//	if (begin > e || end < b)
//		return;
//	if (begin >= b && end <= e)
//	{
//		sa[root] += val;
//		visit[root] += val;
//		return;
//	}
//	pushdown(root);
//	int mid = (begin + end) / 2;
//	update(root * 2, begin, mid, b, e, val);
//	update(root * 2 + 1, mid + 1, end, b, e, val);
//
//}
//void pushdown(int root)
//{
//	if (visit[root])
//	{
//		visit[root * 2] += visit[root];
//		visit[root * 2 + 1] += visit[root];
//		sa[root * 2] += visit[root];
//		sa[root * 2 + 1] += visit[root];
//		visit[root] = 0;
//	}
//}
//int query(int root, int begin, int end, int index)
//{
//	if (begin == end)
//	{
//		return sa[root];
//	}
//	pushdown(root);
//	int mid = (begin + end) / 2;
//	if (index <= mid)
//		return query(root * 2, begin, mid, index);
//	else
//		return query(root * 2 + 1, mid + 1, end, index);
//}








//4267   线段树第3题，区间更新，状态压缩；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//const int MAX = 100000000;
//int ar[50000 * 4];
//int sa[50000 * 4][55];
//int visit[50000 * 4];
//int id[11][11];
//int cur;
//void build(int root, int begin, int end);
//void update(int root, int begin, int end, int b, int e, int val);
//void pushdown(int root);
//int query(int root, int begin, int end, int index);
//int main()
//{
//	int cnt = 0;
//	for (int i = 0; i < 11; i++)
//		for (int j = 0; j < i; j++)
//		{
//			id[i][j] = cnt++;
//		}
//	int i, j, k, u, n, m, a, b, c, d, e;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (i = 1; i <= n; i++)
//		{
//			scanf("%d", &ar[i]);
//		}
//		build(1, 1, n);
//		scanf("%d", &k);
//		for (u = 1; u <= k; u++)
//		{
//			scanf("%d", &a);
//			if (a == 2)
//			{
//				scanf("%d", &b);
//				printf("%d\n", query(1, 1, n, b));
//			}
//			else
//			{
//				scanf("%d %d %d %d", &b, &c, &d, &e);
//				cur = id[d][b % d];
//				update(1, 1, n, b, c, e);
//			}
//		}
//	}
//	return 0;
//}
//void build(int root, int begin, int end)
//{
//	visit[root] = 0;
//	for (int i = 0; i < 55; i++)
//		sa[root][i] = 0;
//	if (begin == end)
//		return;
//	else
//	{
//		build(root * 2, begin, (begin + end) / 2);
//		build(root * 2 + 1, (begin + end) / 2 + 1, end);
//	}
//}
//void update(int root, int begin, int end, int b, int e, int val)
//{
//	if (begin > e || end < b)
//		return;
//	if (begin >= b && end <= e)
//	{
//		sa[root][cur] += val;
//		visit[root] = 1;
//		return;
//	}
//	pushdown(root);
//	int mid = (begin + end) / 2;
//	update(root * 2, begin, mid, b, e, val);
//	update(root * 2 + 1, mid + 1, end, b, e, val);
//
//}
//void pushdown(int root)
//{
//	if (visit[root])
//	{
//		for (int i = 0; i < 55; i++)
//		{
//			sa[root * 2][i] += sa[root][i];
//			sa[root * 2 + 1][i] += sa[root][i];
//			sa[root][i] = 0;
//		}
//		visit[root * 2 + 1] = visit[root];
//		visit[root * 2] = visit[root];
//		visit[root] = 0;
//	}
//}
//int query(int root, int begin, int end, int index)
//{
//	if (begin == end)
//	{
//		int res = ar[begin];
//		for (int i = 1; i <= 10; i++)
//			res += sa[root][id[i][index % i]];
//		return res;
//	}
//	pushdown(root);
//	int mid = (begin + end) / 2;
//	if (index <= mid)
//		return query(root * 2, begin, mid, index);
//	else
//		return query(root * 2 + 1, mid + 1, end, index);
//}







//1698  线段树第4题，区间更改值，只用加一个left和right数组，用 val*(right[root] - left[root] + 1)即可；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//const int MAX = 100000000;
//int ar[100000 * 4];
//int sa[100000 * 4];
//int visit[100000 * 4];
//int lef[100000 * 4], rig[100000 * 4];
//int N;
//void build(int root, int begin, int end);
//void update(int root, int begin, int end, int b, int e, int val);
//void pushdown(int root);
//int main()
//{
//	int i, j, k, u, n, m, a, b, c;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &N);
//			build(1, 1, N);
//			scanf("%d", &k);
//			for (u = 1; u <= k; u++)
//			{
//				scanf("%d %d %d", &a, &b, &c);
//				update(1, 1, N, a, b, c);
//			}
//			printf("Case %d: The total value of the hook is %d.\n", m, sa[1]);
//		}
//	}
//	return 0;
//}
//void build(int root, int begin, int end)
//{
//	visit[root] = 0;
//	lef[root] = begin;
//	rig[root] = end;
//	sa[root] = 0;
//	if (begin == end)
//		sa[root] = 1;
//	else
//	{
//		build(root * 2, begin, (begin + end) / 2);
//		build(root * 2 + 1, (begin + end) / 2+1, end);
//		sa[root] = sa[root * 2] + sa[root * 2 + 1];
//	}
//}
//void update(int root, int begin, int end, int b, int e, int val)
//{
//	if (begin > e || end < b)
//		return;
//	if (begin >= b && end <= e)
//	{
//		sa[root] = val*(rig[root] - lef[root] + 1);
//		visit[root] = val;
//		return;
//	}
//	pushdown(root);
//	update(root * 2, begin, (begin + end) / 2, b, e, val);
//	update(root * 2 + 1, (begin + end) / 2+1, end, b, e, val);
//	sa[root] = sa[root * 2] + sa[root * 2 + 1];
//}
//void pushdown(int root)
//{
//	if (visit[root])
//	{
//		visit[root * 2] = visit[root];
//		visit[root * 2 + 1] = visit[root];
//		sa[root * 2] = visit[root] * (rig[root * 2] - lef[root * 2] + 1);
//		sa[root * 2 + 1] = visit[root] * (rig[root * 2 + 1] - lef[root * 2 + 1] + 1);
//		visit[root] = 0;
//	}
//}








//3308  线段树第5题，LCIS；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//const int MAX = 100000000;
////const int max(int a, int b) { return (a > b) ? a : b; };
////const int min(int a, int b) { return (a < b) ? a : b; };
//struct node
//{
//	int l;
//	int r;
//	int mid;
//	int lx;
//	int rx;
//	int mx;
//};
//node edge[100000 * 4];
//int ar[100010];
//void build(int root, int begin, int end);
//void update(int root, int begin, int end, int index, int val);
//int query(int root, int begin, int end, int b, int e);
//void pushup(int root);
//int N, M;
//int main()
//{
//	int i, j, k, u, n, m, a, b, c;
//	char s[5];
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d", &N, &M);
//			for (i = 0; i < N; i++)
//			{
//				scanf("%d", &ar[i]);
//			}
//			build(1, 0, N - 1);
//			 //for(int i=1;i<=30;i++)  
//			 //  printf("%d %d %d %d %d\n",edge[i].l,edge[i].r,edge[i].mx,edge[i].lx,edge[i].rx);  
//			for (u = 1; u <= M; u++)
//			{
//				scanf("%s%d%d", s, &a, &b);
//				if (strcmp(s, "Q") == 0)
//				{
//					printf("%d\n", query(1, 0, N - 1, a, b));
//				}
//				else
//				{
//					ar[a] = b;
//					update(1, 0, N - 1, a, b);
//				}
//			}
//		}
//	}
//	return 0;
//}
//void build(int root, int begin, int end)
//{
//	edge[root].l = begin;
//	edge[root].r = end;
//	edge[root].mid = (begin + end) / 2;
//	if (begin == end)
//	{
//		edge[root].lx = edge[root].rx = edge[root].mx = 1;
//	}
//	else
//	{
//		build(root * 2, begin, edge[root].mid);
//		build(root * 2 + 1, edge[root].mid + 1, end);
//		pushup(root);
//	}
//}
//void pushup(int root)
//{
//	edge[root].lx = edge[root * 2].lx + (((edge[root * 2].r - edge[root * 2].l + 1) == edge[root * 2].lx && ar[edge[root * 2].r] < ar[edge[root * 2 + 1].l]) ? (edge[root * 2 + 1].lx) : 0);
//	edge[root].rx = edge[root * 2 + 1].rx + (((edge[root * 2 + 1].r - edge[root * 2 + 1].l + 1) == edge[root * 2 + 1].rx && ar[edge[root * 2 + 1].l] > ar[edge[root * 2].r]) ? (edge[root * 2].rx) : 0);
//	edge[root].mx = max(max(edge[root * 2].mx, edge[root * 2 + 1].mx), (ar[edge[root * 2].r] < ar[edge[root * 2 + 1].l]) ? (edge[root * 2].rx + edge[root * 2 + 1].lx) : 0);
//}
//void update(int root, int begin, int end, int index, int val)
//{
//	if (begin == end)
//	{
//		edge[root].lx = edge[root].rx = edge[root].mx = 1;
//	}
//	else
//	{
//		if (index <= edge[root].mid)
//			update(root * 2, begin, edge[root].mid, index, val);
//		else
//			update(root * 2 + 1, edge[root].mid + 1, end, index, val);
//		pushup(root);
//	}
//}
//int query(int root, int begin, int end, int b, int e)
//{
//	if (begin >= b && end <= e)
//		return edge[root].mx;
//	if (begin > e || end < b)
//		return 0;
//	int res = 0;
//	if (ar[edge[root * 2].r] < ar[edge[root * 2 + 1].l])
//	{
//		res = min(edge[root].mid - b + 1, edge[root * 2].rx) + min(e - edge[root].mid, edge[root * 2 + 1].lx);
//		return max(max(query(root * 2, begin, edge[root].mid, b, e), query(root * 2 + 1, edge[root].mid + 1, end, b, e)), res);
//	}
//	else
//		return max(query(root * 2, begin, edge[root].mid, b, e), query(root * 2 + 1, edge[root].mid + 1, end, b, e));
//	//else if (e <= edge[root].mid)
//	//	return query(root * 2, begin, edge[root].mid, b, e);
//	//else if (b > edge[root].mid)
//	//	return query(root * 2 + 1, edge[root].mid + 1, end, b, e);
//	//else
//	//{
//	//	int t1 = query(root * 2, begin, edge[root].mid, b, e);
//	//	int t2 = query(root * 2 + 1, edge[root].mid + 1, end, b, e);
//	//	int res = 0;
//	//	if (ar[edge[root * 2].r] < ar[edge[root * 2 + 1].l])
//	//	{
//	//		res = min(edge[root].mid - b + 1, edge[root * 2].rx) + min(e - edge[root].mid, edge[root * 2 + 1].lx);
//	//	}
//	//	return max(max(t1, t2), res);
//	//}
//}
//





//4366    线段树第6题，巨难，排序能力从大到小dfs按时间戳（能力大小）建树，线段树维护区间忠诚度最大值；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <map>
//#include <vector>
//using namespace std;
//const int MAX = 100000000;
//struct node
//{
//	int id;
//	int loty;
//	int abty;
//	bool operator < (const node &p) const
//	{
//		return abty > p.abty;
//	}
//};
//node edge[50000 * 4];
//int Max[50000 * 4], Id[50000 * 4];
//int res[50000 * 4], L[50000 * 4], R[50000 * 4], tot;
//map<int, int>q;
//vector<int>G[50000 * 4];
//void update(int root, int begin, int end, int index, int id, int val);
//int query(int root, int begin, int end, int b, int e);
//void pushup(int root);
//void dfs(int n);
//int main()
//{
//	int i, j, k, u, n, m, a, b, c, N, M;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			q.clear();
//			scanf("%d %d", &N, &M);
//			for (i = 0; i <= N; i++)
//				G[i].clear();
//
//			for (u = 1; u < N; u++)
//			{
//				scanf("%d %d %d", &a, &edge[u].loty, &edge[u].abty);
//				G[a].push_back(u);
//				edge[u].id = u;
//				q[edge[u].loty] = u;
//			}
//			sort(edge + 1, edge + N);
//			tot = 0;
//			dfs(0);
//			memset(Max, -1, sizeof(Max));
//			memset(res, -1, sizeof(res));
//			memset(Id, -1, sizeof(Id));
//			for (int i = 1, j; i<N; i = j) 
//			{
//				j = i;
//				while (j<N && edge[j].abty == edge[i].abty)
//				{
//					int id = edge[j].id;
//					int lo = query(1, 0, tot-1, L[id] + 1, R[id] - 1);
//					res[id] = lo == -1 ? -1 : q[lo];
//					j++;
//				}
//				j = i;
//				while (j<N && edge[j].abty == edge[i].abty)
//				{
//					int id = edge[j].id;
//					update(1, 0, tot-1, L[id], id, edge[j].loty);
//					j++;
//				}
//			}
//			for (u = 1; u <= M; u++)
//			{
//				scanf("%d", &a);
//				printf("%d\n", res[a]);
//			}
//		}
//	}
//	return 0;
//}
//void dfs(int n)
//{
//	L[n] = tot++;
//	for (int i = 0; i < G[n].size(); i++)
//	{
//		dfs(G[n][i]);
//	}
//	R[n] = tot;
//}
//int query(int root, int begin, int end, int b, int e)
//{
//	if (b > e)
//		return -1;
//	if (begin >= b && end <= e)
//		return Max[root];
//	int mid = (begin + end) / 2;
//	int ans = -1;
//	if (b <= mid)
//		ans = max(ans, query(root * 2, begin, mid, b, e));
//	if (e > mid)
//		ans = max(ans, query(root * 2 + 1, mid + 1, end, b, e));
//	return ans;
//}
//void update(int root, int begin, int end, int index, int id, int val)
//{
//	if (begin == end)
//	{
//		Id[root] = id;
//		Max[root] = val;
//	}
//	else
//	{
//		int mid = (begin + end) / 2;
//		if (index <= mid)
//		{
//			update(root * 2, begin, mid, index, id, val);
//		}
//		else
//			update(root * 2 + 1, mid + 1, end, index, id, val);
//		pushup(root);
//	}
//}
//void pushup(int root)
//{
//	if (Max[root * 2] > Max[root * 2 + 1])
//	{
//		Max[root] = Max[root * 2];
//		Id[root] = Id[root * 2];
//	}
//	else
//	{
//		Max[root] = Max[root * 2 + 1];
//		Id[root] = Id[root * 2 + 1];
//	}
//}



//poj2777      线段树第7题，  状态压缩；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//const int MAX = 100000000;
//typedef long long ll;
//struct node
//{
//	int l;
//	int r;
//	int mid;
//	ll sta;
//	int visit;
//};
//node sa[100000 * 4];
//int ar[100000 * 4];
//int N, M, n;
//void build(int root, int begin, int end);
//void update(int root, int b, int e, int val);
//void pushup(int root);
//void pushdown(int root);
//ll query(int root, int b, int e);
//int main()
//{
//	int i, j, k, u, m, a, b, c;
//	char s[5];
//	while (scanf("%d %d %d", &N, &n, &M) != EOF)
//	{
//		build(1, 1, N);
//		for (u = 1; u <= M; u++)
//		{
//			scanf("%s%d%d", s, &a, &b);
//			int temp;
//			if (a > b)
//			{
//				temp = a;
//				a = b;
//				b = temp;
//			}
//			if (strcmp(s, "C") == 0)
//			{
//				scanf("%d", &c);
//				update(1, a, b, c);
//			}
//			else
//			{
//				ll res = query(1, a, b);
//				int num = 0;
//				while (res)
//				{
//					if (res & 1)
//						num++;
//					res >>= 1;
//				}
//				printf("%d\n", num);
//			}
//		}
//	}
//	return 0;
//}
//void build(int root, int begin, int end)
//{
//	sa[root].l = begin;
//	sa[root].r = end;
//	sa[root].mid = (begin + end) / 2;
//	sa[root].visit = 0;
//	if (begin == end)
//	{
//		sa[root].sta = 1;
//	}
//	else
//	{
//		build(root * 2, sa[root].l, sa[root].mid);
//		build(root * 2 + 1, sa[root].mid + 1, sa[root].r);
//		pushup(root);
//	}
//}
//void pushup(int root)
//{
//	sa[root].sta = sa[root * 2].sta | sa[root * 2 + 1].sta;
//}
//void update(int root, int b, int e, int val)
//{
//	if (sa[root].l > e || sa[root].r < b)
//		return;
//	if (sa[root].l >= b && sa[root].r <= e)
//	{
//		sa[root].sta = (ll)1 << (val-1);
//		sa[root].visit = (ll)1 << (val-1);
//		return;
//	}
//	pushdown(root);
//	update(root * 2, b, e, val);
//	update(root * 2 + 1, b, e, val);
//	pushup(root);
//}
//void pushdown(int root)
//{
//	if (sa[root].visit)
//	{
//		sa[root * 2].visit = sa[root].visit;
//		sa[root * 2 + 1].visit = sa[root].visit;
//		sa[root * 2].sta = sa[root].sta;
//		sa[root * 2 + 1].sta = sa[root].sta;
//		sa[root].visit = 0;
//	}
//}
//ll query(int root, int b, int e)
//{
//	if (sa[root].l > e || sa[root].r < b)
//		return 0;
//	if (sa[root].l >= b && sa[root].r <= e)
//		return sa[root].sta;
//	pushdown(root);
//	return query(root * 2, b, e) | query(root * 2 + 1, b, e);
//}







//线段树  第8题；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//struct node
//{
//	int l;
//	int r;
//	int mid;
//	int lx;
//	int rx;
//	int max;
//	int visit;
//};
//node sa[50000 * 4];
//int ar[50000 * 4];
//int N, M;
//void build(int root, int begin, int end);
//void update(int root, int b, int e, int val);
//void pushdown(int root);
//void pushup(int root);
//int query(int root, int num);
//int main()
//{
//	int i, j, k, u, n, m, a, b, c;
//	while (scanf("%d %d", &N, &M) != EOF)
//	{
//		build(1, 1, N);
//		for (m = 1; m <= M; m++)
//		{
//			scanf("%d %d", &a, &b);
//			if (a == 1)
//			{
//				if (sa[1].max < b)
//				{
//					printf("0\n");
//					continue;
//				}
//				int x = query(1, b);
//				printf("%d\n", x);
//				update(1, x, x + b - 1, m);
//			}
//			else
//			{
//				scanf("%d", &c);
//				update(1, b, b + c - 1, 0);
//			}
//		}
//	}
//	return 0;
//}
//void build(int root, int begin, int end)
//{
//	sa[root].l = begin;
//	sa[root].r = end;
//	sa[root].mid = (begin + end) / 2;
//	sa[root].visit = -1;
//	if (begin == end)
//	{
//		sa[root].lx = sa[root].rx = sa[root].max = 1;
//	}
//	else
//	{
//		build(root * 2, sa[root].l, sa[root].mid);
//		build(root * 2 + 1, sa[root].mid + 1, sa[root].r);
//		pushup(root);
//	}
//}
//void pushup(int root)
//{
//	sa[root].lx = sa[root * 2].lx + ((sa[root * 2].lx == (sa[root].mid - sa[root].l + 1)) ? sa[root * 2 + 1].lx : 0);
//	sa[root].rx = sa[root * 2 + 1].rx + ((sa[root * 2 + 1].rx == (sa[root].r - sa[root].mid)) ? sa[root * 2].rx : 0);
//	sa[root].max = max(max(sa[root * 2].max, sa[root * 2 + 1].max), sa[root * 2].rx + sa[root * 2 + 1].lx);
//}
//void update(int root, int b, int e, int val)
//{
//	if (sa[root].l > e || sa[root].r < b)
//		return;
//	if (sa[root].l >= b && sa[root].r <= e)
//	{
//		sa[root].visit = val;
//		if (val != 0)
//			sa[root].lx = sa[root].rx = sa[root].max = 0;
//		else
//		{
//			sa[root].rx =  sa[root].lx =  sa[root].max = sa[root].r - sa[root].l + 1;
//		}
//		return;
//	}
//	pushdown(root);
//	update(root * 2, b, e, val);
//	update(root * 2 + 1, b, e, val);
//	pushup(root);
//}
//void pushdown(int root)
//{
//	if (sa[root].visit != -1)
//	{
//		sa[root * 2].visit = sa[root].visit;
//		sa[root * 2 + 1].visit = sa[root].visit;
//		if (sa[root].visit == 0)
//		{
//			sa[root * 2].max = (sa[root].mid - sa[root].l + 1);
//			sa[root * 2].lx = (sa[root].mid - sa[root].l + 1);
//			sa[root * 2].rx = (sa[root].mid - sa[root].l + 1);
//			sa[root * 2 + 1].max = (sa[root].r - sa[root].mid);
//			sa[root * 2 + 1].lx = (sa[root].r - sa[root].mid);
//			sa[root * 2 + 1].rx = (sa[root].r - sa[root].mid);
//		}
//		else
//		{
//			sa[root * 2].max = sa[root * 2].lx = sa[root * 2].rx = 0;
//			sa[root * 2 + 1].max = sa[root * 2 + 1].lx = sa[root * 2 + 1].rx = 0;
//		}
//		sa[root].visit = -1;
//	}
//}
//int query(int root, int num)
//{
//	//if (sa[root].max < num)
//	//	return 0;
//	if (sa[root].l == sa[root].r)
//		return 1;
//	pushdown(root);
//	if (sa[root * 2].max >= num)
//		return query(root * 2, num);
//	if (sa[root * 2].rx + sa[root * 2 + 1].lx >= num)
//		return (sa[root].mid - sa[root * 2].rx + 1);
//	return query(root * 2 + 1, num);
//}







//2199   二分查找；
//#include <cstdio>
//#include <cstring>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int i, j, k, u, n, m, a, b, c;
//	double x, Y;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%lf", &Y);
//			if (Y < 6 || Y >(8 * 100000000 + 7 * 1000000 + 2 * 10000 + 3 * 100 + 6))
//			{
//				printf("No solution!\n");
//				continue;
//			}
//			double l = 0;
//			double r = 100;
//			double mid = (l + r) / 2.0;
//			while (r - l > 1e-6)
//			{
//				if (8 * mid*mid*mid*mid + 7 * mid*mid*mid + 2 * mid*mid + 3 * mid + 6 < Y)
//				{
//					l = mid;
//				}
//				else
//				{
//					r = mid;
//				}
//				mid = (l + r) / 2.0;
//			}
//			printf("%.4lf\n", mid);
//		}
//	}
//	return 0;
//}






//2899  二分查找；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <cmath>
//using namespace std;
//int main()
//{
//	int i, j, k, u, n, m;
//	double x, Y, z;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%lf", &Y);
//			double l = 0;
//			double r = 100;
//			double mid = (l + r) / 2.0;
//			while (r - l > 1e-6)
//			{
//				if (42 * pow(mid, 6.0) + 48 * pow(mid, 5.0) + 21 * pow(mid, 2.0) + 10 * mid < Y)
//				{
//					l = mid;
//				}
//				else
//				{
//					r = mid;
//				}
//				mid = (l + r) / 2.0;
//			}
//			printf("%.4lf\n", 6 * pow(mid, 7.0) + 8 * pow(mid, 6.0) + 7 * pow(mid, 3.0) + 5 * pow(mid, 2.0) - Y*mid);
//		}
//	}
//	return 0;
//}







//1969  二分查找；
//#include <cstdio>
//#include <cstring>
//#include <cmath>
//#include <cctype>
//#include <algorithm>
//using namespace std;
//const double PI = acos(-1.0);
//int main()
//{
//	int i, j, k, u, n, m, a, b, c, r[10010];
//	double x, y, s[10010];
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d", &a, &b);
//			b++;
//			for (u = 1; u <= a; u++)
//			{
//				scanf("%d", &r[u]);
//				s[u] = PI*r[u] * r[u];
//			}
//			sort(s + 1, s + a+1);
//			//for (i = 1; i <= a; i++)
//			//	printf("%lf ", s[i]);
//			//printf("%lf\n", PI);
//			double l = 0;
//			double R = s[a];
//			double mid = (R + l) / 2.0;
//			int sum = 0;
//			while (R - l > 1.0e-6)
//			{
//				for (i = 1; i <= a; i++)
//				{
//					sum = sum + (int)(s[i] / mid);
//				}
//				if (sum < b)
//					R = mid;
//				else
//					l = mid;
//				mid = (l + R) / 2.0;
//				sum = 0;
//			}
//			printf("%.4lf\n", mid);
//		}
//	}
//	return 0;
//}






//1905   快速幂（二分幂）；
//#include <cstdio>
//#include <cmath>
//#include <cstring>
//using namespace std;
//typedef long long ll;
//bool Isprime(ll n);
//bool IsPn(ll a, ll p, ll mod);
//int main()
//{
//	ll i, j, k, n, m, a, b, p;
//	while (scanf("%lld %lld", &p, &a) != EOF && (a || p))
//	{
//		if (Isprime(p))
//		{
//			printf("no\n");
//		}
//		else
//		{
//			if (IsPn(a, p, p))
//				printf("yes\n");
//			else
//				printf("no\n");
//		}
//	}
//	return 0;
//}
//bool Isprime(ll n)
//{
//	int i, j, k;
//	for (i = 2; i*i <= n; i++)
//		if (n % i == 0)
//			return false;
//	return true;
//}
//bool IsPn(ll a, ll p, ll mod)
//{
//	ll res = 1, b = a;
//	while (p)
//	{
//		if (p & 1)
//		{
//			res = (res * a) % mod;
//		}
//		a = (a * a) % mod;
//		p >>= 1;
//	}
//	res %= mod;
//	if (res == b)
//		return true;
//	return false;
//}










//#include <cstdio>
//#include <cstring>
//#include <map>
//#include <string>
//using namespace std;
//map<string, int>q;
//int main()
//{
//	int i, j, k, u, n, m, a, ar[10010];
//	char s[40];
//	while (scanf("%d", &n) != EOF)
//	{
//		q.clear();
//		memset(ar, 0, sizeof(ar));
//		for (i = 1; i <= n; i++)
//		{
//			scanf("%s", s);
//			if (strcmp(s, "memory") == 0)
//				q[s] = 0;
//			else
//				q[s] = i;
//		}
//		scanf("%d", &k);
//		for (u = 1; u <= k; u++)
//		{
//			for (i = 1; i <= n; i++)
//			{
//				scanf("%d%s", &a, s);
//				ar[q[s]] += a;
//			}
//			int num = 0;
//			for (j = 0; j <= n; j++)
//				if (ar[j] > ar[0])
//					num++;
//			printf("%d\n", num+1);
//		}
//	}
//	return 0;
//}






//江苏省赛8；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//#include <map>
//#include <queue>
//#include <vector>
//using namespace std;
//const int MAX = 100000000;
//struct node
//{
//	int to;
//	int next;
//	int val;
//	bool operator < (const node& p) const
//	{
//		return val > p.val;
//	}
//};
//node edge[200000];
//map<string, int>q;
//int head[200000], dist[200000];
//int cnt, N, M, Count;
//void addedge(int x, int y, int z);
//void dijkstra(int begin);
//int main()
//{
//	int i, j, k, u, n, m, a, b, c;
//	char s[50], ss[50][50], begin[50], end[50];
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			q.clear();
//			memset(head, -1, sizeof(head));
//			Count = cnt = 0;
//			scanf("%d", &N);
//			for (i = 1; i <= N; i++)
//			{
//				scanf("%s", s);
//				if (strcmp(s, "B") == 0)
//				{
//					scanf("%d", &k);
//					for (j = 1; j <= k; j++)
//					{
//						scanf("%s", ss[j]);
//						if (q[ss[j]] == 0)
//						{
//							q[ss[j]] = Count++;
//						}
//					}
//					for (j = 1; j <= k; j++)
//					{
//						for (u = j + 1; u <= k; u++)
//						{
//							addedge(q[ss[j]], q[ss[u]], 0);
//							addedge(q[ss[u]], q[ss[j]], 0);
//						}
//					}
//				}
//				else
//				{
//					scanf("%d", &k);
//					for (j = 1; j <= k; j++)
//					{
//						scanf("%s", ss[j]);
//						if (q[ss[j]] == 0)
//						{
//							q[ss[j]] = Count++;
//						}
//					}
//					for (j = 1; j <= k; j++)
//					{
//						for (u = j + 1; u <= k; u++)
//						{
//							addedge(q[ss[j]], q[ss[u]], 2);
//							addedge(q[ss[u]], q[ss[j]], 2);
//						}
//					}
//				}
//			}
//			scanf("%s %s", begin, end);
//			dijkstra(q[begin]);
//			printf("Case #%d: %d\n", m, dist[q[end]]);
//		}
//	}
//	return 0;
//}
//void addedge(int x, int y, int z)
//{
//	edge[cnt].to = y;
//	edge[cnt].val = z;
//	edge[cnt].next = head[x];
//	head[x] = cnt++;
//}
//void dijkstra(int begin)
//{
//	priority_queue<node>p;
//	int i, j, k;
//	node now, after;
//	for (i = 0; i <= Count; i++)
//	{
//		dist[i] = MAX;
//	}
//	now.to = begin;
//	now.val = 0;
//	now.next = head[begin];
//	dist[begin] = 0;
//	p.push(now);
//	while (!p.empty())
//	{
//		now = p.top();
//		p.pop();
//		for (i = head[now.to]; i != -1; i = edge[i].next)
//		{
//			after = edge[i];
//			if (dist[after.to] > dist[now.to] + after.val)
//			{
//				dist[after.to] = dist[now.to] + after.val;
//				p.push(after);
//			}
//		}
//	}
//}







//江苏省赛1；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <map>
//#include <cctype>
//#include <cmath>
//using namespace std;
//char s[300], ss[300], sss[100];
//char ar[10000];
//map<char, char*>q;
//int main()
//{
//	q['A'] = q['a'] = ".-"; q['B'] = q['b'] = "-..."; q['C'] = q['c'] = "-.-."; q['D'] = q['d'] = "-.."; q['E'] = q['e'] = "."; q['F'] = q['f'] = "..-."; q['G'] = q['g'] = "--."; q['H'] = q['h'] = "...."; q['I'] = q['i'] = ".."; q['J'] = q['j'] = ".---"; q['K'] = q['k'] = "-.-"; q['L'] = q['l'] = ".-.."; q['M'] = q['m'] = "--"; q['N'] = q['n'] = "-.";q['O'] = q['o'] = "---";q['P'] = q['p'] = ".--.";q['Q'] = q['q'] = "--.-";q['R'] = q['r'] = ".-.";q['S'] = q['s'] = "...";q['T'] = q['t'] = "-";q['U'] = q['u'] = "..-";q['V'] = q['v'] = "...-";q['W'] = q['w'] = ".--";q['X'] = q['x'] = "-..-";q['Y'] = q['y'] = "-.--";q['Z'] = q['z'] = "--..";q['1'] = ".----";q['2'] = "..---";q['3'] = "...--";q['4'] = "....-";q['5'] = ".....";q['6'] = "-....";q['7'] = "--...";q['8'] = "---..";q['9'] = "----.";q['0'] = "-----";q['.'] = "="; q['-'] = "===";
//
//	int i, j, k, u, n, m, a, b, c, h, cnt;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			cnt = 0;
//			memset(ar, 0, sizeof(ar));
//			scanf("%d", &k);
//			for (u = 1; u <= k; u++)
//			{
//				scanf("%s", s);
//				for (i = 0; s[i] != '\0'; i++)
//				{
//					strcpy(sss, q[s[i]]);
//					for (j = 0; sss[j] != '\0'; j++)
//					{
//						if (sss[j] == '.')
//							ar[cnt++] = '=';
//						else
//							ar[cnt++] = '=', ar[cnt++] = '=', ar[cnt++] = '=';
//						ar[cnt++] = '.';
//					}
//					cnt--;
//					ar[cnt++] = '.', ar[cnt++] = '.', ar[cnt++] = '.';
//				}
//				cnt -= 3;
//				ar[cnt++] = '.', ar[cnt++] = '.', ar[cnt++] = '.', ar[cnt++] = '.', ar[cnt++] = '.', ar[cnt++] = '.', ar[cnt++] = '.';
//			}
//			cnt -= 7;
//			ar[cnt] = '\0';
//			printf("Case #%d: %s\n", m, ar);
//		}
//	}
//	return 0;
//}








//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int i, j, k, u, n, m, a, b, x, y, z, h, count;
//	char s[5];
//	int set[20], ti, time[20];
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			memset(set, 0, sizeof(set));
//			memset(time, 0, sizeof(time));
//			scanf("%d %d", &a, &b);
//			count = 0;
//			ti = 0;
//			for (u = 1; u <= b; u++)
//			{
//				scanf("%d%d:%d%s", &x, &y, &z, s);
//				x %= 100;
//				if (s[0] == 'A' && !set[x])
//				{
//					set[x] = 1;
//					time[x] += y * 60 + z;
//					ti += time[x];
//					count++;
//				}
//				else
//				{
//					if (!set[x])
//					{
//						time[x] += 20;
//					}
//				}
//			}
//			printf("%d %d\n", count, ti);
//		}
//	}
//	return 0;
//}






//2446   对二分查找不够熟练啊！！！！   搞了好久；判断条件是r>l，结果是mid，如果是double，不用加==条件，是int，需要加==条件；
//#include <cstdio>
//#include <cstring>
//#include <cmath>
//using namespace std;
//typedef long long ll;
//ll Floor[2002000], num[2002000];
//int main()
//{
//	int i, j, k, u, n, m, a, b, c;
//	ll N;
//	Floor[0] = num[0] = 0;
//	for (i = 1; i < 2002000; i++)
//	{
//		num[i] = num[i - 1] + i;
//		Floor[i] = Floor[i - 1] + num[i];
//	}
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%lld", &N);
//			ll l = 1;
//			ll r = 2002000;
//			ll mid = (l + r) / 2;
//			while (r > l)
//			{
//				if (Floor[mid] < N)
//					l = mid + 1;
//				else if (Floor[mid] > N)
//					r = mid - 1;
//				else
//					break;
//				mid = (l + r) / 2;
//			}
//			if (Floor[mid] < N)
//				mid++;
//			ll F = mid;
//			l = 1;
//			r = F;
//			mid = (l + r) / 2;
//			while (r > l)
//			{
//				if (num[mid] < N - Floor[F - 1])
//					l = mid + 1;
//				else if (num[mid] > N - Floor[F - 1])
//					r = mid - 1;
//				else
//					break;
//				mid = (l + r) / 2;
//			}
//			ll row = mid;
//			if (num[row] == N - Floor[F - 1])
//				printf("%lld %lld %lld\n", F, row, row);
//			else
//			{
//				if (num[row] < N - Floor[F - 1])
//					row++;
//				printf("%lld %lld %lld\n", F, row, N - Floor[F - 1] - num[row - 1]);
//			}
//		}
//	}
//	return 0;
//}







//2289  二分查找；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <cctype>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//const double PI = acos(-1.0);
//int main()
//{
//	int i, j, k, n, m, u, a, b, c;
//	double r, R, H, V;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%lf %lf %lf %lf", &r, &R, &H, &V);
//			double l = 0.0;
//			double ri = H;
//			double mid = (l + ri) / 2.0;
//			while (ri - l >= 1.0e-9)
//			{
//				double rr = r + (R - r) * mid / H;
//				double v = 1.0 / 3.0 * PI * mid * (r* r + rr*rr + r * rr);
//				if (v <= V)
//					l = mid;
//				else
//					ri = mid;
//				mid = (l + ri) / 2.0;
//			}
//			printf("%.6lf\n", mid);
//		}
//	}
//	return 0;
//}





//1010    dfs；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <cctype>
//#include <cmath>
//#include <queue>
//#include <vector>
//#include <algorithm>
//using namespace std;
//struct node
//{
//	int x;
//	int y;
//	int time;
//};
//node now, after;
//int dir[4][2] = { -1, 0, 0, -1, 1, 0, 0, 1 };
//int visit[10][10];
//char ar[10][10];
//int beginx, beginy, N, M, T, endx, endy;
//bool dfs(int b, int e, int t);
//int main()
//{
//	int i, j, k, u, n, m;
//	while (scanf("%d %d %d", &N, &M, &T) != EOF && (N || M || T))
//	{
//		for (i = 1; i <= N; i++)
//		{
//			scanf("%s", ar[i] + 1);
//			for (j = 1; j <= M; j++)
//			{
//				if (ar[i][j] == 'S')
//				{
//					beginx = i;
//					beginy = j;
//				}
//				if (ar[i][j] == 'D')
//				{
//					endx = i;
//					endy = j;
//				}
//			}
//		}
//		memset(visit, 0, sizeof(visit));
//		if (dfs(beginx, beginy, 0))
//			printf("YES\n");
//		else
//			printf("NO\n");
//	}
//	return 0;
//}
//bool dfs(int b, int e, int t)
//{
//	int i, j, u, v, temp;
//	if (ar[b][e] == 'D' && t == T)
//		return true;
//	visit[b][e] = 1;
//	for (i = 0; i < 4; i++)
//	{
//		after.x = b + dir[i][0];
//		after.y = e + dir[i][1];
//		after.time = t + 1;
//		if (after.x < 1 || after.x > N || after.y < 1 || after.y > M || visit[after.x][after.y] || ar[after.x][after.y] == 'X')
//			continue;
//		if ((after.time == T && ar[after.x][after.y] != 'D') || (after.time != T && ar[after.x][after.y] == 'D'))
//			continue;
//		temp = (T - after.time) - abs(after.x - endx) - abs(after.y - endy);
//		if (temp % 2 != 0 || temp < 0)
//			continue;
//		if (dfs(after.x, after.y, after.time))
//			return true;
//	}
//	visit[b][e] = 0;
//	return false;
//}

//1010  bfs会超内存；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <cctype>
//#include <cmath>
//#include <queue>
//#include <vector>
//#include <algorithm>
//using namespace std;
//struct node
//{
//	int x;
//	int y;
//	int time;
//	int vis[9][9];
//	node(int a, int b, int c)
//	{
//		x = a;
//		y = b;
//		time = c;
//		memset(vis, 0, sizeof(vis));
//	}
//	node(const node& p)
//	{
//		x = p.x;
//		y = p.y;
//		time = p.time;
//		for (int i = 1; i < 9; i++)
//		{
//			for (int j = 1; j < 9; j++)
//				vis[i][j] = p.vis[i][j];
//		}
//	}
//	void reset()
//	{
//		vis[x][y] = 1;
//	}
//	int retvis()
//	{
//		return vis[x][y];
//	}
//};
//int dir[4][2] = { -1, 0, 0, -1, 1, 0, 0, 1 };
//char ar[10][10];
//int beginx, beginy, N, M, T, endx, endy;
//bool P_bfs();
//int main()
//{
//	int i, j, k, u, n, m;
//	while (scanf("%d %d %d", &N, &M, &T) != EOF && (N || M || T))
//	{
//		for (i = 1; i <= N; i++)
//		{
//			scanf("%s", ar[i] + 1);
//			for (j = 1; j <= M; j++)
//			{
//				if (ar[i][j] == 'S')
//				{
//					beginx = i;
//					beginy = j;
//				}
//				if (ar[i][j] == 'D')
//				{
//					endx = i;
//					endy = j;
//				}
//			}
//		}
//		if (P_bfs())
//			printf("YES\n");
//		else
//			printf("NO\n");
//	}
//	return 0;
//}
//bool P_bfs()
//{
//	int i, j, u, v, temp;
//	queue<node>q;
//	node now(beginx, beginy, 0);
//	now.reset();
//	q.push(now);
//	while (!q.empty())
//	{
//		node now(q.front());
//		q.pop();
//		if (ar[now.x][now.y] == 'D' && now.time == T)
//			return true;
//		for (i = 0; i < 4; i++)
//		{
//			node after(now);
//			after.x += dir[i][0];
//			after.y += dir[i][1];
//			after.time++;
//			if (after.x < 1 || after.x > N || after.y < 1 || after.y > M || after.retvis() || ar[after.x][after.y] == 'X')
//				continue;
//			if ((after.time == T && ar[after.x][after.y] != 'D') || (after.time != T && ar[after.x][after.y] == 'D'))
//				continue;
//			temp = abs((after.x + after.y) - (endx + endy) - (T - after.time));
//			if (temp % 2 || temp < 0)
//				continue;
//			q.push(after);
//			after.reset();
//		}
//	}
//	return false;
//}




//概率dp第一题，记住printf ：%f！！；
//#include <cstdio>
//#include <cstring>
//#include <cmath>
//using namespace std;
//int main()
//{
//	
//	double p,k;
//	while (scanf("%lf", &k) != EOF && (k))
//	{
//		scanf("%lf", &p);
//		printf("%.3f %.3f\n", k / p, k*(k+1)/ (p*p) - k/p);
//	}
//	return 0;
//}







//3853  概率dp第2题，dp数组记录的是走向答案的结果；
//#include <cstdio>
//#include <cstring>
//#include <cmath>
//#include <cctype>
//using namespace std;
//struct node
//{
//	double stay;
//	double right;
//	double below;
//};
//node ar[1010][1010];
//double sa[1010][1010];
//int N, M;
//int main()
//{
//	int i, j, k, u, n, m, a, b;
//	while (scanf("%d %d", &N, &M) != EOF)
//	{
//		for (i = 1; i <= N; i++)
//		{
//			for (j = 1; j <= M; j++)
//			{
//				scanf("%lf %lf %lf", &ar[i][j].stay, &ar[i][j].right, &ar[i][j].below);
//			}
//		}
//		memset(sa, 0, sizeof(sa));
//		for (i = N; i >= 1; i--)
//		{
//			for (j = M; j >= 1; j--)
//			{
//				if (i == N && j == M)
//					continue;
//				if (1.0 - ar[i][j].stay < 1.0e-9)
//					continue;
//				sa[i][j] = (ar[i][j].right*sa[i][j + 1] + ar[i][j].below*sa[i + 1][j] + 2.0) / (1.0 - ar[i][j].stay);
//			}
//		}
//		printf("%.3f\n", sa[1][1]);
//	}
//	return 0;
//}







//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//using namespace std;
//typedef long long ll;
//struct node
//{
//	int x;
//	int val;
//	int index;
//};
//node sa[100010];
//bool comp(const node& a, const node& b)
//{
//	return a.x < b.x;
//}
//struct point
//{
//	int num;
//	int index;
//};
//point sf[100010];
//bool comp1(const point& a, const point& b)
//{
//	return a.index < b.index;
//}
//int set[100010];
//int main()
//{
//	int i, j, k, u, n, m;
//	while (scanf("%d", &n) != EOF)
//	{
//		memset(set, 0, sizeof(set));
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d", &sa[m].x, &sa[m].val);
//			sa[m].index = m;
//		}
//		sort(sa + 1, sa + n + 1, comp);
//		for (i = 1; i <= n; i++)
//		{
//			for (j = i + 1; j <= n; j++)
//			{
//				if (sa[i].x + sa[i].val >= sa[j].x)
//				{
//					set[i]++;
//				}
//				else
//					break;
//			}
//		}
//		for (i = n; i >= 1; i--)
//		{
//			for (j = i - 1; j >= 1; j--)
//			{
//				if (sa[i].x - sa[i].val <= sa[j].x)
//				{
//					set[i]++;
//				}
//				else
//					break;
//			}
//			sf[i].num = set[i];
//			sf[i].index = sa[i].index;
//		}
//		sort(sf + 1, sf + n + 1, comp1);
//		for (i = 1; i <= n; i++)
//		{
//			if (i != 1)
//				putchar(' ');
//			printf("%d", sf[i].num + 1);
//		}
//		putchar('\n');
//	}
//	return 0;
//}







//1030   斜坐标模拟
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <queue>
//#include <vector>
//using namespace std;
//#define max 10010
//int main()
//{
//	int n, m, dn, dm, lm, ln, rn, rm, sum;
//	while (~scanf("%d%d", &m, &n))
//	{
//		dn = sqrt(n - 1) + 1;
//		dm = sqrt(m - 1) + 1;
//		ln = (n - (dn - 1)*(dn - 1) + 1) / 2;
//		lm = (m - (dm - 1)*(dm - 1) + 1) / 2;
//		rn = (dn*dn - n) / 2 + 1;
//		rm = (dm*dm - m) / 2 + 1;
//		sum = abs(dn - dm) + abs(ln - lm) + abs(rn - rm);
//		printf("%d\n", sum);
//	}
//	return 0;
//}







//2489   最小生成树， dfs枚举顶点，数组记录枚举路径；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <queue>
//#include <vector>
//#include <cmath>
//using namespace std;
//const int MAX = 100000000;
//int ar[20][20], vex[20];
//int visit[20], tem[20], res[20], dist[20];
//int n, m;
//double MIN;
//void dfs(int f, int num);
//int prime(int f);
//int main()
//{
//	int i, j, k, u;
//	while (scanf("%d %d", &n, &m) != EOF && (n + m))
//	{
//		for (i = 1; i <= n; i++)
//		{
//			scanf("%d", &vex[i]);
//		}
//		for (i = 1; i <= n; i++)
//		{
//			for (j = 1; j <= n; j++)
//			{
//				scanf("%d", &ar[i][j]);
//			}
//		}
//		MIN = 1.0*MAX;
//		for (i = 1; i <= n; i++)
//		{
//			tem[1] = i;
//			dfs(i, 1);
//		}
//		for (i = 1; i < m; i++)
//		{
//			printf("%d ", res[i]);
//		}
//		printf("%d\n", res[m]);
//	}
//	return 0;
//}
//int prime(int f)
//{
//	int i, j, k, Min, pos, ans = 0;
//	memset(visit, 0, sizeof(visit));
//	for (i = 1; i < m; i++)
//		dist[tem[i]] = ar[f][tem[i]];
//	visit[f] = 1;
//	for (i = 1; i < m; i++)
//	{
//		Min = MAX;
//		pos = -1;
//		for (j = 1; j <= m; j++)
//		{
//			if (Min > dist[tem[j]] && !visit[tem[j]])
//			{
//				Min = dist[tem[j]];
//				pos = tem[j];
//			}
//		}
//		if (Min == MAX)
//			return -1;
//		visit[pos] = 1;
//		ans += Min;
//		for (j = 1; j <= m; j++)
//		{
//			if (!visit[tem[j]] && dist[tem[j]] > ar[pos][tem[j]])
//			{
//				dist[tem[j]] = ar[pos][tem[j]];
//			}
//		}
//	}
//	return ans;
//}
//void dfs(int f, int num)
//{
//	int i, j, k;
//	double ans = 0, sumv = 0, sume = 0;
//	if (num == m)
//	{
//		int cnt = 1;
//		for (i = 1; i <= m; i++)
//			sumv += (double)vex[tem[i]];
//		sume = (double)prime(f);
//		ans = sume / sumv;
//		if (ans < MIN)
//		{
//			MIN = ans;
//			for (i = 1; i <= m; i++)
//			{
//				res[i] = tem[i];
//			}
//		}
//		return;
//	}
//	if (n - f + num < m)
//		return;
//	for (i = f + 1; i <= n; i++)
//	{
//		tem[num + 1] = i;
//		dfs(i, num + 1);
//	}
//}






//5253     二维点变为一维，kruskal；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//#include <cmath>
//using namespace std;
//const int maxn = 1000000 + 10;
//const int MAX = 100000000;
//int ar[1005][1005], F[maxn];
//int cnt;
//struct node
//{
//	int u;
//	int v;
//	int w;
//};
//node edge[4 * maxn];
//bool comp(const node& a, const node& b)
//{
//	return a.w < b.w;
//}
//int find(int x)
//{
//	if (F[x] == -1)
//		return x;
//	else
//		return F[x] = find(F[x]);
//}
//void addedge(int u, int v, int w)
//{
//	edge[cnt].u = u;
//	edge[cnt].v = v;
//	edge[cnt++].w = w;
//}
//int dir[4][2] = { 1, 0, 0, 1 };
//int kruskal(int n);
//int main()
//{
//	int i, j, k, n, m, ux, uy, N, M;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d", &N, &M);
//			for (i = 1; i <= N; i++)
//			{
//				for (j = 1; j <= M; j++)
//				{
//					scanf("%d", &ar[i][j]);
//				}
//			}
//			cnt = 0;
//			for (i = 1; i <= N; i++)
//			{
//				for (j = 1; j <= M; j++)
//				{
//					for (k = 0; k < 2; k++)
//					{
//						ux = i + dir[k][0];
//						uy = j + dir[k][1];
//						if (ux < 1 || uy < 1 || ux > N || uy > M)
//							continue;
//						addedge((i - 1)*M + j, (ux - 1)*M + uy, abs(ar[i][j] - ar[ux][uy]));
//					}
//				}
//			}
//			printf("Case #%d:\n%d\n", m, kruskal(N*M));
//		}
//	}
//	return 0;
//}
//int kruskal(int n)
//{
//	memset(F, -1, sizeof(F));
//	sort(edge, edge + cnt, comp);
//	int i, j, k, ans = 0, count = 0;
//	for (i = 0; i < cnt; i++)
//	{
//		int u = edge[i].u;
//		int v = edge[i].v;
//		int w = edge[i].w;
//		int t1 = find(u);
//		int t2 = find(v);
//		if (t1 != t2)
//		{
//			F[t2] = t1;
//			ans += w;
//			count++;
//		}
//		if (count == n - 1)
//			break;
//	}
//	if (count < n - 1)
//		return 0;
//	else
//		return ans;
//}







//5624   求最小生成树的最大边减最小边的差最小的那一棵 kruskal，枚举边；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//typedef long long ll;
//const int maxn = 15000 + 10;
//const int MAX = 100000000;
//struct node
//{
//	int u;
//	int v;
//	ll w;
//};
//node edge[maxn];
//int N, M, cnt;
//ll res;
//int F[maxn];
//bool comp(const node& a, const node& b)
//{
//	return a.w < b.w;
//}
//void addedge(int u, int v, ll w)
//{
//	edge[cnt].u = u;
//	edge[cnt].v = v;
//	edge[cnt++].w = w;
//}
//int find(int x)
//{
//	if (F[x] == -1)
//		return x;
//	else
//		return F[x] = find(F[x]);
//}
//ll kruskal(int f)
//{
//	int i, j, k, count = 0;
//	ll ans = 0;
//	memset(F, -1, sizeof(F));
//	for (i = f; i < cnt; i++)
//	{
//		int u = edge[i].u;
//		int v = edge[i].v;
//		ll w = edge[i].w;
//		int t1 = find(u);
//		int t2 = find(v);
//		if (t1 != t2)
//		{
//			F[t2] = t1;
//			ans += w;
//			count++;
//		}
//		if (count == N - 1)
//			break;
//	}
//	if (count < N - 1)
//		return -1;
//	else
//		return edge[i].w - edge[f].w;
//}
//int main()
//{
//	int i, j, k, n, m, a, b;
//	ll c;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			cnt = 0;
//			res = MAX;
//			scanf("%d %d", &N, &M);
//			for (i = 1; i <= M; i++)
//			{
//				scanf("%d %d %lld", &a, &b, &c);
//				addedge(a, b, c);
//			}
//			sort(edge, edge + cnt, comp);
//			res = kruskal(0);
//			if (res == -1)
//			{
//				printf("-1\n");
//				continue;
//			}
//			for (i = 1; i < cnt; i++)
//			{
//				ll t = kruskal(i);
//				if (t < 0)
//					break;
//				if (res > t)
//					res = t;
//			}
//			printf("%lld\n", res);
//		}
//	}
//	return 0;
//}









//3938    kruskal思想，并查集，求路径上各边小于给定值的路径个数；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//using namespace std;
//const int MAX = 100000000;
//int N, M, L, cnt;
//int F[10010], sum[10010];
//struct node
//{
//	int u;
//	int v;
//	int w;
//};
//node edge[50010];
//struct que
//{
//	int l;
//	int index;
//	int res;
//};
//que q[10010];
//bool comp1(const node& a, const node& b)
//{
//	return a.w < b.w;
//}
//bool comp2(const que& a, const que& b)
//{
//	return a.l < b.l;
//}
//bool comp3(const que& a, const que& b)
//{
//	return a.index < b.index;
//}
//int ans[50010];
//int find(int x)
//{
//	if (F[x] == -1)
//		return x;
//	else
//		return F[x] = find(F[x]);
//}
//int UNION(int u, int v)
//{
//	int t1 = find(u);
//	int t2 = find(v);
//	int t;
//	if (t1 == t2)
//		return 0;
//	else if (sum[t1] > sum[t2])
//	{
//		F[t2] = t1;
//		t = sum[t1] * sum[t2];
//		sum[t1] += sum[t2];
//		return t;
//	}
//	else
//	{
//		F[t1] = t2;
//		t = sum[t1] * sum[t2];
//		sum[t2] += sum[t1];
//		return t;
//	}
//}
//int main()
//{
//	int i, j, k, u, n, m, a, b, c;
//	while (scanf("%d %d %d", &n, &m, &k) != EOF)
//	{
//		for (i = 0; i <= n; i++)
//		{
//			sum[i] = 1;
//		}
//		memset(F, -1, sizeof(F));
//		for (i = 1; i <= m; i++)
//		{
//			scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
//		}
//		for (i = 1; i <= k; i++)
//		{
//			scanf("%d", &q[i].l);
//			q[i].res = 0;
//			q[i].index = i;
//		}
//		sort(edge + 1, edge + 1 + m, comp1);
//		sort(q + 1, q + 1 + k, comp2);
//		int cnt = 1;
//		for (i = 1; i <= k; i++)
//		{
//			while (edge[cnt].w <= q[i].l && cnt <= m)
//			{
//				q[i].res += UNION(edge[cnt].u, edge[cnt].v);
//				cnt++;
//			}
//			if (i > 1)
//				q[i].res += q[i - 1].res;
//		}
//		sort(q + 1, q + 1 + k, comp3);
//		for (i = 1; i <= k; i++)
//		{
//			printf("%d\n", q[i].res);
//		}
//	}
//	return 0;
//}







//4018  次小生成树，prime，枚举边；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <cmath>
//using namespace std;
//const int MIN = -10000000;
//const int  MAX = 100000000;
//struct Point
//{
//	int i;
//	int x;
//	int y;
//	int p;
//};
//Point point[1010];
//double ar[1010][1010], Max[1010][1010], dist[1010];
//int pre[1010], visit[1010], used[1010][1010];
//int cnt, N, M;
//double prime()
//{
//	int i, j, k;
//	double ans = 0.0;
//	memset(visit, 0, sizeof(visit));
//	memset(Max, 0, sizeof(Max));
//	memset(used, 0, sizeof(used));
//	visit[1] = 1;
//	for (i = 1; i <= N; i++)
//	{
//		pre[i] = 1;
//		dist[i] = ar[1][i];
//	}
//	pre[1] = -1;
//	dist[1] = 0;
//	for (i = 2; i <= N; i++)
//	{
//		double mindist = 1.0*MAX;
//		int p = -1;
//		for (j = 1; j <= N; j++)
//		{
//			if (!visit[j] && dist[j] < mindist)
//			{
//				mindist = dist[j];
//				p = j;
//			}
//		}
//		if (mindist == MAX)
//			return -1.0;
//		ans += mindist;
//		visit[p] = 1;
//		used[pre[p]][p] = used[p][pre[p]] = 1;
//		for (j = 1; j <= N; j++)
//		{
//			if (visit[j] && j != p)
//			{
//				Max[j][p] = Max[p][j] = max(Max[j][pre[p]], dist[p]);
//			}
//			if (!visit[j] && dist[j] > ar[p][j])
//			{
//				dist[j] = ar[p][j];
//				pre[j] = p;
//			}
//		}
//	}
//	return ans;
//}
//int main()
//{
//	int i, j, k, u, n, m, a, b, c;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &N);
//			for (i = 1; i <= N; i++)
//			{
//				scanf("%d %d %d", &point[i].x, &point[i].y, &point[i].p);
//				point[i].i = i;
//			}
//			for (i = 1; i <= N; i++)
//			{
//				for (j = i + 1; j <= N; j++)
//				{
//					ar[i][j] = ar[j][i] = sqrt((point[i].x - point[j].x)*(point[i].x - point[j].x) + (point[i].y - point[j].y)*(point[i].y - point[j].y));
//				}
//			}
//			double s = prime();
//			double res = 1.0*MIN;
//			for (i = 1; i <= N; i++)
//			{
//				for (j = i + 1; j <= N; j++)
//				{
//					if (used[i][j])
//					{
//						double t = 1.0*(point[i].p + point[j].p) / (s - ar[i][j]);
//						if (res < t)
//							res = t;
//					}
//					else
//					{
//						double t = 1.0*(point[i].p + point[j].p) / (s - Max[i][j]);
//						if (res < t)
//							res = t;
//					}
//				}
//			}
//			printf("%.2f\n", res);
//		}
//	}
//	return 0;
//}






//1530     最大团模板；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//using namespace std;
//const int INF = 100000000;
//const int maxn = 60;
//int ar[maxn][maxn];
//int dp[maxn], stack[maxn][maxn];
//int N, RES;
//void dfs(int dep, int num)
//{
//	int i, j, u, v;
//	if (num == 0)
//	{
//		if (RES < dep)
//			RES = dep;
//		return;
//	}
//	if (dep + num <= RES)
//		return;
//	for (i = 0; i < num; i++)
//	{
//		u = stack[dep][i];
//		if (dep + dp[u] <= RES)
//			continue;
//		if (dep + N - u + 1 <= RES)
//			continue;
//		int top = 0;
//		for (j = i + 1; j < num; j++)
//		{
//			v = stack[dep][j];
//			if (ar[u][v])
//				stack[dep + 1][top++] = v;
//		}
//		dfs(dep + 1, top);
//	}
//}
//int main()
//{
//	int i, j, k, u, n, m;
//	while (scanf("%d", &N) != EOF && N)
//	{
//		for (i = 1; i <= N; i++)
//		{
//			for (j = 1; j <= N; j++)
//			{
//				scanf("%d", &ar[i][j]);
//			}
//		}
//		dp[N] = 1;
//		RES = 1;
//		for (i = N - 1; i >= 1; i--)
//		{
//			int top = 0;
//			for (j = 1; j <= N; j++)
//				if (ar[i][j])
//					stack[1][top++] = j;
//			dfs(1, top);
//			dp[i] = RES;
//		}
//		printf("%d\n", RES);
//	}
//	return 0;
//}








//1398      母函数，j循环要从0开始；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <cmath>
//#include <iostream>
//using namespace std;
//int ar[30], cur[300], pre[300];
//int main()
//{
//	int i, j, k, u, n, m;
//	for (i = 0; i <= 18; i++)
//	{
//		ar[i] = i*i;
//	}
//	while (scanf("%d", &n) != EOF && n)
//	{
//		memset(pre, 0, sizeof(pre));
//		memset(cur, 0, sizeof(cur));
//		for (i = 0; i <= n; i++)
//		{
//			pre[i] = 1;
//		}
//		for (i = 2; i <= 17; i++)
//		{
//			for (j = 0; j <= n; j++)
//			{
//				for (k = 0; k + j <= n; k += ar[i])
//				{
//					cur[k + j] += pre[j];
//				}
//			}
//			for (j = 0; j <= n; j++)
//			{
//				pre[j] = cur[j];
//				cur[j] = 0;
//			}
//		}
//		printf("%d\n", pre[n]);
//	}
//	return 0;
//}







//1709     母函数，负价值的话k循环里直接减一次就行了；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <iostream>
//using namespace std;
//const int maxn = 10001;
//int ar[110], cur[maxn], pre[maxn];
//int main()
//{
//	int i, j, k, u, n, m;
//	while (cin >> n)
//	{
//		memset(pre, 0, sizeof(pre));
//		memset(cur, 0, sizeof(cur));
//		int sum = 0;
//		for (m = 1; m <= n; m++)
//		{
//			cin >> ar[m];
//			sum += ar[m];
//		}
//		for (i = 0; i <= ar[1]; i += ar[1])
//			pre[i] = 1;
//		for (i = 2; i <= n; i++)
//		{
//			for (j = 0; j <= sum; j++)
//			{
//				for (k = 0; k <= ar[i] && k + j <= sum; k += ar[i])
//				{
//					cur[k + j] += pre[j];
//					if (k > j)
//						cur[k - j] += pre[j];
//					else
//						cur[j - k] += pre[j];
//				}
//			}
//			for (j = 0; j <= sum; j++)
//			{
//				pre[j] = cur[j];
//				cur[j] = 0;
//			}
//		}
//		int cnt = 0;
//		for (i = 1; i <= sum; i++)
//		{
//			if (!pre[i])
//			{
//				cnt++;
//			}
//		}
//		cout << cnt << endl;
//		int doudou = 0;
//		for (i = 1; i <= sum; i++)
//		{
//			if (!pre[i])
//			{
//				if (doudou)
//					cout << " ";
//				cout << i;
//				doudou = 1;
//			}
//		}
//		if (cnt)
//			cout << endl;
//	}
//	return 0;
//}









//2152   母函数；
//#include <cstdio>
//#include <iostream>
//#include <cstring>
//using namespace std;
//const int maxn = 110;
//int pre[maxn], cur[maxn], limit[maxn][2];
//int main()
//{
//	int i, j, k, u, n, m;
//	while (scanf("%d %d", &n, &m) != EOF)
//	{
//		memset(pre, 0, sizeof(pre));
//		memset(cur, 0, sizeof(cur));
//		int sum = 0;
//		for (i = 1; i <= n; i++)
//		{
//			scanf("%d %d", &limit[i][0], &limit[i][1]);
//		}
//		for (i = limit[1][0]; i <= limit[1][1]; i++)
//			pre[i] = 1;
//		for (i = 2; i <= n; i++)
//		{
//			for (j = 0; j <= m; j++)
//			{
//				for (k = limit[i][0]; k <= limit[i][1] && k + j <= m; k++)
//				{
//					cur[k + j] += pre[j];
//				}
//			}
//			for (j = 0; j <= m; j++)
//			{
//				pre[j] = cur[j];
//				cur[j] = 0;
//			}
//		}
//		printf("%d\n", pre[m]);
//	}
//	return 0;
//}










//3585     最大团+二分；
//#include <math.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//const int INF = 0x3f3f3f3f;
//int V, K, bestn;
//double len[105 * 105], x[105], y[105], tmp[105][105];
//int dp[105], sum[105][105], G[105][105];
//void dfs(int ns, int dep) {
//	int i, j, u, v, cnt;
//	if (ns == 0) {
//		bestn = max(dep, bestn);
//		return;
//	}
//	for (i = 0; i<ns; i++) {
//		u = sum[dep][i];
//		if (dep + V - u + 1 <= bestn || dep + dp[u] <= bestn)
//			return;
//		cnt = 0;
//		for (j = i + 1; j<ns; j++) {
//			v = sum[dep][j];
//			if (G[u][v])
//				sum[dep + 1][cnt++] = v;
//		}
//		dfs(cnt, dep + 1);
//	}
//}
//int judge(double mid) {
//	int i, j, ns;
//	memset(G, 0, sizeof(G));
//	for (i = 1; i <= V; i++)
//		for (j = i + 1; j <= V; j++)
//			if (tmp[i][j] >= mid)
//				G[i][j] = G[j][i] = 1;
//	bestn = 0;
//	for (i = V; i >= 1; i--) {
//		ns = 0;
//		for (j = i + 1; j <= V; j++) {
//			if (G[i][j])
//				sum[1][ns++] = j;
//		}
//		dfs(ns, 1);
//		dp[i] = bestn;
//		if (bestn >= K)
//			return 1;
//	}
//	return 0;
//}                                               //最大团模板
//int main() {                                     //就是转换成二分最短边，将比最短边大
//	int i, j, k, l, r, id, ans, mid;                   //的值全部连起来，用最大团判断是否点的
//	while (scanf("%d%d", &V, &K) != EOF) {            //个数大于k
//		id = 1;
//		for (i = 1; i <= V; i++)
//			scanf("%lf%lf", &x[i], &y[i]);
//		for (i = 1; i <= V; i++) {
//			tmp[i][i] = 0;
//			for (j = i + 1; j <= V; j++) {
//				tmp[i][j] = tmp[j][i] = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);
//				len[id++] = tmp[i][j];
//			}
//		}                                       //用所有长度排序后二分下标，而不是直接
//		sort(len + 1, len + id);                     //二分长度
//		l = 1, r = id - 1;
//		while (l <= r) {
//			mid = (l + r) / 2;
//			if (judge(len[mid])) {
//				l = mid + 1;
//				ans = mid;
//			}
//			else
//				r = mid - 1;
//		}
//		printf("%.2lf\n", sqrt(len[ans]));
//	}
//	return 0;
//}
//下面这个是自己写的超时
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//#include <cmath>
//using namespace std;
//const int maxn = 110;
//struct Point
//{
//	int x;
//	int y;
//};
//Point point[maxn];
//int N, K, cnt, RES;
//int stack[maxn][maxn], G[maxn][maxn];
//int ar[maxn][maxn], edge[maxn*maxn], dp[maxn];
//void dfs(int dep, int num, int x)
//{
//	int i, j, u, v;
//	if (dep >= K)
//	{
//		RES = dep;
//		return;
//	}
//	if (num == 0)
//	{
//		if (RES < dep)
//			RES = dep;
//		return;
//	}
//	if (dep + num <= RES)
//		return;
//	for (i = 0; i < num; i++)
//	{
//		u = stack[dep][i];
//		if (dep + dp[u] <= RES)
//			return;
//		if (dep + N - u + 1 <= RES)
//			return;
//		int top = 0;
//		for (j = i + 1; j < num; j++)
//		{
//			v = stack[dep][j];
//			if (ar[u][v] >= edge[x])
//				stack[dep + 1][top++] = v;
//		}
//		dfs(dep + 1, top, x);
//	}
//}
//bool check(int x)
//{
//	int i, j, k;
//	dp[N] = 1;
//	RES = 1;
//	for (i = N - 1; i >= 1; i--)
//	{
//		int top = 0;
//		for (j = 1; j <= N; j++)
//			if (ar[i][j] >= edge[x])
//				stack[1][top++] = j;
//		dfs(1, top, x);
//		dp[i] = RES;
//		if (RES >= K)
//			return true;
//	}
//	return false;
//}
//int main()
//{
//	int i, j, k, u, a, b, c;
//	while (scanf("%d %d", &N, &K) != EOF)
//	{
//		for (i = 1; i <= N; i++)
//		{
//			scanf("%d %d", &point[i].x, &point[i].y);
//		}
//		cnt = 0;
//		for (i = 1; i <= N; i++)
//		{
//			ar[i][i] = 0;
//			for (j = i+1; j <= N; j++)
//			{
//				ar[i][j] = ar[j][i] = (point[i].x - point[j].x)*(point[i].x - point[j].x) + (point[i].y - point[j].y)*(point[i].y - point[j].y);
//				edge[++cnt] = ar[i][j];
//			}
//		}
//		sort(edge + 1, edge + cnt + 1);
//		int l = 1;
//		int r = cnt;
//		int mid = (l + r) / 2;
//		int ans;
//		while (r >= l)
//		{
//			if (check(mid))
//			{
//				l = mid + 1;
//				ans = mid;
//			}
//			else
//				r = mid - 1;
//			mid = (l + r) / 2;
//		}
//		printf("%.2f\n", sqrt(edge[ans]));
//	}
//	return 0;
//}









//1846    巴什博弈，n%(m+1) == 0 后手必胜，n%(m+1) != 0 先手必胜；
//#include <cstdio>
//using namespace std;
//int main()
//{
//	int i, j, k, a, b, n, m;
//	scanf("%d", &n);
//	for (m = 1; m <= n; m++)
//	{
//		scanf("%d %d", &a, &b);
//		if (a % (b + 1) == 0)
//		{
//			printf("second\n");
//		}
//		else
//		{
//			printf("first\n");
//		}
//	}
//	return 0;
//}






//1847   巴什博弈；
//#include <iostream>
//using namespace std;
//int main()
//{
//	int i, j, k, n, m, a, b;
//	while (scanf("%d", &n) != EOF)
//	{
//		if (n % 3)
//		{
//			printf("Kiki\n");
//		}
//		else
//			printf("Cici\n");
//	}
//	return 0;
//}







//华东师范大学游族杯；
//D          差分建图，dfs更快，bfs也可以；
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//#include <cctype>
//#include <queue>
//#include <deque>
//#include <vector>
//#include <map>
//using namespace std;
//typedef long long ll;
//const ll MAX = 1e18;
//const int maxn = 200020;
//struct node
//{
//	int to;
//	int next;
//	ll val;
//};
//node edge[maxn * 3];
//ll head[maxn], dist[maxn], visit[maxn], in[maxn];
//int stack[maxn];
//int cnt, top;
//void addedge(int x, int y, ll z);
//bool SPFA(int s);
//int main()
//{
//	int i, j, n, m, a, b, c, u, v;
//	ll k;
//	map<int, int>q;
//	while (scanf("%d", &n) != EOF)
//	{
//		cnt = 0;
//		memset(head, -1, sizeof(head));
//		memset(visit, 0, sizeof(visit));
//		q.clear();
//		top = 1;
//		for (i = 1; i <= n; i++)
//		{
//			scanf("%d %d %lld", &u, &v, &k);
//			u--;
//			if (q.count(u))
//				u = q[u];
//			else
//				u = q[u] = top++;
//			if (q.count(v))
//				v = q[v];
//			else
//				v = q[v] = top++;
//			addedge(u, v, k);
//			addedge(v, u, -k);
//		}
//		int st = top;
//		for (i = 1; i < top; i++)
//		{
//			addedge(st, i, 0);
//			dist[i] = MAX;
//		}
//		dist[st] = 0;
//		visit[st] = 1;
//		if (SPFA(st))
//		{
//			printf("2333!(=v=)\n");
//		}
//		else
//		{
//			printf("666~~~(=_=)\n");
//		}
//	}
//	return 0;
//}
//void addedge(int x, int y, ll z)
//{
//	edge[cnt].to = y;
//	edge[cnt].val = z;
//	edge[cnt].next = head[x];
//	head[x] = cnt++;
//}
//bool SPFA(int u)
//{
//	int i, j, t, v;
//	for (i = head[u]; i != -1; i = edge[i].next)
//	{
//		v = edge[i].to;
//		if (dist[v] > dist[u] + edge[i].val)
//		{
//			if (visit[v])
//				return false;
//			else
//			{
//				dist[v] = dist[u] + edge[i].val;
//				visit[v] = 1;
//				if (!SPFA(v))
//					return false;
//				visit[v] = 0;
//			}
//		}
//	}
//	return true;
//}
//bool SPFA(int s)
//{
//	int i, j, k, u, v;
//	deque<int>q;
//	for (i = 1; i < top; i++)
//		dist[i] = MAX;
//	memset(visit, 0, sizeof(visit));
//	memset(in, 0, sizeof(in));
//	dist[s] = 0;
//	visit[s] = 1;
//	in[s] = 1;
//	q.push_back(s);
//	while (!q.empty())
//	{
//		u = q.front();
//		q.pop_front();
//		visit[u] = 0;
//		for (i = head[u]; i != -1; i = edge[i].next)
//		{
//			v = edge[i].to;
//			if (dist[v] > dist[u] + edge[i].val)
//			{
//				dist[v] = dist[u] + edge[i].val;
//				if (!visit[v])
//				{
//					visit[v] = 1;
//					if (++in[v] > top)
//						return false;
//					if (!q.empty() && dist[v] < dist[q.front()])
//						q.push_front(v);
//					else
//						q.push_back(v);
//				}
//			}
//		}
//	}
//	return true;
//}
//I            第K大公约数问题，某两个数的公约数一定是这两个数的gcd的约数
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <cmath>
//#include <vector>
//using namespace std;
//const int maxn = 1000000 + 10;
//vector<int>G[maxn];
//int ar[maxn];
//int N, K;
//int gcd(int x, int y)
//{
//	int t;
//	while (y)
//	{
//		t = x%y;
//		x = y;
//		y = t;
//	}
//	return  x;
//}
//int main()
//{
//	int i, j, k, u, n, m;
//	for (i = 1; i <= 1000001; i++)
//	{
//		for (j = 1; i*j <= 1000001; j++)
//		{
//			G[j*i].push_back(i);
//		}
//	}
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d", &N, &K);
//			scanf("%d", &ar[1]);
//			for (i = 2; i <= N; i++)
//			{
//				scanf("%d", &ar[i]);
//				int t = gcd(ar[i - 1], ar[i]);
//				if (i == 2)
//					printf("Case %d: ", m);
//				if (G[t].size() < K)
//					printf("-1 ");
//				else
//					printf("%d ", G[t][G[t].size() - K]);
//			}
//			putchar('\n');
//		}
//	}
//	return 0;
//}
//A       
//#include <cstdio>
//#include <cstring>
//using namespace std;
//const int maxn = 10000;
//int dp[] = { 0,1,2,3,4,5,6,7,8,9,19,20,21,22,23,24,25,26,27,28,38,39,40,41,42,43,44,45,46,47,57,58,59,60,61,62,63,64,65,66,76,77,78,79,80,81,82,83,84,85,95,96,97,98,99,100,101,102,103,104,114,115,116,117,118,119,120,121,122,123,133,134,135,136,137,138,139,140,141,142,152,153,154,155,156,157,158,159,160,161,171,172,173,174,175,176,177,178,179,180,199,200,201,202,203,204,205,206,207,208,218,219,220,221,222,223,224,225,226,227,237,238,239,240,241,242,243,244,245,246,256,257,258,259,260,261,262,263,264,265,275,276,277,278,279,280,281,282,283,284,294,295,296,297,298,299,300,301,302,303,313,314,315,316,317,318,319,320,321,322,332,333,334,335,336,337,338,339,340,341,351,352,353,354,355,356,357,358,359,360,370,371,372,373,374,375,376,377,378,379,398,399,400,401,402,403,404,405,406,407,417,418,419,420,421,422,423,424,425,426,436,437,438,439,440,441,442,443,444,445,455,456,457,458,459,460,461,462,463,464,474,475,476,477,478,479,480,481,482,483,493,494,495,496,497,498,499,500,501,502,512,513,514,515,516,517,518,519,520,521,531,532,533,534,535,536,537,538,539,540,550,551,552,553,554,555,556,557,558,559,569,570,571,572,573,574,575,576,577,578,597,598,599,600,601,602,603,604,605,606,616,617,618,619,620,621,622,623,624,625,635,636,637,638,639,640,641,642,643,644,654,655,656,657,658,659,660,661,662,663,673,674,675,676,677,678,679,680,681,682,692,693,694,695,696,697,698,699,700,701,711,712,713,714,715,716,717,718,719,720,730,731,732,733,734,735,736,737,738,739,749,750,751,752,753,754,755,756,757,758,768,769,770,771,772,773,774,775,776,777,796,797,798,799,800,801,802,803,804,805,815,816,817,818,819,820,821,822,823,824,834,835,836,837,838,839,840,841,842,843,853,854,855,856,857,858,859,860,861,862,872,873,874,875,876,877,878,879,880,881,891,892,893,894,895,896,897,898,899,900,910,911,912,913,914,915,916,917,918,919,929,930,931,932,933,934,935,936,937,938,948,949,950,951,952,953,954,955,956,957,967,968,969,970,971,972,973,974,975,976,995,996,997,998,999,1000,1001,1002,1003,1004,1014,1015,1016,1017,1018,1019,1020,1021,1022,1023,1033,1034,1035,1036,1037,1038,1039,1040,1041,1042,1052,1053,1054,1055,1056,1057,1058,1059,1060,1061,1071,1072,1073,1074,1075,1076,1077,1078,1079,1080,1090,1091,1092,1093,1094,1095,1096,1097,1098,1099,1109,1110,1111,1112,1113,1114,1115,1116,1117,1118,1128,1129,1130,1131,1132,1133,1134,1135,1136,1137,1147,1148,1149,1150,1151,1152,1153,1154,1155,1156,1166,1167,1168,1169,1170,1171,1172,1173,1174,1175,1194,1195,1196,1197,1198,1199,1200,1201,1202,1203,1213,1214,1215,1216,1217,1218,1219,1220,1221,1222,1232,1233,1234,1235,1236,1237,1238,1239,1240,1241,1251,1252,1253,1254,1255,1256,1257,1258,1259,1260,1270,1271,1272,1273,1274,1275,1276,1277,1278,1279,1289,1290,1291,1292,1293,1294,1295,1296,1297,1298,1308,1309,1310,1311,1312,1313,1314,1315,1316,1317,1327,1328,1329,1330,1331,1332,1333,1334,1335,1336,1346,1347,1348,1349,1350,1351,1352,1353,1354,1355,1365,1366,1367,1368,1369,1370,1371,1372,1373,1374,1393,1394,1395,1396,1397,1398,1399,1400,1401,1402,1412,1413,1414,1415,1416,1417,1418,1419,1420,1421,1431,1432,1433,1434,1435,1436,1437,1438,1439,1440,1450,1451,1452,1453,1454,1455,1456,1457,1458,1459,1469,1470,1471,1472,1473,1474,1475,1476,1477,1478,1488,1489,1490,1491,1492,1493,1494,1495,1496,1497,1507,1508,1509,1510,1511,1512,1513,1514,1515,1516,1526,1527,1528,1529,1530,1531,1532,1533,1534,1535,1545,1546,1547,1548,1549,1550,1551,1552,1553,1554,1564,1565,1566,1567,1568,1569,1570,1571,1572,1573,1592,1593,1594,1595,1596,1597,1598,1599,1600,1601,1611,1612,1613,1614,1615,1616,1617,1618,1619,1620,1630,1631,1632,1633,1634,1635,1636,1637,1638,1639,1649,1650,1651,1652,1653,1654,1655,1656,1657,1658,1668,1669,1670,1671,1672,1673,1674,1675,1676,1677,1687,1688,1689,1690,1691,1692,1693,1694,1695,1696,1706,1707,1708,1709,1710,1711,1712,1713,1714,1715,1725,1726,1727,1728,1729,1730,1731,1732,1733,1734,1744,1745,1746,1747,1748,1749,1750,1751,1752,1753,1763,1764,1765,1766,1767,1768,1769,1770,1771,1772,1791,1792,1793,1794,1795,1796,1797,1798,1799,1800,1810,1811,1812,1813,1814,1815,1816,1817,1818,1819,1829,1830,1831,1832,1833,1834,1835,1836,1837,1838,1848,1849,1850,1851,1852,1853,1854,1855,1856,1857,1867,1868,1869,1870,1871,1872,1873,1874,1875,1876,1886,1887,1888,1889,1890,1891,1892,1893,1894,1895,1905,1906,1907,1908,1909,1910,1911,1912,1913,1914,1924,1925,1926,1927,1928,1929,1930,1931,1932,1933,1943,1944,1945,1946,1947,1948,1949,1950,1951,1952,1962,1963,1964,1965,1966,1967,1968,1969,1970,1971 };
//int N, M, S;
////打表，从0开始翻到i需要的力气
//// int main()
//// {
//// 	freopen("OUT.txt", "w", stdout);
//// 	int i, j, k, u, n, m, a, b;
//// 	dp[0] = 0;
//// 	for (i = 1; i <= 999; i++)
//// 	{
//// 		if (i % 100 == 0)
//// 		{
//// 			dp[i] = dp[i - 1] + 19;
//// 		}
//// 		else if (i % 10 == 0)
//// 		{
//// 			dp[i] = dp[i - 1] + 10;
//// 		}
//// 		else
//// 		{
//// 			dp[i] = dp[i - 1] + 1;
//// 		}
//// 	}
//// 	for (i = 0; i <= 999; i++)
//// 		printf("%d,", dp[i]);
//// 	return 0;
//// }
//int main()
//{
//	int i, j, k, u, n, m;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d %d", &N, &M, &S);
//			int MAX = -1;
//			for (i = 0; i <= S; i++)
//			{
//				int t = dp[i+N] - dp[N] + dp[S - i+M] - dp[M];
//				if (MAX < t)
//					MAX = t;
//			}
//			printf("Case %d: %d\n", m, MAX);
//		}
//	}
//	return 0;
//}
//C        图的四条边界一定可以走通，所以只要走到0，0就行；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//#include <cstdlib>
//#include <cmath>
//using namespace std;
//const int maxn = 110;
//const int INF = 1000000000;
//int dir[4][2] = { -1, 0, 0, -1, 0, 1, 1, 0 };    //up left right down;
//int visit[maxn][maxn];
//char ar[maxn][maxn];
//struct Node
//{
//	int x;
//	int y;
//	int sta;
//};
//Node stack[maxn*maxn];
//int top, N, M;
//bool dfs(int x, int y)
//{
//	int i, j;
//	if (x == 1 && y == 1)
//		return true;
//	visit[x][y] = 1;
//	for (i = 0; i < 4; i++)
//	{
//		int xx = x + dir[i][0];
//		int yy = y + dir[i][1];
//		if (xx < 1 || xx > N || yy < 1 || yy > M || ar[xx][yy] == '*' || visit[xx][yy])
//			continue;
//		stack[++top].x = x;
//		stack[top].y = y;
//		stack[top].sta = i;
//		if (dfs(xx, yy))
//			return true;
//		top--;
//	}
//	visit[x][y] = 0;
//	return false;
//}
//int main()
//{
//	int i, j, k, u, n, m, bx, by;
//	while (scanf("%d %d", &N, &M) != EOF)
//	{
//		bx = INF;
//		by = INF;
//		for (i = 1; i <= N; i++)
//		{
//			scanf("%s", ar[i] + 1);
//			if (bx == INF)
//				for (j = 1; j <= M; j++)
//				{
//					if (ar[i][j] == 'P')
//					{
//						bx = i;
//						by = j;
//					}
//				}
//		}
//		top = 0;
//		memset(visit, 0, sizeof(visit));
//		if (dfs(bx, by))
//		{
//			for (i = 1; i <= top; i++)
//			{
//				if (stack[i].sta == 0)
//				{
//					printf("U");
//				}
//				else if (stack[i].sta == 1)
//				{
//					printf("L");
//				}
//				else if (stack[i].sta == 2)
//				{
//					printf("R");
//				}
//				else
//				{
//					printf("D");
//				}
//			}
//			for (i = 1; i < M; i++)
//				printf("R");
//			for (i = 1; i < N; i++)
//				printf("D");
//			for (i = 1; i < M; i++)
//				printf("L");
//			for (i = 1; i < N; i++)
//				printf("U");
//			for (i = top; i >= 1; i--)
//			{
//				if (stack[i].sta == 0)
//				{
//					printf("D");
//				}
//				else if (stack[i].sta == 1)
//				{
//					printf("R");
//				}
//				else if (stack[i].sta == 2)
//				{
//					printf("L");
//				}
//				else
//				{
//					printf("U");
//				}
//			}
//			putchar('\n');
//		}
//		else
//			printf("error\n");
//	}
//	return 0;
//}







//EOJ3257   没过
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <cctype>
//using namespace std;
//typedef long long ll;
//const int INF = 1000000000;
//const int maxn = 20;
//int ar[maxn];
//int dp[maxn][maxn];
//ll N, M;
//int dfs(int pos, int pre, int limit)
//{
//	int i, j, k, res = 0;
//	if (pos == 0)
//		return 0;
//	//if (!limit && dp[pos][pre] != -1)
//	//	return dp[pos][pre];
//	int t = (limit ? ar[pos] : 9);
//	for (i = 0; i <= t; i++)
//	{
//		if (i == 6)
//		{
//			int temp = 0;
//			if (limit && ar[pos] == 6)
//			{
//				for (j = pos - 1; j >= 1; j--)
//					temp = ar[j] + 10 * temp;
//				if (temp == 0)
//					temp = 1;
//				res += temp;
//			}
//			else
//			{
//				for (j = pos - 1; j >= 1; j--)
//					temp = 10 * temp + 9;
//				if (temp == 0)
//					temp = 1;
//				res += temp;
//			}
//		}
//		res += dfs(pos - 1, i,  limit && i == ar[pos]);
//	}
//	if (!limit)
//		dp[pos][pre] = res;
//	return res;
//}
//int solve(int n)
//{
//	int i, j, k, count = 0;
//	while (n)
//	{
//		ar[++count] = n % 10;
//		n /= 10;
//	}
//	return dfs(count, 0, 1);
//}
//int main()
//{
//	int i, j, k, u, n, m;
//	memset(dp, -1, sizeof(dp));
//	while (scanf("%lld %lld", &N, &M) != EOF)
//	{
//		printf("%d\n", solve(M) - solve(N - 1));
//	}
//	return 0;
//}








//EOJ3263   右区间排序，从第一个区间开始尽量满足最右端；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <cmath>
//#include <vector>
//using namespace std;
//const int maxn = 1000 + 10;
//int ar[maxn];
//int N, M, K;
//struct Node
//{
//	int x;
//	int y;
//	int num;
//};
//Node edge[maxn];
//bool comp(const Node a, const Node b)
//{
//	return a.y < b.y;
//}
//int solve()
//{
//	int i, j, k, sum = 0;
//	for (i = 1; i <= M; i++)
//	{
//		int t = edge[i].num;
//		for (j = edge[i].x; j <= edge[i].y; j++)
//			if (ar[j])
//				t--;
//		if (t <= 0)
//			continue;
//		for (j = edge[i].y; j >= edge[i].x; j--)
//		{
//			if (!ar[j])
//			{
//				sum++;
//				ar[j]++;
//				t--;
//			}
//			if (t <= 0)
//				break;
//		}
//		if (t > 0)
//			return -1;
//	}
//	return sum;
//}
//int main()
//{
//	int i, j, k, u, n, m, a, b;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d %d", &N, &M, &K);
//			memset(ar, 0, sizeof(ar));
//			for (i = 1; i <= K; i++)
//			{
//				scanf("%d", &a);
//				ar[a]++;
//			}
//			for (i = 1; i <= M; i++)
//			{
//				scanf("%d %d %d", &edge[i].x, &edge[i].y, &edge[i].num);
//			}
//			sort(edge + 1, edge + 1 + M, comp);
//			printf("Case %d: %d\n", m, solve());
//		}
//	}
//	return 0;
//}







//EOJ 3276       纯暴力；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <cctype>
//using namespace std;
//typedef long long ll;
//int main()
//{
//	ll i, j, k, u, n, m, res, a;
//	ll sum;
//	while (scanf("%lld", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%lld", &a);
//			ll res = 0;
//			for (i = 1; i < a; i++)
//			{
//				sum = 0;
//				for (j = 2; j < a; j++)
//				{
//					sum = (i + i + j - 1) * j / 2;
//					if (sum > a)
//						break;
//					if (sum == a)
//						res++;
//				}
//			}
//			printf("Case %lld: %lld\n", m, res);
//		}
//	}
//	return 0;
//}








//EOJ  3260   dfs+怎样按最小的路径走；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <cctype>
//#include <cmath>
//using namespace std;
//const int INF = 1000000000;
//const int maxn = 15;
//int dir[4][2] = { -1, 0, 0, -1, 1, 0, 0, 1 };
//int visit[maxn][maxn];
//char ar[maxn][maxn];
//int N, M, K, bx, by;
//bool check(int xx, int yy, int tt, int x, int y)
//{
//	int i, j, doudou = 0;
//	if (xx < 1 || xx > N || yy < 1 || yy > M || visit[xx][yy])
//		return false;
//	if (xx == bx && yy == by && tt < K)
//		return false;
//	for (j = 0; j < 4; j++)
//	{
//		int xxx = xx + dir[j][0];
//		int yyy = yy + dir[j][1];
//		if (xxx < 1 || xxx > N || yyy < 1 || yyy > M)
//			continue;
//		if (visit[xxx][yyy])
//		{
//			if (xxx == x && yyy == y)
//				continue;
//			else
//				return false;
//		}
//	}
//}
//bool dfs(int x, int y, int t)
//{
//	int i, j, k, doudou;
//	if (x == bx && y == by && t >= K)
//		return true;
//	visit[x][y] = 1;
//	for (i = 0; i < 4; i++)
//	{
//		int xx = dir[i][0] + x;
//		int yy = dir[i][1] + y;
//		int tt = t + 1;
//		if (!check(xx, yy, tt,  x, y))
//			continue;
//		if (dfs(xx, yy, tt))
//			return true;
//	}
//	visit[x][y] = 0;
//	return false;
//}
//int main()
//{
//	int i, j, k, u, n, m, a, b, c;
//	while (scanf("%d %d", &N, &M) != EOF)
//	{
//		scanf("%d %d %d", &bx, &by, &K);
//		memset(ar, '*', sizeof(ar));
//		memset(visit, 0, sizeof(visit));
//		if (abs(bx - 1 + by - 1) >= K)
//		{
//			for (i = 1; i <= N; i++)
//			{
//				for (j = 1; j <= M; j++)
//					putchar('.');
//				putchar('\n');
//			}
//		}
//		else
//		{
//			visit[1][1] = 1;
//			dfs(1, 1, 0);
//			visit[bx][by] = 1;
//			for (i = 1; i <= N; i++)
//			{
//				for (j = 1; j <= M; j++)
//				{
//					if (visit[i][j])
//						printf(".");
//					else
//						printf("*");
//				}
//				printf("\n");
//			}
//		}
//	}
//	return 0;
//}







// EOJ    3246          二分查找+线段树维护
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//using namespace std;
//const int INF = 1e9;
//const int maxn = 100000 + 10;
//struct Node
//{
//	int x;
//	int l;
//	int r;
//	int index;
//};
//Node ar[maxn * 4];
//bool comp(const Node&a, const Node& b)
//{
//	return a.x < b.x;
//}
//int L[maxn], R[maxn];        //表示i能影响到的最左、右远点
//int rig[2][maxn * 4];         //表示root区间下的最左、右远点， lef只有0有用， rig只有1有用；
//int lef[2][maxn * 4];
//int res[maxn];
//int MAX;
//void update(int root, int begin, int end, int index, int val, int sta)
//{
//	if (begin == end && begin == index)
//	{
//		lef[sta][root] = rig[sta][root] = val;
//		return;
//	}
//	if (begin > index || end < index)
//		return;
//	int mid = (begin + end) / 2;
//	if (index <= mid)
//		update(root * 2, begin, mid, index, val, sta);
//	else
//		update(root * 2 + 1, mid + 1, end, index, val, sta);
//	lef[sta][root] = min(lef[sta][root * 2], lef[sta][root * 2 + 1]);
//	rig[sta][root] = max(rig[sta][root * 2], rig[sta][root * 2 + 1]);
//}
//void query_Min(int root, int begin, int end, int b, int e, int sta)
//{
//	if (b <= begin && end <= e)
//	{
//		MAX = min(MAX, lef[sta][root]);
//		return;
//	}
//	if (begin > e || end < b)
//		return;
//	int mid = (begin + end) / 2;
//	query_Min(root * 2, begin, mid, b, e, sta);
//	query_Min(root * 2 + 1, mid + 1, end, b, e, sta);
//}
//void query_Max(int root, int begin, int end, int b, int e, int sta)
//{
//	if (b <= begin && end <= e)
//	{
//		MAX = max(MAX, rig[sta][root]);
//		return;
//	}
//	if (begin > e || end < b)
//		return;
//	int mid = (begin + end) / 2;
//	query_Max(root * 2, begin, mid, b, e, sta);
//	query_Max(root * 2 + 1, mid + 1, end, b, e, sta);
//}
//int main()
//{
//	int i, j, k, u, n, m, a, b;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d", &a, &b);
//			ar[m].x = a;
//			ar[m].l = a - b;
//			ar[m].r = a + b;
//			ar[m].index = m;
//		}
//		sort(ar + 1, ar + 1 + n, comp);
//		for (i = 1; i <= n; i++)
//		{
//			int pos;
//			int l = 1;
//			int r = i;
//			int mid;
//			while (r >= l)
//			{
//				mid = (l + r) / 2;
//				if (ar[i].l > ar[mid].x)
//					l = mid + 1;
//				else if (ar[i].l <= ar[mid].x)
//					r = mid - 1;
//			}
//			L[i] = l;
//
//			l = i;
//			r = n;
//			mid = (l + r) / 2;
//			while (r >= l)
//			{
//				mid = (l + r) / 2;
//				if (ar[i].r >= ar[mid].x)
//					l = mid + 1;
//				else if (ar[i].r < ar[mid].x)
//					r = mid - 1;
//			}
//			R[i] = r;
//		}
//		for (i = 1; i <= n; i++)
//		{
//			update(1, 1, n, i, L[i], 0);
//			update(1, 1, n, i, R[i], 1);
//		}
//		int doudou = 1;
//		while (doudou)
//		{
//			doudou = 0;
//			for (i = 1; i <= n; i++)
//			{
//				MAX = INF;
//				query_Min(1, 1, n, L[i], i, 0);
//				if (MAX != L[i])
//				{
//					L[i] = MAX;
//					update(1, 1, n, i, L[i], 0);
//					doudou = 1;
//				}
//			}
//			for (i = n; i >= 1; i--)
//			{
//				MAX = -INF;
//				query_Max(1, 1, n, i, R[i], 1);
//				if (MAX != R[i])
//				{
//					R[i] = MAX;
//					update(1, 1, n, i, R[i], 1);
//					doudou = 1;
//				}
//			}
//			for (i = n; i >= 1; i--)
//			{
//				MAX = INF;
//				query_Min(1, 1, n, i, R[i], 0);
//				if (MAX != L[i])
//				{
//					L[i] = MAX;
//					update(1, 1, n, i, L[i], 0);
//					doudou = 1;
//				}
//			}
//			for (i = 1; i <= n; i++)
//			{
//				MAX = -INF;
//				query_Max(1, 1, n, L[i], i, 1);
//				if (MAX != R[i])
//				{
//					R[i] = MAX;
//					update(1, 1, n, i, R[i], 1);
//					doudou = 1;
//				}
//			}
//		}
//		for (i = 1; i <= n; i++)
//		{
//			res[ar[i].index] = R[i] - L[i] + 1;
//		}
//		for (i = 1; i <= n; i++)
//		{
//			if (i != 1)
//				printf(" ");
//			printf("%d", res[i]);
//		}
//		putchar('\n');
//	}
//	return 0;
//}






//2795   线段树单点更新，树节点存的是可用的最大空间；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <cmath>
//using namespace std;
//const int INF = 1e9;
//const int maxn = 200000 + 10;
//int N, H, W;
//struct Node
//{
//	int l;
//	int r;
//	int mid;
//	int w;
//};
//Node ar[maxn * 4];
//void build(int root, int begin, int end)
//{
//	ar[root].l = begin;
//	ar[root].r = end;
//	ar[root].mid = (begin + end) / 2;
//	ar[root].w = W;
//	if (begin == end)
//	{
//		return;
//	}
//	build(root * 2, ar[root].l, ar[root].mid);
//	build(root * 2 + 1, ar[root].mid + 1, ar[root].r);
//}
//int update(int root, int begin, int end, int val)
//{
//	if (ar[root].w < val)
//		return -1;
//	if (begin == end)
//	{
//		ar[root].w -= val;
//		return begin;
//	}
//	int res;
//	if (ar[root * 2].w >= val)
//		res = update(root * 2, ar[root].l, ar[root].mid, val);
//	else
//		res = update(root * 2 + 1, ar[root].mid + 1, ar[root].r, val);
//	ar[root].w = max(ar[root * 2].w, ar[root * 2 + 1].w);
//	return res;
//}
//int main()
//{
//	int i, j, k, u, n, m, a, b;
//	while (scanf("%d %d %d", &H, &W, &N) != EOF)
//	{
//		if (H > N)
//			H = N;
//		build(1, 1, H);
//		for (m = 1; m <= N; m++)
//		{
//			scanf("%d", &a);
//			printf("%d\n", update(1, 1, H, a));
//		}
//	}
//	return 0;
//}










//3397     线段树，双标记；
//我知道真正想做出来这道题的人需要的不是代码，而是思路：
//这道题有3个区间修改操作，2个区间查询（其中2个修改操作是完全一样的）。如果把每一个操作或者查询分开来出题，我想一个初学者应该也算水题。所以这道题就需要把简单的题目的代码融会贯通到一起。
//首先，修改操作有2类（0号操作 和 1号操作是同类操作），所以就需要有2个标记，那么最重要的就是处理2个标记之间的关系。我们可以把打标记分为3种情况：（0号操作 和 1号操作 我称为覆盖标记，2号操作我成为异或标记）
//1、先打了异或标记（或没打异或标记，都一样），再打覆盖标记：
//此时，先打的异或标记就没有用了，因为不管之前怎么改，现在全部覆盖了，所以直接把异或标记改为false，覆盖标记就是该操作的值；
//2、先打了覆盖标记，再打了异或标记：
//此时，我们应有的操作是把原来覆盖的值全部改为异或的值，那么就等于是把原来的覆盖标记修改成为其异或值就可以了，而异或标记不用修改，还是原来的值；
//3、没有打覆盖标记（或者打的覆盖标记在pushdown函数里已经清0了），再打异或标记：
//此时，不能像第2种情况一样直接修改覆盖标记的值（人家没有覆盖怎么改），所以需要把原来有关于0的记录   与   有关于1 的记录 交换一下即可。
//
//下面说一下查询操作：
//1、3号操作是简单的区间求和
//2、4号操作是区间长度的最值，需要记录区间长度最值、左端长度最值、右端长度最值，具体这个如果不清楚，说明你还不太适合做这个题，先找2个这样的水题搞一搞。这道题特别的是，我们需要有一个交换操作，所以，不仅要记录1的最值，还要记录0的最值，这样交换起来很方便。
//代码网上有很多，但是没什么人写思路，我是看不懂他们写的辣么长的代码，所以我也挣扎了很久。
//先给2组测试数据及答案：
//2
//10 20
//1 1 1 1 1 1 1 1 1 1
//4 0 9
//3 0 9
//0 1 4
//4 0 9
//3 0 9
//2 3 6
//4 0 9
//3 0 9
//1 4 6
//4 0 9
//3 0 9
//2 0 0
//4 0 9
//3 0 9
//2 0 6
//4 0 9
//3 0 9
//1 0 2
//4 0 2
//3 0 2
//10 20
//0 0 0 0 0 0 0 0 0 0
//4 0 9
//3 0 9
//0 1 4
//4 0 9
//3 0 9
//2 3 6
//4 0 9
//3 0 9
//1 4 6
//4 0 9
//3 0 9
//2 0 0
//4 0 9
//3 0 9
//2 0 6
//4 0 9
//3 0 9
//1 0 2
//4 0 2
//3 0 2
//
//
//10
//10
//5
//6
//3
//6
//7
//8
//7
//7
//3
//6
//3
//3
//
//0
//0
//0
//0
//4
//4
//4
//4
//4
//5
//2
//2
//3
//3
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <cmath>
//using namespace std;
//const int maxn = 100000 + 10;
//struct Node
//{
//	int l;
//	int r;
//	int mid;
//	int visit;
//	int XO;
//	int num;
//	int len;
//	int lx;
//	int rx;
//	int num0;
//	int len0;
//	int lx0;
//	int rx0;
//};
//Node ar[maxn * 6];
//int sa[maxn];
//int N, M;
//void pushup(int root)
//{
//	ar[root].num = ar[root * 2].num + ar[root * 2 + 1].num;
//	ar[root].lx = ar[root * 2].lx + ((ar[root * 2].lx == (ar[root].mid - ar[root].l + 1)) ? ar[root * 2 + 1].lx : 0);
//	ar[root].rx = ar[root * 2 + 1].rx + ((ar[root * 2 + 1].rx == (ar[root].r - ar[root].mid)) ? ar[root * 2].rx : 0);
//	ar[root].len = max(max(ar[root * 2].len, ar[root * 2 + 1].len), ar[root * 2].rx + ar[root * 2 + 1].lx);
//
//	ar[root].num0 = ar[root * 2].num0 + ar[root * 2 + 1].num0;
//	ar[root].lx0 = ar[root * 2].lx0 + ((ar[root * 2].lx0 == (ar[root].mid - ar[root].l + 1)) ? ar[root * 2 + 1].lx0 : 0);
//	ar[root].rx0 = ar[root * 2 + 1].rx0 + ((ar[root * 2 + 1].rx0 == (ar[root].r - ar[root].mid)) ? ar[root * 2].rx0 : 0);
//	ar[root].len0 = max(max(ar[root * 2].len0, ar[root * 2 + 1].len0), ar[root * 2].rx0 + ar[root * 2 + 1].lx0);
//}
//void pushdown(int root)
//{
//	if (ar[root].visit != -1)
//	{
//		ar[root * 2].visit = ar[root * 2 + 1].visit = ar[root].visit;
//		ar[root * 2].XO = ar[root * 2 + 1].XO = 0;
//		if (ar[root].visit == 0)
//		{
//			ar[root * 2].num = ar[root * 2 + 1].num = 0;
//			ar[root * 2].lx = ar[root * 2].rx = ar[root * 2].len = 0;
//			ar[root * 2 + 1].lx = ar[root * 2 + 1].rx = ar[root * 2 + 1].len = 0;
//
//			ar[root * 2].num0 = ar[root].mid - ar[root].l + 1;
//			ar[root * 2 + 1].num0 = ar[root].r - ar[root].mid;
//			ar[root * 2].lx0 = ar[root * 2].rx0 = ar[root * 2].len0 = ar[root].mid - ar[root].l + 1;
//			ar[root * 2 + 1].lx0 = ar[root * 2 + 1].rx0 = ar[root * 2 + 1].len0 = ar[root].r - ar[root].mid;
//		}
//		else if (ar[root].visit == 1)
//		{
//			ar[root * 2].num = ar[root].mid - ar[root].l + 1;
//			ar[root * 2 + 1].num = ar[root].r - ar[root].mid;
//			ar[root * 2].lx = ar[root * 2].rx = ar[root * 2].len = ar[root].mid - ar[root].l + 1;
//			ar[root * 2 + 1].lx = ar[root * 2 + 1].rx = ar[root * 2 + 1].len = ar[root].r - ar[root].mid;
//
//			ar[root * 2].num0 = ar[root * 2 + 1].num0 = 0;
//			ar[root * 2].lx0 = ar[root * 2].rx0 = ar[root * 2].len0 = 0;
//			ar[root * 2 + 1].lx0 = ar[root * 2 + 1].rx0 = ar[root * 2 + 1].len0 = 0;
//		}
//		ar[root].visit = -1;
//	}
//	if (ar[root].XO)
//	{
//		if (ar[root * 2].visit != -1)
//		{
//			ar[root * 2].visit ^= 1;
//			if (ar[root * 2].visit)
//			{
//				ar[root * 2].num = ar[root].mid - ar[root].l + 1;
//				ar[root * 2].lx = ar[root * 2].rx = ar[root * 2].len = ar[root].mid - ar[root].l + 1;
//				ar[root * 2].num0 = 0;
//				ar[root * 2].lx0 = ar[root * 2].rx0 = ar[root * 2].len0 = 0;
//			}
//			else
//			{
//				ar[root * 2].num = 0;
//				ar[root * 2].lx = ar[root * 2].rx = ar[root * 2].len = 0;
//				ar[root * 2].num0 = ar[root].mid - ar[root].l + 1;
//				ar[root * 2].lx0 = ar[root * 2].rx0 = ar[root * 2].len0 = ar[root].mid - ar[root].l + 1;
//			}
//		}
//		else
//		{
//			ar[root * 2].XO ^= 1;
//			swap(ar[root * 2].num, ar[root * 2].num0);
//			swap(ar[root * 2].len, ar[root * 2].len0);
//			swap(ar[root * 2].lx, ar[root * 2].lx0);
//			swap(ar[root * 2].rx, ar[root * 2].rx0);
//		}
//		if (ar[root * 2 + 1].visit != -1)
//		{
//			ar[root * 2 + 1].visit ^= 1;
//			if (ar[root * 2 + 1].visit)
//			{
//				ar[root * 2 + 1].num = ar[root].r - ar[root].mid;
//				ar[root * 2 + 1].lx = ar[root * 2 + 1].rx = ar[root * 2 + 1].len = ar[root].r - ar[root].mid;
//				ar[root * 2 + 1].num0 = 0;
//				ar[root * 2 + 1].lx0 = ar[root * 2 + 1].rx0 = ar[root * 2 + 1].len0 = 0;
//			}
//			else
//			{
//				ar[root * 2 + 1].num = 0;
//				ar[root * 2 + 1].lx = ar[root * 2 + 1].rx = ar[root * 2 + 1].len = 0;
//				ar[root * 2 + 1].num0 = ar[root].r - ar[root].mid;
//				ar[root * 2 + 1].lx0 = ar[root * 2 + 1].rx0 = ar[root * 2 + 1].len0 = ar[root].r - ar[root].mid;
//			}
//		}
//		else
//		{
//			ar[root * 2 + 1].XO ^= 1;
//			swap(ar[root * 2 + 1].num, ar[root * 2 + 1].num0);
//			swap(ar[root * 2 + 1].len, ar[root * 2 + 1].len0);
//			swap(ar[root * 2 + 1].lx, ar[root * 2 + 1].lx0);
//			swap(ar[root * 2 + 1].rx, ar[root * 2 + 1].rx0);
//		}
//		//ar[root * 2].XO ^= 1;
//		//ar[root * 2 + 1].XO ^= 1;
//
//		//swap(ar[root * 2].num, ar[root * 2].num0);
//		//swap(ar[root * 2].len, ar[root * 2].len0);
//		//swap(ar[root * 2].lx, ar[root * 2].lx0);
//		//swap(ar[root * 2].rx, ar[root * 2].rx0);
//
//		//swap(ar[root * 2 + 1].num, ar[root * 2 + 1].num0);
//		//swap(ar[root * 2 + 1].len, ar[root * 2 + 1].len0);
//		//swap(ar[root * 2 + 1].lx, ar[root * 2 + 1].lx0);
//		//swap(ar[root * 2 + 1].rx, ar[root * 2 + 1].rx0);
//
//		ar[root].XO = 0;
//	}
//}
//void build(int root, int begin, int end)
//{
//	ar[root].l = begin;
//	ar[root].r = end;
//	ar[root].mid = (begin + end) / 2;
//	ar[root].visit = -1;
//	ar[root].XO = 0;
//	if (begin == end)
//	{
//		ar[root].num = ar[root].lx = ar[root].rx = ar[root].len = sa[ar[root].l];
//		ar[root].num0 = ar[root].lx0 = ar[root].rx0 = ar[root].len0 = sa[ar[root].l] ^ 1;
//		return;
//	}
//	build(root * 2, ar[root].l, ar[root].mid);
//	build(root * 2 + 1, ar[root].mid + 1, ar[root].r);
//	pushup(root);
//}
//void update(int root, int b, int e, int val)
//{
//	if (ar[root].l > e || ar[root].r < b)
//		return;
//	if (ar[root].l >= b && ar[root].r <= e)
//	{
//		if (val == 0)
//		{
//			ar[root].visit = val;
//			ar[root].XO = 0;
//			ar[root].num = ar[root].lx = ar[root].rx = ar[root].len = 0;
//
//			ar[root].num0 = ar[root].lx0 = ar[root].rx0 = ar[root].len0 = ar[root].r - ar[root].l + 1;
//		}
//		else if (val == 1)
//		{
//			ar[root].visit = val;
//			ar[root].XO = 0;
//			ar[root].num = ar[root].lx = ar[root].rx = ar[root].len = ar[root].r - ar[root].l + 1;
//
//			ar[root].num0 = ar[root].lx0 = ar[root].rx0 = ar[root].len0 = 0;
//		}
//		else
//		{
//			if (ar[root].visit != -1)
//			{
//				ar[root].visit ^= 1;
//				if (ar[root].visit == 0)
//				{
//					ar[root].num = ar[root].lx = ar[root].rx = ar[root].len = 0;
//					ar[root].num0 = ar[root].lx0 = ar[root].rx0 = ar[root].len0 = ar[root].r - ar[root].l + 1;
//				}
//				else
//				{
//					ar[root].num = ar[root].lx = ar[root].rx = ar[root].len = ar[root].r - ar[root].l + 1;
//					ar[root].num0 = ar[root].lx0 = ar[root].rx0 = ar[root].len0 = 0;
//				}
//			}
//			else
//			{
//				ar[root].XO ^= 1;
//				swap(ar[root].num, ar[root].num0);
//				swap(ar[root].len, ar[root].len0);
//				swap(ar[root].lx, ar[root].lx0);
//				swap(ar[root].rx, ar[root].rx0);
//			}
//		}
//		return;
//	}
//	pushdown(root);
//	if (b <= ar[root].mid)
//		update(root * 2, b, e, val);
//	if (e > ar[root].mid)
//		update(root * 2 + 1, b, e, val);
//	pushup(root);
//}
//int query_num(int root, int b, int e)
//{
//	if (ar[root].l > e || ar[root].r < b)
//		return 0;
//	if (ar[root].l >= b && ar[root].r <= e)
//	{
//		return ar[root].num;
//	}
//	pushdown(root);
//	int res = 0;
//	if (b <= ar[root].mid)
//		res += query_num(root * 2, b, e);
//	if (e > ar[root].mid)
//		res += query_num(root * 2 + 1, b, e);
//	return res;
//}
//int query_len(int root, int b, int e)
//{
//	if (ar[root].l > e || ar[root].r < b)
//		return 0;
//	if (ar[root].l >= b && ar[root].r <= e)
//	{
//		return ar[root].len;
//	}
//	pushdown(root);
//	int res = 0;
//	res = max(query_len(root * 2, b, e), query_len(root * 2 + 1, b, e));
//	res = max(res, (min(ar[root * 2].r - b + 1, ar[root * 2].rx) + min(e - ar[root * 2 + 1].l + 1, ar[root * 2 + 1].lx)));
//	return res;
//}
//int main()
//{
//	int i, j, k, u, n, m, a, b, c;
//	//freopen("IN.txt", "r", stdin);
//	//freopen("OUT.txt", "w", stdout);
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d", &N, &M);
//			for (i = 1; i <= N; i++)
//			{
//				scanf("%d", &sa[i]);
//			}
//			build(1, 1, N);
//			for (i = 1; i <= M; i++)
//			{
//				scanf("%d %d %d", &a, &b, &c);
//				b++;
//				c++;
//				if (a == 0)
//				{
//					update(1, b, c, 0);
//				}
//				else if (a == 1)
//				{
//					update(1, b, c, 1);
//				}
//				else if (a == 2)
//				{
//					update(1, b, c, 2);
//				}
//				else if (a == 3)
//				{
//					printf("%d\n", query_num(1, b, c));
//				}
//				else
//				{
//					printf("%d\n", query_len(1, b, c));
//				}
//			}
//		}
//	}
//	return 0;
//}









//2871    又是一个线段树神题
//怎样记录某一个块是现在的第几个块呢？
//需要记录节点下的块的个数，在查询时，如果要在左节点查，就不变，在右结点查只需查x-左结点的块个数就行了；
//那么会出现某个块既属于左结点又属于右节点，会在父节点多记录块数
//怎样解决：因为只要输出某块的最开始位置，所以，只在块的最开始位置记录该块，而不是块里的每个节点都记录该块；
//数据：
//6 10
//New 2
//New 5
//New 2
//New 2
//Free 3
//Get 1
//Get 2
//Get 3
//Free 3
//Reset
//6 20
//New 2
//New 5
//New 2
//New 2
//Free 3
//Get 1
//Get 2
//Get 3
//Free 3
//Reset
//New 2
//New 5
//New 2
//New 2
//Free 3
//Get 1
//Get 2
//Get 3
//Free 3
//Reset
//10 13
//New 2
//New 3
//Free 4
//New 4
//New 3
//New 2
//New 1
//Get 2
//Get 3
//Get 4
//Get 5
//Free 8
//New 2
//6 23
//New 2
//New 5
//New 2
//New 2
//Free 3
//Free 4
//Get 1
//Get 2
//Get 3
//Free 3
//Reset
//New 2
//New 4
//Get 2
//Free 2
//Get 2
//Get 1
//Free 3
//New 6
//Get 2
//Get 1
//Free 3
//Get 1

//答案：
//New at 1
//Reject New
//New at 3
//New at 5
//Free from 3 to 4
//Get at 1
//Get at 5
//Reject Get
//Reject Free
//Reset Now
//
//New at 1
//Reject New
//New at 3
//New at 5
//Free from 3 to 4
//Get at 1
//Get at 5
//Reject Get
//Reject Free
//Reset Now
//New at 1
//Reject New
//New at 3
//New at 5
//Free from 3 to 4
//Get at 1
//Get at 5
//Reject Get
//Reject Free
//Reset Now
//
//New at 1
//New at 3
//Free from 3 to 5
//New at 3
//New at 7
//Reject New
//New at 10
//Get at 3
//Get at 7
//Get at 10
//Reject Get
//Free from 7 to 9
//New at 7
//
//New at 1
//Reject New
//New at 3
//New at 5
//Free from 3 to 4
//Reject Free
//Get at 1
//Get at 5
//Reject Get
//Reject Free
//Reset Now
//New at 1
//New at 3
//Get at 3
//Free from 1 to 2
//Reject Get
//Get at 3
//Free from 3 to 6
//New at 1
//Reject Get
//Get at 1
//Free from 1 to 6
//Reject Get

//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//#include <cmath>
//#include <vector>
//#include <map>
//using namespace std;
//const int maxn = 50000 + 100;
//struct  Node
//{
//	int l;
//	int r;
//	int mid;
//	int start;      //该节点属于的Memory block的左端
//	int end;        //该节点属于的Memory block的右端
//	int lx;
//	int rx;
//	int len;
//	int num;        //该节点下的memory block的个数
//	int visit;      //1表示有memory block，2表示没memory block
//	int num_visit;		//对memory block的个数有无操作的标记
//};
//Node ar[maxn * 4];
//int N, M;
//void pushup(int root);
//void pushdown(int root);
//void update_new(int root, int begin, int end);
//void update_free(int root, int begin, int end);
//void update_num(int root, int x, int val);
//int query_new(int root, int val);
//int query_free(int root, int x);
//int query_get(int root, int x);
//void build(int root, int begin, int end);    //其实没啥用只执行一步，但是线段树不写build感觉别扭
//int main()
//{
//	int i, j, k, n, u, m, a, b;
//	char s[50];
////	freopen("IN.txt", "r", stdin);
////	freopen("OUT.txt", "w", stdout);
//	while (scanf("%d %d", &N, &M) != EOF)
//	{
//		build(1, 1, N);
//		int cnt = 1;
//		for (i = 1; i <= M; i++)
//		{
//			scanf("%s", s);
//			if (strcmp(s, "Reset") == 0)
//			{
//				update_free(1, 1, N);
//				printf("Reset Now\n");
//			}
//			else if (strcmp(s, "New") == 0)
//			{
//				scanf("%d", &a);
//				if (ar[1].len < a)
//					printf("Reject New\n");
//				else
//				{
//					int l = query_new(1, a);
//					printf("New at %d\n", l);
//					update_num(1, l, 1);
//					update_new(1, l, l + a - 1);
//				}
//			}
//			else if (strcmp(s, "Free") == 0)
//			{
//				scanf("%d", &a);
//				int t = query_free(1, a);
//				if (ar[t].start == 0 || ar[t].end == 0)
//					printf("Reject Free\n");
//				else
//				{
//					printf("Free from %d to %d\n", ar[t].start, ar[t].end);
//					update_num(1, ar[t].start, 0);
//					update_free(1, ar[t].start, ar[t].end);
//				}
//			}
//			else
//			{
//				scanf("%d", &a);
//				if (a > ar[1].num)
//					printf("Reject Get\n");
//				else
//				{
//					int t = query_get(1, a);
//					printf("Get at %d\n", ar[t].l);
//				}
//			}
//		}
//		putchar('\n');
//	}
//	return 0;
//}
//void pushup(int root)
//{
//	int i, j;
//	ar[root].lx = ar[root * 2].lx + (ar[root * 2].lx == (ar[root].mid - ar[root].l + 1) ? ar[root * 2 + 1].lx : 0);
//	ar[root].rx = ar[root * 2 + 1].rx + (ar[root * 2 + 1].rx == (ar[root].r - ar[root].mid) ? ar[root * 2].rx : 0);
//	ar[root].len = max(max(ar[root * 2].len, ar[root * 2 + 1].len), ar[root * 2].rx + ar[root * 2 + 1].lx);
//	ar[root].num = ar[root * 2].num + ar[root * 2 + 1].num;
//}
//void pushdown(int root)
//{
//	ar[root * 2].l = ar[root].l;
//	ar[root * 2].r = ar[root].mid;
//	ar[root * 2].mid = (ar[root * 2].l + ar[root * 2].r) / 2;
//
//	ar[root * 2 + 1].r = ar[root].r;
//	ar[root * 2 + 1].l = ar[root].mid + 1;
//	ar[root * 2 + 1].mid = (ar[root * 2 + 1].l + ar[root * 2 + 1].r) / 2;
//
//	if (ar[root].visit != -1)
//	{
//		ar[root * 2].visit = ar[root * 2 + 1].visit = ar[root].visit;
//
//		ar[root * 2].lx = ar[root * 2].rx = ar[root * 2].len = (ar[root].visit ^ 1) * (ar[root].mid - ar[root].l + 1);
//		ar[root * 2].start = ar[root].start;
//		ar[root * 2].end = ar[root].end;
//		ar[root * 2].num = ar[root].visit;
//
//		ar[root * 2 + 1].lx = ar[root * 2 + 1].rx = ar[root * 2 + 1].len = (ar[root].visit ^ 1) * (ar[root].r - ar[root].mid);
//		ar[root * 2 + 1].start = ar[root].start;
//		ar[root * 2 + 1].end = ar[root].end;
//		ar[root * 2 + 1].num = ar[root].visit;
//
//		ar[root].visit = -1;
//	}
//	if (ar[root].num_visit)
//	{
//		ar[root * 2].num = ar[root * 2 + 1].num = 0;
//		ar[root * 2].num_visit = ar[root * 2 + 1].num_visit = 1;
//		ar[root].num_visit = 0;
//	}
//}
//void build(int root, int begin, int end)
//{
//	ar[root].l = begin;
//	ar[root].r = end;
//	ar[root].mid = (begin + end) / 2;
//	ar[root].start = 0;
//	ar[root].end = 0;
//	ar[root].lx = ar[root].rx = ar[root].len = ar[root].r - ar[root].l + 1;
//	ar[root].num = 0;
//	ar[root].visit = 0;
//	ar[root].num_visit = 1;
//	if (begin <= ar[root].l && ar[root].r <= end)
//	{
//		pushdown(root);
//		return;
//	}
//}
//void update_new(int root, int begin, int end)
//{
//	if (begin <= ar[root].l && ar[root].r <= end)
//	{
//		ar[root].start = begin;
//		ar[root].end = end;
//		ar[root].lx = ar[root].rx = ar[root].len = 0;
//		ar[root].visit = 1;
//		return;
//	}
//	pushdown(root);
//	if (begin <= ar[root].mid)
//		update_new(root * 2, begin, end);
//	if (end > ar[root].mid)
//		update_new(root * 2 + 1, begin, end);
//	pushup(root);
//}
//void update_free(int root, int begin, int end)
//{
//	if (begin <= ar[root].l && ar[root].r <= end)
//	{
//		ar[root].start = ar[root].end = 0;
//		ar[root].lx = ar[root].rx = ar[root].len = ar[root].r - ar[root].l + 1;
//		ar[root].visit = 0;
//		ar[root].num = 0;
//		ar[root].num_visit = 1;
//		return;
//	}
//	pushdown(root);
//	if (begin <= ar[root].mid)
//		update_free(root * 2, begin, end);
//	if (end > ar[root].mid)
//		update_free(root * 2 + 1, begin, end);
//	pushup(root);
//}
//void update_num(int root, int x, int val)
//{
//	if (ar[root].l == ar[root].r)
//	{
//		ar[root].num = val;
//		return;
//	}
//	pushdown(root);
//	if (x <= ar[root].mid)
//		update_num(root * 2, x, val);
//	else
//		update_num(root * 2 + 1, x, val);
//	pushup(root);
//}
//int query_new(int root, int val)
//{
//	if (ar[root].l == ar[root].r)
//	{
//		return ar[root].l;
//	}
//	pushdown(root);
//	if (ar[root * 2].len >= val)
//		return query_new(root * 2, val);
//	else if (ar[root * 2].rx + ar[root * 2 + 1].lx >= val)
//		return (ar[root * 2].r - ar[root * 2].rx + 1);
//	else
//		return query_new(root * 2 + 1, val);
//}
//int query_free(int root, int x)
//{
//	if (ar[root].l == ar[root].r)
//	{
//		if (ar[root].l == x)
//			return root;
//		else
//			return -1;
//	}
//	pushdown(root);
//	if (x <= ar[root].mid)
//		query_free(root * 2, x);
//	else
//		query_free(root * 2 + 1, x);
//}
//int query_get(int root, int x)
//{
//	if (ar[root].l == ar[root].r)
//	{
//		return root;
//	}
//	pushdown(root);
//	if (x <= ar[root * 2].num)
//		query_get(root * 2, x);
//	else
//		query_get(root * 2 + 1, x - ar[root * 2].num);
//}








//1542   扫描线，区间更新不要pushdown
//#include <cstdio>
//#include <algorithm>
//#include <cmath>
//#include <cstring>
//using namespace std;
//const int maxn = 1100;
//const double eps = 1.0e-9;
//struct Node
//{
//	int l;
//	int r;
//	int mid;
//	int sta;
//	double len;
//};
//Node ar[maxn * 4];
//struct Edge
//{
//	double l;
//	double r;
//	double h;
//	int f;
//};
//Edge edge[maxn * 3];
//bool comp(Edge& a, Edge& b)
//{
//	return a.h < b.h;
//}
//double sep[maxn * 2];
//int cnt, N;
//void pushup(int root)
//{
//	if (ar[root].sta > 0)
//	{
//		ar[root].len = sep[ar[root].r + 1] - sep[ar[root].l];
//	}
//	else if (ar[root].r == ar[root].l)
//	{
//		ar[root].len = 0;
//	}
//	else
//	{
//		ar[root].len = ar[root * 2].len + ar[root * 2 + 1].len;
//	}
//}
//void build(int root, int begin, int end)
//{
//	ar[root].l = begin;
//	ar[root].r = end;
//	ar[root].mid = (begin + end) / 2;
//	ar[root].sta = 0;
//	ar[root].len = 0;
//	if (begin == end)
//	{
//		return;
//	}
//	build(root * 2, ar[root].l, ar[root].mid);
//	build(root * 2 + 1, ar[root].mid + 1, ar[root].r);
//}
//void update(int root, int begin, int end, int val)
//{
//	if (begin <= ar[root].l && ar[root].r <= end)
//	{
//		ar[root].sta += val;
//		pushup(root);
//		return;
//	}
//	if (begin <= ar[root].mid)
//		update(root * 2, begin, end, val);
//	if (end > ar[root].mid)
//		update(root * 2 + 1, begin, end, val);
//	pushup(root);
//}
//int tp_search(int root, double x)
//{
//	int l = ar[root].l;
//	int r = ar[root].r;
//	int mid;
//	while (r >= l)
//	{
//		mid = (l + r) / 2;
//		if (fabs(sep[mid] - x) < eps)
//			return mid;
//		if (sep[mid] > x)
//			r = mid - 1;
//		else if (sep[mid] < x)
//			l = mid + 1;
//	}
//}
//int main()
//{
//	int i, j, k, u, n, m, cas = 1;
//	double x1, x2, y1, y2;
//	while (scanf("%d", &n) != EOF && n)
//	{
//		cnt = 1;
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
//			sep[cnt] = x1;
//			edge[cnt].l = x1;
//			edge[cnt].r = x2;
//			edge[cnt].h = y1;
//			edge[cnt++].f = 1;
//			sep[cnt] = x2;
//			edge[cnt].l = x1;
//			edge[cnt].r = x2;
//			edge[cnt].h = y2;
//			edge[cnt++].f = -1;
//		}
//		cnt--;
//		sort(edge + 1, edge + cnt + 1, comp);
//		sort(sep + 1, sep + cnt + 1);
//		N = 2;
//		for (i = 2; i <= cnt; i++)
//		{
//			if (sep[i] != sep[i - 1])
//				sep[N++] = sep[i];
//		}
//		N--;
//		build(1, 1, N);
//		double res = 0;
//		for (i = 1; i <= cnt; i++)
//		{
//			int L = tp_search(1, edge[i].l);
//			int R = tp_search(1, edge[i].r) - 1;
//			update(1, L, R, edge[i].f);
//			res += ar[1].len * (edge[i + 1].h - edge[i].h);
//		}
//		printf("Test case #%d\n", cas++);
//		printf("Total explored area: %.2f\n\n", res);
//	}
//	return 0;
//}












//CF 1
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//typedef long long ll;
//int main()
//{
//	int i, j, k, n, m, a, b;
//	while (scanf("%d %d", &a, &b) != EOF)
//	{
//		int l = 0;
//		int r = 100000;
//		int mid;
//		while (r >= l)
//		{
//			mid = (l + r) / 2;
//			ll x = (ll)mid*mid;
//			if (x <= a)
//				l = mid + 1;
//			else
//				r = mid - 1;
//		}
//		int posa = r;
//		l = 0;
//		r = 100000;
//		while (r >= l)
//		{
//			mid = (l + r) / 2;
//			ll x = (ll)mid*mid + (ll)mid;
//			if (x <= b)
//				l = mid + 1;
//			else
//				r = mid - 1;
//		}
//		int posb = r;
//		//printf("%d %d\n", posa, posb);
//		if (posa > posb)
//			printf("Valera\n");
//		else
//			printf("Vladik\n");
//	}
//	return 0;
//}






//CF2
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//#include <map>
//using namespace std;
//typedef long long ll;
//const int maxn = 10000 + 10;
//int ar[maxn], sa[maxn];
//int main()
//{
//	int i, j, k, u, n, m, a, b, c;
//	while (scanf("%d %d", &n, &m) != EOF)
//	{
//		for (i = 1; i <= n; i++)
//		{
//			scanf("%d", &ar[i]);
//			sa[i] = ar[i];
//		}
//		for (i = 1; i <= m; i++)
//		{
//			scanf("%d %d %d", &a, &b, &c);
//			int cnt = 0;
//			for (j = a; j <= b; j++)
//			{
//				if (ar[j] < sa[c])
//					cnt++;
//			}
//			if (cnt == c-a)
//				printf("Yes\n");
//			else
//				printf("No\n");
//		}
//	}
//	return 0;
//}







//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <cmath>
//#include <cctype>
//using namespace std;
//typedef unsigned long long ll;
//char ss[51];
//char *sss;
//int N;
//void er(ll n)
//{
//	int cnt = 1;
//	while (n)
//	{
//		if (n % 2)
//		{
//			ss[cnt++] = '1';
//		}
//		else
//		{
//			ss[cnt++] = '0';
//		}
//		n /= 2;
//	}
//	N = cnt-1;
//}
//ll E()
//{
//	int i;
//	ll res = 0, a = 1;
//	for (i = 1; i <= 32; i++)
//	{
//		if (ss[i] == '1')
//		{
//			res += a;
//		}
//		a *= 2;
//	}
//	return res;
//}
//int main()
//{
//	int i, j, k, u, n, m, len;
//	ll a;
//	while (scanf("%lld", &a) != EOF)
//	{
//		memset(ss, '0', sizeof(ss));
//		er(a);
//			for (i = 1; i <= 16; i++)
//			{
//				char t = ss[i];
//				//ss[i] = ss[N - 16 + i];
//				//ss[N - 16 + i] = t;
//				ss[i] = ss[16 + i];
//				ss[16 + i] = t;
//			}
//		printf("%lld\n", E());
//
//	}
//	return 0;
//}


//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <cmath>
//#include <cctype>
//using namespace std;
//typedef long long ll;
//const int maxn = 1000000 + 10;
//ll bag[maxn];
//int main()
//{
//	ll i, j, k, u, n, m, a, b, c, d;
//	ll ar[3], sa[3], sf[3];
//	while (scanf("%lld %lld %lld %lld %lld", &n, &a, &b, &c, &d) != EOF)
//	{
//		memset(bag, 0, sizeof(bag));
//		ar[1] = a;
//		ar[2] = c;
//		sa[1] = b;
//		sa[2] = d;
//		sf[1] = n / a;
//		sf[2] = n / c;
//		for (i = 1; i <= 2; i++)
//		{
//			for (j = ar[i]; j <= n; j++)
//			{
//				bag[j] = (bag[j] < bag[j - ar[i]] + sa[i]) ? (bag[j - ar[i]] + sa[i]) : bag[j];
//			}
//		}
//		printf("%lld\n", bag[n]);
//	}
//	return 0;
//}

//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <cmath>
//#include <cctype>
//using namespace std;
//typedef long long ll;
//const int maxn = 100000 + 10;
//ll ar[maxn];
//ll sa[maxn];
//ll t;
//int main()
//{
//	int i, j, k, u, n, m, a, b, c;
//	while (scanf("%d %d %d", &n, &m, &c) != EOF)
//	{
//		sa[0] = 0;
//		for (i = 1; i <= n; i++)
//		{
//			scanf("%lld", &ar[i]);
//			sa[i] = sa[i - 1] + ar[i];
//		}
//		sort(sa, sa + n+1);
//		ll res = 0;
//		for (i = 1; i <= m; i++)
//		{
//			ll temp = sa[n-i+1] - sa[i-1];
//			if (temp < 0)
//				temp = -temp;
//			if(temp-c>0)
//				res += temp - c;
//		}
//		printf("%lld\n", res);
//	}
//	return 0;
//}






//1394 暴力法；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//const int maxn = 5000 + 10;
//int ar[maxn], sa[maxn];
//int main()
//{
//	int i, j, k, u, n, m, res, cnt, MAX;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (i = 1; i <= n; i++)
//		{
//			scanf("%d", &ar[i]);
//		}
//		cnt = 0;
//		for (i = 1; i <= n; i++)
//		{
//			for (j = i + 1; j <= n; j++)
//			{
//				if (ar[i] > ar[j])
//					cnt++;
//			}
//		}
//		res = cnt;
//		for (i = 1; i < n; i++)
//		{
//			cnt = cnt - ar[i] + (n- 1 - ar[i]);
//			if (res > cnt)
//				res = cnt;
//		}
//		printf("%d\n", res);
//	}
//	return 0;
//}






//4405    概率dp求期望；
//#include <cstdio>
//#include <algorithm>
//#include <cstring>
//#include <cmath>
//#include <vector>
//using namespace std;
//const int maxn = 100000 + 1000;
//double dp[maxn];
//int visit[maxn];
//vector<int>G[maxn];
//int N, M;
//int main()
//{
//	int i, j, k, u, n, m, a, b;
//	while (scanf("%d %d", &N, &M) != EOF && N + M)
//	{
//		for (i = 0; i <= N + 10; i++)
//			G[i].clear();
//		memset(visit, 0, sizeof(visit));
//		memset(dp, 0, sizeof(dp));
//		for (i = 1; i <= M; i++)
//		{
//			scanf("%d %d", &a, &b);
//			G[b].push_back(a);
//		}
//		for (i = 0; i < G[N].size(); i++)
//			visit[G[N][i]] = 1;
//		visit[N] = 1;
//		for (i = N - 1; i >= 0; i--)
//		{
//			if (!visit[i])
//			{
//				for (j = i + 1; j <= i + 6; j++)
//					dp[i] += dp[j] / 6.0;
//				dp[i] += 1.0;
//				visit[i] = 1;
//			}
//			for (j = 0; j < G[i].size(); j++)
//			{
//				dp[G[i][j]] = dp[i];
//				visit[G[i][j]] = 1;
//			}
//		}
//		printf("%.4f\n", dp[0]);
//	}
//	return 0;
//}







//4089   概率dp求期望，有坑，p4 < 0， 手推一下dp[i][i] 然后依次求1-》i；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <cmath>
//#include <vector>
//using namespace std;
//const int maxn = 2000 + 100;
//const double eps = 1e-9;
//int N, M, K;
//double p1, p2, p3, p4;
//double dp[maxn][maxn], c[maxn], e[maxn];
//int main()
//{
//	int i, j, k, u, n, m, a, b;
//	while (scanf("%d %d %d %lf %lf %lf %lf", &N, &M, &K, &p1, &p2, &p3, &p4) != EOF)
//	{
//		if (p4 < eps)
//		{
//			printf("0.00000\n");
//			continue;
//		}
//		p2 = p2 / (1.0 - p1);
//		p3 = p3 / (1.0 - p1);
//		p4 = p4 / (1.0 - p1);
//		e[0] = 1.0;
//		for (i = 1; i <= N; i++)
//			e[i] = e[i - 1] * p2;
//		c[1] = p4;
//		dp[1][1] = p4 / (1.0 - p2);
//		for (i = 2; i <= N; i++)
//		{
//			for (j = 2; j <= K && j <= i; j++)
//			{
//				c[j] = p3*dp[i - 1][j - 1] + p4;
//			}
//			for (j = K + 1; j <= i; j++)
//			{
//				c[j] = p3*dp[i - 1][j - 1];
//			}
//			double t = 0.0;
//			for (j = 1; j <= i; j++)
//				t += e[i - j] * c[j];
//			dp[i][i] = t / (1.0 - e[i]);
//			dp[i][1] = p2*dp[i][i] + c[1];
//			for (j = 2; j < i; j++)
//			{
//				dp[i][j] = p2*dp[i][j - 1] + c[j];
//			}
//		}
//		printf("%.5f\n", dp[N][M]);
//	}
//	return 0;
//}






//4035   概率dp    手动整理化简， 注意一定要用到已经算过的数据， 一定要从最末状态推到最初状态，数组记录的是从这里到末状态时的期望；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <cmath>
//#include <vector>
//using namespace std;
//const int maxn = 10000 + 100;
//vector<int>G[maxn];
//double A[maxn], B[maxn], C[maxn], E[maxn], K[maxn];
//const double eps = 1.0e-9;
//int N, M;
//bool dfs(int cur, int pre)
//{
//	int i, j;
//	int num = G[cur].size();
//	A[cur] = K[cur];
//	B[cur] = (1.0 - K[cur] - E[cur]) / (double)num;
//	C[cur] = 1.0 - K[cur] - E[cur];
//	double t = 0.0;
//	for (i = 0; i < num; i++)
//	{
//		if (G[cur][i] == pre)
//			continue;
//		if (!dfs(G[cur][i], cur))
//		{
//			return false;
//		}
//		A[cur] += (1.0 - K[cur] - E[cur]) / num * A[G[cur][i]];
//		C[cur] += (1.0 - K[cur] - E[cur]) / num * C[G[cur][i]];
//		t += (1.0 - K[cur] - E[cur]) / num * B[G[cur][i]];
//	}
//	if (fabs(t - 1.0) < eps)
//	{
//		return false;
//	}
//	A[cur] /= (1.0 - t);
//	B[cur] /= (1.0 - t);
//	C[cur] /= (1.0 - t);
//	return true;
//}
//int main()
//{
//	int i, j, k, u, n, m, a, b, c;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &N);
//			for (i = 0; i <= N; i++)
//				G[i].clear();
//			for (i = 1; i < N; i++)
//			{
//				scanf("%d %d", &a, &b);
//				G[a].push_back(b);
//				G[b].push_back(a);
//			}
//			for (i = 1; i <= N; i++)
//			{
//				scanf("%lf %lf", &K[i], &E[i]);
//				K[i] /= 100.0;
//				E[i] /= 100.0;
//			}
//			if (dfs(1, -1) && fabs(1.0 - A[1]) > eps)
//			{
//				printf("Case %d: %.6f\n", m, C[1] / (1.0 - A[1]));
//			}
//			else
//			{
//				printf("Case %d: impossible\n", m);
//			}
//		}
//	}
//	return 0;
//}






//4336     概率dp 状态压缩；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//#include <cmath>
//using namespace std;
//const int maxn = 20 + 5;
//double dp[1 << maxn], ar[maxn];
//int N;
//double all;
//int main()
//{
//	int i, j, k, u, n, m, a, b, c;
//	while (scanf("%d", &N) != EOF)
//	{
//		all = 0.0;
//		for (i = 1; i <= N; i++)
//		{
//			scanf("%lf", &ar[i]);
//			all += ar[i];
//		}
//		all = 1.0 - all;
//		dp[(1 << N) - 1] = 0;
//		for (i = (1 << N) - 2; i >= 0; i--)
//		{
//			double x = 0.0;
//			double sum = 1.0;
//			for (j = 1; j <= N; j++)
//			{
//				if (i & (1 << (j - 1)))
//				{
//					x += ar[j];
//				}
//				else
//				{
//					sum += ar[j] * dp[i | (1 << (j - 1))];
//				}
//				dp[i] = sum / (1.0 - x - all);
//			}
//		}
//		printf("%.5f\n", dp[0]);
//	}
//	return 0;
//}






//4418     概率dp + 搜可行点；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//#include <cmath>
//#include <queue>
//using namespace std;
//const int maxn = 1100;
//const double eps = 1.0e-9;
//int zushu, var;
//int N, M, X, Y, D;
//double a[maxn][maxn], x[maxn], p[maxn];
//int visit[maxn];
//void bfs()
//{
//	queue<int>q;
//	memset(visit, 0, sizeof(visit));
//	int i, j, cnt = 1, u, v;
//	visit[X] = cnt++;
//	q.push(X);
//	while (!q.empty())
//	{
//		u = q.front();
//		q.pop();
//		for (i = 1; i <= M; i++)
//		{
//			int t = (u + i) % N;
//			if (fabs(p[i]) < eps)
//				continue;
//			if (!visit[t])
//			{
//				q.push(t);
//				visit[t] = cnt++;
//			}
//		}
//	}
//	zushu = var = cnt - 1;
//}
//void build()
//{
//	int i, j;
//	memset(a, 0, sizeof(a));
//	memset(x, 0, sizeof(x));
//	for (i = 0; i < N; i++)
//	{
//		if (visit[i])
//		{
//			a[visit[i]][visit[i]] = 1;
//			if (i == Y || i == (N - Y))
//			{
//				x[visit[i]] = 0;
//				continue;
//			}
//			for (j = 1; j <= M; j++)
//			{
//				if (visit[(i + j) % N])
//				{
//					a[visit[i]][visit[(i + j) % N]] -= p[j];
//					x[visit[i]] += j*p[j];
//				}
//			}
//		}
//	}
//}
//int Gauss()
//{
//	int i, j, k, u, col, max_r;
//	for (k = 1, col = 1; k <= zushu && col <= var; k++, col++)
//	{
//		max_r = k;
//		for (i = k + 1; i <= zushu; i++)
//		{
//			if (fabs(a[i][col]) > fabs(a[max_r][col]))
//				max_r = i;
//		}
//		if (fabs(a[max_r][col]) < eps)
//			return 0;
//		if (k != max_r)
//		{
//			for (j = col; j <= var; j++)
//				swap(a[k][j], a[max_r][j]);
//			swap(x[k], x[max_r]);
//		}
//		x[k] /= a[k][col];
//		for (j = col + 1; j <= var; j++)
//			a[k][j] /= a[k][col];
//		a[k][col] = 1;
//		for (i = 1; i <= zushu; i++)
//		{
//			if (i != k)
//			{
//				x[i] -= x[k] * a[i][col];
//				for (j = col + 1; j <= var; j++)
//					a[i][j] -= a[k][j] * a[i][col];
//				a[i][col] = 0;
//			}
//		}
//	}
//	return 1;
//}
//int main()
//{
//	int i, j, k, u, b, c, n, m;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d %d %d %d", &N, &M, &Y, &X, &D);
//			for (i = 1; i <= M; i++)
//			{
//				scanf("%lf", &p[i]);
//				p[i] /= 100.0;
//			}
//			if (X == Y)
//			{
//				printf("0.00\n");
//				continue;
//			}
//			N = (N - 1) * 2;
//			if (D == 1)
//				X = N - X;
//			bfs();
//			if (!visit[Y] && !visit[N - Y])
//			{
//				printf("Impossible !\n");
//				continue;
//			}
//			build();
//			if (Gauss())
//			{
//				printf("%.2f\n", x[visit[X]]);
//			}
//			else
//			{
//				printf("Impossible !\n");
//			}
//		}
//	}
//	return 0;
//}







//2262    概率dp + bfs给可行点编号+ 高斯消元（这次写错了555555）；
//#include <cstdio>
//#include <cstring>
//#include <cmath>
//#include <algorithm>
//#include <vector>
//#include <queue>
//using namespace std;
//const int maxn = 20;
//const double eps = 1.0e-9;
//struct Node
//{
//	int x;
//	int y;
//};
//Node now, after;
//int N, M, bx, by, zushu, var, Count;
//int dir[4][2] = { -1, 0, 0, -1, 1, 0, 0, 1 };
//char ar[maxn][maxn];
//int visit[maxn][maxn];
//double a[maxn*maxn][maxn*maxn], x[maxn*maxn];
//vector<int>G[maxn*maxn];
//int bfs()
//{
//	int i, j, doudou = 0;
//	Count = 1;
//	memset(a, 0, sizeof(a));
//	memset(x, 0, sizeof(x));
//	queue<Node>q;
//	for (i = 0; i < maxn*maxn; i++)
//		G[i].clear();
//	memset(visit, 0, sizeof(visit));
//	now.x = bx;
//	now.y = by;
//	q.push(now);
//	visit[now.x][now.y] = Count++;
//	while (!q.empty())
//	{
//		now = q.front();
//		q.pop();
//		for (i = 0; i < 4; i++)
//		{
//			after.x = now.x + dir[i][0];
//			after.y = now.y + dir[i][1];
//			if (after.x < 1 || after.y < 1 || after.x > N || after.y > M || ar[after.x][after.y] == '#')
//				continue;
//			if (ar[after.x][after.y] == '$')
//				doudou = 1;
//			if (!visit[after.x][after.y])
//			{
//				q.push(after);
//				visit[after.x][after.y] = Count++;
//			}
//			G[visit[now.x][now.y]].push_back(visit[after.x][after.y]);
//		}
//		if (ar[now.x][now.y] == '$')
//		{
//			a[visit[now.x][now.y]][visit[now.x][now.y]] = 1;
//			x[visit[now.x][now.y]] = 0;
//		}
//		else
//		{
//			a[visit[now.x][now.y]][visit[now.x][now.y]] = 1;
//			for (i = 0; i < G[visit[now.x][now.y]].size(); i++)
//			{
//				a[visit[now.x][now.y]][G[visit[now.x][now.y]][i]] = -1.0 / G[visit[now.x][now.y]].size();
//			}
//			x[visit[now.x][now.y]] = 1;
//		}
//	}
//	return doudou;
//}
////void build()
////{
////	int i, j, k, u;
////	for (i = 0; i < maxn*maxn; i++)
////		G[i].clear();
////	memset(a, 0, sizeof(a));
////	memset(x, 0, sizeof(x));
////	for (i = 1; i <= N; i++)
////	{
////		for (j = 1; j <= M; j++)
////		{
////			if (visit[i][j])
////			{
////				if (ar[i][j] == '$')
////				{
////					a[visit[i][j]][visit[i][j]] = 1;
////					x[visit[i][j]] = 0;
////					continue;
////				}
////				int cnt = 0;
////				for (u = 0; u < 4; u++)
////				{
////					int xx = i + dir[u][0];
////					int yy = j + dir[u][1];
////					if (xx < 1 || xx > N || yy < 1 || yy > M || ar[xx][yy] == '#')
////						continue;
////					if (!visit[xx][yy])
////						continue;
////					cnt++;
////					G[visit[i][j]].push_back(visit[xx][yy]);
////				}
////				a[visit[i][j]][visit[i][j]] = 1;
////				for (u = 0; u < G[visit[i][j]].size(); u++)
////				{
////					a[visit[i][j]][G[visit[i][j]][u]] = -1.0 / (double)cnt;
////				}
////				x[visit[i][j]] = 1;
////			}
////		}
////	}
////}
//int Guass()
//{
//	int i, j, k, u, max_r, col;
//	for (k = 1, col = 1; k <= zushu && col <= var; k++, col++)
//	{
//		max_r = k;
//		for (i = k + 1; i <= zushu; i++)
//		{
//			if (fabs(a[i][col]) > fabs(a[max_r][col]))
//				max_r = i;
//		}
//		if (fabs(a[max_r][col]) < eps)
//			return 0;
//		if (max_r != k)
//		{
//			for (i = col; i <= var; i++)
//			{
//				swap(a[k][i], a[max_r][i]);
//			}
//			swap(x[k], x[max_r]);
//		}
//		for (j = col + 1; j <= var; j++)
//		{
//			a[k][j] /= a[k][col];
//		}
//		x[k] /= a[k][col];
//		a[k][col] = 1;
//		for (i = 1; i <= zushu; i++)
//		{
//			if (i != k)
//			{
//				for (j = col + 1; j <= var; j++)
//				{
//					a[i][j] -= a[k][j] * a[i][col];
//				}
//				x[i] -= x[k] * a[i][col];
//				a[i][col] = 0;
//			}
//		}
//	}
//	return 1;
//}
//int main()
//{
//	int i, j, k, u, n, m;
//	while (scanf("%d %d", &N, &M) != EOF)
//	{
//		for (i = 1; i <= N; i++)
//		{
//			scanf("%s", ar[i] + 1);
//			for (j = 1; j <= M; j++)
//			{
//				if (ar[i][j] == '@')
//				{
//					bx = i;
//					by = j;
//				}
//			}
//		}
//		if (!bfs())
//		{
//			printf("-1\n");
//			continue;
//		}
//		zushu = var = Count - 1;
//		//build();
//		if (Guass())
//		{
//			printf("%.6f\n", x[visit[bx][by]]);
//		}
//		//for (i = 1; i < Count; i++)
//		//	printf("%.6f\n", x[i]);
//		else
//		{
//			printf("-1\n");
//		}
//	}
//	return 0;
//}










// 思维训练1.5					分块
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <cmath>
//using namespace std;
//int main()
//{
//	int i, j, k, u, n, m, a, b, c, d, e, f;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d %d %d", &a, &b, &c, &d);
//			if (b > d)
//			{
//				swap(b, d);
//				swap(a, c);
//			}
//			if (a >= c)
//			{
//				printf("%d\n", b);
//				continue;
//			}
//			int res = 0;
//			for (i = 1; i <= b; i = j + 1)
//			{
//				j = min(b / (b / i), d / (d / i));
//				if (i < a)
//					j = min((a - 1) / ((a - 1) / i), j);
//				if (i < c)
//					j = min((c - 1) / ((c - 1) / i), j);
//				if (b / i >(a - 1) / i && d / i >(c - 1) / i)
//					res = j;
//			}
//			printf("%d\n", res);
//		}
//	}
//	return 0;
//}






//思维训练1.8       
//k为询问的数，l为要平移的前缀和左端，r为右端；
//考虑全为1时，1~N全部可以表示，若把其中一个1换为2，则该位置的前缀和表示的数将多了1，那么只需要把第一个1去掉（即l+1 即可）
//若再把一个1 换为2，则再把当前的一个1去掉（l+1）。。。。。。。
//所以，若没有前缀和等于k，如果可以表示k，则一定有前缀和等于k+1（因为只有1和2，跳跃距离最多为2）
//平移该前缀和，若l和r有至少一个为1，就可以表示了（因为平移时是k+1，所以只要有一个1就把它去掉则满足k，若有2个1，则多往前一个，把最后一个1去掉就行了）
//否则继续平移，直到r==N+1时，若没有找到1，则不存在；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//#include <map>
//using namespace std;
//const int maxn = 1000000 + 100;
//int s[maxn], visit[maxn * 2];
//char ar[maxn];
//map<char, int>q;
//int N, M;
//int main()
//{
//	q['W'] = 1;
//	q['T'] = 2;
//	int i, j, k, u, n, m;
//	while (scanf("%d %d", &N, &M) != EOF)
//	{
//		scanf("%s", ar + 1);
//		memset(visit, 0, sizeof(visit));
//		s[0] = 0;
//		for (i = 1; i <= N; i++)
//		{
//			s[i] = s[i - 1] + q[ar[i]];
//			visit[s[i]] = i;
//		}
//		for (m = 1; m <= M; m++)
//		{
//			scanf("%d", &k);
//			if (k > s[N])
//			{
//				printf("NIE\n");
//				continue;
//			}
//			if (visit[k])
//			{
//				printf("TAK\n");
//				continue;
//			}
//			if (visit[k + 1])
//			{
//				int doudou = 0;
//				int l = 1;
//				int r = visit[k + 1];
//				while (r <= N)
//				{
//					if ((ar[l] == 'W' && ar[r] == 'T') || (ar[l] == 'T' && ar[r] == 'W') || (ar[l] == 'W' && ar[r] == 'W'))
//					{
//						doudou = 1;
//						break;
//					}
//					l++;
//					r++;
//				}
//				if (!doudou)
//					printf("NIE\n");
//				else
//					printf("TAK\n");
//			}
//			else
//			{
//				printf("NIE\n");
//			}
//		}
//	}
//	return 0;
//}





//思维训练1.6         树形贪心
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//using namespace std;
//const int maxn = 300000 + 100;
//int N, M, tot, cnt;
//int ar[maxn], sta[maxn];			//0表示未被覆盖到，1表示已经被覆盖到了
//int MAX_UP[maxn];					//能扩展到的最远距离（可以赊账）
//vector<int>G[maxn];
//void dfs(int cur, int pre, int num)
//{
//	int i, j, u, v;
//	int maxup = -1;			//记录该点能扩展的最远距离，初始化为叶子结点的距离-1
//	int farmiss = ar[cur] - 1;					//记录到该点的，需要被覆盖的而未被覆盖的最远点，的距离，初始化为叶子结点，若是叶子关键点则为0，若为叶子非关键点则为-1
//	for (i = 0; i < G[cur].size(); i++)
//	{
//		v = G[cur][i];
//		if (v == pre)
//			continue;
//		dfs(v, cur, num);				//一直搜到叶子结点开始回溯，并记录信息
//	}
//	for (i = 0; i < G[cur].size(); i++)				//找出离该点最远的关键点和能扩展的最远距离，根据子节点找（dp思想）
//	{
//		v = G[cur][i];
//		if (v == pre)
//			continue;
//		if (sta[v] == 1)					//若该子节点被覆盖了，则无需关心离他最远的关键点，只需记录还能扩展的距离
//		{
//			maxup = max(maxup, MAX_UP[v] - 1);
//		}
//		if (sta[v] == 0)					//若该子节点未被覆盖，则需要根据它记录最远的关键点，他没有扩展能力
//		{
//			farmiss = max(farmiss, MAX_UP[v] + 1);
//		}
//	}
//	if (maxup < farmiss)
//	{
//		if (farmiss == num)
//		{
//			tot++;
//			MAX_UP[cur] = num;
//			sta[cur] = 1;
//		}
//		else							//可以赊账，如果该节点的可扩展范围达不到最远关键点，可以假设还有其它树上的点能覆盖到它，在这里不加引燃点，一直到不能再赊账为止（farmiss == num）
//		{
//			MAX_UP[cur] = farmiss;
//			sta[cur] = 0;
//		}
//	}
//	else if (maxup >= farmiss)				//该点的可扩展范围能达到最远关键点
//	{
//		MAX_UP[cur] = maxup;
//		sta[cur] = 1;
//	}
//	else						//非关键点
//	{
//		MAX_UP[cur] = 0;
//		sta[cur] = 2;
//	}
//}
//bool check(int num)
//{
//	int i, j;
//	tot = 0;
//	dfs(1, -1, num);
//	if (sta[1] == 0)
//		tot++;
//	return tot <= M;
//}
//int main()
//{
//	int i, j, k, u, n, m, a, b;
//	while (scanf("%d %d", &N, &M) != EOF)
//	{
//		for (i = 1; i <= N; i++)
//		{
//			scanf("%d", &ar[i]);
//			G[i].clear();
//		}
//		for (i = 1; i < N; i++)
//		{
//			scanf("%d %d", &a, &b);
//			G[a].push_back(b);
//			G[b].push_back(a);
//		}
//		int l = 0;
//		int r = N + 1;
//		int mid;
//		while (r >= l)				//二分枚举需要的距离，找最少的tot是否小于M
//		{
//			mid = (l + r) / 2;
//			if (check(mid))
//				r = mid - 1;
//			else
//				l = mid + 1;
//		}
//		printf("%d\n", l);
//	}
//	return 0;
//}






//思维训练1.9      dp
//dist[i][j] 表示从i到j的最短回文路径
//dist_temp[i][j][c]表示从i到j除去最后一步c是回文路径的最短距离
//在dp时，是从每一条题目给的边开始加入队列并扩展
//扩展方式：
//如果队列中该点的c是27，则说明now.u到now.v的dist已经完成了，则需要扩展now.v的下一个c，下一个点记为v，该now.u和v对应的c为now.v扩展到的点（0~25）；
//如果该点的c是0~25，说明改点的v扩展过了，需要将now.u反扩展（即从now.u也走一步c，该c与v扩展的c相同，反扩展的点记为u），这样就可以形成新的u，v的dist，该u，v对应的c自然是27
//这样一直扩展下去直到所有能被扩展到的点都被扩展过了
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <cctype>
//#include <queue>
//#include <vector>
//using namespace std;
//const int maxn = 60000 + 100;
//struct Node
//{
//	int u;
//	int v;
//	int c;
//	Node() {}
//	Node(int a, int b, int d) : u(a), v(b), c(d) {}
//	Node(const Node& p)
//	{
//		u = p.u;
//		v = p.v;
//		c = p.c;
//	}
//};
//Node now;
//queue<Node>q;
//vector<Node>G_to[450], from_G[450];
//int N, M, K;
//int ar[450][450][30], S[110];
//int dist[450][450], dist_temp[450][450][30];
//int main()
//{
//	int i, j, k, u, n, m, a, b;
//	char s[5];
//	while (scanf("%d %d", &N, &M) != EOF)
//	{
//		memset(ar, 0, sizeof(ar));
//		memset(dist, -1, sizeof(dist));
//		memset(dist_temp, -1, sizeof(dist_temp));
//		while (!q.empty())
//			q.pop();
//		for (i = 0; i <= 401; i++)
//		{
//			G_to[i].clear();
//			from_G[i].clear();
//		}
//		for (i = 1; i <= N; i++)
//		{
//			dist[i][i] = 0;
//			q.push(Node(i, i, 27));
//		}
//		for (i = 1; i <= M; i++)
//		{
//			scanf("%d %d %s", &a, &b, s);
//			G_to[a].push_back(Node(a, b, s[0] - 'a'));
//			from_G[b].push_back(Node(a, b, s[0] - 'a'));
//			dist[a][b] = 1;
//			q.push(Node(a, b, 27));
//		}
//		while (!q.empty())
//		{
//			int t;
//			now = q.front();
//			q.pop();
//			if (now.c == 27)
//			{
//				t = dist[now.u][now.v];
//			}
//			else
//			{
//				t = dist_temp[now.u][now.v][now.c];
//			}
//			if (now.c == 27)
//			{
//				for (i = 0; i < G_to[now.v].size(); i++)
//				{
//					int v = G_to[now.v][i].v;
//					int c = G_to[now.v][i].c;
//					if (dist_temp[now.u][v][c] == -1)
//					{
//						dist_temp[now.u][v][c] = t + 1;
//						q.push(Node(now.u, v, c));
//					}
//				}
//			}
//			else
//			{
//				for (i = 0; i < from_G[now.u].size(); i++)
//				{
//					int u = from_G[now.u][i].u;
//					int c = from_G[now.u][i].c;
//					if (c == now.c)
//					{
//						if (dist[u][now.v] == -1)
//						{
//							dist[u][now.v] = t + 1;
//							q.push(Node(u, now.v, 27));
//						}
//					}
//				}
//			}
//		}
//		scanf("%d", &K);
//		scanf("%d", &S[1]);
//		for (i = 2; i <= K; i++)
//		{
//			scanf("%d", &S[i]);
//			printf("%d\n", dist[S[i - 1]][S[i]]);
//		}
//	}
//	return 0;
//}









//1848     nim+Fibonacci
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <map>
//using namespace std;
//const int maxn = 1000 + 100;
//int Fibo[maxn];
//int E[maxn];
//int temp[maxn];
//int main()
//{
//	int i, j, k, u, n, m, a, b, c;
//	Fibo[1] = 1;
//	Fibo[2] = 2;
//	for (i = 3; i <= 16; i++)
//	{
//		Fibo[i] = Fibo[i - 1] + Fibo[i - 2];
//	}
//	E[0] = 0;
//	E[1] = 1;
//	E[2] = 2;
//	E[3] = 3;
//	for (i = 4; i <= 1000; i++)
//	{
//		memset(temp, 0, sizeof(temp));
//		for (j = 1; Fibo[j] <= i; j++)
//		{
//			temp[E[i - Fibo[j]]] = 1;
//		}
//		for (j = 0; j <= i; j++)
//		{
//			if (!temp[j])
//			{
//				E[i] = j;
//				break;
//			}
//		}
//	}
//	while (scanf("%d %d %d", &a, &b, &c) != EOF && a + b + c)
//	{
//		if ((E[a] ^ E[b] ^ E[c]) == 0)
//			printf("Nacci\n");
//		else
//			printf("Fibo\n");
//	}
//	return 0;
//}








//1849    nim;
//#include <cstdio>
//#include <cstring>
//using namespace std;
//int main()
//{
//	int i, j, k, n, m, t, a;
//	while (scanf("%d", &n) != EOF && n)
//	{
//		t = 0;
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d", &a);
//			t ^= a;
//		}
//		if (t == 0)
//		{
//			printf("Grass Win!\n");
//		}
//		else
//		{
//			printf("Rabbit Win!\n");
//		}
//	}
//	return 0;
//}






//1850   nim博弈  找先手可以赢的个数；
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//const int maxn = 110;
//int main()
//{
//	int i, j, k, ar[maxn], s, t, cnt;
//	while (scanf("%d", &n) != EOF && n)
//	{
//		cnt = s = t = 0;
//		for (i = 1; i <= n; i++)
//		{
//			scanf("%d", &ar[i]);
//			s ^= ar[i];
//		}
//		for (i = 1; i <= n; i++)
//		{
//			t = s ^ ar[i];
//			if (t < ar[i])
//				cnt++;
//		}
//		printf("%d\n", cnt);
//	}
//	return 0;
//}






//2149      基础博弈
//#include <cstdio>
//#include <cstring>
//using namespace std;
//int main()
//{
//	int i, j, k, u, n, m, a, b, doudou;
//	while (scanf("%d %d", &n, &m) != EOF)
//	{
//		if (m >= n)
//		{
//			doudou = 0;
//			while (m >= n)
//			{
//				if (doudou)
//					putchar(' ');
//				doudou = 1;
//				printf("%d", n++);
//			}
//			putchar('\n');
//		}
//		else if (n % (m + 1) == 0)
//		{
//			printf("none\n");
//		}
//		else
//		{
//			printf("%d\n", n % (m + 1));
//		}
//	}
//	return 0;
//}





//2188
//#include <cstdio>
//#include <cstring>
//using namespace std;
//int main()
//{
//	int i, j, k, u, n, m, a, b, doudou;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (m = 1; m <= n; m++)
//		{
//			scanf("%d %d", &a, &b);
//			if (b >= a)
//			{
//				printf("Grass\n");
//			}
//			else if (a % (b + 1) == 0)
//			{
//				printf("Rabbit\n");
//			}
//			else
//			{
//				printf("Grass\n");
//			}
//		}
//	}
//	return 0;
//}







//CF2.1
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//#include <map>
//#include <vector>
//#include <cmath>
//#include <cctype>
//using namespace std;
//const int maxn = 10;
//int ar[maxn][maxn];
//int main()
//{
//	int i, j, k, u, n, m, doudou;
//	while (scanf("%d %d %d %d", &ar[1][1], &ar[1][2], &ar[1][3], &ar[1][4]) != EOF)
//	{
//		doudou = 0;
//		scanf("%d %d %d %d", &ar[2][1], &ar[2][2], &ar[2][3], &ar[2][4]);
//		scanf("%d %d %d %d", &ar[3][1], &ar[3][2], &ar[3][3], &ar[3][4]);
//		scanf("%d %d %d %d", &ar[4][1], &ar[4][2], &ar[4][3], &ar[4][4]);
//		if (ar[1][4])
//		{
//			if (ar[1][1] || ar[1][2] || ar[1][3] || ar[2][1] || ar[3][2] || ar[4][3])
//				doudou = 1;
//		}
//		if (ar[2][4])
//		{
//			if (ar[1][3] || ar[2][1] || ar[2][2] || ar[2][3] || ar[3][1] || ar[4][2])
//				doudou = 1;
//		}
//		if (ar[3][4])
//		{
//			if (ar[1][2] || ar[2][3] || ar[3][1] || ar[3][2] || ar[3][3] || ar[4][1])
//				doudou = 1;
//		}
//		if (ar[4][4])
//		{
//			if (ar[1][1] || ar[2][2] || ar[3][3] || ar[4][1] || ar[4][2] || ar[4][3])
//				doudou = 1;
//		}
//		if (doudou)
//			printf("YES\n");
//		else
//			printf("NO\n");
//	}
//	return 0;
//}







//CF2.3
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//#include <map>
//#include <vector>
//#include <cmath>
//#include <cctype>
//#include <iostream>
//using namespace std;
//const int maxn = 100000 + 10;
//typedef unsigned __int64 ll;
//ll ar[maxn], sa[maxn];
//int N, M;
//int main()
//{
//	int i, j, k, u, n, m;
//	while (cin >> N >> M)
//	{
//		for (i = 1; i <= N; i++)
//		{
//			cin >> ar[i];
//		}
//		int l = 0;
//		int r = N;
//		int mid;
//		ll sum = 0;
//		ll res = 0;
//		while (r >= l)
//		{
//			sum = 0;
//			mid = (l + r) / 2;
//			for (i = 1; i <= N; i++)
//				sa[i] = ar[i] + i*mid;
//			sort(sa + 1, sa + N + 1);
//			for (i = 1; i <= mid; i++)
//				sum += sa[i];
//			if (sum <= M)
//			{
//				res = sum;
//				l = mid + 1;
//			}
//			else
//				r = mid - 1;
//		}
//		cout << r << " " << res << endl;
//	}
//	return 0;
//}








//CF3.1
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <cmath>
//#include <vector>
//using namespace std;
//const int maxn = 1000 + 100;
//int ar[maxn], sa[maxn];
//struct Edge
//{
//	int l;
//	int r;
//	int len;
//};
//Edge edge[maxn];
//int visit[100010];
//int N, M;
//bool comp(const Edge& a, const Edge& b)
//{
//	return a.r < b.l;
//}
//int main()
//{
//	int i, j, k, u, n, m, a, b, Max;
//	while (scanf("%d", &N) != EOF)
//	{
//		int sum = 0;
//		for (i = 1; i <= N; i++)
//		{
//			scanf("%d", &ar[i]);
//			sum += ar[i];
//		}
//		scanf("%d", &M);
//		memset(visit, 0, sizeof(visit));
//		Max = -1;
//		for (i = 1; i <= M; i++)
//		{
//			scanf("%d %d", &edge[i].l, &edge[i].r);
//			edge[i].len = edge[i].r - edge[i].l + 1;
//			visit[edge[i].l]++;
//			visit[edge[i].r + 1]--;
//			if (Max < edge[i].r)
//				Max = edge[i].r;
//		}
//		for (i = 1; i <= Max; i++)
//		{
//			visit[i] += visit[i - 1];
//			if (i >= sum && visit[i])
//				break;
//		}
//		if (i <= Max)
//			printf("%d\n", i);
//		else
//			printf("-1\n");
//	}
//	return 0;
//}









//CF3.3
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <cmath>
//#include <vector>
//using namespace std;
//const int maxn = 200000 + 100;
//const int INF = 1000000000;
//int N, X;
//vector<int>G[maxn * 2], F[maxn * 2];
//int dep[maxn], head[maxn];
//int res;
//void dfs(int cur, int pre, int num)
//{
//	int i, j;
//	res = max(res, dep[cur]);
//	for (i = 0; i < F[cur].size(); i++)
//	{
//		dfs(F[cur][i], cur, num + 1);
//	}
//}
//void dfs1(int cur, int pre, int de)
//{
//	int i, j;
//	dep[cur] = de;
//	head[cur] = pre;
//	for (i = 0; i < G[cur].size(); i++)
//	{
//		if (G[cur][i] == pre)
//			continue;
//		F[cur].push_back(G[cur][i]);
//		dfs1(G[cur][i], cur, de+1);
//	}
//	return;
//}
//int main()
//{
//	int i, j, k, a, b, n, m;
//	while (scanf("%d %d", &N, &X) != EOF)
//	{
//		for (i = 0; i <= N; i++)
//		{
//			G[i].clear();
//			F[i].clear();
//		}
//		for (i = 1; i < N; i++)
//		{
//			scanf("%d %d", &a, &b);
//			G[a].push_back(b);
//			G[b].push_back(a);
//		}
//		if (X == 1)
//		{
//			printf("0\n");
//			continue;
//		}
//		dfs1(1, 0, 0);
//		int l = 0;
//		int r = X;
//		int doudou = 0;
//		while (dep[head[r]] > ++l)
//		{
//			r = head[r];
//		}
//		//if (l < dep[r])
//		//	l++;
//		res = 0;
//		dfs(r, head[r], 1);
//		printf("%d\n", 2*res);
//	}
//	return 0;
//}
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <cmath>
//#include <vector>
//using namespace std;
//const int maxn = 200000 + 100;
//const int INF = 1000000000;
//int N, X;
//vector<int>G[maxn * 2], F[maxn * 2];
//int dep[maxn], head[maxn];
//int dfs(int cur, int pre, int num)
//{
//	int i, j;
//	int m = 0;
//	if (F[cur].size() == 0)
//		return num;
//	for (i = 0; i < F[cur].size(); i++)
//	{
//		//if (F[cur][i] == pre)
//		//	continue;
//		int t = dfs(F[cur][i], cur, num + 1);
//		if (m < t)
//		{
//			m = t;
//		}
//	}
//	return m;
//}
//void dfs1(int cur, int pre, int de)
//{
//	int i, j;
//	dep[cur] = de;
//	head[cur] = pre;
//	for (i = 0; i < G[cur].size(); i++)
//	{
//		if (G[cur][i] == pre)
//			continue;
//		F[cur].push_back(G[cur][i]);
//		dfs1(G[cur][i], cur, de + 1);
//	}
//	return;
//}
//int main()
//{
//	int i, j, k, a, b, n, m;
//	while (scanf("%d %d", &N, &X) != EOF)
//	{
//		for (i = 0; i <= N; i++)
//		{
//			G[i].clear();
//			F[i].clear();
//		}
//		for (i = 1; i < N; i++)
//		{
//			scanf("%d %d", &a, &b);
//			G[a].push_back(b);
//			G[b].push_back(a);
//		}
//		if (X == 1)
//		{
//			printf("0\n");
//			continue;
//		}
//		dfs1(1, 0, 0);
//		int l = 0;
//		int r = X;
//		int doudou = 0;
//		while (dep[head[r]] > ++l)
//		{
//			r = head[r];
//		}
//		int t = dfs(r, head[r], 0);
//		if (l < dep[r])
//			l++;
//		printf("%d\n", 2 * (t + l));
//	}
//	return 0;
//}
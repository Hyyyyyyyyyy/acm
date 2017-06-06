//因为打印的空格和 * 比较多，很多代码都是处理版面的；
#include <stdio.h>
void MONTH_DAY(int, int, char(*w)[7], char(*t)[7], char(*b)[7]);		//打印日期的主要函数；
bool Isleapyear(int);			//判断是否是闰年；
int Isday(int, int, int *, int *);			//判断每个月1号是星期几；
FILE * p;
char week[7][7] = { "星期日" , "星期一" , "星期二" , "星期三" , "星期四" , "星期五" , "星期六" };

int main()
{
	int year, i;

	char(*W)[7], (*turn)[7], (*begin)[7];
	bool flag = false;


	W = week;
	turn = &week[6];
	begin = week;
	p = fopen("D:\\万年历.txt", "w");

	fputs("Please enter the year (XXXX):\n", p);
	while (scanf("%d", &year) == 1 && year >= 1)
	{
		flag = true;
		fprintf(p, "\n%30d年年历\n", year);
		fprintf(p, "%25s(强哥最帅!!!)\n\n", " ");
		fprintf(p, "%30s%d 月\n\n", " ", 1);
		for (i = 1; i <= 73; i = i + 2)
			fprintf(p, "* ");


		fprintf(p, "\n*%72s\n*", "*");

		for (i = 0; i < 7; i++)
			fprintf(p, "%10s", week[i]);

		fprintf(p, " *\n*%72s\n*", "*");

		//开始打印；
		for (i = 1; i <= 12; i++)
		{
			MONTH_DAY(year, i, W, turn, begin);
		}

		fputc('\n', p);
		fputc('\n', p);
		fputs("Please enter the year again(XXXX):(q to quit)\n", p);

	}

	//错误处理；
	if (scanf("%d", &year) != 1 && flag == false)
		fputs("Sorry, we only accept positive number like(2017).-- Bye!\n", p);
	else if (year < 1)
		fputs("Sorry, year or month is illegel, we accept year or month like(2017).--Bye!\n", p);
	else if (scanf("%d", &year) != 1 && flag == true)
		fputs("Thank you for use.--Bye!\n", p);
	fclose(p);
	return 0;
}

void MONTH_DAY(int y, int m, char(*w)[7], char(*t)[7], char(*b)[7])
{

	int normalmonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int leapmonth[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int i, n, *nm, *lm;
	bool dodo = false;

	nm = normalmonth;
	lm = leapmonth;
	n = Isday(y, m, nm, lm);

	//闰年部分
	if (Isleapyear(y))
	{
		for (i = 1; n != 0 && i <= (n - 1) * 10 + 8; i++)
			fputc(' ', p);

		for (i = 1, w += n; i <= leapmonth[m - 1]; i++)
		{
			if (w == b)
				fprintf(p, "%8d", i);
			else
				fprintf(p, "%10d", i);

			if (w == t)
			{
				fprintf(p, "   *\n*");

				if (i == leapmonth[m - 1])
				{
					dodo = true;
					break;
				}
				fprintf(p, "%72s\n*", "*");

				w = b;
				continue;
			}
			w++;
		}
	}
	//普通年部分
	else
	{
		for (i = 1; n != 0 && i <= (n - 1) * 10 + 8; i++)
			fputc(' ', p);

		for (i = 1, w += n; i <= normalmonth[m - 1]; i++)
		{
			if (w == b)
				fprintf(p, "%8d", i);
			else
				fprintf(p, "%10d", i);

			if (w == t)
			{
				fprintf(p, "   *\n*");

				if (i == normalmonth[m - 1])
				{
					dodo = true;
					break;
				}
				fprintf(p, "%72s\n*", "*");

				w = b;
				continue;
			}
			w++;
		}
	}
	//最后一个*
	if (w == t && dodo)
		fprintf(p, "%71s", " ");

	else if (Isleapyear(y))
		for (i = 1; i <= ((6 - ((n + leapmonth[m - 1]) % 7 - 1)) * 10 + 3); i++)
			fputc(' ', p);
	else
		for (i = 1; i <= ((6 - ((n + normalmonth[m - 1]) % 7 - 1)) * 10 + 3); i++)
			fputc(' ', p);

	fputc('*', p);
	fputc('\n', p);

	//结尾
	fprintf(p, "*%72s\n", "*");

	for (i = 1; i <= 73; i = i + 2)
		fprintf(p, "* ");
	fputc('\n', p);
	fputc('\n', p);
	fputc('\n', p);
	fputc('\n', p);

	//开头
	if (m != 12)
	{
		fprintf(p, "%30s%d月\n", " ", m + 1);
		fputc('\n', p);

		for (i = 1; i <= 73; i = i + 2)
			fprintf(p, "* ");


		fprintf(p, "\n*%72s\n*", "*");


		for (i = 0; i < 7; i++)
			fprintf(p, "%10s", week[i]);

		fprintf(p, " *\n*%72s\n*", "*");

	}
}


bool Isleapyear(int a)
{
	if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)
		return true;
	else
		return false;
}


int Isday(int s, int t, int *p, int *q)
{
	int sum = 0, n, count = 0, r;

	for (n = 1; n < s; n++)
		if (Isleapyear(n))
			count++;

	sum = (s - 1) * 365 + count;

	if (Isleapyear(s))
		for (n = 1; n < t; n++)
			sum += *q++;
	else
		for (n = 1; n < t; n++)
			sum += *p++;

	if ((r = sum % 7 + 1) == 7)
		return 0;
	return r;
}

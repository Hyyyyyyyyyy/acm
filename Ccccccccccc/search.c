#include "library.h"
//因为版面和提示信息的原因, 不得不把7个查询功能分开写, 无法合并;
void SLogin();		//根据图书编号查找图书;
void SName();		//根据图书名字查找图书;
void SAuthor();		//根据书的作者查找图书;
void SCategory();		//根据图书分类编号查找图书;
void SPublisher();		//根据图书出版社查找图书;
void SDate();		//根据图书出版日期查找图书;
void SPrice();		//根据图书价格区间(-5~+5)查找图书;

void search()		//在主菜单输入3, 功能: 查询;
{
	int n, i, dodo;
	char ch;
	printf("\nPlease choose the key that you want to search: (0 to quit&&clear)\n");
	printf("1. Login;         2. Name;        3. Author; \n4. Category;      5. Publisher;   6. Date; \n7. Price;         0. end;\n\n");
	
	while (1)
	{
		dodo = scanf("%d", &n);
		if (n == 0)		//输入0退出;
		{
			printf("Thanks for use the function of \"3.查询(search)\"!!\n");
			printf("Bye!\n");
			getchar();
			break;
		}

		if (dodo != 1)		//错误处理, 输入的不是数字
		{
			while (ch = getchar() != '\n')
				;
			printf("Sorry, it is the illegal enter, we only accept the positive numbers(0~7).\n");
			printf("Please enter the choice again(0~7):\n");
			continue;
		}

		if (n < 0 || n > 7)			//错误处理, 输入的数字不正确;
		{
			printf("It  is not the correct choice, Sorry.\n");
			printf("Please enter the choice again:(0~7)\n");
			continue;
		}
		while (ch = getchar() != '\n')		//把多余的输入都清理掉;
			;
		switch (n)			
		{
		case 1:
			SLogin();
			break;
		case 2:
			SName();
			break;
		case 3:
			SAuthor();
			break;
		case 4:
			SCategory();
			break;
		case 5:
			SPublisher();
			break;
		case 6:
			SDate();
			break;
		default:
			SPrice();
			break;
		}
		printf("\n\nPlease make the choice (0~7) again(0 to quit&&clean.):\n");
	}
	return;
}

void SLogin()
{
	Books *cur;
	bool doudou = false;
	int n, i;
	char ch;
	cur = head->next;
	printf("Please enter the Login:\n");
	scanf("%d", &n);
	while (ch = getchar() != '\n')		//错误处理, 清理多余的输入;(下同)
		getchar();

	while (cur != NULL)			//遍历链表,遇到符合条件的打印;(下同)
	{
		if (cur->Login == n)
		{
			printf("\nLogin                Name                Author                Category                Publisher                 Date                Price\n\n");
			printf("%-21d%-20s%-21s %-24d%-26s%-20s%-10f\n\n", cur->Login, cur->Name, cur->Author, cur->Category, cur->Publisher, cur->Date, cur->Price);
			for (i = 1; i <= 150; i++)
				putchar('-');
			doudou = true;
			break;
		}
		cur = cur->next;
	}
	if (!doudou)
		printf("Sorry,no such books.\n");
	return;
}

void SName()
{
	Books *cur;
	bool doudou = false;
	int n, i;
	char ch, ar[100];
	cur = head->next;
	printf("Please enter the Name:\n");

	gets_s(ar, 100);
	while (cur != NULL)
	{
		if (strcmp(ar, cur->Name) == 0)
		{
			printf("\nLogin                Name                Author                Category                Publisher                 Date                Price\n\n");
			printf("%-21d%-20s%-21s %-24d%-26s%-20s%-10f\n\n", cur->Login, cur->Name, cur->Author, cur->Category, cur->Publisher, cur->Date, cur->Price);
			for (i = 1; i <= 150; i++)
				putchar('-');
			putchar('\n');
			putchar('\n');
			doudou = true;
		}
		cur = cur->next;
	}
	if (!doudou)
		printf("Sorry,no such books.\n");
	return;
}

void SAuthor()
{
	Books *cur;
	bool doudou = false;
	int n, i;
	char ar[100];
	cur = head->next;
	printf("Please enter the Author:\n");

	gets_s(ar, 100);
	while (cur != NULL)
	{
		if (strcmp(ar, cur->Author) == 0)
		{
			printf("\nLogin                Name                Author                Category                Publisher                 Date                Price\n\n");
			printf("%-21d%-20s%-21s %-24d%-26s%-20s%-10f\n\n", cur->Login, cur->Name, cur->Author, cur->Category, cur->Publisher, cur->Date, cur->Price);
			for (i = 1; i <= 150; i++)
				putchar('-');
			putchar('\n');
			putchar('\n');
			doudou = true;
		}
		cur = cur->next;
	}
	if (!doudou)
		printf("Sorry,no such books.\n");
	return;
}

void SCategory()
{
	Books *cur;
	bool doudou = false;
	int n, i;
	char ch;
	cur = head->next;
	printf("Please enter the Category:\n");
	scanf("%d", &n);
	while (ch = getchar() != '\n')
		getchar();

	while (cur != NULL)
	{
		if (cur->Category == n)
		{
			printf("\nLogin                Name                Author                Category                Publisher                 Date                Price\n\n");
			printf("%-21d%-20s%-21s %-24d%-26s%-20s%-10f\n\n", cur->Login, cur->Name, cur->Author, cur->Category, cur->Publisher, cur->Date, cur->Price);
			for (i = 1; i <= 150; i++)
				putchar('-');
			putchar('\n');
			putchar('\n');
			doudou = true;
		}
		cur = cur->next;
	}
	if (!doudou)
		printf("Sorry,no such books.\n");
	return;
}

void SPublisher()
{
	Books *cur;
	bool doudou = false;
	int n, i;
	char ch, ar[100];
	cur = head->next;
	printf("Please enter the Publisher:\n");

	gets_s(ar, 100);
	while (cur != NULL)
	{
		if (strcmp(ar, cur->Publisher) == 0)
		{
			printf("\nLogin                Name                Author                Category                Publisher                 Date                Price\n\n");
			printf("%-21d%-20s%-21s %-24d%-26s%-20s%-10f\n\n", cur->Login, cur->Name, cur->Author, cur->Category, cur->Publisher, cur->Date, cur->Price);
			for (i = 1; i <= 150; i++)
				putchar('-');
			putchar('\n');
			putchar('\n');
			doudou = true;
		}
		cur = cur->next;
	}
	if (!doudou)
		printf("Sorry,no such books.\n");
	return;
}


void SDate()
{
	Books *cur;
	bool doudou = false;
	int n, i;
	char ch, ar[100];
	cur = head->next;
	printf("Please enter the Date:\n");

	gets_s(ar, 100);
	while (cur != NULL)
	{
		if (strcmp(ar, cur->Date) == 0)
		{
			printf("\nLogin                Name                Author                Category                Publisher                 Date                Price\n\n");
			printf("%-21d%-20s%-21s %-24d%-26s%-20s%-10f\n\n", cur->Login, cur->Name, cur->Author, cur->Category, cur->Publisher, cur->Date, cur->Price);
			for (i = 1; i <= 150; i++)
				putchar('-');
			putchar('\n');
			putchar('\n');
			doudou = true;
		}
		cur = cur->next;
	}
	if (!doudou)
		printf("Sorry,no such books.\n");
	return;
}

void SPrice()
{
	Books *cur;
	bool doudou = false;
	int i;
	float n;
	char ch;
	cur = head->next;
	printf("Please enter the Price:\n");
	while (scanf("%f", &n) != 1)
	{
		while (ch = getchar() != '\n')
			;
		printf("Sorry, we only accept numbers like (11.11), please enter the price again:\n");
	}
	while (cur != NULL)
	{
		if (fabs(cur->Price - n) < 5.0)
		{
			printf("\nLogin                Name                Author                Category                Publisher                 Date                Price\n\n");
			printf("%-21d%-20s%-21s %-24d%-26s%-20s%-10f\n\n", cur->Login, cur->Name, cur->Author, cur->Category, cur->Publisher, cur->Date, cur->Price);
			for (i = 1; i <= 150; i++)
				putchar('-');
			putchar('\n');
			putchar('\n');
			doudou = true;
		}
		cur = cur->next;
	}
	if (!doudou)
		printf("Sorry,no such books.\n");
	return;
}

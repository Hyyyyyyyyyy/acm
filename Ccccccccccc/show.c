#include "library.h"
void show()		//在主菜单中输入2，可以显示每个一条图书信息；
{
	int i;
	Books *cur;
	cur = head->next;
	putchar('\n');
	while (cur != NULL)			//遍历链表，打印信息；
	{
		printf("Login                Name                Author                Category                Publisher                 Date                Price\n\n");
		printf("%-21d%-20s%-21s %-24d%-26s%-20s%-10f\n\n", cur->Login, cur->Name,cur->Author, cur->Category, cur->Publisher, cur->Date,cur->Price);
		for (i = 1; i <= 130; i++)
			putchar('-');
		putchar('\n');
		putchar('\n');
		cur = cur->next;

	}
	getchar();
	printf("Thanks for use. Bye!!\n");
	return;
}


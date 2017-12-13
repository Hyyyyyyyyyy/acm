#include "Link.h"
int main()
{
	//freopen("IN4.txt", "r", stdin);
	Polyn polyn[maxn];
	Polyn TempPolyn;
	int LenPolyns;
	int i, j, N;
	printf("                                  ***********************************************\n");
	printf("                                  *                  Menu                       *\n");
	printf("                                  *                0.Create                     *\n");
	printf("                                  *                1.Show                       *\n");
	printf("                                  *                2.Add                        *\n");
	printf("                                  *                3.Substract                  *\n");
	printf("                                  *                4.Multify                    *\n");
	printf("                                  *                5.Opposite                   *\n");
	printf("                                  *                6.Exit                       *\n");
	printf("                                  ***********************************************\n");
	LenPolyns = 0;
	while (scanf("%d", &N) != EOF && N != 6)
	{
		switch (N)
		{
			case 0:
			{
				if (LenPolyns >= maxn - 5)				//创建个数超出容量范围
				{
					printf("Sorry. Create fail\n");
					break;
				}
				if (polyn[LenPolyns + 1].root = CreatPolyn(polyn[LenPolyns + 1].root))			//创建成功
				{
					LenPolyns++;
					printf("Create successfullly!\n");
				}
				else
					printf("Sorry. Create fail\n");																			//创建失败
				break;
			}
			case 1:
			{
				printf("Which polyn do you want?\n");
				scanf("%d", &i);
				if (i >= maxn - 5)																								//数值超出容量范围
				{
					printf("Sorry. Runtime error\n");
					break;
				}
				if (polyn[i].root)
					PrintPolyn(polyn[i].root);
				else
					printf("Sorry, no such polyn\n");																	//访问了未创建的多项式
				break;
			}
			case 2:
			{
				printf("What are the polyns do you want to add?\n");
				scanf("%d %d", &i, &j);
				if (i >= maxn - 5 || j >= maxn-5)																	//数值超出容量范围
				{
					printf("Sorry. Runtime error\n");
					break;
				}
				if (TempPolyn.root = AddPolyn(polyn[i].root, polyn[j].root))
					PrintPolyn(TempPolyn.root);
				else
					printf("Sorry. Can not add\n");																	//访问了未创建的多项式
				break;
			}
			case 3:
			{
				printf("What are the polyns do you want to subtract?\n");
				scanf("%d %d", &i, &j);
				if (i >= maxn - 5 || j >= maxn - 5)																		//数值超出容量范围
				{
					printf("Sorry. Runtime error\n");
					break;
				}
				if (TempPolyn.root = SubtractPolyn(polyn[i].root, polyn[j].root))
					PrintPolyn(TempPolyn.root);
				else
					printf("Sorry. Can not substract\n");																//访问了未创建的多项式
				break;
			}
			case 4:
			{
				printf("What are the polyns do you want to multify?\n");
				scanf("%d %d", &i, &j);
				if (i >= maxn - 5 || j >= maxn - 5)																		//数值超出容量范围
				{
					printf("Sorry. Runtime error\n");
					break;
				}
				if (TempPolyn.root = MultiplyPolyn(polyn[i].root, polyn[j].root))
					PrintPolyn(TempPolyn.root);
				else
					printf("Sorry. Can not multify\n");																	//访问了未创建的多项式
				break;
			}
			case 5:
			{
				printf("Which polyn do you want to opposite?\n");
				scanf("%d", &i);
				if (i >= maxn - 5)
				{
					printf("Sorry. Runtime error\n");
					break;
				}
				if (Opposite(polyn[i].root))
					PrintPolyn(polyn[i].root);
				else
					printf("Sorry. Can not opposite\n");
				break;
			}
			default:
				printf("Please input number 0~6\n");
		}
	}
	bool FlagDelete = true;
	for(i = 1; i <= LenPolyns; i++)																				//销毁多项式
	{
		if (!DeletePolyns(polyn[i].root))
			printf("Sorry. Can not delete %d polyn\n", i), FlagDelete = false;
	}
	if (FlagDelete)
		printf("Delete All\n");
	return 0;
}
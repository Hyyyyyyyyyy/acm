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
				if (LenPolyns >= maxn - 5)
				{
					printf("Sorry. Create fail\n");
					break;
				}
				if (polyn[LenPolyns + 1].root = CreatPolyn(polyn[LenPolyns + 1].root))
				{
					LenPolyns++;
					printf("Create successfullly!\n");
				}
				else
					printf("Sorry. Create fail\n");
				break;
			}
			case 1:
			{
				printf("Which polyn do you want?\n");
				scanf("%d", &i);
				if (i >= maxn - 5)
				{
					printf("Sorry. Runtime error\n");
					break;
				}
				if (polyn[i].root)
					PrintPolyn(polyn[i].root);
				else
					printf("Sorry, no such polyn\n");
				break;
			}
			case 2:
			{
				printf("What are the polyns do you want to add?\n");
				scanf("%d %d", &i, &j);
				if (i >= maxn - 5 || j >= maxn-5)
				{
					printf("Sorry. Runtime error\n");
					break;
				}
				if (TempPolyn.root = AddPolyn(polyn[i].root, polyn[j].root))
					PrintPolyn(TempPolyn.root);
				else
					printf("Sorry. Can not add\n");
				break;
			}
			case 3:
			{
				printf("What are the polyns do you want to subtract?\n");
				scanf("%d %d", &i, &j);
				if (i >= maxn - 5 || j >= maxn - 5)
				{
					printf("Sorry. Runtime error\n");
					break;
				}
				if (TempPolyn.root = SubtractPolyn(polyn[i].root, polyn[j].root))
					PrintPolyn(TempPolyn.root);
				else
					printf("Sorry. Can not substract\n");
				break;
			}
			case 4:
			{
				printf("What are the polyns do you want to multify?\n");
				scanf("%d %d", &i, &j);
				if (i >= maxn - 5 || j >= maxn - 5)
				{
					printf("Sorry. Runtime error\n");
					break;
				}
				if (TempPolyn.root = MultiplyPolyn(polyn[i].root, polyn[j].root))
					PrintPolyn(TempPolyn.root);
				else
					printf("Sorry. Can not multify\n");
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
				break;
		}
	}
	return 0;
}
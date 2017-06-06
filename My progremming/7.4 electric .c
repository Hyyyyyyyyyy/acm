#include <stdio.h>
#define RATE1 0.13230	//�״�ʹ�� 360 kwh �ķ��� 
#define RATE2 0.15040	//��ʹ�� 108 kwh �ķ��� 
#define RATE3 0.30025	//��ʹ��252 kwh �ķ��� 
#define RATE4 0.34025	//ʹ�ó���720 kwh �ķ��� 
#define BREAK1 360.0	//���ʵĵ�һ���ֽ�� 
#define BREAK2 468.0	//���ʵĵڶ����ֽ�� 
#define BREAK3 720.0	//���ʵĵ������ֽ�� 
#define BASE1 (RATE1 * BREAK1)		//ʹ�� 360kwh �ķ��� 
#define BASE2 (BASE1 + (RATE2 * (BREAK2 - BREAK1)))		//ʹ�� 468keh �ķ��� 
#define BASE3 (BASE1 + BASE2 + (RATE3 * (BREAK3 - BREAK2)))		//ʹ�� 720kwh �ķ��� 

int main()
{
    double kwh;		//ʹ�õ�ǧ��ʱ 
    double bill;	//��� 

    printf("Please enter the kwh used.\n");
    scanf("%lf", &kwh);
    if (kwh <= BREAK1)
        bill = BASE1 * kwh;
    else if (kwh <= BREAK2)
        bill = BASE1 + (RATE2 * (kwh - BREAK1));
    else if (kwh <= BREAK3)
        bill = BASE2 + (RATE3 * (kwh - BREAK2));
    else
        bill = BASE3 + (RATE4 * (kwh - BREAK3));
    printf("The charge for %.lf kwh is $%1.2f.\n", kwh, bill);

    return 0;
}

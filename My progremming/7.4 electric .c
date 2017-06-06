#include <stdio.h>
#define RATE1 0.13230	//首次使用 360 kwh 的费率 
#define RATE2 0.15040	//再使用 108 kwh 的费率 
#define RATE3 0.30025	//再使用252 kwh 的费率 
#define RATE4 0.34025	//使用超过720 kwh 的费率 
#define BREAK1 360.0	//费率的第一个分界点 
#define BREAK2 468.0	//费率的第二个分界点 
#define BREAK3 720.0	//费率的第三个分界点 
#define BASE1 (RATE1 * BREAK1)		//使用 360kwh 的费用 
#define BASE2 (BASE1 + (RATE2 * (BREAK2 - BREAK1)))		//使用 468keh 的费用 
#define BASE3 (BASE1 + BASE2 + (RATE3 * (BREAK3 - BREAK2)))		//使用 720kwh 的费用 

int main()
{
    double kwh;		//使用的千瓦时 
    double bill;	//电费 

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

#include <stdio.h> 
int main()
{
	const int FREEZING = 0;
	int cold_days = 0;
	int all_days = 0;
	int n, count;
	
	printf("Hello, how many days would you like to enter:\n");
	scanf("%d", &n);
	
	float data[n], temperature[n];
	
	//输入部分 
	printf("Enter the data according to the order from small to large:\n");
	for (count = 0; count < n; count++)
		scanf("%f", &data[count]);
	printf("Enter the list of daily low temperatures.\n");
	for (count = 0; count < n; count++)
	{
		scanf("%f", &temperature[count]);
		all_days++;
		if (temperature[count] < FREEZING)
			cold_days++;
	}
	printf("\n");
	
	//输出部分 
	printf("Your input are as belows:\n");
	printf("data        ");
	for (count = 0; count < n; count++)
		printf("%10.2f", data[count]);
	printf("\n");
	printf("temperature ");
	for (count = 0; count < n; count++)
		printf("%10.2f", temperature[count]);
	printf("\n");
	
	
	if (all_days != 0)
		printf("%d days total: %.1f%% were below freezing.\n", all_days, 100.0 * (float) cold_days / all_days);
	if (all_days == 0)
		printf("No data entered!\n");
		
		return 0;
}

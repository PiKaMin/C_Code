#include <stdio.h>

void JudgePrimeNum(int num)
{
	if (num < 1)
	{
		return;
	}
	if (num == 1)
	{
		printf("%d��������\n", num);
		return;
	}
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			printf("%d��������\n" , num);
			return;
		}
	}
	printf("%d������\n" , num);
}
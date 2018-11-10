#include <stdio.h>
//3.实现一个函数判断year是不是润年。
void JudgeLeapYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0)
	{
		printf("%d是闰年\n" , year);
		return;
	}
	if (year % 400 == 0)
	{
		printf("%d是闰年\n", year);
		return;
	}
	printf("%d不是闰年\n", year);
}
#include <stdio.h>
//3.ʵ��һ�������ж�year�ǲ������ꡣ
void JudgeLeapYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0)
	{
		printf("%d������\n" , year);
		return;
	}
	if (year % 400 == 0)
	{
		printf("%d������\n", year);
		return;
	}
	printf("%d��������\n", year);
}
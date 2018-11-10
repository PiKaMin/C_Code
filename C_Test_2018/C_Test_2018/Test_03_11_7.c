#include <stdio.h>


//3. 写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19

int  DigitSum(int n)
{

	if (n < 0)
	{
		printf("输入不合法");
		return -1;
	}
	if (n > 9)
	{
		return DigitSum(n / 10) + n % 10;
	}
	return n % 10;
}

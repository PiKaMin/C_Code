#include <stdio.h>

//1.递归和非递归分别实现求第n个斐波那契数。

//递归实现
int FibRecursion(int n)
{
	if (n < 1)
	{
		printf("输入不合法");
		return -1;
		
	}
	if (n == 1 || n == 2)
	{
		return 1;
	}
	return FibRecursion(n - 1) + FibRecursion(n - 2);
}

//非递归实现
int FibNotRecursion(int n)
{
	if (n < 1)
	{
		printf("输入不合法");
		return -1;
		
	}
	int preNum = 1;
	int prePreNum = 1;
	int result = 1;
	for (int i = 2; i < n ; i++)
	{
		result = preNum + prePreNum;
		prePreNum = preNum;
		preNum = result;
		
	}
	return result;
}
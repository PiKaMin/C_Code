#include <stdio.h>
//6.递归和非递归分别实现求n的阶乘 

//非递归
int Factorial(int n)
{
	int result = 1;
	if (n < 0)
	{
		printf("输入不合法");
		return -1;
	}
	if (n == 0) return result;
	for (int i = 1; i <= n; i++)
	{
		result *= i;
	}
	return result;
}

//递归
int FactorialRecursion(int n)
{
	if (n < 0)
	{
		printf("输入不合法");
		return -1;
	}
	if (n == 1 || n == 0)
	{
		return 1;
	}
	return FactorialRecursion(n - 1) * n;
}
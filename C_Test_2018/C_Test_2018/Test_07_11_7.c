#include <stdio.h>
//7.递归方式实现打印一个整数的每一位 
void PrintNumber(int n)
{
	if (n > 9)
	{
		PrintNumber(n / 10);
	}
	printf("%d\n", n % 10);
}
#include <stdio.h>
//6.�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳� 

//�ǵݹ�
int Factorial(int n)
{
	int result = 1;
	if (n < 0)
	{
		printf("���벻�Ϸ�");
		return -1;
	}
	if (n == 0) return result;
	for (int i = 1; i <= n; i++)
	{
		result *= i;
	}
	return result;
}

//�ݹ�
int FactorialRecursion(int n)
{
	if (n < 0)
	{
		printf("���벻�Ϸ�");
		return -1;
	}
	if (n == 1 || n == 0)
	{
		return 1;
	}
	return FactorialRecursion(n - 1) * n;
}
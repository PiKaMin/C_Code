#include <stdio.h>
//7.�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ 
void PrintNumber(int n)
{
	if (n > 9)
	{
		PrintNumber(n / 10);
	}
	printf("%d\n", n % 10);
}
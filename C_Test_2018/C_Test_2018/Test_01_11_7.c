#include <stdio.h>

//1.�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲���������

//�ݹ�ʵ��
int FibRecursion(int n)
{
	if (n < 1)
	{
		printf("���벻�Ϸ�");
		return -1;
		
	}
	if (n == 1 || n == 2)
	{
		return 1;
	}
	return FibRecursion(n - 1) + FibRecursion(n - 2);
}

//�ǵݹ�ʵ��
int FibNotRecursion(int n)
{
	if (n < 1)
	{
		printf("���벻�Ϸ�");
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
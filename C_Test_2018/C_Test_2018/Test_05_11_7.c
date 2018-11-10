#include <stdio.h>

//5.递归和非递归分别实现strlen

//递归
int MyStrlenRecursion(char* str)
{
	if (str[0] == '\0')
	{
		return 0;
	}
	return MyStrlenRecursion(str + 1) + 1;
}

//非递归
int MyStrlenNotRecursion(char* str)
{
	int len = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		len++;
	}
	return len;
}
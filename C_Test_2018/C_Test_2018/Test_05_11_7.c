#include <stdio.h>

//5.�ݹ�ͷǵݹ�ֱ�ʵ��strlen

//�ݹ�
int MyStrlenRecursion(char* str)
{
	if (str[0] == '\0')
	{
		return 0;
	}
	return MyStrlenRecursion(str + 1) + 1;
}

//�ǵݹ�
int MyStrlenNotRecursion(char* str)
{
	int len = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		len++;
	}
	return len;
}
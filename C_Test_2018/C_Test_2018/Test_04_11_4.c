#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


#define TRUE  1
#define FALSE 0
//4.
//创建一个数组，
//实现函数init（）初始化数组、
//实现empty（）清空数组、
//实现reverse（）函数完成数组元素的逆置。
//要求：自己设计函数的参数，返回值。

//初始化数组    length：数组长度
int* Init(int length)
{
	int* pArr = NULL;
	pArr = (int* )malloc(sizeof(int) * length);
	printf("数组长度为%d\n"  , length);
	for (int i = 0; i < length; i++)
	{
		printf("输入第%d个数 : " ,(i + 1));
		scanf("%d", pArr + i);
	}
	printf("输入完成\n");
	return pArr;
}

void empty(int* arr , int length)
{
	
	for (int i = 0; i < length; i++)
	{
		*(arr + i) = 0;
	}
}

void reverse(int* arr , int length)
{
	int temp = 0;
	for (int i = 0 , j = length - 1; i < j; i++ ,j--)
	{
		temp = *(arr + i);
		*(arr + i) = *(arr + j);
		*(arr + j) = temp;
	}
}
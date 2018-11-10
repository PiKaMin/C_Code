#include <stdio.h>


//1.实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定， 
//输入9，输出9 * 9口诀表，输入12，输出12 * 12的乘法口诀表。

void PrintMuliteList(int line)
{
	for (int i = 1; i <= line; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf(" %d * %d = %d ", j, i, (i *j));
		}
		printf("\n");
	}
}
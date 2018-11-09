#include <stdio.h>
#include <stdlib.h>

//2.2 编写一个程序，从标准输入读取C源代码，并验证所有的花括号正确配对，
//注意：不必考虑注释内部，字符串常量，和字符常量形式的花括号
void  BracesMatch()
{
	int c;
	int braces = 0;
	int errorRight = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == '{')
		{
			braces++;
		}


		if (c == '}')
		{
			if (braces == 0)
			{
				//有右大括号不匹配
				errorRight++;
			}
			else
			{
				braces--;
			}
		}
	}

	if (braces > 0)
	{
		printf("有大括号不匹配\n");
		printf("不匹配的左大括号数量%d\n" , braces);
	}
	if (errorRight > 0)
	{
		printf("有大括号不匹配\n");
		printf("不匹配的右大括号数量%d\n" , errorRight);
	}
}

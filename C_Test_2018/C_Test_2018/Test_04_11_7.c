#include <stdio.h>

//4. 编写一个函数 reverse_string(char * string)（递归实现）
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中的字符串操作函数。

extern int MyStrlenRecursion(char* str);
void reverse_string(char * string)
{
	int len = MyStrlenRecursion(string);
	if (len <= 1)
		return;
	else
	{
		char temp = string[0];
		string[0] = string[len - 1];
		string[len - 1] = '\0';
		reverse_string(string + 1);
		string[len - 1] = temp	;

	}
}
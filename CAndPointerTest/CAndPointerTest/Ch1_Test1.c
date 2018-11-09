#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COLS 20
#define MAX_INPUT 1000


//1.1 《C和指针》第一章 示例程序
//从标准输入读取文本并对其进行修改，然后把它写到标准输出。
//程序首先读取一串列标号。这些列标号成对出现，表示输入的列范围。
//这串列标号以一个负值结尾，作为结束标志。剩余的输入行被程序读入并打印，
//然后输入行中被选中范围的字符串被提取出来并打印。

int read_column_numbers(int columns[], int max);
void rearrange(char* output, char const* input
	, int n_columns, int const columns[]);
extern void Test_1_5(char* output, char const* input
	, int n_columns, int  columns[]);
extern void Test_1_6(char* output, char const* input
	, int n_columns, int const columns[]);

void Ch_1_Test1()
{
	int n_columns = 0;
	int columns[MAX_COLS];
	char input[MAX_INPUT];
	char output[MAX_INPUT];

	n_columns = read_column_numbers(columns, MAX_COLS);

	//可能会产生的问题：
	//gets函数不进行长度检查，如果输入的长度过长超过1024，会导致input溢出，程序崩溃
	//解决的方法：换用fgets()函数，fgets()函数的参数要求传递数组长度
	//while (gets(input) != NULL)
	while (fgets(input, MAX_INPUT, stdin) != NULL)
	{

		printf("原始字符串 : %s", input);
		Test_1_6(output, input, n_columns, columns);       //编程练习1.6
														   //Test_1_5(output , input , n_columns , columns);  //编程练习1.5
														   //rearrange(output, input, n_columns, columns);    //原本的示例程序
		printf("截取后的字符串 : %s\n", output);
	}
}
void rearrange(char* output, char const* input
	, int n_columns, int const columns[])
{
	int col = 0;
	int output_col = 0;
	int len = strlen(input);
	//处理每对标号
	for (; col < n_columns; col += 2)
	{
		int nchars = columns[col + 1] - columns[col] + 1;//处理的字符个数

														 //如果输出行已满，或列标超过最大下标则返回
		if (columns[col] >= len || output_col == MAX_INPUT - 1)
			break;
		//如果超过输出行的最大容量，只处理可以容纳的数据
		if (output_col + nchars > MAX_INPUT - 1)
			nchars = MAX_INPUT - output_col - 1;
		strncpy(output + output_col, input + columns[col], nchars);
		output_col += nchars;

	}
	output[output_col] = '\0';
}
//读取输入的列标号
int read_column_numbers(int columns[], int max)
{
	int num = 0;
	int ch = 0;
	//三个条件分别为：
	//1.输入的列数没有达到最大值
	//2.scanf函数正确返回
	//3.输入的数字大于0(负值作为结尾)
	while (num < max && scanf("%d", &columns[num]) == 1 && columns[num] >= 0)
	{
		num++;
	}
	//确认数组中保存的标号为偶数个(编程练习1.6要取消这个偶数检查)
	/*if (num % 2 != 0)
	{
	puts(" 标号没有成对出现");
	exit(EXIT_FAILURE);
	}*/
	//清空输入流中的回车，为下次读取数据(读取字符串)做准备
	while ((ch = getchar()) != EOF && ch != '\n')
		;

	return num;

}
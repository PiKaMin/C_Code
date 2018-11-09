#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define MAX_INPUT 1024

//《C和指针》 第一章编程练习

//练习1.1 输出 Hello world！并换行
void Test_1_1()
{
	printf("Hello world!\n");
}

//练习1.2 从标准输入中读取几行输入，前面加上行号后逐行打印至标准输出。
//在编写这个程序时试图让程序能够处理的输入行没有上限。
void Test_1_2()
{
	//如果使用gets()或fgets()按行处理输入是有上限的，那么就可以考虑按字符读取

	int ch;
	int line = 1;   //保存读入的行数
	int isNextLine = TRUE;//是否是一个新的行(刚换行，要先输出行号)
	while ((ch = getchar()) != EOF)
	{
		if (isNextLine == TRUE)
		{
			printf("%d ", line);
			isNextLine = FALSE;
		}
		putchar(ch);
		if (ch == '\n')
		{
			line++;
			isNextLine = TRUE;
		}
	}
}

//练习1.3 从标准输入读取一些字符，并把它写到标准输出，并计算checksum的和，以十进制打印，
//checksum ：singed char ， 初始值为-1
void Test_1_3()
{
	int ch;
	signed char checksum = -1;
	printf("输入一些字符，如果要结束输入，在新的空行输入ctrl+Z");
	while ((ch = getchar()) != EOF)
	{
		//printf("%d + %d = %d \n", checksum, ch , (checksum + ch) );
		checksum += ch;
		putchar(ch);
	}
	printf("%d\n", checksum);
}

//练习1.4 编写一个程序，一行行地读取输入行，直至达到文件尾。
//算出每行输入行的长度，然后把最长的那行打印出来。
//为了简单起见，假定所有的输入行均不超过1000个字符。
void Test_1_4()
{
	char input[MAX_INPUT] = { 0 };
	char maxInput[MAX_INPUT] = { 0 };

	int inputMaxNum = 0;
	int inputNum = 0;
	printf("输入多行文本，将计算并打印最长的那一行，回车作为一行结束，输入完成后在新的一行输入 ctrl+z 完成输入\n");
	printf("如果有多行长度同为最长，将打印最先输入的那一行\n");
	while (gets(input) != NULL) // gets()函数以 \n 作为一行结束，并忽略这个 \n ，不会将 \n 读入字符数组
	{
		inputNum = strlen(input);
		if (inputNum > inputMaxNum)
		{
			inputMaxNum = inputNum;
			strcpy(maxInput, input);
		}
	}
	printf("最长的一行输出入是 : %s\n长度是 : %d\n", maxInput, inputMaxNum);
}

//练习1.4 修改示例程序中 rearrange 函数
//使它可以处理列标号范围非递增顺序的情况
//如输入：5 2 8 1 -1 可以正确处理
void Test_1_5(char* output, char const* input
	, int n_columns, int  columns[])
{
	int col = 0;
	int output_col = 0;
	int len = strlen(input);
	//处理每对标号
	for (; col < n_columns; col += 2)
	{
		//列标号成对处理，如果列标号顺序递减只需要交换两个标号位置就可以了
		if (columns[col + 1] < columns[col])
		{
			int temp = columns[col + 1];
			columns[col + 1] = columns[col];
			columns[col] = temp;
		}

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

//练习1.6 修改rearrange
//去除输入的列标号成对的限制，如果读入的列标号是奇数，就会将剩下最后一个列标号和行尾所有字符复制输出。
void Test_1_6(char* output, char const* input
	, int n_columns, int const columns[])
{
	//使用这段代码要注释 Ch1_Test1.c 文件中 read_column_numbers() 函数中的判断偶数代码
	int col = 0;
	int output_col = 0;
	int len = strlen(input);
	//处理每对标号
	for (; col < n_columns; col += 2)
	{
		//如果剩下最后一个列标，直接计算这个列标到行尾的字符个数
		int nchars = col == (n_columns - 1) ? len - columns[col] : columns[col + 1] - columns[col] + 1;//处理的字符个数

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
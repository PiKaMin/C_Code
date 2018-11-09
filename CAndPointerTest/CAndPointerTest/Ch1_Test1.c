#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COLS 20
#define MAX_INPUT 1000


//1.1 ��C��ָ�롷��һ�� ʾ������
//�ӱ�׼�����ȡ�ı�����������޸ģ�Ȼ�����д����׼�����
//�������ȶ�ȡһ���б�š���Щ�б�ųɶԳ��֣���ʾ������з�Χ��
//�⴮�б����һ����ֵ��β����Ϊ������־��ʣ��������б�������벢��ӡ��
//Ȼ���������б�ѡ�з�Χ���ַ�������ȡ��������ӡ��

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

	//���ܻ���������⣺
	//gets���������г��ȼ�飬�������ĳ��ȹ�������1024���ᵼ��input������������
	//����ķ���������fgets()������fgets()�����Ĳ���Ҫ�󴫵����鳤��
	//while (gets(input) != NULL)
	while (fgets(input, MAX_INPUT, stdin) != NULL)
	{

		printf("ԭʼ�ַ��� : %s", input);
		Test_1_6(output, input, n_columns, columns);       //�����ϰ1.6
														   //Test_1_5(output , input , n_columns , columns);  //�����ϰ1.5
														   //rearrange(output, input, n_columns, columns);    //ԭ����ʾ������
		printf("��ȡ����ַ��� : %s\n", output);
	}
}
void rearrange(char* output, char const* input
	, int n_columns, int const columns[])
{
	int col = 0;
	int output_col = 0;
	int len = strlen(input);
	//����ÿ�Ա��
	for (; col < n_columns; col += 2)
	{
		int nchars = columns[col + 1] - columns[col] + 1;//������ַ�����

														 //�����������������б곬������±��򷵻�
		if (columns[col] >= len || output_col == MAX_INPUT - 1)
			break;
		//�����������е����������ֻ����������ɵ�����
		if (output_col + nchars > MAX_INPUT - 1)
			nchars = MAX_INPUT - output_col - 1;
		strncpy(output + output_col, input + columns[col], nchars);
		output_col += nchars;

	}
	output[output_col] = '\0';
}
//��ȡ������б��
int read_column_numbers(int columns[], int max)
{
	int num = 0;
	int ch = 0;
	//���������ֱ�Ϊ��
	//1.���������û�дﵽ���ֵ
	//2.scanf������ȷ����
	//3.��������ִ���0(��ֵ��Ϊ��β)
	while (num < max && scanf("%d", &columns[num]) == 1 && columns[num] >= 0)
	{
		num++;
	}
	//ȷ�������б���ı��Ϊż����(�����ϰ1.6Ҫȡ�����ż�����)
	/*if (num % 2 != 0)
	{
	puts(" ���û�гɶԳ���");
	exit(EXIT_FAILURE);
	}*/
	//����������еĻس���Ϊ�´ζ�ȡ����(��ȡ�ַ���)��׼��
	while ((ch = getchar()) != EOF && ch != '\n')
		;

	return num;

}
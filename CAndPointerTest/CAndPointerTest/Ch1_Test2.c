#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define MAX_INPUT 1024

//��C��ָ�롷 ��һ�±����ϰ

//��ϰ1.1 ��� Hello world��������
void Test_1_1()
{
	printf("Hello world!\n");
}

//��ϰ1.2 �ӱ�׼�����ж�ȡ�������룬ǰ������кź����д�ӡ����׼�����
//�ڱ�д�������ʱ��ͼ�ó����ܹ������������û�����ޡ�
void Test_1_2()
{
	//���ʹ��gets()��fgets()���д��������������޵ģ���ô�Ϳ��Կ��ǰ��ַ���ȡ

	int ch;
	int line = 1;   //������������
	int isNextLine = TRUE;//�Ƿ���һ���µ���(�ջ��У�Ҫ������к�)
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

//��ϰ1.3 �ӱ�׼�����ȡһЩ�ַ���������д����׼�����������checksum�ĺͣ���ʮ���ƴ�ӡ��
//checksum ��singed char �� ��ʼֵΪ-1
void Test_1_3()
{
	int ch;
	signed char checksum = -1;
	printf("����һЩ�ַ������Ҫ�������룬���µĿ�������ctrl+Z");
	while ((ch = getchar()) != EOF)
	{
		//printf("%d + %d = %d \n", checksum, ch , (checksum + ch) );
		checksum += ch;
		putchar(ch);
	}
	printf("%d\n", checksum);
}

//��ϰ1.4 ��дһ������һ���еض�ȡ�����У�ֱ���ﵽ�ļ�β��
//���ÿ�������еĳ��ȣ�Ȼ���������д�ӡ������
//Ϊ�˼�������ٶ����е������о�������1000���ַ���
void Test_1_4()
{
	char input[MAX_INPUT] = { 0 };
	char maxInput[MAX_INPUT] = { 0 };

	int inputMaxNum = 0;
	int inputNum = 0;
	printf("��������ı��������㲢��ӡ�����һ�У��س���Ϊһ�н�����������ɺ����µ�һ������ ctrl+z �������\n");
	printf("����ж��г���ͬΪ�������ӡ�����������һ��\n");
	while (gets(input) != NULL) // gets()������ \n ��Ϊһ�н�������������� \n �����Ὣ \n �����ַ�����
	{
		inputNum = strlen(input);
		if (inputNum > inputMaxNum)
		{
			inputMaxNum = inputNum;
			strcpy(maxInput, input);
		}
	}
	printf("���һ��������� : %s\n������ : %d\n", maxInput, inputMaxNum);
}

//��ϰ1.4 �޸�ʾ�������� rearrange ����
//ʹ�����Դ����б�ŷ�Χ�ǵ���˳������
//�����룺5 2 8 1 -1 ������ȷ����
void Test_1_5(char* output, char const* input
	, int n_columns, int  columns[])
{
	int col = 0;
	int output_col = 0;
	int len = strlen(input);
	//����ÿ�Ա��
	for (; col < n_columns; col += 2)
	{
		//�б�ųɶԴ�������б��˳��ݼ�ֻ��Ҫ�����������λ�þͿ�����
		if (columns[col + 1] < columns[col])
		{
			int temp = columns[col + 1];
			columns[col + 1] = columns[col];
			columns[col] = temp;
		}

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

//��ϰ1.6 �޸�rearrange
//ȥ��������б�ųɶԵ����ƣ����������б�����������ͻὫʣ�����һ���б�ź���β�����ַ����������
void Test_1_6(char* output, char const* input
	, int n_columns, int const columns[])
{
	//ʹ����δ���Ҫע�� Ch1_Test1.c �ļ��� read_column_numbers() �����е��ж�ż������
	int col = 0;
	int output_col = 0;
	int len = strlen(input);
	//����ÿ�Ա��
	for (; col < n_columns; col += 2)
	{
		//���ʣ�����һ���бֱ꣬�Ӽ�������б굽��β���ַ�����
		int nchars = col == (n_columns - 1) ? len - columns[col] : columns[col + 1] - columns[col] + 1;//������ַ�����

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
#pragma once
#include <stdio.h>

//
//1.
//дһ���������ز����������� 1 �ĸ���
//���磺 15 0000 1111 4 �� 1
//����ԭ�ͣ�
//int count_one_bits(unsigned int value)
//{
//	// ���� 1��λ�� 
//}

int count_one_bits(int value)
{
	int one_num = 0;
	for (int i = 0; i < 32; i++)    //32λ�� 
	{
		if ((value >> i) & 0x1)     //�ж�ÿһλ�Ƿ�Ϊ 1
		{
			one_num++;
		}
		
	}

	return one_num;
}

//2.��ȡһ�������������������е�ż��λ������λ��
//�ֱ�������������С�

void GetBinaryEvenAndOddSeq(int num)
{
	printf("ż��λ:");
	for (int i = 0; i < 32; i += 2)
	{
		printf("%d " , (num >> i) & 0x1);
	}
	printf("\n");

	printf("����λ:");
	for (int i = 1; i < 32; i += 2)
	{
		printf("%d ", (num >> i) & 0x1);
	}
}

//3. ���һ��������ÿһλ��
// �������� 0 �����    num != 0
void PrintNum(int num)
{
	if (num == 0)
		return;

	int tmp = num % 10;
	PrintNum(num / 10);
	if (tmp < 0) tmp = -tmp;
	printf("%d " , tmp);
}


//4.���ʵ�֣�
//����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ��
//�������� :
//1999 2299
//������� : 7

void FindBitDifferent(int num1 , int num2)
{
	int differentCount = 0;
	//����32λ,����ѭ��32��
	for (int i = 0; i < 32; i++)
	{
		int temp1 = (num1 >> i) & 1; // num1��ǰ�����һλ
		int temp2 = (num2 >> i) & 1;

		if (temp1 != temp2)
			++differentCount;

	}

	printf("�� %d ��bitλ��һ��", differentCount);
}
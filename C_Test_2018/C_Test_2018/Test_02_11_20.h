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

}
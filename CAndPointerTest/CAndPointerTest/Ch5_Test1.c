#include <stdio.h>

//������ ʾ������ ����һ������������1�ĸ���:�����汾
int CountOneBits(unsigned int value)
{
	int ones = 0;

	for (ones = 0; value != 0; value >>= 1)   //ÿ������һλ
	{
		if (value % 2 != 0)
			ones += 1;         //�����������˵�������������һλΪ 1 
	}

	return ones;
}
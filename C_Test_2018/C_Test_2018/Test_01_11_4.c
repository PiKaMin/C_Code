#include <stdio.h>


//1.ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ���� 
//����9�����9 * 9�ھ�������12�����12 * 12�ĳ˷��ھ���

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
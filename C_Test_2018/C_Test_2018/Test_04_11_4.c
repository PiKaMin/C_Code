#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


#define TRUE  1
#define FALSE 0
//4.
//����һ�����飬
//ʵ�ֺ���init������ʼ�����顢
//ʵ��empty����������顢
//ʵ��reverse���������������Ԫ�ص����á�
//Ҫ���Լ���ƺ����Ĳ���������ֵ��

//��ʼ������    length�����鳤��
int* Init(int length)
{
	int* pArr = NULL;
	pArr = (int* )malloc(sizeof(int) * length);
	printf("���鳤��Ϊ%d\n"  , length);
	for (int i = 0; i < length; i++)
	{
		printf("�����%d���� : " ,(i + 1));
		scanf("%d", pArr + i);
	}
	printf("�������\n");
	return pArr;
}

void empty(int* arr , int length)
{
	
	for (int i = 0; i < length; i++)
	{
		*(arr + i) = 0;
	}
}

void reverse(int* arr , int length)
{
	int temp = 0;
	for (int i = 0 , j = length - 1; i < j; i++ ,j--)
	{
		temp = *(arr + i);
		*(arr + i) = *(arr + j);
		*(arr + j) = temp;
	}
}
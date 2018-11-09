#pragma once
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
//��̬˳���

typedef int DataType;
#define MAX_SIZE (100)
typedef struct SeqList
{
	DataType array[MAX_SIZE];
	int size ;		// 1.����˳������Ѿ����˵����ݵĸ���
						// 2.��ǰ�����±�
}  SeqList ;

//�ӿ�(����)
//��ʼ��/����
//����ɾ���顢��


//��ʼ��
void SeqListInit(SeqList* pSeq)
{
	// 1.��ʼ�� size
	// 2.������Ҫ�������ռ����

	assert(pSeq != NULL);
	pSeq->size = 0;
}


//����
void SeqListDestory(SeqList *pSeq)
{
	assert(pSeq);
	pSeq->size = 0;
}


//����
//1.β��(���������� C++ STLͳһ)
void SeqListPushBack(SeqList* pSeq, DataType data)
{
	assert(pSeq);

	//����
	if (pSeq->size >= MAX_SIZE)
	{
		assert(0);
		return;
	}
	pSeq->array[pSeq->size] = data;
	pSeq->size++;
}

//2.ͷ��
void SeqListPushFront(SeqList* pSeq, DataType data)
{
	assert(pSeq);
	if (pSeq->size >= MAX_SIZE)
	{
		assert(0);
		return;
	}

	// 1. i ����λ��
	/*for (int i = pSeq->size; i > 0; i--)
	{
		pSeq->array[i] = pSeq->array[i - 1];
	}*/

	// 2. i ����Ԫ��
	for (int i = pSeq->size - 1; i >= 0; i--)
	{
		pSeq->array[i + 1] = pSeq->array[i];
	}

	pSeq->array[0] = data;
	pSeq->size++;
}

//3. �м����
//index : ������±�
void SeqListInsert(SeqList* pSeq, int index, DataType data)
{
	assert(pSeq);
	assert(index >= 0 && index <= pSeq->size);//�������±겻����
	if (pSeq->size >= MAX_SIZE)
	{
		assert(0);
		return;
	}

	// 1.���ݰ���
	for (int i = pSeq->size - 1; i >= index; i--)
	{
		pSeq->array[i + 1] = pSeq->array[i];
	}


	// 2. ����
	pSeq->array[index] = data;
	pSeq->size++;
}


//ɾ����
//1.βɾ
void SeqListPopBack(SeqList* pSeq)
{
	if (pSeq->size <= 0)
	{
		assert(0);
		return;
	}
	pSeq->size--;
}

//2.ͷɾ
void SeqListPopFront(SeqList* pSeq)
{
	assert(pSeq);
	//��˳���
	if(pSeq->size <= 0)
	{
		assert(0);
		return;
	}

	for (int i = 1; i < pSeq->size; i++)
	{
		pSeq->array[i - 1] = pSeq->array[i];
	}

	pSeq->size--;
}

//3. �м�ɾ��
void SeqListErase(SeqList* pSeq, int index)
{
	assert(pSeq);
	assert(index >= 0 && index <= pSeq->size - 1);
	if (pSeq->size <= 0)
	{
		assert(0);
		return;
	}

	//1.���ݰ���
	for (int i = index + 1; i < pSeq->size ; i++)
	{
		pSeq->array[i - 1] = pSeq->array[i];
	}
	//2. ɾ��
	pSeq->size--;
}

//   ����
//   ���ҵ�һ�������������±꣬û�ҵ�����-1
int SeqListFind(SeqList* pSeq , DataType data)
{
	//���ֲ���(����)
	//˳�����
	for (int i = 0; i < pSeq->size; i++)
	{
		if (pSeq->array[i] == data)
		{
			return i;
		}
	}
	return -1;
}
void SeqListPrint(SeqList* const pSeq)
{
	assert(pSeq);
	for (int i = 0; i < pSeq->size; i++)
	{
		printf("%d " , pSeq->array[i]);
	}
	printf("\n");
}

//ɾ���ڶ���(��������ɾ��)
//ɾ�������ĵ�һ������

void SeqListRemove(SeqList* pSeq, DataType data)
{
	int index = SeqListFind(pSeq, data);
	if (index != -1)
	{
		SeqListErase(pSeq, index);
	}
}

void SeqListRemoveAll(SeqList *pSeq, DataType data)
{
	//1.��һ�ַ�ʽ  �� N^N
	//int index;
	//while ((index = SeqListFind(pSeq, data)) != -1)
	//{
	//	SeqListErase(pSeq, index);

	//}

#if 0
	//2.һ�α���ɾ�� �ŵ㣺�죬һ�α���  ȱ�㣺�������µĿռ䣬�ռ��С��size�й�ϵ
	//1) ��������
	DataType* newArr = malloc(sizeof(DataType) * pSeq->size);
	int i, j;
	
	//���ҵ��Ĳ�ɾ�������ŵ���������
	for (i = 0, j = 0; i < pSeq->size; i++)
	{
		if (pSeq->array[i] != data)
		{
			newArr[j] = pSeq->array[i];
			j++;
		}
	}

	//���������������˳���(û��Ҫɾ��������)
	for (int i = 0; i < j; i++)
	{
		pSeq->array[i] = newArr[i];
	}

	//����  size  �Ĵ�С

	pSeq->size = j;

	//�ͷ��ڴ�
	free(newArr);
#endif
	
	//�����ַ���
	int i, j;
	for (i = 0, j = 0; i < pSeq->size; i++)
	{
		if (pSeq->array[i] != data)
		{
			pSeq->array[j] = pSeq->array[i];
			j++;
		}
	}
	pSeq->size = j;
}


#pragma once
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#define INIT_CAPACITY (10)
//��̬˳���
//��̬˳�����������Զ�̬����


typedef int DataType;
typedef struct SeqListD
{
	DataType* array;
	int capacity; // ��ǰ���� �� ��ͬ�ھ�̬˳���MAX_SIZE
	int size;    //  ͬ��̬˳���

}SeqListD;

//��ʼ��
void SeqListDInit(SeqListD* pSeq)
{
	pSeq->capacity = INIT_CAPACITY;
	pSeq->size = 0;
	pSeq->array = (DataType*)malloc(pSeq->capacity * sizeof(DataType));
	assert(pSeq->array);
}

//����
void SeqlistDDestory(SeqListD* pSeq)
{
	assert(pSeq->array);
	pSeq->size = 0;
	pSeq->capacity = 0;
	free(pSeq->array);
	pSeq->array = NULL;
}

//˽�У�������Ľӿ�
//������������
static void ExpandIfRequired(SeqListD* pSeq)
{
	//0. �����Ϸ��Լ�� , �ж��Ƿ���Ҫ����
	assert(pSeq);
	if (pSeq->size < pSeq->capacity) return;
	//1.�����µĶ��ϵ��ڴ棬��СΪԭ��������2��
	DataType* newArr = (DataType*)malloc(sizeof(DataType) * pSeq->capacity * 2);
	assert(newArr);
	//2.���ڴ��е����ݰ��Ƶ��µĿռ�
	for (int i = 0; i < pSeq->size; i++)
	{
		newArr[i] = pSeq->array[i];
	}
	//3.����capacity
	pSeq->capacity *= 2;
	//4.�ͷžɿռ�
	free(pSeq->array);
	//5.�ö�̬˳����ָ��ָ���µĿռ�
	pSeq->array = newArr;
}
//�� 1. β��
void SeqListDPushBack(SeqListD* pSeq, DataType data)
{
	//������ˣ����� capacity >= size
	ExpandIfRequired(pSeq);
	pSeq->array[pSeq->size++] = data;
}

//�� 2. ͷ��
void SeqListDPushFront(SeqListD* pSeq , DataType data)
{
	ExpandIfRequired(pSeq);

	//��������
	for (int i = pSeq->size - 1; i >= 0; i--)
	{
		pSeq->array[i + 1] = pSeq->array[i];
	}

	pSeq->array[0] = data;
	pSeq->size++;
}

//�� 3. ����   
void SeqListDInsert(SeqListD* pSeq, int index, DataType data)
{
	assert(pSeq);
	assert(index <= pSeq->size &&index >= 0);

	ExpandIfRequired(pSeq);

	
	for (int i = pSeq->size - 1; i >= index; i--)
	{
		pSeq->array[i + 1] = pSeq->array[i];
	}

	pSeq->array[index] = data;
	pSeq->size++;
	
}
//ɾ�� 1.βɾ
void SeqListDPopBack(SeqListD* pSeq)
{
	assert(pSeq);
	assert(pSeq->size > 0);

	pSeq->size--;
}
//ɾ�� 2. ͷɾ
void SeqListDPopFront(SeqListD* pSeq)
{
	assert(pSeq);
	assert(pSeq->size > 0);

	for (int i = 1; i < pSeq->size; i++)
	{
		pSeq->array[i - 1] = pSeq->array[i];
	}

	pSeq->size--;

}
//ɾ��  3.ɾ��ָ��λ��
void SeqListDErase(SeqListD* pSeq, int index)
{
	assert(pSeq);
	assert(index >= 0 && index < pSeq->size);

	for (int i = index + 1; i < pSeq->size; i++)
	{
		pSeq->array[i - 1] = pSeq->array[i];
	}

	pSeq->size--;
}
//ɾ��  ���
void SeqListDEmpty(SeqListD* pSeq)
{
	for (int i = 0; i < pSeq->size; i++)
	{
		SeqListDPopBack(pSeq);
	}

	pSeq->size = 0;
}
//�޸�ָ���±��Ԫ��
void SeqListDSet(SeqListD* pSeq, int index , DataType data)
{
	assert(pSeq);
	assert(index >= 0 && index < pSeq->size);

	pSeq->array[index] = data;
}
// ��ѯ
DataType SeqListDGet(SeqListD* pSeq, int index)
{
	assert(pSeq);
	assert(index >= 0 && index < pSeq->size);

	return pSeq->array[index];
}
//����  ����
void SeqListDBubbleSort(SeqListD* pSeq)
{
	int isSorted = 1;
	for (int i = 0; i < pSeq->size - 1; i++)
	{
		for (int j = 0; j < pSeq->size - i - 1; j++)
		{
			if (pSeq->array[j] < pSeq->array[j + 1])
			{
				isSorted = 0;
				int temp = pSeq->array[j];
				pSeq->array[j] = pSeq->array[j + 1];
				pSeq->array[j + 1] = temp;
			}
		}
		if (isSorted) break;
	}

}

//��ӡ˳���
void PrintSeqListD(SeqListD* pSeq)
{
	assert(pSeq);
	for (int i = 0; i < pSeq->size; i++)
	{
		printf("%d " , pSeq->array[i]);
	}
	printf("\n");

}

//���Ժ���
void SeqListDTest()
{
	SeqListD seqListD;
	SeqListDInit(&seqListD);
	
	SeqListDPushBack(&seqListD, 0);
	SeqListDPushBack(&seqListD, 1);
	SeqListDPushBack(&seqListD, 2);
	SeqListDPushBack(&seqListD, 3);
	SeqListDPushBack(&seqListD, 4);
	SeqListDPushBack(&seqListD, 5); 
	
	SeqListDSet(&seqListD, 0, 10);
	SeqListDSet(&seqListD, 1, 100);
	SeqListDSet(&seqListD, 2, 1000);
	SeqListDSet(&seqListD, 3, 10000);
	SeqListDSet(&seqListD, 4, 100000);
	SeqListDSet(&seqListD, 5, 1000000);

	//SeqListDEmpty(&seqListD);
	//printf("%d ", seqListD.capacity);
	SeqListDBubbleSort(&seqListD);
	PrintSeqListD(&seqListD);
	/*for (int i = 0; i < seqListD.size; i++)
	{
		printf("%d ", SeqListDGet(&seqListD, i));
	}*/
}
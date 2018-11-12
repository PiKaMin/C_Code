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
//�� β��
void SeqListDPushBack(SeqListD* pSeq, DataType data)
{
	//������ˣ����� capacity >= size
	ExpandIfRequired(pSeq);
	pSeq->array[pSeq->size++] = data;
}

//�� ͷ��
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


void PrintSeqListD(SeqListD* pSeq)
{
	assert(pSeq);
	for (int i = 0; i < pSeq->size; i++)
	{
		printf("%d " , pSeq->array[i]);
	}
	printf("\n");

}
void SeqListDTest()
{
	SeqListD seqListD;
	SeqListDInit(&seqListD);
	
	SeqListDPushFront(&seqListD, 10);
	SeqListDPushFront(&seqListD, 9);
	SeqListDPushFront(&seqListD, 8);
	SeqListDPushFront(&seqListD, 7);
	SeqListDPushFront(&seqListD, 6);
	SeqListDPushFront(&seqListD, 5);
	SeqListDPushFront(&seqListD, 4);
	SeqListDPushFront(&seqListD, 3);
	SeqListDPushFront(&seqListD, 2);
	SeqListDPushFront(&seqListD, 1);
	SeqListDPushFront(&seqListD, 0);
	SeqListDPushFront(&seqListD, -1);
	SeqListDPushFront(&seqListD, -2);
	SeqListDPushFront(&seqListD, -3);
	SeqListDPushFront(&seqListD, -4);
	SeqListDPushFront(&seqListD, -5);

	//printf("%d ", seqListD.capacity);
	PrintSeqListD(&seqListD);
}
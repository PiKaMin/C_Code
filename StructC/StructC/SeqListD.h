#pragma once
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#define INIT_CAPACITY (10)
//动态顺序表
//动态顺序表的容量可以动态增加


typedef int DataType;
typedef struct SeqListD
{
	DataType* array;
	int capacity; // 当前容量 ， 等同于静态顺序表MAX_SIZE
	int size;    //  同静态顺序表

}SeqListD;

//初始化
void SeqListDInit(SeqListD* pSeq)
{
	pSeq->capacity = INIT_CAPACITY;
	pSeq->size = 0;
	pSeq->array = (DataType*)malloc(pSeq->capacity * sizeof(DataType));
	assert(pSeq->array);
}

void SeqlistDDestory(SeqListD* pSeq)
{
	assert(pSeq->array);
	pSeq->size = 0;
	pSeq->capacity = 0;
	free(pSeq->array);
	pSeq->array = NULL;
}

//私有，不对外的接口
//用来处理扩容
static void ExpandIfRequired(SeqListD* pSeq)
{
	//0. 参数合法性检查 , 判断是否需要扩容
	assert(pSeq);
	if (pSeq->size < pSeq->capacity) return;
	//1.申请新的堆上的内存，大小为原来容量的2倍
	DataType* newArr = (DataType*)malloc(sizeof(DataType) * pSeq->capacity * 2);
	assert(newArr);
	//2.旧内存中的数据搬移到新的空间
	for (int i = 0; i < pSeq->size; i++)
	{
		newArr[i] = pSeq->array[i];
	}
	//3.更新capacity
	pSeq->capacity *= 2;
	//4.释放旧空间
	free(pSeq->array);
	//5.让动态顺序表的指针指向新的空间
	pSeq->array = newArr;
}
void SeqListDPushBack(SeqListD* pSeq, DataType data)
{
	//如果满了，扩容 capacity >= size
	ExpandIfRequired(pSeq);
	pSeq->array[pSeq->size++] = data;
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
	SeqListDPushBack(&seqListD, 1);
	SeqListDPushBack(&seqListD, 2);
	SeqListDPushBack(&seqListD, 3);
	SeqListDPushBack(&seqListD, 4);
	SeqListDPushBack(&seqListD, 5);
	SeqListDPushBack(&seqListD, 6);
	SeqListDPushBack(&seqListD, 7);
	SeqListDPushBack(&seqListD, 8);
	printf("%d " , seqListD.capacity);
	SeqListDPushBack(&seqListD, 1);
	SeqListDPushBack(&seqListD, 2);
	SeqListDPushBack(&seqListD, 3);
	SeqListDPushBack(&seqListD, 4);
	SeqListDPushBack(&seqListD, 5);
	SeqListDPushBack(&seqListD, 6);
	SeqListDPushBack(&seqListD, 7);
	SeqListDPushBack(&seqListD, 8);

	printf("%d ", seqListD.capacity);
	PrintSeqListD(&seqListD);
}
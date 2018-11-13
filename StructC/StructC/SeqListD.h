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

//销毁
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
//增 1. 尾插
void SeqListDPushBack(SeqListD* pSeq, DataType data)
{
	//如果满了，扩容 capacity >= size
	ExpandIfRequired(pSeq);
	pSeq->array[pSeq->size++] = data;
}

//增 2. 头插
void SeqListDPushFront(SeqListD* pSeq , DataType data)
{
	ExpandIfRequired(pSeq);

	//搬移数据
	for (int i = pSeq->size - 1; i >= 0; i--)
	{
		pSeq->array[i + 1] = pSeq->array[i];
	}

	pSeq->array[0] = data;
	pSeq->size++;
}

//增 3. 插入   
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
//删除 1.尾删
void SeqListDPopBack(SeqListD* pSeq)
{
	assert(pSeq);
	assert(pSeq->size > 0);

	pSeq->size--;
}
//删除 2. 头删
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
//删除  3.删除指定位置
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
//删除  清空
void SeqListDEmpty(SeqListD* pSeq)
{
	for (int i = 0; i < pSeq->size; i++)
	{
		SeqListDPopBack(pSeq);
	}

	pSeq->size = 0;
}
//修改指定下标的元素
void SeqListDSet(SeqListD* pSeq, int index , DataType data)
{
	assert(pSeq);
	assert(index >= 0 && index < pSeq->size);

	pSeq->array[index] = data;
}
// 查询
DataType SeqListDGet(SeqListD* pSeq, int index)
{
	assert(pSeq);
	assert(index >= 0 && index < pSeq->size);

	return pSeq->array[index];
}
//排序  降序
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

//打印顺序表
void PrintSeqListD(SeqListD* pSeq)
{
	assert(pSeq);
	for (int i = 0; i < pSeq->size; i++)
	{
		printf("%d " , pSeq->array[i]);
	}
	printf("\n");

}

//测试函数
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
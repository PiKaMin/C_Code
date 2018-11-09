#pragma once
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
//静态顺序表

typedef int DataType;
#define MAX_SIZE (100)
typedef struct SeqList
{
	DataType array[MAX_SIZE];
	int size ;		// 1.保存顺序表里已经存了的数据的个数
						// 2.当前可用下标
}  SeqList ;

//接口(函数)
//初始化/销毁
//增、删、查、改


//初始化
void SeqListInit(SeqList* pSeq)
{
	// 1.初始化 size
	// 2.可能需要把容器空间清空

	assert(pSeq != NULL);
	pSeq->size = 0;
}


//销毁
void SeqListDestory(SeqList *pSeq)
{
	assert(pSeq);
	pSeq->size = 0;
}


//增加
//1.尾插(命名尽量和 C++ STL统一)
void SeqListPushBack(SeqList* pSeq, DataType data)
{
	assert(pSeq);

	//满了
	if (pSeq->size >= MAX_SIZE)
	{
		assert(0);
		return;
	}
	pSeq->array[pSeq->size] = data;
	pSeq->size++;
}

//2.头插
void SeqListPushFront(SeqList* pSeq, DataType data)
{
	assert(pSeq);
	if (pSeq->size >= MAX_SIZE)
	{
		assert(0);
		return;
	}

	// 1. i 代表位置
	/*for (int i = pSeq->size; i > 0; i--)
	{
		pSeq->array[i] = pSeq->array[i - 1];
	}*/

	// 2. i 代表元素
	for (int i = pSeq->size - 1; i >= 0; i--)
	{
		pSeq->array[i + 1] = pSeq->array[i];
	}

	pSeq->array[0] = data;
	pSeq->size++;
}

//3. 中间插入
//index : 数组的下标
void SeqListInsert(SeqList* pSeq, int index, DataType data)
{
	assert(pSeq);
	assert(index >= 0 && index <= pSeq->size);//给定的下标不合理
	if (pSeq->size >= MAX_SIZE)
	{
		assert(0);
		return;
	}

	// 1.数据搬移
	for (int i = pSeq->size - 1; i >= index; i--)
	{
		pSeq->array[i + 1] = pSeq->array[i];
	}


	// 2. 插入
	pSeq->array[index] = data;
	pSeq->size++;
}


//删除：
//1.尾删
void SeqListPopBack(SeqList* pSeq)
{
	if (pSeq->size <= 0)
	{
		assert(0);
		return;
	}
	pSeq->size--;
}

//2.头删
void SeqListPopFront(SeqList* pSeq)
{
	assert(pSeq);
	//空顺序表
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

//3. 中间删除
void SeqListErase(SeqList* pSeq, int index)
{
	assert(pSeq);
	assert(index >= 0 && index <= pSeq->size - 1);
	if (pSeq->size <= 0)
	{
		assert(0);
		return;
	}

	//1.数据搬移
	for (int i = index + 1; i < pSeq->size ; i++)
	{
		pSeq->array[i - 1] = pSeq->array[i];
	}
	//2. 删除
	pSeq->size--;
}

//   查找
//   查找第一个遇到的数的下标，没找到返回-1
int SeqListFind(SeqList* pSeq , DataType data)
{
	//二分查找(有序)
	//顺序查找
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

//删除第二种(根据数据删除)
//删除遇到的第一个数据

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
	//1.第一种方式  慢 N^N
	//int index;
	//while ((index = SeqListFind(pSeq, data)) != -1)
	//{
	//	SeqListErase(pSeq, index);

	//}

#if 0
	//2.一次遍历删除 优点：快，一次遍历  缺点：开辟了新的空间，空间大小和size有关系
	//1) 开新数组
	DataType* newArr = malloc(sizeof(DataType) * pSeq->size);
	int i, j;
	
	//将找到的不删除的数放到新数组中
	for (i = 0, j = 0; i < pSeq->size; i++)
	{
		if (pSeq->array[i] != data)
		{
			newArr[j] = pSeq->array[i];
			j++;
		}
	}

	//将新数组的数返回顺序表(没有要删除的数了)
	for (int i = 0; i < j; i++)
	{
		pSeq->array[i] = newArr[i];
	}

	//更改  size  的大小

	pSeq->size = j;

	//释放内存
	free(newArr);
#endif
	
	//第三种方法
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


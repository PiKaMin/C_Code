#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
typedef int DataType;

//链表中的一个结点
//链表定义  vs  顺序表定义
//顺序表直接定义一个顺序表，链表结构体定义的是一条链表中的一个结点
typedef struct LinkedListNode
{
	DataType data;
	struct LinkedListNode* next;
}LinkedListNode;

//初始化
void LinkedlistInit(LinkedListNode** ppFirst)
{
	assert(ppFirst);
	*ppFirst = NULL;  //初始化为空链表
}
//销毁
void LinkedListDestory(LinkedListNode** ppFirst)
{
	//TODO
	*ppFirst = NULL;
}
//创建一个新结点
static LinkedListNode* CreateNewNode(DataType data)
{
	LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	assert(newNode);
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
//增删改查

//头插
void LinkedListPushFront(LinkedListNode** ppFirst, DataType data)
{
	assert(ppFirst);
	
	//正常情况
	LinkedListNode* newNode = CreateNewNode(data);
	newNode->next = *ppFirst;
	*ppFirst = newNode;

}
//尾插
void LinkedListPushBack(LinkedListNode** ppFirst, DataType data)
{
	assert(ppFirst);
	LinkedListNode* temp = *ppFirst;
	LinkedListNode* newNode = CreateNewNode(data);

	//特殊情况，链表为空
	if (temp == NULL)  //把新结点的地址赋给 pFirst
	{
		*ppFirst = newNode;
		return;
	}
	//一般情况
	while (temp->next != NULL)//先找到最后一个结点，然后加在最后一个结点后
	{
		temp = temp->next;
	}
	temp->next = newNode;
}
//头删
void LinkedListPopFront(LinkedListNode** ppFirst)
{
	assert(ppFirst);
	//特殊情况，链表为空,结束程序
	assert((*ppFirst));
	//一般情况
	LinkedListNode* deleteNode = (*ppFirst);
	(*ppFirst) = deleteNode->next;
	free(deleteNode);
}
//尾删
void LinkedListPopBack(LinkedListNode** ppFirst)
{
	assert(ppFirst);
	assert((*ppFirst)); // 链表为空

	LinkedListNode* temp = *ppFirst;
	//链表只有一个结点
	if (temp->next == NULL)
	{

		free(temp);
		temp = NULL;
		*ppFirst = NULL;
		return;
	}
	//一般情况
	while (temp->next->next != NULL)
	{
		temp = temp->next; //temp  ==  倒数第二个结点
	}
	free(temp->next);
	temp->next = NULL;
}
void LikedListPrint(LinkedListNode* const pFirst)
{
	for (LinkedListNode* temp = pFirst; temp != NULL; temp = temp->next)
	{
		printf("%d ", temp->data);
	}
	printf("\n");
}
//链表测试函数
void LinkedListTest()
{
	LinkedListNode* first;
	LinkedlistInit(&first);
	/*LinkedListPushFront(&first, 4);
	LinkedListPushFront(&first, 3);
	LinkedListPushFront(&first, 2);
	LinkedListPushFront(&first, 1);*/

	LinkedListPushBack(&first, 5);
	LinkedListPushBack(&first, 6);


	LinkedListPopBack(&first);
	LinkedListPopBack(&first);
	//sLinkedListPopBack(&first);
	//LinkedListPopBack(&first);
	//LinkedListPopBack(&first);
	////
	//LinkedListPopBack(&first);


	LikedListPrint(first);
}
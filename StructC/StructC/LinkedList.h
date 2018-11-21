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
//查找
LinkedListNode* LinkedListFind(LinkedListNode* pFirst , DataType data)
{
	for (LinkedListNode* temp = pFirst; temp != NULL; temp = temp->next)
	{
		if (data == temp->data)
		{
			return temp;
		}
	}
	return NULL;
}
//在结点前做插入
void LinkedListInsert(LinkedListNode** ppFirst, LinkedListNode* pos, DataType data)
{
	//头插 
	if (*ppFirst == pos)
	{
		LinkedListPushFront(ppFirst, data);
		return;
	}

	//一般情况
	LinkedListNode* temp = *ppFirst;
	while (temp->next != pos)
	{
		temp = temp->next;
	}

	LinkedListNode* newNode = CreateNewNode(data);
	newNode->next = temp->next;
	temp->next = newNode;
}
//删除指定结点
void LinkeListErase(LinkedListNode** ppFirst, LinkedListNode* pos)
{
	//头删
	if (*ppFirst == pos)
	{
		LinkedListPopFront(ppFirst);
		return;
	}

	LinkedListNode* temp = *ppFirst;
	while (temp->next != pos)
	{
		temp = temp->next;
	}
	
	temp->next = pos->next;
	free(pos);
	pos = NULL;
}
//打印
void LikedListPrint(LinkedListNode* const pFirst)
{
	for (LinkedListNode* temp = pFirst; temp != NULL; temp = temp->next)
	{
		printf("%d ", temp->data);
	}
	printf("\n");
}

//***************************************
//***********链表面试题******************
//***************************************


//1. 从尾到头打印单链表
//利用递归
void LinkedListPrintReverseRecursion(LinkedListNode* pCur)
{	
	if (pCur == NULL) return;

	LinkedListPrintReverseRecursion(pCur->next);
	printf("%d ", pCur->data);
}
//非递归
void LinkedListPrintReverse(LinkedListNode* pFirst)
{
	LinkedListNode* end = NULL;
	while (end != pFirst)
	{
		LinkedListNode* temp = pFirst;
		while (temp->next != end)
		{
			temp = temp->next;
		}
		printf("%d " , temp->data);

		end = temp;
	}
	printf("\n");
}

//2. 逆置反转单链表 , 原链表上
void LinkedListReverse(LinkedListNode** ppFirst)
{
	
	LinkedListNode* temp = *ppFirst;

	while (temp != NULL)
	{
		LinkedListNode* next = temp->next;
		if (temp == *ppFirst)
		{
			temp->next = NULL;
		}
		else
		{
			temp->next = *ppFirst;
			*ppFirst = temp;
		}
		temp = next;
	
	}
}
//2.逆置链表，返回新链表
//一个链表头删，一个链表头插
LinkedListNode* LinkedListReverseNew(LinkedListNode* pFirst)
{
	LinkedListNode* cur = pFirst;
	LinkedListNode* node;
	LinkedListNode* result = NULL;

	while (cur != NULL)
	{
		node = cur;
		cur = cur->next;

		node->next = result;
		result = node;
	}

	return result;
}
//3. 删除一个无头单链表的非尾结点(不能遍历链表)
void RemoveNoFirst(LinkedListNode* pos)
{
	pos->data = pos->next->data;
	LinkedListNode* del = pos->next;
	pos->next = pos->next->next;

	free(del);
}
//4. 在无头单链表中的一个结点前插入一个结点(不能遍历链表)
void InsertNoFirst(LinkedListNode* pos , DataType data)
{
	LinkedListNode* newNode =CreateNewNode(data);
	newNode->next = pos->next;
	pos->next = newNode;

	int temp = newNode->data;
	newNode->data = pos->data;
	pos->data = temp;
}
//5.单链表实现约瑟夫环
LinkedListNode* JosephCycle(LinkedListNode* pfirst, int k)
{
	//1.将单链表构造成环 ,找到最后一个结点,令最后一个的next指向第一个
	LinkedListNode* temp = pfirst;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	//temp   是最后一个结点
	temp->next = pfirst;   //单链表成一个环

	LinkedListNode* cur = pfirst;

	while (cur->next != cur)  //结束条件,当自己的next指向自己,说明只剩一个结点
	{
		//每走 k 次 删掉一个结点

		LinkedListNode* prev = NULL; //要删除结点的前一个结点
		for (int i = 0; i < k - 1; i++)
		{
			prev = cur;
			cur = cur->next; //要删除的结点
		}

		prev->next = cur->next;
		free(cur);
		cur = prev->next;
	}

	cur->next = NULL; //将剩余的一个结点转成单链表

	return cur;
	
}
//6. 合并两个升序链表,合并后依然是升序
LinkedListNode* MergeOrderList(LinkedListNode* list1, LinkedListNode* list2)
{
	LinkedListNode* cur1 = list1;
	LinkedListNode* cur2 = list2;
	LinkedListNode* result = NULL; //结果链表
	LinkedListNode* tail = NULL;   //结果链表尾结点方便尾插
	LinkedListNode* next = NULL;   //保存遍历过程中的下一个结点

	while (cur1 != NULL && cur2 != NULL)
	{
		if (cur1->data <= cur2->data)
		{			
			// 将cur1 尾插到result
			/*if (result != NULL)
			{
				next = cur1;

				tail->next = cur1;
				cur1->next = NULL;
				tail = cur1;

				cur1 = next;
			}
			else
			{
				next = cur1;

				result = cur1;
				cur1->next = NULL;
				tail = cur1;

				cur1 = next;
			}*/
		}
		else
		{
			// 将cur2 尾插到result
		}
	}

	if (cur1 == NULL)
	{
		tail->next = cur2;
	}
	if (cur2 == NULL)
	{
		tail->next = cur1;
	}
	return result;
}
//链表测试函数
void LinkedListTest()
{
	LinkedListNode* first;
	LinkedlistInit(&first);

	for (int i = 1; i < 8; i++)
	{
		LinkedListPushBack(&first, i);
	}
	LikedListPrint(first);
	first = JosephCycle(first, 3);
	LikedListPrint(first);

	/*LinkedListPushFront(&first, 4);
	LinkedListPushFront(&first, 3);
	LinkedListPushFront(&first, 2);
	LinkedListPushFront(&first, 1);*/

	/*LinkedListPushBack(&first, 1);
	LinkedListPushBack(&first, 2);
	LinkedListPushBack(&first, 3);
	LinkedListPushBack(&first, 4);
	LinkedListPushBack(&first, 5);

	LinkedListReverse(&first);*/
	/*LinkedListPopBack(&first);
	LinkedListPopBack(&first);*/
	//sLinkedListPopBack(&first);
	//LinkedListPopBack(&first);
	//LinkedListPopBack(&first);
	////
	//LinkedListPopBack(&first);

	//LinkedListPrintReverseRecursion(first);
	//printf("\n");
	//LikedListPrint(first);
}
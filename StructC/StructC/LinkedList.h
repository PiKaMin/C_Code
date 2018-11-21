#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
typedef int DataType;

//�����е�һ�����
//������  vs  ˳�����
//˳���ֱ�Ӷ���һ��˳�������ṹ�嶨�����һ�������е�һ�����
typedef struct LinkedListNode
{
	DataType data;
	struct LinkedListNode* next;
}LinkedListNode;

//��ʼ��
void LinkedlistInit(LinkedListNode** ppFirst)
{
	assert(ppFirst);
	*ppFirst = NULL;  //��ʼ��Ϊ������
}
//����
void LinkedListDestory(LinkedListNode** ppFirst)
{
	//TODO
	*ppFirst = NULL;
}
//����һ���½��
static LinkedListNode* CreateNewNode(DataType data)
{
	LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	assert(newNode);
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
//��ɾ�Ĳ�

//ͷ��
void LinkedListPushFront(LinkedListNode** ppFirst, DataType data)
{
	assert(ppFirst);
	
	//�������
	LinkedListNode* newNode = CreateNewNode(data);
	newNode->next = *ppFirst;
	*ppFirst = newNode;

}
//β��
void LinkedListPushBack(LinkedListNode** ppFirst, DataType data)
{
	assert(ppFirst);
	LinkedListNode* temp = *ppFirst;
	LinkedListNode* newNode = CreateNewNode(data);

	//�������������Ϊ��
	if (temp == NULL)  //���½��ĵ�ַ���� pFirst
	{
		*ppFirst = newNode;
		return;
	}
	//һ�����
	while (temp->next != NULL)//���ҵ����һ����㣬Ȼ��������һ������
	{
		temp = temp->next;
	}
	temp->next = newNode;
}
//ͷɾ
void LinkedListPopFront(LinkedListNode** ppFirst)
{
	assert(ppFirst);
	//�������������Ϊ��,��������
	assert((*ppFirst));
	//һ�����
	LinkedListNode* deleteNode = (*ppFirst);
	(*ppFirst) = deleteNode->next;
	free(deleteNode);
}
//βɾ
void LinkedListPopBack(LinkedListNode** ppFirst)
{
	assert(ppFirst);
	assert((*ppFirst)); // ����Ϊ��

	LinkedListNode* temp = *ppFirst;
	//����ֻ��һ�����
	if (temp->next == NULL)
	{

		free(temp);
		temp = NULL;
		*ppFirst = NULL;
		return;
	}
	//һ�����
	while (temp->next->next != NULL)
	{
		temp = temp->next; //temp  ==  �����ڶ������
	}
	free(temp->next);
	temp->next = NULL;
}
//����
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
//�ڽ��ǰ������
void LinkedListInsert(LinkedListNode** ppFirst, LinkedListNode* pos, DataType data)
{
	//ͷ�� 
	if (*ppFirst == pos)
	{
		LinkedListPushFront(ppFirst, data);
		return;
	}

	//һ�����
	LinkedListNode* temp = *ppFirst;
	while (temp->next != pos)
	{
		temp = temp->next;
	}

	LinkedListNode* newNode = CreateNewNode(data);
	newNode->next = temp->next;
	temp->next = newNode;
}
//ɾ��ָ�����
void LinkeListErase(LinkedListNode** ppFirst, LinkedListNode* pos)
{
	//ͷɾ
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
//��ӡ
void LikedListPrint(LinkedListNode* const pFirst)
{
	for (LinkedListNode* temp = pFirst; temp != NULL; temp = temp->next)
	{
		printf("%d ", temp->data);
	}
	printf("\n");
}

//***************************************
//***********����������******************
//***************************************


//1. ��β��ͷ��ӡ������
//���õݹ�
void LinkedListPrintReverseRecursion(LinkedListNode* pCur)
{	
	if (pCur == NULL) return;

	LinkedListPrintReverseRecursion(pCur->next);
	printf("%d ", pCur->data);
}
//�ǵݹ�
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

//2. ���÷�ת������ , ԭ������
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
//2.������������������
//һ������ͷɾ��һ������ͷ��
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
//3. ɾ��һ����ͷ������ķ�β���(���ܱ�������)
void RemoveNoFirst(LinkedListNode* pos)
{
	pos->data = pos->next->data;
	LinkedListNode* del = pos->next;
	pos->next = pos->next->next;

	free(del);
}
//4. ����ͷ�������е�һ�����ǰ����һ�����(���ܱ�������)
void InsertNoFirst(LinkedListNode* pos , DataType data)
{
	LinkedListNode* newNode =CreateNewNode(data);
	newNode->next = pos->next;
	pos->next = newNode;

	int temp = newNode->data;
	newNode->data = pos->data;
	pos->data = temp;
}
//5.������ʵ��Լɪ��
LinkedListNode* JosephCycle(LinkedListNode* pfirst, int k)
{
	//1.����������ɻ� ,�ҵ����һ�����,�����һ����nextָ���һ��
	LinkedListNode* temp = pfirst;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	//temp   �����һ�����
	temp->next = pfirst;   //�������һ����

	LinkedListNode* cur = pfirst;

	while (cur->next != cur)  //��������,���Լ���nextָ���Լ�,˵��ֻʣһ�����
	{
		//ÿ�� k �� ɾ��һ�����

		LinkedListNode* prev = NULL; //Ҫɾ������ǰһ�����
		for (int i = 0; i < k - 1; i++)
		{
			prev = cur;
			cur = cur->next; //Ҫɾ���Ľ��
		}

		prev->next = cur->next;
		free(cur);
		cur = prev->next;
	}

	cur->next = NULL; //��ʣ���һ�����ת�ɵ�����

	return cur;
	
}
//6. �ϲ�������������,�ϲ�����Ȼ������
LinkedListNode* MergeOrderList(LinkedListNode* list1, LinkedListNode* list2)
{
	LinkedListNode* cur1 = list1;
	LinkedListNode* cur2 = list2;
	LinkedListNode* result = NULL; //�������
	LinkedListNode* tail = NULL;   //�������β��㷽��β��
	LinkedListNode* next = NULL;   //������������е���һ�����

	while (cur1 != NULL && cur2 != NULL)
	{
		if (cur1->data <= cur2->data)
		{			
			// ��cur1 β�嵽result
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
			// ��cur2 β�嵽result
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
//������Ժ���
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
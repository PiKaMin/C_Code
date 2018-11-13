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
void LikedListPrint(LinkedListNode* const pFirst)
{
	for (LinkedListNode* temp = pFirst; temp != NULL; temp = temp->next)
	{
		printf("%d ", temp->data);
	}
	printf("\n");
}
//������Ժ���
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
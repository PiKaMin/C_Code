
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Test_01_11_10.h"
#include "Test_09_11_16.h"
#include "Test_01_11_20.h"
#include "Test_02_11_20.h"
#include "Test_01_11_25.h"
//所有的C语言作业运行测试
//2018年 10 月 31 日开始

extern void PrintDiamond(int k);
extern void PrintNarcissisticNumber();
extern void PolynomialSum(int a);
extern int BinarySearch(int* arr, int num, int len);
extern int BinSearch(int* arr, int len, int num);
//extern int GameInit();
//extern void GameLoop();
extern void GuessNum();
extern void Login();
extern void PrintMuliteList(int line);
extern void UpperletterLowLetterConvert();
extern void Swap(int* pa, int* pb);
extern void JudgeLeapYear(int year);
extern int* Init(int length);
extern int empty(int* arr, int length);
extern void reverse(int* arr, int length);
extern void JudgePrimeNum(int num);
extern int FibRecursion(int n);
extern int FibNotRecursion(int n);
extern double MyPow(int n, int k);
extern int  DigitSum(int n);
extern int Factorial(int n);
extern int FactorialRecursion(int n);
extern int MyStrlenNotRecursion(char* str);
extern int MyStrlenRecursion(char* str);
extern void PrintNumber(int n);
extern void reverse_string(char * string);

void PrintArr(int* arr, int length);
int main()
{
	////1. 初始化游戏
	//InitBorad();
	////2. 打印棋盘
	//PrintBoard();
	////3.游戏循环
	//BoradGameLoop();

	//扫雷游戏
	//MineSweeper();
	
	//第十次作业
	//Test1_11_20();
	//PrintAverage(-20, 0);
	//printf("%u\n", reverse_bit(25));
	FindSingleNum();
	//FindBitDifferent(1, -1);
	//printf("%x\n" , -3);
	//printf("%d\n", count_one_bits(15));
	printf("\n");
	system("pause");
	return 0;
	//PrintDiamond(15);
	//PrintNarcissisticNumber();
	//PolynomialSum(2);
	//int arr[] = { 1 , 2 , 3 , 4 , 5  , 6 , 7 , 8 , 9};
	//int len = sizeof(arr) / sizeof(arr[0]);
	//printf("%d\n", BinSearch(arr, len, 9));
	//GuessNum();
	//Login();
	//UpperletterLowLetterConvert();
	//PrintMuliteList(12);
	/*int a = 10; int b = 20;
	Swap(&a, &b);
	printf("%d  %d", a, b);*/
	//JudgeLeapYear(2000);
	//int length = 6;
	//int* arr = Init(length);
	//PrintArr(arr, length);
	////empty(arr, length);
	//reverse(arr, length);
	//PrintArr(arr, length);
	//JudgePrimeNum(19);
	//printf("%d\n", FibRecursion(7));
	//printf("%d\n", FactorialRecursion(3));
	//printf("%d\n", Factorial(3));
	//PrintNum(1234567231);
	//printf("%d\n" , MyStrlenNotRecursion("hello"));
	//printf("%d\n" , MyStrlenRecursion("hello"));
	//printf("\n");
	//PrintNumber(123456);;
	/*char s[] = "hello";
	reverse_string(s);
	printf("%s\n" , s);*/


	
}

void PrintArr(int* arr, int length)
{
	printf("[");
	for(int i = 0 ;i < length;i++)
	{
		printf(" %d "  , *(arr + i));
	}
	printf("]\n");
}
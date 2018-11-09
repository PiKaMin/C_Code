#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



#pragma region Ch1_Test1Extern
extern void Ch_1_Test1();
extern int read_column_numbers(int columns[], int max);
extern void rearrange(char* output, char const* input, int n_columns, int const columns[]);
#pragma endregion
#pragma region Ch1Test2Extern
extern void Test_1_1();
extern void Test_1_2();
extern void Test_1_3();
extern void Test_1_4();
#pragma endregion

extern void  BracesMatch();
extern void MySqrt();
int main()
{
	//Ch_1_Test1();
	//Test_1_1();
	//Test_1_2();
	//Test_1_3();
	//Test_1_4();
	//BracesMatch();
	MySqrt();
	system("pause");
	return 0;
}

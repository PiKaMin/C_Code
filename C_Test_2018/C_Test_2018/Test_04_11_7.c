#include <stdio.h>

//4. ��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�
//ʵ�֣��������ַ����е��ַ��������С�
//Ҫ�󣺲���ʹ��C�������е��ַ�������������

extern int MyStrlenRecursion(char* str);
void reverse_string(char * string)
{
	int len = MyStrlenRecursion(string);
	if (len <= 1)
		return;
	else
	{
		char temp = string[0];
		string[0] = string[len - 1];
		string[len - 1] = '\0';
		reverse_string(string + 1);
		string[len - 1] = temp	;

	}
}

//�ǵݹ�
void reverse_string2(char * string) 
{
	int start = 0;
	int end = MyStrlenRecursion(string) - 1;


	
	while (start < end)
	{
		char temp = string[start];
		string[start] = string[end];
		string[end] = temp;

		start++;
		end--;
	}
}



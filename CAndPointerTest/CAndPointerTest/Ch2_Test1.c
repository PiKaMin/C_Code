#include <stdio.h>
#include <stdlib.h>

//2.2 ��дһ�����򣬴ӱ�׼�����ȡCԴ���룬����֤���еĻ�������ȷ��ԣ�
//ע�⣺���ؿ���ע���ڲ����ַ������������ַ�������ʽ�Ļ�����
void  BracesMatch()
{
	int c;
	int braces = 0;
	int errorRight = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == '{')
		{
			braces++;
		}


		if (c == '}')
		{
			if (braces == 0)
			{
				//���Ҵ����Ų�ƥ��
				errorRight++;
			}
			else
			{
				braces--;
			}
		}
	}

	if (braces > 0)
	{
		printf("�д����Ų�ƥ��\n");
		printf("��ƥ��������������%d\n" , braces);
	}
	if (errorRight > 0)
	{
		printf("�д����Ų�ƥ��\n");
		printf("��ƥ����Ҵ���������%d\n" , errorRight);
	}
}

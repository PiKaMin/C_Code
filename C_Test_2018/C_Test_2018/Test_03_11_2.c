#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//3.��д����ģ��������������ĳ�����
//����������������룬������ȷ����ʾ����¼�ɹ���, �������
//�����������룬����������Ρ����ξ�������ʾ�˳�����

//���� ��123456
void Login()
{
	char pwd[1024] = "";

	for (int i = 0; i < 3; i++)
	{
		printf("�������� : ");
		scanf("%s", pwd);

		if (strcmp(pwd, "123456") == 0)
		{
			printf("��¼�ɹ���\n");
			return;
		}
	
		
	}
	printf("����������� , �˳�����\n");
}
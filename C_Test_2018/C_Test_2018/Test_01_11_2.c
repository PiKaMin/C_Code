#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//1.��ɲ�������Ϸ��(1 ~ 100)

int GameInit()
{
	int choose = 0;
	printf("1.��ʼ��Ϸ\n");
	printf("2.�˳���Ϸ\n");
	printf("��������(1 or 2) : ");
	scanf("%d" , &choose);
	return choose;
}
void GameLoop()
{
	int guess = 0;                        //�������
	srand((unsigned int)time(0));        //�������������
	int randomNum = rand() % 100 + 1;   //����һ�� 1~100�������

	for (int i = 1; i <= 10; i++)
	{
		printf("�����%d��Ҫ�µ��� : " , i);
		scanf("%d", &guess);

		if (guess > randomNum)
		{
			printf("����\n");
		}
		else if (guess < randomNum)
		{
			printf("С��\n");
		}
		else
		{
			printf("������\n");
			return ;
		}
	}

	printf("ʮ�ζ�û�в���\n");
}
void GuessNum()
{


	if (GameInit() == 1)  //��ʼ��Ϸ
	{
		
		GameLoop();
	}
	else                 //�˳���Ϸ
	{
		return;
	}
	

}

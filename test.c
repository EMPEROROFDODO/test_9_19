#include "game.h"

//������Ϸ
void game()
{
	//��������
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	//��ʼ������
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//��ӡ����
	//Display(mine, ROW, COL);
	//���õ���
	SetMine(mine, ROW, COL);
	Display(mine, ROW, COL);
	//�Ų����
	FindMine(mine, show, ROW, COL);
}

int main()
{
		int input = 0;
	do
	{
		//��ӡ�˵�
		meun();
		printf("���������ѡ��:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//������Ϸ
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}
#include "game.h"

//�˵�
void meun()
{
	printf("------------------------------\n");
	printf("--------    1.play    --------\n");
	printf("--------    0.exit    --------\n");
	printf("------------------------------\n");
}

//��ʼ������
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

//��ӡ����
void Display(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("------ɨ����Ϸ-----\n\n");
	for (i = 0; i <= col; i++)
	{
		if (i == 0)
		{
			printf("  ");
		}
		else
		printf("%d ", i);
	}	
	printf("\n");
	for (i = 0; i < col; i++)
	{
		if (i == 0)
		{
			printf("  -");
		}
		else
			printf("--");
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d|", i);
		for(j=1;j<=col;j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n-------------------\n\n");
}

//���õ���
void SetMine(char mine[ROWS][COLS], int row, int col)
{
	srand((unsigned int)time(NULL));
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

static int get_mine_count(char mine[ROWS][COLS],int x,int y)
{
	return mine[x - 1][y] + mine[x - 1][y + 1] + mine[x][y + 1] + mine[x + 1][y + 1] + mine[x + 1][y] + mine[x + 1][y - 1] + mine[x][y - 1] + mine[x - 1][y - 1] - 8 * '0';
}

//�Ų����
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
		int x = 0;
		int y = 0;
		int win = 0;
	while (win<row*col-EASY_COUNT)
	{
		system("cls");
		Display(mine, ROW, COL);
		Display(show, ROW, COL);
		printf("��������Ҫ�Ų������:>\n");
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (mine == '1')
			{
				printf("��ϲ,�㱻ը����!\n");
				Display(mine, ROW, COL);
				break;
			}
			else
			{
				int ret = get_mine_count(mine, x, y);
				show[x][y] = ret + '0';
			}
		}
		else
		{
			printf("�����������������:>\n");
		}
	}
	if (win = row * col - EASY_COUNT)
	{
		printf("�ܿ�ϧ����Ӯ��\n");
		Display(mine, ROW, COL);
	}
}

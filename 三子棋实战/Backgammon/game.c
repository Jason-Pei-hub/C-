#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < row - 1)
					printf("|");
			}
			printf("\n");
		}
			
	}
}

void PlayMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("��һغϣ�\n");
	while (1)
	{
		printf("��������������꣺->");
		scanf("%d %d", &x, &y);
		//�ж�����Ϸ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//����
			//�ж������Ƿ�ռ��
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'X';
				break;
			}
			else
			{
				printf("���걻ռ�ã�����������");
			}
		}
		else
		{
			printf("����Ƿ�������������\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("���Իغϣ�\n");
	int i = 0;
	int j = 0;
	//�жϵ����Ƿ��ܹ���ʤ
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				board[i][j] = 'O';
				char ret = IsWin(board, ROW, COL);
				if (ret == 'O')
					return 0;
				else
					board[i][j] = ' ';
			}
			
		}
	}
	//�ж�����Ƿ���Ҫ����
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				board[i][j] = 'X';
				char ret = IsWin(board, ROW, COL);
				if (ret == 'X')
				{
					board[i][j] = 'O';
					return 0;
				}
				else
					board[i][j] = ' ';
			}
		}
	}

	while (1)
	{
		int x = rand() % ROW;
		int y = rand() % COL;
		if (board[x][y] = ' ')
		{
			board[x][y] = 'O';
			break;
		}
	}

}

char IsWin(char board[ROW][COL], int row, int col) {
	// ���ÿ��
	for (int i = 0; i < row; i++) {
		if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X') {
			return 'X'; // ���Ӯ��
		}
		else if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O') {
			return 'O'; // ����Ӯ��
		}
	}

	// ���ÿ��
	for (int j = 0; j < col; j++) {
		if (board[0][j] == 'X' && board[1][j] == 'X' && board[2][j] == 'X') {
			return 'X'; // ���Ӯ��
		}
		else if (board[0][j] == 'O' && board[1][j] == 'O' && board[2][j] == 'O') {
			return 'O'; // ����Ӯ��
		}
	}

	// ���Խ���
	if ((board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') ||
		(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')) {
		return 'X'; // ���Ӯ��
	}
	else if ((board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') ||
		(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')) {
		return 'O'; // ����Ӯ��
	}

	// ����Ƿ�ƽ��
	int totalMoves = row * col;
	int movesPlayed = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (board[i][j] != ' ') {
				movesPlayed++;
			}
		}
	}
	if (movesPlayed == totalMoves) {
		return 'Q'; // ƽ��
	}

	return 'C'; // ����
}
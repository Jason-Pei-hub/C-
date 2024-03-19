#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
    printf("****************************************\n");
    printf("*************    1.paly    *************\n");
    printf("*************    0.exit    *************\n");
    printf("****************************************\n");
}

void game()
{
    //�洢���� ���� ��ά����
    char board[ROW][COL];
    //��ʼ�����̣��������ڶ���Ϊ�ո�
    InitBoard(board, ROW, COL);
    //��ӡ����
    DisplayBoard(board, ROW, COL);

    char ret = 0;//������Ϸ״̬

    while (1)
    {
        //�������
        PlayMove(board, ROW, COL); 
        system("cls");
        DisplayBoard(board, ROW, COL);
        
        //�ж��Ƿ�Ӯ����Ϸ
        ret = IsWin(board, ROW, COL);
        if (ret != 'C')
            break;

        //��������
        ComputerMove(board, ROW, COL);
        system("cls");
        DisplayBoard(board, ROW, COL);

        //�ж��Ƿ�Ӯ����Ϸ
        ret = IsWin(board, ROW, COL);
        if (ret != 'C')
            break;
    }


    if (ret == 'X')
    {
        system("cls");
        printf("****************************************\n");
        printf("************    ��һ�ʤ    ************\n");
        printf("****************************************\n");
        system("cls");
        DisplayBoard(board, ROW, COL);
        // ������뻺����
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        printf("��������ر�...\n");
        getchar(); // �ȴ��û����������ַ�
    }
    else if (ret == 'O')
    {
        system("cls");
        printf("****************************************\n");
        printf("************    ���Ի�ʤ    ************\n");
        printf("****************************************\n");
        
        DisplayBoard(board, ROW, COL);
        // ������뻺����
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        printf("��������ر�...\n");
        getchar(); // �ȴ��û����������ַ�;
    }
    else
    {
        system("cls");
        printf("****************************************\n");
        printf("************      ƽ��      ************\n");
        printf("****************************************\n");
        // ������뻺����
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        printf("��������ر�...\n");
        getchar(); // �ȴ��û����������ַ�
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    int input = 0;
    do
    {
        system("cls");
        menu();//���ȴ�ӡ�˵�
        printf("��ѡ��->");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            system("cls");
            game();
            break;
        case 0:
            printf("�˳���Ϸ\n");
            exit(1);
            break;
        default:
            printf("ѡ���������ѡ��\n");
            break;
        }
    } while (input);
}
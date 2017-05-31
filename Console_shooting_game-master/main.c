/* 20700486 �̼���
   Term-Project: STRIKERS 1945
   Visual C++ */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // for getch

#include "Console.h"

// Global Variables Declaration
char selection=0; // �޴� ���� ����
char first_name[3];
char second_name[3];
char third_name[3]; // ��ŷ�� 1, 2, 3���� �̸�
int first_score;
int second_score;
int third_score; // ��ŷ�� 1, 2, 3���� ����

// Functions Declaration
int StartMenu(char selection); // ���� �޴�
void ViewRanking();
int GamePlay();
void HelpScreen();
void ExitGame();
void DrawBoundary();
void DrawLogo();
void CountRanking(); // ��ŷ�� ���Ϸκ��� �ҷ����� ���� ����

// main function
int main()
{
	CountRanking();
	while(1){
		selection=StartMenu(selection);
		switch(selection){
		case '1': // ���� ����
			GamePlay();
			return 0;
		case '2': // Ranking Ȯ��
			ViewRanking();
			break;
		case '3': // ����
			HelpScreen();
			break;
		case '4': // ���� ����
			ExitGame();
			system("PAUSE");
			return 0;
			break;
		} // switch
	} // while
	return 0;
}

/* ���Ϸκ��� ��ŷ �����͸� �ҷ����� */
void CountRanking()
{
	int i = 0;					// �ݺ��� ������ ���� ����

	FILE *rank = NULL;			// FILE�� ����Ʈ ������ rank ����

	while (i == 0) {

		rank = fopen("1945rk.dat", "r");		// �б� ���� ��Ʈ���� ����

		if (rank != NULL)			// ������ rank���� �ּ� ���� ��ȯ �� ��� => ���� ����
			i = 1;

		else if (rank == NULL) {	// NULL�� ��ȯ �� ��� => ���� ���� X

			clrscr();			// ȭ�� �����
			DrawBoundary();		// ȭ�鿡 �ܰ��� �׸���
			DrawLogo();			// ȭ�鿡 �ΰ� �׸���

			gotoxy(5, 5);
			printf("Error to open file!\n");
			gotoxy(5, 6);
			printf("File open error! ��ŷ������ ���� �ۼ��մϴ�.");
			gotoxy(5, 7);
			system("PAUSE");

			rank = fopen("1945rk.dat", "w");	// ������ �����Ͽ� ���� ���� ��Ʈ���� ����
			fprintf(rank, "COa 500 ");		// ���ڿ��� ù ��° ����(rank)�� ����Ű�� ���Ͽ� ���� ��
			fprintf(rank, "COb 200 ");
			fprintf(rank, "COc 100 ");

			fclose(rank);		// ��Ʈ���� ����
		}
	}

	// ����� �����͸� ������ ���� �����Ͽ� �о� ���̱�
	fscanf(rank, "%s", first_name);
	fscanf(rank, "%d", &first_score);
	fscanf(rank, "%s", second_name);
	fscanf(rank, "%d", &second_score);
	fscanf(rank, "%s", third_name);
	fscanf(rank, "%d", &third_score);

	fclose(rank);
}

int StartMenu(char selection) // Menu
{
	do{
		clrscr();
		DrawBoundary();
		DrawLogo();
		gotoxy(10,5);
		printf("1. ���� ����");
		gotoxy(10,8);
		printf("2. Ranking Ȯ��");
		gotoxy(10,11);
		printf("3. ����");
		gotoxy(10,14);
		printf("4. ���� ����");
		gotoxy(10,20);
		printf(" ��ȣ �Է�: ");
		selection=getch();
		if(selection!='1'&&selection!='2'&&selection!='3'&&selection!='4'){
			printf("#    �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��ϼ���.\n");
			printf("#    ");
			system("PAUSE");
		} // if
	} while(selection!='1'&&selection!='2'&&selection!='3'&&selection!='4'); // while
	return selection;
}
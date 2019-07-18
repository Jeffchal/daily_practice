#include <iostream>
#include <cstdlib>
#include "chessboard.h"

using namespace std;

//���캯��
ChessBoard::ChessBoard()
{
	for (int i = 1; i <= ROW - 2; i += 2) {     //�����̸��з��롮-��.
		for (int j = 1; j <= COL - 2; j += 2) {
			cSquare[i][j] = ' ';
			cSquare[i][j + 1] = '|';
			cSquare[i + 1][j] = '-';
			cSquare[i + 1][j + 1] = '-';
		}
	}
	//Χ�����̵�����
	for (int j = 0; j < COL; j++)
		cSquare[0][j] = cSquare[ROW - 1][j] = '-';
	for (int i = 0; i < ROW; i++)
		cSquare[i][0] = cSquare[i][COL - 1] = '|';

	//�մ��������ӿռ�
	cSquare[ROW][0] = ' ';
	cSquare[0][COL] = ' ';
	//��������д�ӡ���С����±�0��1,2 ... A��B��C ...
	for (int i = 1; i < 20; i += 2) {
		cSquare[i][COL] = i / 2 + 48;
		cSquare[i + 1][COL] = ' ';
		cSquare[ROW][i] = i / 2 + 48;
		cSquare[ROW][i + 1] = ' ';
	}
	for (int j = 21; j < COL; j += 2) {
		cSquare[ROW][j] = j / 2 + 55;
		cSquare[ROW][j + 1] = ' ';
	}
	for (int j = 21; j < ROW; j += 2) {
		cSquare[j][COL] = j / 2 + 55;
		cSquare[j + 1][COL] = ' ';
	}
}
void ChessBoard::show()
{
	system("clear");       //�������������
	//��ʾ����
	for (int i = 0; i <= ROW; ++i) {
		for (int j = 0; j <= COL; ++j)
			cout << cSquare[i][j] << ' ';
		cout << endl;
	}
}

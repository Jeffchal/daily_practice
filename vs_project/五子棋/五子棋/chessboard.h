#pragma once
#ifndef _CHESSBOARD_H_
#define _CHESSBOARD_H_

#include <iostream>

using namespace std;

class ChessBoard    //����
{
public:
	enum { ROW = 31, COL = 31 };    //����������ռ������������
	char cSquare[ROW + 1][COL + 1];      //����һ���ַ����飬������ӡ����
public:
	ChessBoard();                //���̹��캯��
	void show();                 //���̵���ʾ
	~ChessBoard() {}              //��������
};
#endif


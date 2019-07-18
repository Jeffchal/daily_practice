#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <iostream>
#include <string>
#include "chessboard.h"

using namespace std;

class Player
{
private:
	string m_name;
	char m_ChessType;
	int m_x;
	int m_y;
	ChessBoard * m_ptBoard;
public:
	enum { ROW = 31, COL = 31 };
	Player() :m_name("no_name"), m_ChessType('?'), m_x(0), m_y(0), m_ptBoard(NULL) {}
	void attachToBoard(ChessBoard* ptBoard) { m_ptBoard = ptBoard; }
	bool isInChessBoard(int x, int y) const;  //�����Ƿ�����������
	bool HisLine(int x, int y) const;   //�ж�ˮƽ�����Ƿ�����5������
	bool VisLine(int x, int y) const;   //�ж���ֱ�����Ƿ�����5������
	bool LtoBottomisLine(int x, int y) const;  //�ж������Ͻǵ����½��Ƿ�����5������
	bool LtoTopisLine(int x, int y) const;     //�ж������Ͻǵ����½��Ƿ�����5������
	bool isWin() const;                //�Ƿ�Ӯ
	string WinName() const { return m_name; }     //Ӯ������
	void SetInfo(int no);
	void SetChess();              //�������ѡ�ķ��ŷŽ���ѡΪֵ
	~Player() {}
};

#endif

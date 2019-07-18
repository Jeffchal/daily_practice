#include <iostream>
#include <cstdlib>
#include "player.h"

using namespace std;

bool Player::isInChessBoard(int x, int y) const
{
	if (x < ROW - 1 && x > 0 && y < COL - 1 && y > 0)
		return true;
	else
		return false;
}

void Player::SetInfo(int no)
{
	cout << "Please No." << no << " input your name(q to quit): \n";
	getline(cin, m_name);
	if ("q" == m_name) {
		cout << "Bye Bye!" << endl;
		exit(-1);
	}
	//������������д�����������־�ͻ���ȥ�����������û�����
	while (!cin) {
		cin.clear();
		cin.ignore(2048, '\n');  //1024�������������
		cout << "Please No." << no << " input your name agin(q to quit): " << endl;
		getline(cin, m_name);
		if ("q" == m_name) { cout << "Bye Bye!" << endl; exit(-1); }
	}
	cout << "Hello! " << this->m_name << ": Please Choose Your Chess Type '*' or '#': " << endl;
	cin >> m_ChessType;
	cin.get();
	//����û�����q�����˳�����
	if ('q' == m_ChessType) { cout << "Bye Bye" << endl; exit(-1); }
	//��������������󣬻����û�����������Ų�����Ԥ�����*��#����Ҫ���û���������
	while (!cin || (m_ChessType != '*' && m_ChessType != '#')) {
		cin.clear();
		cin.sync();
		cout << "Hello! " << this->m_name << ": Please Choose YOur Chess Type '*' or '#'(q to quit): \n";
		cin >> m_ChessType;
		cin.get();
		if ('q' == m_ChessType) { cout << "Bye Bye!" << endl; exit(-1); }
	}
}

//��ʾ�û��������ӵ����꣬���ж��Ƿ������������ϣ����ѵ�ǰ���ѡ�������ͼ���ַ���������ǰ���������
void Player::SetChess()
{
	char x;
	char y;

	cout << this->m_name << ": Please input Position (x, y) of your Chess. (-, -) to quit" << endl;
	cin >> x >> y;
	if ('-' == x && '-' == y) {
		cout << "Bye Bye!" << endl;
		exit(-1);
	}
#if 1
	if (x >= '0' && x <= '9') {
		m_x = (int)x - 48;
	}
	else if (isupper(x)) {
		m_x = (int)x - 55;
	}
	else if (islower(x)) {
		x = toupper(x);
		m_x = (int)x - 55;
	}
	if (y >= '0' && y <= '9') {
		m_y = (int)y - 48;
	}
	else if (isupper(y)) {
		m_y = (int)y - 55;
	}
	else if (islower(y)) {
		y = toupper(y);
		m_y = (int)y - 55;
	}
	m_x = m_x + (1 * m_x + 1);
	m_y = m_y + (1 * m_y + 1);
#endif
	//������������д����������������Ѿ�������������
	while (!cin || m_ptBoard->cSquare[m_x][m_y] != ' ') {
		cin.clear();
		cin.ignore(1024, '\n');
		cout << this->m_name << ": Please Input Position (x, y) of Your Chess.(-, -) to quit" << endl;
		cin >> x >> y;
		//����������������С��нǱ��ҳ���Ӧ������λ�ã����������������Ӧ�����ӷ�����䵽��λ�ã������ִ�Сд��
		if ('-' == x && '-' == y) {
			cout << "Bye Bye!" << endl;
			exit(-1);
		}
		if (x >= '0' && x <= '9') {
			m_x = (int)x - 48;
		}
		else if (isupper(x)) {
			m_x = (int)x - 55;
		}
		else if (islower(x)) {
			x = toupper(x);
			m_x = (int)x - 55;
		}
		if (y >= '0' && y <= '9') {
			m_y = (int)y - 48;
		}
		else if (isupper(y)) {
			//cout << "m_y" << m_y << endl;
			m_y = (int)y - 55;
			//cout << "m_y" << m_y << endl;
		}
		else if (islower(y)) {
			y = toupper(y);
			m_y = (int)y - 55;
		}
		m_x = m_x + (1 * m_x + 1);
		m_y = m_y + (1 * m_y + 1);
	}
	//������ǰ����������Ӧ�����̵Ķ�ά���鵥Ԫ��
	if (isInChessBoard(m_x, m_y)) {
		m_ptBoard->cSquare[m_x][m_y] = m_ChessType;
	}
}

//�ж��Ƿ���ˮƽ�������γ�5������
bool Player::HisLine(int x, int y) const
{
	int num = 0;
	for (int i = -8; i <= 8; i += 2) {
		if (isInChessBoard(x, y + i) && m_ptBoard->cSquare[x][y + i] == m_ChessType) {
			num++;
			if (num == 5)
				return true;
		}
		else
			num = 0;
	}
	return false;
}

//�ж��Ƿ��ڴ�ֱ����������5������
bool Player::VisLine(int x, int y) const
{
	int num = 0;
	for (int i = -8; i <= 8; i += 2) {
		//�����ǰ����ͳһ�е����������������ϣ������������ͼ���͵�ǰ��ҵ�����ͼ����ͬ���������׼�
		if (isInChessBoard(x + i, y) && m_ptBoard->cSquare[x + i][y] == m_ChessType) {
			num++;
			//����ͬһ����5��������ͼ����ͬʱ������Ӯ�������
			if (num == 5)
				return true;
		}
		else
			num = 0;
	}
	return false;
}

//�ж��Ƿ��������Ͻǵ����½ǵķ���������5������
bool Player::LtoBottomisLine(int x, int y) const
{
	int num = 0;
	for (int i = -8; i <= 8; i += 2) {
		//�����ǰ�����������Ͻǵ����½ǵĶԽ��߷��������
		if (isInChessBoard(x + i, y + i) && m_ptBoard->cSquare[x + i][y + i] == m_ChessType) {
			num++;
			if (num == 5)
				return true;
		}
		else
			num = 0;
	}
	return false;
}

//�ж��Ƿ��������½ǵ����Ͻǵķ���������5������
bool Player::LtoTopisLine(int x, int y) const
{
	int num = 0;
	for (int i = -8; i <= 8; i += 2) {
		if (isInChessBoard(x - i, y + i) && m_ptBoard->cSquare[x - i][y + i] == m_ChessType) {
			num++;
			if (num == 5)
				return true;
		}
		else
			num = 0;
	}
	return false;
}

bool Player::isWin()const
{
	return (HisLine(m_x, m_y) || VisLine(m_x, m_y) || LtoBottomisLine(m_x, m_y) || LtoTopisLine(m_x, m_y)) ? true : false;
}

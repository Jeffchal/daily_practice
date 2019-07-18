#include <iostream>
#include "player.h"
#include "chessboard.h"

using namespace std;

int main()
{
	ChessBoard board;
	Player playerA;
	playerA.SetInfo(1);
	playerA.attachToBoard(&board);
	Player playerB;
	playerB.SetInfo(2);
	playerB.attachToBoard(&board);
	board.show();
	while (1) {
		//���1����һ������
		playerA.SetChess();
		if (playerA.isWin()) {
			//board.show();
			cout << playerA.WinName() << " Winner! Game Over!!\n";
			break;
		}
		//��ʾ��ǰ�������������ӵ�λ�á�
		board.show();

		//���2����һ������
		playerB.SetChess();
		if (playerB.isWin()) {
			cout << playerB.WinName() << " Winner! Game Over!!\n";
			break;
		}
		board.show();
	}
	//���г���
	return 1;
}

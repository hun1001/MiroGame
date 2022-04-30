#include "console.h"
#include "Board.h"

int main()
{
	Board board(25);
	char buffer;
	
	fullscreen();
	hideCursor();

	board.RenderBoard();
	while (!board.GetIsGameEnd())
	{
		gotoxy(0, 0);
		buffer = _getch();
		board.InputCommend(buffer);
		board.RenderBoard();
	}
	
	system("cls");
	cout << "°ñÀÎ";
	
	return 0;
}

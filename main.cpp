#include "console.h"
#include "Board.h"

int main()
{
	Board board(25);
	char buffer;
	
	fullscreen();
	hideCursor();

	while (true)
	{
		gotoxy(0, 0);
		board.RenderBoard();
		buffer = _getch();
		board.InputCommend(buffer);
	}
	
	return 0;
}

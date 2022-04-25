#include "console.h"
#include "Board.h"


int main()
{
	using namespace std;
	using namespace MiroInitAlgorithm;
	
	hideCursor();
	
	Board board;
	board.Initialize(25);
	board.GenerateByBinaryTree();
	
	while (true)
	{
		gotoxy(0, 0);
		board.RenderBoard();
		char input = _getch();
		board.PlayerMoveInput(input);
	}
	
	return 0;
}
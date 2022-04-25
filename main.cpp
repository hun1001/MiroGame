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
	
	while (!board._isGoal)
	{
		gotoxy(0, 0);
		board.RenderBoard();
		char input = _getch();
		board.PlayerMoveInput(input);
	}
	
	system("cls");
	cout << "게임 클리어" << endl;
	
	return 0;
}
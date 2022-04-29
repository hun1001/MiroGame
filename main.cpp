#include "console.h"
#include "Board.h"


int main()
{
	using namespace std;
	using namespace MiroInitAlgorithm;
	
	int mapSize(31);
	
	hideCursor();
	
	Board board;
	board.Initialize(mapSize);
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
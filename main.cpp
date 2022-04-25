#include "console.h"
#include "Board.h"


int main()
{
	using namespace std;
	using namespace MiroInitAlgorithm;
	
	Board board;
	board.Initialize(25);
	board.GenerateByBinaryTree();

	int playerPosX(1), playerPosY(1);

	while (true)
	{
		system("cls");
		board.RenderBoard();
		char input = _getch();
		
	}
	
	return 0;
}
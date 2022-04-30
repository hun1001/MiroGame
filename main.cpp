#include "console.h"
#include "Board.h"
#include "Timer.h"

using namespace std;

void PrtMazeText();

int main()
{
	
	
	int mapSize(31);
	
	hideCursor();
	
	Board board;
	Timer timer;
	
	board.GetMaze().Initialize(mapSize);
	board.GetMaze().GenerateByBinaryTree();
	 
	PrtMazeText();

	system("pause");
	system("cls");
	timer.Start();
	while (/*!board._isGoal*/true)
	{
		gotoxy(0, 0);
		board.RenderBoard();
		char input = _getch();
		if (board.InputIdentify(input))
		{
			board.PlayerMoveInput(input);
		}
	}
	timer.Stop();
	system("cls");
	cout << "게임 클리어" << endl;
	cout << "걸린 시간 : " << timer.GetInterval() << "초" << endl;
	return 0;
}

void PrtMazeText()
{
	int oldMode = _setmode(_fileno(stdout), _O_U8TEXT);
	wcout << L"███╗   ███╗ █████╗ ███████╗███████╗     ██████╗  █████╗ ███╗   ███╗███████╗" << endl;
	wcout << L"████╗ ████║██╔══██╗╚══███╔╝██╔════╝    ██╔════╝ ██╔══██╗████╗ ████║██╔════╝" << endl;
	wcout << L"██╔████╔██║███████║  ███╔╝ █████╗      ██║  ███╗███████║██╔████╔██║█████╗  " << endl;
	wcout << L"██║╚██╔╝██║██╔══██║ ███╔╝  ██╔══╝      ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  " << endl;
	wcout << L"██║ ╚═╝ ██║██║  ██║███████╗███████╗    ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗" << endl;
	wcout << L"╚═╝     ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝     ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝" << endl;
	oldMode = _setmode(_fileno(stdout), oldMode);
}
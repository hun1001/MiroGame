#include "console.h"
#include "Board.h"
#include "Timer.h"

int main()
{
	Board board(25);
	char buffer;
	Timer* timer;
	long long time = 0;
	
	fullscreen();
	hideCursor();

	int outMode = _setmode(_fileno(stdout), _O_U8TEXT);
	wcout << L" ▄▄▄▄███▄▄▄▄      ▄████████  ▄███████▄     ▄████████         ▄██████▄     ▄████████   ▄▄▄▄███▄▄▄▄      ▄████████	" << endl;
	wcout << L"▄██▀▀▀███▀▀▀██▄   ███    ███ ██▀     ▄██   ███    ███        ███    ███   ███    ███ ▄██▀▀▀███▀▀▀██▄   ███    ███" << endl;
	wcout << L"███   ███   ███   ███    ███       ▄███▀   ███    █▀         ███    █▀    ███    ███ ███   ███   ███   ███    █▀	" << endl;
	wcout << L"███   ███   ███   ███    ███  ▀█▀▄███▀▄▄  ▄███▄▄▄           ▄███          ███    ███ ███   ███   ███  ▄███▄▄▄	" << endl;
	wcout << L"███   ███   ███ ▀███████████   ▄███▀   ▀ ▀▀███▀▀▀          ▀▀███ ████▄  ▀███████████ ███   ███   ███ ▀▀███▀▀▀	" << endl;
	wcout << L"███   ███   ███   ███    ███ ▄███▀         ███    █▄         ███    ███   ███    ███ ███   ███   ███   ███    █▄	" << endl;
	wcout << L"███   ███   ███   ███    ███ ███▄     ▄█   ███    ███        ███    ███   ███    ███ ███   ███   ███   ███    ███" << endl;
	wcout << L"▀█    ███   █▀    ███    █▀   ▀████████▀   ██████████        ████████▀    ███    █▀   ▀█   ███   █▀    ██████████" << endl;
	outMode = _setmode(_fileno(stdout), outMode);

	system("pause");
	system("cls");
	
	timer = new Timer(&time);
	board.RenderBoard();
	while (!board.GetIsGameEnd())
	{
		gotoxy(0, 0);
		buffer = _getch();
		board.InputCommend(buffer);
		board.RenderBoard();
	}
	delete(timer);
	system("cls");
	cout << "골인" << endl;
	cout << "시간: " << time << "초" << endl;
	return 0;
}

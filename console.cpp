#include "console.h"

void gotoxy(int x, int y)
{
	HANDLE hout;
	COORD Cur;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(hout, Cur);
}

void setcolor(int color, int bgcolor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

void fullscreen()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, NULL);
}

void hideCursor()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

// get cursor position
int wherex(void)
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	return info.dwCursorPosition.X;
}

/*
	HWND console = GetConsoleWindow();
	SetWindowLong(console, GWL_STYLE, GetWinsowLong(console, GWL_STYLE) & WS_MAXMIZEBOX & WS_SIZEBOX)
	대충 이거 쓰면 못건들임 콘솔창의 크기를 변경하는 것을
	---------------------------------------------------------------------------------------------------
	RECT rect;
	GetWindowRect(console, &rect);
	while(true)
	{
		BOOL result = gotoxy(x,y);
		if(result == FALSE)
			continue;
		그냥 이거 벗어났을때 이동하는 코드 작동 시키지 않는 것
	}
*/
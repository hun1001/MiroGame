#pragma once
#include <iostream>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <io.h>
#include <fcntl.h>
#include <mmsystem.h>
#include <random>

void gotoxy(int x, int y);
void setcolor(int color, int bgcolor);
void fullscreen();
void hideCursor();
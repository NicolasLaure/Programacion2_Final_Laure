#include "Utils.h"

void Print(string text)
{
	cout << text;
}

void PrintError(string text)
{
	cerr << endl << text << endl;
}

void SetCursorPos(COORD pos)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, pos);
}

void ClearLine(int lineNum)
{
	SetCursorPos({ 0,(short)lineNum });
	cout << "                                        ";
}

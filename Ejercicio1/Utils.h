#pragma once
#include <iostream>
#include <Windows.h>
#include <Conio.h>
#include <string>

using namespace std; 

void Print(string text);
void PrintError(string text);
void SetCursorPos(COORD pos);
void ClearLine(int lineNum);
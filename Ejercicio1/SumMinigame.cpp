#include "SumMinigame.h"
#include "Utils.h"

using namespace std;

void SumMinigame::Start()
{
	Print("Enter SumMinigame");
}
void SumMinigame::Update()
{
	system("cls");
	Print("Update SumMinigame");
	if (_kbhit() && _getch() == 27)
		nextScene = Scenes::MENU;
}

void SumMinigame::End()
{
	Print("Exit SumMinigame");
}
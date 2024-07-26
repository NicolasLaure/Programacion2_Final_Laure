#include "SumMinigame.h"
#include "Utils.h"

using namespace std;

void SumMinigame::Start()
{
	system("cls");
	Print("Sum Minigame: Mentally Sum the numbers");
	srand(time(nullptr));
	numIndex = 0;
	result = 0;
}
void SumMinigame::Update()
{
	if (_kbhit() && _getch() == 27)
	{
		nextScene = Scenes::MENU;
		return;
	}

	if (!AllNumsPrinted())
	{
		PrintNumber();
	}
	else
	{
		ClearLine(2);
		SetCursorPos({ 0,2 });
		cout << "Enter The Result: ";
		cin >> playerInput;
		if (playerInput == result)
			cout << "Congratulations, You Win\n";
		else
			cout << "Wrong Result, You Lose\n";

		system("pause");
		nextScene = Scenes::MENU;
		return;
	}
}

void SumMinigame::End()
{
	Print("Exit SumMinigame");
}

bool SumMinigame::AllNumsPrinted()
{
	return numIndex >= numsQty;
}

void SumMinigame::PrintNumber()
{
	int randomNum = rand() % 201 - 100;
	result += randomNum;
	ClearLine(2);
	SetCursorPos({ 0,2 });
	cout << randomNum;
	Sleep(sleepDuration);
	numIndex++;
}
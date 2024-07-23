#include "MenuScene.h"
#include "Utils.h"

MenuScene::MenuScene()
{
	actualScene = Scenes::MENU;
}

void MenuScene::Start()
{
	system("cls");
	Print("1. Sum Game\n2. Multiple Choice\n3. Find by Define\n0. Quit");
}

void MenuScene::Update()
{
	if (_kbhit())
	{
		char response = _getch();

		switch (response)
		{
		case '1':
			nextScene = Scenes::SUM_MINIGAME;
			break;
		case '2':
			nextScene = Scenes::SUM_MINIGAME;
			break;
		case '3':
			nextScene = Scenes::SUM_MINIGAME;
			break;
		case '0':
			nextScene = Scenes::EXIT;
			break;
		default:
			break;
		}
	}
}

void MenuScene::End()
{

}
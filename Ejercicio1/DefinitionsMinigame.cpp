#include "DefinitionsMinigame.h"

void DefinitionsMinigame::Start()
{
	system("cls");
	Print("Find By Define\n");
	Print("Write Words with First Letter Uppercase\n");
	system("pause");
	currentWord = "Pato";
	currentDefinition = "Animal que nada y vuela, posee pico amarillo";

	correctAnswers = 0;
	displayedDefinitions = 0;
}

void DefinitionsMinigame::Update()
{
	if (displayedDefinitions < DefinitionsQty)
	{
		system("cls");
		string response = "";
		Print(currentDefinition + ": ");
		cin >> response;

		if (response == currentWord)
			correctAnswers++;

		displayedDefinitions++;
	}
	else
	{
		Print("Find By Define game completed\n");
		Print("Correct Answers: " + std::to_string(correctAnswers) + "/" + std::to_string(displayedDefinitions) + "\n");

		system("pause");
		nextScene = Scenes::MENU;
		return;
	}
}

void DefinitionsMinigame::End()
{
}

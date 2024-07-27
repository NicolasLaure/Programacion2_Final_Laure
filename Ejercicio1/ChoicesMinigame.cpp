#include "ChoicesMinigame.h"
#include "Utils.h"

void ChoicesMinigame::Start()
{
	vector<MultipleChoiceAnswer> answers;
	answers.push_back(MultipleChoiceAnswer("Messi", true));
	answers.push_back(MultipleChoiceAnswer("Cr7", false));
	answers.push_back(MultipleChoiceAnswer("Mbappe", false));
	answers.push_back(MultipleChoiceAnswer("Pele", false));

	questions.push_back(MultipleChoiceQuestion("Who's the goat?", answers));
	currentQuestion = 0;
	correctAnswers = 0;
}

void ChoicesMinigame::Update()
{
	if (_kbhit() && _getch() == 27)
	{
		nextScene = Scenes::MENU;
		return;
	}
	system("cls");
	if (currentQuestion < questions.size())
	{
		questions[currentQuestion].PrintQuestion();
		if (questions[currentQuestion].QuestionResponse())
			correctAnswers++;

		currentQuestion++;
	}
	else
	{
		Print("All questions Answered\n");
		Print("Correct Answers" + to_string(correctAnswers) + "/" + to_string(currentQuestion) + "\n");

		system("pause");
		nextScene = Scenes::MENU;
		return;
	}
}

void ChoicesMinigame::End()
{
}

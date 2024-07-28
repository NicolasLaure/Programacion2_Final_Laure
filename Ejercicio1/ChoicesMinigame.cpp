#include "ChoicesMinigame.h"
#include "Utils.h"
#include "FileReader.h"

void ChoicesMinigame::Start()
{
	FileReader reader;
	questions.push_back(reader.ReadQuestionFile("Fut.question"));
	questions.push_back(reader.ReadQuestionFile("Chemistry.question"));
	questions.push_back(reader.ReadQuestionFile("History.question"));
	currentQuestion = 0;
	correctAnswers = 0;
}

void ChoicesMinigame::Update()
{
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

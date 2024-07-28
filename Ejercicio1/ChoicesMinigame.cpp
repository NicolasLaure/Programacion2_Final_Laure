#include "ChoicesMinigame.h"
#include "Utils.h"
#include "FileReader.h"
#include "CorruptedFileException.h"

void ChoicesMinigame::Start()
{
	FileReader reader;
	try
	{
		questions.push_back(reader.ReadQuestionFile("Fut1.question"));
		questions.push_back(reader.ReadQuestionFile("Chemistry.question"));
		questions.push_back(reader.ReadQuestionFile("History.question"));
	}
	catch (const CorruptedFileException& e)
	{
		PrintError(e.what());
		system("pause");
	}


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

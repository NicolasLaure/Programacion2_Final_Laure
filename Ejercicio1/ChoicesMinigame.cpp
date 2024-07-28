#include "ChoicesMinigame.h"
#include "Utils.h"
#include "FileReader.h"
#include "CorruptedFileException.h"

void ChoicesMinigame::Start()
{
	paths.push_back("Fut.question");
	paths.push_back("Chemistry.question");
	paths.push_back("History.question");

	FileReader reader;
	for (int i = 0; i < paths.size(); i++)
	{
		try
		{
			questions.push_back(reader.ReadQuestionFile(paths[i]));
		}
		catch (const CorruptedFileException& e)
		{
			PrintError("Question " + to_string(i + 1) + " " + (string)e.what());
			system("pause");
		}
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

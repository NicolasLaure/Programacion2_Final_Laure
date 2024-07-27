#include "MultipleChoiceQuestion.h"
#include "Utils.h"

MultipleChoiceQuestion::MultipleChoiceQuestion()
{
	question = "";
	answers = std::vector<MultipleChoiceAnswer>();
}

MultipleChoiceQuestion::MultipleChoiceQuestion(std::string question, std::vector<MultipleChoiceAnswer> answers)
{
	this->question = question;
	this->answers = answers;
}

void MultipleChoiceQuestion::PrintQuestion()
{
	Print(question + "\n");
	for (int i = 0; i < answers.size(); i++)
	{
		Print(to_string(i + 1) + ": " + answers[i].text + "\n");
	}
	Print("Enter Response: ");
}

bool MultipleChoiceQuestion::QuestionResponse()
{
	int response = 0;
	cin >> response;
	return answers[response - 1].isTrue;
}

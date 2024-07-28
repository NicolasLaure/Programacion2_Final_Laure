#pragma once
#include <vector>
#include "MultipleChoiceAnswer.h"

class MultipleChoiceQuestion
{
private:

public:
	std::string question;
	std::vector<MultipleChoiceAnswer> answers;

	MultipleChoiceQuestion();
	MultipleChoiceQuestion(std::string question, std::vector<MultipleChoiceAnswer> answers);
	void PrintQuestion();
	bool QuestionResponse();
};


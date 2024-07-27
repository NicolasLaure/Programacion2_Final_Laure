#pragma once
#include <vector>
#include "MultipleChoiceAnswer.h"

class MultipleChoiceQuestion
{
private:
	std::string question;
	std::vector<MultipleChoiceAnswer> answers;

public:
	MultipleChoiceQuestion();
	MultipleChoiceQuestion(std::string question, std::vector<MultipleChoiceAnswer> answers);
	void PrintQuestion();
	bool QuestionResponse();
};


#pragma once
#include <string>
#include "MultipleChoiceQuestion.h"

class FileReader
{
public:
	MultipleChoiceQuestion ReadQuestionFile(std::string fileName);
};


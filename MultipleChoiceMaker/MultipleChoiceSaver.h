#pragma once
#include "MultipleChoiceQuestion.h"
#include <string>
#include <vector>
using namespace std;

class MultipleChoiceSaver
{
public:
	void SaveQuestion(string fileName, MultipleChoiceQuestion* question);
	MultipleChoiceQuestion ReadQuestion(string fileName);
};


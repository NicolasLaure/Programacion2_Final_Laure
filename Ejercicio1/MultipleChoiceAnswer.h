#pragma once
#include <string>
class MultipleChoiceAnswer
{
public:
	std::string text = "";
	bool isTrue = false;
	MultipleChoiceAnswer(std::string text, bool isTrue);
};


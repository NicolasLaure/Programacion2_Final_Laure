#include "MultipleChoiceSaver.h"
#include <fstream>
#include <iostream>


void MultipleChoiceSaver::SaveQuestion(string fileName, MultipleChoiceQuestion* question)
{
	ofstream outputStream;
	outputStream.open(fileName, ios::out | ios::binary | ios::trunc);

	outputStream.write((char*)question, sizeof(MultipleChoiceQuestion));
	outputStream.close();
}

void MultipleChoiceSaver::ReadQuestion(string fileName)
{
	ifstream inputStream;
	inputStream.open(fileName, ios::in | ios::binary);
	if (!inputStream.is_open() || inputStream.fail())
		return;

	MultipleChoiceQuestion* readQuestion = new MultipleChoiceQuestion();
	inputStream.read((char*)readQuestion, sizeof(MultipleChoiceQuestion));
	inputStream.close();

	readQuestion->PrintQuestion();

	delete readQuestion;
}

#include "MultipleChoiceSaver.h"
#include <fstream>
#include <iostream>


void MultipleChoiceSaver::SaveQuestion(string fileName, MultipleChoiceQuestion* question)
{
	ofstream outputStream;
	outputStream.open(fileName, ios::out | ios::binary | ios::trunc);

	//outputStream.write((char*)question->question.c_str(), sizeof(question->question));

	char cursor = ' ';
	int index = 0;
	while (cursor != '\0')
	{
		cursor = question->question[index];
		outputStream.write((char*)&cursor, sizeof(char));
		index++;
	}

	int vectorLength = question->answers.size();
	outputStream.write((char*)&vectorLength, sizeof(int));
	for (int i = 0; i < vectorLength; i++)
	{
		cursor = ' ';
		index = 0;
		while (cursor != '\0')
		{
			cursor = question->answers[i].text[index];
			outputStream.write((char*)&cursor, sizeof(char));
			index++;
		}

		outputStream.write((char*)&question->answers[i].isTrue, sizeof(bool));
	}
	outputStream.close();
}

MultipleChoiceQuestion MultipleChoiceSaver::ReadQuestion(string fileName)
{
	ifstream inputStream;
	inputStream.open(fileName, ios::in | ios::binary);
	if (!inputStream.is_open() || inputStream.fail())
		return MultipleChoiceQuestion();

	/*MultipleChoiceQuestion* readQuestion = new MultipleChoiceQuestion();
	inputStream.read((char*)readQuestion, sizeof(MultipleChoiceQuestion));
	inputStream.close();*/

	char cursor = ' ';
	string readQuestion = "";
	while (cursor != '\0')
	{
		inputStream.read((char*)&cursor, sizeof(char));
		readQuestion += cursor;
	}
	readQuestion += cursor;

	vector<MultipleChoiceAnswer> answers;
	int answersQty = 0;
	inputStream.read((char*)&answersQty, sizeof(int));

	for (int i = 0; i < answersQty; i++)
	{
		cursor = ' ';
		string readAnswer = "";
		while (cursor != '\0')
		{
			inputStream.read((char*)&cursor, sizeof(char));
			readAnswer += cursor;
		}
		bool isTrue = false;
		inputStream.read((char*)&isTrue, sizeof(bool));
		answers.push_back(MultipleChoiceAnswer(readAnswer, isTrue));
	}

	MultipleChoiceQuestion auxQuestion = MultipleChoiceQuestion(readQuestion, answers);
	return auxQuestion;
}

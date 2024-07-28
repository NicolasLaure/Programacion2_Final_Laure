#include "FileReader.h"
#include <fstream>
#include "Utils.h"
#include "FileOpeningException.h"

using namespace std;
MultipleChoiceQuestion FileReader::ReadQuestionFile(std::string fileName)
{
	try
	{
		ifstream inputStream;
		inputStream.open(fileName, ios::in | ios::binary);
		if (!inputStream.is_open() || inputStream.fail())
			throw FileOpeningException();

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
	catch (const ifstream::failure& e)
	{
		PrintError(e.what());
	}
	catch (const FileOpeningException& fileOpeningException)
	{
		PrintError(fileOpeningException.what());
		system("pause");
		exit(0);
	}
}

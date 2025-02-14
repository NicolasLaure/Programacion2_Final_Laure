#include "MultipleChoiceSaver.h"

void main()
{
	MultipleChoiceSaver saver = MultipleChoiceSaver();
	MultipleChoiceQuestion* question1 = new MultipleChoiceQuestion("Who's the greatest football player of all times?",
		{ MultipleChoiceAnswer("Messi", true),
		  MultipleChoiceAnswer("Pele", false),
		  MultipleChoiceAnswer("Cristiano Ronaldo", false),
		  MultipleChoiceAnswer("Zidane", false), });

	MultipleChoiceQuestion* question2 = new MultipleChoiceQuestion("When did WWII start?",
		{ MultipleChoiceAnswer("1932", false),
		  MultipleChoiceAnswer("1939", true),
		  MultipleChoiceAnswer("1940", false),
		  MultipleChoiceAnswer("1942", false), });

	MultipleChoiceQuestion* question3 = new MultipleChoiceQuestion("What does Au stand for?",
		{ MultipleChoiceAnswer("Automatic", false),
		  MultipleChoiceAnswer("Gold", true),
		  MultipleChoiceAnswer("Austria", false),
		  MultipleChoiceAnswer("Australia", false), });

	saver.SaveQuestion("Fut.question", question1);
	saver.SaveQuestion("History.question", question2);
	saver.SaveQuestion("Chemistry.question", question3);

	vector<MultipleChoiceQuestion> readQuestions = vector<MultipleChoiceQuestion>();
	readQuestions.push_back(saver.ReadQuestion("Fut.question"));
	readQuestions.push_back(saver.ReadQuestion("History.question"));
	readQuestions.push_back(saver.ReadQuestion("Chemistry.question"));

	for (int i = 0; i < readQuestions.size(); i++)
	{
		readQuestions[i].PrintQuestion();
	}
}
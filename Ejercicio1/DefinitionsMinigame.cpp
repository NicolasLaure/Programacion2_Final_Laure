#include "DefinitionsMinigame.h"



void DefinitionsMinigame::Start()
{
	system("cls");
	Print("Find By Define\n");
	Print("Write Words with First Letter LowerCase\n");
	system("pause");
	RequestWords();

	words.clear();
	definitionRequestTasks.clear();
	correctAnswers = 0;
	currentWordIndex = 0;
	printedWords = 0;
}

void DefinitionsMinigame::Update()
{
	if (!AreAllTasksDone())
	{
		LoadingScreen();

		if (wordsRequestTask.is_done() && words.size() == 0)
			SetWords();

		if (words.size() != 0 && definitionRequestTasks.size() == 0)
		{
			for (int i = 0; i < words.size(); i++)
			{
				RequestDefinition(words[i]);
			}
		}
	}
	else
	{
		if (definitions.size() == 0)
		{
			for (int i = 0; i < definitionRequestTasks.size(); i++)
			{
				SetDefinition(i);
			}
		}

		if (currentWordIndex < definitions.size())
		{
			if (definitions[currentWordIndex].size() > 1)
			{
				system("cls");
				string response = "";
				Print(definitions[currentWordIndex] + ": ");
				cin >> response;


				if (response == words[currentWordIndex])
					correctAnswers++;

				printedWords++;
			}
			currentWordIndex++;
		}
		else
		{
			Print("Find By Define game completed\n");
			Print("Correct Answers: " + std::to_string(correctAnswers) + "/" + std::to_string(printedWords) + "\n");

			Print("The Words were:\n");
			for (int i = 0; i < words.size(); i++)
			{
				Print(words[i] + "\n");
			}
			system("pause");
			nextScene = Scenes::MENU;
			return;
		}
	}
}

void DefinitionsMinigame::End()
{
}

void DefinitionsMinigame::RequestWords()
{
	http_client client = http_client(to_string_t(BASE_WORD_API_URL));
	http_request wordsRequest = http_request(methods::GET);
	uri_builder uriBuilder = uri_builder(to_string_t("/word"));

	uriBuilder.append_query(to_string_t("number"), to_string_t(to_string(definitionsQty)));

	utility::string_t url = uriBuilder.to_string();

	wordsRequest.set_request_uri(url);
	wordsRequestTask = client.request(wordsRequest);
}

void DefinitionsMinigame::SetWords()
{
	http_response wordsResponse = wordsRequestTask.get();
	json::array wordsJsonArray = wordsResponse.extract_json().get().as_array();

	for (int i = 0; i < wordsJsonArray.size(); i++)
	{
		words.push_back(to_utf8string(wordsJsonArray[i].as_string()));
	}
}

void DefinitionsMinigame::RequestDefinition(string word)
{
	http_client client = http_client(to_string_t(BASE_DEFINITION_API_URL));
	http_request definitionRequest = http_request(methods::GET);
	uri_builder uriBuilder = uri_builder();
	uriBuilder.append_path(to_string_t(word));

	utility::string_t url = uriBuilder.to_string();

	definitionRequest.set_request_uri(url);
	definitionRequestTasks.push_back(client.request(definitionRequest));
}

void DefinitionsMinigame::SetDefinition(int index)
{
	http_response definitionResponse = definitionRequestTasks[index].get();
	json::value definitionJsonValue = definitionResponse.extract_json().get();

	string definition = "";
	if (definitionJsonValue.size() == 3)
	{
		PrintError("Definition" + to_string(index + 1) + "Was not found\n");
		system("pause");
	}
	else
		definition = to_utf8string(definitionJsonValue[0][to_string_t("meanings")][0][to_string_t("definitions")][0][to_string_t("definition")].as_string());

	definitions.push_back(definition);
}

bool DefinitionsMinigame::AreAllTasksDone()
{
	if (!wordsRequestTask.is_done())
		return false;

	for (int i = 0; i < definitionRequestTasks.size(); i++)
	{
		if (!definitionRequestTasks[i].is_done())
			return false;
	}

	return true;
}

void DefinitionsMinigame::LoadingScreen()
{
	system("cls");
	Print("Loading");
	for (int i = 0; i < loadingStage; i++)
	{
		Print(".");
	}
	loadingStage = loadingStage > 2 ? 0 : loadingStage + 1;
}

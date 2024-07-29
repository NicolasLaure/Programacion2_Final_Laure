#pragma once
#include "Scene.h"
#include "Utils.h"

#include "cpprest/http_client.h"
#include "cpprest/filestream.h"
using namespace web;
using namespace web::http;
using namespace web::http::client;
using namespace utility::conversions;
using namespace Concurrency;

class DefinitionsMinigame : public Scene
{
private:

	const string BASE_WORD_API_URL = "https://random-word-api.herokuapp.com";
	const string BASE_DEFINITION_API_URL = "https://api.dictionaryapi.dev/api/v2/entries/en";
	task<http_response> wordsRequestTask;
	vector<task<http_response>> definitionRequestTasks;

	vector<string> words;
	vector<string> definitions;
	string currentDefinition;
	int correctAnswers;
	int currentWordIndex = 0;
	int printedWords = 0;
	int definitionsQty = 5;

	void RequestWords();
	void SetWords();
	void RequestDefinition(string word);
	void SetDefinition(int index);
	bool AreAllTasksDone();

public:
	virtual void Start() override;
	virtual void Update() override;
	virtual void End() override;
};


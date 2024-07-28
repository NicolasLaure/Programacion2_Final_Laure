#pragma once
#include "Scene.h"
#include "Utils.h"

class DefinitionsMinigame : public Scene
{
private:
	string currentWord;
	string currentDefinition;
	int correctAnswers;
	int displayedDefinitions = 0;
	int DefinitionsQty = 1;
public:
	virtual void Start() override;
	virtual void Update() override;
	virtual void End() override;
};


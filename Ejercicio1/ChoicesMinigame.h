#pragma once
#include "Scene.h"
#include "MultipleChoiceQuestion.h"

class ChoicesMinigame : public Scene
{
private:
	std::vector<MultipleChoiceQuestion> questions;
	int currentQuestion = 0;
	int correctAnswers = 0;
public:
	virtual void Start() override;
	virtual void Update() override;
	virtual void End() override;
};


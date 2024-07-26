#pragma once
#include "Scene.h"

class SumMinigame : public Scene
{
private:
	int numsQty = 5;
	int sleepDuration = 2000;
	int numIndex = 0;
	int result;
	int playerInput;

	bool AllNumsPrinted();
	void PrintNumber();
public:
	virtual void Start() override;
	virtual void Update() override;
	virtual void End() override;
};


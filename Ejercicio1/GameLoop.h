#pragma once
#include "SceneManager.h"

class GameLoop
{
private:
	SceneManager* sceneManager;
	bool ShouldClose();
public:
	void StartLoop();
};
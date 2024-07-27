#include "GameLoop.h"

void GameLoop::StartLoop()
{
	sceneManager = new SceneManager(new MenuScene());
	while (!ShouldClose())
	{
		sceneManager->CurrentSceneFlow();
	}
	delete sceneManager;
}

bool GameLoop::ShouldClose()
{
	if (sceneManager->nextScene == Scenes::EXIT)
		return true;

	return false;
}
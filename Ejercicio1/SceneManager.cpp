#include "SceneManager.h"

SceneManager::SceneManager()
{
}

void SceneManager::CurrentSceneFlow()
{
	currentScene->Update();
	nextScene = currentScene->ShouldChangeScene();
	if (nextScene == Scenes::NONE)
		return;

	switch (nextScene)
	{
	case Scenes::MENU:
		ChangeScene<MenuScene>();
		break;
	case Scenes::SUM_MINIGAME:
		ChangeScene<SumMinigame>();
		break;
	case Scenes::NONE:
		break;
	default:
		break;
	}
}
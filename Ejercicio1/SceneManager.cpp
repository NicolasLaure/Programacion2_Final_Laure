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
		ChangeScene<SumMinigame<float>>();
		break;
	case Scenes::MULTIPLE_CHOICE_MINIGAME:
		ChangeScene<ChoicesMinigame>();
		break;
	case Scenes::FIND_BY_DEFINE_MINIGAME:
		ChangeScene<DefinitionsMinigame>();
		break;
	case Scenes::NONE:
		break;
	default:
		break;
	}
}
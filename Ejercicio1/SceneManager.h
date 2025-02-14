#pragma once
#include "Scene.h"
#include <concepts>
#include "MenuScene.h"
#include "SumMinigame.h"
#include "ChoicesMinigame.h"
#include "DefinitionsMinigame.h"

template <class T>
concept SceneObject = std::derived_from<T, Scene>;

class SceneManager
{
private:
	Scene* currentScene = nullptr;
public:
	Scenes nextScene = Scenes::NONE;

	template<SceneObject T>
	SceneManager(T* initialScene);

	SceneManager();

	template<SceneObject T>
	void ChangeScene();

	void CurrentSceneFlow();

};

#include "SceneManager.tpp"
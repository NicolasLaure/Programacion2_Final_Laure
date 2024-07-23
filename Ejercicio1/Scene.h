#pragma once
#include "ScenesEnum.h"

class Scene
{
public:
	Scenes actualScene;
	Scenes nextScene = Scenes::NONE;

	virtual ~Scene() {}
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void End() = 0;
	Scenes ShouldChangeScene();
};
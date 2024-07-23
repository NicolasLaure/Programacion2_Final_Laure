#pragma once
#include "Scene.h"

class MenuScene : public Scene
{
public:
	MenuScene();
	~MenuScene() {}

	void Start() override;
	void Update() override;
	void End() override;
};
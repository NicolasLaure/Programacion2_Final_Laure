
template<SceneObject T>
SceneManager::SceneManager(T* initialScene)
{
	currentScene = initialScene;
	currentScene->Start();
}

template<SceneObject T>
void SceneManager::ChangeScene()
{
	if (currentScene != nullptr)
	{
		currentScene->End();
		delete currentScene;
	}

	currentScene = new T();
	currentScene->Start();
}
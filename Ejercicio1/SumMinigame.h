#pragma once
#include "Scene.h"
#include "Utils.h"

using namespace std;

template<typename T>
concept NUMBER = integral<T> || floating_point<T>;

template<NUMBER T>
class SumMinigame : public Scene
{
private:
	int numsQty = 5;
	int numMin = -100;
	int numMax = 100;
	int sleepDuration = 4000;
	int numIndex = 0;
	float maxMargin = 0.02f;
	T result;
	T playerInput;

	bool AllNumsPrinted();
	void PrintNumber();
	bool areNumsEqual(T a, T b);
public:
	virtual void Start() override;
	virtual void Update() override;
	virtual void End() override;
};

#include "SumMinigame.tpp"
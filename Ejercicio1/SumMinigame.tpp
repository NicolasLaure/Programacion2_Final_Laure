
template<NUMBER T>
void SumMinigame<T>::Start()
{
	system("cls");
	Print("Sum Minigame: Mentally Sum the numbers");
	srand(time(nullptr));
	numIndex = 0;
	result = 0;
}

template<NUMBER T>
void SumMinigame<T>::Update()
{
	if (_kbhit() && _getch() == 27)
	{
		nextScene = Scenes::MENU;
		return;
	}

	if (!AllNumsPrinted())
	{
		PrintNumber();
	}
	else
	{
		ClearLine(2);
		SetCursorPos({ 0,2 });
		cout << "Enter The Result: ";
		cin >> playerInput;
		cout << "The Result was: " << result << endl;
		if (areNumsEqual(playerInput, result))
			cout << "Congratulations, You Win\n";
		else
			cout << "Wrong Result, You Lose\n";

		system("pause");
		nextScene = Scenes::MENU;
		return;
	}
}

template<NUMBER T>
void SumMinigame<T>::End()
{
	Print("Exit SumMinigame");
}

template<NUMBER T>
bool SumMinigame<T>::AllNumsPrinted()
{
	return numIndex >= numsQty;
}

template<NUMBER T>
void SumMinigame<T>::PrintNumber()
{
	T randomNum = rand() % (numMax + abs(numMin) + 1) - abs(numMin);
	if (floating_point<T>)
	{
		randomNum = (T)rand() / RAND_MAX * (numMax + abs(numMin) + 1) - abs(numMin);
		randomNum = ceilf(randomNum * 100) / 100;
	}
	if (result + randomNum < 0)
		randomNum *= -1;

	result += randomNum;
	ClearLine(2);
	SetCursorPos({ 0,2 });
	cout << randomNum;
	Sleep(sleepDuration);
	numIndex++;
}

template<NUMBER T>
bool SumMinigame<T>::areNumsEqual(T a, T b)
{
	T diff = a - b;
	T diffMag = diff * diff;
	return diffMag < maxMargin;
}

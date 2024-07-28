#pragma once
#include "Utils.h"

class CorruptedFileException : exception 
{
private:
	string message = "File Was Corrupted No Questions Loaded\n";

public:
	CorruptedFileException();
	const char* what() const throw();
};


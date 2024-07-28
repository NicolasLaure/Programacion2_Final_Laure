#pragma once
#include "Utils.h"

class FileOpeningException : std::exception
{
private:
	string message = "Failed To Open File";

public:
	FileOpeningException();
	const char* what() const throw();
};


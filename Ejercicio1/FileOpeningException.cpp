#include "FileOpeningException.h"

FileOpeningException::FileOpeningException()
{
}

const char* FileOpeningException::what() const throw()
{
	return message.c_str();
}
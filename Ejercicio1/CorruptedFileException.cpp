#include "CorruptedFileException.h"

CorruptedFileException::CorruptedFileException()
{
}

const char* CorruptedFileException::what() const throw()
{
    return message.c_str();
}

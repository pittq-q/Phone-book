#pragma once
#include "TechnicalFunc.h"

class PhoneBook
{
private:
	std::fstream file;

public:
	PhoneBook(char* argv);

	~PhoneBook();

	bool IsOpen();
};
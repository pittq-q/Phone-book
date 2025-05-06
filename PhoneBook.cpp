#include "PhoneBook.h"

PhoneBook::PhoneBook(char* argv)
{
	file.open(argv, std::ios::in | std::ios::out);
}

PhoneBook::~PhoneBook()
{
	file.close();
}

bool PhoneBook::IsOpen()
{
	if (!file.is_open())
	{
		std::cout << "This file could not be opened. Create one or choose another." << std::endl;
		exit(1);
	}

	return true;
}

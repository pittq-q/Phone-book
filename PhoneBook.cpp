#include "PhoneBook.h"

void PhoneBook::ReadPhoneBookSortByName() const
{
	BinaryTree tree{ file, 1 };
}

void PhoneBook::ReadPhoneBookSortByPhoneNumber() const
{
	BinaryTree tree{ file, 2 };
}

void PhoneBook::ReadPhoneBookSortByAddress() const
{
	BinaryTree tree{ file, 3 };
}

PhoneBook::PhoneBook(char* argv)
{
	file.open(argv, std::ios::in | std::ios::out);
}

PhoneBook::~PhoneBook()
{
	file.close();
}

bool PhoneBook::IsOpen() const
{
	if (!file.is_open())
	{
		std::cerr << "This file could not be opened. Create one or choose another." << std::endl;
		exit(1);
	}

	return true;
}

void PhoneBook::ReadPhoneBook() const
{
	std::cout << "Which sorting do you choose?" << std::endl
		<< "1 - By Full name;" << std::endl
		<< "2 - By Phone number;" << std::endl
		<< "3 - By Address;" << std::endl
		<< "4 - Return to main menu." << std::endl;

	switch (UserChoice(4, "Your choice is uncorrect. Please, choose from the following.", "Enter your choice"))
	{
	case 1:
		ReadPhoneBookSortByName();
		break;
	case 2:
		ReadPhoneBookSortByPhoneNumber();
		break;
	case 3:
		ReadPhoneBookSortByAddress();
		break;
	case 4:
		return;
	}
}

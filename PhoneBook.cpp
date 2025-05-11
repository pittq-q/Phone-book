#include "PhoneBook.h"

void PhoneBook::ReadPhoneBookSorted(const BinaryTree* tree) const
{
	tree->Show();
}

PhoneBook::PhoneBook(char* argv)
{
	file.open(argv, std::ios::in | std::ios::out);
	IsOpen();
	treeWithSortingByName = new BinaryTree{ file, 1 };
	file.clear();
	file.seekg(0, std::ios::beg);
	treeWithSortingByPhoneNumber = new BinaryTree{ file, 2 };
	file.clear();
	file.seekg(0, std::ios::beg);
	treeWithSortingByAddress = new BinaryTree{ file, 3 };
	file.clear();
	file.seekg(0, std::ios::beg);
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

void PhoneBook::ReadPhoneBook()
{
	std::cout << "Which sorting do you choose?" << std::endl
		<< "1 - By Full name;" << std::endl
		<< "2 - By Phone number;" << std::endl
		<< "3 - By Address;" << std::endl
		<< "4 - Return to main menu." << std::endl;

	switch (UserChoice(4, "Your choice is uncorrect. Please, choose from the following.", "Enter your choice"))
	{
	case 1:
		ReadPhoneBookSorted(treeWithSortingByName);
		break;
	case 2:
		ReadPhoneBookSorted(treeWithSortingByPhoneNumber);
		break;
	case 3:
		ReadPhoneBookSorted(treeWithSortingByAddress);
		break;
	case 4:
		return;
	}
}

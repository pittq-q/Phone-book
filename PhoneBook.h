#pragma once
#include "TechnicalFunc.h"
#include "BinaryTree.h"

class PhoneBook
{
private:
	std::fstream file;

	void ReadPhoneBookSortByName() const;

	void ReadPhoneBookSortByPhoneNumber() const;

	void ReadPhoneBookSortByAddress() const;

public:
	PhoneBook(char* argv);

	~PhoneBook();

	bool IsOpen() const;

	void ReadPhoneBook() const;
};
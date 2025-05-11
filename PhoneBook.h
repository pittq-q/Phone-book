#pragma once
#include "TechnicalFunc.h"
#include "BinaryTree.h"

class PhoneBook
{
private:
	std::fstream file;

	BinaryTree* treeWithSortingByName;
	BinaryTree* treeWithSortingByPhoneNumber;
	BinaryTree* treeWithSortingByAddress;

	void ReadPhoneBookSorted(const BinaryTree* tree) const;

public:
	PhoneBook(char* argv);

	~PhoneBook();

	bool IsOpen() const;

	void ReadPhoneBook();
};
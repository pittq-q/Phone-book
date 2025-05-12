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

	void InputInfoAboutNewNumber(const char* text, char* record, size_t size);

	void WriteNewRecordIntoFile(const char* text);

public:
	PhoneBook(char* argv);

	~PhoneBook();

	bool IsOpen() const;

	void ReadPhoneBook();

	void AddNewNumber();
};
#pragma once
#include "Record.h"
#include "PhoneBook.h"

class BinaryTree
{
private:
	struct Node
	{
		Record record;
		Node* right;
		Node* left;
	};

	Node* root = nullptr;

	void LoopForInsert();

public:
	BinaryTree() = default;

	BinaryTree(const std::fstream& file, int whatTypeOfSorting);

	void Insert(Record record, int whatTypeOfSorting);
};
#pragma once
#include "Record.h"
#include "TechnicalFunc.h"

class BinaryTree
{
private:
	struct Node
	{
		Record record;
		Node* left;
		Node* right;
	};

	Node* root;
	int sortType;

	int Compare(const Record& first, const Record& second) const;

	void Clear();

	void RemoveSubTree(Node* node);

	void ShowATree(Node* node) const;

public:
	BinaryTree(std::fstream& file, int whatTypeOfSorting);

	~BinaryTree();

	bool Insert(const Record& record);

	void Show() const;
};
#include "BinaryTree.h"

BinaryTree::BinaryTree(std::fstream& file, int whatTypeOfSorting)
	: sortType{ whatTypeOfSorting }, root{ nullptr }
{
	if (!file.is_open())
	{
		std::cerr << "Phone book isn't open.";
		exit(1);
	}

	Record record;
	char* context = nullptr;

	while (true)
	{
		char* buffer = new char[150] {};
		file.getline(buffer, 150);

		if (file.gcount() == 0)
		{
			delete[] buffer;
			break;
		}

		char* token = strtok_s(buffer, "|", &context);
		if (token)
		{
			memset(record.fullName, 0, 64);
			strcpy_s(record.fullName, 64, token);
		}
		
		token = strtok_s(nullptr, "|", &context);
		if (token)
		{
			memset(record.phoneNumber, 0, 15);
			strcpy_s(record.phoneNumber, 15, token);
		}

		token = strtok_s(nullptr, "|", &context);
		if (token)
		{
			memset(record.address, 0, 32);
			strcpy_s(record.address, 32, token);
		}

		Insert(record);
		delete[] buffer;
	}
}

BinaryTree::~BinaryTree()
{
	Clear();
}

bool BinaryTree::Insert(const Record& record)
{
	if (root == nullptr)
	{
		root = new Node{ record, nullptr, nullptr };
		return true;
	}

	Node* node = root;
	int comparison = 0;

	while (node != nullptr)
	{
		comparison = Compare(record, node->record);

		if (comparison == 0)
		{
			return false;
		}
		else if (comparison < 0)
		{
			if (node->left == nullptr)
			{
				node->left = new Node{ record, nullptr, nullptr };
				return true;
			}

			node = node->left;
		}
		else
		{
			if (node->right == nullptr)
			{
				node->right = new Node{ record, nullptr, nullptr };
				return true;
			}

			node = node->right;
		}
	}

	return false;
}

void BinaryTree::Show() const
{
	ShowATree(root);
}

int BinaryTree::Compare(const Record& first, const Record& second) const
{
	switch (sortType)
	{
	case 1:
		return std::strcmp(first.fullName, second.fullName);
	case 2:
		return std::strcmp(first.phoneNumber, second.phoneNumber);
	case 3:
		return std::strcmp(first.address, second.address);
	}

	return 0;
}

void BinaryTree::Clear()
{
	if (root != nullptr)
	{
		RemoveSubTree(root);
		root = nullptr;
	}
}

void BinaryTree::RemoveSubTree(Node* node)
{
	if (node->left != nullptr)
		RemoveSubTree(node->left);

	if (node->right != nullptr)
		RemoveSubTree(node->right);

	delete node;
}

void BinaryTree::ShowATree(Node* node) const
{
	if (node->left != nullptr)
		ShowATree(node->left);

	std::cout << "\nFull Name: " << node->record.fullName << std::endl
		<< "Phone Number: " << node->record.phoneNumber << std::endl
		<< "Address: " << node->record.address << std::endl;

	if (node->right != nullptr)
		ShowATree(node->right);
}

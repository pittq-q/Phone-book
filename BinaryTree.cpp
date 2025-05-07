#include "BinaryTree.h"

void BinaryTree::LoopForInsert()
{

}

BinaryTree::BinaryTree(const std::fstream& file, int whatTypeOfSorting)
{
	if (!file.is_open())
	{
		std::cerr << "Phone book isn't open.";
		exit(1);
	}

	switch (whatTypeOfSorting)
	{
	case 1:
		
		break;
	case 2:
		break;
	case 3:
		break;
	}
}

void BinaryTree::Insert(Record record, int whatTypeOfSorting)
{

}

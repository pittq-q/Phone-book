#include "PhoneBook.h"

void PhoneBook::ReadPhoneBookSorted(const BinaryTree* tree) const
{
	tree->Show();
}

void PhoneBook::InputInfoAboutNewNumber(const char* text, char* record, size_t size)
{
	std::cout << text;
	std::cin.getline(record, size);
	CheckingInput(Getline);
}

void PhoneBook::WriteNewRecordIntoFile(const char* text)
{
	int count = 0;
	while (text[count] != '\0')
	{
		file.put(text[count]);
		count++;
	}
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
	std::cout << "\nWhich sorting do you choose?" << std::endl
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

void PhoneBook::AddNewNumber()
{
	Record currentRecord;
	
	const char* infoAboutEnteringANewNumber = "\nEnter new phone number\nMax figures: 15;\nFormats: +123456789 or 123-145-1535\n: ";
	InputInfoAboutNewNumber(infoAboutEnteringANewNumber, currentRecord.phoneNumber, 15);

	const char* infoAboutEnteringANewFullName = "Enter the full name of the phone number owner\nMax symbols: 64;\nFormat: Last_name First_name Father's_name (if you have)\n: ";
	InputInfoAboutNewNumber(infoAboutEnteringANewFullName, currentRecord.fullName, 64);

	const char* infoAboutEnteringANewAddress = "Enter the full name of the address owner\nMax symbols: 32;\nFormat: Street_name street, house_number\n: ";
	InputInfoAboutNewNumber(infoAboutEnteringANewAddress, currentRecord.address, 32);

	file.seekp(0, std::ios::end);

	file.put('\n');
	WriteNewRecordIntoFile(currentRecord.fullName);
	file.put('|');
	WriteNewRecordIntoFile(currentRecord.phoneNumber);
	file.put('|');
	WriteNewRecordIntoFile(currentRecord.address);

	file.seekp(0, std::ios::beg);

	treeWithSortingByName->Insert(currentRecord);
	treeWithSortingByPhoneNumber->Insert(currentRecord);
	treeWithSortingByAddress->Insert(currentRecord);

	std::cout << "\nNew phone number has been added successfully! Please press any key to continue..." << std::endl;
}

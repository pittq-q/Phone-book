#include "TechnicalFunc.h"
#include "PhoneBook.h"

int main(int argc, char* argv[])
{
	CheckCorrectInputCommand(argc, argv);

	PhoneBook phoneBook{ argv[1] };

	std::cout << "Press any key to start..." << std::endl;
	while (getchar())
	{
		system("cls");
		std::cout << "Welcome to Phone Book Editor. Choose what do you want: " << std::endl
			<< "1 - Read a phone book;" << std::endl
			<< "2 - Add a new number to the phone book;" << std::endl
			<< "3 - Delete a specific number from the phone book;" << std::endl
			<< "4 - Find a specific number in the phone book;" << std::endl
			<< "5 - Update a specific number in the phone book;" << std::endl
			<< "6 - Close the program." << std::endl;

		switch (UserChoice(6, "Your choice is uncorrect. Please, choose from the following.", "Enter your choice"))
		{
		case 1:
			phoneBook.ReadPhoneBook();
			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

			break;
		case 6:
			return 0;
		}
	}
	
	return 0;
}
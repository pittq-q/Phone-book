#include "TechnicalFunc.h"

void CheckCorrectInputCommand(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cerr << "You didn't enter file!";
		exit(1);
	}

	if (argc > 2)
	{
		std::cerr << "You entered too many arguments!";
		exit(1);
	}

	int count = 0;
	while (argv[1][count] != '.')
	{
		if (argv[1][count] == '\0')
		{
			std::cerr << "Your file doesn't have extension!";
			exit(1);
		}
		count++;
	}
}

void CheckingInput(InputType type)
{
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(LLONG_MAX, '\n');
	}
	else if (type == InputType::Extraction)
	{
		std::cin.ignore(LLONG_MAX, '\n');
	}
}

int UserChoice(int count, const char* error, const char* whatToEnter)
{
	char checkForAString[2];

	while(true)
	{
		std::cout << whatToEnter << ": ";
		std::cin >> std::setw(2) >> checkForAString;
		CheckingInput(InputType::Extraction);
		if (checkForAString[1] != '\0' || (checkForAString[0] - '0') < 1 || (checkForAString[0] - '0') > count)
		{
			std::cerr << error << std::endl;
		}
		else
		{
			return checkForAString[0] - '0';
		}
	};

	return 0;
}
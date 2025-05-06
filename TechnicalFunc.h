#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>

enum InputType
{
	Extraction,
	Getline
};

void CheckCorrectInputCommand(int argc, char* argv[]);

void CheckingInput(InputType type);

int UserChoice(int count, const char* error, const char* whatToEnter);
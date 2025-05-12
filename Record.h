#pragma once
#include <cstring>

struct Record
{
	char* fullName;
	char* phoneNumber;
	char* address;

	Record();

	Record(const Record& other);

	~Record();
};
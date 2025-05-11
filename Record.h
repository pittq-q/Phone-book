#pragma once
#include <cstring>

struct Record
{
	char* fullName;
	char* phoneNumber;
	char* address;

	Record()
	{
		fullName = new char[64] {};
		phoneNumber = new char[15] {};
		address = new char[32] {};
	}

	Record(const Record& other)
	{
		fullName = new char[64] {};
		phoneNumber = new char[15] {};
		address = new char[32] {};

		strcpy_s(fullName, 64, other.fullName);
		strcpy_s(phoneNumber, 15, other.phoneNumber);
		strcpy_s(address, 32, other.address);
	}

	~Record()
	{
		delete[] fullName;
		fullName = nullptr;
		delete[] phoneNumber;
		phoneNumber = nullptr;
		delete[] address;
		address = nullptr;
	}
};
#pragma once
#include<string>
using namespace std;
class FullName
{
public:
	string firstName;
	string lastName;


	void   fInputFullName(ifstream& filein)
	{
		getline(filein, lastName, ';');
		getline(filein, firstName, ';');
	}
	bool   IsTrueLastName()
	{
		if (lastName.empty())
			return false;
		if (lastName[0] == ' ')
			return false;
		for (int i = 0; i < lastName.length(); i++)
		{
			if (lastName[i] < 65 || lastName[i] >132 || (lastName[i] > 90 && lastName[i] < 97))
				if (lastName[i] != ' ')
					return false;
		}
		return true;
	}
	bool   IsTrueFirstName()
	{
		if (firstName[0] < 32)
			return false;
		for (int i = 0; i < firstName.length(); i++)
		{
			if (firstName[i] < 65 || firstName[i] >132 || (firstName[i] > 90 && firstName[i] < 97))
				return false;
		}
		return true;
	}
	void   printName()
	{
		string temp = lastName + " " + firstName;
		cout << left << setw(32) << temp << "| ";
	}

};
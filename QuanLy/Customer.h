#pragma once

#include <string>
#include "FullName.h"
#include "Date.h"
#include<fstream>
#include<iostream>
#include<iomanip>
using namespace std;
class Customer
{
public:
	string id;
	FullName fullName;
	Date dateOfBirth;
	string sex;
	string phoneNumber;
	string address;
	void fInputCustomer(ifstream& filein)//true
	{
		getline(filein, id, ';');
		fullName.fInputFullName(filein);
		dateOfBirth.fDate(filein);
		filein.seekg(1, 1);
		getline(filein, sex, ';');
		getline(filein, phoneNumber, ';');
		getline(filein, address, '\n');
	}
	void printCustomer()
	{
		cout << "| " << left << setw(14) << id << "| ";
		fullName.printName();
		cout << left << setw(15) << phoneNumber << "| ";
		dateOfBirth.printDate();
		cout << left << setw(8) << sex << "| ";
		cout << left << setw(51) << address << "|";
	}


};

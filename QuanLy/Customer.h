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
	string phone;
	string address;
	void printCustomer()
	{
		cout << "| " << left << setw(14) << id << "| ";
		fullName.printName();
		cout << left << setw(15) << phone << "| ";
		dateOfBirth.printDate();
		cout << left << setw(8) << sex << "| ";
		cout << left << setw(51) << address << "|";
	}
	void fInputCustomer(ifstream& filein)
	{
		getline(filein, id, ';');
		fullName.fInputFullName(filein);
		dateOfBirth.fDate(filein);
		filein.seekg(1, 1);
		getline(filein, sex, ';');
		getline(filein, phone, ';');
		getline(filein, address, '\n');
	}
};



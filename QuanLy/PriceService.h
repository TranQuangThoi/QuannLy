#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class PriceService                          // N la san 5, M la san 11
{
public:
	int prTrada;
	int prSuoi;
	int prOlong;
	int prPepsi;
	PriceService()
	{
		fGetPriceService();
	}
	void UpdatePriceService();
	void fSetPriceService();
	void fGetPriceService();
};
void PriceService::UpdatePriceService()
{
NHAPGIATRADA:
	try
	{
		cout << "Gia tra da: ";
		cin >> prTrada;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			throw "Phai nhap gia tra da la so nha ban ~.~";
		}
		if (prTrada < 0)
			throw "Gia tra da phai la so duong ~.~";
	}
	catch (const char* msg)
	{
		cout << msg << endl;
		cout << "Vui long nhap lai gia san ~.~\n";
		goto NHAPGIATRADA;
	}
NHAPGIAPNUOCSUOI:
	try
	{
		cout << "Gia nuoc suoi:";
		cin >> prSuoi;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			throw "Phai nhap gia nuoc suoi la so ban ui ~.~";
		}
		if (prSuoi < 0)
			throw "Gia nuoc suoi phai la so duong";
	}
	catch (const char* msg)
	{
		cout << msg << endl;
		cout << "Vui long nhap lai gia\n";
		goto NHAPGIAPNUOCSUOI;
	}
NHAPGIAOLONG:
	try
	{
		cout << "Gia o long: ";
		cin >> prOlong;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			throw "Phai nhap gia o long la so ~.~";
		}
		if (prOlong < 0)
			throw "Gia o long phai la so duong";
	}
	catch (const char* msg)
	{
		cout << msg << endl;
		cout << "Vui long nhap lai gia o long\n";
		goto NHAPGIAOLONG;
	}
NHAPGIAPEPSI:
	try
	{
		cout << "Gia pepsi ";
		cin >> prPepsi;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			throw "Phai nhap gia pepsi la so ban ui ~.~";
		}
		if (prPepsi < 0)
			throw "Gia pepsi phai la so duong";
	}
	catch (const char* msg)
	{
		cout << msg << endl;
		cout << "Vui long nhap lai gia san\n";
		goto NHAPGIAPEPSI;
	}
	fSetPriceService();
}
void PriceService::fSetPriceService()
{
	ofstream fileout;
	fileout.open("GIADICHVU.TXT", ios::out);
	fileout << this->prTrada << endl;
	fileout << this->prSuoi << endl;
	fileout << this->prOlong << endl;
	fileout << this->prPepsi << endl;
	fileout.close();
}
void PriceService::fGetPriceService()
{
	ifstream filein;
	filein.open("GIADICHVU.TXT", ios::in);
	while (!filein.eof())
	{
		filein >> prTrada;
		filein >> prSuoi;
		filein >> prOlong;
		filein >> prPepsi;
	}
	filein.close();
}

#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Price                          // N la san 5, M la san 11
{
public:
	int perHourM;
	int perHourN;
	Price()
	{
		fGetPrice();
	}
	void  UpdatePrice()
	{
		cout << "Cap nhat lai gia san\n";
		cout << "San 5 nguoi\n";
	NHAPGIASAN5THEOGIO:
		try
		{
			cout << "Gia san theo moi gio: ";
			cin >> perHourN;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore();
				throw "Phai nhap gia san la so nha ban ~.~";
			}
			if (perHourN < 0)
				throw "Gia san phai la so duong ~.~";
		}
		catch (const char* msg)
		{
			cout << msg << endl;
			cout << "Vui long nhap lai gia san ~.~\n";
			goto NHAPGIASAN5THEOGIO;
		}

		cout << "San 11\n";
	NHAPGIASAN11THEOGIO:
		try
		{
			cout << "Gia san theo moi gio: ";
			cin >> perHourM;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore();
				throw "Phai nhap gia san la so ~.~";
			}
			if (perHourM < 0)
				throw "Gia san phai la so duong";
		}
		catch (const char* msg)
		{
			cout << msg << endl;
			cout << "Vui long nhap lai gia san\n";
			goto NHAPGIASAN11THEOGIO;
		}
		fSetPrice();
	}
	void  fSetPrice()
	{
		ofstream fileout;
		fileout.open("GIASAN.TXT", ios::out);
		fileout << this->perHourN << endl;
		fileout << this->perHourM << endl;
		fileout.close();
	}
	void  fGetPrice()
	{
		ifstream filein;
		filein.open("GIASAN.TXT", ios::in);
		while (!filein.eof())
		{
			filein >> perHourN;
			filein >> perHourM;
		}
		filein.close();
	}

};

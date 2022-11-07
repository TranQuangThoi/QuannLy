#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;
class Picture
{
public:
	void inputPicture()
	{
		ifstream file;
		file.open("Picture.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line, '\n');
			cout << line << endl;
			Sleep(80);
		}

	}

};


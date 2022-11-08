#pragma once
#include <time.h>
class Date
{
public:
	int second;
	int minute;
	int hour;
	int day;
	int month;
	int year;
	int  SumDate() {
		if (month < 3) {
			year--;
			month += 12;
		}
		return 365 * year + year / 4 - year / 100 + year / 400 + (153 * month - 457) / 5 + day - 306;
	}
	
	void  fOuputDateTime(ofstream& fileout, Date date)
	{
		fileout << date.hour << ":" << date.minute << ":" << date.second << ";"
			<< date.day << "/" << date.month << "/" << date.year;

	}
	void  fOuputDate(ofstream& fileout, Date date)
	{
		fileout << date.day << "/" << date.month << "/" << date.year;
	}
	void  fDate(ifstream& filein)
	{
		filein >> day;
		filein.seekg(1, 1);
		filein >> month;
		filein.seekg(1, 1);
		filein >> year;
	}
	void  fDateTime(ifstream& filein)
	{
		filein >> hour;
		filein.seekg(1, 1);
		filein >> minute;
		filein.seekg(1, 1);
		filein >> second;
		filein.seekg(1, 1);
		filein >> day;
		filein.seekg(1, 1);
		filein >> month;
		filein.seekg(1, 1);
		filein >> year;
	}
	bool  IsLeapYear()
	{
		if (year % 400 == 0 || year % 100 != 0 && year % 4 == 0)
			return true;
		return false;
	}
	int  DateInMonth()
	{
		if (month == 4 || month == 6 || month == 9 || month == 11)
			return 30;
		else
			if (month == 2)
				if (IsLeapYear())
					return 29;
				else
					return 28;
			else
				return 31;
	}
	bool  CheckDate()
	{
		if (day > 0 && day <= DateInMonth() && month > 0 && month <= 12 && year > 0)
			return  true;
		return false;
	}

	void  printDateTime()
	{
		string temp = to_string(hour) + ":" + to_string(minute) + ":" + to_string(second)
			+ " " + to_string(day) + "/" + to_string(month) + "/" + to_string(year);
		cout << " " << left << setw(25) << temp << "|";
	}
	void  printDate()
	{
		string temp = to_string(day) + "/" + to_string(month) + "/" + to_string(year);
		cout << left << setw(11) << temp << "| ";
	}

	void  AutoSetDate()
	{
		struct tm currentTime;
		time_t now = time(0);
		localtime_s(&currentTime, &now);
		day = currentTime.tm_mday;
		month = 1 + currentTime.tm_mon;
		year = 1900 + currentTime.tm_year;
		hour = currentTime.tm_hour;
		minute = currentTime.tm_min;
		second = currentTime.tm_sec;
	}

};
#pragma once
#include <string>
#include "Date.h"
#include "CustomerList.h"
#include "RoomList.h"
#include "Service.h"
#include "ServiceList.h"
#include"Picture.h"

class Trade
{
private:
	int price = 0;
	int tiendichvu;
public:
	string id;
	Room room;
	Service service;
	Customer customer;
	Date dateIn;
	Date dateOut;
	void fOutput(ofstream& fileout)
	{
		fileout << id << ";" << customer.id << ";" << room.id << ";";
		dateIn.fOuputDateTime(fileout, dateIn);
	}
	void InitDateOut()
	{
		dateOut.day = 0;
		dateOut.minute = 0;
		dateOut.year = 0;
		dateOut.hour = 0;
		dateOut.minute = 0;
		dateOut.second = 0;
	}
	int GetPrice()
	{
		CalPrice();
		return price;
	}
	void CalPrice()//true
	{
		int totalhour;
		dateOut.AutoSetDate();
		int gen = dateOut.SumDate() - dateIn.SumDate();
		if (gen == 0)
			totalhour = dateOut.hour - dateIn.hour;
		else
			totalhour = (gen - 1) * 24 + (dateOut.hour + (24 - dateIn.hour));
		if (totalhour == 0)
			price = room.GetPricePerHour();
		else if (totalhour < 5)
			price = totalhour * room.GetPricePerHour();
		else
			if (totalhour >= 5 && totalhour < 12)
				price = totalhour * room.GetPricePerHour();
			else
				price = (totalhour / 12) * room.GetPricePerHour() + (totalhour % 12) * room.GetPricePerHour();
	}

};
#pragma once
#include <string>
#include "Price.h"
using namespace std;
class Room
{
private:
	Price price;
public:
	string id;
	int state;


	int GetPricePerHour()
	{
		price.fGetPrice();
		if (id[0] == 'M')
			return price.perHourM;
		return price.perHourN;
	}

};

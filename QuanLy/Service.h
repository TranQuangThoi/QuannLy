#pragma once
#include <string>
#include "PriceService.h"
using namespace std;
class Service
{
private:
	PriceService price;
public:
	string id;
	int quatity;
	

	int GetPriceService()
	{
		price.fGetPriceService();
		if (id[0] == 'S')
			return price.prSuoi;
		else if (id[0] == 'T')
			return price.prTrada;
		else if (id[0] == 'O')
			return price.prOlong;
		else
		{
			return price.prPepsi;
		}
	}

};



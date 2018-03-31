#include "Header.h"

istream &operator>>(istream&is, Reading &r)
{

	int hr;
	double tmp;
	string suffix;

	is >> hr >> tmp>>suffix;

	if (!is)
	{
		if (suffix != "c")
		{
			is.unget();
			is.clear(ios_base::failbit);
		}
		else if (suffix != "f")
		{
			is.unget();
			is.clear(ios_base::failbit);		
		}
	}
		
	r.hour = hr;
	r.temperature = tmp;
	r.unit = suffix;
	
	return is;
}


void write_txt(vector<Reading>&store, ofstream& ost,string oname)
{
	cout << "Enter temperature readings(i.e hr temperature):\n";

	for(Reading r; cin >> r;)
	{
		store.push_back(r);

	}

	cout << "Filling txt file...\n";
	
	ost.open(oname);
	if (!ost)runtime_error("can't open output file");
	
	for (size_t i = 0; i < store.size(); ++i)
	{
		ost << store[i].hour << " "
			<< store[i].temperature
			<< store[i].unit << endl;
		
	}

	ost.close();	
}




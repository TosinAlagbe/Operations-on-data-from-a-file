//reads data from file and calculates median and mode of the data

#include "Header.h"

bool operator<(const Reading& r1, const Reading& r2)
{
	return r1.temperature < r2.temperature;
}

void read_txt(ifstream&ist, string oname, vector<Reading>&temps_vector)
{
	ist.open(oname);

	for (Reading r; ist >> r;)
	{
		temps_vector.push_back(r);
	}
	for (size_t i= 0; i < temps_vector.size(); ++i)
	{
		if (temps_vector[i].unit == "c")
		{
			temps_vector[i].temperature = temps_vector[i].temperature*1.8 + 32;
		}

	}

	
}


double mean(vector<Reading>&r)
{
	double sum = 0;

	for (size_t i = 0; i < r.size(); ++i)
	{

		sum = sum + r[i].temperature;
		
	}

	return(sum / double(r.size()));
}

double median(vector<Reading>&r)
{
	sort(r.begin(), r.end());
	return r[r.size() / 2].temperature;

}

#include "stdafx.h"
#include <vector>
#include<iostream>
#include<fstream>
#include<string>
#include <cerrno>
#include<algorithm>
#include<functional>

using std::ifstream;
using std::ofstream;
using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::istream;
using std::ios_base;
using std::runtime_error;


struct Reading
{
	int hour;
	double temperature;
	string unit;
};


istream &operator>>(istream&is, Reading &r);
void read_txt(ifstream&, string , vector<Reading>&);
void write_txt(vector<Reading>&, ofstream& , string );
double mean(vector<Reading>&);
double median(vector<Reading>&);



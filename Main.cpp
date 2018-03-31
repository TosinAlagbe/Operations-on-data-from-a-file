#include"Header.h"

string choose_file(string filename)    //add extesnion of file
{
	return filename;
}

int main()
{
	string oname = choose_file("test_file.txt");

	vector<Reading>store;
	ofstream ost;
	write_txt(store, ost, oname);

	vector<Reading>store2;
	ifstream it;
	read_txt(it, oname, store2);
	cout <<"Mean: "<< mean(store2)<<endl;
	cout << "Median: " << median(store2) << endl;
}

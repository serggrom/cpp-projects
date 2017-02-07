#include "../../std_lib_facilities.h"

void init(vector<double>& v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		v[i] = i;
	}
}


int main()
{
	/*
	vector<double> vd(10);
	init(vd);
	for (int i = 0; i < vd.size(); ++i)
	{
		cout << vd[i] << "\n";
	}
	*/
	
	int i = 7;
	int& r = i;
	cout << r << "\t" << i << "\n";
	r = 9;
	cout << r << "\t" << i << "\n";
	i = 10;
	cout << r << "\t" << i;
}
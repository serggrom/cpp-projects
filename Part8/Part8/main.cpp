#include "../../std_lib_facilities.h"
#include "my.h"
#include <iostream>


/*
void init(vector<double>& v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		v[i] = i;
	}
}
*/


/*
void g(int a, int& r, const int& cr)
{
	++a;
	++r;
	a = cr;
}
*/

/*
void larger(vector<int>& v1, vector<int>& v2)
{
	if (v1.size() != v2.size())
	{
		error("larger(): different sizes");
	}
	for (int i = 0; i < v1.size(); ++i)
	{
		if (v1[i] < v2[i])
		{
			swap(v1[i], v2[i]);
		}
	}
}


void f()
{
	vector<int> vx;
	vector<int> vy;

	larger(vx, vy);
}
*/
/*
void print_foo()
{
	cout << foo << "\n";
}

void print(int a)
{
	cout << a << "\n";
}
*/

void swap_v(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void swap_r(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

/*
void swap_cr(const int& a, const int& b)
{
	int tåmð;
	tåmð = a;
	a = b;
	b = tåmð;
}
*/


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
	
	/*
	int i = 7;
	int& r = i;
	cout << r << "\t" << i << "\n";
	r = 9;
	cout << r << "\t" << i << "\n";
	i = 10;
	cout << r << "\t" << i << "\n";
	*/
	const int x = 7;
	 int y = 9;
	
	cout << x << "\t" << y << "\n";
	swap_r(x, y);
	cout << x << "\t" << y << "\n";
	


}

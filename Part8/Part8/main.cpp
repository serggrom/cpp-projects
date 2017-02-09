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

/*
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
*/


/*
void swap_cr(const int& a, const int& b)
{
	int tåmð;
	tåmð = a;
	a = b;
	b = tåmð;
}
*/

/*
namespace X
{
	int var;
	void print()
	{
		cout << var << "\n";
	}
}


namespace Y
{
	int var;
	void print()
	{
		cout << var << "\n";
	}
}

namespace Z
{
	int var;
	void print()
	{
		cout << var << "\n";
	}
}
*/

void print(vector<int>& v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		cout << "v[" << i << "] = " << v[i] << "\n";
	}
}

void print_str(vector<string>& v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		cout << "v[" << i << "] = " << v[i] << "\n";
	}
}

vector<int> fibonacci(int x, int y, vector<int>& v, int n)
{
	v.push_back(x);
	v.push_back(y);
	for (int i = 0; i < n; ++i)
	{
		int next_fibb = x + y;
		v.push_back(next_fibb);
		x = y;
		y = next_fibb;
	}
	return v;
}


vector<int> my_sort(vector<int>& v)
{
	vector<int> b;
	b = v;
	int med = b.size()/2;
	for (int i = 1; i <= med; ++i)
	{
		swap(b[i-1], b[b.size() - i]);
	}
	return b;
}


void my_sort2(vector<int>& v)
{
	int med = v.size()/2;
	for (int i = 1; i <= med; ++i)
	{
		swap(v[i-1], v[v.size() - i]);
	}
}

vector<string> sort_str(vector<string>& v)
{
	vector<string> b;
	b = v;
	int med = b.size()/2;
	for (int i = 1; i <= med; ++i)
	{
		swap(b[i-1], b[b.size() - i]);
	}
	return b;
}

void sort_str2(vector<string>& v)
{
	int med = v.size()/2;
	for (int i = 1; i <= med; ++i)
	{
		swap(v[i-1], v[v.size() - i]);
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
	
	/*
	int i = 7;
	int& r = i;
	cout << r << "\t" << i << "\n";
	r = 9;
	cout << r << "\t" << i << "\n";
	i = 10;
	cout << r << "\t" << i << "\n";
	*/
	
	/*
	const int x = 7;
	int y = 9;
	
	cout << x << "\t" << y << "\n";
	swap_r(x, y);
	cout << x << "\t" << y << "\n";
	*/

	/*
	X::var = 7;
	X::print();
	using namespace Y;
	var = 9;
	print();
	{
		using Z::var;
		using Z::print;
		var = 11;
		print();
	}
	print();
	X::print();
	*/
	
	/*
	vector<int> a;
	fibonacci(1,2, a, 5);
	print(a);
	int c = 3;
	int d = 4;
	swap(c,d);
	cout << c << "\t" << d << "\n";
	print(my_sort(a));
	my_sort2(a);
	print(a);
	*/


	
	vector<string> name_v;
	vector<int> age_v;
	
	/*
	name.push_back("cadfem");
	name.push_back("ansys");
	name.push_back("stroustrup");
	name.push_back("aaa");
	print_str(name);
	print_str(sort_str(name));
	sort_str2(name);
	print_str(name);
	*/

	for (int i = 0; i < 5; ++i)
	{
		string name;
		int age;
		cin >> name >> age;
		name_v.push_back(name);
		age_v.push_back(age);
	}
	vector<string> copy_name_v = name_v;
	sort(name_v.begin(), name_v.end());
	for (int i = 0; i < name_v.size(); ++i)
	{
		for (int j = 0; j < copy_name_v.size(); ++j)
		{
			if (name_v[i] == copy_name_v[j])
			{
				swap(age_v[j], age_v[i]);
			}
		}
	}

	print_str(name_v);
	print(age_v);
}

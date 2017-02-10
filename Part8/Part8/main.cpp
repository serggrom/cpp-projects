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


double sum_of_multiply(vector<double>& v, vector<double>& w)
{
	if (v.size() == w.size())
	{
		double sum = 0;
		for (int i = 0; i < v.size(); ++i)
		{
			sum =+ v[i]*w[i];
		}
		return sum;
	}
	else
	{
		error("Vectors must have same size!");
	}
}

int maxv (vector<int>& v)
{
	int max = v[0];
	for(int i = 0; i < v.size(); ++i)
	{
		if (max < v[i])
		{
			max = v[i];
		}
	}
	return max;
}

void properties_of_vector(vector<double>& v)
{
	double max = v[0];
	for(int i = 0; i < v.size(); ++i)
	{
		if (max < v[i])
		{
			max = v[i];
		}
	}


	double min = v[0];
	for(int i = 0; i < v.size(); ++i)
	{
		if (v[i] < min)
		{
			min = v[i];
		}
	}

	double mediana;
	sort(v.begin(), v.end());
	if (v.size() % 2 != 0)
	{
		int med_count = (v.size()+1) / 2;
		mediana = v[med_count];
	}
	else
	{
		int med_count1 = v.size()/2;
		int med_count2 = (v.size() + 1) /2;
		mediana = (v[med_count1] + v[med_count2]) / 2;
	}

	double sum;
	for (int i = 0; i < v.size(); ++i)
	{
		sum =+ v[i];
	}
	double medium_value = sum / v.size();
	
	cout << "Maximum value: " << &max << "\n";
	cout << "Minimum value: " << &min << "\n";
	cout << "Mediana's value: " << &mediana << "\n";
	cout << "Medium value: " << &medium_value << "\n";
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

	vector<double> price;
	vector<double> weight;
	
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


	/*
	while (true)
	{
		string name;
		int age;
		cin >> name;
		if (name == "quit")
		{
			break;
		}
		cin >> age;
		name_v.push_back(name);
		age_v.push_back(age);
	}
	vector<string> copy_name_v = name_v;
	sort(name_v.begin(), name_v.end());
	int med1 = name_v.size()/2;
	//int med2 = copy_name_v.size()/2;
	for (int i = 0; i < med1; ++i)
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
	*/
	 /*
	while (true)
	{
		double one_price;
		double one_wight;
		cin >> one_price;
		cin >> one_wight;
		price.push_back(one_price);
		weight.push_back(one_wight);
		cout << "Do you want to exit?\n";
		string exit;
		cin >> exit;
		if (exit == "yes")
		{
			break;
		}
	}
	cout << sum_of_multiply(price, weight) << "\n";
	*/

	vector<int> counts;
	vector<double> statistics;
	statistics.push_back(12);
	statistics.push_back(360);
	statistics.push_back(150);
	statistics.push_back(8.5);
	statistics.push_back(22.8);
	statistics.push_back(3.14);




	/*
	while (true)
	{
		int  count;
		cin >> count;
		counts.push_back(count);
		cout << "Do you want to exit?\n";
		string exit;
		cin >> exit;
		if (exit == "yes")
		{
			break;
		}
	}
	*/

	//cout << maxv(counts) << "\n";
	
	
	properties_of_vector(statistics);



}

#include "../../std_lib_facilities.h"

vector<string> month_tbl;

/*9.4.1
struct Date
{
	int y;
	int m;
	int d;
	//Date(int y, int m, int d);
	void init_day(Date& dd, int y, int m, int d);
	void add_day(Date& dd, int n);
};
*/

/*9.4.1
struct Date
{
	int y, m, d;
	Date(int y, int m, int d);
	
	void add_day(int n);
};
*/

/*9.4.3
class Date
{
	int y, m, d;
public:
	Date(int y, int m, int d);
	void add_day(int n);
	int month()
	{
		return m;
	}
	int day()
	{
		return d;
	}
	int year()
	{
		return y;
	}
};
*/

/*9.7.1
enum class Month 
{
	Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
};

class Date
{
public:
	Date(int y, Month m, int d);
	void add_day(int n);
	int year()
	{
		return y;
	}
	Month month()
	{
		return m;
	}
	int day()
	{
		return d;
	}
private:
	int y;
	Month m;
	int d;
};
*/

/*9.7.4
enum class Month 
{
	Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
};


class Date
{
public:
	Date(int y, Month m, int d);
	int day() const
	{
		return d;
	}
	Month month() const
	{
		return m;
	}
	int year() const
	{
		return y;
	}

	void add_day(int n);
private:
	int y;
	Month m;
	int d;
};
*/


class Name_pairs
{
public:
	void read_names();
	void read_ages();
	void print();
	void my_sort();
	vector<string> nms()
	{
		return names;
	}
	vector<double> ags()
	{
		return ages;
	}
private:
	vector<string> names;
	vector<double> ages;
};

void Name_pairs::read_names()
{
	string name;
	cout << "Input the names, if you want to end input 'exit'" << endl;
	while (cin)
	{
		cin >> name;
		if (!cin)
		{
			error("Unexpected chars");
		}
		if (name == "exit")
		{
			break;
		}
		names.push_back(name);
	}
}

void Name_pairs::read_ages()
{
	double age;
	for (int i = 0; i < names.size(); ++i)
	{
		cout << "What is a " << names[i] << " age?" << endl;
		cin >> age;
		ages.push_back(age);
	}
}


void Name_pairs::print()
{
	if (names.size() != ages.size())
	{
		error("Missing one pair!");
	}
	for (int i = 0; i < names.size(); ++i)
	{
		cout << names[i] << " " << ages[i] << endl;
	}

}


void Name_pairs::my_sort()
{
	if (names.size() != ages.size())
	{
		error("Missing one pair!");
	}
	vector<string> names_copy = names;
	sort(names.begin(), names.end());
	int k = names.size() / 2;
	int n = names_copy.size() ;
	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (names_copy[j] == names[i])
			{
				double temp = ages[i];
				ages[i] = ages[j];
				ages[j] = temp;
			}
		}
	}
}

ostream& operator<<(ostream& os, Name_pairs& tbl)
{
	if (tbl.nms().size() != tbl.ags().size())
	{
		error("Missing one pair!");
	}
	for (int i = 0; i < tbl.nms().size(); ++i)
	{
		cout << "Name: " << tbl.nms()[i] << " "
		      << "Age: " << tbl.ags() [i]<< endl;
	}
	return os;
}

bool operator==(Name_pairs& tbls, Name_pairs& tbl)
{
	if (tbls.nms().size() != tbls.ags().size())
	{
		error("Missing one pair!");
	}
	if (tbl.nms().size() != tbl.ags().size())
	{
		error("Missing one pair!");
	}
	if (tbls.nms().size() != tbl.ags().size())
	{
		error("Missing one pair!");
	}
	for (int i = 0; i < tbls.nms().size(); ++i)
	{
		if (tbls.nms()[i] == tbl.nms()[i] && tbls.ags()[i] == tbl.ags()[i])
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}


bool operator!=(Name_pairs& tbls, Name_pairs& tbl)
{
	return !(tbls == tbl);
}



class Book
{
public:
	bool find_book();
	void add_books();
private:
	vector<char> ISBN;
	vector<string> Title;
	vector<string> Last_Name;
	vector<string> First_Name;
	vector<bool> where_is_book();
};

void Book::add_books()
{
	while (true)
	{
		cout << "Input info about books in the database:" << endl;
		int isbn_max = 7;
		int counter = 0;
		cout << "Input the ISBN number: " << endl;
		while (counter < isbn_max)
		{
			if (counter == 1 || counter == 3 || counter == 5)
			{
				ISBN.push_back('-');
			}
			else if (counter == 7)
			{
				char n;
				if (!cin)
				{
					error("Unexpected chars");
				}
				cin >> n;
				switch (n)
				{
				case '0': case '1': case '2': case '3': 
				case '4': case '5': case '6': case '7':
				case '8': case '9':
					ISBN.push_back(n);
					break;
				}
			}
			char n;
			if (!cin)
			{
				error("Unexpected chars");
			}
			cin >> n;
			switch (n)
			{
			case '0': case '1': case '2': case '3': 
			case '4': case '5': case '6': case '7':
			case '8': case '9': case 'a': case 'b':
			case 'c': case 'd': case 'e': case 'f':
			case 'g': case 'h':
				ISBN.push_back(n);
				break;
			}
			char x;
			++counter;
		}
		cout << "Input the title of book: " << endl;
		string bk_ttl;
		cin >> bk_ttl;
		if (!cin)
		{
			error("Unexpected chars");
		}
		Title.push_back(bk_ttl);

		cout << "Input the Author First Name: " << endl;
		string Name;
		cin >> Name;
		if (!cin)
		{
			error("Unexpected chars");
		}
		First_Name.push_back(Name);

		cout << "Input the Author Last Name: " << endl;
		string Name;
		cin >> Name;
		if (!cin)
		{
			error("Unexpected chars");
		}
		Last_Name.push_back(Name);

		cout << "Are are you want to add one book yet? Y/N: " << endl;
		string ans;
		cin >> ans;
		if (!cin)
		{
			error("Unexpected chars");
		}
		if (ans == "N")
		{
			break;
		}
	}


}

/*
class Year 
{
	static const int min = 1800;
	static const int max = 2200;
public:
	class Invalid { };
	Year(int x)
		:y(x)
	{
		if (x < min || max <= max)
		{
			throw Invalid();
		}
	}
	int year()
	{
		return y;
	}
private:
	int y;
};

enum class Month
{
	Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
};
*/


/*
enum Month_simplify 
{
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec 
};
*/


/*
Month int_to_month(int x)
{
	if (x < int(Month::Jan) || int(Month::Dec) < x)
	{
		error("Wrong month");
	}
	return Month(x);
}


Month operator++(Month& m)
{
	if (m == Month::Dec)
	{
		m = Month::Jan;
	}
	else
	{
		m = Month(int(m) + 1);
	}
	return m;
}

ostream& operator<<(ostream& os, Month m)
{
	return os << month_tbl[int(m)];
}


enum class Day 
{
	monday, tuesday, wednesday, thursday, friday, saturday, sunday
};

class Date
{
public:
	Date(Year y, Month m, int d);
	void add_day(int n);
	void add_month(int n);
	void add_year(int n);
	class Invalid { };
	Month month() const
	{
		return m;
	}
	int day() const
	{
		return d;
	}
	Year year() const
	{
		return y;
	}
	Date();
	~Date();

private:
	Year y ;
	Month m;
	int d ;
	bool is_valid();
};


Date::Date()
	:y(default_date().year),
	 m(default_date().month), 
	 d(default_date().day)
{
}


const Date& default_date()
{
	static Date dd(2001, Month::Jan, 1);
	return dd;
}

Date::Date(Year yy, Month mm, int dd)
	:y(yy), m(mm), d(dd)
{
	if (!is_valid())
	{
		throw Invalid();
	}
}

/*
bool Date::is_valid()
{
	if (m == 2)
	{
		if (y % 4 == 0)
		{
			if (d >= 1 && d < 30)
			{
				return true;
			}
		}
		else if (d >= 1 && d < 29)
		{
			return true;
		}
	}
	if (m < 1 || 12 < m)
	{
		return false;
	}
}
*/

/*
void Date::add_day(int n)
{

}
*/

/*
int Date::year()
{
	return y;
}

int Date::month()
{
	return m;
}

int Date::day()
{
	return d;
}
*/

/*
Date::~Date()
{
}
*/

/*
void f (int x, int y)
{
	try 
	{
		Date dxy(Year(2009), Month::Feb, y);
		cout << dxy << "\n";
		dxy.add_day(2);
	}
	catch(Date::Invalid)
	{
		error("Wrong date");
	}
}
*/


class X
{
public:
	int m;
	int mf (int v)
	{
		int old = m;
		m = v;
		return old;
	}
	X();
	~X();

private:

};

X::X()
{
}

X::~X()
{
}


//9.4.1
/*
void init_day(Date& dd, int y, int m, int d)
{
    if (d < 1 || d > 31)
	{
		error("Wrong day!");
	}
	else
	{
		dd.d = d;
	}
	if (m < 1 || m > 12)
	{
		error("Wrong month");
	}
	else
	{
		dd.m = m;
	}
	if (y < 1800 || y > 2200)
	{
		error("Wrong year");
	}
	else
	{
		dd.y = y;
	}	
}


void add_day(Date& dd,int n)
{
	
	if (dd.m == 12 && dd.d == 31)
	{
		dd.y++;
		dd.m = 1;
		dd.d = 1;
	}
	if (dd.d == 31)
	{
		dd.m++;
		dd.d = 1;
	}
	else
	{
	
		dd.d = dd.d +  n;
	}
}
*/

/*9.4.2
Date::Date(int y0, int m0, int d0)
{
    if (d0 < 1 || d0 > 31)
	{
		error("Wrong day!");
	}
	else
	{
		d = d0;
	}
	if (m0 < 1 || m0 > 12)
	{
		error("Wrong month");
	}
	else
	{
		m = m0;
	}
	if (y0 < 1800 || y0 > 2200)
	{
		error("Wrong year");
	}
	else
	{
		y = y0;
	}
}

void Date::add_day(int n)
{	
	if (m == 12 && d == 31)
	{
		y++;
		m = 1;
		d = 1;
	}
	if (d == 31)
	{
		m++;
		d = 1;
	}
	else
	{
	
		d = d + n;
	}
}
*/

/*9.4.3
Date::Date(int y0, int m0, int d0)
{
    if (d0 < 1 || d0 > 31)
	{
		error("Wrong day!");
	}
	else
	{
		d = d0;
	}
	if (m0 < 1 || m0 > 12)
	{
		error("Wrong month");
	}
	else
	{
		m = m0;
	}
	if (y0 < 1800 || y0 > 2200)
	{
		error("Wrong year");
	}
	else
	{
		y = y0;
	}
}

void Date::add_day(int n)
{
	if (m == 12 && d == 31)
	{
		y++;
		m = 1;
		d = 1;
	}
	if (d == 31)
	{
		m++;
		d = 1;
	}
	else
	{
	
		d = d + n;
	}
}
*/

/*9.7.1
Date::Date(int y0, Month m0, int d0)
{
	if (d0 < 1 || d0 > 31)
	{
		error("Wrong day!");
	}
	else
	{
		d = d0;
	}
	if (m0 < Month::Jan || m0 > Month::Dec)
	{
		error("Wrong month");
	}
	else
	{
		m = m0;
	}
	if (y0 < 1800 || y0 > 2200)
	{
		error("Wrong year");
	}
	else
	{
		y = y0;
	}
}

Month operator++(Month& m)
{
	m = (m == Month::Dec) ? Month::Jan : Month(int(m)+1);
	return m;
}


void Date::add_day(int n)
{
	if (m == Month::Dec && d == 31)
	{
		y++;
		m = Month::Jan;
		d = 1;
	}
	if (d == 31)
	{
		m++;
		d = 1;
	}
	else
	{
	
		d = d + n;
	}
}
*/

/*9.7.4
Date::Date(int y0, Month m0, int d0)
{
	if (d0 < 1 || d0 > 31)
	{
		error("Wrong day!");
	}
	else
	{
		d = d0;
	}
	if (m0 < Month::Jan || m0 > Month::Dec)
	{
		error("Wrong month");
	}
	else
	{
		m = m0;
	}
	if (y0 < 1800 || y0 > 2200)
	{
		error("Wrong year");
	}
	else
	{
		y = y0;
	}
}

Month operator++(Month& m)
{
	m = (m == Month::Dec) ? Month::Jan : Month(int(m)+1);
	return m;
}


void Date::add_day(int n)
{
	if (m == Month::Dec && d == 31)
	{
		y++;
		m = Month::Jan;
		d = 1;
	}
	if (d == 31)
	{
		m++;
		d = 1;
	}
	else
	{
	
		d = d + n;
	}
}
*/

/*
ostream& operator<<(ostream& os, Date& dd)
{
	return os << '(' << dd.year()
		      << ',' << int(dd.month())
              << ',' << dd.day() << ')';
}
*/

int main()
{
	/*
	X var;
	var.m = 7;
	int x = var.mf(9);
	Date today = {2017,02,13};
	today.y = 2017;
	today.m = 02;
	today.d = 13;
	*/

	/*
	Month m = Month::Feb;

	Date d (2000, Month::Jan, 1);
	const Date cd (2001, Month::Jan, 2);
	cout << d.day() << "—" << cd.day() << endl;
	d.add_day(1);
	*/
	//.add_day(1);

	/*9.4.1
	try
	{
		Date today;
		init_day(today, 1963, 5, -19);
		Date tomorrow = today;
		add_day(tomorrow, 1);
		cout << today;
		cout << tomorrow;
	}
	catch(exception& e)
	{
		cerr << "exception: " << e.what() << endl;
	}
	*/
	/*9.4.2
	try
	{
		Date today(1963, 5, 21);
		Date tomorrow = today;
		tomorrow.add_day(1);
		cout << today << endl;
		cout << tomorrow << endl;
	}
	catch(exception& e)
	{
		cerr << "exception: " << e.what() << endl;
	}
	*/

	/*9.4.3
	try
	{
		Date today(1963, 5, 21);
		Date tomorrow = today;
		tomorrow.add_day(1);
		cout << today << endl;
		cout << tomorrow << endl;
	}
	catch(exception& e)
	{
		cerr << "exception: " << e.what() << endl;
	}
	*/


	/*9.7.1
	try
	{
		Date today(1963, Month::May, 21);
		Date tomorrow = today;
		tomorrow.add_day(1);
		cout << today << endl;
		cout << tomorrow << endl;
	}
	catch(exception& e)
	{
		cerr << "exception: " << e.what() << endl;
	}
	*/

	/*9.7.4
	try
	{
		Date today(1963, Month::May, 31);
		Date tomorrow = today;
		tomorrow.add_day(1);
		cout << today << endl;
		cout << tomorrow << endl;
	}
	catch(exception& e)
	{
		cerr << "exception: " << e.what() << endl;
	}
	*/

	/*
	try
	{
		Name_pairs table;
		table.read_names();
		table.read_ages();
		cout << table;
		//table.print();
		table.my_sort();
		cout << table;
		//table.print();
	}
	catch(exception& e)
	{
		cerr << "exception: " << e.what() << endl;
	}*/



}
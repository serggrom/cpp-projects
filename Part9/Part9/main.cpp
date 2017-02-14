#include "../../std_lib_facilities.h"

vector<string> month_tbl;

/*
struct Date
{
	int y;
	int m;
	int d;
	Date(int y, int m, int d);

	void add_day(int n);
};
*/

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

/*
enum Month_simplify 
{
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec 
};
*/

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

void Date::add_day(int n)
{

}

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


Date::~Date()
{
}

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



void init_day(Date& dd, int y, int m, int d)
{

}


void add_day(Date& dd, int y, int m, int d)
{

}



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


	Month m = Month::Feb;

	Date d (2000, Month::Jan, 1);
	const Date cd (2001, Month::Jan, 2);
	cout << d.day() << "—" << cd.day() << endl;
	d.add_day(1);
	//.add_day(1);
}
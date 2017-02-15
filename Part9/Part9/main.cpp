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
		return n;
	}
private:
	int y;
	Month m;
	int n;
};



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

Date::Date(int y, Month m, int d)
{

}

ostream& operator<<(ostream& os, Date& dd)
{
	return os << '(' << dd.year()
		      << ',' << int(dd.month())
              << ',' << dd.day() << ')';
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



}
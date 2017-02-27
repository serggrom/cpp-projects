#include "../../std_lib_facilities.h"
#include "Chrono.h"


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


class ISBN2
{
public:
	ISBN2();
	ISBN2 (int n1, int n2, int n3, char x);
	void input_isbn2();
	int x_1()
	{
		return x1;
	}
	int x_2()
	{
		return x2;
	}
	int x_3()
	{
		return x3;
	}
	char x_x()
	{
		return x;
	}
private:
	int x1;
	int x2;
	int x3;
	char x;
};


void ISBN2::input_isbn2()
{
	cout << "Input the ISBN number: " << endl;
	cin >> x1;
	if (x1 < 0)
	{
		error("ISBN can't be less then 0");
	}
	if (!cin)
	{
		error("Unexpected chars");
	}
	cin >> x2;
	if (x2 < 0)
	{
		error("ISBN can't be less then 0");
	}
	if (!cin)
	{
		error("Unexpected chars");
	}
	cin >> x3;
	if (x3 < 0)
	{
		error("ISBN can't be less then 0");
	}
	if (!cin)
	{
		error("Unexpected chars");
	}
	cin >> x;
	if (!cin)
	{
		error("Unexpected chars");
	}

}


ISBN2::ISBN2(int x1, int x2, int x3, char x)
	:x1(x1), x2(x2), x3(x3), x(x)
{
}


const ISBN2& default_isbn2()
{
	static const ISBN2 number(0, 0, 0, '0');
	return number;
}

ISBN2::ISBN2()
	:x1(default_isbn2().x1),
	 x2(default_isbn2().x2),
	 x3(default_isbn2().x3),
	 x(default_isbn2().x)
{
}


class Book
{
public:
	enum Genre
	{
		none = 0, fiction, periodic, biography, child  
	};
	Book();
	Book(ISBN2 isbn, string title, string last_name, string first_name, 
		Genre genre, bool book_check);
	void find_book();
	void input_book();
	ISBN2 isbn()
	{
		return ISBNum;
	}
	string title()
	{
		return Title;
	}
	string last_name()
	{
		return Last_Name;
	}
	string first_name()
	{
		return First_Name;
	}
private:
	ISBN2 ISBNum;
	string Title;
	string Last_Name;
	string First_Name;
	Genre genre;
	bool where_is_book;
};


/*
Book::Book(ISBN2 isbn0, string title0, string last_name0, string first_name0, 
		Genre genre0, bool book_check0)
{
	if(isbn0.x_1() < 0 || isbn0.x_2() < 0 || isbn0.x_3() < 0)
	{
		error("ISBN can't be less then 0");
	}
	ISBNum = isbn0;
	Title = title0;
	Last_Name = last_name0;
	First_Name = first_name0;
	genre = genre0;
	where_is_book = book_check0;
}
*/

Book::Book(ISBN2 isbn0, string title0, string last_name0, string first_name0, 
		Genre genre0, bool book_check0)
		:ISBNum(isbn0), Title(title0), Last_Name(last_name0), First_Name(first_name0),
		genre(genre0), where_is_book(book_check0)
{
}

const Book& default_book()
{
	static const Book bb (ISBN2::ISBN2(), "", "", "", Book::Genre::none, 0);
	return bb;
}

Book::Book()
	:ISBNum(default_book().ISBNum),
	Title(default_book().Title),
	Last_Name(default_book().Last_Name),
	First_Name(default_book().First_Name),
	genre(default_book().genre),
	where_is_book(default_book().where_is_book)
{
}


void Book::input_book()
{
		
		cout << "Input info about book in the database:" << endl;
		ISBN2 A;
		A.input_isbn2();
		ISBNum = A;
		cout << "Input the title of book: " << endl;
		cin >> Title;
		if (!cin)
		{
			error("Unexpected chars");
		}

		cout << "Input the Author First Name: " << endl;
		cin >> First_Name;
		if (!cin)
		{
			error("Unexpected chars");
		}

		cout << "Input the Author Last Name: " << endl;
		cin >> Last_Name;
		if (!cin)
		{
			error("Unexpected chars");
		}

		cout << "Input the book's Genre"
			    "[none = 0, fiction = 1, periodic = 2, biography = 3, child = 4]: " << endl;
		int genre0;
		cin >> genre0;
		if (!cin)
		{
			error("Unexpected chars");
		}
		/*
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
		*/


}



void Book::find_book()
{
	cout << "Does " << ISBNum.x_1() << "-" << ISBNum.x_2() << "-" << ISBNum.x_3() << "-" << ISBNum.x_x() 
		 << " " << Title << " book in the library?(Input 'Yes' or 'No')?\n";
	string ans;
	cin >> ans;
	if (!cin)
	{
		error("Unexpected chars");
	}
	if (ans == "Yes")
	{
		where_is_book = true;
	}
	else if (ans == "No")
	{
		where_is_book = false;
	}
}



bool operator==(ISBN2& a, ISBN2& b)
{
	return a.x_1() == b.x_1() && a.x_2() == b.x_2()
		&& a.x_3() == b.x_3() && a.x_x() == b.x_x();
}


bool operator!=(ISBN2& a, ISBN2& b)
{
	return !(a == b);
}


ostream& operator<<(ostream& os, Book& a)
{
	return os << "Title:" << a.title() << "\n" 
		      << "Author name: " << a.first_name() << " " << a.last_name() << "\n"
			  << "ISBN: " << a.isbn().x_1() << "-" << a.isbn().x_2() << "-" << a.isbn().x_3() << "-" << a.isbn().x_x() << "\n";
}


class Patron
{
public:
	Patron();
	Patron(string name, int card_number, double pay, bool pay_compl);
	string name()
	{
		return Name;
	}
	int card_number()
	{
		return Card_Number;
	}
	double pay()
	{
		return Pay;
	}
	bool pay_compl()
	{
		return Pay_Compl;
	}
	void check_pay();
	void add_patron();
private:
	string Name;
	int Card_Number;
	double Pay;
	bool Pay_Compl;
};

const Patron& default_patron()
{
	static const Patron pp ("", 0, 0, 0);
	return pp;
}


Patron::Patron()
	:Name(default_patron().Name),
	Card_Number(default_patron().Card_Number),
	Pay(default_patron().Pay),
	Pay_Compl(default_patron().Pay_Compl)
{
}





Patron::Patron(string name0, int card_number0, double pay0, bool pay_compl0)
{
	Name = name0;
	if (card_number0 < 0)
	{
		error("Card number can't be less then 0");
	}
	Card_Number = card_number0;
	if (pay0 < 0)
	{
		error("Pay can't be less then 0");
	}
	Pay = pay0;
	Pay_Compl = pay_compl0;
}



void Patron::add_patron()
{
	cout << "Input info about patron.\n"
		 << "Please, input patron name: ";
	cin >> Name;
    if (!cin)
	{
		error("Unexpected chars");
	}
	cout << "Please, input card number: ";
	cin >> Card_Number;
	if (!cin)
	{
		error("Unexpected chars");
	}
	cout << "Please, input fee: ";
	cin >> Pay;
	cout << "Please, input 'Yes', if fee was payed, or 'No' if fee not payed: ";
	string check;
	cin >> check;
	if (!cin)
	{
		error("Unexpected chars");
	}
	if (check == "Yes")
	{
		Pay_Compl = true;
	}
	else if (check == "No")
	{
		Pay_Compl = false;
	}

}

void Patron::check_pay()
{
	cout << "Was fee payed by patron " << Name << " ?";
    cout << "Please, input 'Yes', if fee was payed, or 'No' if fee not payed: ";
	string check;
	cin >> check;
	if (!cin)
	{
		error("Unexpected chars");
	}
	if (check == "Yes")
	{
		Pay_Compl = true;
	}
	else if (check == "No")
	{
		Pay_Compl = false;
	}
}



class Library
{
public:
	struct Transaction
	{
		Book b;
		Patron p;
		Chrono::Date d;
	};
	void Patrons_With_Debts(vector<Patron>& lib_patrons);
private:
	vector<Book> lib_books;
	vector<Patron> lib_patrons;
	vector<Transaction> lib_transaction;
	vector<string> patrons_with_debts;
};


void Library::Patrons_With_Debts(vector<Patron>& lib_patrons)
{
	for (int i = 0; i < lib_patrons.size(); ++i)
	{
		if (lib_patrons[i].pay_compl() == false)
		{
			cout << "Error: patron " << lib_patrons[i].name() << " did not pay fees!\n";
			patrons_with_debts.push_back(lib_patrons[i].name());
		}
		else
		{
			Transaction A;
			A.p = lib_patrons[i];
			lib_transaction.push_back(A);
		}
	}
}

enum Monthes
{
	Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
};

Monthes operator++(Monthes& m)
{
	if (m == Monthes::Dec)
	{
		m = Monthes::Jan;
	}
	else
	{
		Monthes(int(m)+1);
	}
	return m;
}

class Date_unix
{
public:
	Date_unix(int y, Monthes m, int d);
	Date_unix();
	void convert_date_to_unix();
	long int uni_days()
	{
		return unix_days;
	}
private:
	long int unix_days;
	int y;
	Monthes m;
	int d;
};



Date_unix::Date_unix(int y0, Monthes m0, int d0)
	:y(y0), m(m0), d(d0)
{
	if (y < 1970 && d < 1)
	{
		error("Input wrong year or day, pls input positive numbers");
	}
}


const Date_unix& default_date_unix()
{
	static const Date_unix dd_uu(1970, Monthes::Jan, 1);
	return dd_uu;
}

Date_unix::Date_unix()
	:y(default_date_unix().y),
	m(default_date_unix().m),
	d(default_date_unix().d)
{
	if (y < 1970 && d < 1)
	{
		error("Input wrong year or day, pls input positive numbers");
	}
}

bool leapyear(int y)
{
	return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

void Date_unix::convert_date_to_unix()
{
	unix_days = 0;
	for (int y0 = 1970; y0 < y; ++y0)
	{
		if (leapyear(y))
		{
			unix_days += 366;
		}
		else
		{
			unix_days += 365;
		}
	}
	/*
	for (Monthes m0 = Monthes::Jan; m0 < m; ++m0)
	{
		switch (m0)
		{
		case Monthes::Jan: case Monthes::Mar: case Monthes::May: case Monthes::Jul: case Monthes::Aug: case Monthes::Oct: case Monthes::Dec:
			int days_in_month0 = 31;
			unix_days += days_in_month0;
			break;
		case Monthes::Feb:
			int days_in_month1 = 28;
			unix_days += days_in_month1;
			break;
		case Monthes::Apr: case Monthes::Jun: case Monthes::Sep: case Monthes::Nov:
			int days_in_month2 = 30;
			unix_days += days_in_month2;
			break;
		default:
			break;
		}
	}
	*/
	unix_days += d;

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

	/*
	try
	{
		Book database;
		database.input_book();
		database.find_book();
	}
	catch(exception& e)
	{
		cerr << "exception: " << e.what() << endl;
	}
	*/


	try
	{
		Date_unix A(1972, Monthes::Jan, 1);
		A.convert_date_to_unix();
		cout << A.uni_days() << endl;
	}
	catch(exception& e)
	{
		cerr << "exception: " << e.what() << endl;
	}

}
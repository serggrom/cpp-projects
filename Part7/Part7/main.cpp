/*
Эта программа реализует основные выражения калькулятора.

Ввод о существляется из потока cin ; вывод - в поток cout .

Грамматика для ввода :


Инструкция :
	Выражение
	Вывод
	Выход

Вывод : 
=

Выход :
=


Выражение :
	Терм
	Выражение + Терм
	Выражение - Терм

Терм:
	Первичное_выражение
	Терм * Первичное_выражение
	Терм / Первичное_выражение
	Терм % Первичное_ выражение
	
Первичное_выражение :
	Число
	Выражение )
	- Первичное_выражение
	+ Первичное_выражение

Число :
	Литерал_с_плавающей_ то чкой

	
	
Ввод из потока cin через Token_stream с именем ts.


*/












#include "../../std_lib_facilities.h"




const char number = '8';
const char qiut = 'x';
const char print = ';';
const char name = 'a';
const char let = 'L';

const string prompt = "> ";
const string result = "= ";
const string delckey = "let";


int fact (int N)
{
	if (N<0)
	{
		error("input number must be positive.\n");
	}
	if (N==0)
	{
		return 1;
	}
	else 
	{
		int curr = 1;
		for (int i = 1; i <= N; i++)
		{
			curr *= i;
			
		}
		return curr;
	}
}

double my_sqrt(double n)
{
	if (n<0)
	{
		error("input number must be positive");
	}
	else
	{
		return sqrt(n);
	}
}



class Token {
public:
	char kind; 
	double value;
	string name;
	Token (char ch)
		:kind(ch), value(0) { }
	Token (char ch, double val)
		:kind(ch), value(val) { }
	Token (char ch, string n):kind(ch), name(n) { }
};

class Token_stream
{
public:
	Token_stream();
	Token get();
	void putback (Token t);
	void ignore (char c);
private:
	bool full;
	Token buffer;

};

Token_stream::Token_stream()
	:full(false), buffer(0)
{
}

void Token_stream::putback(Token t)
{
	if (full)
	{
		error("putback() into a full buffer\n");
	}
	buffer = t;
	full = true;
}

Token Token_stream::get()
{
	if (full)
	{
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;

	switch (ch)
	{
	case qiut:
	case print:
	case '{': case '}': case '(': case ')':
	case '+': case '-': case '!': case '*': case '/': case '$':
	case '@':
		return Token(ch);
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
		{
			cin.putback(ch);
			double val;
			cin >> val;
			//return Token ('8',val);
			return Token (number,val);
		}
	default:
		if (isalpha(ch))
		{
			cin.putback(ch);
			string s;
			s += ch;
			//cin >> s;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch)))
			{
				s += ch;
			}
			cin.putback(ch);
			if (s == delckey)
			{
				return Token(let);
			}
			return Token(name,s);
		}
		error("Bad token\n");
	}
}

void Token_stream::ignore(char c)
{
	//Проверяем буфер:
	if (full && c == buffer.kind)
	{
		full = false;
		return;
	}
	full = false;

	//Проверяем входные данные:
	char ch = 0;
	while (cin >> ch)
	{
		if (ch == c)
		{
			return;
		}
	}
}

Token_stream ts;

double expression();


double primary()
{
	Token t = ts.get();
	switch (t.kind)
	{
	case '(':
		{
			double d = expression();
			t = ts.get();
			if (t.kind != ')')
			{
				error("need a ')'\n");
			}
			return d;
		}
		case '{':
		{
			double d = expression();
			t = ts.get();
			if (t.kind != '}')
			{
				error("need a '}'\n");
			}
			return d;
		}
	case number:
		return t.value;
	case '-':
		return - primary();
	case '+': 
		return primary();
	default:
		error("need a primary expression!\n");
	}
}

double term()
{
	double left = primary();
	Token t = ts.get();
	while (true)
	{
		int f = 0;
		switch (t.kind)
		{
		case '!':
			f = left;
			left = fact(f);
			t = ts.get();
			break;
		case '$':
			f = left;
			left = my_sqrt(f);
			break;
		case '*':
			left *= primary();
			t = ts.get();
			break;
		case '/':
			{
				double d = primary();
				if (d==0)
				{
					error("divide by zero\n");
				}
				left /= d;
				t = ts.get();
				break;
			}
		case '%':
			{
				
				double d = primary();
				if (d == 0)
				{
					error("%: divide by zero!\n");
				}
				left = fmod(left, d);
				/*
				int i1 = narrow_cast<int>(left);
				int i2 = narrow_cast<int>(primary());
				if (i2 == 0) 
				{
					error("%: divide by zero\n");
				}
				left = i1 % i2;
				*/
				t = ts.get();
				break;
			}
		default:
			ts.putback(t);
			return left;

		}
	}
}



double expression()
{
	double left = term();
	Token t = ts.get();
	while (true)
	{
		switch (t.kind)
		{
		case '+':
			left += term();
			t = ts.get();
			break;
		case '-':
			left -= term();
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}

}



class Variable
{
public:
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) {}
	
	//Variable();
	//~Variable();

//private:

};

/*
Variable::Variable()
{
}

Variable::~Variable()
{
}
*/
vector <Variable> var_table;


double get_value(string s)
{
	// Возвращает значение переменной с именем s
	for (const Variable& v : var_table)
	{
		if (v.name == s)
		{
			return v.value;
		}
	}
	error("get: undefined variable ", s);
}


void set_value(string s, double d)
{
	// Присваивает объекту s типа Variable значение d
	for (Variable& v : var_table)
	{
		if (v.name == s)
		{
			v.value = d;
			return;
		}
	}
	error("set: undefined variable ", s);
}

bool is_declared(string var)
	// Есть ли переменная var в векторе var_table?
{
	for (const Variable& v: var_table)
	{
		if (v.name == var)
		{
			return true;
		}
	}
}


double define_name(string var, double val)
	// Добавляем пару (var, val) в вектор var_table
{
	if (is_declared(var))
	{
		error(var, " повторное объявление\n");
	}
	var_table.push_back(Variable(var, val));
	return val;
}


double declaration()
{
	Token t = ts.get();
	if (t.kind != name)
	{
		error("Declaration expect name of variable\n");
	}
	string var_name = t.name;

	Token t2 = ts.get();
	if (t2.kind != '=')
	{
		error("Missing symbol = in declaration", var_name);
	}

	double d = expression();
	//define_name(var_name, d);
	var_table.push_back(Variable(var_name, d));
	return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind)
	{
	case let:
		return declaration();
	default:
		ts.putback(t);
		return expression();
	}
}



 void clean_up_mess()
 {
	 ts.ignore(print);
	 /* first example of function
	 while (true)
	 {
		 Token t = ts.get();
		 if (t.kind == print)
		 {
			 return;
		 }
	 }
	 */
 }

 void calculate()
 {
	double val = 0;
		while (cin)
		{
			try
			{
				cout << prompt;
				Token t = ts.get();
				/*
				while (t.kind == ';')
				{
					t = ts.get();
				}
				if (t.kind == 'q')
				{
					keep_window_open();
					return 0;
				}
				ts.putback(t);
				cout << '=' << expression() << '\n';
				*/
			
				if (t.kind == qiut)
				{
					cout << result << val << "\n";
					break;
				}
				if (t.kind == print)
				{
					cout << result << val << "\n";
				}
				else 
				{
					ts.putback(t);
				}
				val = expression();
			}
			catch (exception& e)
			{
				cerr << e.what() << "\n";
				clean_up_mess();
			}
		}
 }



int main()
{
	try
	{
		//define_name("pi", 3.1415926535);
		//define_name("e", 2.7182818284);


		cout << "Welcome to the calculator programm!"
			 << " You can input numbers with floating point.\n"
			 << "For print results press ';'. For exit press 'x'.\n";
		calculate();
		keep_window_open();
		return 0;
		
	}
	catch (runtime_error& e)
	{
		cerr << e.what() << "\n";
		//keep_window_open();
		cout << "Please, input the '~' for windwow closing.\n";
		char ch;
		for (char ch; cin >> ch;)
			if (ch == '~')
			{
				return 1;
			}
	}
	
	catch (...)
	{
		cerr << "exception\n";
		keep_window_open();
		return 2;
	}
}

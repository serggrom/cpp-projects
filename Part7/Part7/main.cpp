#include "../../std_lib_facilities.h"

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


class Token {
public:
	char kind; 
	double value;
	Token (char ch)
		:kind(ch), value(0) { }
	Token (char ch, double val)
		:kind(ch), value(val) { }
};

class Token_stream
{
public:
	Token_stream();
	Token get();
	void putback (Token t);
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
	case 'x':
	case '=':
	case '{': case '}': case '(': case ')':
	case '+': case '-': case '!': case '*': case '/': case '%':
		return Token(ch);
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
		{
			cin.putback(ch);
			double val;
			cin >> val;
			return Token ('8',val);
		}
	default:
		error("Bad token\n");
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
	case '8':
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
					error("% divide by zero!\n");
				}
				left = fmod(left, d);
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





int main()
{
	try
	{
		cout << "Welcome to the calculator programm!"
			 << " You can input numbers with floating point.\n"
			 << "For print results press '='. For exit press 'x'.\n";
		double val = 0;
		while (cin)
		{
			cout << "> ";
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
			
			if (t.kind == 'x')
			{
				cout << "= " << val << "\n";
				break;
			}
			if (t.kind == '=')
			{
				cout << "= " << val << "\n";
			}
			else 
			{
				ts.putback(t);
			}
			val = expression();
		}
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

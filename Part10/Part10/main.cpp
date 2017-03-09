#include "../../std_lib_facilities.h"



void skip_to_int()
{
	if (cin.fail())
	{
		cin.clear();
		for(char ch; cin >> ch;)
		{
			if(isdigit(ch) || ch == '-')
			{
				cin.unget();
				return;
			}
		}
	}
}


int get_int()
{
	int n = 0;
	while (true)
	{
		if (cin >> n)
		{
			return n;
		}
		cout << "This is not number" << endl;
		skip_to_int();
	}
}


int get_int(int low, int high)
{
	cout << "Input integer between " << low << " and " << high << endl;
	while (true)
	{
		int n = get_int();
		if(low <= n && n <= high)
		{
			return n;
		}
		cout << "Sorry, " << n << " out of range [" << low << " , " << high << "], please, try again" << endl;
	}
}



int main()
{
	/*
	cout << "Input integer between 1 and 10" << endl;
	int n = 0;
	while (cin >> n)
	{
		if (n >= 1 && n <= 10)
		{
			break;
		}
		cout << "Sorry, " << n << " out of range [1, 10], please, try again" << endl;
	}
	*/

	/*
	cout << "Input integer between 1 and 10" << endl;
	int n = 0;
	while(cin >> n && !(n >= 1 && n <= 10))
	{
		cout << "Sorry, " << n << " out of range [1, 10], please, try again" << endl;
	}
	*/

	/*
	cout << "Input integer between 1 and 10" << endl;
	int n = 0;

	while (true)
	{
		cin >>n;
		if (cin) 
		{
			if (n >= 1 && n <= 10)
			{
				break;
			}
			cout << "Sorry, " << n << " out of range [1, 10], please, try again" << endl;

		}
		else if (cin.fail())
		{
			cin.clear();
			cout << "This is not number, please, try again" << endl;
			for (char ch; cin >> ch && !isdigit(ch);)
			{
	
			}
			if (!cin)
			{
				error("No input");
			}
			cin.unget();
		}
		else 
		{
			error("No input");
		}
	}
	*/

	/*
	cout << "Input integer between 1 and 10" << endl;
	int n = 0;

	while (true)
	{
		cin >>n;
		if (cin) 
		{
			if (n >= 1 && n <= 10)
			{
				break;
			}
			cout << "Sorry, " << n << " out of range [1, 10], please, try again" << endl;
		}
		else
		{
			cout << "This is not number, please, try again" << endl;
			skip_to_int();
		}
	
	
	}
	*/

	int n = get_int(1, 10);
	cout << "n: " << n << endl;


}
















































































































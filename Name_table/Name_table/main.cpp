#include "../../std_lib_facilities.h"

using namespace std;

class Name_value {
public:
	string Name;
	int Score;
	Name_value();
	~Name_value();
};

Name_value::Name_value()
{}

Name_value::~Name_value()
{}



/*
class Token_stream
{
public:
	Token_stream();
	Name_value get();
	void putback (Name_value t);
private:
	bool full;
	Name_value buffer;

};

Token_stream::Token_stream()
	:full(false), buffer(0)
{
}

void Token_stream::putback(Name_value t)
{
	if (full)
	{
		error("putback() into a full buffer\n");
	}
	buffer = t;
	full = true;
}

Name_value Token_stream::get()
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
	case '+': case '-': case '!': case '*': case '/':
		return Name_value(ch);
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
		{
			cin.putback(ch);
			double val;
			cin >> val;
			return Name_value ('8',val);
		}
	default:
		error("Bad token\n");
	}
}
*/

int main()
{
	vector <Name_value> table;
	Name_value nameTable;
	nameTable.Name = "Class";
	nameTable.Score = 1;


	bool check = true;
	while (check)
	{
		cin >> nameTable.Name;
		if (nameTable.Name == "x")
		{
			break;
		}
		cin >> nameTable.Score;
		table.push_back(nameTable);
	}

	vector<Name_value>::iterator it;

	it = table.begin();

	//cout << "Class name = " << it[0].Name << "\n"
		// << "Class count = " << it[0].Score << "\n";
	

	for (int i = 0; i<table.size(); i++)
	{
		Name_value nameTable2 = table[i];
		cout << "Class name = "<< nameTable2.Name << "\n" 
			 << "Class count = "<<nameTable2.Score << "\n";
	}

	getchar();
	return 0;
	/*
	while (cin)
	{
		if (nameTable.Name == "x")
		{
			break;
		}
		/*
		if (nameTable.Name == "p")
		{
			table.push_back(nameTable);
			for (int i = 0; i < table.size(); i++)
			{
				cout << table[i] << "\n";
			}
		}
		
	cin >> nameTable.Name;
	cin >> nameTable.Score;
	table.push_back(nameTable);
	cout << table.Name << "\n";
	}
	*/
}

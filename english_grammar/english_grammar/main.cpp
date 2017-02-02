#include "../../std_lib_facilities.h"
//#include <sstream>

using namespace std;

/*
int method1 (int a, int n)
{
	int p = 0;
	if (n == 0)
	{
		p = 1;
	}
	else if (n % 2 == 0)
	{
		p = method1(a, n/2) * method1(a, n/2); 
	}
	else
	{
		p = method1(a, n-1) * a;
	}
	return p;
}


int method2 (int a, int n)
{
	int p = 1;
	if (n == 0)
	{
		p = 1;
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			p *= a;
		}
	}
	return p;
}
*/


int main()
{
	string InputSentence = " ";
	cout << "Please, input the sentence in English\n";
	getline(cin, InputSentence);
	/*
	int A, N;
	cout << "Input 2 integers\n";
	cin >> A >> N;
	int answ = method1(A, N);
	int answ2 = method2(A, N);
	cout << "Result: " << answ << "\n";
	cout << "Result: " << answ2 << "\n";
	*/
	int n = InputSentence.length();
	cout << "Size of inputed string: " << n << "\n";
	cout << InputSentence << "\n";
	char n3 = InputSentence[n-3];
	char n2 = InputSentence[n-2];
	char n1 = InputSentence[n-1];
	if ( n3 == ' ' && n2 == '.'
		&& n1 == ' ')
	{
		cout << "This is a correct end of the sentence!\n" ;
	}














}
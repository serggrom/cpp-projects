// ComPortProject.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../../std_lib_facilities.h"
#include "SerialGate.h"
#include <conio.h>
#include <windows.h>


int _tmain(int argc, _TCHAR* argv[])

{
	cout << "Hello!\n";

	cout << "Detect all COM ports in system\n";

	SerialGate sg;

	PortInfo pi;

	sg.GetPortsInfo(&pi);

	printf("Total COM ports: %d\n\n", pi.koll);
	//cout << "Total COM ports: %d" << pi.koll << "\n";

	for (int i = 0; i < pi.koll; i++)
	{
		if (pi.p[i].Availbl == true)
		{
			printf("COM%d - free\n", pi.p[i].Id);
			//cout << "COM" << pi.p[i].Id << " - free\n";
		}
		else 
		{
			printf("COM%d - inaccessible\n", pi.p[i].Id);
			//cout << "COM" << pi.p[i].Id << " - inaccessible\n";
		}
	}

	cout << "Choose ports\n";

	_getch();
}


// ComPortProject.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../../std_lib_facilities.h"
#include "SerialGate.h"
#include <conio.h>
#include <windows.h>

int UserChoosePort = 0;
int dwBytesRead = 0;



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

	cout << "Choose port from free ports\n";
	cout << "Please, input port number like 1 or any number.\n";
	cin >> UserChoosePort;
	int rate = 9600;
	bool Port = sg.Open(UserChoosePort, rate);
	if (Port == false)
	{
		cout << "Open Error.\n";
	}
	else
	{
		cout << "Port open successfully\n";
	}

	cout << "Press key to send command to COM port\n";
	cout << "Press '#' to exit\n";

	while (true)
	{
		/*
		char WriteBuffer[20];
		fgets(WriteBuffer, 20, stdin);

		for(int i = 0; i < sizeof(WriteBuffer); i++)
		{
			if (WriteBuffer[i] == '#')
			{
				cout << "End of sendind\n";
				break;
			}
		}
		*/

		char c = _getch();
		printf("%c", c);

		sg.Send(&c, sizeof(c));

		cout << "\n" << sizeof(c) << " bytes sended.\n";

		if (c == '#')
		{
			break;
		}

		cout << "\nGet data from COM port every 0.01 sec.\n";

		bool terminate = false;
		char ReadBuffer[20];


		while(!terminate)
		{
			Sleep(10);
			dwBytesRead = sg.Recv(ReadBuffer, sizeof(ReadBuffer));

			for (int i = 0; i < dwBytesRead; i++)
			{
				printf("%c", ReadBuffer[i]);
				if (ReadBuffer[i] == '#')
				{
					terminate = true;
					break;
				}
			}
		}




		
	}







	
	//_getch();
}


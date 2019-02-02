#include <iostream>
#include <Windows.h>

int Modules(int iN, int iMod)
{
	int iQ = (iN / iMod);
	return iN - (iQ*iMod);
}

char GetChar(int iGenerator, char cBase, int  iRange)
{
	return (cBase + Modules(iGenerator, iRange));
}


int main()
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 2);


	char caRow[80];
	int j = 7;
	int k = 2;
	int l = 5;
	int m = 1;


	while (true)
	{
		int i = 0;

		// Output a random row of characters
		while (i < 80) {
			if (caRow[i] != ' ') {
				caRow[i] = GetChar(j + i * i, 33, 30);
				if (((i*i + k) % 71) == 0) {
					SetConsoleTextAttribute(hConsole, 7);
				}
				else {
					SetConsoleTextAttribute(hConsole, 2);
				}
			}
			std::cout << caRow[i];
			++i;
			SetConsoleTextAttribute(hConsole, 2);
		}
		j = (j + 31);
		k = (k + 17);
		l = (l + 47);
		m = (m + 67);
		caRow[Modules(j, 80)] = '-';
		caRow[Modules(k, 80)] = ' ';
		caRow[Modules(l, 80)] = '-';
		caRow[Modules(m, 80)] = ' ';
		// Delay
		Sleep(20);
	}
}
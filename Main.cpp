#include <iostream>
#include <windows.h>

using namespace std;
bool loop = true;
int px = 10, py = 12;
char input;
bool up;
int main()
{
	char** wall = new char* [15];
	do {
		for (int i = 0; i < 15; i++)
			wall[i] = new char[15];
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				if (j == 0)
					**wall = '|';
				else if (j == 14)
					**wall = '|';
				else if (i == 0)
					**wall = '-';
				else if (i == 14)
					**wall = '-';
				else if (j == px && i == py)
					**wall = 'V';
				else if (GetAsyncKeyState(VK_ESCAPE)) {
					loop = false;
				}
				else if (GetAsyncKeyState(VK_UP) && py > 1) {
					up = true;
				}
				else
					**wall = '*';
				while (up == true && py > 1) {
					py -= 1;
					cout << **wall << ' ';
					cout << ' ';
				}
				cout << **wall << ' ';
				cout << ' ';
			}
			cout << '\n';
		}
		//cin >> input;
		system("CLS");
	} while (loop == true);
	for (int i = 0; i < 15; i++)
		delete[] wall[i];
	delete[] wall;
}
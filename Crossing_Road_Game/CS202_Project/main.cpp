#include "Object.h"

void Typing()
{
	int c;
	int i = 10;
	do {
		gotoxy(i, 10);
		++i;
		c = _getch();
	} while (c != '.');
}

int main()
{
	CVehicle *CC1 = new CCar(1,1);
	CVehicle *CC2 = new CCar(2,2);
	thread seccond(&CVehicle::Move,CC1);
	thread seccond2(&CVehicle::Move, CC2);
	thread first(Typing);
	seccond.join();
	seccond2.join();
	first.join();
	cout << "an di dien";
	return 0;
}
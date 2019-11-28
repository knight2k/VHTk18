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
	CVehicle *CC1 = new CCar;
	thread seccond(&CVehicle::Move,CC1);
	thread first(Typing);
	first.join();
	seccond.join();
	return 0;
}
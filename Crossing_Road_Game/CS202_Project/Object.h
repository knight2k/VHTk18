#pragma once
#ifndef OBJECT_H
#define OBJECT_H
#include "console.h"
#include <chrono>
#include <thread>

using namespace std::this_thread;
using namespace std::chrono;

class CVehicle {
protected:
	int mX,mY;
public:
	CVehicle() {};
	virtual void Move() = 0;
};

class CCar : public CVehicle {
public:
	CCar() :CVehicle() { 
		mX = 1;
		mY = 1;
	};
	void Relocation()
	{
		gotoxy(mX, mY);
		cout << "    ";
		++mX;
		gotoxy(mX, mY);
		cout << "CCar";
	}
	void Move()
	{
		for (int i = 0; i < 100; ++i)
		{
			Relocation();
			sleep_for(nanoseconds(10));
			sleep_until(system_clock::now() + nanoseconds(500000000));
		}
	}
};
#endif // !OBJECT_CAR_H
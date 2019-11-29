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
	CCar(int a,int b) :CVehicle() { 
		mX = a;
		mY = b;
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
		this_thread::sleep_for(seconds(1));
		for (int i = 0; i < 100; ++i)
		{
			Relocation();
			sleep_for(seconds(1));
		}
	}
};
#endif // !OBJECT_CAR_H
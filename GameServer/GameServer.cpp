#include "pch.h"
#include <iostream>
#include "CorePch.h"

#include <thread>
#include <atomic>
#include <mutex>

#include "AccountManager.h"
#include "UserManager.h"

void Func1()
{
	for (int32 i = 0; i < 100; ++i)
	{
		UserManager::instance()->ProcessSave();
	}
}

void Func2()
{
	for (int32 i = 0; i < 100; ++i)
	{
		AccountManager::instance()->ProcessLogin();
	}
}

int main()
{
	thread t1(Func1);
	thread t2(Func2);
    t1;

	t1.join();
	t2.join();

	cout << "Jobs Done" << endl;
}
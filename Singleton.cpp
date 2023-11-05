// Singleton.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <mutex>
#include<thread> 
#include "Singleton.h"
// This is the main DLL file.
using namespace std;


class Singleton {

private:
	Singleton()
	{
		cout << "Object created" << endl;
	}
	static Singleton* instance;
	static mutex m_mutex;

public:
	static Singleton* GetInstance();
	void writeMsg();
};
Singleton* Singleton::GetInstance()
{
	/*if (instance == nullptr)
	{
		lock_guard<mutex> lock(m_mutex);
		if (instance == nullptr)
		{
			return instance = new Singleton();
		}
	}*/
	return instance;
}
void Singleton::writeMsg()
{
	//printf("This is the first Message");
	cout << "This is the first Message" << endl;
}
Singleton* Singleton::instance = new Singleton();
mutex Singleton::m_mutex;

void WriteFun()
{
	Singleton* singletonObj1 = singletonObj1->GetInstance();
	singletonObj1->writeMsg();
}
int main()
{
	//WriteFun();
	thread th1(WriteFun);
	thread th2(WriteFun);
	th1.join();
	th2.join();
	/*Singleton* singletonObj2 = singletonObj2->GetInstance();
	singletonObj2->writeMsg();*/
	return 0;
}































// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

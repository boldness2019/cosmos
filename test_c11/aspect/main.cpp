#include <iostream>
#include <string>
#include <functional>
#include "Timer.hpp"
#include "Aspect.hpp"
using namespace std;

struct AA {
	void Before(int i) {
		cout << "Before from AA: " << i << endl;		
	}
	void After(int i) {
		cout << "After from AA: " << i << endl;		
	}
};

struct BB {
	void Before(int i) {
		cout << "Before from BB: " << i << endl;		
	}
	void After(int i) {
		cout << "After from BB: " << i << endl;		
	}
};

struct CC {
	void Before() {
		cout << "Before from CC: " << endl;		
	}
	void After() {
		cout << "After from CC: " << endl;		
	}
};

struct DD {
	void Before() {
		cout << "Before from DD: " << endl;		
	}
	void After() {
		cout << "After from DD: " << endl;		
	}
};

void GT()
{
	cout << "real GT function " << endl;
}

void HT(int a)
{
	cout << "real HT function: " << a << endl;
}

void foo(int a) {
	cout << "real foo function: " << a << endl;	
}

struct TimeElapsedAspect
{
	void Before(int i)
	{
		m_lastTime = m_t.elapsed();
	}

	void After(int i)
	{
		cout <<"time elapsed: "<< m_t.elapsed() - m_lastTime << endl;
	}

private:
	double m_lastTime;
	Timer m_t;
};

struct LoggingAspect
{
	void Before(int i)
	{
		std::cout <<"entering"<< std::endl;
	}

	void After(int i)
	{
		std::cout <<"leaving"<< std::endl;
	}
};

void TestAop() {
	cout << "std::function bind-----------: " << endl;
	std::function<void(int)> f = std::bind(&HT, std::placeholders::_1);
	cout << "Invoke std::function bind-------------: " << endl;
	Invoke<AA, BB>(std::function<void(int)>(std::bind(&HT, std::placeholders::_1)), 1);
	cout << "Invoke std::function ---------------AA, BB " << endl;
	Invoke<AA, BB>(f, 1);
		
	// function
	cout << "Invoke std::function ---------------CC, DD " << endl;
	Invoke<CC, DD>(&GT);
	cout << "Invoke std::function ---------------AA, BB " << endl;
	Invoke<AA, BB>(&HT, 1);
	
	// lambda	
	cout << "Invoke std::function ---------------lambda " << endl;
	Invoke<AA, BB>([] (int i) {}, 1);
	cout << "Invoke std::function ---------------CC, DD " << endl;
	Invoke<CC, DD>([] {});
}

int main()
{
   TestAop();

	cout <<"-----------------------"<< endl;
	Invoke<LoggingAspect, TimeElapsedAspect>(&foo, 1); //织入方法
	cout <<"-----------------------"<< endl;
	Invoke<TimeElapsedAspect, LoggingAspect>(&foo, 1);
	
   return 0;
}

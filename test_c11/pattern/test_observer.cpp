#include <iostream>
#include <string>
#include "Observer.hpp"
using namespace std;

struct stA {
	int a,b;
	void print(int a, int b) { cout << a << ", "  << b << endl; }
};

void print(int a, int b) { cout << a << ", outer, "  << b << endl; }

int main()
{
	Events<std::function<void(int,int)>> myevent;
	auto key = myevent.Connect(print);
	cout << "function key = "  << key << endl;
	stA t;
	auto lamdakey = myevent.Connect([&t](int a, int b) { t.a = a; t.b = b; });
	cout << "lamda key = "  << lamdakey << endl;
	
	std::function<void(int,int)> f = std::bind(&stA::print, &t, std::placeholders::_1, std::placeholders::_2);
	auto bindkey = myevent.Connect(f);
	cout << "bind key = "  << bindkey << endl;
	int a = 1, b = 2;
	myevent.Notify(a, b);
	myevent.Disconnect(key);
	
    return 0;
}

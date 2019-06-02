#include <iostream>
#include <string>
//#include <functional>
#include "MessageBus.hpp"
using namespace std;

void TestMessageBus() {
	MessageBus bus;
	bus.Attach([](int a) { cout << "no reference" << a << endl; });
	bus.Attach([](int& a) { cout << "lvalue reference" << a << endl; });
	bus.Attach([](int&& a) { cout << "rvalue reference" << a << endl; });
	bus.Attach([](const int& a) { cout << "const lvalue reference" << a << endl; });
	bus.Attach([](int a) { cout << "no reference has return value and key " << a << endl; return a; }, "a");

	// send message
	int i = 2;
	bus.SendReq<void, int>(2);
	bus.SendReq<int, int>(2, "a");
	bus.SendReq<void, int&>(i);
	bus.SendReq<void, const int&>(2);
	bus.SendReq<void, int&&>(2);
	// remove
	bus.Remove<void, int>();
	bus.Remove<int, int>("a");
	bus.Remove<void, int&>();
	bus.Remove<void, const int&>();
	bus.Remove<void, int&&>();	
	// send message
	bus.SendReq<void, int>(2);
	bus.SendReq<int, int>(2, "a");
	bus.SendReq<void, int&>(i);
	bus.SendReq<void, const int&>(2);
	bus.SendReq<void, int&&>(2);
}

int main()
{
	TestMessageBus();
	
   return 0;
}

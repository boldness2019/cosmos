#include <iostream>
#include <string>
//#include <functional>
#include "MessageBus.hpp"
using namespace std;


MessageBus g_bus;
const string Topic = "Drive";

struct Subject {
	void SendReq(const string& topic) {
		g_bus.SendReq<void, int>(50, topic);
	}
};

struct Car {
	Car() {
		g_bus.Attach([this](int speed) { Drive(speed); }, Topic);
	}
	void Drive(int speed) {
		cout << "Car Drive " << speed << endl;
	}
};

struct Bus {
	Bus() {
		g_bus.Attach([this](int speed) { Drive(speed); });
	}
	void Drive(int speed) {
		cout << "Bus Drive " << speed << endl;
	}
};

struct Truck {
	Truck() {
		g_bus.Attach([this](int speed) { Drive(speed); }, Topic);
	}
	void Drive(int speed) {
		cout << "Truck Drive " << speed << endl;
	}
};

void TestBus() {
	Subject subject;
	Car car;
	Bus bus;
	Truck truck;
	subject.SendReq(Topic);
	subject.SendReq("");
	
	g_bus.Remove<void, int>();
	subject.SendReq("");
}

int main()
{
	TestBus();
	
   return 0;
}

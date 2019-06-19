#include <iostream>
#include <string>
#include <functional>
#include "IocContainer1.hpp"
using namespace std;

struct ICar
{
	virtual ~ ICar() {};
	virtual void test() const = 0;	
};

struct Bus : ICar
{
	Bus() {};
	void test() const { std::cout << "Bus:test()" << endl; }
};

struct Car : ICar
{
	Car() {};
	void test() const { std::cout << "Car:test()" << endl; }
};

int main()
{
	IocContainer<ICar> carioc;
	carioc.RegisterType<Bus>("bus");
	carioc.RegisterType<Car>("car");
	
	std::shared_ptr<ICar> bus = carioc.ResolveShared("bus");
	bus->test();
	std::shared_ptr<ICar> car = carioc.ResolveShared("car");
	car->test();
	
	return 0;
}

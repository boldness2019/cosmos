#include <iostream>
#include <string>
#include <functional>
#include "IocContainer2.hpp"
using namespace std;

struct Bus
{
	void test() const { std::cout << "Bus:test()" << endl; }
};

struct Car
{
	void test() const { std::cout << "Car:test()" << endl; }
};

struct Base
{
	virtual void Func(){}
	virtual ~Base(){}
};

struct DerivedB : Base
{
	void Func() override
	{
		cout<< "Call func in DerivedB Func: " <<endl;
	}
};

struct DerivedC : Base
{
	void Func() override
	{
		cout<< "Call func in DerivedC Func: " <<endl;
	}
};

struct DerivedD : Base
{
	void Func() override
	{
		cout<< "Call func in DerivedD Func: " <<endl;
	}
};

struct A
{
	A(Base * ptr) :m_ptr(ptr)
	{		
	}

	void Func()
	{
		cout<< "struct A Func: "<<endl;
		m_ptr->Func();
	}
	
	~A()
	{
		if(m_ptr!=nullptr)
		{
			delete m_ptr;
			m_ptr = nullptr;
		}
	}

private:
    Base * m_ptr;
};

void TestIoc()
{
	IocContainer ioc;
	ioc.RegisterType<A, DerivedB>("B");
	ioc.RegisterType<A, DerivedC>("C");
	ioc.RegisterType<A, DerivedD>("D");
	
	auto c = ioc.ResolveShared<A>("B");
	c->Func();
	auto c1 = ioc.ResolveShared<A>("C");
	c1->Func();


	ioc.RegisterType<Bus>("bus");
	ioc.RegisterType<Car>("car");
	
	auto bus = ioc.ResolveShared<Bus>("bus");
	bus->test();
	auto car = ioc.ResolveShared<Car>("car");
	car->test();	
	
}


int main()
{
	TestIoc();
	
	return 0;
}

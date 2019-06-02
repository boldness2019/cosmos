#include <iostream>
#include <string>
#include <functional>
#include "Ioc.hpp"
using namespace std;

struct IX {
	virtual ~ IX() {}
	
	virtual void g() {}
};

class X: public IX {
public:
	void g() override {
		cout << "It is a test in x. " << endl;		
	}
};

class Y: public IX {
public:
    Y(int a) : m_a(a) {}
	void g() override {
		cout << "It is a test in y : " << m_a << endl;		
	}
	
	int m_a;
};

struct MyStructA {
	MyStructA(IX * x) : m_x(x) {	
	}
	~ MyStructA() {
		if (m_x != nullptr) {
			delete m_x;
			m_x = nullptr;
		}
	}
	void Func() {
		m_x->g();
	}
private:
    IX * m_x;
};

int main()
{
	IocContainer ioc;
	ioc.RegisterType<MyStructA, X>("A");
	auto pa = ioc.ResolveShared<MyStructA>("A");
	pa->Func();
	
	ioc.RegisterType<MyStructA, Y, int>("A1");
	auto pa1 = ioc.ResolveShared<MyStructA>("A1", 1);
	pa1->Func();
	
   return 0;
}

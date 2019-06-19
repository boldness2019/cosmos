#include <iostream>
#include <string>
#include <functional>
#include "Ioc1.hpp"
using namespace std;

struct Interface
{
	virtual void Func() = 0;
	virtual ~Interface() {}
};

struct DerivedB : public Interface
{
	void Func() override
	{
		cout << "call func in DerivedB " << endl;
	}
};

struct DerivedC : public Interface
{
	void Func() override
	{
		cout << "call func in DerivedC" << endl;
	}
};

void TestIoc()
{
	IocContainer ioc;
	ioc.RegisterType<Interface, DerivedB>("B");
	ioc.RegisterType<Interface, DerivedC>("C");
	
	std::shared_ptr<Interface> pb = ioc.ResolveShared<Interface>("B");
	pb->Func();

	std::shared_ptr<Interface> pc = ioc.ResolveShared<Interface>("C");
	pc->Func();

}

int main()
{
	TestIoc();
	
   return 0;
}

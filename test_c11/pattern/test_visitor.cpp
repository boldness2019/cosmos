#include <iostream>
#include <string>
#include "Visitor.hpp"
using namespace std;

struct stA;
struct stB;

struct Base {
	typedef Visitor<stA, stB> MyVisitor;
	virtual void Accept(MyVisitor&) = 0;
};

struct stA: Base {
	double val;
	void Accept(Base::MyVisitor& v) {
		v.Visit(*this);
	}
};

struct stB: Base {
	int val;
	void Accept(Base::MyVisitor& v) {
		v.Visit(*this);
	}
};

struct PrintVisitor: Base::MyVisitor {
	void Visit(const stA& a) {
		cout << "from stA: "  << a.val << endl;
	}
	void Visit(const stB& b) {
		cout << "from stB: "  << b.val << endl;
	}
};

int main()
{
	PrintVisitor vis;
	stA a;
	a.val = 8.97;
	stB b;
	b.val = 8;
	Base* base = &a;
	base->Accept(vis);
	base = &b;
	base->Accept(vis);	
	
    return 0;
}

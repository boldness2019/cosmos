#include <iostream>
#include <string>
#include "ObjectPool.hpp"
using namespace std;

struct BigObject {
	BigObject() {}
	
	BigObject(int a) {}
	BigObject(const int& a, const int& b) {}
	
	void Print(const string& str) {
		cout << str << endl;
	}
	
};

void Print(shared_ptr<BigObject> p, const string& str) {
	if (p != nullptr) {
		p->Print(str);
	}
}
	
int main()
{
	ObjectPool<BigObject> pool;
	pool.Init(2);
	{
		auto p = pool.Get();
		Print(p, "p");
		auto p2 = pool.Get();
		Print(p2, "p2");
	}
	
	auto p = pool.Get();
	auto p2 = pool.Get();
	Print(p, "p");
	Print(p2, "p2");
		
	pool.Init(2, 1);
	auto p4 = pool.Get<int>();
	Print(p4, "p4");
	
	pool.Init(2, 1, 2);
	auto p5 = pool.Get<int, int>();
	Print(p5, "p5");	
	
	
    return 0;
}

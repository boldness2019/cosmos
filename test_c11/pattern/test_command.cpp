#include <iostream>
#include <string>
#include "Command.hpp"
using namespace std;

struct STA {
	int m_a;
	int operator()() { return m_a; }
	int operator()(int n) { return m_a + n; }
	int triple0() { return m_a * 3; }
	int triple1() const { return m_a * 3; }
	int triple(int a) { return m_a * 3 + a; }
	const int triple2(int a) const { return m_a * 3 + a; }
	void triple3() { cout << "from triple3: " << endl; }
};

int add_one(int n) {
	return n + 1;
}

int main()
{
	CommCommand<int> cmd;
	cmd.Wrap(add_one, 0);
	
	cmd.Wrap([](int n) { return n+1; }, 1);	
	
	//cmd.Wrap(bloop);
	
	STA t = { 10 };
	int x = 3;
	cmd.Wrap(&STA::triple0, &t);
	cmd.Wrap(&STA::triple, &t, x);
	cmd.Wrap(&STA::triple, &t, 3);
	cmd.Wrap(&STA::triple2, &t, 3);
	auto r = cmd.Excecute();
	cout << "from Excecute: " << r << endl;
	
	CommCommand<> cmd1;
	//cmd1.Wrap(Bloop::triple3, &t);
	//cmd1.Excecute();
	
    return 0;
}

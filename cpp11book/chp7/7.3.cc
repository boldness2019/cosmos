
#include <iostream>
#include <type_traits>
using namespace std;

struct A 
{
	int avg;
	A(int a, int b) : avg((a+b)/2) {}
};

typedef aligned_storage<sizeof(A), alignof(A)>::type Aligned_A;

int main()
{
	
	Aligned_A a, b;
	new (&a) A (10,20);
	b =a;
	
   cout << reinterpret_cast<A&>(b).avg << endl;
   
   
   return 0;
}



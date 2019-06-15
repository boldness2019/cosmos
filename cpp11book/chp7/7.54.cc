#include <numeric>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v(4);
	std::iota(v.begin(), v.end(), 1);
	cout << " vector:  ";
	for (auto i: v)
	{
		cout << i << "  ";
	}
	cout << endl;
	
	std::array<int, 4> arr;
	std::iota(arr.begin(), arr.end(), 1);
	cout << " arrray:  ";
	for (auto n: arr)
	{
		cout << n << "  ";
	}
	cout << endl;
   
   return 0;
}

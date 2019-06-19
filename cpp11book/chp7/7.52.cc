
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int> v = {1, 3 , 5, 7, 9, 4};
	auto isEven = [](int i) { return i % 2 == 0; };	
	auto firstEven = std::find_if(v.begin(), v.end(), isEven);	
	cout << "the first even is: " << *firstEven << endl;
	
	auto isNotEven = [](int i) { return i % 2 != 0; };
	auto firstOdd = std::find_if(v.begin(), v.end(), isNotEven);	
	cout << "first odd is Even: " << *firstOdd << endl;
   
	auto odd = std::find_if_not(v.begin(), v.end(), isEven);
	cout << "first odd is Even: " << *odd << endl;
   
   return 0;
}

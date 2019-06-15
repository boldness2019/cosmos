
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int> v = {1,3 , 5, 7, 9};
	auto isEven = [](int i) { return i % 2 != 0; };
	
	bool isallOld = std::all_of(v.begin(), v.end(), isEven);	
	cout << "all is odd: " << isallOld << endl;
	bool isNoneEven = std::none_of(v.begin(), v.end(), isEven);	
	cout << "None is Even: " << isNoneEven << endl;
   
   
	vector<int> v1 = {1,3 , 5, 7, 8, 9};
	bool anyof = std::any_of(v1.begin(), v1.end(), isEven);
	cout << "at least one is Even: " << anyof << endl;
   
   return 0;
}

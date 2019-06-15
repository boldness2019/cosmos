
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int> v = {1, 3 , 5, 7, 9, 4};
	auto result = std::minmax_element(v.begin(), v.end());
	cout << *result.first << " , " << *result.second << endl;
   
   return 0;
}

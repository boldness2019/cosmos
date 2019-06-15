
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int> v = {1, 3 , 5, 7, 9, 4};
	auto pos = std::is_sorted_until(v.begin(), v.end());
	for (auto it=v.begin(); it != pos; ++it) 
	{
		cout << *it << " ";
	}
	cout << endl;
	
	bool is_sort = is_sorted(v.begin(), v.end());
	cout << "is_sort , " << is_sort << endl;
   
   return 0;
}

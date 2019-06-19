
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int> v = {1, 3 , 5, 7, 9, 4};
	vector<int> v1(v.size());
	auto it = std::copy_if(v.begin(), v.end(), v1.begin(), [](int i){ return i % 2 != 0; });
	v1.resize(std::distance(v1.begin(), it));
	for (int i: v1)
	{
		cout << i << "  ";
	}
	cout << endl;
   
   return 0;
}

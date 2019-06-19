
#include <iostream>
#include <string>
using namespace std;

int main() {
   string str = "D:\A\B\test.txt";
   cout << str << endl;
   
   string str1 = "D:\\A\\B\\test.txt";
   cout << str1 << endl;
   
   string str2 = R"(D:\A\B\test.txt)";
   cout << str2 << endl;
   
   return 0;
}



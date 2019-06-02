#include <iostream>
#include <string>
#include "ThreadPool.hpp"

void test_pool()
{
   ThreadPool pool;
   
   std::thread thd1([&pool] {
	   for(size_t i = 0; i < 10; i++) {
		   auto thdId = this_thread::get_id();
		   pool.AddTask([thdId] {
			   cout << "Sync thread 1 for thread id: " << thdId << endl;
               });
	   }	   
   });
   
   std::thread thd2([&pool] {
	   for(size_t i = 0; i < 10; i++) {
		   auto thdId = this_thread::get_id();
		   pool.AddTask([thdId] {
			   cout << "Sync thread 2 for thread id: " << thdId << endl;
               });
	   }	   
   });
   
   std::this_thread::sleep_for(std::chrono::seconds(2));
   
   getchar();
   pool.Stop();
   thd1.join();
   thd2.join(); 
}

int main()
{
   test_pool();

   return 0;
}

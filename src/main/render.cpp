#include <glog/logging.h>
#include <iostream>
int main()
{
	CHECK(1==10);
	std::cout << "sb" << std::endl;
	std::cin.get();
	return 0;
}
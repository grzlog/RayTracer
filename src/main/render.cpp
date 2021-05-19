#include <glog/logging.h>
#include <iostream>
int main()
{
	DCHECK(1==1);
	std::cout << "sb" << std::endl;
	return 0;
}
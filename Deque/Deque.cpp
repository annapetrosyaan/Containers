#include <iostream>

#include "DequeImpl.h"
#include "DequeImpl.hpp"

int main()
{
	Deque<int> container;
	container.push_front(8);
	container.push_front(3);
	container.push_back(2);
	container.push_back(9);

	std::cout << container.size()<<" \n";
	std::cout << container.empty() << " \n";

	std::cout << container[0]<<" \n";

	container.pop_front();
	std::cout << container[0];
}

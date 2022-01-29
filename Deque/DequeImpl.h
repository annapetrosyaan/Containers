#ifndef __DEQUEIMPL__
#define __DEQUEIMPL__

#include <iostream>
#include <vector>
#include <algorithm>

template<class T>
class Deque
{
public:

	Deque()=default;
	~Deque()=default;
public:

	//modifiers
	void push_back(const T&);
	void push_front(const T&);
	void pop_back();
	void pop_front();

	//access
	const T& operator[](int)const;

	//capacity
	bool empty()const;
	int  size()const;

private:
	std::vector <T> first;
	std::vector<T> second;
};

#endif // !__DEQUEIMPL__

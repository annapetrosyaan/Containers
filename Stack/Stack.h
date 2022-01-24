#ifndef _STACK_
#define _STACK_

#include <iostream>
#include <vector>

template<class T>
class Stack
{
public:
	Stack() = default;
	~Stack() = default;
public:
	//element access
	T top();
	//capacity
	bool empty()const;
	int size()const;
	//modifiers
	void push(T);
	void pop();
	void pop(T);
public:
	void print()const;
private:
	std::vector<T> myData;
};

#endif //_STACK
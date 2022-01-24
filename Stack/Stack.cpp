#include "Stack.h"

template<typename T>
T Stack<T>::top()
{
	return myData[myData.size() - 1];
}

template<typename T>
void  Stack<T>::pop()
{
	if (!empty())
	{
	myData.pop_back();
	}
}

template<typename T>
bool Stack<T>::empty()const
{
	return myData.size() == 0;
}

template<typename T>
void Stack<T>::push(T element)
{
	myData.push_back(element);
}

template<typename T>
int Stack<T>::size()const
{
	return myData.size();
}

template<typename T>
void Stack<T>::print()const
{
	for (int i=0; i<myData.size(); ++i)
	{
		std::cout << myData[i]<<" ";
	}
	std::cout << "\n";
}
#include "DequeImpl.h"

//modifiers

template<typename T>
void Deque<T>::push_back(const T& elem)
{
	second.push_back(elem);
}

template<typename T>
void Deque<T>::push_front(const T& elem)
{
	std::reverse(first.begin(), first.end());
	first.push_back(elem);
	std::reverse(first.begin(), first.end());
}

template<typename T>
void Deque<T>::pop_back()
{
	second.pop_back();
}

template<typename T>
void Deque<T>::pop_front()
{
	first.pop_back();
}

//access

template<typename T>
const T& Deque<T>::operator[](int index)const
{
	if (index >= first.size() + second.size())
	{
		std::cout << "Index out of range";
	}
	if (index >= first.size())
	{
		return second[index - first.size()];
	}
	return first[first.size() - index - 1];
}

//capacity

template <typename T>
bool Deque<T>::empty()const
{
	return first.size() == 0 && second.size() == 0 ? true : false;
}

template<typename T>
int Deque<T>::size()const
{
	return first.size() + second.size();
}
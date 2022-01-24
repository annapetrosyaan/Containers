#include "VectorImpl.h"

template<typename T>
MyVector<T>::MyVector() {
	v_cap = 3;
	v_size = 0;
	v_ptr = new T[v_cap];
}

template<typename T>
void MyVector<T>::PushBack(T elem) 
{
	if (v_size == v_cap) 
	{
		v_cap *= 2;
		T* temp = new T[v_cap];
		for (int i = 0; i < v_size; ++i)
		{
			temp[i] = v_ptr[i];
		}
		delete[] v_ptr;
		v_ptr = temp;
	}
	v_ptr[v_size] = elem;
	v_size++;
}

template<typename T>
T MyVector<T>::GetIndex(int index) 
{
	if (index < v_size) {
		return ptr[index];
	}
}

template<typename T>
void MyVector<T>::Insert(T value, int index)
{
	if (index == v_cap)
	{
		PushBack(value);
	}
	else
	{
		ptr[index] = value;
	}
}

template<typename T>
void MyVector<T>::PrintData()
{
	for (int i = 0; i < v_size; ++i) 
	{
		std::cout << ptr[i] << " ";
	}
}

template<typename T>
void MyVector<T>::PopBack() 
{
	v_size--;
}

template<typename T>
int MyVector<T>::Capacity()
{
	return v_cap;
}

template<typename T>
bool MyVector<T>::Empty()
{
	if (v_size == 0) {
		return true;
	}
	return false;
}

template<typename T>
void MyVector<T>::Clear()
{
	v_size = 0;
}

template<typename T>
int MyVector<T>::Size()
{
	return v_size;
}

template<typename T>
void MyVector<T>::ShrinkToFit() {
	if (v_size == v_cap) { return; }
	T* temp = new T[v_size];
	for (int i = 0; i < v_size; ++i) {
		temp[i] =v_ptr[i];
	}
	delete[]v_ptr;
	v_ptr = temp;
	v_cap = v_size;
}

template<typename T>
void MyVector<T>::ReSize(int size, T elem = 0)
{
	if (size < v_size)
	{
		v_size = size;
		return;
	}
	while (v_size < size)
	{
		PushBack(elem);
	}
}

template<typename T>
MyVector<T>::~MyVector() {
	delete[]ptr;
	ptr = nullptr;
}
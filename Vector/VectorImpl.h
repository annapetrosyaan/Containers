#ifndef __VECTORIMPL__
#define __VECTORIMPL__

#include <iostream>

template <typename T>
class MyVector
{
public:
	MyVector();
	~MyVector();
public:
	int Capacity();
	void PushBack(T);
	void PopBack();
	void PrintData()
public:

	int Size();
	bool Empty();
	T GetIndex(int);
	void Insert(T,int);
	void Clear();
	void ShrinkToFit();
	void ReSize(int, T elem=0);

private:
	int v_cap;
	int v_size;
	T* v_ptr;
};

#endif



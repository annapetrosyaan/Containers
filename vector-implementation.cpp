#include <iostream>
template <typename T>
class myVector {
private:
	int v_cap;
	int v_size;
	T* ptr;
  public:
	myVector() {
		v_cap = 3;
		v_size = 0;
		ptr = new T[v_cap];
	}

	void PushBack(T elem) {
		if (v_size == v_cap) {
			v_cap *= 2;
			 T* temp = new T[v_cap];
			for (int i = 0; i < v_size; ++i) {
				temp[i] = ptr[i];
			}
			delete[] ptr;
			ptr = temp;
		}
		ptr[v_size] = elem;
		v_size++;
	}
	T get_index(int index) {
		if (index < v_size) {
			return ptr[index];
		}
		}
	template<typename T>
	void Insert( T value,int index){
		if (index == v_cap) {
			PushBack(value);
	}
		else
		{
			ptr[index] = value;
		}
	}
	void Print_data() {
		for (int i = 0; i < v_size; ++i) {
			std::cout << ptr[i] << " ";
		}
	}
	void Pop_Back() {
		v_size--;
	}
	int capacity() {
		return v_cap;
	}
	bool Empty() {
		if (v_size == 0) {
			return true;
		}
		return false;
	}
	void Clear() {
		v_size = 0;
	}
	int Size() {
		return v_size;
	}
	void ShrinkToFit() {
		if (v_size == v_cap) { return; }
		T* temp = new T[v_size];
		for (int i = 0; i < v_size; ++i) {
			temp[i] = ptr[i];
		}
		delete[]ptr;
		ptr = temp;
		v_cap = v_size;
	}

	void ReSize(int size, T elem = 0) 
	{
		if (size < v_size) 
		{
			v_size = size;
			return;
		}
		while(v_size < size) 
		{
			PushBack(elem);
		}
	}
	  ~myVector(){
		delete[]ptr;
	ptr = nullptr;
	}
}; 



int main() {
	myVector<int>vec;
	myVector<char>vec2;
	vec.PushBack(97);
	vec.PushBack(65);
	vec.PushBack(71);
	vec.PushBack(23);
	vec2.PushBack(65);
	std::cout << " Integers vector elements are   ";
	vec.Print_data();
	std::cout << std::endl;
	std::cout << "Char vector element is   ";
	vec2.Print_data();
	std::cout << std::endl;
	std::cout << "Integer vectors element in 3rd index is=";
	std::cout << vec.get_index(3)<<std::endl;
	vec.Insert(8, 2);
	std::cout << "After inserting value in vectors 2 index" << std::endl;
	std::cout << "Elements are";
	vec.Print_data();
	std::cout << std::endl;
	vec.Pop_Back();
	std::cout << "Ater deleting last element of integer vector"<<std::endl;
	std::cout << "Elements are:";
	vec.Print_data();
	std::cout << std::endl;
	std::cout << "Integer Vectors capacity is=";
	std::cout << vec.capacity()<<std::endl;
	if (vec.Empty()) {
		std::cout << "Integer Vector is empty"<<std::endl;
	}
	else{
		std::cout << "Integer Vector is not empty"<<std::endl;
	}
	vec.ReSize(10, 7);
	vec.Print_data();
	std::cout << std::endl;
	vec.Clear();
	std::cout << "Vectors elements are cleared"<<std::endl;
	std::cout << "now it has " << vec.Size() << " elements" << std::endl;
	return 0;
}

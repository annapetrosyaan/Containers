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
		++v_size;
	}
	T get_i(int index) {
		if (index < v_size) {
			return ptr[index];
		}
	}
	void Print() {
		for (int i = 0; i < v_size; ++i) {
			std::cout << ptr[i] << " ";
		}
	}
	void Pop_Back() {
		v_size--;
	}
	~myVector() {
		delete[]ptr;
		ptr = NULL;
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
	std::cout << " Integers vector elements are   "<<std::endl;
	vec.Print();
	std::cout << std::endl;
	std::cout << "Char vector element is   ";
	vec2.Print();
	std::cout << std::endl;
	std::cout << "Integer vectors element in 3rd index is=";
	std::cout << vec.get_i(3)<<std::endl;
	vec.Pop_Back();
	std::cout << "Ater deleting last element of integer vector"<<std::endl;
	std::cout << "Elements are:";
	vec.Print();
	return 0;
}

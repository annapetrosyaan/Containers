#ifndef __FWDLIST__
#define __FWDLIST__

#include <iostream>
#include <stdexcept>

namespace opt
{

template <class T>
class FwdList 
{
public:
FwdList()=default;
~FwdList() { clear(); }
FwdList& operator=(const FwdList&);
  
public:
//modifiers
void push_front(const T& elem) noexcept;
void pop_front() noexcept;
void insert(const T&, int) noexcept;
void remove_at(int) noexcept;
void clear() noexcept;
void sort() noexcept;
void reverse() noexcept;

public:
void traverse(void(*visit)(const T&)) const;
void print() const;
bool is_empty() const;

protected:
template <typename E>
struct Node
{
E data{};
Node* next{};
Node():data{},next{} {}
explicit Node(const E& elems,Node* ptr): data{elems}, next{ptr} {}
~Node()=default;
};

private:
Node<T>* head{};
size_t size{};
};

#include "FwdList.hpp"

}  //namespace opt

#endif // !__FWDLIST__

#ifndef __FLIST__
#define __FLIST__

#include <iostream> 

namespace opt
{

template <typename D>
struct Node 
{
   explicit Node(const D& value) : data{value},
    next{nullptr}, 
    prev{nullptr}, 
    asc{nullptr},
    desc{nullptr} {}
  D data;
  Node* next; // natural order
  Node* prev;
  Node* asc; // points to next ascending nm
  Node* desc; // to next descending nm 

};
 
template <class T>
class FList 
{
public:
  FList()=default;
  ~FList();
public:
 //insertions
  void push_front(const T&) noexcept;
  void push_back(const T&) noexcept;
  void insert(const T&,const int) noexcept;

public: 
//getters
  void print_asc() const;
  const T get_at(size_t) noexcept;
  size_t size() const;

public:
  void traverse(void(*visit)(const T&)) noexcept;
  void print() const;
  void print_sorted(bool) const;

private:
//sorting helper function
void put_sorted(Node <T>*) noexcept;
void advance(Node <T>*) noexcept;

private:
  Node <T>* f_head{};
  Node <T>* f_tail{};
  Node <T>* f_asc{}; // access nodes in ascending order
  Node <T>* f_desc{}; // access nodes in descending order
  size_t f_size{};

};
    
#include "FList.hpp"

} //namespace opt

#endif // !__FLIST__
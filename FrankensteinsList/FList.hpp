#include "FList.h"

using namespace opt;

template <typename T>
void FList<T>::push_front(const T& value) noexcept
{
  Node <T>* temp = new Node <T>(value);
  temp-> next = f_head;
  if(f_head)
  {
    f_head-> prev = temp;
  } else
    {
     f_tail = temp;
    }
  f_head = temp;
  ++f_size;

   put_sorted(temp);
}

template <typename T>
void FList<T>::push_back(const T& value) noexcept
{
  Node <T>* temp = new Node <T> (value);
  temp-> prev = f_tail;
  if(f_tail)
  {
      f_tail->next = temp;
  } else
    {
      f_head = temp;
    }
  f_tail = temp;
  ++f_size;  

  put_sorted(temp);
}

template <typename T>
void FList<T>::insert(const T& elem, const int index) noexcept
{
  if( index < 0 || index > f_size  )
  {
     abort();
  } if( index == 0 ) 
    {
      push_front(elem);
    } if( index >= f_size )
      {
      push_back(elem);
      }
    Node <T>* temp = new Node <T> (elem); 
    Node <T>* current = f_head;  
    size_t count{};
    while( count != index)
    {
      ++count;
      current = current-> next;
    } 
    current->prev-> next = temp;
    temp-> prev = current-> prev;
    current-> prev = temp;
    temp-> next = current;

    ++f_size;

    put_sorted(temp);
}

template <typename T>
const T FList<T>::get_at(size_t index) noexcept
{
 if(index > f_size)
 {
   std::cout<<"out of range index";
 } 
 Node <T>* current = f_head;
 size_t count{};
 while (count < index)
 {
   current = current-> next;
   ++count;
 }
 advance(current);

 return current-> data;
}

template <typename T>
void FList<T>::traverse(void(*visit)(const T&)) noexcept
{
  Node <T>* current = f_head;
  while(current != nullptr)
  {
    visit(current-> data);
    current-> next;
  }
}

template <typename T>
void FList<T>::print() const
{
  Node <T>* current = f_head;
  
  size_t count = f_size;
  while(count)
  {
    std::cout<< current->data << " ";
    current = current-> next;
    --count;
  }
  std::cout<<std::endl;
}

template <typename T>
size_t FList<T>::size() const
{
    return f_size;
}

 template <typename T>
 void FList<T>::put_sorted(Node<T>* node) noexcept
 {
   if( !f_asc ) 
   {
    f_asc = node;
    f_desc = node;
    return;
   }
   Node <T>* current = f_asc;
   while(current->asc && current-> data < node-> data)
   {
    current =current-> asc;
   }
   if(current-> data < node-> data)
   {
       node-> asc= current-> asc;
       current-> asc = node;
       node-> desc = current;
     if(! node->asc )
     {
       f_desc=node;
     }
   } else 
    {
      node-> desc = current-> desc;
      if( current->desc )
      {
        current-> desc-> asc =node;
      } else
        {
          f_asc=node;
        }
      node-> asc= current;
      current-> desc= node;
    }
 }

 template <typename T>
 void FList<T>::advance(Node <T>* node) noexcept
 {
   if(node == f_head) { return; } 
   Node <T>* left = node->prev;
   Node <T>* right = node->next;
   if(left)
   {
     if(left->prev)
     {
      left-> prev-> next= node;
      node-> prev =left-> prev; 
     }
      left-> prev = node;
      left-> next = right;
      node-> next = left;
   }
  if(right)
  {
    right-> prev = left; 
  }
  if(left == f_head)
  {
    f_head = node;
  }
  if(node == f_tail)
  {
    f_tail = left;
  }
 }

template <class T>
void FList<T>::print_sorted(bool order) const
{
  Node<T>* current = order ? f_asc : f_desc;
  while(current)
  {
    std::cout<< current-> data<<" ";
    current = order ? current-> asc : current-> desc;
  } 
  std::cout<<std::endl;
}

template <class T>
FList<T>::~FList()
{
      Node <T>* current = f_head;
      Node <T>* temp = current;
      while( current )
      {
          temp=current;
          current = temp -> next;
          delete temp;
      }
  }

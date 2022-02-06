#include "FwdList.h"

using namespace opt;

template <typename T> 
FwdList<T>& FwdList<T>::operator=(const FwdList& rhs)
{
 if( this == &rhs )
 {
     return *this;
 }
 clear();
 this->size = rhs.size;
 this->head = new Node<T>(rhs.head->data);
 Node <T>* temp = rhs.head->next;
 Node <T>* current = head;
 while( temp != nullptr )
 {
     current->next = new Node<T>( temp-> data);
     temp= temp-> next;
     current = current-> next;
 }
 return *this;
}

template <typename T>
void FwdList<T>::push_front(const T& elem) noexcept
{
    head = new Node<T>(elem,head);
    size++;
}

template<typename T>
void FwdList<T>::pop_front() noexcept
{
    Node <T>* temp = head;
    head= head -> next;
    delete temp;
    --size;
}

template <typename T>
void FwdList<T>::clear() noexcept
{
    while(size)
    {
        pop_front();
    }
}

template <typename T>
void FwdList<T>::insert(const T& value,int index) noexcept
{
    Node <T>* current = head;
    size_t count{};
    while(count != index )
    {
          ++count;
        current= current-> next;
    }
    Node <T>* temp = new Node<T> (value,current->next);
    current-> next =temp;
    ++size;

}

template <typename T>
void FwdList<T>::remove_at(int pos) noexcept
{
  if( pos < 0 || pos > size  )
  {
     throw std::invalid_argument();
  }
  Node <T>* current= head;
  if (pos > 1)
  {
   current= current->next;
   --pos;
  }
  Node <T>* temp = current->next;
  current-> next= current-> next->next;
  delete temp;
 --size;
}

template<typename T>
void FwdList<T>::sort() noexcept
{
    Node <T>* fst{};
    Node <T>* scnd{};
    T temp;
    for(fst->head; fst->next != nullptr; fst=fst->next)
    {
        for(scnd= fst->next; scnd->next != nullptr; scnd=scnd->next)
        {
            if(fst->data > scnd->data)
            {
                temp= fst-> data;
                fst-> data= scnd-> data;
                scnd-> data = temp;
            }
        }
    }
}

template<typename T>
void FwdList<T>::reverse() noexcept
{
 Node <T>* prev{};
 Node <T>* next2{};
 Node <T> current = head;

  while(current != nullptr)
  {
      next2 =current-> next;
      current-> next =prev;
      prev = current;
      current = next2;
  }
  head = prev;
}

template<typename T>
bool FwdList<T>::is_empty() const
{
    return size== 0 ? true : false;
}

template<typename T>
void FwdList<T>::traverse(void(*visit)(const T&))const
{
    Node <T>* current = head;
    while(current != nullptr)
    {
        visit (current->data);
        current = current-> next;
    }
}

template<typename T>
void FwdList<T>::print() const
{
    Node <T>* current = head;
    while( current != nullptr )
    {
        std::cout<< current-> data <<" ";
        current = current->next;
    }
    std::cout<<std::endl;
}
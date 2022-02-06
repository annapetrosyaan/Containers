#include <iostream>

#include "FwdList.h"

int main()
{
   opt::FwdList<int> obj;
   obj.push_front(1);
   obj.push_front(2);
   obj.push_front(6);
   obj.push_front(5);
   obj.pop_front();
   obj.insert(3,2);
   obj.print();
}
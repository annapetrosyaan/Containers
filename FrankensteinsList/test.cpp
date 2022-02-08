#include <iostream>

#include "FList.h"

int main()
{
 opt::FList <int> list;
 list.push_front(88);
 list.push_back(4);
 list.push_front(21);
 list.insert(34,1);
 list.print();
 list.get_at(3);
 list.print();
 list.print_sorted(true);
}

#include <iostream>

#include "Stack.h"

int main()
{
  Stack<int> stack;
  stack.push(21);
  stack.push(22);
  stack.push(24);
  stack.push(25);

   stack.pop();
   stack.pop();

  while (!stack.empty())
  {
  std::cout << ' ' << stack.top();
  stack.pop();
   }
}

#include <iostream>
int divide(int x, int y)
{
  return x/y;
}

int main()
{
  int div = divide(10, 0); // can't divide by zero
  std::cout << div << std::endl;
  return 0;
}
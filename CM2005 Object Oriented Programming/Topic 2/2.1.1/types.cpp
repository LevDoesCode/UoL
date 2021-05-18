#include <iostream>

int main()
{
  char c = 0;
  std::cout << "char: " << sizeof(char)  << std::endl;

  signed int si = 0;
  std::cout << "signed int: " << sizeof(si)  << std::endl;

  float f = 0.0f;
  std::cout << "float: " << sizeof(f)  << std::endl;

  double d = 0.0;
  std::cout << "double: " << sizeof(d)  << std::endl;

  long double ld = 0.0;
  std::cout << "long double: " << sizeof(ld)  << std::endl;
}
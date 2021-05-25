#include <string>
#include <iostream>

int main()
{
  std::string s = "Matthew";
  std::cout << "Length of the string is " << s.length() << std::endl; // .length is stateful
  // the life of a stateful function ends with the object that it belongs to

  // static or non-stateful function, they use memory and then return it
  std::cout << std::stod("100") << std::endl;
}
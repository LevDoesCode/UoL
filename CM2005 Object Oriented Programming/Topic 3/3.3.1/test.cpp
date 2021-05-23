#include <string>
#include <iostream>

int main()
{
  double d{}; //initializes to 0, dicated by the compiler
  std::string s = "x1.6x";
  try
  {
    d = std::stod(s);
  }
  catch(const std::exception& e)
  {
    //throw e;
    std::cerr << e.what() << '\n';
  }  
  std::cout << "d: " << d << std::endl;
  return 0;
}
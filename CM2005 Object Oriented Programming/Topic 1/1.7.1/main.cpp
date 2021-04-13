#include <iostream>

int difference(int a, int b);

void printHello()
{
  std::cout << "Hello" << std::endl;
}

/** compute the average of x and y**/
float average(float x, float y)
{
  float sum;
  sum = x+y;
  return (x+y)/2;
}

int main()
{
  printHello();
  float a = average(15, 23);
  std::cout << a << std::endl;
  int c = difference(10, 7);
  std::cout << c << std::endl;
  return 0;
}

//This can be compiled adding both files as in
//g++ main.cpp side.cpp
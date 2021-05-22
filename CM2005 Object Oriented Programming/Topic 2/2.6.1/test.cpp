#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Vec3D.h"

Vec3D vec1;

void doSomething()
{
  vec1.x = 10;
  vec1.y = 12;
  vec1.z = 25;
}

int main()
{
  doSomething();
  
  //std::cout << vec1.x << std::endl;
  //std::cout << vec1.size << std::endl;
  std::vector<Vec3D> coords;
  coords.push_back(vec1);
  //std::cout << coords[0].x << std::endl;
  std::cout << coords[0].getLength() << std::endl;
  return 0;
}
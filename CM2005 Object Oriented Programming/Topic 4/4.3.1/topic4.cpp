#include <iostream>
#include <vector>
#include <string>

//using namespace std;

int main()
{
  //vector<string> a;
  std::vector<std::string> strings;
  strings.push_back("one");
  strings.push_back("two");
  strings.push_back("three");
  // we use const because we won't mutate the data in the s variable
  // Because we're only reading, we don't want to create a copy
  // so we use a reference '&' instead
  for (const std::string& s:strings)
  {
    std::cout << s << std::endl;
    std::string lel = "lol";
    //s.append(lel); // we can't use this because s is of type const
  }
}
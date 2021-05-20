#include <iostream>
#include <string>
#include <vector>

enum class Colours{blue, green, red};

int main()
{
    //unsigned short usi=65536;
    signed long sli=65536;

    std::cout << " size of unsigned short: " << sizeof(unsigned short) << std::endl;
    std::cout << " size of unsigned short: " << sizeof(unsigned long) << std::endl;
    std::cout << " size of unsigned short: " << sizeof(int) << std::endl;
    //std::cout << "i contains: " << usi << std::endl;
    std::cout << "i contains: " << sli << std::endl;

    std::cout << "--enum--" << std::endl;

    std::string s = {"hello"};
    Colours col = Colours::red;
    //std::cout << "color is: " << col.toString() << std::endl; this doesn't work
    return 0;
}
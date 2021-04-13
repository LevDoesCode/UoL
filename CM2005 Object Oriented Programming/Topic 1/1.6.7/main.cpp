#include <iostream>
#include <map>

void printMenu()
{
  std::cout << "1: Print help" << std::endl;
  std::cout << "2. Print exchange stats"  << std::endl;
  std::cout << "3: Place an ask" << std::endl;
  std::cout << "4: Place a bid" << std::endl;
  std::cout << "5: Print wallet" << std::endl;
  std::cout << "6: Continue" << std::endl;
  std::cout << "Type in 1-6" << std::endl;
}

int getUserOption()
{
  int userOption;
  std::cin >> userOption;
  return userOption;
}

void processUserOption(int userOption)
{
  if(userOption == 1)
  {
    std::cout << "Pressed 1" << std::endl;
  }
  if(userOption == 2)
  {
    std::cout << "Pressed 2" << std::endl;
  }
  if(userOption == 3)
  {
    std::cout << "Pressed 3" << std::endl;
  }
  if(userOption == 4)
  {
    std::cout << "Pressed 4" << std::endl;
  }
  if(userOption == 5)
  {
    std::cout << "Pressed 5" << std::endl;
  }
  if(userOption == 6)
  {
    std::cout << "Pressed 6" << std::endl;
  }
}

int main()
{
  while(1)
  {
    printMenu();
    int userOption = getUserOption();
    processUserOption(userOption);  
  }
  return 0;
}
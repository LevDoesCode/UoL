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

void printHelp()
{
  std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers. " << std::endl;
}

void printMarketStats()
{
  std::cout << "Market Stats" << std::endl;
}

void enterAsk()
{
  std::cout << "Enter Ask" << std::endl;
}
void enterBid()
{
  std::cout << "Enter Bid" << std::endl;
}

void printWallet()
{
  std::cout << "Wallet" << std::endl;
}

void gotoNextTimeframe()
{
  std::cout << "Next Time Frame" << std::endl;
}

int getUserInput()
{
  int userInput;
  std::cout << "Enter an option: ";
  std::cin >> userInput;
  return userInput;
}

int main ()
{
  // map from ints to function pointers
  std::map<int,void(*)()> menu;
  // connect 1 to the printHelp function
  menu[1] = printHelp;
  menu[2] = printMarketStats;
  menu[3] = enterAsk;
  menu[4] = enterBid;
  menu[5] = printWallet;
  menu[6] = gotoNextTimeframe;

  while(1)
  {
    printMenu();
    int userInput = getUserInput();
    menu[userInput]();
  }
  //menu[0]();
  return 0;
}
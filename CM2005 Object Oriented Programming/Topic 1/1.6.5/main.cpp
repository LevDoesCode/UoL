#include <iostream>

void printMenu()
{
  // 1 print help
  std::cout << "1: Print help" << std::endl;
  // 2 print exchange stats
  std::cout << "2: Print exchange stats" << std::endl;
  // 3 make an offer
  std::cout << "3: Make an offer" << std::endl;
  // 4 make a bid
  std::cout << "4: Make a bid " << std::endl;
  // 5 print wallet
  std::cout << "5: Print wallet " << std::endl;
  // 6 continue
  std::cout << "6: Continue" << std::endl;

  std::cout << "==========" << std::endl;
  std::cout << "Enter an option: " << std::endl;
}

void printHelp()
{
  std::cout << "Help - Your aim is to analyze the market, make bid and offers and make money." << std::endl;
}

void printMarketStats()
{
  std::cout << "Market looks good" << std::endl;
}

void enterOffer()
{
  std::cout << "Make an offer - Enter the amount: " << std::endl;
}

void enterBid()
{
  std::cout << "Make a bid - Enter the amount: " << std::endl;
}

void printWallet()
{
  std::cout << "Your wallet is empty. " << std::endl;
}

void goToNextTimeFrame()
{
  std::cout << "Going to next time frame. " << std::endl;
}

int getUserOption()
{
  int userOption;
  std::cin >> userOption;
  std::cout << "You chose: " << userOption << std::endl;
  return userOption;
}

void processUserOption(int userOption)
{
  if (userOption == 0) // bad input
  {
    std::cout << "Invalid choice. Choose 1-6" << std::endl;
  }

  if (userOption == 1) // Option 1 - Help
  {
    printHelp();
  }

  if (userOption == 2) // Option 2 - Stats
  {
    printMarketStats();
  }

  if (userOption == 3) // Option 3 - Offer
  {
    enterOffer();
  }

  if (userOption == 4) // Option 4 - Bid
  {
    enterBid();
  }

  if (userOption == 5) // Option 5 - Wallet
  {
    printWallet();
  }

  if (userOption == 6) // bad input
  {
    goToNextTimeFrame();
  }
  return;
}

int main(int argc, char const *argv[])
{

  while (true)
  {
    printMenu();
    int userOption = getUserOption();
    processUserOption(userOption);
  }
  return 0;
}

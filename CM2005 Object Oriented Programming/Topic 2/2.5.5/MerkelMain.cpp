#include "MerkelMain.h"
#include <iostream>

MerkelMain::MerkelMain()
{
  MerkelMain::init();
}

void MerkelMain::init()
{
  
}

void MerkelMain::printMenu()
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

void MerkelMain::printHelp()
{
  std::cout << "Help - Your aim is to analyze the market, make bid and offers and make money." << std::endl;
}

void MerkelMain::printMarketStats()
{
  std::cout << "Market looks good" << std::endl;
}

void MerkelMain::enterOffer()
{
  std::cout << "Make an offer - Enter the amount: " << std::endl;
}

void MerkelMain::enterBid()
{
  std::cout << "Make a bid - Enter the amount: " << std::endl;
}

void MerkelMain::printWallet()
{
  std::cout << "Your wallet is empty. " << std::endl;
}

void MerkelMain::goToNextTimeFrame()
{
  std::cout << "Going to next time frame. " << std::endl;
}

int MerkelMain::getUserOption()
{
  int userOption;
  std::cin >> userOption;
  std::cout << "You chose: " << userOption << std::endl;
  return userOption;
}

void MerkelMain::processUserOption(int userOption)
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
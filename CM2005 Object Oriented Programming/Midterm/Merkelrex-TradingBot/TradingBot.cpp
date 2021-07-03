#include "TradingBot.h"

TradingBot::TradingBot(MerkelMain *merkel)
{
  this->merkel = merkel;
}

void TradingBot::startBot()
{
  int input;
  while (input != 8)
  {
    printMenu();
    input = getUserOption();
    processUserOption(input);
  }
  std::cout << "Exiting bot..." << std::endl;
}

void TradingBot::printMenu()
{
  std::string spacer = "================================================================================";
  std::cout << spacer << std::endl;
  std::cout << " Welcome to the Trading Bot | Current time: " + merkel->getCurrentTime() << std::endl;
  std::cout << spacer << std::endl;
  // 1 print help
  std::cout << "1: Retrieve current orders" << std::endl;
  std::cout << "8: Exit bot" << std::endl;
  std::cout << spacer << std::endl;
  return;
  // 2 print exchange stats
  std::cout << "2: Print exchange stats" << std::endl;
  // 3 make an offer
  std::cout << "3: Make an offer " << std::endl;
  // 4 make a bid
  std::cout << "4: Make a bid " << std::endl;
  // 5 print wallet
  std::cout << "5: Print wallet " << std::endl;
  // 6 continue
  std::cout << "6: Continue " << std::endl;
}

int TradingBot::getUserOption()
{
  int userOption = 0;
  std::string line;
  std::getline(std::cin, line);
  try
  {
    userOption = std::stoi(line);
  }
  catch (const std::exception &e)
  {
    std::cout << "Invalid option" << std::endl;
  }
  return userOption;
}

void TradingBot::processUserOption(int userOption)
{
  if (userOption == 0)
    return;
  if (userOption == 1)
  {
    retrieveOrders();
  }
}

void TradingBot::retrieveOrders()
{
  bookAsks.clear();
  bookAsks = merkel->getCurrentAsks();
  bookBids.clear();
  bookBids = merkel->getCurrentBids();std::cout << bookBids[0].product << std::endl;
}

void TradingBot::testFunc()
{
}
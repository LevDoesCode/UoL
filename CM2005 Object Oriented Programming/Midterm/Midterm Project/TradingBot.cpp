#include "TradingBot.h"
#include <iostream>

Bot::Bot(std::string filename)
{
  orders = CSVReader::readCSV(filename);
  Print(20);
}

void Bot::Print(int intLimit)
{
  int i = 0;
  for (OrderBookEntry &entry : orders)
  {
    std::cout << entry.product << " " << entry.price << " " << entry.amount << std::endl;
    i++;
    if (i == intLimit)
      break;
  }
}
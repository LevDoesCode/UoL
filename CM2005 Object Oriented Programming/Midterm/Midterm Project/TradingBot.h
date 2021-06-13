#pragma once

#include "OrderBook.h"
#include <vector>
//#include "CSVReader.h"

class Bot
{
public:
  Bot(std::string filename);
  void Print(int intLimit);

private:
  std::vector<OrderBookEntry> orders;
};
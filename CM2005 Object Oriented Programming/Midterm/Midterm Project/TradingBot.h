#pragma once

#include "OrderBook.h"
#include <vector>
//#include "CSVReader.h"

class Bot
{
public:
  MerkelMain app;
  Bot(MerkelMain app);
  /** returns a vector with the Y, B0 and B1 values in the formula Y = B0 + B1.X */
  std::vector<double> linearRegresion(std::vector<OrderBookEntry> orderList, unsigned int start, unsigned int end);


private:
  double getMean(std::vector<OrderBookEntry>);
  std::vector<std::string> Bot::getTimeStamps();
};
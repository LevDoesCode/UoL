#include <iostream>
#include <string>
#include <vector>
#include "OrderBookEntry.h"

double computeAveragePrice(std::vector<OrderBookEntry>& entries)
{
  double avg = 0;
  for(unsigned int i=0; i<entries.size(); ++i) //thid doesn't create a copy, ++i increments on the same variable
  {
    //std::cout << "The price is " << entries[i].price << std::endl;
    avg += entries[i].price;
  }
  return avg/entries.size();
}

int main()
{

  std::vector<OrderBookEntry> orders;

  orders.push_back( OrderBookEntry{
                                    10000,
                                    0.002,
                                    "2020/03/17 17:01:24.884492",
                                    "BTC/USDT",
                                    OrderBookType::bid});

  orders.push_back( OrderBookEntry{
                                    50000,
                                    0.002,
                                    "2020/03/17 17:01:24.884492",
                                    "BTC/USDT",
                                   OrderBookType::bid});

  std::cout << "Average price: " << computeAveragePrice(orders) << std::endl;
}
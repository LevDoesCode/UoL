#pragma once

#include "OrderBookEntry.h"
#include "CSVReader.h"
#include <string>
#include <vector>

class OrderBook
{
  public:
    /* Construct, reading a csv data file */
    OrderBook(std::string filename);
    /* return vector of all known products in the dataset */
    std::vector<std::string> getKnownProducts();
    /* return vector of Orders according to the sent filters */
    std::vector<OrderBookEntry> getOrders(OrderBookType type, std::string product, std::string timestamp);
    std::string getEarliestTime();
    static double getHighPrice(std::vector<OrderBookEntry>& orderList);
    static double getLowPrice(std::vector<OrderBookEntry>& orderList);
  private:
    std::vector<OrderBookEntry> orders;
};
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
    /** returns earliest time in the order book */
    std::string getEarliestTime();
    /** returns the next time after the sent time in the orderbook
      * If no next timestamp is found, wraps to the start */
    std::string getNextTime(std::string timestamp);
    std::string getPrevTime(std::string timestamp);
    unsigned int getBookSize(); 
    static double getHighPrice(std::vector<OrderBookEntry>& orderList);
    static double getLowPrice(std::vector<OrderBookEntry>& orderList);

    static double getLastPrice(std::vector<OrderBookEntry>& orderList);
    static double getAverage(std::vector<OrderBookEntry>& orderList);
    static double getSpread(std::vector<OrderBookEntry>& bids, std::vector<OrderBookEntry>& asks);
    double getChangePercent(std::vector<OrderBookEntry>& orderList);
    double getChangeNumber(std::vector<OrderBookEntry>& orderList);
  private:
    std::vector<OrderBookEntry> orders;
};

/*
About the Spread
https://www.forex.com/en/markets/forex/
https://www.ig.com/en/trading-strategies/what-is-the-spread-in-forex-and-how-do-you-calculate-it-201126

Percentage variance
https://www.tradingview.com/markets/currencies/rates-major/
*/
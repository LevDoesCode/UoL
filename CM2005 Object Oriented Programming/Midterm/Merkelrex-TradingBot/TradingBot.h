#pragma once

#include "MerkelMain.h" // required to interact with the order book, place bids, withdraw bids, place asks
#include "OrderBookEntry.h" // required to build vectors of this type
#include <string>
#include <iostream>
#include <vector>

class TradingBot
{
  public:
    TradingBot(MerkelMain* merkel);
    void testFunc();
  private:
    MerkelMain* merkel;
    std::vector<OrderBookEntry> bookBids;
    std::vector<OrderBookEntry> bookAsks;
};
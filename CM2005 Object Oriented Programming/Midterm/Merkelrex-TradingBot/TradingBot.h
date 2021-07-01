#pragma once

#include "MerkelMain.h" // required to interact with the order book, place bids, withdraw bids, place asks

class TradingBot
{
  public:
    TradingBot(MerkelMain* merkel);
  private:
    MerkelMain* merkel;
};
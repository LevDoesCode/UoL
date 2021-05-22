#pragma once

#include <vector>
#include "OrderBookEntry.h"

class MerkelMain
{
  public:
    MerkelMain();
  private:
  /* Starts the sim */
    void init();
    void loadOrderBook();
    void printMenu();
    void printHelp();
    void printMarketStats();
    void enterOffer();
    void enterBid();
    void printWallet();
    void goToNextTimeFrame();
    int getUserOption();
    void processUserOption(int userOption);
    std::vector<OrderBookEntry> orders;
};
#pragma once

#include <vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"
#include "Wallet.h"

class MerkelMain
{
public:
    MerkelMain();

    /** Returns the current time */
    std::string getCurrentTime();
    
    /** Returns the list of known products */
    std::vector<std::string> getKnownProducts();
    
    /** returns a vector of all asks orders for the current time */
    std::vector<OrderBookEntry> getCurrentAsks();

    /** returns a vector of all bids orders for the current time */
    std::vector<OrderBookEntry> getCurrentBids();

    void enterAsk();
private:
    void printMenu();
    void printHelp();
    void printMarketStats();

    void enterBid();
    void printWallet();
    void gotoNextTimeframe();
    int getUserOption();
    void init(); // initialization function for user interaction
    void processUserOption(int userOption);

    std::string currentTime;

    OrderBook orderBook{"20200317.csv"};
    //OrderBook orderBook{"20200601.csv"};
    Wallet wallet;
};

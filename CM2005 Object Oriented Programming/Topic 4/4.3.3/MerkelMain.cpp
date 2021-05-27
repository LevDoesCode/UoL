#include "MerkelMain.h"
#include <iostream>
#include <vector>
#include "OrderBookEntry.h"
#include "CSVReader.h"
#include <iomanip>

MerkelMain::MerkelMain()
{
    std::cout << "================================================================================" << std::endl;
}

void MerkelMain::init()
{
    //if(orderBook.orders.size() == 0)
    if(! orderBook.getBookSize() > 0)
    {
        std::cout << "No entries found! Exiting program :(" << std::endl;
        return;
    }
    int input;
    currentTime = orderBook.getEarliestTime();
    while(true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}

void MerkelMain::printMenu()
{
    std::cout << "MENU" << std::endl;
    // 1 print help
    std::cout << "1: Print help " << std::endl;
    // 2 print exchange stats
    std::cout << "2: Print exchange stats" << std::endl;
    // 3 make an offer
    std::cout << "3: Make an offer " << std::endl;
    // 4 make a bid 
    std::cout << "4: Make a bid " << std::endl;
    // 5 print wallet
    std::cout << "5: Print wallet " << std::endl;
    // 6 continue   
    std::cout << "6: Continue " << std::endl;

    std::cout << "====================================================================================================" << std::endl;

    std::cout << "Current Time: " << currentTime << std::endl;
}

void MerkelMain::printHelp()
{
    std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers. " << std::endl;
}

// void setw(int w)
// {
//     std::cout.width(w);
//     return;
// }

void MerkelMain::printMarketStats()
{
    /*
    for(std::string const p : orderBook.getKnownProducts())
    {
        std::cout << "Product: " << p  << std::endl;
        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, p, currentTime);
        std::cout << "Asks for product " << p << " are " << entries.size() << std::endl;
        std::cout << "Max ask for " << p << " is " << orderBook.getHighPrice(entries)  << std::endl;
        std::cout << "Min ask for " << p << " is " << orderBook.getLowPrice(entries)  << std::endl;
    }
    */
    std::string separator = "====================================================================================================";
    std::cout << separator << std::endl;
    std::cout << "Current Time: " << currentTime << std::endl;
    std::cout << separator << std::endl;
    //std::cout <<            "PRODUCT     LAST        CHANGE%     CHANGE      HIGH        LOW         MEAN    " << std::endl;
    std::cout << std::left
              << std::setw(12) << "PRODUCT" << std::right
              << std::setw(12) << "LAST"
              << std::setw(12) << "CHANGE%"
              << std::setw(12) << "CHANGE"
              << std::setw(12) << "HIGH"
              << std::setw(12) << "LOW"
              << std::setw(12) << "AVERAGE"
              << std::setw(12) << "SPREAD" << std::endl;
    std::cout << "----------------------------------------------------------------------------------------------------" << std::endl;
    for(std::string const p : orderBook.getKnownProducts())
    {
        //std::cout.precision(5);
        
        std::vector<OrderBookEntry> askEntries = orderBook.getOrders(OrderBookType::ask, p, currentTime);
        std::vector<OrderBookEntry> bidEntries = orderBook.getOrders(OrderBookType::bid, p, currentTime);
        
        //std::cout << p << fluff << std::cout.width(4) << orderBook.getHighPrice(askEntries) << std::endl;
        std::cout.left;
        std::streamsize pres = std::cout.precision();
        std::cout << std::left << std::setw(12) << p
                  << std::right << std::fixed << std::setw(12) << orderBook.getLastPrice(askEntries)
                  << std::right << std::fixed << std::setw(12) << orderBook.getChangePercent(askEntries)
                  << std::right << std::fixed << std::setw(12) << orderBook.getChangeNumber(askEntries)
                  << std::right << std::fixed << std::setw(12) << orderBook.getHighPrice(askEntries)
                  << std::right << std::fixed << std::setw(12) << orderBook.getLowPrice(askEntries)
                  << std::right << std::fixed << std::setw(12) << orderBook.getAverage(askEntries)
                  << std::right << std::fixed << std::setw(12) << orderBook.getSpread(bidEntries, askEntries)
                  << std::endl;
    }
    std::cout << separator << std::endl;
}

void MerkelMain::enterOffer()
{
    std::cout << "Mark and offer - enter the amount " << std::endl;
}

void MerkelMain::enterBid()
{
    std::cout << "Make a bid - enter the amount" << std::endl;
}

void MerkelMain::printWallet()
{
    std::cout << "Your wallet is empty. " << std::endl;
}
        
void MerkelMain::gotoNextTimeframe()
{
    std::cout << "Going to next time frame. " << std::endl;
    currentTime = orderBook.getNextTime(currentTime);
}
 
int MerkelMain::getUserOption()
{
    int userOption;

    std::cout << "To select, type in 1-6:" << std::endl;
    std::cin >> userOption;
    std::cout << "You chose: " << userOption << std::endl;
    return userOption;
}

void MerkelMain::processUserOption(int userOption)
{
    if (userOption == 0) // bad input
    {
        std::cout << "Invalid choice. Choose 1-6" << std::endl;
    }
    if (userOption == 1) 
    {
        printHelp();
    }
    if (userOption == 2) 
    {
        printMarketStats();
    }
    if (userOption == 3) 
    {
        enterOffer();
    }
    if (userOption == 4) 
    {
        enterBid();
    }
    if (userOption == 5) 
    {
        printWallet();
    }
    if (userOption == 6) 
    {
        gotoNextTimeframe();
    }       
}
 

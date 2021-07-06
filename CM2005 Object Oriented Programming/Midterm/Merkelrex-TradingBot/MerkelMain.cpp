#include "MerkelMain.h"
#include <iostream>
#include <vector>
#include "OrderBookEntry.h"
#include "CSVReader.h"

MerkelMain::MerkelMain()
{
    currentTime = orderBook.getEarliestTime();
    wallet.insertCurrency("BTC", 10);
    wallet.insertCurrency("ETC", 10);
    wallet.insertCurrency("DOGE", 10);
    wallet.insertCurrency("USDT", 10);
}

std::string MerkelMain::getCurrentTime()
{
    return currentTime;
}

std::vector<std::string> MerkelMain::getKnownProducts()
{
    return orderBook.getKnownProducts();
}

void MerkelMain::init()
{
    int input;
    currentTime = orderBook.getEarliestTime();

    wallet.insertCurrency("BTC", 10);

    while (true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}

void MerkelMain::printMenu()
{
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

    std::cout << "============== " << std::endl;

    std::cout << "Current time is: " << currentTime << std::endl;
}

void MerkelMain::printHelp()
{
    std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers. " << std::endl;
}

void MerkelMain::printMarketStats()
{
    for (std::string const &p : orderBook.getKnownProducts())
    {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, p, currentTime);
        std::cout << "Asks seen: " << entries.size() << std::endl;
        std::cout << "Max ask: " << OrderBook::getHighPrice(entries) << std::endl;
        std::cout << "Min ask: " << OrderBook::getLowPrice(entries) << std::endl;
    }
    // std::cout << "OrderBook contains :  " << orders.size() << " entries" << std::endl;
    // unsigned int bids = 0;
    // unsigned int asks = 0;
    // for (OrderBookEntry& e : orders)
    // {
    //     if (e.orderType == OrderBookType::ask)
    //     {
    //         asks ++;
    //     }
    //     if (e.orderType == OrderBookType::bid)
    //     {
    //         bids ++;
    //     }
    // }
    // std::cout << "OrderBook asks:  " << asks << " bids:" << bids << std::endl;
}

// Enter a new ask
void MerkelMain::enterAsk()
{
    std::cout << "Make an ask - enter the amount: product,price, amount, eg  ETH/BTC,200,0.5" << std::endl;
    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
    if (tokens.size() != 3)
    {
        std::cout << "MerkelMain::enterAsk Bad input! " << input << std::endl;
    }
    else
    {
        try
        {
            OrderBookEntry obe = CSVReader::stringsToOBE(
                tokens[1],
                tokens[2],
                currentTime,
                tokens[0],
                OrderBookType::ask);
            obe.username = "simuser";
            if (wallet.canFulfillOrder(obe))
            {
                std::cout << "Wallet looks good. " << std::endl;
                orderBook.insertOrder(obe);
            }
            else
            {
                std::cout << "Wallet has insufficient funds . " << std::endl;
            }
        }
        catch (const std::exception &e)
        {
            std::cout << " MerkelMain::enterAsk Bad input " << std::endl;
        }
    }
}

// Enter a new bid
void MerkelMain::enterBid()
{
    std::cout << "Make an bid - enter the amount: product,price, amount, eg  ETH/BTC,200,0.5" << std::endl;
    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
    if (tokens.size() != 3)
    {
        std::cout << "MerkelMain::enterBid Bad input! " << input << std::endl;
    }
    else
    {
        try
        {
            OrderBookEntry obe = CSVReader::stringsToOBE(
                tokens[1],
                tokens[2],
                currentTime,
                tokens[0],
                OrderBookType::bid);
            obe.username = "simuser";

            if (wallet.canFulfillOrder(obe))
            {
                std::cout << "Wallet looks good. " << std::endl;
                orderBook.insertOrder(obe);
            }
            else
            {
                std::cout << "Wallet has insufficient funds . " << std::endl;
            }
        }
        catch (const std::exception &e)
        {
            std::cout << " MerkelMain::enterBid Bad input " << std::endl;
        }
    }
}

// Withdraw an order
void MerkelMain::withdrawOrder(OrderBookEntry order)
{
    orderBook.removeOrder(order);
}

void MerkelMain::printWallet()
{
    std::cout << wallet.toString() << std::endl;
}

std::vector<OrderBookEntry> MerkelMain::gotoNextTimeframe(bool silent)
{
    // Sales vector to return
    std::vector<OrderBookEntry> sales;
    if (!silent)
        std::cout << "Going to next time frame. " << std::endl;
    // Match ask to bids product by product
    for (std::string p : orderBook.getKnownProducts())
    {
        std::cout << "Matching.. " << p << std::endl;
        std::vector<OrderBookEntry> productSales = orderBook.matchAsksToBids(p, currentTime);
        std::cout << "Number of sales for " << p << ": " << productSales.size() << std::endl;
        for (OrderBookEntry &sale : sales)
        {
            if (!silent)
                std::cout << "Sale price: " << sale.price << " amount " << sale.amount << std::endl;
            if (sale.username == "simuser")
            {
                // update the wallet
                wallet.processSale(sale);
            }
        }
        // Add this product sales to the complete sales list
        sales.insert(sales.end(), productSales.begin(), productSales.end());
    }

    currentTime = orderBook.getNextTime(currentTime);
    return sales;
}

// Enter an ask at the current time
void MerkelMain::enterAsk(double price, double amount, std::string product)
{
    OrderBookEntry order = {price, amount, currentTime, product, OrderBookType::ask, "simuser"};
    // check if the wallet can afford it
    if (wallet.canFulfillOrder(order))
    {
        orderBook.insertOrder(order);
    }
}

// Enter a bid at the current time
void MerkelMain::enterBid(double price, double amount, std::string product)
{
    OrderBookEntry order = {price, amount, currentTime, product, OrderBookType::bid, "simuser"};
    // check if the wallet can afford it
    if (wallet.canFulfillOrder(order))
    {
        orderBook.insertOrder(order);
    }
}

int MerkelMain::getUserOption()
{
    int userOption = 0;
    std::string line;
    std::cout << "Type in 1-6" << std::endl;
    std::getline(std::cin, line);
    try
    {
        userOption = std::stoi(line);
    }
    catch (const std::exception &e)
    {
        //
    }
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
        enterAsk();
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
        gotoNextTimeframe(false);
    }
}

std::vector<OrderBookEntry> MerkelMain::getCurrentAsks()
{
    std::vector<OrderBookEntry> currentAsks;
    for (const std::string &prod : orderBook.getKnownProducts())
    {
        std::vector<OrderBookEntry> thisProductAsks = orderBook.getOrders(OrderBookType::ask, prod, currentTime);
        currentAsks.insert(currentAsks.end(), thisProductAsks.begin(), thisProductAsks.end());
    }
    return currentAsks;
}

std::vector<OrderBookEntry> MerkelMain::getCurrentBids()
{
    std::vector<OrderBookEntry> currentBids;
    for (const std::string &prod : orderBook.getKnownProducts())
    {
        std::vector<OrderBookEntry> thisProductBids = orderBook.getOrders(OrderBookType::bid, prod, currentTime);
        currentBids.insert(currentBids.end(), thisProductBids.begin(), thisProductBids.end());
    }
    return currentBids;
}

std::string MerkelMain::returnWallet()
{
    return wallet.toString();
}
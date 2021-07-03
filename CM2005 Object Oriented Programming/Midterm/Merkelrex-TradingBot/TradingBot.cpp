#include "TradingBot.h"

TradingBot::TradingBot(MerkelMain *merkel)
{
  this->merkel = merkel;
}

void TradingBot::startBot()
{
  int input;
  while (input != 8)
  {
    printMenu();
    input = getUserOption();
    processUserOption(input);
  }
  std::cout << "Exiting bot..." << std::endl;
}

void TradingBot::printMenu()
{
  std::string spacer = "================================================================================";
  std::cout << spacer << std::endl;
  std::cout << " Welcome to the Trading Bot | Current time: " + merkel->getCurrentTime() << std::endl;
  std::cout << spacer << std::endl;
  // 1 print help
  std::cout << "1: Retrieve current orders" << std::endl;
  std::cout << "2: Predict ask and bid rates" << std::endl;
  std::cout << "8: Exit bot" << std::endl;
  std::cout << spacer << std::endl;
  std::cout << "Enter an option: ";
  return;
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
}

int TradingBot::getUserOption()
{
  int userOption = 0;
  std::string line;
  std::getline(std::cin, line);
  try
  {
    userOption = std::stoi(line);
  }
  catch (const std::exception &e)
  {
    std::cout << "Invalid option" << std::endl;
  }
  return userOption;
}

void TradingBot::processUserOption(int userOption)
{
  if (userOption == 0)
    return;
  if (userOption == 1)
  {
    retrieveOrders();
    if (bookAsks.size() > 0 && bookBids.size() > 0)
      std::cout << "Bids and Asks loaded successfully for the current time." << std::endl;
  }
  if (userOption == 2)
  {
    predictRates();
    if (predictedAsks.size() > 0 && predictedBids.size() > 0)
    {
      std::cout << "New predicitons have been created" << std::endl;
    }
  }
  if (userOption == 3)
  {
    printPredictions();
  }
  if (userOption == 7)
  {
    testFunc();
  }
}

void TradingBot::retrieveOrders()
{
  bookAsks.clear();
  bookAsks = merkel->getCurrentAsks();
  bookBids.clear();
  bookBids = merkel->getCurrentBids();
}

// Predict the next rates for all products
void TradingBot::predictRates()
{
  if (bookAsks.size() == 0 || bookBids.size() == 0)
  {
    std::cout << "No orders have been imported. Import orders and try again" << std::endl;
    return;
  }

  // We'll go through all products and get the mean
  std::vector<std::string> products = merkel->getKnownProducts();

  // Get all asks and store the mean
  std::map<std::string, double> askMap;
  for (const std::string &product : products)
  {
    askMap[product] = getMean(bookAsks, product);
  }
  askHistory.push_back(askMap);

  // Get all bids and store the mean
  std::map<std::string, double> bidMap;
  for (const std::string &product : products)
  {
    bidMap[product] = getMean(bookBids, product);
  }
  bidHistory.push_back(bidMap);

  // If the history vectors only have 1 element, then we're at the first time slot
  // Our prediction will be half way between the mean ask and bid
  if (bidHistory.size() == 1)
  {
    for (std::string &product : products)
    {
      predictedAsks[product] = (bidHistory[0][product] + askHistory[0][product]) / 2;
      predictedBids[product] = predictedAsks[product];
    }
  }

  //std::map<std::string, std::vector<double>> provMap;

  //askHistory.push_back(getMean(bookAsks));
  //bidHistory.push_back(getMean(bookBids));
}

// return the mean price from the vector
double TradingBot::getMean(std::vector<OrderBookEntry> orders, std::string product)
{
  double sum = 0;
  for (const OrderBookEntry &order : orders)
  {
    if (order.product == product)
      sum += order.price;
  }
  return sum / orders.size();
}

// Print predictions if they have been made
void TradingBot::printPredictions()
{
  std::cout << "Asks" << std::endl;
  if (predictedAsks.size() == 0)
    std::cout << "No ask predictions have been made yet" << std::endl;
  for (auto const &ask : predictedAsks)
  {
    std::cout << ask.first << " - " << ask.second << std::endl;
  }

  std::cout << "Bids" << std::endl;
  if (predictedBids.size() == 0)
    std::cout << "No bid predictions have been made yet" << std::endl;
  for (auto const &bid : predictedBids)
  {
    std::cout << bid.first << " - " << bid.second << std::endl;
  }
}

void TradingBot::testFunc()
{
  std::cout << "Asks" << std::endl;
  for (auto const &ask : predictedAsks)
  {
    std::cout << ask.first << " - " << ask.second << std::endl;
  }

  std::cout << "Bids" << std::endl;
  for (auto const &bid : predictedBids)
  {
    std::cout << bid.first << " - " << bid.second << std::endl;
  }

  //std::cout << "Ask: " << askHistory[0] << std::endl;
  return;
  std::cout << "Asks" << std::endl;
  for (int i = 0; i < bookAsks.size(); ++i)
  {
    std::cout << "Entry: " << bookAsks[i].timestamp << " - "
              << bookAsks[i].product << " - "
              << OrderBookEntry::OrderBookTypeToString(bookAsks[i].orderType) << " - "
              << std::fixed << bookAsks[i].price << " - "
              << std::fixed << bookAsks[i].amount << " - "
              << bookAsks[i].username << std::endl;
  }

  std::cout << "Bids" << std::endl;
  for (int i = 0; i < bookBids.size(); ++i)
  {
    std::cout << "Entry: " << bookBids[i].timestamp << " - "
              << bookBids[i].product << " - "
              << OrderBookEntry::OrderBookTypeToString(bookBids[i].orderType) << " - "
              << std::fixed << bookBids[i].price << " - "
              << std::fixed << bookBids[i].amount << " - "
              << bookBids[i].username << std::endl;
  }

  return;
  std::vector<OrderBookEntry> currentAsks = merkel->getCurrentAsks();
  std::cout.precision(8);
  for (int i = 0; i < currentAsks.size(); ++i)
  {
    //std::cout << merkel->getCurrentTime() << std::endl;
    if (currentAsks[i].product == "DOGE/BTC")
    {
      //std::cout.precision(14);
      std::cout << "Entry: " << currentAsks[i].timestamp << " - "
                << currentAsks[i].product << " - "
                << OrderBookEntry::OrderBookTypeToString(currentAsks[i].orderType) << " - "
                << std::fixed << currentAsks[i].price << " - "
                << std::fixed << currentAsks[i].amount << " - "
                << currentAsks[i].username << std::endl;
    }
  }

  return;

  std::vector<std::string> prods = merkel->getKnownProducts();
  for (int i = 0; i < prods.size(); ++i)
  {
    std::cout << prods[i] << std::endl;
  }
  return;

  std::string test1 = OrderBookEntry::OrderBookTypeToString(OrderBookType::bid);
  std::cout << test1 << std::endl;
  return;
}
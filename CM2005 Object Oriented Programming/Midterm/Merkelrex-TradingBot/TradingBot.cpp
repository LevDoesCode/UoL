#include "TradingBot.h"

TradingBot::TradingBot(MerkelMain *merkel)
{
  this->merkel = merkel;
  products = merkel->getKnownProducts();
  // We create the log files
  logAssets(merkel->returnWallet(), merkel->getCurrentTime(), "start");
  logBidsAsks(OrderBookEntry{1.0, 1.0, "", "", OrderBookType::ask, "simuser"}, "start");
  logUserSales(lastSales, "start");
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
  std::cout << "3: Print predictions" << std::endl;
  std::cout << "4: Make automatic bids and asks for the current time" << std::endl;
  std::cout << "5: Process bids and asks and go to next time slot" << std::endl;
  std::cout << "6: Fully automate this time slot" << std::endl;
  std::cout << "7: Fully automate all remaining time slots" << std::endl;
  std::cout << "8: Exit bot" << std::endl;
  std::cout << spacer << std::endl;
  std::cout << "Enter an option: ";
  return;
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
  // Retrieve bids and asks for current time slot
  if (userOption == 1)
  {
    retrieveOrders();
    if (bookAsks.size() > 0 && bookBids.size() > 0)
      std::cout << "Bids and Asks loaded successfully for the current time." << std::endl;
  }
  // User linear regression to predict future rates
  if (userOption == 2)
  {
    predictRates();
    if (predictedAsks.size() > 0 && predictedBids.size() > 0)
    {
      std::cout << "New predicitons have been created" << std::endl;
    }
  }
  // Create new bids or asks if they are predicted to make a profit
  if (userOption == 3)
  {
    if(predictedAsks.size() == 0 || predictedBids.size() == 0)
    {
      std::cout << "No predictions to print" << std::endl;
      return;
    }
    printPredictions();
  }
  // Based on predicted rates, make new bids or asks
  if (userOption == 4)
  {
    makeAutoBids();
    makeAutoAsks();
  }
  // Have Merkel process bids, asks and go to the new time slot
  if (userOption == 5)
  {
    processBidsAsks();
  }
  // Automate by pulling orders, predicting rates, making new asks/bids, withdrawing bids/asks
  if (userOption == 6)
  {
    retrieveOrders();
    predictRates();
    makeAutoBids();
    makeAutoAsks();
    processBidsAsks();
  }
  // Automate all remaining time slots
  if (userOption == 7)
  {
    do
    {
      retrieveOrders();
      predictRates();
      makeAutoBids();
      makeAutoAsks();
      processBidsAsks();
    }
    while (merkel->getCurrentTime() != "END");
    std::cout << "Finished all time slots and made " << salesHistory.size() << " sales" << std::endl;
  }
}

// R1A
// Retrieve orders for the current time slot
void TradingBot::retrieveOrders()
{
  bookAsks.clear();
  bookAsks = merkel->getCurrentAsks();
  bookBids.clear();
  bookBids = merkel->getCurrentBids();
  // We'll go through all products and get the mean
  // Get the mean ask and bid price and store in history
  std::map<std::string, double> askMap;
  std::map<std::string, double> bidMap;
  for (const std::string &product : products)
  {
    askMap[product] = getMean(bookAsks, product);
    bidMap[product] = getMean(bookBids, product);
  }
  askHistory.push_back(askMap);
  bidHistory.push_back(bidMap);
  return;
}

// R1B
// Predict the next rates for all products
// Also calculates the mean ask and bid prices per product and saves them to history
void TradingBot::predictRates()
{
  if (bookAsks.size() == 0 || bookBids.size() == 0)
  {
    std::cout << "No orders have been imported. Import orders and try again" << std::endl;
    return;
  }

  // If the history vectors only have 1 element, then we're at the first time slot
  // We can only predict a future price thorugh regression when there are at least 2 entries in the history vectors
  if (bidHistory.size() >= 2 && askHistory.size() >= 2)
  {
    for (const std::string &product : products)
    {
      // We want to find an equation of type Y = a + bX where
      // Y is the predicted value
      // X is the point in time index
      // We need to calculate a and b
      // The regression needs to be calculated every time slot because it may change due to the new data

      // ASKS //
      std::vector<double> askRegression = regressionFromHistory(askHistory, product);
      double &askIntercept = askRegression[0];
      double &askSlope = askRegression[1];
      // We calculate the current askRegression value (1-indexed)
      // The formula is Y = Y-intercept + Slope * X or regressionValue = askntercept + askSlope * timeIndex
      
      
      currentAsks[product] = askIntercept + askSlope * bidHistory.size();
      predictedAsks[product] = askIntercept + askSlope * (bidHistory.size() + 1);

      // BIDS //
      std::vector<double> bidRegression = regressionFromHistory(bidHistory, product);
      double &bidIntercept = bidRegression[0];
      double &bidSlope = bidRegression[1];
      // We calculate the current bidRegression value (1-indexed)
      // The formula is Y = Y-intercept + Slope * X or regressionValue = bidIntercept + bidSlope * timeIndex
      currentBids[product] = bidIntercept + bidSlope * bidHistory.size();
      predictedBids[product] = bidIntercept + bidSlope * (bidHistory.size() + 1);
    }
  }
  return;
}

// R2A
// R2B
// R2D
// Make bids automatically
void TradingBot::makeAutoBids()
{
  // The bid history has one or no entries, auto bids are skipped
  if (bidHistory.size() < 2)
    return;

  // We use the regression values to determine if we should make bids for the different products
  for (std::string &product : products)
  {
    // We'll make a bid (buy) the product if the predicted price is higher than the current mean stored in bidHistory
    if (bidHistory.back()[product] < predictedBids[product])
    {
      // The price we'll offer to buy will be half way between the current and predicted regression values
      double price = (currentBids[product] + predictedBids[product]) / 2.0;
      // To determine how much to offer to buy, we'll use the last saved list of sales to get an idea of the traded volume
      double amount = 0.0;
      if (lastSales.size() > 0)
      {
        for(int i=0; i<lastSales.size(); ++i)
        {
          if(lastSales[i].product == product)
            amount += lastSales[i].amount;
        }
      }
      // We will trade up to 20 percent of the last traded volume
      amount = amount * 0.20;
      // If amount still 0, we use the current orders' volume
      if(amount == 0.0)
      {
        for (const OrderBookEntry &bid : bookBids)
        {
          if (bid.product == product)
            amount += bid.amount;
        }
        amount = amount * 0.20;
      }

      // R2D
      // Check our bids and withdraw them if the price is higher than our calculated price
      for (const OrderBookEntry &bid : bookBids)
      {
        if(bid.username == "simuser" && bid.product == product && bid.price > price)
          {
            merkel->withdrawOrder(bid);
          }
      }
      
      // We now make a bid
      // R2B
      merkel->enterBid(price, amount, product);
      // We log the bid
      // R4B
      logBidsAsks(OrderBookEntry{price, amount, merkel->getCurrentTime(), product, OrderBookType::bid, "simuser"}, "append");
    }
  }
}

// R3A
// R3B
// R3D
// Make asks automatically
void TradingBot::makeAutoAsks()
{
  // The ask history has one or no entries, auto asks are skipped
  if (askHistory.size() < 2)
    return;
  
  // We use the regression values to determine if we should make asks for the different products
  for (std::string &product : products)
  {
    // We'll make an ask (sell) the product if the predicted price is lower than the current mean stored in askHistory
    if (askHistory.back()[product] > predictedAsks[product])
    {
      // The price we'll offer to sell will be half way between the current and predicted regression values
      double price = (currentAsks[product] + predictedAsks[product]) / 2.0;
      // To determine how much to offer to sell, we'll use the last saved list of sales to get an idea of the traded volume
      double amount = 0.0;
      if (lastSales.size() > 0)
      {
        for(int i=0; i<lastSales.size(); ++i)
        {
          if(lastSales[i].product == product)
            amount += lastSales[i].amount;
        }
      }
      // We will trade up to 20 percent of the last traded volume
      amount = amount * 0.20;
      // If amount still 0, we use the current orders' volume
      if(amount == 0.0)
      {
        for (const OrderBookEntry &ask : bookAsks)
        {
          if (ask.product == product)
            amount += ask.amount;
        }
        amount = amount * 0.20;
      }

      // R3D
      // Check our asks and withdraw them if the price is higher than our calculated price
      for (const OrderBookEntry &ask : bookAsks)
      {
        if(ask.username == "simuser" && ask.product == product && ask.price < price)
          {
            merkel->withdrawOrder(ask);
          }
      }

      // We now make an ask
      // R3B
      merkel->enterAsk(price, amount, product);
      // We log the ask
      // R4B
      logBidsAsks(OrderBookEntry{price, amount, merkel->getCurrentTime(), product, OrderBookType::ask, "simuser"}, "append");
    }
  }
}

// R2C & R3C
// Ask Merkel to process all bids and asks for the current time slot
void TradingBot::processBidsAsks()
{
  lastSales.clear();
  // R2C & R3C
  lastSales = merkel->gotoNextTimeframe(true);
  salesHistory.insert(salesHistory.end(), lastSales.begin(), lastSales.end());
  logAssets(merkel->returnWallet(), merkel->getCurrentTime(), "append");
  logUserSales(lastSales, "append");
  return;
}

// Calculate and Return the Y intercept and slope from a vector of map objects
std::vector<double> TradingBot::regressionFromHistory(std::vector<std::map<std::string, double>> history, std::string product)
{
  // Check if enough data points are present
  if (history.size() < 2)
    return std::vector<double>{0.0, 0.0};
  // number of history entries
  int hisSize = history.size();
  // Build a vector of history prices for this product
  std::vector<double> priceHistory;
  for (const std::map<std::string, double> &historyEntry : history)
  {
    priceHistory.push_back(historyEntry.at(product));
  }
  // Find the mean of the independent variables
  // 1-indexed sum
  double sumX = (hisSize * (hisSize + 1)) / 2;
  double meanX = sumX / ((double)hisSize);
  // Find the mean of the dependent variables
  double sumY = 0.0;
  double meanY = 0.0;
  for (const double &price : priceHistory)
  {
    sumY += price;
  }
  meanY = sumY / ((double)hisSize);
  // We calculate the distances to the mean lines
  // X distances
  std::vector<double> distanceX;
  for (int i = 1; i <= hisSize; ++i)
  {
    distanceX.push_back(((double)i) - meanX);
  }
  // Y distances
  std::vector<double> distanceY;
  for (const double &price : priceHistory)
  {
    distanceY.push_back(price - meanY);
  }
  // We square X distances
  std::vector<double> distanceSquareX;
  for (int i = 0; i < distanceX.size(); ++i)
  {
    distanceSquareX.push_back(distanceX[i] * distanceX[i]);
  }
  // We find the product of the distances
  std::vector<double> distanceProducts;
  for (int i = 0; i < distanceX.size(); ++i)
  {
    distanceProducts.push_back(distanceX[i] * distanceY[i]);
  }
  // We add up the X distance squares
  double squareSum = 0.0;
  for (const double &square : distanceSquareX)
  {
    squareSum += square;
  }
  // We add up the distance products
  double productSum = 0.0;
  for (const double &distanceP : distanceProducts)
  {
    productSum += distanceP;
  }
  // We calculate the slope of the regression line
  double slope = productSum / squareSum;

  // We calculate interception with the Y axis
  // We know the regression line will go through the (meanX, meanY) point
  // We have: meanY = yIntercept + slope * meanX
  // So we solve for Y
  double yIntercept = meanY - slope * meanX;
  return std::vector<double>{yIntercept, slope};
}

// return the mean price from the vector
double TradingBot::getMean(std::vector<OrderBookEntry> orders, std::string product)
{
  double sum = 0;
  int count = 0;
  for (const OrderBookEntry &order : orders)
  {
    if (order.product == product)
    {
      sum += order.price;
      ++count;
    }
  }
  if (count == 0)
    return 0.0;
  return sum / count;
}

// Print predictions if they have been made
void TradingBot::printPredictions()
{
  std::cout.precision(8);
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

// R4A
// Print assets from wallet
void TradingBot::logAssets(std::string Wallet, std::string timestamp, std::string mode)
{
    std::fstream assetStream;
    if(mode == "start")
      assetStream.open("assets.txt", std::ios::out);
    else
      assetStream.open("assets.txt", std::ios_base::app);
    
    // Check the file was created properly
    if(!assetStream)
    {
      // We couldn't open/create the file
      return;
    }
    else
    {
      assetStream << "Time: " << timestamp << std::endl;
      assetStream << Wallet << std::endl;
      assetStream.close();
    }
}

// R4B
// Print bids and offers that have been created
void TradingBot::logBidsAsks(OrderBookEntry order, std::string mode)
{
  std::fstream askStream;
  std::fstream bidStream;
  if(mode == "start")
  {
    // create the files overwriting anything there
    askStream.open("asks.txt", std::ios::out);
    bidStream.open("bids.txt", std::ios::out);
    askStream.close();
    bidStream.close();
    return;
  }
  else if(order.orderType == OrderBookType::ask)
  {
    askStream.open("asks.txt", std::ios_base::app);
    // Check the file was created properly
    if(!askStream)
    {
      // We couldn't open/create the file
      return;
    }
    else
    {
      askStream << order.timestamp << ","
                << order.product << ","
                << OrderBookEntry::OrderBookTypeToString(order.orderType) << ","
                << order.price << ","
                << order.amount << std::endl;
      askStream.close();
    }
  }
  else if(order.orderType == OrderBookType::bid)
  {
    bidStream.open("bids.txt", std::ios_base::app);
    // Check the file was created properly
    if(!bidStream)
    {
      // We couldn't open/create the file
      return;
    }
    else
    {
      bidStream << order.timestamp << ","
                << order.product << ","
                << OrderBookEntry::OrderBookTypeToString(order.orderType) << ","
                << order.price << ","
                << order.amount << std::endl;
      bidStream.close();
    }
  }
}

// R4C
// Print successful asks and bids
void TradingBot::logUserSales(std::vector<OrderBookEntry> sales, std::string mode)
{
  std::fstream saleStream;
  if(mode == "start")
    saleStream.open("user-sales.txt", std::ios::out);
  else
    saleStream.open("user-sales.txt", std::ios_base::app);
  
  // Check the file was created properly
  if(!saleStream)
  {
    // We couldn't open/create the file
    return;
  }
  else
  {
    // We loop though the sales vector and check the type username
    for(const OrderBookEntry &sale : sales)
    {
      // this means the sale was created from a user ask or sale.
      if(sale.username == "simuser")
      {
        saleStream << sale.timestamp << ","
                   << sale.product << ","
                   << OrderBookEntry::OrderBookTypeToString(sale.orderType) << ","
                   << sale.price << ","
                   << sale.amount << std::endl;
      }
    }
    saleStream.close();
  }
}
#include "OrderBook.h"
#include "CSVReader.h"
#include <map>
#include <iostream>

/* Construct, reading a csv data file */
OrderBook::OrderBook(std::string filename)
{
  orders = CSVReader::readCSV(filename);
}

/* return vector of all known products in the dataset */
std::vector<std::string> OrderBook::getKnownProducts()
{
  std::vector<std::string> products;

  std::map<std::string, bool> productMap;

  for(OrderBookEntry& entry : orders)
  {
    productMap[entry.product] = true;
  }

  for(auto const&entry : productMap)
  {
    products.push_back(entry.first);
  }
  return products;
}

unsigned int OrderBook::getBookSize()
{
  return orders.size();
}

/* return vector of Orders according to the sent filters */
std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type, std::string product, std::string timestamp)
{
  std::vector<OrderBookEntry> order_selection;

  for(OrderBookEntry& entry : orders)
  {
    if(entry.orderType == type && entry.product == product && entry.timestamp == timestamp)
    {
      order_selection.push_back(entry);
    }
  }

  return order_selection;
}

double OrderBook::getHighPrice(std::vector<OrderBookEntry>& orderList)
{
  double max = orderList[0].price;
  for(OrderBookEntry& entry : orderList)
  {
    if(entry.price > max)
      max = entry.price;
  }
  return max;
}

double OrderBook::getLowPrice(std::vector<OrderBookEntry>& orderList)
{
  double min = orderList[0].price;
  for(OrderBookEntry& entry : orderList)
  {
    if(entry.price < min)
      min = entry.price;
  }
  
  return min;
}

std::string OrderBook::getEarliestTime()
{
  return orders[0].timestamp;
}

std::string OrderBook::getNextTime(std::string timestamp)
{
  std::string prev_timestamp = "";
  for(OrderBookEntry& entry : orders)
  {
    if(entry.timestamp > timestamp)
    {
      prev_timestamp = entry.timestamp;
      break;
    }
  }
  if(prev_timestamp == "")
  {
    prev_timestamp = orders[0].timestamp;
  }
  return prev_timestamp;
}

double OrderBook::getLastPrice(std::vector<OrderBookEntry>& orderList)
{
  //std::cout <<  std::endl << std::to_string(orderList[orderList.size()-1].price) << std::endl;
  return orderList[orderList.size()-1].price;
}

double OrderBook::getAverage(std::vector<OrderBookEntry>& orderList)
{
  double sum{};
  for (const OrderBookEntry& entry : orderList)
  {
    sum += entry.price;
  }
  return sum/orderList.size();
}

double OrderBook::getSpread(std::vector<OrderBookEntry>& bids, std::vector<OrderBookEntry>& asks)
{
  return getAverage(bids) - getAverage(asks);
}
double OrderBook::getChangePercent(std::vector<OrderBookEntry>& orderList)
{
  std::string prevTime = getPrevTime(orderList[0].timestamp);
  if(orderList[0].timestamp == prevTime)
    return 0.0;
  std::vector<OrderBookEntry> lastList = getOrders(orderList[0].orderType, orderList[0].product, prevTime);
  double lastAverage = getAverage(lastList);
  double thisAverage = getAverage(orderList);
  return ((lastAverage - thisAverage) / lastAverage) * 100;
}

double OrderBook::getChangeNumber(std::vector<OrderBookEntry>& orderList)
{
  std::string prevTime = getPrevTime(orderList[0].timestamp);
  if(orderList[0].timestamp == prevTime)
    return 0.0;
  std::vector<OrderBookEntry> lastList = getOrders(orderList[0].orderType, orderList[0].product, prevTime);
  double lastAverage = getAverage(lastList);
  double thisAverage = getAverage(orderList);
  return lastAverage - thisAverage;
}

std::string OrderBook::getPrevTime(std::string timestamp)
{
  std::string prev_timestamp = "";
  for(OrderBookEntry& entry : orders)
  {
    if(entry.timestamp == timestamp)
    {
      break;
    }
    prev_timestamp = entry.timestamp;
  }
  if(prev_timestamp == "")
  {
    prev_timestamp = orders[0].timestamp;
  }
  return prev_timestamp;
}
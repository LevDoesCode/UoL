#include "OrderBook.h"
#include "CSVReader.h"
#include <map>

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
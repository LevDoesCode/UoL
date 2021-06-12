#include "OrderBook.h"
#include "CSVReader.h"
#include <map>
#include <algorithm>

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

std::string OrderBook::getNextTime(std::string timestamp)
{
  std::string next_timestamp = "";
  for(OrderBookEntry& entry : orders)
  {
    if(entry.timestamp > timestamp)
    {
      next_timestamp = entry.timestamp;
      break;
    }
  }
  if(next_timestamp == "")
  {
    next_timestamp = orders[0].timestamp;
  }
  return next_timestamp;
}

void OrderBook::insertOrder(OrderBookEntry& order)
{
  orders.push_back(order);
  std::sort(orders.begin(), orders.end(), OrderBookEntry::compareByTimestamp);
}

std::vector<OrderBookEntry> OrderBook::matchAsksToBids(std::string product, std::string timestamp)
{
  std::vector<OrderBookEntry> asks = getOrders(OrderBookType::ask, product, timestamp);
  std::vector<OrderBookEntry> bids = getOrders(OrderBookType::bid, product, timestamp);

  std::vector<OrderBookEntry> sales;

  std::sort(asks.begin(), asks.end(), OrderBookEntry::compareByPriceAsc);
  std::sort(bids.begin(), bids.end(), OrderBookEntry::compareByPriceDesc);

  for(OrderBookEntry& thisAsk : asks)
  {
    for(OrderBookEntry& thisBid : bids)
    {
      if(thisBid.price >= thisAsk.price)
      {
        OrderBookEntry sale{thisAsk.price, 0, timestamp, product, OrderBookType::sale};
        if(thisBid.amount == thisAsk.amount)
        {
          sale.amount = thisAsk.amount;
          sales.push_back(sale);
          thisBid.amount = 0;
          break;
        }
        else if(thisBid.amount > thisAsk.amount)
        {
          sale.amount = thisAsk.amount;
          sales.push_back(sale);
          thisBid.amount = thisBid.amount - thisAsk.amount;
          break;
        }
        else if(thisBid.amount > 0 && thisBid.amount < thisAsk.amount)
        {
          sale.amount = thisBid.amount;
          sales.push_back(sale);
          thisAsk.amount = thisAsk.amount - thisBid.amount;
          thisBid.amount = 0;
          continue;
        }
      }
    }
  }
  return sales;
}
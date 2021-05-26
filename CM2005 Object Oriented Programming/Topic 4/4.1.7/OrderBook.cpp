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
  return order_selection;
}
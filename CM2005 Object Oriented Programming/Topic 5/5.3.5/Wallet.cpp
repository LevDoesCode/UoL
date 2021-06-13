#include "Wallet.h"
#include "CSVReader.h"
#include <iostream>

Wallet::Wallet()
{

}

void Wallet::insertCurrency(std::string type, double amount)
{
  double balance;
  if(amount < 0)
  {
    throw std::exception{};
  }
  if(currencies.count(type) == 0) // not in wallet yet
  {
    balance = 0;
  }
  else
  {
    balance = currencies[type];
  }
  balance += amount;
  currencies[type] = balance;
}

bool Wallet::removeCurrency(std::string type, double amount)
{
  double balance;
  if(amount < 0)
  {
    return false;
  }
  if(currencies.count(type) == 0) // currency not in wallet
  {
    return false;
  }
  else // is there, do we have enough?
  {
    if(containsCurrency(type, amount))
    {
      currencies[type] -= amount;
      return true;
    }
    else // didn't have enough
      return false;
  }
}

bool Wallet::containsCurrency(std::string type, double amount)
{
  if(currencies.count(type) == 0) // not in wallet yet
  {
    return false;
  }
  else
    return currencies[type] >= amount;
}

std::string Wallet::toString()
{
  std::string s;
  for(std::pair<const std::string, double> pair : currencies)
  {
    std::string currency = pair.first;
    double amount = pair.second;
    s += currency + " : " + std::to_string(amount) + "\n";
  }
  return s;
}

bool Wallet::canFulfillOrder(OrderBookEntry order)
{
  std::vector<std::string> currs = CSVReader::tokenise(order.product, '/');
  // ask
  if(order.orderType == OrderBookType::ask)
  {
    double amount = order.amount;
    std::string currency = currs[0];
    std::cout << "Wallet::canFulfillrder " << currency << ":" <<amount << std::endl;
    return containsCurrency(currency, amount);
  }
  if(order.orderType == OrderBookType::bid)
  {
    double amount = order.amount * order.price;
    std::string currency = currs[1];
    return containsCurrency(currency, amount);
  }
  return false;
}

void Wallet::processSale(OrderBookEntry& sale)
{
  std::vector<std::string> currs = CSVReader::tokenise(sale.product, '/');
  // ask
  if(sale.orderType == OrderBookType::asksale)
  {
    double outAmount = sale.amount;
    std::string outCurrency = currs[0];
    double incAmount = sale.amount * sale.price;
    std::string incCurrency = currs[1];

    currencies[incCurrency] += incAmount;
    currencies[outCurrency] -= outAmount;
  }
  if(sale.orderType == OrderBookType::bidsale)
  {
    double incAmount = sale.amount;
    std::string incCurrency = currs[0];
    double outAmount = sale.amount * sale.price;
    std::string outCurrency = currs[1];

    currencies[incCurrency] += incAmount;
    currencies[outCurrency] -= outAmount;
  }
}
#include "Wallet.h"

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
  for(std::pair<std::string, double> pair : currencies)
  {
    std::string currency = pair.first;
    double amount = pair.second;
    s += currency + " : " + std::to_string(amount) + "\n";
  }
  return s;
}
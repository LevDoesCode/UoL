#pragma once

#include <string>
#include <map>
#include "OrderBookEntry.h"

class Wallet
{
  public:
    Wallet();
    /** insert currency to the wallet */
    void insertCurrency(std::string type, double amount);

    /** remove currency from the wallet */
    bool removeCurrency(std::string type, double amount);

    /** check if the wallet contains at least this much currency */
    bool containsCurrency(std::string type, double amount);

    /** check if the wallet can cope with the ask or bid */
    bool canFulfillOrder(OrderBookEntry order);

    /** update the contents of the wallet * assumes the order was amade by the owner of the wallet */
    void processSale(OrderBookEntry& sale);

    /** generate a string representation of the wallet */
    std::string toString();

  private:
    std::map<std::string, double> currencies;
};
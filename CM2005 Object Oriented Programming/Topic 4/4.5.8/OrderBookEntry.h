#pragma once

#include <string>

enum class OrderBookType
{
    bid,
    ask,
    unknown,
    sale
};

class OrderBookEntry
{
public:
    OrderBookEntry(double _price,
                   double _amount,
                   std::string _timestamp,
                   std::string _product,
                   OrderBookType _orderType);

    static OrderBookType stringToOrderBookType(std::string s);
    static bool compareByTimestamp(OrderBookEntry &entry1, OrderBookEntry &entry2)
    {
        return entry1.timestamp < entry2.timestamp;
    }
    static bool compareByPriceAsc(OrderBookEntry &entry1, OrderBookEntry &entry2)
    {
        return entry1.price < entry2.price;
    }
    static bool compareByPriceDesc(OrderBookEntry &entry1, OrderBookEntry &entry2)
    {
        return entry1.price > entry2.price;
    }

    double price;
    double amount;
    std::string timestamp;
    std::string product;
    OrderBookType orderType;
};

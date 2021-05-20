#include <iostream>
#include <string>
#include <vector>

enum class OrderBookType
{
  bid,
  ask
};

// We add a constructor
class OrderBookEntry
{
  public:
    OrderBookEntry
    (
      double _price,
      double _amount,
      std::string _timestamp,
      std::string _product,
      OrderBookType _orderType
    )
    {
      price = _price;
      amount = _amount;
      timestamp = _timestamp;
      product = _product;
      orderType = _orderType;
    }
    double price;
    double amount;
    std::string timestamp;
    std::string product;
    OrderBookType orderType;
};

class OrderBookEntry2
{
  public:
    OrderBookEntry2
    (
      double price,
      double amount,
      std::string timestamp,
      std::string product,
      OrderBookType orderType
    )
    {
      this->price = price;
      this->amount = amount;
      this->timestamp = timestamp;
      this->product = product;
      this->orderType = orderType;
    }
    double price;
    double amount;
    std::string timestamp;
    std::string product;
    OrderBookType orderType;
};

int main()
{
  OrderBookEntry order1{  10000,
                          0.002,
                          "2020/03/17 17:01:24.884492",
                          "BTC/USDT",
                          OrderBookType::bid};
  OrderBookEntry2 order2{  50000,
                           0.002,
                          "2020/03/17 17:01:24.884492",
                          "BTC/USDT",
                          OrderBookType::bid};
  // order1.price = 10000;
  // order1.amount = 0.002;
  // order1.timestamp = "2020/03/17 17:01:24.884492";
  // order1.product = "BTC/USDT";
  // order1.orderType = OrderBookType::bid;

  std::cout << order1.price << std::endl;
  std::cout << order2.price << std::endl;
}
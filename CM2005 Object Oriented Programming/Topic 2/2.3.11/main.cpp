#include <iostream>
#include <string>
#include <vector>

enum class OrderBookType
{
  bid,
  ask
};

class OrderBookEntry
{
  public:
    OrderBookEntry
    (
      double price,
      double amount,
      std::string timestamp,
      std::string product,
      OrderBookType orderType
    )
    : price{price},
      amount(amount),
      timestamp(timestamp),
      product(product),
      orderType(orderType)
      // can use parenthesis or curly braces
    {
      
    }
    double price;
    double amount;
    std::string timestamp;
    std::string product;
    OrderBookType orderType;
};

int main()
{

  std::vector<OrderBookEntry> orders;
  
  // OrderBookEntry order1{  10000,
  //                         0.002,
  //                         "2020/03/17 17:01:24.884492",
  //                         "BTC/USDT",
  //                         OrderBookType::bid};

  orders.push_back( OrderBookEntry{
                                    10000,
                                    0.002,
                                    "2020/03/17 17:01:24.884492",
                                    "BTC/USDT",
                                    OrderBookType::bid});

  orders.push_back( OrderBookEntry{
                                    50000,
                                    0.002,
                                    "2020/03/17 17:01:24.884492",
                                    "BTC/USDT",
                                   OrderBookType::bid});

  // Version 1
  std::cout << "Version 1" << std::endl;
  for(OrderBookEntry order : orders) //this create a copy of the members of orders and assigns it to 'order'
  {
    std::cout << "The price is " << order.price << std::endl;
  }

  std::cout << "---new line---" << std::endl;

  for(OrderBookEntry &order : orders) //this doesn't crate a copy
  {
    std::cout << "The price is " << order.price << std::endl;
  }

  // Version 2
  std::cout << "Version 2" << std::endl;
  for(unsigned int i=0; i<orders.size(); ++i) //thid doesn't create a copy, ++i increments on the same variable
  {
    std::cout << "The price is " << orders[i].price << std::endl;
  }

  //version 3
  std::cout << "Version 3" << std::endl;
  for(unsigned int i=0; i<orders.size(); ++i) //thid doesn't create a copy, ++i increments on the same variable
  {
    std::cout << "The price is " << orders.at(i).price << std::endl;
  }
}
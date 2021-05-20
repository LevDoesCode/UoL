#include <iostream>
#include <string>
#include <vector>

enum class OrderBookType
{
  bid,
  ask
};

// We add a constructor with an initialization list :
// This is mor effecient because it doesn't copy but assigns the data right away.
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


  OrderBookEntry order1{  10000,
                          0.002,
                          "2020/03/17 17:01:24.884492",
                          "BTC/USDT",
                          OrderBookType::bid};
  orders.push_back(order1);
  orders.push_back(order1);
  std::cout << orders[0].price << std::endl;
  std::cout << orders[1].price << std::endl;
}
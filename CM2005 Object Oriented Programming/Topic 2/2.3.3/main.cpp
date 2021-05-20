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
  double price;
  double amount;
  std::string timestamp;
  std::string product;
  OrderBookType orderType;
};

int main()
{
  OrderBookEntry order1;
  order1.price = 10000;
  order1.amount = 0.002;
  order1.timestamp = "2020/03/17 17:01:24.884492";
  order1.product = "BTC/USDT";
  order1.orderType = OrderBookType::bid;

  std::cout << order1.price << std::endl;
}
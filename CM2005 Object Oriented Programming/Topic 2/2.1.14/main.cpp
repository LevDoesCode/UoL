#include <iostream>
#include <string>
#include <vector>

int main()
{
    enum class OrderBookType{bid, ask};
    
    //double price = 5319.450228;
    //double amount = 0.00020075;
    //std::string timestamp{"2020/03/17 17:01:24.884492"};
    //std::string product{"BTC/USDT"};
    //std::string orderType{"bid"};
    //enum class OrderBookType{bid, ask};
    //OrderBookType orderType = OrderBookType::ask;

    std::vector<double> prices;
    std::vector<double> amounts;
    std::vector<std::string> timestamps;
    std::vector<std::string> products;
    std::vector<OrderBookType> orderTypes;

    prices.push_back(5000.01);
    amounts.push_back(0.001);
    timestamps.push_back("2020/03/17 17:01:24.884492");
    products.push_back("BTC/USDT");
    orderTypes.push_back(OrderBookType::bid);

    prices.push_back(5000.03);
    amounts.push_back(0.003);
    timestamps.push_back("2020/03/17 17:01:24.884492");
    products.push_back("BTC/USDT");
    orderTypes.push_back(OrderBookType::bid);

    std::cout << "prices: " << prices[0] << std::endl;
    std::cout << "prices: " << prices[1] << std::endl;

    return 0;
}
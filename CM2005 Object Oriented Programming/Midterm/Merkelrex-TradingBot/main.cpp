#include "Wallet.h"
#include <iostream>
#include "MerkelMain.h"
#include "TradingBot.h"

int main()
{   
    MerkelMain app{};
    TradingBot bot{&app};
    bot.startBot();
}

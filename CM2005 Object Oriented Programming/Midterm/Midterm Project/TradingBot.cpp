#include "TradingBot.h"
#include <iostream>
#include <string>
#include "main.cpp"

Bot::Bot(MerkelMain _app)
{
  app = _app;
}

std::vector<double> Bot::linearRegresion(std::vector<OrderBookEntry> orderList, unsigned int start, unsigned int end)
{
  //get all dates from the order book
}

std::vector<std::string> Bot::getTimeStamps()
{
  std::vector<std::string> timeStamps;
  //timeStamps.push_back(app.;
  //while(std::find(timeStamps.begin(), timeStamps.end(), ))
}

double Bot::getMean(std::vector<OrderBookEntry>)
{
  
}
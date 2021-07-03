#pragma once

#include "MerkelMain.h"     // required to interact with the order book, place bids, withdraw bids, place asks
#include "OrderBookEntry.h" // required to build vectors of this type
#include <string>
#include <iostream>
#include <vector>
#include <map>

class TradingBot
{
public:
  TradingBot(MerkelMain *merkel);
  /** start the Trading Bot interface */
  void startBot();
  void testFunc();

private:
  // ===== Functions =====
  // Interface functions
  void printMenu();
  int getUserOption();
  void processUserOption(int userOption);
  // Exchange functions
  void retrieveOrders(); // Retrieves current orders from Merkel and stores them in bookBids and BookAsks

  // ===== Variables =====
  MerkelMain *merkel;
  std::vector<OrderBookEntry> bookBids;
  std::vector<OrderBookEntry> bookAsks;
  double bidHistory = {};
};
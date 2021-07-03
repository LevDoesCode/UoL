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
  void printPredictions();
  // Exchange functions
  void retrieveOrders(); // Retrieves current orders from Merkel and stores them in bookBids and BookAsks
  void predictRates();
  // Helper functions
  static double getMean(std::vector<OrderBookEntry> orders, std::string product);
  // ===== Variables =====
  MerkelMain *merkel;
  std::vector<OrderBookEntry> bookBids;
  std::vector<OrderBookEntry> bookAsks;
  std::vector<std::map<std::string, double>> bidHistory;
  std::vector<std::map<std::string, double>> askHistory;
  std::map<std::string, double> predictedBids;
  std::map<std::string, double> predictedAsks;
};
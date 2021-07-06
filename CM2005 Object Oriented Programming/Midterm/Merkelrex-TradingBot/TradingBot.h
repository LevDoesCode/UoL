#pragma once

#include "MerkelMain.h"     // required to interact with the order book, place bids, withdraw bids, place asks
#include "OrderBookEntry.h" // required to build vectors of this type
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <fstream>

class TradingBot
{
public:
  TradingBot(MerkelMain *merkel);
  /** start the Trading Bot interface */
  void startBot();

private:
  // ===== Functions =====
  // Interface functions
  void printMenu();
  int getUserOption();
  void processUserOption(int userOption);
  void printPredictions();
  // ==== Exchange functions ====
  void retrieveOrders();
  void predictRates();
  void makeAutoBids();
  void makeAutoAsks();
  void processBidsAsks();
  // ==== Helper functions ====
  static std::vector<double> regressionFromHistory(std::vector<std::map<std::string, double>> history, std::string product);
  static double getMean(std::vector<OrderBookEntry> orders, std::string product);
  static void logAssets(std::string wallet, std::string timestamp, std::string mode);
  static void logBidsAsks(OrderBookEntry order, std::string mode);
  static void logUserSales(std::vector<OrderBookEntry> sales, std::string mode);
  // ===== Variables =====
  MerkelMain *merkel;
  std::vector<std::string> products;
  std::vector<OrderBookEntry> bookBids;
  std::vector<OrderBookEntry> bookAsks;
  std::vector<OrderBookEntry> lastSales;
  std::vector<std::map<std::string, double>> bidHistory;
  std::vector<std::map<std::string, double>> askHistory;
  std::vector<OrderBookEntry> salesHistory;
  std::map<std::string, double> predictedBids;
  std::map<std::string, double> predictedAsks;
  std::map<std::string, double> currentBids;
  std::map<std::string, double> currentAsks;
};
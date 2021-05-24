#include "CSVReader.h"
#include "OrderBookEntry.h"
#include <string>

CSVReader::CSVReader()
{

}

std::vector<OrderBookEntry> CSVReader::readCSV(std::string csvFile)
{
  std::vector<OrderBookEntry> entries;
  return entries;
}

std::vector<std::string> CSVReader::tokenise(std::string csvLine, char separator)
{
  std::vector<std::string> tokens;
  return tokens;
}

OrderBookEntry CSVReader::stringsToBE(std::vector<std::string> tokens)
{
  if(tokens.size() != 5) //bad
  {
    throw std::exception{};
  }
  
  // We checked and we have 5 tokens
  double price{};
  double amount{};
  try
  {
    price = std::stod(tokens[3]);
    amount = std::stod(tokens[4]);
  }
  catch(const std::exception& e)
  {
    throw e;
  }

  OrderBookEntry obe{ price,
                      amount,
                      tokens[0],
                      tokens[1],
                      OrderBookEntry::stringToOrderBookType(tokens[2])};
  return obe;
}
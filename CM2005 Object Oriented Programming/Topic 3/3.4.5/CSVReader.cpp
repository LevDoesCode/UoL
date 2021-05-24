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

OrderBookEntry CSVReader::stringsToBE(std::vector<std::string> strings)
{
  OrderBookEntry obe{ 1,
                      1,
                      "",
                      "",
                      OrderBookType::bid};
  return obe;
}
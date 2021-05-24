#include "CSVReader.h"
#include "OrderBookEntry.h"
#include <fstream>
#include <iostream>

CSVReader::CSVReader()
{

}

std::vector<OrderBookEntry> CSVReader::readCSV(std::string csvFilename)
{
  std::vector<OrderBookEntry> entries;

  std::string line;
  std::ifstream csvFile{csvFilename};

  if(csvFile.is_open())
  {
    int count = 1;
    while (std::getline(csvFile, line))
    {
      
      try
      {
        OrderBookEntry obe = stringsToBE(tokenise(line, ','));
        entries.push_back(obe);
      }
      catch(const std::exception& e)
      {
        // std::cerr << e.what() << '\n';
        // reached error
        std::cout << "Error at line " << count << std::endl;
      }++count;
    }
    std::cout << "Read: " <<entries.size() << " entries." << std::endl;
  }

  return entries;
}

std::vector<std::string> CSVReader::tokenise(std::string csvLine, char separator)
{
  std::vector<std::string> tokens;
  signed int start{}, end{};
  std::string token;
  start = csvLine.find_first_not_of(separator, 0);
  do
  {
    end = csvLine.find_first_of(separator, start);
    if(start == csvLine.length() || start == end) break;
    if(end >= 0)
      token = csvLine.substr(start, end - start);
    else
      token = csvLine.substr(start, csvLine.length() - start);
    
    tokens.push_back(token);
    start = end + 1;
  }
  while (end > 0);
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
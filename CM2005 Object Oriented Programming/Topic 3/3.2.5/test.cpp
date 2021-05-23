#include <string>
#include <vector>
#include <iostream>
#include <fstream>

std::vector<std::string> Tokenise(std::string csvLine, char separator)
{
  std::vector<std::string> tokens;
  signed int start, end;
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
  } while (end > 0);
  return tokens;
}

int main()
{
  std::string filename = "20200317.csv";
  std::string line;
  std::ifstream csvFile{filename};

  std::vector<std::string> tokens;

  if(csvFile.is_open())
  {
    std::cout << "File open" << std::endl;
    while(std::getline(csvFile, line))
    {
      std::cout << "Read line: " << line << std::endl;
      tokens = Tokenise(line, ',');
      if(tokens.size() != 5) //bad
      {
        std::cout << "Bad line" << std::endl;
        continue;
      }
      // We checked and we have 5 tokens
      double price = std::stod(tokens[3]);
      double amount = std::stod(tokens[4]);
      
      std::cout << price << std::endl;
      std::cout << amount << std::endl;
      break;  // can be removed to read all lines in the csv
    }
    csvFile.close();
  }
  else
  {
    std::cout << "Could not open file" << std::endl;
  }

  return 0;
}
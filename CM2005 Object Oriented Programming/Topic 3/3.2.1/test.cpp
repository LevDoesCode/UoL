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
  std::ifstream csvFile{filename};

  if(csvFile.is_open())
  {
    std::cout << "File open" << std::endl;
    csvFile.close();
  }
  else
  {
    std::cout << "Could not open file" << std::endl;
  }

  return 0;
}
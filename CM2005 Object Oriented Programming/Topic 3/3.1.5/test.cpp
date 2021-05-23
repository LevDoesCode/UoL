#include <string>
#include <vector>
#include <iostream>

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
  std::vector<std::string> tokens6;
  std::vector<std::string> tokens3;
  std::vector<std::string> tokens1;
  std::vector<std::string> tokens0;
  std::vector<std::string> tokensA;
  std::string s6 = "thing0,thing1,thing2,thing3,thing4,thing5,thing6";
  std::string s3 = "thing0,thing1,thing2,thing3,thing4,thing5,thing6";
  std::string s1 = "thing0,thing1,thing2,thing3,thing4,thing5,thing6";
  std::string s0 = "";
  std::string sA = "2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187308,7.44564869";

  tokens6 = Tokenise(s6, ',');
  tokens3 = Tokenise(s3, ',');
  tokens1 = Tokenise(s1, ',');
  tokens0 = Tokenise(s0, ',');
  tokensA = Tokenise(sA, ',');
  std::cout << "6 tokens" << std::endl;
  for(std::string& token : tokens6)
  {
    std::cout << token << std::endl;
  }
  std::cout << "3 tokens" << std::endl;
  for(std::string& token : tokens3)
  {
    std::cout << token << std::endl;
  }
  std::cout << "1 token" << std::endl;
  for(std::string& token : tokens1)
  {
    std::cout << token << std::endl;
  }
  std::cout << "0 tokens" << std::endl;
  for(std::string& token : tokens0)
  {
    std::cout << token << std::endl;
  }
  std::cout << "Entry tokens" << std::endl;
  for(std::string& token : tokensA)
  {
    std::cout << token << std::endl;
  }
  return 0;
}
// Challenge:
// https://www.codewars.com/kata/525c7c5ab6aecef16e0001a5

#include <string>
#include <sstream>
#include <map>
#include <vector>

std::map<std::string, int> dict{
    {"zero", 0},
    {"one", 1},
    {"two", 2},
    {"three", 3},
    {"four", 4},
    {"five", 5},
    {"six", 6},
    {"seven", 7},
    {"eight", 8},
    {"nine", 9},
    {"ten", 10},
    {"eleven", 11},
    {"twelve", 12},
    {"thirteen", 13},
    {"fourteen", 14},
    {"fifteen", 15},
    {"sixteen", 16},
    {"seventeen", 17},
    {"eighteen", 18},
    {"nineteen", 19},
    {"twenty", 20},
    {"thirty", 30},
    {"forty", 40},
    {"fifty", 50},
    {"sixty", 60},
    {"seventy", 70},
    {"eighty", 80},
    {"ninety", 90},
    {"hundred", 100},
    {"thousand", 1'000},
    {"million", 1'000'000},
};

// make sure to not feed "and" in there!
long parse_word(const std::string& word) {
      if(size_t pos = word.find("-"); pos != std::string::npos)
      {
          std::string first = word.substr(0, pos);
          std::string second = word.substr(pos + 1, word.size());
          return dict[first] + dict[second];
      } else {
        return dict[word];
      } 
}


long parse_int(std::string number) {
  std::stringstream ss{number};
  std::vector<std::string> words;
  while(ss >> number) words.push_back(number);
  long result{};
  long factor = 1;
  for(auto itr = words.rbegin(); itr != words.rend(); ++itr)
  {
      if(*itr == "and") continue;
      long tmp = parse_word(*itr);
      if(tmp >= 100) {
        if(factor > tmp) factor *= tmp;
        else factor = tmp;
      } else {
        result += tmp * factor;
      }
  }
  return result;
}
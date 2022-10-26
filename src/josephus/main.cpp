// Challenge:
// https://www.codewars.com/kata/5550d638a99ddb113e0000a2

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

std::vector<int> josephus(std::vector < int > items, int k) {
  if(items.size() == 0) return {};
  std::vector<int> result;
  size_t index = k - 1;
  A:
  while(items.size() > 0) 
  {
      if(index >= items.size())
      {
        index = index - items.size();
        goto A;
      }
      result.push_back(items[index]);
      items.erase(items.begin() + index);
      index = index + k - 1;
  }
  return result;
}

int main()
{
    auto res = josephus({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 2);
    auto test = std::vector{2, 4, 6, 8, 10, 3, 7, 8, 9, 5};
    assert(res == test);
}
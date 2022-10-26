// Challenge:
// https://www.codewars.com/kata/52e864d1ffb6ac25db00017f

#include <string>
#include <stack>

std::string to_postfix(std::string infix) {
  struct OperatorImportance { char op; size_t imp{0}; };
  
  std::string result;
  std::stack<OperatorImportance> operators;
  
  size_t imp_offset = 0;
  for(auto& c : infix) 
  {
    OperatorImportance tmp;
    switch (c) 
    {
      case '+':
      case '-':
        tmp = { c, 1 + imp_offset};
        break;
      case '*':
      case '/':
        tmp = { c, 2 + imp_offset};
        break;
      case '^':
        tmp = { c, 3 + imp_offset};
        break;
      case '(':
        imp_offset += 3;
        break;
      case ')':
        imp_offset -= 3;
        break;
      default:
        result += c;
        break;
    }
    
    if(tmp.imp != 0)
    {
      while(!operators.empty() && operators.top().imp >= tmp.imp) 
      {
        result += operators.top().op;
        operators.pop();
      }
      operators.push(tmp);
    }
    
  } // for
  
  while(!operators.empty()) {
      result += operators.top().op;
      operators.pop(); 
  }
  return result;
}
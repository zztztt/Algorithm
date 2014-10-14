#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    vector<string>::iterator it = tokens.begin();
    stack<int> s;
    for (; it != tokens.end(); ++it) {
      if (*it == "+") {
        int e2 = s.top();
        s.pop();
        int e1 = s.top();
        s.pop();
        s.push(e1 + e2);
      } else if (*it == "-") {
        int e2 = s.top();
        s.pop();
        int e1 = s.top();
        s.pop();
        s.push(e1 - e2);
      } else if (*it == "*") {
        int e2 = s.top();
        s.pop();
        int e1 = s.top();
        s.pop();
        s.push(e1 * e2);
      } else if (*it == "/") {
        int e2 = s.top();
        s.pop();
        int e1 = s.top();
        s.pop();
        s.push(e1 / e2);
      } else {
        s.push(atoi((*it).c_str()));
      }
    }
    return s.top();
  }
};

int main() {
  vector<string> tokens;
  tokens.push_back("2");
  tokens.push_back("1");
  tokens.push_back("+");
  tokens.push_back("3");
  tokens.push_back("*");
  Solution s;
  int result = s.evalRPN(tokens);
  cout << result << endl;
}

#include <iostream>
#include <list>

using namespace std;

class Solution {
public:
  void reverseWords(string &s) {
    list<string> l;
    string temp = "";
    for (int i = 0; i != s.length(); ++i) {
      if (s[i] != ' ') {
        temp += s[i];
      }
      else {
        if (!temp.empty())
          l.push_front(temp);
        temp = "";
      }
    }
    if (!temp.empty())
      l.push_front(temp);

    s = "";
    list<string>::iterator it = l.begin();
    for (; it != l.end(); ++it) {
      if (it != l.begin())
        s += " ";
      s += *it;
    }
  }
};

int main() {
  string input = "the sky is blue";
  Solution s;
  s.reverseWords(input);
  cout  << "[" << input  << "]" << endl;
  return 0;
}

/*
 * Given a string s and a dictionary of words dict, determine 
 * if s can be segmented into a space-separated sequence of one or more dictionary words
 * For example, given :
 * s = "leetocode"
 * dict = ["leet", "code"]
 * Return true because "leetcode" can be segmented as "leet code"
 *
 * Solution:
 *  DP[j] = DP[j - i] && s.substr(0, i) in s
 *
 */
#include <string>
#include <stdio.h>
#include <string.h>
#include <unordered_set>

using namespace std;

class Solution {
  public:
    bool wordBreak(string s, unordered_set<string> &dict) {
      if (s.length() == 0)
        return false;
      bool dp[s.length() + 1];
      dp[0] = true;
      for (int j = 1; j <= s.length(); ++j) {
        dp[j] = false;
        for (int i = 1; i <= j; ++i) {
          if (dp[j - i])
            dp[j] |= (dict.find(s.substr(j - i, i)) == dict.end()) ? false : true;
        }
      }
      return dp[s.length()];
    }
};

int main() {
  unordered_set<string> dict;
  string s = "a";
  Solution ss;
  bool flag = ss.wordBreak(s, dict);

  if (flag)
    printf("true\n");
  else
    printf("false\n");
  return 0;
}

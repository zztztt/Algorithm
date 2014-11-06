/*
 * Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2.
 * Each operation is counted as 1 step
 * You have the following 3 operations permitted on a word:
 *  a) Insert a character
 *  b) Delete a character
 *  c) Replace a character
 *
 * Soluction:
 *  Dynamic Programming
 */
class Solution {
  public:
    int minDistance(string word1, string word2) {
      int len1 = word1.length() + 1;
      int len2 = word2.length() + 1;
      int dp[len1][len2];
      for (int i = 0; i < len1; ++i) 
        dp[i][0] = i;
      for (int j = 1; j < len2; ++j)
        dp[0][j] = j;
      for (int i = 1; i < len1; ++i) {
        for (int j = 1; j < len2; ++j) {
          int cost = 1;
          if (word1[i - 1] == word2[j - 1])
            cost = 0;
          dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + cost);
        }
      }
      return dp[len1 - 1][len2 - 1];
    }
};

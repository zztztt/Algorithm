/*
 * Reverse digits of an interger.
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 *
 */
class Solution {
public:
  int reverse(int x) {
    long long result = 0;
    bool positive = true;
    if (x < 0) {
      positive = false;
      x = 0 - x;
    }
    while(x != 0) {
      result = 10 * result + x % 10;
      x = x / 10;
    }
    if (!positive)
      result = 0 - result;
    return (result > INT_MAX || result < INT_MIN) ? 0 : result;

  }
};

/*
 * Given an array of integers, every element appers twice except for one. Find that single one
 * runtime complexity. without using extra memory
 * Solution:
 * Bit Manipulation A ^ A => 0
 *
 */
class Solution {
  public:
    int singleNumber(int A[], int n) {
      for (int i = 1; i < n; ++i) {
        A[0] ^= A[i];
      }
      return A[0];
    }
};

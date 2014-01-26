/*
 * Longest Non-decreasing sequence : 最长非降序子序列
 * Q: 一个序列A有N个数，求其最长非降序子序列长度?
 * A: 动态规划求解,状态转移方程为: d[i] = max{1, d[j]+1},j < i,d[j] < d[i]
 * *: d[i]是已第i+1个数结尾的最长非降序子序列长度(i从0开始),所以结果应为所有d[i],i < N 的最大值
 *
 */

#include <stdio.h>

#define N 15

// method : O(n*n)
int LNS(int *A,int n)
{
  int len = 0;
  int *d = new int[n];
  int i = 0;
  for(; i < n; ++i)
  {
    d[i] = 1;
    int j = 0;
    for (; j < i; ++j)
    {
      if (A[j] <= A[i] && d[i] < d[j] + 1)
      {
        d[i] = d[j] + 1;
      } 
    }
    if (len < d[i])
    {
      len = d[i];
    }
    //printf("%d  %d\n",i, d[i]);
  }
  return len;
}
int main()
{
  //int A[N] = {3,5,3,1,5,8,9,1,3,5};
  int A[N] = {7,5,6,8,10,7,9,3,8,7,4,1,8,9,4};
  int result = LNS(A, N);
  printf("result:%d\n", result);
}

/*
 * W: 0-1 背包问题, 有n个物品每个重w[i],价值p[i](均大于0),背包最多能放W重的物品，
 *    且每个物品只能放0或者1个,求价值最大的放法
 * A: 动态规划求解，状态转移方程：
 *    dp[i][Y],前i个物品，放重量为Y的背包，能取得的最大价值
 *    dp[i][0] = 0;
 *    dp[0][Y] = 0;
 *    w[i] > Y, dp[i][Y] = dp[i-1][Y];
 *    w[i] < Y, dp[i][Y] = max{dp[i-1][Y], p[i] + dp[i-1][Y-w[i]]};
 */
#include <stdio.h>

#define N 8
struct item
{
  int w;
  int p;
};
int MaxPrice(item *items, const int num, int W)
{
  int dp[num + 1][W + 1];
  int i = 0;
  int j = 0;
  for (;i <= num; ++i) 
  {
    for (j = 0; j <= W; ++j)
    {
      if (i == 0 || j == 0)
      {
        dp[i][j] = 0;
      }
      else if (items[i - 1].w > j)
      {
        dp[i][j] = dp[i - 1][j];
      }
      else
      {
        int x = dp[i - 1][j];
        int y = dp[i - 1][j - items[i - 1].w] + items[i - 1].p;
        dp[i][j] = x > y ? x : y;
      }
      printf("%4d", dp[i][j]);
    }
    printf("\n");
  }
  return dp[num][W];
}
int main()
{
  item items[N] = {
    {3,4},
    {4,5},
    {5,6},
    {1,4},
    {2,3},
    {8,20},
    {9,1},
    {7,7},
  };
  int result = MaxPrice(items, N, 10);
  printf("result: %d\n", result);
  return 0;
}

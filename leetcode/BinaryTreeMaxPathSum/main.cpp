#include <stdio.h>
#include <limits.h>
#include <algorithm>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
  public:
    int maxPathSum(TreeNode *root) {
      int result = INT_MIN;
      maxSinglePath(root, result);
      return result;
    }
    int maxSinglePath(TreeNode *root, int &result) {
      if (root == NULL) {
        return 0;
      }
      int now = root->val;
      int temp_result = now;
      int left = maxSinglePath(root->left, result);
      int right = maxSinglePath(root->right, result);
      if (left > 0) {
        temp_result += left;
      }
      if (right > 0) {
        temp_result += right;
      }
      if (temp_result > result) {
        result = temp_result;
      }
      return max(max(left + now, right + now), now);
    }
};
int main() {
  return 0;
}

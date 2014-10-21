/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stdio.h>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    int sumNumbers(TreeNode *root) {
      return calSumNum(root, 0);
    }
    int calSumNum(TreeNode *root, int sum) {
      if (root == NULL) {
        return 0;
      }
      sum = sum * 10 + root->val;
      if (root->left == NULL && root->right == NULL) {
        return sum;
      }
      int leftSum = calSumNum(root->left, sum);
      int rightSum = calSumNum(root->right, sum);
      return leftSum + rightSum;
      
    }
};
int main() {
  TreeNode *root = new TreeNode(4);
  TreeNode *p1 = new TreeNode(7);
  TreeNode *p2 = new TreeNode(5);
  TreeNode *p3 = new TreeNode(2);
  TreeNode *p4 = new TreeNode(1);
  TreeNode *p5 = new TreeNode(6);
  root->left = p1;
  root->right = p2;
  p1->left = p3;
  p1->right = p4;
  p2->right = p5;
  Solution s;
  int result = s.sumNumbers(root);
  printf("%d\n",result);
}

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    bool isBalanced(TreeNode *root) {
      if (root == NULL) {
        return true;
      }       
      int lh = depth(root->left);
      int rh = depth(root->right);
      if ((rh - lh < 2) && (rh - lh > -2)) {
        return (isBalanced(root->left) && isBalanced(root->right));
      } else {
        return false;
      }
    }
    int depth(TreeNode *node) {
      if (node == NULL) {
        return 0;
      } else {
        return max(depth(node->left), depth(node->right)) + 1;
      }
    }

};

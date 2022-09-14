/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/
 * Runtime: 513ms
 */

class Solution {
private:
  bitset<10> bs;
public:
  int pseudoPalindromicPaths(TreeNode* root) {
    bs.flip(root->val);

    int sum;
    if (root->left == nullptr && root->right == nullptr) {
      sum = (bs.count() <= 1);
    } else if (root->left == nullptr) {
      sum = pseudoPalindromicPaths(root->right);
    } else if (root->right == nullptr) {
      sum = pseudoPalindromicPaths(root->left);
    } else {
      sum = pseudoPalindromicPaths(root->left) + pseudoPalindromicPaths(root->right);
    }

    bs.flip(root->val);
    return sum;
  }
};

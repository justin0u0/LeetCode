/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/delete-leaves-with-a-given-value/
 * Runtime: 4ms (96.50%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  TreeNode* removeLeafNodes(TreeNode* root, const int target) {
    if (root == nullptr) {
      return nullptr;
    }
    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);
    if (root->left == nullptr && root->right == nullptr) {
      if (root->val == target) {
        return nullptr;
      }
    }
    return root;
  }
};

/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
 * Runtime: 39ms (95.85%)
 */

class Solution {
private:
  vector<int> box;

  void dfs(TreeNode* root) {
    if (root->left != nullptr) {
      dfs(root->left);
    }
    box.emplace_back(root->val);
    if (root->right != nullptr) {
      dfs(root->right);
    }
  }
public:
  bool findTarget(TreeNode* root, int k) {
    box.clear();
    dfs(root);
    int l = 0;
    int r = box.size() - 1;
    while (l < r) {
      int s = box[l] + box[r];
      if (s == k) {
        return true;
      }

      if (s < k) {
        ++l;
      } else {
        --r;
      }
    }

    return false;
  }
};

/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/path-sum-ii/
 * Runtime: 7ms (96.06%)
 */

class Solution {
private:
  vector<vector<int>> paths;

  void dfs(TreeNode* root, int target, vector<int>& path) {
    path.emplace_back(root->val);

    if (root->left == nullptr && root->right == nullptr) {
      if (target == root->val) {
        paths.emplace_back(path);
      }
    } else {
      if (root->left != nullptr) {
        dfs(root->left, target - root->val, path);
      }
      if (root->right != nullptr) {
        dfs(root->right, target - root->val, path);
      }
    }

    path.pop_back();
  }
public:
  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) {
      return vector<vector<int>>{};
    }

    paths.clear();
    vector<int> path;
    dfs(root, targetSum, path);
    return paths;
  }
};

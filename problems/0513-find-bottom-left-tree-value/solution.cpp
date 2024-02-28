/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-bottom-left-tree-value/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    int cand = root->val;
    while (!q.empty()) {
      cand = q.front()->val;

      int sz = q.size();
      while (sz--) {
        auto u = q.front();
        q.pop();
        if (u->left != nullptr) {
          q.push(u->left);
        }
        if (u->right != nullptr) {
          q.push(u->right);
        }
      }
    }
    return cand; 
  }
};

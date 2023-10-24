/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-largest-value-in-each-tree-row/
 * Runtime: 7ms (81.90%)
 */

class Solution {
public:
  vector<int> largestValues(TreeNode* root) {
    if (root == nullptr) {
      return vector<int>{};
    }

    queue<TreeNode*> q;
    q.push(root);

    vector<int> answer;
    while (!q.empty()) {
      int val = INT_MIN;
      for (int sz = q.size(); sz != 0; --sz) {
        TreeNode* n = q.front();
        q.pop();

        val = max(val, n->val);
        if (n->left != nullptr) {
          q.push(n->left);
        }
        if (n->right != nullptr) {
          q.push(n->right);
        }
      }
      answer.emplace_back(val);
    }
    return answer;
  }
};

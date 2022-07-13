/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/binary-tree-level-order-traversal/
 * Runtime: 3ms
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> answer;
    if (root == nullptr) {
      return answer;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      int size = q.size();
      vector<int> box;
      box.reserve(size);

      for (int i = 0; i < size; ++i) {
        TreeNode* cur = q.front();
        q.pop();

        box.emplace_back(cur->val);
        if (cur->left != nullptr) {
          q.push(cur->left);
        }
        if (cur->right != nullptr) {
          q.push(cur->right);
        }
      }

      answer.emplace_back(box);
    }

    return answer;
  }
};

/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/binary-tree-right-side-view/
 * Runtime: 4ms
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
private:
public:
  vector<int> rightSideView(TreeNode* root) {
    queue<TreeNode*> q;
    vector<int> answer;

    if (root != nullptr) {
      q.push(root);
    }

    while (!q.empty()) {
      answer.emplace_back(q.front()->val);

      int size = (int)q.size();
      for (int i = 0; i < size; ++i) {
        TreeNode* cur = q.front();
        q.pop();

        if (cur->right != nullptr) {
          q.push(cur->right);
        }
        if (cur->left != nullptr) {
          q.push(cur->left);
        }
      }
    }

    return answer;
  }
};

/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/average-of-levels-in-binary-tree/
 * Runtime: 11ms
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
  vector<double> averageOfLevels(TreeNode* root) {
    vector<double> answer;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      int size = q.size();
      double sum = 0;
      for (int i = 0; i < size; ++i) {
        TreeNode* n = q.front();
        q.pop();

        if (n->left != nullptr) {
          q.push(n->left);
        }
        if (n->right != nullptr) {
          q.push(n->right);
        }

        sum += n->val;
      }
      answer.emplace_back(sum / size);
    }
    return answer;
  }
};

/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/
 * Runtime: 0ms (100.00%)
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
  int averageOfSubtree(TreeNode* root) {
    int answer = 0;
    
    function<pair<int, int>(TreeNode*)> dfs = [&](TreeNode* n) {
      int sum = n->val;
      int count = 1;
      if (n->left != nullptr) {
        auto l = dfs(n->left);
        sum += l.first;
        count += l.second;
      }
      if (n->right != nullptr) {
        auto r = dfs(n->right);
        sum += r.first;
        count += r.second;
      }

      if (sum / count == n->val) {
        ++answer;
      }

      return pair{sum, count};
    };
    dfs(root);

    return answer;
  }
};

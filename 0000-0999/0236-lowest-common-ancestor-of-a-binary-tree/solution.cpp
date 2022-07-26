/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
 * Runtime: 18ms
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
  bool dfs(TreeNode* n, stack<TreeNode*>& path, TreeNode* target) {
    path.push(n);
    if (n == target) {
      return true;
    }

    if (n->left != nullptr && dfs(n->left, path, target)) {
      return true;
    }
    if (n->right != nullptr && dfs(n->right, path, target)) {
      return true;
    }

    path.pop();
    return false;
  }
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    stack<TreeNode*> pPath;
    stack<TreeNode*> qPath;

    dfs(root, pPath, p);
    dfs(root, qPath, q);
    if (pPath.size() > qPath.size()) {
      swap(pPath, qPath);
    }

    while (qPath.size() > pPath.size()) {
      qPath.pop();
    }
    while (pPath.top() != qPath.top()) {
      pPath.pop();
      qPath.pop();
    }

    return pPath.top();
  }
};

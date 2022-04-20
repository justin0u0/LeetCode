/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/binary-search-tree-iterator/
 * Runtime: 26ms
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
class BSTIterator {
private:
  stack<TreeNode*> stk;
public:
  BSTIterator(TreeNode* root) {
    while (root != nullptr) {
      stk.push(root);
      root = root->left;
    }
  }

  int next() {
    TreeNode* cur = stk.top();
    stk.pop();

    int val = cur->val;
    cur = cur->right;

    while (cur != nullptr) {
      stk.push(cur);
      cur = cur->left;
    }

    return val;
  }

  bool hasNext() {
    return !stk.empty();
  }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

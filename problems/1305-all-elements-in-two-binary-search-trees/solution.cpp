/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
 * Runtime: 176ms
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
  list<int> l;
  
  void dfs(TreeNode* root) {
    if (root == nullptr) {
      return;
    }

    dfs(root->left);
    l.emplace_back(root->val);
    dfs(root->right);
  }
  
  void dfs2(TreeNode* root, list<int>::iterator it) {
    if (root == nullptr) {
      return;
    }

    dfs2(root->left, it);
    while (it != l.end() && (*it) < root->val) {
      ++it;
    }
    l.emplace(it, root->val);
    dfs2(root->right, it);
  }
public:
  vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    dfs(root1);
    dfs2(root2, l.begin());

    vector<int> answer(l.size());
    copy(l.begin(), l.end(), answer.begin());

    return answer;
  }
};

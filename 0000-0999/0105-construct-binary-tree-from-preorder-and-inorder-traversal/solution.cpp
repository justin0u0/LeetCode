/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 * Runtime: 8ms
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

class Solver {
private:
  vector<int>::const_iterator& it; // preorder iterator
  unordered_map<int, int>& indexer; // inorder value/index mapping
public:
  Solver(vector<int>::const_iterator& it, unordered_map<int, int>& indexer)
    : it(it), indexer(indexer) {}

  TreeNode* solve(int l, int r) {
    if (l == r) {
      return nullptr;
    }

    int val = *it;
    it++;
    TreeNode* n = new TreeNode(val);
    n->left = solve(l, indexer[val]);
    n->right = solve(indexer[val] + 1, r);

    return n;
  }
};

class Solution {
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> indexer;
    for (int i = 0; i < inorder.size(); ++i) {
      indexer[inorder[i]] = i;
    }

    vector<int>::const_iterator it = preorder.cbegin();
    Solver solver(it, indexer);

    return solver.solve(0, indexer.size());
  }
};

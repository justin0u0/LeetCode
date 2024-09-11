/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/n-ary-tree-postorder-traversal/
 * Runtime: 10ms (85.15%)
 */

class Solution {
public:
  vector<int> postorder(Node* root) {
    if (root == nullptr) {
      return {};
    }
    
    vector<int> po;
    function<void(Node*)> dfs = [&](Node* n) {
      for (Node* c : n->children) {
        dfs(c);
      }
      po.emplace_back(n->val);
    };
    dfs(root);
    return po;
  }
};

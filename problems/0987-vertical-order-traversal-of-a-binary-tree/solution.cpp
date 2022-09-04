/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
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
  struct Node {
    int row;
    int col;
    int val;

    bool operator < (const Node& rhs) const {
      if (col != rhs.col) {
        return col < rhs.col;
      }
      if (row != rhs.row) {
        return row < rhs.row;
      }
      return val < rhs.val;
    }
  };

  vector<Node> nodes;

  void dfs(TreeNode* root, int row, int col) {
    nodes.emplace_back(Node{row, col, root->val});
    if (root->left != nullptr) {
      dfs(root->left, row + 1, col - 1);
    }
    if (root->right != nullptr) {
      dfs(root->right, row + 1, col + 1);
    }
  }
public:
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    nodes.clear();
    dfs(root, 0, 0);
    sort(nodes.begin(), nodes.end());

    vector<vector<int>> answer;
    int preCol = -0x3f3f3f3f;
    for (const Node& node : nodes) {
      if (preCol != node.col) {
        answer.emplace_back(vector<int>{node.val});
      } else {
        answer.back().emplace_back(node.val);
      }
      preCol = node.col;
    }

    return answer;
  }
};

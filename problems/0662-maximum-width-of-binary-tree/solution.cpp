/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-width-of-binary-tree/
 * Runtime: 10ms
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
  int widthOfBinaryTree(TreeNode* root, int width = 1) {
    queue<TreeNode*>* q1 = new queue<TreeNode*>;
    queue<TreeNode*>* q2 = new queue<TreeNode*>;

    root->val = 1;
    q1->push(root);

    int answer = 0;
    while (!q1->empty()) {
      int l = 0x7fffffff;
      int r = 1;
      int base = q1->front()->val - 1;

      while (!q1->empty()) {
        TreeNode* u = q1->front();
        q1->pop();

        l = min(l, u->val);
        r = max(r, u->val);
        u->val -= base;

        if (u->left != nullptr) {
          u->left->val = (u->val << 1) - 1;
          q2->push(u->left);
        }
        if (u->right != nullptr) {
          u->right->val = (u->val << 1);
          q2->push(u->right);
        }
      }

      swap(q1, q2);
      answer = max(answer, r - l + 1);
    }

    delete q1;
    delete q2;
    return answer;
  }
};


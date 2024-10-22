/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/
 * Runtime: 16ms (98.63%)
 */

class Solution {
public:
  long long kthLargestLevelSum(TreeNode* root, int k) {
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      int sz = q.size();
      long long sum = 0;

      while (sz--) {
        TreeNode* n = q.front();
        q.pop();

        sum += n->val;

        if (n->left != nullptr) {
          q.push(n->left);
        }
        if (n->right != nullptr) {
          q.push(n->right);
        }
      }

      pq.push(sum);
      if (pq.size() > k) {
        pq.pop();
      }
    }

    if (pq.size() != k) {
      return -1;
    }
    return pq.top();
  }
};

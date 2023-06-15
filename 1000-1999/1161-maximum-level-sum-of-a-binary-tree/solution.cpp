/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
 * Runtime: 172ms (99.11%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int maxLevelSum(TreeNode* root) {

    queue<TreeNode*> q;
    q.push(root);

    int maxSum = INT_MIN;
    int answer = -1;

    for (int i = 1; !q.empty(); ++i) {
      int sz = q.size();
      int sum = 0;
      while (sz--) {
        TreeNode* u = q.front();
        q.pop();
        sum += u->val;

        if (u->left != nullptr) {
          q.push(u->left);
        }
        if (u->right != nullptr) {
          q.push(u->right);
        }
      }

      if (sum > maxSum) {
        maxSum = sum;
        answer = i;
      }
    }

    return answer;
  }
};

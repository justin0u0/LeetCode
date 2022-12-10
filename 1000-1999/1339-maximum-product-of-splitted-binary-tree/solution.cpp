/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
 * Runtime: 131ms (96.85%)
 */

class Solution {
private:
  const int mod = 1e9 + 7;
  int total;
  long long answer;

  void getTotal(TreeNode* root) {
    total += root->val;
    if (root->left != nullptr) {
      getTotal(root->left);
    }
    if (root->right != nullptr) {
      getTotal(root->right);
    }
  }

  int solve(TreeNode* root) {
    int sum = root->val;
    if (root->left != nullptr) {
      sum += solve(root->left);
    }
    if (root->right != nullptr) {
      sum += solve(root->right);
    }
    answer = max(answer, 1LL * sum * (total - sum));
    return sum;
  }
public:
  int maxProduct(TreeNode* root) {
    total = 0;
    getTotal(root);
    answer = 0;
    solve(root);
    return answer % mod;
  }
};

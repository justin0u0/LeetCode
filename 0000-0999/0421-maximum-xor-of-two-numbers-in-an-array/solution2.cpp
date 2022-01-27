/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/submissions/
 * Runtime: 196ms
 * Time Complexity: O(32N)
 * Description: Iterative solution.
 */

class Solution {
private:
  class TreeNode {
  public:
    TreeNode* left;
    TreeNode* right;
    TreeNode() : left(nullptr), right(nullptr) {}
  };
public:
  int findMaximumXOR(vector<int>& nums) {
    TreeNode* node = new TreeNode();
    TreeNode* cur;

    int answer = 0;
    for (int num : nums) {
      cur = node;

      // insert into tree
      for (int mask = (1 << 30); mask; mask >>= 1) {
        if (num & mask) {
          if (cur->right == nullptr) {
            cur->right = new TreeNode();
          }
          cur = cur->right;
        } else {
          if (cur->left == nullptr) {
            cur->left = new TreeNode();
          }
          cur = cur->left;
        }
      }

      int value = 0;
      cur = node;

      // find best
      for (int mask = (1 << 30); mask; mask >>= 1) {
        if (cur->right == nullptr || ((num & mask) && cur->left != nullptr)) {
          cur = cur->left;
        } else {
          value = mask | value;
          cur = cur->right;
        }
      }
      
      answer = max(answer, num ^ value);
    }

    return answer;
  }
};

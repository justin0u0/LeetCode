/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
 * Runtime: 362ms
 * Time Complexity: O(32N)
 * Description: Recursive solution.
 */

class Solution {
private:
  class TreeNode {
  public:
    TreeNode* left;
    TreeNode* right;
    TreeNode() : left(nullptr), right(nullptr) {}
  };

  TreeNode* insert(TreeNode* node, int value, int mask) {
    if (node == nullptr) {
      node = new TreeNode();
    }

    if (!mask) {
      return node;
    }

    if (value & mask) {
      node->right = insert(node->right, value, mask >> 1);
    } else {
      node->left = insert(node->left, value, mask >> 1);
    }

    return node;
  }

  int find(TreeNode* node, int value, int mask) {
    if (!mask) {
      return 0;
    }

    if (node->right == nullptr || ((value & mask) && node->left != nullptr)) {
      return find(node->left, value, mask >> 1);
    }

    return (mask | find(node->right, value, mask >> 1));
  }
public:
  int findMaximumXOR(vector<int>& nums) {
    const int mask = (1 << 30);
    TreeNode* node = nullptr;

    int answer = 0;
    for (int num : nums) {
      node = insert(node, num, mask);
      answer = max(answer, num ^ find(node, num, mask));
    }

    return answer;
  }
};

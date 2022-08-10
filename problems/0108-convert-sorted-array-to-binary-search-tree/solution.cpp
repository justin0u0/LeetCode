/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 * Runtime: 28ms
 */

class Solution {
private:
  TreeNode* build(vector<int>& nums, int l, int r) {
    if (l >= r) {
      return nullptr;
    }

    int mid = (l + r) >> 1;
    TreeNode* n = new TreeNode(nums[mid]);
    n->left = build(nums, l, mid);
    n->right = build(nums, mid + 1, r);
    return n;
  }
public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return build(nums, 0, nums.size());
  }
};

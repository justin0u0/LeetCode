/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/next-permutation/
 * Description: https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
 */

class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    int n = (int)nums.size();

    int k = -1;
    for (int i = 0; i < n - 1; ++i) {
      if (nums[i] < nums[i + 1]) {
        k = i;
      }
    }

    if (k == -1) {
      reverse(nums.begin(), nums.end());

      return;
    }

    int l;
    for (int i = k + 1; i < n; ++i) {
      if (nums[i] > nums[k]) {
        l = i;
      }
    }

    swap(nums[k], nums[l]);
    reverse(nums.begin() + k + 1, nums.end());
  }
};

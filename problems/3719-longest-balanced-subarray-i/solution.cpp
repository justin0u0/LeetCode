/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/longest-balanced-subarray-i/
 * Runtime: 2524ms (5.25%)
 */

class Solution {
public:
  int longestBalanced(const vector<int>& nums) {
    int longest = 0;
    for (int i = 0; i < nums.size(); ++i) {
      unordered_set<int> odd;
      unordered_set<int> even;
      for (int j = i; j >= 0; --j) {
        if (nums[j] & 1) {
          odd.emplace(nums[j]);
        } else {
          even.emplace(nums[j]);
        }
        if (odd.size() == even.size()) {
          longest = max(longest, i - j + 1);
        }
      }
    }
    return longest;
  }
};

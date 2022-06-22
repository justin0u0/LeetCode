/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/kth-largest-element-in-an-array/
 * Runtime: 12ms
 */

class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
  }
};

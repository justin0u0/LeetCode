/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 * Runtime: 8ms
 */

class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> answer(2, -1);
    if (nums.empty()) {
      return answer;
    }

    answer[0] = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    answer[1] = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
    if (answer[1] < 0 || nums[answer[1]] != target) {
      answer[0] = -1;
      answer[1] = -1;
    }

    return answer;
  }
};

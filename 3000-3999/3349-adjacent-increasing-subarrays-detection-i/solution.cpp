/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/
 * Runtime: 7ms (94.09%)
 */

class Solution {
public:
  bool hasIncreasingSubarrays(const vector<int>& nums, const int k) {
    auto decr = [&](int i) {
      for (int j = i; j > i - k + 1; --j) {
        if (nums[j] <= nums[j - 1]) {
          return false;
        }
      }
      return true;
    };
    auto incr = [&](int i) {
      for (int j = i; j < i + k - 1; ++j) {
        if (nums[j] >= nums[j + 1]) {
          return false;
        }
      }
      return true;
    };

    for (int i = k; i < nums.size() - k + 1; ++i) {
      if (decr(i - 1) && incr(i)) {
        return true;
      }
    }
    return false;
  }
};

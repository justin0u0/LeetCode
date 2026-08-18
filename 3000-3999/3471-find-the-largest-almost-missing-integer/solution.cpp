/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-largest-almost-missing-integer/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int largestInteger(const vector<int>& nums, const int k) {
    int cnt[51] = {0};
    for (int num : nums) {
      ++cnt[num];
    }

    if (k == 1) {
      for (int i = 50; i >= 0; --i) {
        if (cnt[i] == 1) {
          return i;
        }
      }
      return -1;
    }
    if (k == nums.size()) {
      for (int i = 50; i >= 0; --i) {
        if (cnt[i] > 0) {
          return i;
        }
      }
    }

    int res = -1;
    if (cnt[nums[0]] == 1) {
      res = nums[0];
    }
    if (cnt[nums.back()] == 1) {
      res = max(res, nums.back());
    }
    return res;
  }
};

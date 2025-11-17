/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool kLengthApart(const vector<int>& nums, const int k) {
    int last = -1e9;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == 1) {
        if (i - last <= k) {
          return false;
        }
        last = i;
      }
    }
    return true;
  }
};

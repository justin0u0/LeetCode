/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/monotonic-array/
 * Runtime: 66ms (99.89%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  bool isMonotonic(const vector<int>& nums) {
    bool incr = true;
    bool decr = true;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        incr = false;
      } else if (nums[i] < nums[i - 1]) {
        decr = false;
      }
    }
    return incr || decr;
  }
};
